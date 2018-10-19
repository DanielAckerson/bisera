#pragma once

#include <bisera/mainwindow.hpp>

#include <vector>

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

#endif//RENDER_HPP
