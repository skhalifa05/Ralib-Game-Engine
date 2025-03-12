//
// Created by Seif Khalifa on 12/03/2025.
//

#ifndef BASE_STATE_H
#define BASE_STATE_H

#include <iostream>
#include <thread>
#include <chrono>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

class StateManager; // Forward declaration

class BaseState {
protected:
    StateManager* stateManager;
    float remainingTime;

public:
    BaseState(StateManager* manager) : stateManager(manager) {}
    virtual ~BaseState() = default;

    virtual void Enter() = 0;
    virtual void Update(float deltatime) = 0;
    virtual void Exit() = 0;

    //non blocking user input fn
    bool kbhit() {
        struct termios oldt, newt;
        int ch;
        int oldf;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        ch = getchar();

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);

        if (ch != EOF) {
            ungetc(ch, stdin);
            return true;
        }

        return false;
    }
};

#endif // BASE_STATE_H
