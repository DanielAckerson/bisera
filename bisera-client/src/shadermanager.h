#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <glad/glad.h>
#include <string>
#include <unordered_map>
#include <utility>

/* maybe return void for the addShader methods
 * that way, threads/promises/futures can be used
 * the getShader will wait for the thread to complete if it hasn't already
 */

class ShaderManager {
    // Maps shader program name to std::pair of program ID and reference count
    std::unordered_map<std::string, std::pair<GLuint,int>> programs;
    //can only cache with load, not with loadInline
    std::unordered_map<std::string, GLuint> shaderCache;

public:
    ShaderManager();
    ~ShaderManager();

public:
    /* Get shaders from files
     * Load shaders into OpenGL
     * Enter shader program ID in shaders[name]
     * return program ID
     */
    void load(std::string name, std::string vertexPath, std::string fragmentPath);
    /* Pass whole shader programs as strings
     * Load shaders into OpenGL
     * Enter shader program ID in shaders[name]
     * return program ID
     */
    void loadInline(std::string name, std::string vertexSource, std::string fragmentSource);

    /* Find shader program by name
     * Delete shader program from OpenGL
     * Delete shader program entry from shaders
     */
    void disown(std::string name);

    /* Find shader program by name
     * Tell OpenGL to use that program
     */
    void useProgram(std::string name);
};

#endif//SHADERMANAGER_H
