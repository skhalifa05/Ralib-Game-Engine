//
// Created by Seif Khalifa on 12/03/2025.
//

#ifndef IDLE_STATE_H
#define IDLE_STATE_H

#include "BaseState.h"

class IdleState : public BaseState {
public:
    using BaseState::BaseState;

    void Enter() override;
    void Update(float deltatime) override;
    void Exit() override;
};

#endif // IDLE_STATE_H
