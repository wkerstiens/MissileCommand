//
// Created by William Kerstiens on 11/7/20.
//

#include "City.h"

City::City(int x, int y, int w, int h) : _x(x), _y(y), _width(w), _height(h), _status(CITY_STATUS::INTACT) {

}

CITY_STATUS City::Status() {
    std::unique_lock<std::mutex> lock(_mtxStatus);
    return _status;
}

void City::Status(CITY_STATUS status) {
    std::unique_lock<std::mutex> lock(_mtxStatus);
    _status = status;
}

void City::Render(SDL_Renderer *renderer) {
    SDL_Rect block;
    if(_status == CITY_STATUS::DESTROYED ) SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0X20);
    else SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xff, 0xFF);
    block.x = _x;
    block.y = _y;
    block.h = _height;
    block.w = _width;
    SDL_RenderFillRect(renderer, &block);
}

void City::printStatus() {

}
