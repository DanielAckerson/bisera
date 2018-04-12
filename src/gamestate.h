#ifndef GAMESTATE_H
#define GAMESTATE_H

/* class Game; */

#include "game.h"

class GameState {
public:
    virtual void init() = 0;
    virtual void close() = 0;

    virtual void pause() = 0;
    virtual void play() = 0;
    
    virtual void render(Game *game) = 0;
    virtual void update(Game *game) = 0;
    virtual void handleEvents(Game *game) = 0;

    /* void changeState(Game *game, GameState *state); */

    void changeState(Game *game, GameState *state) {
        game->changeState(state);
    }

protected:
    GameState() {}
};

/* #include "game.h" */

/* void GameState::changeState(Game *game, GameState *state) { */
/*     game->changeState(state); */
/* } */


#endif//GAMESTATE_H
