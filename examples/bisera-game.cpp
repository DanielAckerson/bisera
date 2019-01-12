/*  bisera.cpp
 *  This is the main file for the game Bisera
 *
 *  before doing input, checkout https://gamedev.stackexchange.com/questions/58541/how-can-i-associate-a-key-callback-with-a-wrapper-class-instance
 *
 *  should support bare minimum opengl 3.0
 *      https://www.khronos.org/opengl/wiki/History_of_OpenGL#OpenGL_3.0_.282008.29
 */

#include <iostream>
#include <memory>

#include <bisera/renderer.hpp>
#include <bisera/mainwindow.hpp>
#include <bisera/game.hpp>

#include "mainmenu_state.hpp"

class MyRenderer : public bisera::Renderer {
    GLFWwindow *window;

public:
    MyRenderer(GLFWwindow *window)
    :   window(window)
    { }

    virtual void clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    virtual void swapBuffers()
    {
        glfwSwapBuffers(window);
    }
};


int main()
{
    try {
        bisera::MainWindow window;
        MyRenderer renderer(window.context());
        bisera::Game bisera(&renderer);
        bisera.pushState(new MainMenu_State(&bisera));
        bisera.start();
    } catch (char const *err) {
        std::cerr << err << std::endl;
        return 1;
    }
    return 0;
}
