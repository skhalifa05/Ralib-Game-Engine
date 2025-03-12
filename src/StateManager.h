//
// Created by Seif Khalifa on 12/03/2025.
//
#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "./States/BaseState.h"
#include <unordered_map>
#include <memory>
#include <typeindex>
#include <chrono>
#include <iostream>

class StateManager {
private:
    BaseState* currentState = nullptr;
    std::unordered_map<std::type_index, std::unique_ptr<BaseState>> stateInstances;
    std::chrono::steady_clock::time_point stateStartTime;

public:
    ~StateManager() = default;

    template <typename T>
    void RegisterState();

    template <typename T>
    void GoToState();

    void Update(float deltatime);
    float GetStateTime();
};


#endif // STATE_MANAGER_H