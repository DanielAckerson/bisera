#include "mainmenu_state.h"

#include <iostream>

MainMenu_State::MainMenu_State() {
}


MainMenu_State::~MainMenu_State() {
    std::cout << "state destroyed" << std::endl;
}


void MainMenu_State::init() {
}


void MainMenu_State::close() {
}


void MainMenu_State::pause() {
}


void MainMenu_State::play() {
}


void MainMenu_State::render(Game *game) {
}


void MainMenu_State::update(Game *game) {
}


void MainMenu_State::handleEvents(Game *game) {
}
