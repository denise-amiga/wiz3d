#ifndef INPUT_SDL_H_INCLUDED
#define INPUT_SDL_H_INCLUDED

#include "micron_config.h"

#ifdef USE_SDL2

#define KEY_RETURN 13
#define KEY_ESC 27
#define KEY_BACKSPACE 8
#define KEY_TAB 9
#define KEY_SPACE 32
#define KEY_EXCLAIM 33
#define KEY_QUOTEDBL 34
#define KEY_HASH 35
#define KEY_PERCENT 37
#define KEY_DOLLAR 36
#define KEY_AMPERSAND 38
#define KEY_QUOTE 39
#define KEY_LEFTPAREN 40
#define KEY_RIGHTPAREN 41
#define KEY_ASTERISK 42
#define KEY_PLUS 43
#define KEY_COMMA 44
#define KEY_MINUS 45
#define KEY_PERIOD 46
#define KEY_SLASH 47
#define KEY_0 48
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57
#define KEY_COLON 58
#define KEY_SEMICOLON 59
#define KEY_LESS 60
#define KEY_EQUALS 61
#define KEY_GREATER 62
#define KEY_QUESTION 63
#define KEY_AT 64
#define KEY_LEFTBRACKET 91
#define KEY_BACKSLASH 92
#define KEY_RIGHTBRACKET 93
#define KEY_CARET 94
#define KEY_UNDERSCORE 95
#define KEY_BACKQUOTE 96
#define KEY_A 97
#define KEY_B 98
#define KEY_C 99
#define KEY_D 100
#define KEY_E 101
#define KEY_F 102
#define KEY_G 103
#define KEY_H 104
#define KEY_I 105
#define KEY_J 106
#define KEY_K 107
#define KEY_L 108
#define KEY_M 109
#define KEY_N 110
#define KEY_O 111
#define KEY_P 112
#define KEY_Q 113
#define KEY_R 114
#define KEY_S 115
#define KEY_T 116
#define KEY_U 117
#define KEY_V 118
#define KEY_W 119
#define KEY_X 120
#define KEY_Y 121
#define KEY_Z 122
#define KEY_CAPSLOCK 1073741881
#define KEY_F1 1073741882
#define KEY_F2 1073741883
#define KEY_F3 1073741884
#define KEY_F4 1073741885
#define KEY_F5 1073741886
#define KEY_F6 1073741887
#define KEY_F7 1073741888
#define KEY_F8 1073741889
#define KEY_F9 1073741890
#define KEY_F10 1073741891
#define KEY_F11 1073741892
#define KEY_F12 1073741893
#define KEY_PRINTSCREEN 1073741894
#define KEY_SCROLLLOCK 1073741895
#define KEY_PAUSE 1073741896
#define KEY_INSERT 1073741897
#define KEY_HOME 1073741898
#define KEY_PAGEUP 1073741899
#define KEY_DELETE 127
#define KEY_END 1073741901
#define KEY_PAGEDOWN 1073741902
#define KEY_RIGHT 1073741903
#define KEY_LEFT 1073741904
#define KEY_DOWN 1073741905
#define KEY_UP 1073741906
#define KEY_NUMLOCKCLEAR 1073741907
#define KEY_KP_DIVIDE 1073741908
#define KEY_KP_MULTIPLY 1073741909
#define KEY_KP_MINUS 1073741910
#define KEY_KP_PLUS 1073741911
#define KEY_KP_ENTER 1073741912
#define KEY_KP_1 1073741913
#define KEY_KP_2 1073741914
#define KEY_KP_3 1073741915
#define KEY_KP_4 1073741916
#define KEY_KP_5 1073741917
#define KEY_KP_6 1073741918
#define KEY_KP_7 1073741919
#define KEY_KP_8 1073741920
#define KEY_KP_9 1073741921
#define KEY_KP_0 1073741922
#define KEY_KP_PERIOD 1073741923
#define KEY_APPLICATION 1073741925
#define KEY_POWER 1073741926
#define KEY_KP_EQUALS 1073741927
#define KEY_F13 1073741928
#define KEY_F14 1073741929
#define KEY_F15 1073741930
#define KEY_F16 1073741931
#define KEY_F17 1073741932
#define KEY_F18 1073741933
#define KEY_F19 1073741934
#define KEY_F20 1073741935
#define KEY_F21 1073741936
#define KEY_F22 1073741937
#define KEY_F23 1073741938
#define KEY_F24 1073741939
#define KEY_EXECUTE 1073741940
#define KEY_HELP 1073741941
#define KEY_MENU 1073741942
#define KEY_SELECT 1073741943
#define KEY_STOP 1073741944
#define KEY_AGAIN 1073741945
#define KEY_UNDO 1073741946
#define KEY_CUT 1073741947
#define KEY_COPY 1073741948
#define KEY_PASTE 1073741949
#define KEY_FIND 1073741950
#define KEY_MUTE 1073741951
#define KEY_VOLUMEUP 1073741952
#define KEY_VOLUMEDOWN 1073741953
#define KEY_KP_COMMA 1073741957
#define KEY_KP_EQUALSAS400 1073741958
#define KEY_ALTERASE 1073741977
#define KEY_SYSREQ 1073741978
#define KEY_CANCEL 1073741979
#define KEY_CLEAR 1073741980
#define KEY_PRIOR 1073741981
#define KEY_RETURN2 1073741982
#define KEY_SEPARATOR 1073741983
#define KEY_OUT 1073741984
#define KEY_OPER 1073741985
#define KEY_CLEARAGAIN 1073741986
#define KEY_CRSEL 1073741987
#define KEY_EXSEL 1073741988
#define KEY_KP_00 1073742000
#define KEY_KP_000 1073742001
#define KEY_THOUSANDSSEPARATOR 1073742002
#define KEY_DECIMALSEPARATOR 1073742003
#define KEY_CURRENCYUNIT 1073742004
#define KEY_CURRENCYSUBUNIT 1073742005
#define KEY_KP_LEFTPAREN 1073742006
#define KEY_KP_RIGHTPAREN 1073742007
#define KEY_KP_LEFTBRACE 1073742008
#define KEY_KP_RIGHTBRACE 1073742009
#define KEY_KP_TAB 1073742010
#define KEY_KP_BACKSPACE 1073742011
#define KEY_KP_A 1073742012
#define KEY_KP_B 1073742013
#define KEY_KP_C 1073742014
#define KEY_KP_D 1073742015
#define KEY_KP_E 1073742016
#define KEY_KP_F 1073742017
#define KEY_KP_XOR 1073742018
#define KEY_KP_POWER 1073742019
#define KEY_KP_PERCENT 1073742020
#define KEY_KP_LESS 1073742021
#define KEY_KP_GREATER 1073742022
#define KEY_KP_AMPERSAND 1073742023
#define KEY_KP_DBLAMPERSAND 1073742024
#define KEY_KP_VERTICALBAR 1073742025
#define KEY_KP_DBLVERTICALBAR 1073742026
#define KEY_KP_COLON 1073742027
#define KEY_KP_HASH 1073742028
#define KEY_KP_SPACE 1073742029
#define KEY_KP_AT 1073742030
#define KEY_KP_EXCLAM 1073742031
#define KEY_KP_MEMSTORE 1073742032
#define KEY_KP_MEMRECALL 1073742033
#define KEY_KP_MEMCLEAR 1073742034
#define KEY_KP_MEMADD 1073742035
#define KEY_KP_MEMSUBTRACT 1073742036
#define KEY_KP_MEMMULTIPLY 1073742037
#define KEY_KP_MEMDIVIDE 1073742038
#define KEY_KP_PLUSMINUS 1073742039
#define KEY_KP_CLEAR 1073742040
#define KEY_KP_CLEARENTRY 1073742041
#define KEY_KP_BINARY 1073742042
#define KEY_KP_OCTAL 1073742043
#define KEY_KP_DECIMAL 1073742044
#define KEY_KP_HEXADECIMAL 1073742045
#define KEY_LCTRL 1073742048
#define KEY_LSHIFT 1073742049
#define KEY_LALT 1073742050
#define KEY_LGUI 1073742051
#define KEY_RCTRL 1073742052
#define KEY_RSHIFT 1073742053
#define KEY_RALT 1073742054
#define KEY_RGUI 1073742055
#define KEY_MODE 1073742081
#define KEY_AUDIONEXT 1073742082
#define KEY_AUDIOPREV 1073742083
#define KEY_AUDIOSTOP 1073742084
#define KEY_AUDIOPLAY 1073742085
#define KEY_AUDIOMUTE 1073742086
#define KEY_MEDIASELECT 1073742087
#define KEY_WWW 1073742088
#define KEY_MAIL 1073742089
#define KEY_CALCULATOR 1073742090
#define KEY_COMPUTER 1073742091
#define KEY_AC_SEARCH 1073742092
#define KEY_AC_HOME 1073742093
#define KEY_AC_BACK 1073742094
#define KEY_AC_FORWARD 1073742095
#define KEY_AC_STOP 1073742096
#define KEY_AC_REFRESH 1073742097
#define KEY_AC_BOOKMARKS 1073742098
#define KEY_BRIGHTNESSDOWN 1073742099
#define KEY_BRIGHTNESSUP 1073742100
#define KEY_DISPLAYSWITCH 1073742101
#define KEY_KBDILLUMTOGGLE 1073742102
#define KEY_KBDILLUMDOWN 1073742103
#define KEY_KBDILLUMUP 1073742104
#define KEY_EJECT 1073742105
#define KEY_SLEEP 1073742106
#define KEY_APP1 1073742107
#define KEY_APP2 1073742108
#define KEY_AUDIOREWIND 1073742109
#define KEY_AUDIOFASTFORWARD 1073742110

#endif /* USE_SDL2 */

#endif /* INPUT_SDL_H_INCLUDED */
