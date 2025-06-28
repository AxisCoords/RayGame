#include <iostream>
#include "raylib.h"
#include "src/globals.hpp"

int main() {
	SetTraceLogLevel(LOG_WARNING);
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_ALWAYS_RUN | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_HIDDEN);

	InitAudioDevice();
	InitWindow(WIN_WIDTH, WIN_HEIGHT, "GAME");
	SetExitKey(KEY_NULL);
	ClearWindowState(FLAG_WINDOW_HIDDEN);

	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_T)) std::cout << "Hello World!" << std::endl;

		BeginDrawing();
			ClearBackground(RED);
			DrawText("HELLO!", 0, 0, 26, WHITE);
		EndDrawing();
	}

	CloseAudioDevice();
	CloseWindow();
}
