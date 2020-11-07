//
// Created by William Kerstiens on 11/7/20.
//

#include "LaserCannon.h"
LaserCannon::LaserCannon(int x, int y, int w, int h) : _x(x), _y(y), _width(w), _height(h), _status(LASER_CANNON_STATUS::READY) {

}

LASER_CANNON_STATUS LaserCannon::Status() {
    std::unique_lock<std::mutex> lock(_mtxStatus);
    return _status;
}

void LaserCannon::Status(LASER_CANNON_STATUS status) {
    std::unique_lock<std::mutex> lock(_mtxStatus);
    _status = status;
}

void LaserCannon::Render(SDL_Renderer *renderer) {
    SDL_Rect block;
    if(_status == LASER_CANNON_STATUS::DESTROYED ) SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0X20);
    else SDL_SetRenderDrawColor(renderer, 0x55, 0xbb, 0x55, 0xFF);
    block.x = _x;
    block.y = _y;
    block.h = _height;
    block.w = _width;
    SDL_RenderFillRect(renderer, &block);
}

void LaserCannon::printStatus() {

}