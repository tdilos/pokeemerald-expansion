#include "global.h"
#include "main.h"
#include "event_data.h"
#include "field_effect.h"
#include "field_specials.h"
#include "item.h"
#include "list_menu.h"
#include "menu.h"
#include "palette.h"
#include "script.h"
#include "script_menu.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "list_menu.h"
#include "malloc.h"
#include "util.h"
#include "item_icon.h"
#include "constants/field_specials.h"
#include "constants/items.h"
#include "constants/script_menu.h"
#include "constants/seagallop.h"
#include "constants/songs.h"

#include "data/script_menu.h"

struct DynamicListMenuEventArgs
{
    struct ListMenuTemplate *list;
    u16 selectedItem;
    u8 windowId;
};

typedef void (*DynamicListCallback)(struct DynamicListMenuEventArgs *eventArgs);

struct DynamicListMenuEventCollection
{
    DynamicListCallback OnInit;
    DynamicListCallback OnSelectionChanged;
    DynamicListCallback OnDestroy;
};

static EWRAM_DATA u8 sProcessInputDelay = 0;
static EWRAM_DATA u8 sDynamicMenuEventId = 0;
static EWRAM_DATA struct DynamicMultichoiceStack *sDynamicMultiChoiceStack = NULL;
static EWRAM_DATA u16 *sDynamicMenuEventScratchPad = NULL;

static u8 sLilycoveSSTidalSelections[SSTIDAL_SELECTION_COUNT];

static void FreeListMenuItems(struct ListMenuItem *items, u32 count);
static void Task_HandleScrollingMultichoiceInput(u8 taskId);
static void Task_HandleMultichoiceInput(u8 taskId);
static void Task_HandleYesNoInput(u8 taskId);
static void Task_HandleMultichoiceGridInput(u8 taskId);
static void DrawMultichoiceMenuDynamic(u8 left, u8 top, u8 argc, struct ListMenuItem *items, bool8 ignoreBPress, u32 initialRow, u8 maxBeforeScroll, u32 callbackSet);
static void DrawMultichoiceMenu(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 cursorPos);
static void InitMultichoiceCheckWrap(bool8 ignoreBPress, u8 count, u8 windowId, u8 multichoiceId);
static void DrawLinkServicesMultichoiceMenu(u8 multichoiceId);
static void CreatePCMultichoice(void);
static void CreateLilycoveSSTidalMultichoice(void);
static bool8 IsPicboxClosed(void);
static void CreateStartMenuForPokenavTutorial(void);
static void InitMultichoiceNoWrap(bool8 ignoreBPress, u8 unusedCount, u8 windowId, u8 multichoiceId);
static void MultichoiceDynamicEventDebug_OnInit(struct DynamicListMenuEventArgs *eventArgs);
static void MultichoiceDynamicEventDebug_OnSelectionChanged(struct DynamicListMenuEventArgs *eventArgs);
static void MultichoiceDynamicEventDebug_OnDestroy(struct DynamicListMenuEventArgs *eventArgs);
static void MultichoiceDynamicEventShowItem_OnInit(struct DynamicListMenuEventArgs *eventArgs);
static void MultichoiceDynamicEventShowItem_OnSelectionChanged(struct DynamicListMenuEventArgs *eventArgs);
static void MultichoiceDynamicEventShowItem_OnDestroy(struct DynamicListMenuEventArgs *eventArgs);

static const struct DynamicListMenuEventCollection sDynamicListMenuEventCollections[] =
{
    [DYN_MULTICHOICE_CB_DEBUG] =
    {
        .OnInit = MultichoiceDynamicEventDebug_OnInit,
        .OnSelectionChanged = MultichoiceDynamicEventDebug_OnSelectionChanged,
        .OnDestroy = MultichoiceDynamicEventDebug_OnDestroy
    },
    [DYN_MULTICHOICE_CB_SHOW_ITEM] =
    {
        .OnInit = MultichoiceDynamicEventShowItem_OnInit,
        .OnSelectionChanged = MultichoiceDynamicEventShowItem_OnSelectionChanged,
        .OnDestroy = MultichoiceDynamicEventShowItem_OnDestroy
    }
};

static const struct ListMenuTemplate sScriptableListMenuTemplate =
{
    .item_X = 8,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
};

bool8 ScriptMenu_MultichoiceDynamic(u8 left, u8 top, u8 argc, struct ListMenuItem *items, bool8 ignoreBPress, u8 maxBeforeScroll, u32 initialRow, u32 callbackSet)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        FreeListMenuItems(items, argc);
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenuDynamic(left, top, argc, items, ignoreBPress, initialRow, maxBeforeScroll, callbackSet);
        return TRUE;
    }
}

bool8 ScriptMenu_Multichoice(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenu(left, top, multichoiceId, ignoreBPress, 0);
        return TRUE;
    }
}

bool8 ScriptMenu_MultichoiceWithDefault(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 defaultChoice)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DrawMultichoiceMenu(left, top, multichoiceId, ignoreBPress, defaultChoice);
        return TRUE;
    }
}

static void MultichoiceDynamicEventDebug_OnInit(struct DynamicListMenuEventArgs *eventArgs)
{
    DebugPrintf("OnInit: %d", eventArgs->windowId);
}

static void MultichoiceDynamicEventDebug_OnSelectionChanged(struct DynamicListMenuEventArgs *eventArgs)
{
    DebugPrintf("OnSelectionChanged: %d", eventArgs->selectedItem);
}

static void MultichoiceDynamicEventDebug_OnDestroy(struct DynamicListMenuEventArgs *eventArgs)
{
    DebugPrintf("OnDestroy: %d", eventArgs->windowId);
}

#define sAuxWindowId sDynamicMenuEventScratchPad[0]
#define sItemSpriteId sDynamicMenuEventScratchPad[1]
#define TAG_CB_ITEM_ICON 3000

static void MultichoiceDynamicEventShowItem_OnInit(struct DynamicListMenuEventArgs *eventArgs)
{
    struct WindowTemplate *template = &gWindows[eventArgs->windowId].window;
    u32 baseBlock = template->baseBlock + template->width * template->height;
    struct WindowTemplate auxTemplate = CreateWindowTemplate(0, template->tilemapLeft + template->width + 2, template->tilemapTop, 4, 4, 15, baseBlock);
    u32 auxWindowId = AddWindow(&auxTemplate);
    SetStandardWindowBorderStyle(auxWindowId, FALSE);
    FillWindowPixelBuffer(auxWindowId, 0x11);
    CopyWindowToVram(auxWindowId, COPYWIN_FULL);
    sAuxWindowId = auxWindowId;
    sItemSpriteId = MAX_SPRITES;
}

static void MultichoiceDynamicEventShowItem_OnSelectionChanged(struct DynamicListMenuEventArgs *eventArgs)
{
    struct WindowTemplate *template = &gWindows[eventArgs->windowId].window;
    u32 x = template->tilemapLeft * 8 + template->width * 8 + 36;
    u32 y = template->tilemapTop * 8 + 20;

    if (sItemSpriteId != MAX_SPRITES)
    {
        FreeSpriteTilesByTag(TAG_CB_ITEM_ICON);
        FreeSpritePaletteByTag(TAG_CB_ITEM_ICON);
        DestroySprite(&gSprites[sItemSpriteId]);
    }

    sItemSpriteId = AddItemIconSprite(TAG_CB_ITEM_ICON, TAG_CB_ITEM_ICON, eventArgs->selectedItem);
    gSprites[sItemSpriteId].oam.priority = 0;
    gSprites[sItemSpriteId].x = x;
    gSprites[sItemSpriteId].y = y;
}

static void MultichoiceDynamicEventShowItem_OnDestroy(struct DynamicListMenuEventArgs *eventArgs)
{
    ClearStdWindowAndFrame(sAuxWindowId, TRUE);
    RemoveWindow(sAuxWindowId);

    if (sItemSpriteId != MAX_SPRITES)
    {
        FreeSpriteTilesByTag(TAG_CB_ITEM_ICON);
        FreeSpritePaletteByTag(TAG_CB_ITEM_ICON);
        DestroySprite(&gSprites[sItemSpriteId]);
    }
}

#undef sAuxWindowId
#undef sItemSpriteId
#undef TAG_CB_ITEM_ICON

static void FreeListMenuItems(struct ListMenuItem *items, u32 count)
{
    u32 i;
    for (i = 0; i < count; ++i)
    {
        // All items were dynamically allocated, so items[i].name is not actually constant.
        Free((void *)items[i].name);
    }
    Free(items);
}

static u16 UNUSED GetLengthWithExpandedPlayerName(const u8 *str)
{
    u16 length = 0;

    while (*str != EOS)
    {
        if (*str == PLACEHOLDER_BEGIN)
        {
            str++;
            if (*str == PLACEHOLDER_ID_PLAYER)
            {
                length += StringLength(gSaveBlock2Ptr->playerName);
                str++;
            }
        }
        else
        {
            str++;
            length++;
        }
    }

    return length;
}

void MultichoiceDynamic_InitStack(u32 capacity)
{
    AGB_ASSERT(sDynamicMultiChoiceStack == NULL);
    sDynamicMultiChoiceStack = AllocZeroed(sizeof(*sDynamicMultiChoiceStack));
    AGB_ASSERT(sDynamicMultiChoiceStack != NULL);
    sDynamicMultiChoiceStack->capacity = capacity;
    sDynamicMultiChoiceStack->top = -1;
    sDynamicMultiChoiceStack->elements = AllocZeroed(capacity * sizeof(struct ListMenuItem));
}

