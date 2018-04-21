#ifndef GAMESTATE_H
#define GAMESTATE_H

class Game;

/* #include "game.h" */

class GameState {
public:
    // these are done in ctor & dtor so they're probably not necessary
    /* virtual void init() = 0; */
    /* virtual void close() = 0; */

    virtual void pause() = 0;
    virtual void resume() = 0;
    
    virtual void render(Game *game) = 0;
    virtual void update(Game *game) = 0;
    virtual void handleEvents(Game *game) = 0;

    /* not needed because you can just call the public Game::changeState
    void changeState(Game *game, std::shared_ptr<GameState> &state) {
        game->changeState(state);
    }
    */

protected:
    GameState() {}
};

#include "game.h"

#endif//GAMESTATE_H
