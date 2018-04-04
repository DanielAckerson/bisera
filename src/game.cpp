#include "game.h"
#include "mainmenu_state.h"

#include <iostream>

Game::Game()
:   window(nullptr), monitor(nullptr), running(false) {
    /* Initialize glfw */
    if(!glfwInit()) {
        throw "error: failed to init glfw";
    }
    std::cout << "Game created!" << std::endl;
}


Game::~Game() {
    if(running) {
        close();
    }
    glfwTerminate();
    std::cout << "Game destroyed!" << std::endl;
}


void Game::init() {
    // set monitor for fullscreen
    // for borderless window, see http://www.glfw.org/docs/latest/window_guide.html#window_windowed_full_screen
    /* monitor = glfwGetPrimaryMonitor(); */

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", monitor, NULL);
    if(!window) {
        glfwTerminate();
        throw "error: failed to create window";
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    running = true;
    pushState(new MainMenu_State());
    std::cout << "Game initialized!" << std::endl;
}


void Game::close() {
}


void Game::loop() {
    /* Loop until the user closes the window */
    int counter = 0;
    while(running) {
        std::cout << "looped " << counter << " times" << std::endl;
        update();
        render();
        counter++;
    }
}


void Game::changeState(GameState *state) {
}


void Game::pushState(GameState *state) {
}


void Game::popState() {
}


void Game::render() {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);
}


void Game::update() {
    handleEvents();
    if(glfwWindowShouldClose(window)) {
        quit();
    }
}


void Game::handleEvents() {
    /* Poll for and process events */
    glfwPollEvents();
}
