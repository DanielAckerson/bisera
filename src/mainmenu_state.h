#ifndef MAINMENU_STATE_H
#define MAINMENU_STATE_H

#include "gamestate.h"

class MainMenu_State : public GameState {
public:
    virtual void init();
    virtual void close();

    virtual void pause();
    virtual void play();
    
    virtual void render(Game *game);
    virtual void update(Game *game);
    virtual void handleEvents(Game *game);

public:
    MainMenu_State();
    ~MainMenu_State();
};

#endif//MAINMENU_STATE_H
