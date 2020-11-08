//
// Created by William Kerstiens on 11/7/20.
//
#include "Drawable.h"

#ifndef MISSILECOMMAND_CITY_H
#define MISSILECOMMAND_CITY_H

enum class CITY_STATUS {
    INTACT,
    DESTROYED
};

class City : public Drawable {
public:
    City(int x, int y, int w, int h);
    void Render(SDL_Renderer *renderer) override;
    void printStatus() override;
    void Update() override;

    CITY_STATUS Status();
    void Status(CITY_STATUS status);
protected:
private:
    std::mutex _mtxStatus;
    CITY_STATUS _status;
    int _x {0};
    int _y {0};
    int _width{0};
    int _height {0};


};


#endif //MISSILECOMMAND_CITY_H
