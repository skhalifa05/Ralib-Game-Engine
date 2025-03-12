//
// Created by Seif Khalifa on 12/03/2025.
//

#include "IdleState.h"
#include "../StateManager.h"
#include "WalkingState.h"
#include "JumpingState.h"

void IdleState::Enter() {
    std::cout << "Entering Idle State." << std::endl;
}

void IdleState::Update(float deltatime) {
    char userinput = '\0'; // Default to no input

    if (kbhit()) { // Check if a key is pressed
        userinput = getchar(); // Read the key
    }

    if (userinput == 'j') {
        std::cout << "Switching to JumpingState" << std::endl;
        stateManager->GoToState<JumpingState>();
        return;
    } else if (userinput == 'w') {
        std::cout << "Switching to WalkingState" << std::endl;
        stateManager->GoToState<WalkingState>();
        return;
    }
}

void IdleState::Exit() {
    std::cout << "Exiting Idle State." << std::endl;
}