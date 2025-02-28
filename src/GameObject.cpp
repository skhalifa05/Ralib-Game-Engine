//
// Created by Seif Khalifa on 12/02/2025.
//

#include "GameObject.h"

#include <iostream>

#include "Components/RenderComponent.h"

GameObject::GameObject() {
    // Generate a unique GUID (this is a placeholder implementation)
    m_strGUID = "GameObject_" + std::to_string(rand());
}

GameObject::~GameObject() {
    DeleteAllComponents();
}

std::string& GameObject::GetGUID() {
    return m_strGUID;
}

bool GameObject::AddComponent(IComponent* p_pComponent) {
    if (!p_pComponent) return false;

    std::string familyID = p_pComponent->GetFamilyID();

    // Ensure only one component per family is allowed
    if (m_components.find(familyID) != m_components.end()) {
        std::cout << "Component of family " << familyID << " already exists on GameObject " << m_strGUID << std::endl;
        return false;
    }

    m_components[familyID] = p_pComponent;
    return true;
}

template <typename T>
T* GameObject::GetComponent() {
    for (auto& pair : m_components) {
        T* component = dynamic_cast<T*>(pair.second);
        if (component) return component;
    }
    return nullptr;
}


IComponent* GameObject::RemoveComponent(const std::string& p_strFamilyId) {
    auto it = m_components.find(p_strFamilyId);
    if (it != m_components.end()) {
        IComponent* component = it->second;
        m_components.erase(it);
        return component;
    }
    return nullptr;
}

void GameObject::DeleteAllComponents() {
    for (auto& pair : m_components) {
        delete pair.second;
    }
    m_components.clear();
}

void GameObject::Update(float deltaTime) {
    for (auto& pair : m_components) {
        pair.second->Update(deltaTime);
    }
}

void GameObject::Render() {
    // ✅ Get PositionComponent if it exists
    PositionComponent* position = GetComponent<PositionComponent>();

    if (position) {
        Matrix transform = position->GetTransform();
        // Apply transformation if needed before rendering
    }

    // ✅ Render only components derived from RenderComponent
    for (auto& pair : m_components) {
        RenderComponent* renderComponent = dynamic_cast<RenderComponent*>(pair.second);
        if (renderComponent) {
            renderComponent->Render();
        }
    }
}