#include "mainmenu_state.hpp"

#include <glad/glad.h>
#include <iostream>

MainMenu_State::MainMenu_State(bisera::Game *game)
:   GameState(game) {
    //TODO init meshes and materials
    std::cout << "main menu state created" << std::endl;
}


MainMenu_State::~MainMenu_State() {
    std::cout << "main menu state destroyed" << std::endl;
}


void MainMenu_State::pause() {
}


void MainMenu_State::resume() {
}


void MainMenu_State::render() {
}


void MainMenu_State::update() {
}


void MainMenu_State::handleEvents() {
}
