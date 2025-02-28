#include "raylib.h"
#include "src/GameObjectManager.h"

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - Two Bouncing Circles");
    SetTargetFPS(60);

    // Create GameObjectManager
    GameObjectManager gameObjectManager;

    // Create two bouncing circles
    gameObjectManager.CreateGameObject(screenWidth / 3.0f, screenHeight / 2.0f, 100, 100, 30.0f, RED);
    gameObjectManager.CreateGameObject(2 * screenWidth / 3.0f, screenHeight / 2.0f, -120, 80, 30.0f, BLUE);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        // Update all game objects
        gameObjectManager.Update(deltaTime, screenWidth, screenHeight);

        // Rendering
        BeginDrawing();
        ClearBackground(RAYWHITE);

        gameObjectManager.Render();
        DrawText("Two Bouncing Circles!", 250, 20, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}