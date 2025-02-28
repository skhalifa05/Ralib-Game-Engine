#include "GameObjectManager.h"
#include <cmath>
#include "Components/CircleRenderComponent.h"

GameObjectManager::~GameObjectManager() {
    DestroyAllGameObjects();
}

GameObject* GameObjectManager::CreateGameObject(float x, float y, float vx, float vy, float radius, Color color) {
    GameObject* obj = new GameObject();
    PositionComponent* position = new PositionComponent(obj);
    position->SetPosition({ x, y, 0.0f });
    obj->AddComponent(position);

    CircleRenderComponent* render = new CircleRenderComponent(obj, radius, color);
    obj->AddComponent(render);

    gameObjects.push_back(obj);
    gameObjectMap[nextID] = obj;
    velocities.push_back({ vx, vy });

    return obj;
}

void GameObjectManager::DestroyGameObject(int id) {
    auto it = gameObjectMap.find(id);
    if (it != gameObjectMap.end()) {
        GameObject* obj = it->second;
        gameObjectMap.erase(it);

        auto vecIt = std::find(gameObjects.begin(), gameObjects.end(), obj);
        if (vecIt != gameObjects.end()) {
            int index = std::distance(gameObjects.begin(), vecIt);
            gameObjects.erase(vecIt);
            velocities.erase(velocities.begin() + index);
        }

        delete obj;
    }
}

std::vector<GameObject*>::iterator GameObjectManager::getObjectIteratorStart() {
    return gameObjects.begin();
}

std::vector<GameObject*>::iterator GameObjectManager::getObjectIteratorEnd() {
    return gameObjects.end();
}

void GameObjectManager::DestroyAllGameObjects() {
    for (GameObject* obj : gameObjects) {
        delete obj;
    }
    gameObjects.clear();
    gameObjectMap.clear();
    velocities.clear();
}

GameObject* GameObjectManager::GetGameObject(int id) {
    auto it = gameObjectMap.find(id);
    return (it != gameObjectMap.end()) ? it->second : nullptr;
}

void GameObjectManager::Update(float deltaTime, int screenWidth, int screenHeight) {
    for (size_t i = 0; i < gameObjects.size(); i++) {
        PositionComponent* position = gameObjects[i]->GetComponent<PositionComponent>();
        if (!position) continue;

        Vector3 pos = position->GetPosition();
        pos.x += velocities[i].x * deltaTime;
        pos.y += velocities[i].y * deltaTime;

        if (pos.x - 30.0f <= 0 || pos.x + 30.0f >= screenWidth) velocities[i].x *= -1;
        if (pos.y - 30.0f <= 0 || pos.y + 30.0f >= screenHeight) velocities[i].y *= -1;

        position->SetPosition(pos);
    }

    // Collision handling
    if (gameObjects.size() >= 2) {
        PositionComponent* pos1 = gameObjects[0]->GetComponent<PositionComponent>();
        PositionComponent* pos2 = gameObjects[1]->GetComponent<PositionComponent>();

        if (pos1 && pos2) {
            Vector3 p1 = pos1->GetPosition();
            Vector3 p2 = pos2->GetPosition();

            if (sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)) <= 60) {
                velocities[0].x *= -1;
                velocities[1].x *= -1;
                velocities[1].y *= -1;
            }
        }
    }
}

void GameObjectManager::Render() {
    for (auto obj : gameObjects) {
        obj->Render();
    }
}