#include "mesh.h"

#include <iostream>
#include <fstream>

Mesh::Mesh()
:   VAO(0), VBO(0), EBO(0) {
}


Mesh::Mesh(const std::vector<Mesh::Vertex> &vertices, const std::vector<unsigned int> &indices) {
    assert(!vertices.empty() && !indices.empty() && indices.size() % 3 == 0);
    //gen IDs
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
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
    //unbind VAO
    unbind();
}


Mesh::Mesh(const std::string &objFilePath) {
    std::fstream fs(objFilePath);
}


Mesh::Mesh(Mesh &&mesh) {
    VAO = mesh.VAO;
    VBO = mesh.VBO;
    EBO = mesh.EBO;
    mesh.VAO = 0;
    mesh.VBO = 0;
    mesh.EBO = 0;
}


Mesh &Mesh::operator=(Mesh &&mesh) {
    VAO = mesh.VAO;
    VBO = mesh.VBO;
    EBO = mesh.EBO;
    mesh.VAO = 0;
    mesh.VBO = 0;
    mesh.EBO = 0;
    return *this;
}


Mesh::~Mesh() {
    glDeleteBuffers(1, &EBO);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1,&VAO);
}


void Mesh::bind() const {
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}


void Mesh::unbind() const {
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
