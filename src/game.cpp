#include <bisera/game.hpp>

#include <iostream>

namespace bisera
{
    Game::Game(Renderer *renderer)
    :   renderer(renderer)
    {
        std::cout << "Game created!" << std::endl;
    }


    Game::~Game()
    {
        std::cout << "Game destroyed!" << std::endl;
    }


    //TODO loop only when active && there is at least one game state
    void Game::start()
    {
        using namespace std::chrono;
        const Tick dt (1.0);
        Tick accumulator (0.0);
        auto currentTime = Clock::now();
        int ups = 0;
        int fps = 0;
        active = true;
        while (active) {
            auto newTime = Clock::now();
            auto frameTime = duration_cast<Tick>(newTime - currentTime);
            currentTime = newTime;
            accumulator += frameTime;
            while (accumulator >= dt) {
                handleEvents();
                update();
                accumulator -= dt;
                if (++ups >= Tick::period::den) {
                    std::cout << fps << "fps"  << std::endl;
                    ups = 0;
                    fps = 0;
                }
            }
            render();
            fps++;
        }
    }


    // if previous state, assumes paused
    // else pushes new state
    void Game::changeState(GameState *state)
    {
        if (!states.empty())
            states.pop_back();
        states.emplace_back(state);
    }


    void Game::pushState(GameState *state)
    {
        pause();
        states.emplace_back(state);
    }


    void Game::popState()
    {
        if (!states.empty())
            states.pop_back();
        else
            throw "error: no GameState to pop";
        resume();
    }


    void Game::pause()
    {
        if (!states.empty())
            states.back()->pause();
    }


    void Game::resume()
    {
        if (!states.empty())
            states.back()->resume();
    }


    void Game::render()
    {
        renderer->clear();
        states.back()->render();
        renderer->swapBuffers();
    }


    void Game::update()
    {
        states.back()->update();
    }


    void Game::handleEvents()
    {
        //Poll for and process events
        states.back()->handleEvents();
    }
}
