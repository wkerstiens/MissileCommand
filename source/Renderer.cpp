//
// Created by William Kerstiens on 11/6/20.
//
#include <iostream>
#include <algorithm>
#include <future>
#include <vector>
#include "Renderer.h"
#include "City.h"
#include "SDL_blendmode.h"

Renderer::Renderer(const std::size_t screen_width, const std::size_t screen_height)
        : _screen_width(screen_width),
          _screen_height(screen_height) {

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    sdl_window = SDL_CreateWindow("Missile Command", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, screen_width,
                                  screen_height, SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, 0);
    if (nullptr == sdl_renderer) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
}

Renderer::~Renderer() {
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::Render(std::vector<std::unique_ptr<City>> &cities, std::vector<std::unique_ptr<LaserCannon>> &laserCannons) {
    // Clear Screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(sdl_renderer);
    SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_BLEND);

    // RENDER STUFF GOES HERE
    // Async here cause some screen flicker
    DrawGround();
    Render(cities);
    Render(laserCannons);

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::SetTitle(int fps)  {
    std::string title{"Missile Command - William Kerstiens - FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}

void Renderer::printStatus() {
    std::unique_lock<std::mutex> lock(_mtxCout);
    std::cout << "Renderer is running\n";
}

template <class T>
void Renderer::Render(std::vector<std::unique_ptr<T>> &drawables) {
    for ( auto &drawable : drawables) {
        drawable->Render(sdl_renderer);
    }
}

void Renderer::DrawGround() {
    SDL_Rect block;
    SDL_SetRenderDrawColor(sdl_renderer, 0x95, 0x75, 0x1C, 0xFF);
    block.x = 0;
    block.y = _screen_height - 30;
    block.h = 30;
    block.w = _screen_width;
    SDL_RenderFillRect(sdl_renderer, &block);

    // draw turret mounts
    block.y -= 30;
    block.w = 60;
    SDL_RenderFillRect(sdl_renderer, &block);

    block.x = _screen_width / 2 - 30;
    SDL_RenderFillRect(sdl_renderer, &block);

    block.x = _screen_width - 60;
    SDL_RenderFillRect(sdl_renderer, &block);
}