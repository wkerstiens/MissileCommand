//
// Created by William Kerstiens on 11/6/20.
//
#include <memory>
#include "SDL.h"
#include "City.h"

#ifndef MISSILECOMMAND_RENDERER_H
#define MISSILECOMMAND_RENDERER_H

class Renderer : public GameComponent {
public:
    Renderer();
    Renderer(const std::size_t screen_width, const std::size_t screen_height);
    ~Renderer();

    void Render(std::vector<std::unique_ptr<City>> &cities);
    void SetTitle(int fps);

    void printStatus() override;

private:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
    const std::size_t _screen_width;
    const std::size_t _screen_height;

    void RenderCities(std::vector<std::unique_ptr<City>> &cities);
    void DrawGround();
};


#endif //MISSILECOMMAND_RENDERER_H
