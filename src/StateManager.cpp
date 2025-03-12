#include "StateManager.h"
#include "States/IdleState.h"
#include "States/WalkingState.h"
#include "States/JumpingState.h"


void StateManager::Update(float deltatime) {
    if (currentState) {
        currentState->Update(deltatime);
    }
}

float StateManager::GetStateTime() {
    return std::chrono::duration<float>(std::chrono::steady_clock::now() - stateStartTime).count();
}

template <typename T>
void StateManager::RegisterState() {
    std::type_index stateType = typeid(T);
    if (stateInstances.find(stateType) == stateInstances.end()) {
        stateInstances[stateType] = std::make_unique<T>(this);
    }
}

template <typename T>
void StateManager::GoToState() {
    std::type_index stateType = typeid(T);

    if (stateInstances.find(stateType) == stateInstances.end()) {
        std::cerr << "State not registered: " << stateType.name() << std::endl;
        return;
    }

    if (currentState == stateInstances[stateType].get()) {
        std::cout << "Already in state: " << stateType.name() << std::endl;
        return;
    }

    if (currentState) {
        currentState->Exit();
    }

    currentState = stateInstances[stateType].get();
    if (currentState) {
        currentState->Enter();
        stateStartTime = std::chrono::steady_clock::now();
    }
}

// Explicit instantiations for each state
template void StateManager::RegisterState<IdleState>();
template void StateManager::RegisterState<WalkingState>();
template void StateManager::RegisterState<JumpingState>();

template void StateManager::GoToState<IdleState>();
template void StateManager::GoToState<WalkingState>();
template void StateManager::GoToState<JumpingState>();