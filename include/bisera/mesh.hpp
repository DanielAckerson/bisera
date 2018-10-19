#ifndef MESH_HPP
#define MESH_HPP

#include <glad/glad.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include <array>
#include <string>

class Mesh {
    GLuint vao, vbo, ebo;
    unsigned int element_count;
    std::string filename;

public:
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 uv;
    };

    using Face = std::array<unsigned int, 3>;

public:
    Mesh();
    ~Mesh();
    Mesh(const std::vector<Vertex> &vertices, const std::vector<Face> &faces);
    Mesh(std::string objFilePath);

    Mesh(Mesh &&mesh);
    Mesh &operator=(Mesh &&mesh);

    Mesh(const Mesh &) = delete;
    Mesh &operator=(const Mesh &) = delete;

public:
    void bind() const;
    unsigned int elementCount() const;

private:
    void readObjFile(std::vector<Vertex> &vertices, std::vector<Face> &faces);
    void makeGlObject(const std::vector<Vertex> &vertices, const std::vector<Face> &faces);
};

#endif//MESH_HPP
