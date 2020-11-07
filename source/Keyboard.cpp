//
// Created by William Kerstiens on 11/7/20.
//
#include <iostream>
#include "SDL.h"
#include "Keyboard.h"

void Keyboard::HandleInput(bool &&running) const {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            running = false;
        } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_q | SDLK_LCTRL:
                case SDLK_ESCAPE:
                    running = false;
                    break;
            }
        }
    }
}

void Keyboard::printStatus() {
    std::unique_lock<std::mutex> lock(_mtxCout);
    std::cout << "Keyboard is running\n";
}