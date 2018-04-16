#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GLFW/glfw3.h>

class MainWindow {
    GLFWwindow *window;
    GLFWmonitor *monitor;

public:
    inline operator GLFWwindow*() { return window; }

public:
    MainWindow();
    ~MainWindow();
};

#endif//MAINWINDOW_H