void MultichoiceDynamic_ReallocStack(u32 newCapacity)
{
    struct ListMenuItem *newElements;
    AGB_ASSERT(sDynamicMultiChoiceStack != NULL);
    AGB_ASSERT(sDynamicMultiChoiceStack->capacity < newCapacity);
    newElements = AllocZeroed(newCapacity * sizeof(struct ListMenuItem));
    AGB_ASSERT(newElements != NULL);
    memcpy(newElements, sDynamicMultiChoiceStack->elements, sDynamicMultiChoiceStack->capacity * sizeof(struct ListMenuItem));
    Free(sDynamicMultiChoiceStack->elements);
    sDynamicMultiChoiceStack->elements = newElements;
    sDynamicMultiChoiceStack->capacity = newCapacity;
}

bool32 MultichoiceDynamic_StackFull(void)
{
    AGB_ASSERT(sDynamicMultiChoiceStack != NULL);
    return sDynamicMultiChoiceStack->top == sDynamicMultiChoiceStack->capacity - 1;
}

bool32 MultichoiceDynamic_StackEmpty(void)
{
    AGB_ASSERT(sDynamicMultiChoiceStack != NULL);
    return sDynamicMultiChoiceStack->top == -1;
}

u32 MultichoiceDynamic_StackSize(void)
{
    AGB_ASSERT(sDynamicMultiChoiceStack != NULL);
    return sDynamicMultiChoiceStack->top + 1;
}

void MultichoiceDynamic_PushElement(struct ListMenuItem item)
{
    if (sDynamicMultiChoiceStack == NULL)
        MultichoiceDynamic_InitStack(MULTICHOICE_DYNAMIC_STACK_SIZE);
    if (MultichoiceDynamic_StackFull())
        MultichoiceDynamic_ReallocStack(sDynamicMultiChoiceStack->capacity + MULTICHOICE_DYNAMIC_STACK_INC);
    sDynamicMultiChoiceStack->elements[++sDynamicMultiChoiceStack->top] = item;
}

struct ListMenuItem *MultichoiceDynamic_PopElement(void)
{
    if (sDynamicMultiChoiceStack == NULL)
        return NULL;
    if (MultichoiceDynamic_StackEmpty())
        return NULL;
    return &sDynamicMultiChoiceStack->elements[sDynamicMultiChoiceStack->top--];
}

struct ListMenuItem *MultichoiceDynamic_PeekElement(void)
{
    if (sDynamicMultiChoiceStack == NULL)
        return NULL;
    if (MultichoiceDynamic_StackEmpty())
        return NULL;
    return &sDynamicMultiChoiceStack->elements[sDynamicMultiChoiceStack->top];
}

struct ListMenuItem *MultichoiceDynamic_PeekElementAt(u32 index)
{
    if (sDynamicMultiChoiceStack == NULL)
        return NULL;
    if (sDynamicMultiChoiceStack->top < index)
        return NULL;
    return &sDynamicMultiChoiceStack->elements[index];
}

void MultichoiceDynamic_DestroyStack(void)
{
    TRY_FREE_AND_SET_NULL(sDynamicMultiChoiceStack->elements);
    TRY_FREE_AND_SET_NULL(sDynamicMultiChoiceStack);
}

static void MultichoiceDynamic_MoveCursor(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    u8 taskId;
    if (!onInit)
        PlaySE(SE_SELECT);
    taskId = FindTaskIdByFunc(Task_HandleScrollingMultichoiceInput);
    if (taskId != TASK_NONE)
    {
        ListMenuGetScrollAndRow(gTasks[taskId].data[0], &gScrollableMultichoice_ScrollOffset, NULL);
        if (sDynamicMenuEventId != DYN_MULTICHOICE_CB_NONE && sDynamicListMenuEventCollections[sDynamicMenuEventId].OnSelectionChanged && !onInit)
        {
            struct DynamicListMenuEventArgs eventArgs = {.selectedItem = itemIndex, .windowId = list->template.windowId, .list = &list->template};
            sDynamicListMenuEventCollections[sDynamicMenuEventId].OnSelectionChanged(&eventArgs);
        }
    }
}

static void DrawMultichoiceMenuDynamic(u8 left, u8 top, u8 argc, struct ListMenuItem *items, bool8 ignoreBPress, u32 initialRow, u8 maxBeforeScroll, u32 callbackSet)
{
    u32 i;
    u8 windowId;
    s32 width = 0;
    u8 newWidth;
    u8 taskId;
    u32 windowHeight;
    struct ListMenu *list;

    for (i = 0; i < argc; ++i)
    {
        width = DisplayTextAndGetWidth(items[i].name, width);
    }
    LoadMessageBoxAndBorderGfx();
    windowHeight = (argc < maxBeforeScroll) ? argc * 2 : maxBeforeScroll * 2;
    newWidth = ConvertPixelWidthToTileWidth(width);
    left = ScriptMenu_AdjustLeftCoordFromWidth(left, newWidth);
    windowId = CreateWindowFromRect(left, top, newWidth, windowHeight);
    SetStandardWindowBorderStyle(windowId, FALSE);
    CopyWindowToVram(windowId, COPYWIN_FULL);

    // I don't like this being global either, but I could not come up with another solution that
    // does not invade the whole ListMenu infrastructure.
    sDynamicMenuEventId = callbackSet;
    sDynamicMenuEventScratchPad = AllocZeroed(100 * sizeof(u16));
    if (sDynamicMenuEventId != DYN_MULTICHOICE_CB_NONE && sDynamicListMenuEventCollections[sDynamicMenuEventId].OnInit)
    {
        struct DynamicListMenuEventArgs eventArgs = {.selectedItem = initialRow, .windowId = windowId, .list = NULL};
        sDynamicListMenuEventCollections[sDynamicMenuEventId].OnInit(&eventArgs);
    }

    gMultiuseListMenuTemplate = sScriptableListMenuTemplate;
    gMultiuseListMenuTemplate.windowId = windowId;
    gMultiuseListMenuTemplate.items = items;
    gMultiuseListMenuTemplate.totalItems = argc;
    gMultiuseListMenuTemplate.maxShowed = maxBeforeScroll;
    gMultiuseListMenuTemplate.moveCursorFunc = MultichoiceDynamic_MoveCursor;

    taskId = CreateTask(Task_HandleScrollingMultichoiceInput, 80);
    gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
    gTasks[taskId].data[1] = ignoreBPress;
    gTasks[taskId].data[2] = windowId;
    gTasks[taskId].data[5] = argc;
    gTasks[taskId].data[7] = maxBeforeScroll;
    StoreWordInTwoHalfwords((u16*) &gTasks[taskId].data[3], (u32) items);
    list = (void *) gTasks[gTasks[taskId].data[0]].data;
    ListMenuChangeSelectionFull(list, TRUE, FALSE, initialRow, TRUE);

    if (sDynamicMenuEventId != DYN_MULTICHOICE_CB_NONE && sDynamicListMenuEventCollections[sDynamicMenuEventId].OnSelectionChanged)
    {
        struct DynamicListMenuEventArgs eventArgs = {.selectedItem = items[initialRow].id, .windowId = windowId, .list = &gMultiuseListMenuTemplate};
        sDynamicListMenuEventCollections[sDynamicMenuEventId].OnSelectionChanged(&eventArgs);
    }
    ListMenuGetScrollAndRow(gTasks[taskId].data[0], &gScrollableMultichoice_ScrollOffset, NULL);
    if (argc > maxBeforeScroll)
    {
        // Create Scrolling Arrows
        struct ScrollArrowsTemplate template;
        template.firstX = (newWidth / 2) * 8 + 12 + (left) * 8;
        template.firstY = top * 8 + 5;
        template.secondX = template.firstX;
        template.secondY = top * 8 + windowHeight * 8 + 12;
        template.fullyUpThreshold = 0;
        template.fullyDownThreshold = argc - maxBeforeScroll;
        template.firstArrowType = SCROLL_ARROW_UP;
        template.secondArrowType = SCROLL_ARROW_DOWN;
        template.tileTag = 2000;
        template.palTag = 100,
        template.palNum = 0;

        gTasks[taskId].data[6] = AddScrollIndicatorArrowPair(&template, &gScrollableMultichoice_ScrollOffset);
    }
}

void DrawMultichoiceMenuInternal(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 cursorPos, const struct MenuAction *actions, int count)
{
    int i;
    u8 windowId;
    int width = 0;
    u8 newWidth;

    for (i = 0; i < count; i++)
    {
        width = DisplayTextAndGetWidth(actions[i].text, width);
    }

    newWidth = ConvertPixelWidthToTileWidth(width);
    left = ScriptMenu_AdjustLeftCoordFromWidth(left, newWidth);
    windowId = CreateWindowFromRect(left, top, newWidth, count * 2);
    SetStandardWindowBorderStyle(windowId, FALSE);
    PrintMenuTable(windowId, count, actions);
    InitMenuInUpperLeftCornerNormal(windowId, count, cursorPos);
    ScheduleBgCopyTilemapToVram(0);
    InitMultichoiceCheckWrap(ignoreBPress, count, windowId, multichoiceId);
}

static void DrawMultichoiceMenu(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 cursorPos)
{
    DrawMultichoiceMenuInternal(left, top, multichoiceId, ignoreBPress, cursorPos, sMultichoiceLists[multichoiceId].list, sMultichoiceLists[multichoiceId].count);
}

