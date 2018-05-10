#ifndef GAME_H
#define GAME_H

#include <chrono>   //switch to glfwGetTime if need faster clock
#include <ratio>
#include <vector>
#include <memory>   //unique_ptr

#include "mainwindow.h"

class Game;

class GameState {
protected:
    Game *game;

public:
    GameState(Game *game) : game(game) {}
    virtual ~GameState() {}

public:
    virtual void pause() = 0;
    virtual void resume() = 0;
    
    virtual void render() = 0;
    virtual void update() = 0;
    virtual void handleEvents() = 0;
};


class Game {
    std::vector<std::unique_ptr<GameState>> states;
    std::unique_ptr<MainWindow> window;
    bool active;

public:
    Game();
    ~Game();

    //prevent copying
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

    using Clock = std::chrono::steady_clock;
    using Tick = std::chrono::duration<double, std::ratio<1,100>>;

public:
    void start();

    /* changeState pops top state and pushes new one
     * may need to queue state for removal
     */
    void changeState(GameState *state);

    /* pushState loads new state on top of stack.
     * pauses states below.
     */
    void pushState(GameState *state);

    /* popState unloads top state.
     * plays state below.
     * may need to queue state for removal
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
};

#endif//GAME_H
