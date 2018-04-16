#include "game.h"
#include "mainmenu_state.h"

#include <iostream>

Game::Game() {
    try {
        window = new MainWindow();
    } catch (const char *err) {
        std::cerr << err << endl;
        throw "error: failed to create game";
    }
    active = true;
    pushState(new MainMenu_State());
    std::cout << "Game created!" << std::endl;
}


Game::~Game() {
    /*
    if(active) {
        close();
    }
    */
    std::cout << "Game destroyed!" << std::endl;
}


void Game::start() {
    using namespace std::chrono;
    const update_t dt(1.0);
    update_t t(0.0);
    update_t accumulator(0.0);
    auto currentTime = gclock::now();

    int updates = 0;
    int fps = 0;

    while(active) {
        auto newTime = gclock::now();
        auto frameTime = duration_cast<update_t>(newTime - currentTime);
        currentTime = newTime;
        accumulator += frameTime;

        while(accumulator >= dt) {
            //integrate(state, t, dt);
            handleEvents();
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
    if(glfwWindowShouldClose(window)) {
        quit();
    }
}


void Game::handleEvents() {
    /* Poll for and process events */
    glfwPollEvents();
}
