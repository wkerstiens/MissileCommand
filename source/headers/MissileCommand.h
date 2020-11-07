//
// Created by William Kerstiens on 11/6/20.
//
#include <cstddef>
#include <vector>

#include "Keyboard.h"
#include "Renderer.h"
#include "City.h"

#ifndef MISSILECOMMAND_MISSILECOMMAND_H
#define MISSILECOMMAND_MISSILECOMMAND_H
#include "GameComponent.h"

class MissileCommand : public GameComponent {
public:
    MissileCommand(std::size_t width, std::size_t height, std::size_t target_frame_duration);
    void Run();
    void Running(bool running);
    bool Running();

    void printStatus() override;

private:
    std::size_t _width{640};
    std::size_t _height{640};
    std::size_t _target_frame_duration {14};
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Keyboard> keyboard;
    bool _running {true};
    std::mutex mtxRunning;

    std::vector<std::unique_ptr<City>> cities {};

    void HandleInput();
    void Update();
};

#endif //MISSILECOMMAND_MISSILECOMMAND_H
