#ifndef RENDER_H
#define RENDER_H

#include <GLFW/glfw3.h>

class Game;


class Renderable {
public:
    virtual void render() = 0;
protected:
    Renderable();
};


class Renderer {
    Game *game;
public:
    virtual void render();
    
public:
    Renderer();
    ~Renderer();

    friend class Renderable;
};

#include "game.h"

#endif//RENDER_H
