#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include <chrono> //switch to glfwGetTime if need faster clock
#include <ratio>
#include <vector>
#include <memory> //shared_ptr

/* #include "gamestate.h" */
#include "mainwindow.h"
#include "render.h" //Renderer, Renderable

/* Handling keyboard/joystick input per GameState
 *  set glfw user pointer to Game* instance
 *  each state must handle inputs
 *  only get input from gamestate on top of stack
 */
class GameState;

class Game {
    std::vector<std::shared_ptr<GameState>> states;
    MainWindow window;
    bool active;

    using gclock = std::chrono::steady_clock;
    using update_t = std::chrono::duration<double, std::ratio<1,100>>;

public:
    void start();

    void changeState(GameState *state);
    void pushState(GameState *state);
    void popState();

    void pause();
    void play();

    void render();
    void update();
    void handleEvents();

    inline bool isActive() const { return active; }
    inline void quit() { active = false; }

public:
    Game();
    ~Game();

    //prevent copying
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;
};

#include "gamestate.h"

#endif//GAME_H
