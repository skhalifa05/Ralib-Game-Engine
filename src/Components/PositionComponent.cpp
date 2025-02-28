//
// Created by Seif Khalifa on 12/02/2025.
//

#include "PositionComponent.h"

PositionComponent::PositionComponent(GameObject* parent): IComponent(parent, "Position", "PositionComponent"){
    transform = MatrixIdentity();
    position = { 0, 0, 0};
}

void PositionComponent::SetPosition(Vector3 newPos) {
    transform = MatrixTranslate(newPos.x, newPos.y, newPos.z);  // Reset transform
    position = newPos;
}


void PositionComponent::Translate(Vector3 translation) {
    transform = MatrixMultiply(transform, MatrixTranslate(translation.x, translation.y, translation.z));
    Vector3 newPos = Vector3Transform({ 0, 0, 0 }, transform);
    position = { newPos.x, newPos.y, newPos.z };
}

Matrix PositionComponent::GetTransform() {
    return transform;
}

Vector3 PositionComponent::GetPosition() {
    return position;
}

void PositionComponent::Update(float deltaTime) {}