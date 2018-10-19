#include <bisera/mesh.hpp>

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


Mesh::Mesh(const std::vector<Mesh::Vertex> &vertices, const std::vector<Face> &faces) {
    makeGlObject(vertices, faces);
}


Mesh::Mesh(std::string objFilePath)
    :   filename(objFilePath) {
    std::vector<Vertex> vertices;
    std::vector<Face> faces;
    readObjFile(vertices, faces);
    makeGlObject(vertices, faces);
}


Mesh::Mesh(Mesh &&mesh)
    :   vao(mesh.vao),
        vbo(mesh.vbo),
        ebo(mesh.ebo),
        element_count(mesh.element_count) {
    mesh.vao = 0;
    mesh.vbo = 0;
    mesh.ebo = 0;
    mesh.element_count = 0;
    filename = std::move(mesh.filename);
}


Mesh &Mesh::operator=(Mesh &&mesh) {
    vao = mesh.vao;
    vbo = mesh.vbo;
    ebo = mesh.ebo;
    element_count = mesh.element_count;
    mesh.vao = 0;
    mesh.vbo = 0;
    mesh.ebo = 0;
    mesh.element_count = 0;
    return *this;
}


void Mesh::bind() const {
    glBindVertexArray(vao);
}


unsigned int Mesh::elementCount() const {
    return element_count;
}


void Mesh::readObjFile(std::vector<Mesh::Vertex> &vertices, std::vector<Mesh::Face> &faces) {
    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> UVs;
    /* std::vector<Face> faces; */
    std::fstream fs(filename);
}


void Mesh::makeGlObject(const std::vector<Vertex> &vertices, const std::vector<Face> &faces) {
    assert(!vertices.empty() && !faces.empty());
    element_count = faces.size() * faces[0].size();
    //gen IDs
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    //bind data
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(
        GL_ARRAY_BUFFER,
        vertices.size() * sizeof(Vertex),
        vertices.data(),
        GL_STATIC_DRAW);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        element_count * sizeof(Face::value_type),
        faces.data(),
        GL_STATIC_DRAW);
    //describe how to pass to shader
    //vertex positions: layout(location = 0) in vec3 position;
    glEnableVertexAttribArray(0);	
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        (void*) 0);
    //vertex normals:   layout(location = 1) in vec3 normal;
    glEnableVertexAttribArray(1);	
    glVertexAttribPointer(
        1,
        3,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        (void*) sizeof(glm::vec3));
    //vertex UVs:       layout(location = 2) in vec2 UV;
    glEnableVertexAttribArray(2);	
    glVertexAttribPointer(
        2,
        2,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        (void*) (sizeof(glm::vec3) * 2));
}
