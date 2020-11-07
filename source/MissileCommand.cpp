//
// Created by William Kerstiens on 11/6/20.
//
#include <mutex>
#include <iostream>
#include "MissileCommand.h"
#include "Keyboard.h"
#include "Renderer.h"
#include "SDL.h"

MissileCommand::MissileCommand(std::size_t width, std::size_t height, std::size_t target_frame_duration)
        : _width(width), _height(height), _target_frame_duration(target_frame_duration) {
    renderer = std::make_unique<Renderer>(_width, _height);
    keyboard = std::make_unique<Keyboard>();
    cities.push_back(std::make_unique<City>(80, 580, 50, 30));
    cities.push_back(std::make_unique<City>(150, 580, 50, 30));
    cities.push_back(std::make_unique<City>(220, 580, 50, 30));
    cities.push_back(std::make_unique<City>(370, 580, 50, 30));
    cities.push_back(std::make_unique<City>(440, 580, 50, 30));
    cities.push_back(std::make_unique<City>(510, 580, 50, 30));

    laserCannons.push_back(std::make_unique<LaserCannon>(20, 550, 20, 30));
    laserCannons.push_back(std::make_unique<LaserCannon>(310, 550, 20, 30));
    laserCannons.push_back(std::make_unique<LaserCannon>(600, 550, 20, 30));

    Running(true);
    std::lock_guard<std::mutex> lock(_mtxCout);
    std::cout << "Missile Command instantiated. \n";
}


void MissileCommand::Run() {
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 last_console_dump = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;

    while (Running()) {
        frame_start = SDL_GetTicks();
        // input, update, render
        HandleInput();
        Update();
        renderer->Render(cities, laserCannons);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000) {
            renderer->SetTitle(frame_count);
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // After every 10 seconds, dump info to console.
        if (frame_end - last_console_dump >= 100000) {
            printStatus();
            last_console_dump = frame_end;
        }

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < _target_frame_duration) {
            SDL_Delay(_target_frame_duration - frame_duration);
        }

    }
}

void MissileCommand::Running(bool running) {
    std::unique_lock<std::mutex> lck (mtxRunning);
    _running = running;
}

bool MissileCommand::Running() {
    std::unique_lock<std::mutex> lck (mtxRunning);
    return _running;
}

void MissileCommand::HandleInput() {
    keyboard->HandleInput(std::move(_running));
}

void MissileCommand::Update() {

}

void MissileCommand::printStatus()  {
    std::unique_lock<std::mutex> lock(_mtxCout);
    std::cout << "Missile command is running\n";
    lock.unlock();
    keyboard->printStatus();
    renderer->printStatus();
}
