#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include <chrono> //switch to glfwGetTime if need faster clock
#include <ratio>
#include <vector>
#include <memory> //shared_ptr

/* #include "gamestate.h" */
#include "render.h" //Renderer, Renderable

/* Handling keyboard/joystick input per GameState
 *  set glfw user pointer to Game* instance
 *  each state must handle inputs
 *  only get input from gamestate on top of stack
 */
class GameState;

class Game {
    GLFWwindow *window;
    GLFWmonitor *monitor;

    bool running;
    std::vector<std::shared_ptr<GameState>> states;

    using gclock = std::chrono::steady_clock;
    using update_t = std::chrono::duration<double, std::ratio<1,100>>;
    //gclock::time_point startTime;

public:
    void init();
    void close();
    void run();

    void changeState(GameState *state);
    void pushState(GameState *state);
    void popState();

    void pause();
    void play();

    void render();
    void update();
    void handleEvents();

    bool isRunning() const { return running; }
    void quit() { running = false; }

public:
    Game();
    ~Game();
};

#include "gamestate.h"

#endif//GAME_H
