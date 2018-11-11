#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* this is defined on macos, so undefine it */
#ifdef _KEY_T
#undef _KEY_T
#endif

#define _MOUSE_LEFT 0
#define _MOUSE_RIGHT 1
#define _MOUSE_MIDDLE 2

#define _KEY_SPACE 32
#define _KEY_APOSTROPHE 39
#define _KEY_COMMA 44
#define _KEY_MINUS 45
#define _KEY_PERIOD 46
#define _KEY_SLASH 47
#define _KEY_0 48
#define _KEY_1 49
#define _KEY_2 50
#define _KEY_3 51
#define _KEY_4 52
#define _KEY_5 53
#define _KEY_6 54
#define _KEY_7 55
#define _KEY_8 56
#define _KEY_9 57
#define _KEY_SEMICOLON 59
#define _KEY_EQUAL 61
#define _KEY_A 65
#define _KEY_B 66
#define _KEY_C 67
#define _KEY_D 68
#define _KEY_E 69
#define _KEY_F 70
#define _KEY_G 71
#define _KEY_H 72
#define _KEY_I 73
#define _KEY_J 74
#define _KEY_K 75
#define _KEY_L 76
#define _KEY_M 77
#define _KEY_N 78
#define _KEY_O 79
#define _KEY_P 80
#define _KEY_Q 81
#define _KEY_R 82
#define _KEY_S 83
#define _KEY_T 84
#define _KEY_U 85
#define _KEY_V 86
#define _KEY_W 87
#define _KEY_X 88
#define _KEY_Y 89
#define _KEY_Z 90
#define _KEY_LEFT_BRACKET 91
#define _KEY_BACKSLASH 92
#define _KEY_RIGHT_BRACKET 93
#define _KEY_GRAVE_ACCENT 96
#define _KEY_WORLD_1 161
#define _KEY_WORLD_2 162
#define _KEY_ESC 256
#define _KEY_ENTER 257
#define _KEY_TAB 258
#define _KEY_BACKSPACE 259
#define _KEY_INSERT 260
#define _KEY_DELETE 261
#define _KEY_RIGHT 262
#define _KEY_LEFT 263
#define _KEY_DOWN 264
#define _KEY_UP 265
#define _KEY_PAGE_UP 266
#define _KEY_PAGE_DOWN 267
#define _KEY_HOME 268
#define _KEY_END 269
#define _KEY_CAPS_LOCK 280
#define _KEY_SCROLL_LOCK 281
#define _KEY_NUM_LOCK 282
#define _KEY_PRINT_SCREEN 283
#define _KEY_PAUSE 284
#define _KEY_F1 290
#define _KEY_F2 291
#define _KEY_F3 292
#define _KEY_F4 293
#define _KEY_F5 294
#define _KEY_F6 295
#define _KEY_F7 296
#define _KEY_F8 297
#define _KEY_F9 298
#define _KEY_F10 299
#define _KEY_F11 300
#define _KEY_F12 301
#define _KEY_F13 302
#define _KEY_F14 303
#define _KEY_F15 304
#define _KEY_F16 305
#define _KEY_F17 306
#define _KEY_F18 307
#define _KEY_F19 308
#define _KEY_F20 309
#define _KEY_F21 310
#define _KEY_F22 311
#define _KEY_F23 312
#define _KEY_F24 313
#define _KEY_F25 314
#define _KEY_KP_0 320
#define _KEY_KP_1 321
#define _KEY_KP_2 322
#define _KEY_KP_3 323
#define _KEY_KP_4 324
#define _KEY_KP_5 325
#define _KEY_KP_6 326
#define _KEY_KP_7 327
#define _KEY_KP_8 328
#define _KEY_KP_9 329
#define _KEY_KP_DECIMAL 330
#define _KEY_KP_DIVIDE 331
#define _KEY_KP_MULTIPLY 332
#define _KEY_KP_SUBTRACT 333
#define _KEY_KP_ADD 334
#define _KEY_KP_ENTER 335
#define _KEY_KP_EQUAL 336
#define _KEY_LEFT_SHIFT 340
#define _KEY_LEFT_CONTROL 341
#define _KEY_LEFT_ALT 342
#define _KEY_LEFT_SUPER 343
#define _KEY_RIGHT_SHIFT 344
#define _KEY_RIGHT_CONTROL 345
#define _KEY_RIGHT_ALT 346
#define _KEY_RIGHT_SUPER 347
#define _KEY_MENU 348

void input_setmousevisible(bool_t visible);
void input_setmouseposition(int x, int y);
int input_mousex();
int input_mousey();
bool_t input_mousedown(int b);
bool_t input_keydown(int k);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* INPUT_H_INCLUDED */
