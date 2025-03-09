#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include <vector>
#include <unordered_map>
#include "GameObject.h"

class GameObjectManager {
private:
    std::vector<GameObject*> gameObjects;
    std::unordered_map<int, GameObject*> gameObjectMap;
    std::vector<Vector2> velocities;
    int nextID = 0;

public:
    ~GameObjectManager();

    GameObject* CreateGameObject(float x, float y, float vx, float vy, float radius, Color color);
    void DestroyGameObject(int id);
    std::vector<GameObject*>::iterator getObjectIteratorStart();
    std::vector<GameObject*>::iterator getObjectIteratorEnd();
    void DestroyAllGameObjects();
    GameObject* GetGameObject(int id);
    void Update(float deltaTime, int screenWidth, int screenHeight);
    void Render();
};

#endif