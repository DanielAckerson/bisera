#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class MainWindow {
    GLFWwindow *window;
    GLFWmonitor *monitor;
    GLuint width, height;

public:
    MainWindow();
    ~MainWindow();

public:
    inline GLFWwindow *context() { return window; }
};

#endif//MAINWINDOW_HPP
