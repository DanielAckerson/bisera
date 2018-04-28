#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <glad/glad.h>
#include <string>
#include <unordered_map>

/*also think about making it just a loader, not a manager
 */

/* think about using threads
 */

class TextureManager {
    std::unordered_map<std::string, GLuint> textures;

public:
    TextureManager();
    ~TextureManager();

public:
    /* Get texture from image file
     * Load texture into OpenGL
     * Enter texture ID in textures[name]
     * return texture ID
     */
    GLuint addTexture(std::string name, std::string texPath);

    /* Pass whole image as vector<unsigned char>
     * Load texture into OpenGL
     * Enter texture ID in textures[name]
     * return texture ID
     */
    GLuint addTextureInline(std::string name, unsigned int width, unsigned int height, const std::vector<unsigned char> &image);

    /* Find texture by name
     * Delete texture from OpenGL
     * Delete texture entry from textures
     */
    void removeShader(std::string name);

    /* Find first occurence of texture by texture ID
     * Delete texture from OpenGL
     * Delete texture entry from textures
     */
    void removeShader(GLuint texID);

    GLuint getTexture(std::string name);
};

#endif//TEXTUREMANAGER_H

