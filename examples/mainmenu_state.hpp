#pragma once

#include <bisera/game.hpp>
/* #include "mesh.h" */
/* #include "material.h" */

class MainMenu_State : public bisera::GameState {
    /* Mesh mesh_background; */
    /* Mesh mesh_buttons; */
    /* Material mat_background; */
    /* Material mat_buttons; */

public:
    MainMenu_State(bisera::Game *game);
    ~MainMenu_State();

public:
    virtual void pause();
    virtual void resume();
    
    virtual void render();
    virtual void update();
    virtual void handleEvents();
};
