#include "raylib.h"
#include "src/GameObject.h"
#include "src/Components/CircleRenderComponent.h"

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - Two Bouncing Circles");
    SetTargetFPS(60);

    // First Circle
    GameObject circleObject;
    PositionComponent* position1 = new PositionComponent(&circleObject);
    position1->SetPosition({screenWidth / 3.0f, screenHeight / 2.0f, 0.0f});
    circleObject.AddComponent(position1);
    CircleRenderComponent* renderComponent1 = new CircleRenderComponent(&circleObject, 30.0f, RED);
    circleObject.AddComponent(renderComponent1);
    Vector2 velocity1 = { 100, 100 };

    // Second Circle
    GameObject circleObject2;
    PositionComponent* position2 = new PositionComponent(&circleObject2);
    position2->SetPosition({2 * screenWidth / 3.0f, screenHeight / 2.0f, 0.0f});
    circleObject2.AddComponent(position2);
    CircleRenderComponent* renderComponent2 = new CircleRenderComponent(&circleObject2, 30.0f, BLUE);
    circleObject2.AddComponent(renderComponent2);
    Vector2 velocity2 = { -120, 80 }; // Different speed & direction

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        // Update Circle 1
        Vector3 pos1 = position1->GetPosition();
        pos1.x += velocity1.x * deltaTime;
        pos1.y += velocity1.y * deltaTime;

        if (pos1.x - 30.0f <= 0 || pos1.x + 30.0f >= screenWidth) velocity1.x *= -1;
        if (pos1.y - 30.0f <= 0 || pos1.y + 30.0f >= screenHeight) velocity1.y *= -1;
        position1->SetPosition(pos1);

        // Update Circle 2
        Vector3 pos2 = position2->GetPosition();
        pos2.x += velocity2.x * deltaTime;
        pos2.y += velocity2.y * deltaTime;

        if (pos2.x - 30.0f <= 0 || pos2.x + 30.0f >= screenWidth) velocity2.x *= -1;
        if (pos2.y - 30.0f <= 0 || pos2.y + 30.0f >= screenHeight) velocity2.y *= -1;
        position2->SetPosition(pos2);

        // Rendering
        BeginDrawing();
        ClearBackground(RAYWHITE);

        circleObject.Render();
        circleObject2.Render();

        DrawText("Two Bouncing Circles!", 250, 20, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}