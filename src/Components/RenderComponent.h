//
// Created by Seif Khalifa on 12/02/2025.
//

#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H
#include "../IComponent.h"


class RenderComponent : public IComponent {
public:
    explicit RenderComponent(GameObject* parent, std::string componentID) : IComponent(parent, "Render", std::move(componentID)) {}

    virtual ~RenderComponent() = default;

    virtual void Render() = 0;  // Pure virtual function (makes this an abstract class)
    void Update(float deltaTime) override {};
};

#endif //RENDERCOMPONENT_H
