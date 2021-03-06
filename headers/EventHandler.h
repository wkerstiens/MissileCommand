//
// Created by William Kerstiens on 11/7/20.
//

#include "GameComponent.h"
#include "LaserCannon.h"

#ifndef MISSILECOMMAND_EVENTHANDLER_H
#define MISSILECOMMAND_EVENTHANDLER_H

class EventHandler : public GameComponent {
public:
    void HandleInput(bool &&running, std::vector<std::unique_ptr<LaserCannon>> &laserCannons);
    void printStatus() override;
private:
};

#endif //MISSILECOMMAND_EVENTHANDLER_H
