#include "mainwindow.h"

#include <iostream>

MainWindow::MainWindow()
:   window(nullptr), monitor(nullptr), width(1280), height(720) {
    /* Initialize glfw */
    if(!glfwInit()) {
        throw "error: failed to init glfw";
    }
    // set monitor for fullscreen
    // for borderless window, see http://www.glfw.org/docs/latest/window_guide.html#window_windowed_full_screen
    /* monitor = glfwGetPrimaryMonitor(); */

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Bisera", monitor, NULL);
    if(!window) {
        glfwTerminate();
        throw "error: failed to create window";
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        glfwTerminate();
        throw "error: failed to load OpenGL with glad";
    }
    glViewport(0, 0, width, height);
    /* Set user pointer to reference this instance from static calls*/
    /* this is useless. maybe point to input handler instead */
    //glfwSetWindowUserPointer(window, this);
    std::cout << "MainWindow created!" << std::endl;
}


MainWindow::~MainWindow() {
    glfwTerminate();
    std::cout << "MainWindow destroyed!" << std::endl;
}
