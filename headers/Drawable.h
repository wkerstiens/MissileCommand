//
// Created by William Kerstiens on 11/7/20.
//
#include "SDL.h"
#include "GameComponent.h"

#ifndef MISSILECOMMAND_DRAWABLE_H
#define MISSILECOMMAND_DRAWABLE_H

class Drawable : public GameComponent {
public:
    virtual void Render(SDL_Renderer *renderer) = 0;
protected:
private:
};

#endif //MISSILECOMMAND_DRAWABLE_H
