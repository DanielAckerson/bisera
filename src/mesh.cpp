#include "mesh.hpp"

#include <iostream>
#include <fstream>
#include <utility>

Mesh::Mesh()
:   vao(0), vbo(0), ebo(0) {}


Mesh::~Mesh() {
    glDeleteBuffers(1, &ebo);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1,&vao);
}


Mesh::Mesh(const std::vector<Mesh::Vertex> &vertices, const std::vector<unsigned int> &indices) {
    assert(!vertices.empty() && !indices.empty() && indices.size() % 3 == 0);
    //gen IDs
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    //bind data
    std::cout << "if mesh isn't renderered, check here in ctor" << std::endl;
    bind(); //may need to manually bind before each glBufferData call
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    //describe how to pass to shader
    //vertex positions: layout(location = 0) in vec3 position;
    glEnableVertexAttribArray(0);	
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0);
    //vertex normals:   layout(location = 1) in vec3 normal;
    glEnableVertexAttribArray(1);	
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) sizeof(glm::vec3));
    //vertex UVs:       layout(location = 2) in vec2 UV;
    glEnableVertexAttribArray(2);	
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) (sizeof(glm::vec3) * 2));
    //unbind vao
    unbind();
}


Mesh::Mesh(const std::string &objFilePath) {
    throw "Mesh file ctor not implemented";
    std::fstream fs(objFilePath);
}


Mesh::Mesh(Mesh &&mesh)
    :   vao(mesh.vao),
        vbo(mesh.vbo),
        ebo(mesh.ebo) {
    mesh.vao = 0;
    mesh.vbo = 0;
    mesh.ebo = 0;
}


Mesh &Mesh::operator=(Mesh &&mesh) {
    vao = mesh.vao;
    vbo = mesh.vbo;
    ebo = mesh.ebo;
    mesh.vao = 0;
    mesh.vbo = 0;
    mesh.ebo = 0;
    return *this;
}


void Mesh::bind() const {
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
}


void Mesh::unbind() const {
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
