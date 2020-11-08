//
// Created by William Kerstiens on 11/7/20.
//
#include <iostream>
#include <vector>
#include "SDL.h"
#include "EventHandler.h"

void EventHandler::HandleInput(bool &&running, std::vector<std::unique_ptr<LaserCannon>> &laserCannons) {
    SDL_Event e;
    int x, y;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_q | SDLK_LCTRL:
                case SDLK_ESCAPE:
                    running = false;
                    break;
                case SDLK_a:
                    if(laserCannons[0]->Status() == LASER_CANNON_STATUS::READY) {
                        SDL_GetMouseState(&x, &y);
                        laserCannons[0]->TargetX(x);
                        laserCannons[0]->TargetY(y);
                        laserCannons[0]->Status(LASER_CANNON_STATUS::FIRING);
                    }
                    break;
                case SDLK_s:
                    if(laserCannons[1]->Status() == LASER_CANNON_STATUS::READY) {
                        SDL_GetMouseState(&x, &y);
                        laserCannons[1]->TargetX(x);
                        laserCannons[1]->TargetY(y);
                        laserCannons[1]->Status(LASER_CANNON_STATUS::FIRING);
                    }
                    break;
                case SDLK_d:
                    if(laserCannons[2]->Status() == LASER_CANNON_STATUS::READY) {
                        SDL_GetMouseState(&x, &y);
                        laserCannons[2]->TargetX(x);
                        laserCannons[2]->TargetY(y);
                        laserCannons[2]->Status(LASER_CANNON_STATUS::FIRING);
                    }
                    break;
            }
        }
    }

}

void EventHandler::printStatus() {
    std::unique_lock<std::mutex> lock(_mtxCout);
    std::cout << "Keyboard is running\n";
}