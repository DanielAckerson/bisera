#ifndef MAINMENU_STATE_H
#define MAINMENU_STATE_H

#include "gamestate.h"

class MainMenu_State : public GameState {
public:
    MainMenu_State();
    ~MainMenu_State();

public:
    virtual void pause();
    virtual void resume();
    
    virtual void render(Game *game);
    virtual void update(Game *game);
    virtual void handleEvents(Game *game);
};

#endif//MAINMENU_STATE_H
