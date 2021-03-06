#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <glad/glad.h>
#include <string>
#include <vector>

class Texture {
    GLuint buffer;
    unsigned int width, height;
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
    void unbind() const;

private:
    void createBuffer(const std::vector<unsigned char> &image);
};

#endif//TEXTURE_HPP