#define tLeft           data[0]
#define tTop            data[1]
#define tRight          data[2]
#define tBottom         data[3]
#define tIgnoreBPress   data[4]
#define tDoWrap         data[5]
#define tWindowId       data[6]
#define tMultichoiceId  data[7]

static void InitMultichoiceCheckWrap(bool8 ignoreBPress, u8 count, u8 windowId, u8 multichoiceId)
{
    u8 i;
    u8 taskId;
    sProcessInputDelay = 2;

    for (i = 0; i < ARRAY_COUNT(sLinkServicesMultichoiceIds); i++)
    {
        if (sLinkServicesMultichoiceIds[i] == multichoiceId)
        {
            sProcessInputDelay = 12;
        }
    }

    taskId = CreateTask(Task_HandleMultichoiceInput, 80);

    gTasks[taskId].tIgnoreBPress = ignoreBPress;

    if (count > 3)
        gTasks[taskId].tDoWrap = TRUE;
    else
        gTasks[taskId].tDoWrap = FALSE;

    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tMultichoiceId = multichoiceId;

    DrawLinkServicesMultichoiceMenu(multichoiceId);
}

static void Task_HandleScrollingMultichoiceInput(u8 taskId)
{
    bool32 done = FALSE;
    s32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    switch (input)
    {
    case LIST_HEADER:
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        if (!gTasks[taskId].data[1])
        {
            gSpecialVar_Result = MULTI_B_PRESSED;
            done = TRUE;
        }
        break;
    default:
        gSpecialVar_Result = input;
        done = TRUE;
        break;
    }

    if (done)
    {
        struct ListMenuItem *items;

        PlaySE(SE_SELECT);

        if (sDynamicMenuEventId != DYN_MULTICHOICE_CB_NONE && sDynamicListMenuEventCollections[sDynamicMenuEventId].OnDestroy)
        {
            struct DynamicListMenuEventArgs eventArgs = {.selectedItem = input, .windowId = gTasks[taskId].data[2], .list = NULL};
            sDynamicListMenuEventCollections[sDynamicMenuEventId].OnDestroy(&eventArgs);
        }

        sDynamicMenuEventId = DYN_MULTICHOICE_CB_NONE;

        if (gTasks[taskId].data[5] > gTasks[taskId].data[7])
        {
            RemoveScrollIndicatorArrowPair(gTasks[taskId].data[6]);
        }

        LoadWordFromTwoHalfwords((u16*) &gTasks[taskId].data[3], (u32* )(&items));
        FreeListMenuItems(items, gTasks[taskId].data[5]);
        TRY_FREE_AND_SET_NULL(sDynamicMenuEventScratchPad);
        DestroyListMenuTask(gTasks[taskId].data[0], NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].data[2], TRUE);
        RemoveWindow(gTasks[taskId].data[2]);
        ScriptContext_Enable();
        DestroyTask(taskId);
    }
}

static void Task_HandleMultichoiceInput(u8 taskId)
{
    s8 selection;
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        if (sProcessInputDelay)
        {
            sProcessInputDelay--;
        }
        else
        {
            if (!tDoWrap)
                selection = Menu_ProcessInputNoWrap();
            else
                selection = Menu_ProcessInput();

            if (JOY_NEW(DPAD_UP | DPAD_DOWN))
            {
                DrawLinkServicesMultichoiceMenu(tMultichoiceId);
            }

            if (selection != MENU_NOTHING_CHOSEN)
            {
                if (selection == MENU_B_PRESSED)
                {
                    if (tIgnoreBPress)
                        return;
                    PlaySE(SE_SELECT);
                    gSpecialVar_Result = MULTI_B_PRESSED;
                }
                else
                {
                    gSpecialVar_Result = selection;
                }
                ClearToTransparentAndRemoveWindow(tWindowId);
                DestroyTask(taskId);
                ScriptContext_Enable();
            }
        }
    }
}

bool8 ScriptMenu_YesNo(u8 left, u8 top)
{
    if (FuncIsActiveTask(Task_HandleYesNoInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        DisplayYesNoMenuDefaultYes();
        CreateTask(Task_HandleYesNoInput, 0x50);
        return TRUE;
    }
}

// Unused
bool8 IsScriptActive(void)
{
    if (gSpecialVar_Result == 0xFF)
        return FALSE;
    else
        return TRUE;
}

static void Task_HandleYesNoInput(u8 taskId)
{
    if (gTasks[taskId].tRight < 5)
    {
        gTasks[taskId].tRight++;
        return;
    }

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
    case 1:
        PlaySE(SE_SELECT);
        gSpecialVar_Result = 0;
        break;
    case 0:
        gSpecialVar_Result = 1;
        break;
    }

    DestroyTask(taskId);
    ScriptContext_Enable();
}

bool8 ScriptMenu_MultichoiceGrid(u8 left, u8 top, u8 multichoiceId, bool8 ignoreBPress, u8 columnCount)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceGridInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        u8 taskId;
        u8 rowCount, newWidth;
        int i, width;

        gSpecialVar_Result = 0xFF;
        width = 0;

        for (i = 0; i < sMultichoiceLists[multichoiceId].count; i++)
        {
            width = DisplayTextAndGetWidth(sMultichoiceLists[multichoiceId].list[i].text, width);
        }

        newWidth = ConvertPixelWidthToTileWidth(width);

        left = ScriptMenu_AdjustLeftCoordFromWidth(left, columnCount * newWidth);
        rowCount = sMultichoiceLists[multichoiceId].count / columnCount;

        taskId = CreateTask(Task_HandleMultichoiceGridInput, 80);

        gTasks[taskId].tIgnoreBPress = ignoreBPress;
        gTasks[taskId].tWindowId = CreateWindowFromRect(left, top, columnCount * newWidth, rowCount * 2);
        SetStandardWindowBorderStyle(gTasks[taskId].tWindowId, FALSE);
        PrintMenuGridTable(gTasks[taskId].tWindowId, newWidth * 8, columnCount, rowCount, sMultichoiceLists[multichoiceId].list);
        InitMenuActionGrid(gTasks[taskId].tWindowId, newWidth * 8, columnCount, rowCount, 0);
        CopyWindowToVram(gTasks[taskId].tWindowId, COPYWIN_FULL);
        return TRUE;
    }
}

static void Task_HandleMultichoiceGridInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s8 selection = Menu_ProcessGridInput();

    switch (selection)
    {
    case MENU_NOTHING_CHOSEN:
        return;
    case MENU_B_PRESSED:
        if (tIgnoreBPress)
            return;
        PlaySE(SE_SELECT);
        gSpecialVar_Result = MULTI_B_PRESSED;
        break;
    default:
        gSpecialVar_Result = selection;
        break;
    }

    ClearToTransparentAndRemoveWindow(tWindowId);
    DestroyTask(taskId);
    ScriptContext_Enable();
}

#undef tWindowId

bool16 ScriptMenu_CreatePCMultichoice(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        CreatePCMultichoice();
        return TRUE;
    }
}

static void CreatePCMultichoice(void)
{
    u8 x = 8;
    u32 pixelWidth = 0;
    u8 width;
    u8 numChoices;
    u8 windowId;
    int i;

    for (i = 0; i < ARRAY_COUNT(sPCNameStrings); i++)
    {
        pixelWidth = DisplayTextAndGetWidth(sPCNameStrings[i], pixelWidth);
    }

    if (FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        pixelWidth = DisplayTextAndGetWidth(gText_HallOfFame, pixelWidth);
    }

    width = ConvertPixelWidthToTileWidth(pixelWidth);

    // Include Hall of Fame option if player is champion
    if (FlagGet(FLAG_SYS_GAME_CLEAR))
    {
        //numChoices = 4;
        //windowId = CreateWindowFromRect(0, 0, width, 8);
		numChoices = 5;
        windowId = CreateWindowFromRect(0, 0, width, 10);
        SetStandardWindowBorderStyle(windowId, FALSE);
        //AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_HallOfFame, x, 33, TEXT_SKIP_DRAW, NULL);
        //AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_LogOff, x, 49, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_SaveGame, x, 33, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_HallOfFame, x, 49, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_LogOff, x, 65, TEXT_SKIP_DRAW, NULL);
    }
    else
    {
        //numChoices = 3;
        //windowId = CreateWindowFromRect(0, 0, width, 6);
		numChoices = 4;
        windowId = CreateWindowFromRect(0, 0, width, 8);
        SetStandardWindowBorderStyle(windowId, FALSE);
        //AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_LogOff, x, 33, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_SaveGame, x, 33, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_LogOff, x, 49, TEXT_SKIP_DRAW, NULL);
    }

    // Change PC name if player has met Lanette
    if (FlagGet(FLAG_SYS_PC_LANETTE))
    {
        if (IS_FRLG)
            AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_BillsPc, x, 1, TEXT_SKIP_DRAW, NULL);
        else
            AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_LanettesPC, x, 1, TEXT_SKIP_DRAW, NULL);
    }
    else
    {
        AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_SomeonesPC, x, 1, TEXT_SKIP_DRAW, NULL);
    }

    StringExpandPlaceholders(gStringVar4, gText_PlayersPC);
    PrintPlayerNameOnWindow(windowId, gStringVar4, x, 17);
    InitMenuInUpperLeftCornerNormal(windowId, numChoices, 0);
    CopyWindowToVram(windowId, COPYWIN_FULL);
    InitMultichoiceCheckWrap(FALSE, numChoices, windowId, MULTI_PC);
}

