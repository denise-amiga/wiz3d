#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include "types.h"

#define COLOR_RED        -65536
#define COLOR_GREEN      -16711936
#define COLOR_BLUE       -16776961
#define COLOR_CYAN       -16711681
#define COLOR_MAGENTA    -65281
#define COLOR_YELLOW     -256
#define COLOR_BLACK      -16777216
#define COLOR_WHITE      -1
#define COLOR_GRAY       -8355712
#define COLOR_LIGHTGRAY -4210753
#define COLOR_DARKGRAY  -12566464
#define COLOR_ORANGE     -23296
#define COLOR_BROWN      -7650029

#ifdef __cplusplus
extern "C"
{
#endif

EXPORT int CALL color_rgb(int r, int g, int b);
EXPORT int CALL color_rgba(int r, int g, int b, int a);
EXPORT int CALL color_red(int color);
EXPORT int CALL color_green(int color);
EXPORT int CALL color_blue(int color);
EXPORT int CALL color_alpha(int color);
EXPORT int CALL color_changealpha(int color, int new_alpha);
EXPORT int CALL color_multiply(int color, float factor);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* COLOR_H_INCLUDED */
