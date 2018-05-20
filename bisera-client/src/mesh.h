#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include <string>

class Mesh {
    GLuint VAO, VBO, EBO;

public:
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 uv;
    };

public:
    Mesh();
    Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &indices);
    Mesh(const std::string &objFilePath);
    Mesh(Mesh &&mesh);

    Mesh &operator=(Mesh &&mesh);

    virtual ~Mesh();

    Mesh(const Mesh &) = delete;
    Mesh &operator=(const Mesh &) = delete;

public:
    void bind() const;
    void unbind() const;
};

#endif//MESH_H