void ScriptMenu_DisplayPCStartupPrompt(void)
{
    LoadMessageBoxAndFrameGfx(0, TRUE);
    AddTextPrinterParameterized2(0, FONT_NORMAL, gText_WhichPCShouldBeAccessed, 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
}

bool8 ScriptMenu_CreateLilycoveSSTidalMultichoice(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        CreateLilycoveSSTidalMultichoice();
        return TRUE;
    }
}

// gSpecialVar_0x8004 is 1 if the Sailor was shown multiple event tickets at the same time
// otherwise gSpecialVar_0x8004 is 0
static void CreateLilycoveSSTidalMultichoice(void)
{
    u8 selectionCount = 0;
    u8 count;
    u32 pixelWidth;
    u8 width;
    u8 windowId;
    u8 i;
    u32 j;

    for (i = 0; i < SSTIDAL_SELECTION_COUNT; i++)
    {
        sLilycoveSSTidalSelections[i] = 0xFF;
    }

    GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_WIDTH);

    //if (gSpecialVar_0x8004 == 0)
    if (FlagGet(FLAG_IS_CHAMPION) == TRUE)
    {
        sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_SLATEPORT;
        selectionCount++;

        //if (FlagGet(FLAG_MET_SCOTT_ON_SS_TIDAL) == TRUE)
        if (FlagGet(FLAG_IS_CHAMPION) == TRUE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_BATTLE_FRONTIER;
            selectionCount++;
        }
    }

    if (CheckBagHasItem(ITEM_EON_TICKET, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_SOUTHERN_ISLAND) == TRUE)
    {
        //if (gSpecialVar_0x8004 == 0)
		if (FlagGet(FLAG_IS_CHAMPION) == TRUE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_SOUTHERN_ISLAND;
            selectionCount++;
        }

        /*if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_EON_TICKET) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_SOUTHERN_ISLAND;
            selectionCount++;
            FlagSet(FLAG_SHOWN_EON_TICKET);
        }*/
    }

    //if (CheckBagHasItem(ITEM_MYSTIC_TICKET, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_NAVEL_ROCK) == TRUE)
    if (CheckBagHasItem(ITEM_RAINBOW_PASS, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_NAVEL_ROCK) == TRUE)
    {
        //if (gSpecialVar_0x8004 == 0)
		if (FlagGet(FLAG_IS_CHAMPION) == TRUE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_NAVEL_ROCK;
            selectionCount++;
        }

        /*if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_MYSTIC_TICKET) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_NAVEL_ROCK;
            selectionCount++;
            FlagSet(FLAG_SHOWN_MYSTIC_TICKET);
        }*/
    }

    /*if (CheckBagHasItem(ITEM_AURORA_TICKET, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_BIRTH_ISLAND) == TRUE)
    {
        if (gSpecialVar_0x8004 == 0)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_BIRTH_ISLAND;
            selectionCount++;
        }

        if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_AURORA_TICKET) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_BIRTH_ISLAND;
            selectionCount++;
            FlagSet(FLAG_SHOWN_AURORA_TICKET);
        }
    }*/
    if (CheckBagHasItem(ITEM_APEX_TICKET, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_PERENNIAL_PILLAR) == TRUE)
    {
        //if (gSpecialVar_0x8004 == 0)
		if (FlagGet(FLAG_IS_CHAMPION) == TRUE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_PERENNIAL_PILLAR;
            selectionCount++;
        }

        /*if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_APEX_TICKET) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_PERENNIAL_PILLAR;
            selectionCount++;
            FlagSet(FLAG_SHOWN_APEX_TICKET);
        }*/
    }

    if (CheckBagHasItem(ITEM_OLD_SEA_MAP, 1) == TRUE && FlagGet(FLAG_ENABLE_SHIP_FARAWAY_ISLAND) == TRUE)
    {
        //if (gSpecialVar_0x8004 == 0)
		if (FlagGet(FLAG_IS_CHAMPION) == TRUE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_FARAWAY_ISLAND;
            selectionCount++;
        }

        /*if (gSpecialVar_0x8004 == 1 && FlagGet(FLAG_SHOWN_OLD_SEA_MAP) == FALSE)
        {
            sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_FARAWAY_ISLAND;
            selectionCount++;
            FlagSet(FLAG_SHOWN_OLD_SEA_MAP);
        }*/
    }
	
    sLilycoveSSTidalSelections[selectionCount] = SSTIDAL_SELECTION_EXIT;
    selectionCount++;

    //if (gSpecialVar_0x8004 == 0 && FlagGet(FLAG_MET_SCOTT_ON_SS_TIDAL) == TRUE)
    if (FlagGet(FLAG_IS_CHAMPION) == TRUE)
    {
        count = selectionCount;
    }

    count = selectionCount;
    if (count == SSTIDAL_SELECTION_COUNT)
    {
        gSpecialVar_0x8004 = SCROLL_MULTI_SS_TIDAL_DESTINATION;
        ShowScrollableMultichoice();
    }
    else
    {
        pixelWidth = 0;

        for (j = 0; j < SSTIDAL_SELECTION_COUNT; j++)
        {
            u8 selection = sLilycoveSSTidalSelections[j];
            if (selection != 0xFF)
            {
                pixelWidth = DisplayTextAndGetWidth(sLilycoveSSTidalDestinations[selection], pixelWidth);
            }
        }

        width = ConvertPixelWidthToTileWidth(pixelWidth);
        windowId = CreateWindowFromRect(MAX_MULTICHOICE_WIDTH - width, (6 - count) * 2, width, count * 2);
        SetStandardWindowBorderStyle(windowId, FALSE);

        for (selectionCount = 0, i = 0; i < SSTIDAL_SELECTION_COUNT; i++)
        {
            if (sLilycoveSSTidalSelections[i] != 0xFF)
            {
                AddTextPrinterParameterized(windowId, FONT_NORMAL, sLilycoveSSTidalDestinations[sLilycoveSSTidalSelections[i]], 8, selectionCount * 16 + 1, TEXT_SKIP_DRAW, NULL);
                selectionCount++;
            }
        }

        InitMenuInUpperLeftCornerNormal(windowId, count, count - 1);
        CopyWindowToVram(windowId, COPYWIN_FULL);
        InitMultichoiceCheckWrap(FALSE, count, windowId, MULTI_SSTIDAL_LILYCOVE);
    }
}

void GetLilycoveSSTidalSelection(void)
{
    if (gSpecialVar_Result != MULTI_B_PRESSED)
    {
        gSpecialVar_Result = sLilycoveSSTidalSelections[gSpecialVar_Result];
    }
}

#define tState       data[0]
#define tMonSpecies  data[1]
#define tMonSpriteId data[2]
#define tWindowX     data[3]
#define tWindowY     data[4]
#define tWindowId    data[5]

static void Task_PokemonPicWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tState++;
        break;
    case 1:
        // Wait until state is advanced by ScriptMenu_HidePokemonPic
        break;
    case 2:
        FreeResourcesAndDestroySprite(&gSprites[task->tMonSpriteId], task->tMonSpriteId);
        task->tState++;
        break;
    case 3:
        ClearToTransparentAndRemoveWindow(task->tWindowId);
        DestroyTask(taskId);
        break;
    }
}

bool8 ScriptMenu_ShowPokemonPic(u16 species, u8 x, u8 y)
{
    u8 taskId;
    u8 spriteId;

    if (FindTaskIdByFunc(Task_PokemonPicWindow) != TASK_NONE)
    {
        return FALSE;
    }
    else
    {
        spriteId = CreateMonSprite_PicBox(species, x * 8 + 40, y * 8 + 40, 0);
        taskId = CreateTask(Task_PokemonPicWindow, 0x50);
        gTasks[taskId].tWindowId = CreateWindowFromRect(x, y, 8, 8);
        gTasks[taskId].tState = 0;
        gTasks[taskId].tMonSpecies = species;
        gTasks[taskId].tMonSpriteId = spriteId;
        gSprites[spriteId].callback = SpriteCallbackDummy;
        gSprites[spriteId].oam.priority = 0;
        SetStandardWindowBorderStyle(gTasks[taskId].tWindowId, TRUE);
        ScheduleBgCopyTilemapToVram(0);
        return TRUE;
    }
}

bool8 (*ScriptMenu_HidePokemonPic(void))(void)
{
    u8 taskId = FindTaskIdByFunc(Task_PokemonPicWindow);

    if (taskId == TASK_NONE)
        return NULL;
    gTasks[taskId].tState++;
    return IsPicboxClosed;
}

static bool8 IsPicboxClosed(void)
{
    if (FindTaskIdByFunc(Task_PokemonPicWindow) == TASK_NONE)
        return TRUE;
    else
        return FALSE;
}

#undef tState
#undef tMonSpecies
#undef tMonSpriteId
#undef tWindowX
#undef tWindowY
#undef tWindowId

u8 CreateWindowFromRect(u8 x, u8 y, u8 width, u8 height)
{
    struct WindowTemplate template = CreateWindowTemplate(0, x + 1, y + 1, width, height, 15, 100);
    u8 windowId = AddWindow(&template);
    PutWindowTilemap(windowId);
    return windowId;
}

