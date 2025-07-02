#include "raylib.h"
#include "src/windowManager.hpp"
#include "src/globals.hpp"

int main() {
	CreateWindow(WIN_WIDTH, WIN_HEIGHT, "GAME");
	
	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_F3)) showDebug = !showDebug;

		BeginDrawing();
		ClearBackground(BLACK);

		if (showDebug) {
			DrawFPS(0, 0);

			DrawLineV(
				(Vector2){0, WIN_HEIGHT / 2}, 
				(Vector2){WIN_WIDTH, WIN_HEIGHT / 2}, 
				RED
			);

			DrawLineV(
				(Vector2){WIN_WIDTH / 2, 0}, 
				(Vector2){WIN_WIDTH / 2, WIN_HEIGHT}, 
				GREEN
			);
		}

		EndDrawing();
	}

	DestroyWindow();
}
