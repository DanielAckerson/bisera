#include "game.h"
#include <iostream>

Game::Game() {
    /* Initialize glfw */
    if(!glfwInit()) {
        throw "error: failed to init glfw";
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if(!window) {
        glfwTerminate();
        throw "error: failed to create window";
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    std::cout << "Game created!" << std::endl;
}


Game::~Game() {
    glfwTerminate();
    std::cout << "Game destroyed!" << std::endl;
}


void Game::start() {
    /* Loop until the user closes the window */
    while(!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
}
