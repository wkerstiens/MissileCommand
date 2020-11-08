# Missile Command
Missile Command is a 1980 arcade game developed and published by Atari, Inc. and licensed to Sega for European release. 
It was designed by Dave Theurer, who also designed Atari's vector graphics game Tempest from the same year.
The 1981 Atari 2600 port of Missile Command by Rob Fulop sold over 2.5 million copies.

This simple version was developed by William Kerstiens to help me better understand the SDL Library.

## Plot
The player's six cities are being attacked by and endless hail of ballistic missiles.  As a regional commander of three 
anti-missile batteries, the player must defend six cities in their zone from being destroyed.

For my interpretation of this classic the anti-missile batteries are laser canons that can only be fired at some yet 
determined time frame.

## Project Information
All source files are located in the source directory and all header files are in the source/headers directory.  All the
classes in this project are GameComponents and anything that is drawable is also derived from the Drawable class.

In it's current state the game should compile and run.  You should be able to fire from all three batteries and once all 
your cities are destroyed the game is over.

Use your mouse pointer to aim and the following keys to fire.

A - Fires left cannon  
S - Fires middle cannon  
D - Fires right cannon  

------

## Readme Rubric
- [x] A README with instructions is included with the project.
- [x] This README describes the project I have built.
- [x] This project includes information about each rubric point addressed.
- [x] The submission must compile and run.

## Loops, Functions, I/O
- [x] This project demonstrates an understanding of C++ functions and control structures. This is almost every cpp file
- [ ] This project reads data from a file and processes data or the program writes data to a file.
- [x] The project accepts user input and processes the input.  This code can be located in the EventHandler class.

## Object Oriented Programming
- [x] The project uses Object Oriented Programming techniques.
- [x] Classes use appropriate access specifiers for class members.
- [x] Class constructors utilize member initialization lists.
- [x] Classes abstract implementation details from their interfaces.
- [x] Class encapsulate behavior
- [x] Classes follow an appropriate inheritance hierarchy.
- [x] Overloaded functions allow the same function to operate on different parameters.
- [x] Derived class functions override virtual base class functions.
- [x] Templates generalize functions in the project. This can be found in the Render class

## Memory Management
- [x] The project makes use of references in function declarations. Renderer.cpp line 72
- [ ] The project uses destructors appropriately.
- [x] The project uses scope / RAII where appropriate
- [ ] This project follows the Rule of 5
- [x] The project uses move semantics to move data, instead of copying it where possible.  MissileCommand.cpp line 87
- [x] The project uses smart pointers instead of raw pointers.  MissileCommand.cpp line 12

## Concurrency
- [ ] The project uses multithreading
- [ ] A promise and a future is used in the project.
- [x] A mutex or lock is used in the project
- [ ] A condition variable is used.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./MissileCommand`


## References
1.  https://en.wikipedia.org/wiki/Missile_Command