#include <iostream>
#include <thread>
#include "MissileCommand.h"

#include "SDL.h"

int main() {
    constexpr std::size_t screen_width{640};
    constexpr std::size_t screen_height{640};
    constexpr std::size_t framesPerSecond{30};
    constexpr std::size_t msPerFrame{ 1000 / framesPerSecond };

    std::cout << "Welcome to Missile Command.\n";
    std::unique_ptr<MissileCommand> missileCommand = std::make_unique<MissileCommand>(screen_width, screen_height, msPerFrame);
    missileCommand->Run();
    std::cout << "Thanks for playing Missile Command.\n";


    return 0;
}
