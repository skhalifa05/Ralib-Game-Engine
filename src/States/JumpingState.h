//
// Created by Seif Khalifa on 12/03/2025.
//

#ifndef JUMPING_STATE_H
#define JUMPING_STATE_H

#include "BaseState.h"

class JumpingState : public BaseState {
public:
    using BaseState::BaseState;

    void Enter() override;
    void Update(float deltatime) override;
    void Exit() override;
};

#endif // JUMPING_STATE_H