void ClearToTransparentAndRemoveWindow(u8 windowId)
{
    ClearStdWindowAndFrameToTransparent(windowId, TRUE);
    RemoveWindow(windowId);
}

static void DrawLinkServicesMultichoiceMenu(u8 multichoiceId)
{
    switch (multichoiceId)
    {
    case MULTI_WIRELESS_NO_BERRY:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, FONT_NORMAL, sWirelessOptionsNoBerryCrush[Menu_GetCursorPos()], 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        break;
    case MULTI_CABLE_CLUB_WITH_RECORD_MIX:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, FONT_NORMAL, sCableClubOptions_WithRecordMix[Menu_GetCursorPos()], 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        break;
    case MULTI_WIRELESS_NO_RECORD:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, FONT_NORMAL, sWirelessOptions_NoRecordMix[Menu_GetCursorPos()], 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        break;
    case MULTI_WIRELESS_ALL_SERVICES:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, FONT_NORMAL, sWirelessOptions_AllServices[Menu_GetCursorPos()], 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        break;
    case MULTI_WIRELESS_NO_RECORD_BERRY:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, FONT_NORMAL, sWirelessOptions_NoRecordMixBerryCrush[Menu_GetCursorPos()], 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        break;
    case MULTI_CABLE_CLUB_NO_RECORD_MIX:
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, FONT_NORMAL, sCableClubOptions_NoRecordMix[Menu_GetCursorPos()], 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        break;
    }
}

bool16 ScriptMenu_CreateStartMenuForPokenavTutorial(void)
{
    if (FuncIsActiveTask(Task_HandleMultichoiceInput) == TRUE)
    {
        return FALSE;
    }
    else
    {
        gSpecialVar_Result = 0xFF;
        CreateStartMenuForPokenavTutorial();
        return TRUE;
    }
}

static void CreateStartMenuForPokenavTutorial(void)
{
    u8 windowId = CreateWindowFromRect(21, 0, 7, 18);
    SetStandardWindowBorderStyle(windowId, FALSE);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_MenuOptionPokedex, 8, 9, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_MenuOptionPokemon, 8, 25, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_MenuOptionBag, 8, 41, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_MenuOptionPokenav, 8, 57, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gSaveBlock2Ptr->playerName, 8, 73, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_MenuOptionSave, 8, 89, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_MenuOptionOption, 8, 105, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_MenuOptionExit, 8, 121, TEXT_SKIP_DRAW, NULL);
    InitMenuNormal(windowId, FONT_NORMAL, 0, 9, 16, ARRAY_COUNT(MultichoiceList_ForcedStartMenu), 0);
    InitMultichoiceNoWrap(FALSE, ARRAY_COUNT(MultichoiceList_ForcedStartMenu), windowId, MULTI_FORCED_START_MENU);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

#define tWindowId       data[6]

static void InitMultichoiceNoWrap(bool8 ignoreBPress, u8 unusedCount, u8 windowId, u8 multichoiceId)
{
    u8 taskId;
    sProcessInputDelay = 2;
    taskId = CreateTask(Task_HandleMultichoiceInput, 80);
    gTasks[taskId].tIgnoreBPress = ignoreBPress;
    gTasks[taskId].tDoWrap = 0;
    gTasks[taskId].tWindowId = windowId;
    gTasks[taskId].tMultichoiceId = multichoiceId;
}

#undef tLeft
#undef tTop
#undef tRight
#undef tBottom
#undef tIgnoreBPress
#undef tDoWrap
#undef tWindowId
#undef tMultichoiceId

static int DisplayTextAndGetWidthInternal(const u8 *str)
{
    u8 temp[64];
    StringExpandPlaceholders(temp, str);
    return GetStringWidth(FONT_NORMAL, temp, 0);
}

int DisplayTextAndGetWidth(const u8 *str, int prevWidth)
{
    int width = DisplayTextAndGetWidthInternal(str);
    if (width < prevWidth)
    {
        width = prevWidth;
    }
    return width;
}

int ConvertPixelWidthToTileWidth(int width)
{
    return (((width + 9) / 8) + 1) > MAX_MULTICHOICE_WIDTH ? MAX_MULTICHOICE_WIDTH : (((width + 9) / 8) + 1);
}

int ScriptMenu_AdjustLeftCoordFromWidth(int left, int width)
{
    int adjustedLeft = left;

    if (left + width > MAX_MULTICHOICE_WIDTH)
    {
        if (MAX_MULTICHOICE_WIDTH - width < 0)
        {
            adjustedLeft = 0;
        }
        else
        {
            adjustedLeft = MAX_MULTICHOICE_WIDTH - width;
        }
    }

    return adjustedLeft;
}


// FRLG
#define FOSSIL_PIC_PAL_NUM  13

bool8 OpenMuseumFossilPic(void)
{
    // u8 spriteId;
    // u8 taskId;
    // if (QL_AvoidDisplay(QL_DestroyAbortedDisplay) == TRUE)
    //     return TRUE;
    // if (FindTaskIdByFunc(Task_WaitMuseumFossilPic) != TASK_NONE)
    //     return FALSE;
    // if (gSpecialVar_0x8004 == SPECIES_KABUTOPS)
    // {
    //     LoadSpriteSheets(sMuseumKabutopsSprSheets);
    //     LoadPalette(sMuseumKabutopsSprPalette, OBJ_PLTT_ID(FOSSIL_PIC_PAL_NUM), sizeof(sMuseumKabutopsSprPalette));
    // }
    // else if (gSpecialVar_0x8004 == SPECIES_AERODACTYL)
    // {
    //     LoadSpriteSheets(sMuseumAerodactylSprSheets);
    //     LoadPalette(sMuseumAerodactylSprPalette, OBJ_PLTT_ID(FOSSIL_PIC_PAL_NUM), sizeof(sMuseumAerodactylSprPalette));
    // }
    // else
    // {
    //     return FALSE;
    // }
    // spriteId = CreateSprite(&sMuseumFossilSprTemplate, gSpecialVar_0x8005 * 8 + 40, gSpecialVar_0x8006 * 8 + 40, 0);
    // gSprites[spriteId].oam.paletteNum = FOSSIL_PIC_PAL_NUM;
    // taskId = CreateTask(Task_WaitMuseumFossilPic, 80);
    // gTasks[taskId].tWindowId = CreateWindowFromRect(gSpecialVar_0x8005, gSpecialVar_0x8006, 8, 8);
    // gTasks[taskId].tState = 0;
    // gTasks[taskId].tSpriteId = spriteId;
    // SetStandardWindowBorderStyle(gTasks[taskId].tWindowId, TRUE);
    // ScheduleBgCopyTilemapToVram(0);
    return TRUE;
}

bool8 CloseMuseumFossilPic(void)
{
    // u8 taskId = FindTaskIdByFunc(Task_WaitMuseumFossilPic);
    // if (taskId == TASK_NONE)
    //     return FALSE;
    // gTasks[taskId].tState++;
    return TRUE;
}

static const u8 sText_Other[] = _("OTHER");

void DrawSeagallopDestinationMenu(void)
{
    // 8004 = Starting location
    // 8005 = Page (0: Verm, One, Two, Three, Four, Other, Exit; 1: Four, Five, Six, Seven, Other, Exit)
    u8 destinationId;
    u8 top;
    u8 numItems;
    u8 cursorWidth;
    u8 UNUSED fontHeight;
    u8 windowId;
    u8 i;
    gSpecialVar_Result = 0xFF;

    if (gSpecialVar_0x8005 == 1)
    {
        if (gSpecialVar_0x8004 < SEAGALLOP_FIVE_ISLAND)
            destinationId = SEAGALLOP_FIVE_ISLAND;
        else
            destinationId = SEAGALLOP_FOUR_ISLAND;
        numItems = 5;
        top = 2;
    }
    else
    {
        destinationId = SEAGALLOP_VERMILION_CITY;
        numItems = 6;
        top = 0;
    }
    cursorWidth = GetMenuCursorDimensionByFont(FONT_NORMAL, 0);
    fontHeight = GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT);
    windowId = CreateWindowFromRect(17, top, 11, numItems * 2);
    SetStandardWindowBorderStyle(windowId, FALSE);

    // -2 excludes "Other" and "Exit", appended after the loop
    for (i = 0; i < numItems - 2; i++)
    {
        if (destinationId != gSpecialVar_0x8004)
            AddTextPrinterParameterized(windowId, FONT_NORMAL, sSeagallopDestStrings[destinationId], cursorWidth, i * 16 + 2, TEXT_SKIP_DRAW, NULL);
        else
            i--;
        destinationId++;

        // Wrap around
        if (destinationId == SEAGALLOP_SEVEN_ISLAND + 1)
            destinationId = SEAGALLOP_VERMILION_CITY;
    }
    AddTextPrinterParameterized(windowId, FONT_NORMAL, sText_Other, cursorWidth, i * 16 + 2, TEXT_SKIP_DRAW, NULL);
    i++;
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_Exit, cursorWidth, i * 16 + 2, TEXT_SKIP_DRAW, NULL);
    InitMenuNormal(windowId, FONT_NORMAL, 0, 2, 16, numItems, 0);
    InitMultichoiceCheckWrap(FALSE, numItems, windowId, MULTI_NONE);
    ScheduleBgCopyTilemapToVram(0);
}

