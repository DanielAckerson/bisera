#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace bisera
{
    class MainWindow {
        GLFWwindow *window = nullptr;
        GLFWmonitor *monitor = nullptr;
        GLuint width, height;

    public:
        MainWindow();
        ~MainWindow();

    public:
        inline GLFWwindow *context() { return window; }
    };
}
