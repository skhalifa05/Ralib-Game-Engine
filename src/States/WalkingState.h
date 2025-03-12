//
// Created by Seif Khalifa on 12/03/2025.
//

#ifndef WALKING_STATE_H
#define WALKING_STATE_H

#include "BaseState.h"

class WalkingState : public BaseState {
public:
    using BaseState::BaseState;

    void Enter() override;
    void Update(float deltatime) override;
    void Exit() override;

};

#endif // WALKING_STATE_H
