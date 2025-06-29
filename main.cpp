#include <iostream>
#include "raylib.h"
#include "src/globals.hpp"
#include "src/sprite.hpp"

int main() {
	SetTraceLogLevel(LOG_WARNING);
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_ALWAYS_RUN | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_HIDDEN);

	InitAudioDevice();
	InitWindow(WIN_WIDTH, WIN_HEIGHT, "GAME");
	SetExitKey(KEY_NULL);
	ClearWindowState(FLAG_WINDOW_HIDDEN);

	gfx::Sprite sprite("image", (Vector2){100, 0}, 4);

	while (!WindowShouldClose()) {
		BeginDrawing();
			ClearBackground(BLACK);
			sprite.Draw(WHITE);
		EndDrawing();
	}

	sprite.Unload();

	CloseAudioDevice();
	CloseWindow();
}
