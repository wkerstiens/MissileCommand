//
// Created by William Kerstiens on 11/7/20.
//

#include "LaserCannon.h"
#include <iostream>
#include <math.h>

float getSlope(float x1, float y1, float x2, float y2) {
    return (y1 - y2) / (x1 - x2);
}

float getB( float m, float x1, float y1) {
    return y1 - m * x1;
}

float getY(float x1, float m, float b) {
    return m * x1 + b;
}

// This filled circle function borrowed from https://gist.github.com/Gumichan01/332c26f6197a432db91cc4327fcabb1c
void SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius)
{
    int offsetX, offsetY, d;
    int status;

    offsetX = 0;
    offsetY = radius;
    d = radius -1;
    status = 0;

    while (offsetY >= offsetX) {
        status += SDL_RenderDrawLine(renderer, x - offsetY, y + offsetX, x + offsetY, y + offsetX);
        status += SDL_RenderDrawLine(renderer, x - offsetX, y + offsetY, x + offsetX, y + offsetY);
        status += SDL_RenderDrawLine(renderer, x - offsetX, y - offsetY, x + offsetX, y - offsetY);
        status += SDL_RenderDrawLine(renderer, x - offsetY, y - offsetX, x + offsetY, y - offsetX);

        if (status < 0) break;

        if (d >= 2 * offsetX) {
            d -= 2 * offsetX + 1;
            offsetX +=1;
        } else if (d < 2 * (radius - offsetY)) {
            d += 2 * offsetY - 1;
            offsetY -= 1;
        } else {
            d += 2 * (offsetY - offsetX - 1);
            offsetY -= 1;
            offsetX += 1;
        }
    }
}



LaserCannon::LaserCannon(int x, int y, int w, int h) : _x(x), _y(y), _width(w), _height(h), _status(LASER_CANNON_STATUS::READY) {
    _centerOfCannon = _x + _width / 2;
    _currentX = _centerOfCannon;
    _currentY = _y;
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
    if(_status == LASER_CANNON_STATUS::DESTROYED ) {
        SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0X20);
        return;
    }
    else SDL_SetRenderDrawColor(renderer, 0x55, 0xbb, 0x55, 0xFF);
    block.x = _x;
    block.y = _y;
    block.h = _height;
    block.w = _width;
    SDL_RenderFillRect(renderer, &block);

    if(_targetX != 0 && _targetY !=0 && (_status == LASER_CANNON_STATUS::FIRING || _status == LASER_CANNON_STATUS::EXPLODING)) { // draw the laser
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
        SDL_RenderDrawLine(renderer, _centerOfCannon, _y, static_cast<int>(_currentX), static_cast<int>(_currentY));
    }

    if(_status == LASER_CANNON_STATUS::EXPLODING) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x60);
        SDL_RenderFillCircle(renderer, _targetX, _targetY, _radius);
    }
}

void LaserCannon::Update() {

    float m, b;
    switch(_status) {
        case LASER_CANNON_STATUS::READY:
            break;
        case LASER_CANNON_STATUS::FIRING:
            if(_centerOfCannon < _targetX) _currentX++;
            else if(_centerOfCannon > _targetX) _currentX--;
            m = getSlope(_centerOfCannon, _y, _targetX, _targetY);
            b = getB(m, _centerOfCannon, _y);
            if(_targetX == _centerOfCannon) {
                _currentY--;
            } else {
                _currentY = getY(_currentX, m, b);
            }
            if(abs(_targetX - static_cast<int>(_currentX)) < 2 && abs(_targetY - static_cast<int>(_currentY)) < 2) {
                _status = LASER_CANNON_STATUS::EXPLODING;
            }
            break;
        case LASER_CANNON_STATUS::EXPLODING:
            _radius+=.25;
            if(_radius > 50.2) _status = LASER_CANNON_STATUS::RECHARGING;
            break;
        case LASER_CANNON_STATUS::RECHARGING:
            _currentX = _centerOfCannon;
            _currentY = _y;
            _radius = 0;
            _status = LASER_CANNON_STATUS::READY;
            break;
        case LASER_CANNON_STATUS::DESTROYED:
            break;
    }

//    if(_status == LASER_CANNON_STATUS::FIRING) {
//        if(_centerOfCannon < _targetX) _currentX++;
//        else if(_centerOfCannon > _targetX) _currentX--;
//        float m = getSlope(_centerOfCannon, _y, _targetX, _targetY);
//        float b = getB(m, _centerOfCannon, _y);
//        if(_targetX == _centerOfCannon) {
//            _currentY--;
//        } else {
//            _currentY = getY(_currentX, m, b);
//        }
//    }
//
//    if(abs(_targetX - static_cast<int>(_currentX)) < 2 && abs(_targetY - static_cast<int>(_currentY)) < 2) {
//        _status = LASER_CANNON_STATUS::EXPLODING;
//    }
//
//    if(_status == LASER_CANNON_STATUS::RECHARGING) {
//        _currentX = _centerOfCannon;
//        _currentY = _y;
//
//    }

}

void LaserCannon::printStatus() {

}

int LaserCannon::TargetX() {
    return _targetX;
}

void LaserCannon::TargetX(int x) {
    if(x < 1) x = 1;
    else if(x > 640) x = 640;
    _targetX = x;
}

int LaserCannon::TargetY() {
    return _targetY;
}

void LaserCannon::TargetY(int y) {
    if(y < 1) y = 1;
    else if(y > 640) y = 640;
    _targetY = y;
}
