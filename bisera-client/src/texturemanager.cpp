#include "texturemanager.h"
#include <lodepng.h>
#include <vector>

TextureManager::TextureManager() {
}


TextureManager::~TextureManager() {
    for(auto &kv : textures) {
        glDeleteTextures(1, kv.second);
    }
}


/* Get texture from image file
 * Load texture into OpenGL
 * Enter texture ID in textures[name]
 * return texture ID
 */
GLuint TextureManager::addTexture(std::string name, std::string texPath) {
    std::vector<unsigned char> image;
    unsigned int width, height;
    unsigned int error = lodepng::decode(image, width, height, filename);
    if(error != 0) {
        throw "error: lodepng error";
        //cout << "error " << error << ": " << lodepng_error_text(error) << endl;
    }
    return addTexture(name, width, height, image);
}


/* Pass whole image as vector<unsigned char>
 * Load texture into OpenGL
 * Enter texture ID in textures[name]
 * return texture ID
 */
GLuint TextureManager::addTextureInline(std::string name, unsigned int width, unsigned int height, const std::vector<unsigned char> &image) {
    GLuint texID;
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
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
    return texID;
}


/* Find texture by name
 * Delete texture from OpenGL
 * Delete texture entry from textures
 */
void TextureManager::removeShader(std::string name) {
}


/* Find first occurence of texture by texture ID
 * Delete texture from OpenGL
 * Delete texture entry from textures
 */
void TextureManager::removeShader(GLuint texID) {
}


GLuint TextureManager::getTexture(std::string name) {
}
