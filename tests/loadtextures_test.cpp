#include <glad/glad.h>
#include <bisera/mainwindow.hpp>
#include <bisera/texture.hpp>
#include <bisera/mesh.hpp>
#include <bisera/shader.hpp>
#include <vector>
#include <string>
using namespace std;



int main() {
vector<Mesh::Vertex> vertices = {
//  Position------------   Normals--------   Texcoords--
    {{-0.5f,  0.5f, 0.0f}, {1.0f,1.0f,1.0f}, {0.0f, 0.0f}}, // 0 Top-left
    {{ 0.5f,  0.5f, 0.0f}, {1.0f,1.0f,1.0f}, {1.0f, 0.0f}}, // 1 Top-right
    {{ 0.5f, -0.5f, 0.0f}, {1.0f,1.0f,1.0f}, {1.0f, 1.0f}}, // 2 Bottom-right
    {{-0.5f, -0.5f, 0.0f}, {1.0f,1.0f,1.0f}, {0.0f, 1.0f}}  // 3 Bottom-left
};


// these refer to the vertex array
vector<unsigned int> indices = {
    0, 1, 2,    // Top-left triangle
    2, 3, 0     // Bottom-right triangle
};


vector<unsigned char> colors = {
    0xff, 0xff, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00,
    0xff, 0x00, 0x00, 0x00,
    0xff, 0xff, 0x00, 0xff
};

    MainWindow window;
    Mesh mesh(vertices, indices);
    Shader basicShader(
        "assets/loadtextures.vs",
        "assets/loadtextures.fs");
    Texture texture1("assets/loadtextures_checkered.png");
    Texture texture2(2, 2, colors);

    mesh.bind();
    texture1.bind();
    basicShader.bind();

//render
    while(!glfwWindowShouldClose(window.context())) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        //draws currently bound element array buffer
        //  requires vao, vbo, and ebo bound
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window.context());
    }

    return 0;
}
