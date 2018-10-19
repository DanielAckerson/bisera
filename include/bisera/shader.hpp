#pragma once

#include <glad/glad.h>
#include <string>

namespace bisera
{
    class Shader {
        GLuint program = 0;
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
}
