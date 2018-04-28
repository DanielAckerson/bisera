#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <glad/glad.h>
#include <string>
#include <unordered_map>


/* maybe return void for the addShader methods
 * that way, threads/promises/futures can be used
 * the getShader will wait for the thread to complete
 */

class ShaderManager {
    std::unordered_map<std::string, GLuint> shaders;

public:
    /* Get shaders from files
     * Load shaders into OpenGL
     * Enter shader program ID in shaders[name]
     * return program ID
     */
    GLuint addShader(std::string name, std::string vertexPath std::string fragmentPath);
    /* Pass whole shader programs as strings
     * Load shaders into OpenGL
     * Enter shader program ID in shaders[name]
     * return program ID
     */
    GLuint addShaderInline(std::string name, std::string vertexProgram, std::string fragmentProgram);

    /* Find shader program by name
     * Delete shader program from OpenGL
     * Delete shader program entry from shaders
     */
    void removeShader(std::string name);

    /* Find first occurence of shader program by programID
     * Delete shader program from OpenGL
     * Delete shader program entry from shaders
     */
    void removeShader(GLuint programID);

    GLuint getShader(std::string name);

public:
    ShaderManager();
    ~ShaderManager();
};

#endif//SHADERMANAGER_H
