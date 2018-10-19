#pragma once

#include <bisera/mainwindow.hpp>

#include <vector>

namespace bisera
{
    class Renderable {
    protected:
        Renderable();
    public:
        virtual void render() = 0;
    };


    class Renderer {
        MainWindow *window;
        
    public:
        Renderer(MainWindow *window);

        friend class Renderable;

    public:
        virtual void render(const std::vector<Renderable> &renderables);
    };
}
