//
// Created by William Kerstiens on 11/7/20.
//
#include <mutex>

#ifndef MISSILECOMMAND_GAMECOMPONENT_H
#define MISSILECOMMAND_GAMECOMPONENT_H

class GameComponent {
public:
    virtual void printStatus() = 0;
protected:


    std::mutex _mtxCout;
private:
};

#endif //MISSILECOMMAND_GAMECOMPONENT_H
