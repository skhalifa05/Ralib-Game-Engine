#include "raylib.h"
#include "src/GameObjectManager.h"
#include "src/StateManager.h"
#include "src/States/IdleState.h"
#include "src/States/JumpingState.h"
#include "src/States/WalkingState.h"

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

    StateManager stateManager;

    // Register all states
    stateManager.RegisterState<IdleState>();
    stateManager.RegisterState<WalkingState>();
    stateManager.RegisterState<JumpingState>();



    // Start in Idle State
    cout << "w for walk - j for Jump";
    stateManager.GoToState<IdleState>();
    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        // Update all game objects
        gameObjectManager.Update(deltaTime, screenWidth, screenHeight);
        stateManager.Update(deltaTime);
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
