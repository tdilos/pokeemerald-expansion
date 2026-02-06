#ifndef GUARD_MIRAGE_PALACE_H
#define GUARD_MIRAGE_PALACE_H

extern u8 gNumSafariBalls;

bool32 GetMiragePalaceFlag(void);
void SetMiragePalaceFlag(void);
void ResetMiragePalaceFlag(void);

void EnterMiragePalace(void);
void ExitMiragePalace(void);

bool8 MiragePalaceTakeStep(void);


#endif // GUARD_MIRAGE_PALACE_H