u16 GetSelectedSeagallopDestination(void)
{
    // 8004 = Starting location
    // 8005 = Page (0: Verm, One, Two, Three, Four, Other, Exit; 1: Four, Five, Six, Seven, Other, Exit)
    if (gSpecialVar_Result == MULTI_B_PRESSED)
        return MULTI_B_PRESSED;
    if (gSpecialVar_0x8005 == 1)
    {
        if (gSpecialVar_Result == 3)
        {
            return SEAGALLOP_MORE;
        }
        else if (gSpecialVar_Result == 4)
        {
            return MULTI_B_PRESSED;
        }
        else if (gSpecialVar_Result == 0)
        {
            if (gSpecialVar_0x8004 > SEAGALLOP_FOUR_ISLAND)
                return SEAGALLOP_FOUR_ISLAND;
            else
                return SEAGALLOP_FIVE_ISLAND;
        }
        else if (gSpecialVar_Result == 1)
        {
            if (gSpecialVar_0x8004 > SEAGALLOP_FIVE_ISLAND)
                return SEAGALLOP_FIVE_ISLAND;
            else
                return SEAGALLOP_SIX_ISLAND;
        }
        else if (gSpecialVar_Result == 2)
        {
            if (gSpecialVar_0x8004 > SEAGALLOP_SIX_ISLAND)
                return SEAGALLOP_SIX_ISLAND;
            else
                return SEAGALLOP_SEVEN_ISLAND;
        }
    }
    else
    {
        if (gSpecialVar_Result == 4)
            return SEAGALLOP_MORE;
        else if (gSpecialVar_Result == 5)
            return MULTI_B_PRESSED;
        else if (gSpecialVar_Result >= gSpecialVar_0x8004)
            return gSpecialVar_Result + 1;
        else
            return gSpecialVar_Result;
    }
    return SEAGALLOP_VERMILION_CITY;
}

/////////////////////////////////////////////////
////////// SCROLLING MULTICHOICE MENUS //////////
/////////////////////////////////////////////////

static const u8 sText_TutorCancel[] = _("Cancel");

// Green shard tutor
static const u8 sText_Green1[] = _("2. Helping Hand");
static const u8 sText_Green2[] = _("2. Sonar Wave");
static const u8 sText_Green3[] = _("2. Snore");
static const u8 sText_Green4[] = _("4. Charm");
static const u8 sText_Green5[] = _("4. Defog");
static const u8 sText_Green6[] = _("4. Endure");
static const u8 sText_Green7[] = _("4. Gastro Acid");
static const u8 sText_Green8[] = _("6. Dream Eater");
static const u8 sText_Green9[] = _("6. Magnet Rise");
static const u8 sText_Green10[] = _("6. Petrify");
static const u8 sText_Green11[] = _("6. Recycle");
static const u8 sText_Green12[] = _("6. Worry Seed");
static const u8 sText_Green13[] = _("8. Magic Room");
static const u8 sText_Green14[] = _("8. Pain Split");
static const u8 sText_Green15[] = _("8. Seismic Toss");
static const u8 sText_Green16[] = _("8. Wonder Room");
static const u8 sText_Green17[] = _("10. Fling");
static const u8 sText_Green18[] = _("10. Gravity");
static const u8 sText_Green19[] = _("10. Tailwind");
static const u8 sText_Green20[] = _("12. Last Resort");
static const u8 sText_Green21[] = _("12. Sleep Talk");
static const u8 sText_Green22[] = _("14. Foul Play");

// Red shard tutor
static const u8 sText_Red1[] = _("2. Covet");
static const u8 sText_Red2[] = _("2. Fury Cutter");
static const u8 sText_Red3[] = _("2. Low Kick");
static const u8 sText_Red4[] = _("4. Counter");
static const u8 sText_Red5[] = _("4. Knock Off");
static const u8 sText_Red6[] = _("4. Retaliate");
static const u8 sText_Red7[] = _("4. Secret Power");
static const u8 sText_Red8[] = _("6. Bounce");
static const u8 sText_Red9[] = _("6. Drain Punch");
static const u8 sText_Red10[] = _("6. Iron Head");
static const u8 sText_Red11[] = _("6. Mega Punch");
static const u8 sText_Red12[] = _("6. Zen Headbutt");
static const u8 sText_Red13[] = _("8. Flip Turn");
static const u8 sText_Red14[] = _("8. Gyro Ball");
static const u8 sText_Red15[] = _("8. Iron Tail");
static const u8 sText_Red16[] = _("8. Wild Frenzy");
static const u8 sText_Red17[] = _("10. Fire Punch");
static const u8 sText_Red18[] = _("10. Ice Punch");
static const u8 sText_Red19[] = _("10. Thunder Punch");
static const u8 sText_Red20[] = _("12. Mega Kick");
static const u8 sText_Red21[] = _("12. Superpower");
static const u8 sText_Red22[] = _("14. Body Press");

// Blue shard tutor
static const u8 sText_Blue1[] = _("2. Incinerate");
static const u8 sText_Blue2[] = _("2. Sand Tomb");
static const u8 sText_Blue3[] = _("2. Whirlpool");
static const u8 sText_Blue4[] = _("4. Icy Wind");
static const u8 sText_Blue5[] = _("4. Struggle Bug");
static const u8 sText_Blue6[] = _("4. Swift");
static const u8 sText_Blue7[] = _("4. Vacuum Wave");
static const u8 sText_Blue8[] = _("6. Giga Drain");
static const u8 sText_Blue9[] = _("6. Signal Beam");
static const u8 sText_Blue10[] = _("6. Phreno Attack");
static const u8 sText_Blue11[] = _("6. Soma Attack");
static const u8 sText_Blue12[] = _("6. Tri Attack");
static const u8 sText_Blue13[] = _("8. Blue Noise");
static const u8 sText_Blue14[] = _("8. Psychosis");
static const u8 sText_Blue15[] = _("8. Drone Wave");
static const u8 sText_Blue16[] = _("8. Volt Switch");
static const u8 sText_Blue17[] = _("10. Dragon Pulse");
static const u8 sText_Blue18[] = _("10. Earth Power");
static const u8 sText_Blue19[] = _("10. Psyshock");
static const u8 sText_Blue20[] = _("12. Heat Wave");
static const u8 sText_Blue21[] = _("12. UV Burst");
static const u8 sText_Blue22[] = _("14. Force of Will");

// Yellow shard tutor
static const u8 sText_Yellow1[] = _("2. Baby Doll Eyes");
static const u8 sText_Yellow2[] = _("2. Heal Bell");
static const u8 sText_Yellow3[] = _("2. Confide");
static const u8 sText_Yellow4[] = _("4. Crystalize");
static const u8 sText_Yellow5[] = _("4. Iron Defense");
static const u8 sText_Yellow6[] = _("4. Quash");
static const u8 sText_Yellow7[] = _("4. Spite");
static const u8 sText_Yellow8[] = _("6. Aurora Veil");
static const u8 sText_Yellow9[] = _("6. Darkness Dream");
static const u8 sText_Yellow10[] = _("6. Embargo");
static const u8 sText_Yellow11[] = _("6. Super Fang");
static const u8 sText_Yellow12[] = _("6. Role Play");
static const u8 sText_Yellow13[] = _("8. Roost");
static const u8 sText_Yellow14[] = _("8. Softboiled");
static const u8 sText_Yellow15[] = _("8. Shore Up");
static const u8 sText_Yellow16[] = _("8. Synthesis");
static const u8 sText_Yellow17[] = _("10. Endeavor");
static const u8 sText_Yellow18[] = _("10. Snatch");
static const u8 sText_Yellow19[] = _("10. Trick");
static const u8 sText_Yellow20[] = _("12. Fairy Dust");
static const u8 sText_Yellow21[] = _("12. Stealth Rock");
static const u8 sText_Yellow22[] = _("14. Baton Pass");

// Weather explainer
static const u8 sText_FullMoon[] = _("Full Moon");
static const u8 sText_Hail[] = _("Hail");
static const u8 sText_RainDance[] = _("Rain Dance");
static const u8 sText_Sandstorm[] = _("Sandstorm");
static const u8 sText_Smaze[] = _("Smaze");
static const u8 sText_SunnyDay[] = _("Sunny Day");

// Status explainer
static const u8 sText_BRN[] = _("BRN");
static const u8 sText_DAZ[] = _("DAZ");
static const u8 sText_EXH[] = _("EXH");
static const u8 sText_FER[] = _("FER");
static const u8 sText_FRZ[] = _("FRZ");
static const u8 sText_INF[] = _("INF");
static const u8 sText_PAR[] = _("PAR");
static const u8 sText_PSN[] = _("PSN");
static const u8 sText_SLP[] = _("SLP");

// Xanthos Library quiz
static const u8 sText_Bug[] = _("BUG");
static const u8 sText_Echo[] = _("ECHO");
static const u8 sText_Electric[] = _("ELECTRIC");
static const u8 sText_Fairy[] = _("FAIRY");
static const u8 sText_Fighting[] = _("FIGHTING");
static const u8 sText_Grass[] = _("GRASS");
static const u8 sText_Ground[] = _("GROUND");
static const u8 sText_Ice[] = _("ICE");
static const u8 sText_Normal[] = _("NORMAL");
static const u8 sText_Poison[] = _("POISON");
static const u8 sText_Rock[] = _("ROCK");
static const u8 sText_Steel[] = _("STEEL");
static const u8 sText_Water[] = _("WATER");

// Pledge tutor
static const u8 sText_GrassPledge[] = _("Grass Pledge");
static const u8 sText_FirePledge[] = _("Fire Pledge");
static const u8 sText_WaterPledge[] = _("Water Pledge");

