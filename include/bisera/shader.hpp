#pragma once

#include <glad/glad.h>
#include <string>

class Shader {
    GLuint program;
    std::string vertPath, fragPath;

public:
    Shader();
    ~Shader();

    Shader(std::string vertPath, std::string fragPath);

    Shader(Shader &&shader);
    Shader &operator=(Shader &&shader);

    Shader(const Shader &) = delete;
    Shader &operator=(const Shader &) = delete;

public:
    void bind() const;
    void reload();
};
