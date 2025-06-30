#include "src/WindowManager.hpp"
#include "raylib.h"
#include "src/globals.hpp"
#include "src/sprite.hpp"

static void drawDebug();

int main() {
	CreateWindow(WIN_WIDTH, WIN_HEIGHT, "GAME");
	
	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_F3)) showDebug = !showDebug;

		BeginDrawing();
		ClearBackground(BLACK);

		drawDebug();
		EndDrawing();
	}
	
	DestroyWindow();
}

void drawDebug() {
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
}
