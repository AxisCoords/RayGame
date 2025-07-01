#include "raylib.h"
#include "src/windowManager.hpp"
#include "src/globals.hpp"
#include "src/entity.hpp"

int main() {
	CreateWindow(WIN_WIDTH, WIN_HEIGHT, "GAME");

	entt::Entity* mob = new entt::Entity("image", (Vector2){WIN_WIDTH / 2, WIN_HEIGHT / 2}, 4, gfx::BOTTOM_CENTER);
	
	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_F3)) showDebug = !showDebug;

		if (IsKeyDown(KEY_SPACE)) {
			mob->pos.x += 0.5f;
			mob->pos.y += 0.5f;
		}

		BeginDrawing();
		ClearBackground(BLACK);

		mob->Update();
		mob->Render(WHITE);

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

	delete mob;
	DestroyWindow();
}
