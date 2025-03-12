//
// Created by Seif Khalifa on 12/03/2025.
//

#include "WalkingState.h"

#include <future>

#include "../StateManager.h"
#include <iostream>

#include "IdleState.h"
#include "JumpingState.h"

void WalkingState::Enter() {
    std::cout << "Entering Walking State." << std::endl;
    remainingTime = 5.0f;
}

void WalkingState::Update(float deltatime) {
    if (remainingTime <= 0.0f) {
        stateManager->GoToState<IdleState>();
        return;
    }

    char userinput = '\0'; // Default to no input

    if (kbhit()) { // Check if a key is pressed
        userinput = getchar(); // Read the key
    }

    if (userinput == 'j') {
        std::cout << "Switching to JumpingState" << std::endl;
        stateManager->GoToState<JumpingState>();
        return;
    } else if (userinput == 'w') {
        std::cout << "Extending Walking state duration." << std::endl;
        remainingTime += 3.0f;
    }

    remainingTime -= deltatime;
}

void WalkingState::Exit() {
    std::cout << "Exiting Walking State." << std::endl;
}