// Elemntal HB tutor
static const u8 sText_FrenzyPlant[] = _("Frenzy Plant");
static const u8 sText_BlastBurn[] = _("Blast Burn");
static const u8 sText_HydroCannon[] = _("Hydro Cannon");

// Nature Changer
static const u8 sText_Hardy[] = _("Hardy");
static const u8 sText_Lonely[] = _("Lonely");
static const u8 sText_Brave[] = _("Brave");
static const u8 sText_Adamant[] = _("Adamant");
static const u8 sText_Naughty[] = _("Naughty");
static const u8 sText_Bold[] = _("Bold");
static const u8 sText_Docile[] = _("Docile");
static const u8 sText_Relaxed[] = _("Relaxed");
static const u8 sText_Impish[] = _("Impish");
static const u8 sText_Lax[] = _("Lax");
static const u8 sText_Timid[] = _("Timid");
static const u8 sText_Hasty[] = _("Hasty");
static const u8 sText_Serious[] = _("Serious");
static const u8 sText_Jolly[] = _("Jolly");
static const u8 sText_Naive[] = _("Naive");
static const u8 sText_Modest[] = _("Modest");
static const u8 sText_Mild[] = _("Mild");
static const u8 sText_Quiet[] = _("Quiet");
static const u8 sText_Bashful[] = _("Bashful");
static const u8 sText_Rash[] = _("Rash");
static const u8 sText_Calm[] = _("Calm");
static const u8 sText_Gentle[] = _("Gentle");
static const u8 sText_Sassy[] = _("Sassy");
static const u8 sText_Careful[] = _("Careful");
static const u8 sText_Quirky[] = _("Quirky");

// Game Corner Item Prizes
static const u8 sText_DubiousDisc[] = _("Dubious Disc (1000c)");
static const u8 sText_KingsRock[] =   _("King's Rock (1000c)");
static const u8 sText_OniMask[] =     _("Oni Mask (1000c)");
static const u8 sText_ReaperCloth[] = _("Reaper Cloth (1000c)");
static const u8 sText_Upgrade[] =     _("Upgrade (1000c)");

// Game Corner Pokemon Prizes
static const u8 sText_Solosis[] =   _("Solosis (800c)");
static const u8 sText_Cryogonal[] = _("Cryogonal (1600c)");
static const u8 sText_Klefki[] =    _("Klefki (3200c)");
static const u8 sText_Larvitar[] =  _("Larvitar (4800c)");
static const u8 sText_Beldum[] =    _("Beldum (4800c)");
static const u8 sText_Deino[] =     _("Deino (4800c)");
static const u8 sText_Dreepy[] =    _("Dreepy (4800c)");
static const u8 sText_Porygon[] =   _("Porygon (9999c)");

// Starters
static const u8 sText_Bulbasaur[] = _("Bulbasaur");
static const u8 sText_Chikorita[] = _("Chikorita");
static const u8 sText_Treecko[] = _("Treecko");
static const u8 sText_Turtwig[] = _("Turtwig");
static const u8 sText_Snivy[] = _("Snivy");
static const u8 sText_Chespin[] = _("Chespin");
static const u8 sText_Rowlet[] = _("Rowlet");
static const u8 sText_Grookey[] = _("Grookey");

static const u8 sText_Charmander[] = _("Charmander");
static const u8 sText_Cyndaquil[] = _("Cyndaquil");
static const u8 sText_Torchic[] = _("Torchic");
static const u8 sText_Chimchar[] = _("Chimchar");
static const u8 sText_Tepig[] = _("Tepig");
static const u8 sText_Fennekin[] = _("Fennekin");
static const u8 sText_Litten[] = _("Litten");
static const u8 sText_Scorbunny[] = _("Scorbunny");

static const u8 sText_Squirtle[] = _("Squirtle");
static const u8 sText_Totodile[] = _("Totodile");
static const u8 sText_Mudkip[] = _("Mudkip");
static const u8 sText_Piplup[] = _("Piplup");
static const u8 sText_Oshawott[] = _("Oshawott");
static const u8 sText_Froakie[] = _("Froakie");
static const u8 sText_Popplio[] = _("Popplio");
static const u8 sText_Sobble[] = _("Sobble");

static const u8 sText_Pikachu[] = _("Pikachu");
static const u8 sText_Plusle[] = _("Plusle");
static const u8 sText_Minun[] = _("Minun");
static const u8 sText_Pachirisu[] = _("Pachirisu");
static const u8 sText_Emolga[] = _("Emolga");
static const u8 sText_Dedenne[] = _("Dedenne");
static const u8 sText_Togedemaru[] = _("Togedemaru");
static const u8 sText_Morpeko[] = _("Morpeko");

// Kendom Corp burglar
static const u8 sText_ClearanceACard[] =  _("Clearance A Card");
static const u8 sText_ClearanceBCard[] =  _("Clearance B Card");

// Underground City burglar
static const u8 sText_GenesisACard[] =  _("Genesis A Card");
static const u8 sText_GenesisBCard[] =  _("Genesis B Card");
static const u8 sText_GenesisCCard[] =  _("Genesis C Card");

// Sets of multichoices.
static const struct ListMenuItem sUndergroundCityBurglar[] =
{
    {sText_GenesisACard,        0},
    {sText_GenesisBCard,        1},
    {sText_GenesisCCard,        2},
	{sText_TutorCancel,         3},
};

static const struct ListMenuItem sKendomCorpBurglar[] =
{
    {sText_ClearanceACard,        0},
    {sText_ClearanceBCard,        1},
	{sText_TutorCancel,           2},
};

static const struct ListMenuItem sGrassStarters[] =
{
    {sText_Bulbasaur,        0},
    {sText_Chikorita,        1},
    {sText_Treecko,          2},
    {sText_Turtwig,          3},
    {sText_Snivy,            4},
    {sText_Chespin,          5},
    {sText_Rowlet,           6},
    {sText_Grookey,          7},
	{sText_TutorCancel,      8},
};

static const struct ListMenuItem sFireStarters[] =
{
    {sText_Charmander,       0},
    {sText_Cyndaquil,        1},
    {sText_Torchic,          2},
    {sText_Chimchar,         3},
    {sText_Tepig,            4},
    {sText_Fennekin,         5},
    {sText_Litten,           6},
    {sText_Scorbunny,        7},
	{sText_TutorCancel,      8},
};

static const struct ListMenuItem sWaterStarters[] =
{
    {sText_Squirtle,         0},
    {sText_Totodile,         1},
    {sText_Mudkip,           2},
    {sText_Piplup,           3},
    {sText_Oshawott,         4},
    {sText_Froakie,          5},
    {sText_Popplio,          6},
    {sText_Sobble,           7},
	{sText_TutorCancel,      8},
};

static const struct ListMenuItem sElectricStarters[] =
{
    {sText_Pikachu,          0},
    {sText_Plusle,           1},
    {sText_Minun,            2},
    {sText_Pachirisu,        3},
    {sText_Emolga,           4},
    {sText_Dedenne,          5},
    {sText_Togedemaru,       6},
    {sText_Morpeko,          7},
	{sText_TutorCancel,      8},
};

static const struct ListMenuItem sGameCornerItems[] =
{
    {sText_DubiousDisc,    0},
    {sText_KingsRock,      1},
    {sText_OniMask,        2},
    {sText_ReaperCloth,    3},
    {sText_Upgrade,        4},
	{sText_TutorCancel,    5},
};

static const struct ListMenuItem sGameCornerMons[] =
{
    {sText_Solosis,       0},
    {sText_Cryogonal,     1},
    {sText_Klefki,        2},
    {sText_Larvitar,      3},
    {sText_Beldum,        4},
    {sText_Deino,         5},
    {sText_Dreepy,        6},
    {sText_Porygon,       7},
	{sText_TutorCancel,   8},
};

static const struct ListMenuItem sQuizQuestion1[] =
{
    {sText_Echo,    0},
    {sText_Ice,     1},
    {sText_Water,   2},
    {sText_Grass,   3},
};

static const struct ListMenuItem sQuizQuestion2[] =
{
    {sText_Poison,     0},
    {sText_Echo,       1},
    {sText_Steel,      2},
    {sText_Fighting,   3},
};

static const struct ListMenuItem sQuizQuestion3[] =
{
    {sText_Electric,   0},
    {sText_Ground,     1},
    {sText_Ice,        2},
    {sText_Poison,     3},
};

static const struct ListMenuItem sQuizQuestion4[] =
{
    {sText_Rock,       0},
    {sText_Water,      1},
    {sText_Normal,     2},
    {sText_Echo,       3},
};

static const struct ListMenuItem sQuizQuestion5[] =
{
    {sText_Normal,  0},
    {sText_Steel,   1},
    {sText_Echo,    2},
    {sText_Rock,    3},
};

static const struct ListMenuItem sWeatherExplainer[] =
{
    {sText_FullMoon,    0},
    {sText_Hail,        1},
    {sText_RainDance,   2},
    {sText_Sandstorm,   3},
    {sText_Smaze,       4},
    {sText_SunnyDay,    5},
	{sText_TutorCancel, 6},
};

static const struct ListMenuItem sStatusExplainer[] =
{
    {sText_BRN,   0},
    {sText_DAZ,   1},
    {sText_EXH,   2},
    {sText_FER,   3},
    {sText_FRZ,   4},
    {sText_INF,   5},
    {sText_PAR,   6},
    {sText_PSN,   7},
    {sText_SLP,   8},
	{sText_TutorCancel, 9},
};

