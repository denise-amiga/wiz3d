#include "wiz3d_config.h"

#ifndef PLATFORM_NULL

#include "../lib/litelibs/litegfx.h"
#include "draw.h"
#include "platform.h"
#include "screen.h"
#include "time.h"

static void* _screen_ptr = NULL;
static int _screen_fps = 0;
static int _screen_fpscounter = 0;
static float _screen_fpstime = 0;

EXPORT void CALL wzSetScreen(int width, int height, bool_t fullscreen, bool_t resizable) {
    _UnloadFonts();
    if (_screen_ptr) p_CloseScreen(_screen_ptr);
    _screen_ptr = p_OpenScreen(width, height, fullscreen, 0, TRUE, resizable);
    lgfx_init();
    wzSetDefaultFont();
}

EXPORT void CALL wzRefreshScreen() {
    p_RefreshScreen(_screen_ptr);
    wzUpdateTimer();

    /* Update FPS */
    ++_screen_fpscounter;
    _screen_fpstime += wzGetDeltaTime();
    if (_screen_fpstime >= 1) {
        _screen_fps = _screen_fpscounter;
        _screen_fpscounter = 0;
        _screen_fpstime -= 1;
    }
}

EXPORT void CALL wzSetScreenTitle(const char* title) {
    p_SetScreenTitle(_screen_ptr, title);
}

EXPORT int CALL wzGetScreenWidth() {
    return p_GetScreenWidth(_screen_ptr);
}

EXPORT int CALL wzGetScreenHeight() {
    return p_GetScreenHeight(_screen_ptr);
}

EXPORT int CALL wzGetScreenFPS() {
    return _screen_fps;
}

EXPORT bool_t CALL wzIsScreenOpened() {
    return p_IsScreenOpened(_screen_ptr);
}

EXPORT int CALL wzGetDesktopWidth() {
    return p_GetDesktopWidth();
}

EXPORT int CALL wzGetDesktopHeight() {
    return p_GetDesktopHeight();
}

void* _GetScreenPtr() {
    return _screen_ptr;
}

#endif /* PLATFORM_NULL */
