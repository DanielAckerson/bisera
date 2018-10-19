#include <bisera/texture.hpp>

#include <lodepng.h>
#include <vector>
#include <iostream>

namespace bisera
{
    Texture::Texture()
    { }


    Texture::~Texture()
    {
        glDeleteTextures(1, &buffer);
    }


    Texture::Texture(std::string filename)
    {
        std::cout << "loading texture" << std::endl;
        std::vector<unsigned char> image;
        unsigned int error = lodepng::decode(image, width, height, filename);
        if (error)
            throw "error: lodepng error";
        createBuffer(image);
        std::cout << "texture loaded" << std::endl;
    }


    Texture::Texture(unsigned int width, unsigned int height, const std::vector<unsigned char> &image)
    :   width(width), height(height)
    {
        createBuffer(image);
    }


    Texture::Texture(Texture &&texture)
    {
        buffer = texture.buffer;
        texture.buffer = 0;
    }


    Texture &Texture::operator=(Texture &&texture)
    {
        buffer = texture.buffer;
        texture.buffer = 0;
        return *this;
    }


    void Texture::bind() const
    {
        glBindTexture(GL_TEXTURE_2D, buffer);
    }


    void Texture::createBuffer(const std::vector<unsigned char> &image)
    {
        glGenTextures(1, &buffer);
        bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGBA,
            width,
            height,
            0,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            image.data());
    }
}
