/*  bisera.cpp
 *  This is the main file for the game Bisera
 *
 *  before doing input, checkout https://gamedev.stackexchange.com/questions/58541/how-can-i-associate-a-key-callback-with-a-wrapper-class-instance
 *
 *  should support bare minimum opengl 3.0
 *      https://www.khronos.org/opengl/wiki/History_of_OpenGL#OpenGL_3.0_.282008.29
 *
 *  think about switching from GLEW to glad
 */

#include <iostream>

#include <bisera/game.hpp>
#include "mainmenu_state.hpp"

int main()
{
    try {
        Game bisera;
        bisera.pushState(new MainMenu_State(&bisera));
        bisera.start();
    } catch(const char *err) {
        std::cerr << err << std::endl;
        return 1;
    }
    return 0;
}
