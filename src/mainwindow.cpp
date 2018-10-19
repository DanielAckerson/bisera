#include <bisera/mainwindow.hpp>

#include <iostream>

namespace bisera
{
    MainWindow::MainWindow()
    :   width(1280), height(720)
    {
        if (!glfwInit())
            throw "error: failed to init glfw";

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, "Bisera", monitor, NULL);
        if (!window) {
            glfwTerminate();
            throw "error: failed to create window";
        }

        glfwMakeContextCurrent(window);
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            glfwTerminate();
            throw "error: failed to load OpenGL with glad";
        }

        glViewport(0, 0, width, height);

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        glDisable(GL_ALPHA_TEST);

        std::cout <<
            "OpenGL " << glGetString(GL_VERSION) <<
            ", GLSL " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
        std::cout << "MainWindow created!" << std::endl;
    }


    MainWindow::~MainWindow()
    {
        glfwTerminate();
        std::cout << "MainWindow destroyed!" << std::endl;
    }
}
