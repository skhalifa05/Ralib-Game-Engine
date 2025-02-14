//
// Created by Seif Khalifa on 12/02/2025.
//

#ifndef CIRCLERENDERCOMPONENT_H
#define CIRCLERENDERCOMPONENT_H
#include <raylib.h>

#include "RenderComponent.h"


class CircleRenderComponent : public RenderComponent {
public:
    CircleRenderComponent(GameObject* parent, float radius, Color color);

    void Render() override;

private:
    float radius;
    Color foregroundColor;
};



#endif //CIRCLERENDERCOMPONENT_H
