//
// Created by William Kerstiens on 11/7/20.
//

#include "GameComponent.h"

#ifndef MISSILECOMMAND_KEYBOARD_H
#define MISSILECOMMAND_KEYBOARD_H

class Keyboard : public GameComponent {
public:
    void HandleInput(bool &&running) const;
    void printStatus() override;
private:
};

#endif //MISSILECOMMAND_KEYBOARD_H
