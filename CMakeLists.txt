cmake_minimum_required(VERSION 3.8)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(MissileCommand)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} headers)

add_executable(MissileCommand source/main.cpp headers/MissileCommand.h source/MissileCommand.cpp source/Renderer.cpp headers/Renderer.h headers/EventHandler.h source/EventHandler.cpp headers/GameComponent.h source/GameComponent.cpp headers/Drawable.h source/City.cpp headers/City.h source/LaserCannon.cpp headers/LaserCannon.h)

string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(MissileCommand ${SDL2_LIBRARIES})