#pragma once

#include <glad/glad.h>
#include <string>
#include <vector>

namespace bisera
{
    class Texture {
        GLuint buffer = 0;
        unsigned int width = 0, height = 0;
        std::string filepath;

    public:
        Texture();
        ~Texture();
        Texture(std::string texPath);
        Texture(unsigned int width, unsigned int height, const std::vector<unsigned char> &image);
        
        Texture(Texture &&texture);
        Texture &operator=(Texture &&texture);

        Texture(const Texture &texture) = delete;
        Texture &operator=(const Texture &texture) = delete;

    public:
        void bind() const;

    private:
        void createBuffer(const std::vector<unsigned char> &image);
    };
}
