#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <chrono> //switch to glfwGetTime if need faster clock
#include <ratio>
#include <vector>
#include <memory> //shared_ptr

/* #include "gamestate.h" */
#include "mainwindow.h"
#include "render.h" //Renderer, Renderable
#include "gamestate.h"

/* Handling keyboard/joystick input per GameState
 *  set glfw user pointer to Game* instance
 *  each state must handle inputs
 *  only get input from gamestate on top of stack
 */

class Game {
    std::vector<std::shared_ptr<GameState>> states;
    MainWindow *window;
    bool active;

    using Clock = std::chrono::steady_clock;
    using Tick = std::chrono::duration<double, std::ratio<1,100>>;

public:
    void start();

    /* changeState pops top state and pushes new one
     */
    void changeState(std::shared_ptr<GameState> state);

    /* pushState loads new state on top of stack.
     * pauses states below.
     */
    void pushState(std::shared_ptr<GameState> state);

    /* popState unloads top state.
     * plays state below.
     */
    void popState();

    /* pause prevents update from being called.
     *  events will still be handled
     *  haven't decided if pause also prevents render
     *
     * pause should only be called when window loses focus
     *  or explicitly from same scope as the Game object
     *  (i.e. game.pause() is fine but game->pause() is undefined behavior)
     */
    void pause();
    
    /* resume allows game to update (and render?) again
     * 
     * resume should only be called when window regains focus
     *  or explicitly from same scope as the Game object
     *  (i.e. game.resume() is fine but game->resume() is undefined behavior()
     */
    void resume();

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


#endif//GAME_H
