//
// Created by Seif Khalifa on 12/02/2025.
//

#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H
#include <raylib.h>
#include "raymath.h"
#include "../IComponent.h"


class PositionComponent : public IComponent{
public:
     PositionComponent(GameObject* parent);
     void SetPosition(Vector3 newPos);
     Matrix GetTransform();
     Vector3 GetPosition();
     void Translate(Vector3 newTransform);
     void Update(float deltaTime) override;
private:
     Matrix transform;
     Vector3 position;
};



#endif //POSITIONCOMPONENT_H
