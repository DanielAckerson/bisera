#include "mainwindow.h"

#include <iostream>

MainWindow::MainWindow()
:   window(nullptr), monitor(nullptr), width(1280), height(720) {
    // Initialize glfw
    if(!glfwInit()) {
        throw "error: failed to init glfw";
    }

    // Required to get up-to-date OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Set monitor for fullscreen
    // For borderless window, see http://www.glfw.org/docs/latest/window_guide.html#window_windowed_full_screen
    /* monitor = glfwGetPrimaryMonitor(); */

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(width, height, "Bisera", monitor, NULL);
    if(!window) {
        glfwTerminate();
        throw "error: failed to create window";
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        glfwTerminate();
        throw "error: failed to load OpenGL with glad";
    }

    // The official code for "Setting Your Raster Position to a Pixel Location" (i.e. set up a camera for 2D screen)
    glViewport(0, 0, width, height);
    /*
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    */

    // Make some OpenGL properties better for 2D and enable alpha channel.
    /*
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    */
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);

    std::cout << "OpenGL " << glGetString(GL_VERSION)
        << ", GLSL " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    // Set user pointer to reference this instance from static calls
    // this is useless. maybe point to input handler instead
    /* glfwSetWindowUserPointer(window, this); */
    std::cout << "MainWindow created!" << std::endl;
}


MainWindow::~MainWindow() {
    glfwTerminate();
    std::cout << "MainWindow destroyed!" << std::endl;
}
