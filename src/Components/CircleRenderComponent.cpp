//
// Created by Seif Khalifa on 12/02/2025.
//

#include "CircleRenderComponent.h"

#include <iostream>

#include "../GameObject.h"
#include "PositionComponent.h"

CircleRenderComponent::CircleRenderComponent(GameObject* parent, float r, Color color)
    : RenderComponent(parent, "CircleRenderComponent"), radius(r), foregroundColor(color) {}

void CircleRenderComponent::Render() {
    if (gameObject) {
     PositionComponent* position = gameObject->GetComponent<PositionComponent>();
        if (position) {
            Vector3 pos = position->GetPosition();
            DrawCircleV({pos.x, pos.y}, radius, foregroundColor);
        }else {
            DrawCircle(0, 0, radius, foregroundColor);  // Draw at the origin
        }
    }
}