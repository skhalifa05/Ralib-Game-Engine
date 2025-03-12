//
// Created by Seif Khalifa on 12/03/2025.
//

#include "JumpingState.h"
#include "../StateManager.h"
#include "IdleState.h"
#include "WalkingState.h"

#include "JumpingState.h"
#include "../StateManager.h"
#include <iostream>

void JumpingState::Enter() {
    std::cout << "Entering Jumping State." << std::endl;
    remainingTime = 5.0f;
}


void JumpingState::Update(float deltatime) {
    if (remainingTime <= 0.0f) {
        stateManager->GoToState<IdleState>();
        return;
    }

    char userinput = '\0'; // Default to no input

    if (kbhit()) { // Check if a key is pressed
        userinput = getchar(); // Read the key
    }

    if (userinput == 'j') {
        std::cout << "Extending Jumping state duration." << std::endl;
        remainingTime += 3.0f;
    } else if (userinput == 'w') {
        std::cout << "Switching to WalkingState" << std::endl;
        stateManager->GoToState<WalkingState>();
        return;
    }

    remainingTime -= deltatime;
}

void JumpingState::Exit() {
    std::cout << "Exiting Jumping State." << std::endl;
}