#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include <chrono>
#include <vector>

class GameState;

class Game {
    GLFWwindow *window;
    GLFWmonitor *monitor;

    bool running;
    std::vector<GameState *> states;

    using Clock = std::chrono::high_resolution_clock;
    //Clock::time_point startTime;

public:
    void init();
    void close();
    void loop();

    void changeState(GameState *state);
    void pushState(GameState *state);
    void popState();

    void pause();
    void play();

    void render();
    void update();
    void handleEvents();

    bool isRunning() { return running; }
    void quit() { running = false; }

public:
    Game();
    ~Game();
};

#include "gamestate.h"

#endif//GAME_H
