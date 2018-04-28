#ifndef GAMESTATE_H
#define GAMESTATE_H

class Game;

/* #include "game.h" */

class GameState {
protected:
    GameState() {}

public:
    virtual void pause() = 0;
    virtual void resume() = 0;
    
    virtual void render(Game *game) = 0;
    virtual void update(Game *game) = 0;
    virtual void handleEvents(Game *game) = 0;
};

#include "game.h"

#endif//GAMESTATE_H
