#include "game.h"
#include "mainmenu_state.h"

#include <iostream>

Game::Game() {
    try {
        window = std::make_unique<MainWindow>();
    } catch(const char *err) {
        std::cerr << err << std::endl;
        throw "error: failed to create game";
    }
    active = true;
    pushState(new MainMenu_State(this));
    std::cout << "Game created!" << std::endl;
}


Game::~Game() {
    std::cout << "Game destroyed!" << std::endl;
}


void Game::start() {
    using namespace std::chrono;
    const Tick dt(1.0);
    Tick accumulator(0.0);
    auto currentTime = Clock::now();
    int updates = 0;
    int fps = 0;
    while(active) {
        auto newTime = Clock::now();
        auto frameTime = duration_cast<Tick>(newTime - currentTime);
        currentTime = newTime;
        accumulator += frameTime;
        while(accumulator >= dt) {
            handleEvents();
            update();
            accumulator -= dt;
            if(++updates >= 100) {
                std::cout << fps << "fps"  << std::endl;
                updates = 0;
                fps = 0;
            }
        }
        render();
        fps++;
    }
}


// if previous state, assumes paused
// else pushes new state
void Game::changeState(GameState *state) {
    if(!states.empty())
        states.pop_back();
    states.emplace_back(state);
}


void Game::pushState(GameState *state) {
    pause();
    states.emplace_back(state);
}


void Game::popState() {
    if(!states.empty())
        states.pop_back();
    else
        throw "error: no GameState to pop";
    resume();
}


void Game::pause() {
    if(!states.empty())
        states.back()->pause();
}


void Game::resume() {
    if(!states.empty())
        states.back()->resume();
}


void Game::render() {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* render top state.
     * top state is responsible for rendering any
     *  states that should be rendered in background
     *  (e.g. pauseMenu is top state but the paused
     *  world is still rendered in background).
     */
    states.back()->render();

    /* Swap front and back buffers
     * Vsync by default
     * to turn off Vsync set glfwSwapInterval(0)
     * to turn back on, set glfwSwapInterval(1) (i think)
     */
    glfwSwapBuffers(window->context());
}


void Game::update() {
    if(glfwWindowShouldClose(window->context())) {
        quit();
        return;
    }
    states.back()->update();
}


void Game::handleEvents() {
    //Poll for and process events
    glfwPollEvents();
    states.back()->handleEvents();
}
