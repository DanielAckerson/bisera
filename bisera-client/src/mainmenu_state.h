#ifndef MAINMENU_STATE_H
#define MAINMENU_STATE_H

#include "game.h"
/* #include "mesh.h" */
/* #include "material.h" */

class MainMenu_State : public GameState {
    /* Mesh mesh_background; */
    /* Mesh mesh_buttons; */
    /* Material mat_background; */
    /* Material mat_buttons; */

public:
    MainMenu_State(Game *game);
    ~MainMenu_State();

public:
    virtual void pause();
    virtual void resume();
    
    virtual void render();
    virtual void update();
    virtual void handleEvents();
};

#endif//MAINMENU_STATE_H
