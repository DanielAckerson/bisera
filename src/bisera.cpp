/*  bisera.cpp
 *  This is the main file for the game Bisera
 */

#include <iostream>

#include "game.h"

int main(void)
{
    try {
        Game bisera;
        bisera.start();
    } catch(const char *msg) {
        std::cerr << msg << std::endl;
        return 1;
    }
    return 0;
}
