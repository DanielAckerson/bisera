#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>

// #include "audiosystem.h"
// #include "scene.h"
// #include "timer.h"
// #include "eventhandler.h"
// #include "input.h"

class Game {
    GLFWwindow *window;

    // AudioSystem aSys;
    // EventHandler eHandler;
    // Timer timer;

public:
    Game();
    ~Game();
    
    void start();

private:
    void render();
    void update();
};

#endif//GAME_H
