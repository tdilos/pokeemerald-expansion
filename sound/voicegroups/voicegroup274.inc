	.align 2
voicegroup274:: @ BW basic
	voice_keysplit voicegroup195, KeySplitTable35	@ piano
	voice_keysplit voicegroup196, KeySplitTable36	@ rock piano
	voice_keysplit voicegroup235, KeySplitTable37	@ piano octave
	voice_keysplit voicegroup236, KeySplitTable9	@ rhodes 1
	voice_keysplit voicegroup237, KeySplitTable9	@ rhodes 2
	voice_keysplit voicegroup200, KeySplitTable11	@ vibraphone
	voice_keysplit voicegroup239, KeySplitTable38	@ marimba
	voice_keysplit voicegroup202, KeySplitTable13    @ xylophone
	voice_keysplit voicegroup241, KeySplitTable25	@ tubular bell
	voice_keysplit voicegroup242, KeySplitTable36   @ glockenspiel
	voice_keysplit voicegroup243, KeySplitTable38	@ music box
	voice_keysplit voicegroup205, KeySplitTable16    @ rotary organ
	voice_keysplit voicegroup206, KeySplitTable17    @ straight organ
	voice_keysplit voicegroup207, KeySplitTable18    @ accordion
	voice_keysplit voicegroup247, KeySplitTable41    @ nylon guitar
	voice_keysplit voicegroup208, KeySplitTable41	@ folk guitar
	voice_keysplit voicegroup210, KeySplitTable21    @ distortion guitar 1
	voice_keysplit voicegroup224, KeySplitTable32    @ distortion guitar 2
	voice_keysplit voicegroup209, KeySplitTable20    @ clean guitar
	voice_keysplit voicegroup212, KeySplitTable42    @ upright bass 1
	voice_keysplit voicegroup225, KeySplitTable43    @ upright bass 2
	voice_directsound 60, 0, DirectSoundWaveData_dp_slapbass_c1_16, 255, 0, 255, 197	@ 127/127/127/118/ 64
	voice_keysplit voicegroup254, KeySplitTable44	@ synth bass
	voice_keysplit voicegroup217, KeySplitTable45    @ strings
	voice_keysplit voicegroup213, KeySplitTable46    @ violin
	voice_keysplit voicegroup257, KeySplitTable47	@ cello
	voice_keysplit voicegroup214, KeySplitTable48    @ pizzicato
	voice_keysplit voicegroup215, KeySplitTable40    @ harp
	voice_keysplit voicegroup216, KeySplitTable40    @ timpani 1
	voice_keysplit voicegroup219, KeySplitTable39    @ trumpets 1
	voice_keysplit voicegroup220, KeySplitTable47    @ trombone
	voice_keysplit voicegroup223, KeySplitTable78	@ french horns
	voice_keysplit voicegroup223, KeySplitTable50	@ french horns
	voice_keysplit voicegroup265, KeySplitTable51	@ oboe
	voice_keysplit voicegroup266, KeySplitTable52	@ clarinet
	voice_keysplit voicegroup226, KeySplitTable33    @ flute
	voice_keysplit voicegroup268, KeySplitTable54    @ bassoon
	voice_keysplit voicegroup269, KeySplitTable55    @ orchestra hit
	voice_keysplit voicegroupInst27, KeySplitTable115	@ harp 2
	voice_keysplit_all voicegroupDrum1				@ standard kit
	voice_keysplit_all voicegroupDrum2				@ tr-909 kit
	voice_keysplit_all voicegroupDrum3				@ room kit
	voice_directsound 60, 0, DirectSoundWaveData_bw_french_horn_ensemble_c3, 255, 216, 219, 208	@ 127/117/118/116/ 64
	voice_keysplit voicegroupInst34, KeySplitTable22	@ tuba
	voice_keysplit voicegroup265, KeySplitTable101	@ oboe 2
	voice_keysplit voicegroupInst22, KeySplitTable95	@ slap bass
	voice_directsound 60, 0, DirectSoundWaveData_dp_timpany_as_16, 255, 249, 0, 208	@ 127/ 80/  1/116/ 64
	voice_directsound 60, 0, DirectSoundWaveData_bw_slap_bass_g2, 255, 64, 227, 178	@ 127/125/120/120/ 64
	voice_directsound 60, 0, DirectSoundWaveData_puresquare_50, 255, 242, 25, 0	@ 126/100/ 40/127/ 64
	voice_keysplit voicegroup195, KeySplitTable90	@ piano (longer decay)
	voice_keysplit voicegroupInst40, KeySplitTable93	@ saxophone
	voice_directsound 60, 0, DirectSoundWaveData_bw_trombone_stab_cs2, 255, 197, 227, 208	@ 127/120/120/116/ 64
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_directsound 60, 0, DirectSoundWaveData_purenoise, 255, 0, 255, 178	@ 125/127/127/120/ 64
	voice_directsound 60, 0, DirectSoundWaveData_bw_ocean_waves_sfx_c4, 255, 0, 255, 0	@ 127/127/127/127/ 64
	voice_keysplit voicegroup217, KeySplitTable96	@ strings 2
	voice_keysplit voicegroupInst57, KeySplitTable80	@ underwater sfx
	voice_keysplit voicegroup234, KeySplitTable35	@ piano 2
	voice_keysplit voicegroup247, KeySplitTable41	@ nylon guitar 2
	voice_directsound 60, 0, DirectSoundWaveData_bw_electronic_organ_c5, 255, 0, 255, 208	@ 127/127/127/116/ 64
	voice_directsound 60, 0, DirectSoundWaveData_bw_solo_trumpet_c5, 255, 0, 255, 178	@ 127/127/127/120/ 64
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_directsound 60, 0, DirectSoundWaveData_bw_suspended_cymbal_e2, 255, 0, 255, 237	@ 127/127/127/100/ 64
	voice_keysplit voicegroupInst41, KeySplitTable85	@ choir aahs
	voice_keysplit voicegroupInst60, KeySplitTable63	@ female choir
	voice_keysplit voicegroupInst48, KeySplitTable62	@ male choir
	voice_keysplit voicegroupInst5, KeySplitTable81	@ harpsichord
	voice_directsound 60, 0, DirectSoundWaveData_bw_erhu_c3, 42, 233, 159, 208	@  80/110/100/116/ 64
	voice_keysplit voicegroupInst6, KeySplitTable100	@ vibraphone 2
	voice_directsound 60, 0, DirectSoundWaveData_bw_vibraphone_soft_c5, 255, 249, 2, 208	@ 127/ 80/ 10/116/ 64
	voice_directsound 60, 0, DirectSoundWaveData_bw_gong1_c4, 255, 252, 0, 237	@ 127/ 45/  1/100/ 64
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_keysplit voicegroupInst64, KeySplitTable86	@ pipe organ
	voice_keysplit voicegroupInst43, KeySplitTable81	@ sitar
	voice_directsound 60, 0, DirectSoundWaveData_bw_steel_drum_g4, 255, 252, 0, 208	@ 127/ 50/  1/116/ 64
	voice_keysplit voicegroupInst65, KeySplitTable74	@ clarinet ensemble
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_keysplit voicegroupInst62, KeySplitTable38	@ resonant synth
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_keysplit voicegroupInst50, KeySplitTable106	@ french horn ensemble soft
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_directsound 60, 0, DirectSoundWaveData_bw_celesta_g3, 255, 249, 0, 208	@ 127/ 80/  1/116/ 64
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_directsound 60, 0, DirectSoundWaveData_bw_electric_bass_e2, 255, 233, 191, 197	@ 127/110/110/118/ 64
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_directsound 60, 0, DirectSoundWaveData_dp_whistle_c5_16, 255, 0, 255, 178	@ 127/127/127/120/ 64
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0	@ dummy
	voice_directsound 60, 0, DirectSoundWaveData_dp_808snare_16, 255, 219, 0, 178	@ 127/116/  0/120/ 64
