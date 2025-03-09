//
// Created by Seif Khalifa on 12/02/2025.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <map>

#include "IComponent.h"
#include "Components/PositionComponent.h"


class GameObject {
public:
    GameObject();
    ~GameObject();

    std::string& GetGUID();
    bool AddComponent(IComponent* p_pComponent);
    template <typename T>
    T* GetComponent();
    IComponent* RemoveComponent(const std::string &p_strFamilyId);
    void DeleteAllComponents();

    void Update(float deltaTime);
    void Render();
private:
    std::string m_strGUID;
    std::map<std::string, IComponent*> m_components;
};



#endif //GAMEOBJECT_H
