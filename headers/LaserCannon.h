//
// Created by William Kerstiens on 11/7/20.
//
#include "Drawable.h"

#ifndef MISSILECOMMAND_LASERCANNON_H
#define MISSILECOMMAND_LASERCANNON_H

enum class LASER_CANNON_STATUS {
    RECHARGING,
    READY,
    FIRING,
    EXPLODING,
    DESTROYED

};


class LaserCannon : public Drawable {
public:
    LaserCannon(int x, int y, int w, int h);
    void Render(SDL_Renderer *renderer) override;
    void printStatus() override;
    void Update() override;

    int TargetX();
    void TargetX( int x);
    int TargetY();
    void TargetY( int y);

    LASER_CANNON_STATUS Status();
    void Status(LASER_CANNON_STATUS status);
protected:
private:
    std::mutex _mtxStatus;
    LASER_CANNON_STATUS _status;
    int _x {0};
    int _y {0};
    int _width{0};
    int _height {0};

    int _targetX {0};
    int _targetY {0};
    int _centerOfCannon;

    float _currentX;
    float _currentY;
    float _radius;
};


#endif //MISSILECOMMAND_LASERCANNON_H
