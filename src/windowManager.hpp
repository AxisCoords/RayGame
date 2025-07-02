#pragma once

#include <cstdint>
#include "raylib.h"

void CreateWindow(uint32_t width, uint32_t height, const char* title, bool resizable = false, bool vsync = true, uint32_t targetFPS = 120) {
    SetTraceLogLevel(LOG_WARNING);

    uint32_t flags = FLAG_MSAA_4X_HINT | FLAG_WINDOW_ALWAYS_RUN | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_HIDDEN;
    if (resizable) flags |= FLAG_WINDOW_RESIZABLE;
    if (vsync)     flags |= FLAG_VSYNC_HINT;

    SetConfigFlags(flags);

    InitAudioDevice();
    InitWindow(width, height, title);
    if (!vsync) SetTargetFPS(targetFPS);

    //SetExitKey(KEY_NULL);
    ClearWindowState(FLAG_WINDOW_HIDDEN);
}

void DestroyWindow() {
	CloseAudioDevice();
	CloseWindow();
}
