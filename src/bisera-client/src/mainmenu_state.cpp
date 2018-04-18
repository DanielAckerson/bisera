#include "mainmenu_state.h"
#include "mainwindow.h"
#include "render.h"

#include <GLFW/glfw3.h>
#include <iostream>

MainMenu_State::MainMenu_State() {
    std::cout << "menu state created" << std::endl;
}


MainMenu_State::~MainMenu_State() {
    std::cout << "menu state destroyed" << std::endl;
}


void MainMenu_State::pause() {
}


void MainMenu_State::resume() {
}


void MainMenu_State::render(Game *game) {
    // this can't work because glfwGetWindowUserPointer needs the GLFWwindow*
    //auto window = reinterpret_cast<MainWindow *>(glfwGetWindowUserPointer());
}


void MainMenu_State::update(Game *game) {
}


void MainMenu_State::handleEvents(Game *game) {
}
