#include "raylib.h"
#include "src/windowManager.hpp"
#include "src/globals.hpp"
#include "src/player.hpp"

int main() {
	CreateWindow(WIN_WIDTH, WIN_HEIGHT, "GAME");

	entt::Player* player = new entt::Player((Vector2){8 * 4, WIN_HEIGHT / 2});
	
	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_F3)) showDebug = !showDebug;

		player->Update();

		BeginDrawing();
		ClearBackground(BLACK);
			player->Render(WHITE);

			/* #region Debug */
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
		/* #endregion */
		EndDrawing();
	}

	delete player;
	
	DestroyWindow();
}
