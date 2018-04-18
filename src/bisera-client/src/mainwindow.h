#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class MainWindow {
    GLFWwindow *window;
    GLFWmonitor *monitor;
    GLuint width, height;

public:
    inline GLFWwindow *context() { return window; }

public:
    MainWindow();
    ~MainWindow();
};

#endif//MAINWINDOW_H
