//
// Created by Seif Khalifa on 11/02/2025.
//

#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

using namespace std;
class GameObject;  // Forward declaration instead of including "GameObject.h"

class IComponent {
public:
    explicit IComponent(GameObject* parent, string family, string component)
        : gameObject(parent), familyID(std::move(family)), componentID(std::move(component)) {}
    virtual ~IComponent() = default;  // Virtual destructor for proper cleanup

    virtual GameObject* GetGameObject() const { return gameObject; }  // Can be overridden if needed
    virtual void Update(float deltaTime) = 0;
    string GetFamilyID() const { return familyID; }
    string GetComponentID() const { return componentID; }
protected:
    GameObject* gameObject;
    const string familyID;
    const string componentID;
};

#endif // COMPONENT_H
