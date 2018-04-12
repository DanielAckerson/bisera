#include "game.h"
#include "mainmenu_state.h"

#include <iostream>

Game::Game()
:   window(nullptr), monitor(nullptr), running(false) {
    /* Initialize glfw */
    if(!glfwInit()) {
        throw "error: failed to init glfw";
    }
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
    std::cout << "Game created!" << std::endl;
}


Game::~Game() {
    /*
    if(running) {
        close();
    }
    */
    glfwTerminate();
    std::cout << "Game destroyed!" << std::endl;
}


void Game::run() {
    using namespace std::chrono;
    const update_t dt(1.0);
    update_t t(0.0);
    update_t accumulator(0.0);
    auto currentTime = gclock::now();

    int updates = 0;
    int fps = 0;

    while(running) {
        auto newTime = gclock::now();
        auto frameTime = duration_cast<update_t>(newTime - currentTime);
        currentTime = newTime;
        accumulator += frameTime;

        while(accumulator >= dt) {
            //integrate(state, t, dt);
            update();
            accumulator -= dt;
            t += dt;
            updates++;
            if(updates >= 100) {
                std::cout   << "centiseconds to update: " << frameTime.count()
                            << ", fps: " << fps << std::endl;
                updates = 0;
                fps = 0;
            }
        }
        render();
        fps++;
        //render(state);
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

    /* Swap front and back buffers
     * Vsync by default
     * to turn off Vsync set glfwSwapInterval(0)
     * to turn back on, set glfwSwapInterval(1) (i think)
     */
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
