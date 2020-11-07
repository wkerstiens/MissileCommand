//
// Created by William Kerstiens on 11/6/20.
//
#include <memory>
#include "SDL.h"
#include "City.h"
#include "LaserCannon.h"

#ifndef MISSILECOMMAND_RENDERER_H
#define MISSILECOMMAND_RENDERER_H

class Renderer : public GameComponent {
public:
    Renderer();
    Renderer(const std::size_t screen_width, const std::size_t screen_height);
    ~Renderer();

    void Render(std::vector<std::unique_ptr<City>> &cities, std::vector<std::unique_ptr<LaserCannon>> &laserCannons);
    void SetTitle(int fps);

    void printStatus() override;

private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
    const std::size_t _screen_width;
    const std::size_t _screen_height;

    template <class T>
    void Render(std::vector<std::unique_ptr<T>> &drawables);
    void DrawGround();
};


#endif //MISSILECOMMAND_RENDERER_H