static const struct ListMenuItem sGreenSet[] =
{
    {sText_Green1,   0},
    {sText_Green2,   1},
    {sText_Green3,   2},
    {sText_Green4,   3},
    {sText_Green5,   4},
    {sText_Green6,   5},
    {sText_Green7,   6},
    {sText_Green8,   7},
    {sText_Green9,   8},
	{sText_Green10,  9},
	{sText_Green11, 10},
    {sText_Green12, 11},
    {sText_Green13, 12},
    {sText_Green14, 13},
    {sText_Green15, 14},
    {sText_Green16, 15},
    {sText_Green17, 16},
    {sText_Green18, 17},
    {sText_Green19, 18},
	{sText_Green20, 19},
	{sText_Green21, 20},
	{sText_Green22, 21},
	{sText_TutorCancel, 22},
};

static const struct ListMenuItem sRedSet[] =
{
    {sText_Red1,   0},
    {sText_Red2,   1},
    {sText_Red3,   2},
    {sText_Red4,   3},
    {sText_Red5,   4},
    {sText_Red6,   5},
    {sText_Red7,   6},
    {sText_Red8,   7},
    {sText_Red9,   8},
	{sText_Red10,  9},
	{sText_Red11, 10},
    {sText_Red12, 11},
    {sText_Red13, 12},
    {sText_Red14, 13},
    {sText_Red15, 14},
    {sText_Red16, 15},
    {sText_Red17, 16},
    {sText_Red18, 17},
    {sText_Red19, 18},
	{sText_Red20, 19},
	{sText_Red21, 20},
	{sText_Red22, 21},
	{sText_TutorCancel, 22},
};

static const struct ListMenuItem sBlueSet[] =
{
    {sText_Blue1,   0},
    {sText_Blue2,   1},
    {sText_Blue3,   2},
    {sText_Blue4,   3},
    {sText_Blue5,   4},
    {sText_Blue6,   5},
    {sText_Blue7,   6},
    {sText_Blue8,   7},
    {sText_Blue9,   8},
	{sText_Blue10,  9},
	{sText_Blue11, 10},
    {sText_Blue12, 11},
    {sText_Blue13, 12},
    {sText_Blue14, 13},
    {sText_Blue15, 14},
    {sText_Blue16, 15},
    {sText_Blue17, 16},
    {sText_Blue18, 17},
    {sText_Blue19, 18},
	{sText_Blue20, 19},
	{sText_Blue21, 20},
	{sText_Blue22, 21},
	{sText_TutorCancel, 22},
};

static const struct ListMenuItem sYellowSet[] =
{
    {sText_Yellow1,   0},
    {sText_Yellow2,   1},
    {sText_Yellow3,   2},
    {sText_Yellow4,   3},
    {sText_Yellow5,   4},
    {sText_Yellow6,   5},
    {sText_Yellow7,   6},
    {sText_Yellow8,   7},
    {sText_Yellow9,   8},
	{sText_Yellow10,  9},
	{sText_Yellow11, 10},
    {sText_Yellow12, 11},
    {sText_Yellow13, 12},
    {sText_Yellow14, 13},
    {sText_Yellow15, 14},
    {sText_Yellow16, 15},
    {sText_Yellow17, 16},
    {sText_Yellow18, 17},
    {sText_Yellow19, 18},
	{sText_Yellow20, 19},
	{sText_Yellow21, 20},
	{sText_Yellow22, 21},
	{sText_TutorCancel, 22},
};

static const struct ListMenuItem sPledgeTutor[] =
{
    {sText_GrassPledge,   0},
    {sText_FirePledge,    1},
    {sText_WaterPledge,   2},
	{sText_TutorCancel,   3},
};

static const struct ListMenuItem sElementalHBTutor[] =
{
    {sText_GrassPledge,   0},
    {sText_FirePledge,    1},
    {sText_WaterPledge,   2},
	{sText_TutorCancel,   3},
};

static const struct ListMenuItem sNatureChanger[] =
{
	{sText_Hardy,           0},
	{sText_Lonely,          1},
	{sText_Brave,           2},
	{sText_Adamant,         3},
	{sText_Naughty,         4},
	{sText_Bold,            5},
	{sText_Docile,          6},
	{sText_Relaxed,         7},
	{sText_Impish,          8},
	{sText_Lax,             9},
	{sText_Timid,           10},
	{sText_Hasty,           11},
	{sText_Serious,         12},
	{sText_Jolly,           13},
	{sText_Naive,           14},
	{sText_Modest,          15},
	{sText_Mild,            16},
	{sText_Quiet,           17},
	{sText_Bashful,         18},
	{sText_Rash,            19},
	{sText_Calm,            20},
	{sText_Gentle,          21},
	{sText_Sassy,           22},
	{sText_Careful,         23},
	{sText_Quirky,          24},
	{sText_TutorCancel,     25},
};

// Table of your multichoice sets.
struct
{
    const struct ListMenuItem *set;
    int count;
} static const sScrollingSets[] =
{
    {sGreenSet, ARRAY_COUNT(sGreenSet)},
    {sRedSet, ARRAY_COUNT(sRedSet)},
	{sBlueSet, ARRAY_COUNT(sBlueSet)},
	{sYellowSet, ARRAY_COUNT(sYellowSet)},
	{sStatusExplainer, ARRAY_COUNT(sStatusExplainer)},
	{sWeatherExplainer, ARRAY_COUNT(sWeatherExplainer)},
	{sQuizQuestion1, ARRAY_COUNT(sQuizQuestion1)},
	{sQuizQuestion2, ARRAY_COUNT(sQuizQuestion2)},
	{sQuizQuestion3, ARRAY_COUNT(sQuizQuestion3)},
	{sQuizQuestion4, ARRAY_COUNT(sQuizQuestion4)},
	{sQuizQuestion5, ARRAY_COUNT(sQuizQuestion5)},
	{sPledgeTutor, ARRAY_COUNT(sPledgeTutor)},
	{sElementalHBTutor, ARRAY_COUNT(sElementalHBTutor)},
	{sNatureChanger, ARRAY_COUNT(sNatureChanger)},
	{sGameCornerItems, ARRAY_COUNT(sGameCornerItems)},
	{sGameCornerMons, ARRAY_COUNT(sGameCornerMons)},
	{sGrassStarters, ARRAY_COUNT(sGrassStarters)},
	{sFireStarters, ARRAY_COUNT(sFireStarters)},
	{sWaterStarters, ARRAY_COUNT(sWaterStarters)},
	{sElectricStarters, ARRAY_COUNT(sElectricStarters)},
	{sKendomCorpBurglar, ARRAY_COUNT(sKendomCorpBurglar)},
	{sUndergroundCityBurglar, ARRAY_COUNT(sUndergroundCityBurglar)},
};

static void Task_ScrollingMultichoiceInput(u8 taskId);

static const struct ListMenuTemplate sMultichoiceListTemplate =
{
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = 1,
    .cursorKind = 0
};

// 0x8004 = set id
// 0x8005 = window X
// 0x8006 = window y
// 0x8007 = showed at once
// 0x8008 = Allow B press
void ScriptMenu_ScrollingMultichoice(void)
{
    int i, windowId, taskId, width = 0;
    int setId = gSpecialVar_0x8004;
    int left = gSpecialVar_0x8005;
    int top = gSpecialVar_0x8006;
    int maxShowed = gSpecialVar_0x8007;

    for (i = 0; i < sScrollingSets[setId].count; i++)
        width = DisplayTextAndGetWidth(sScrollingSets[setId].set[i].name, width);

    width = ConvertPixelWidthToTileWidth(width);
    left = ScriptMenu_AdjustLeftCoordFromWidth(left, width);
    windowId = CreateWindowFromRect(left, top, width, maxShowed * 2);
    SetStandardWindowBorderStyle(windowId, 0);
    CopyWindowToVram(windowId, 3);

    gMultiuseListMenuTemplate = sMultichoiceListTemplate;
    gMultiuseListMenuTemplate.windowId = windowId;
    gMultiuseListMenuTemplate.items = sScrollingSets[setId].set;
    gMultiuseListMenuTemplate.totalItems = sScrollingSets[setId].count;
    gMultiuseListMenuTemplate.maxShowed = maxShowed;

    taskId = CreateTask(Task_ScrollingMultichoiceInput, 0);
    gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
    gTasks[taskId].data[1] = gSpecialVar_0x8008;
    gTasks[taskId].data[2] = windowId;
}

static void Task_ScrollingMultichoiceInput(u8 taskId)
{
    bool32 done = FALSE;
    s32 input = ListMenu_ProcessInput(gTasks[taskId].data[0]);

    switch (input)
    {
    case LIST_HEADER:
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        if (gTasks[taskId].data[1])
        {
            gSpecialVar_Result = 0x7F;
            done = TRUE;
        }
        break;
    default:
        gSpecialVar_Result = input;
        done = TRUE;
        break;
    }

    if (done)
    {
        DestroyListMenuTask(gTasks[taskId].data[0], NULL, NULL);
        ClearStdWindowAndFrame(gTasks[taskId].data[2], TRUE);
        RemoveWindow(gTasks[taskId].data[2]);
        //EnableBothScriptContexts();
        DestroyTask(taskId);
		ScriptContext_Enable();
    }
}
