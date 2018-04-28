#include "shadermanager.h"
#include <fstream>
#include <iostream>
#include <vector>

ShaderManager::ShaderManager() {
}


ShaderManager::~ShaderManager() {
    for(auto &kv : shaders) {
        glDeleteProgram(kv.second);
    }
}


/* helper function for reading shaders
 */
std::string readFile(std::string filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);
    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }
    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }
    fileStream.close();
    return content;
}


/* Get shaders from files
 * Load shaders into OpenGL
 * Enter shader program ID in shaders[name]
 * return program ID
 */
GLuint ShaderManager::addShader(std::string name, std::string vertexPath std::string fragmentPath) {
    std::string vertShaderStr = readFile(vertexPath),
    std::string fragShaderStr = readFile(fragment_path);
    return addShaderInline(name, vertShaderStr, fragShaderStr);
}


/* Pass whole shader programs as strings
 * Load shaders into OpenGL
 * Enter shader program ID in shaders[name]
 * return program ID
 */
GLuint ShaderManager::addShaderInline(std::string name, std::string vertexProgram, std::string fragmentProgram) {
    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char *vertShaderSrc = vertexProgram.c_str();
    const char *fragShaderSrc = vertexProgram.c_str();
    GLint result = GL_FALSE;
    int logLength;

    // Compile vertex shader
    std::cout << "Compiling vertex shader." << std::endl;
    glShaderSource(vertShader, 1, &vertShaderSrc, NULL);
    glCompileShader(vertShader);

    // Check vertex shader
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
    std::cout << &vertShaderError[0] << std::endl;

    // Compile fragment shader
    std::cout << "Compiling fragment shader." << std::endl;
    glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
    glCompileShader(fragShader);

    // Check fragment shader
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
    std::cout << &fragShaderError[0] << std::endl;

    std::cout << "Linking program" << std::endl;
    GLuint program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> programError( (logLength > 1) ? logLength : 1 );
    glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
    std::cout << &programError[0] << std::endl;

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return program;
}


/* Find shader program by name
 * Delete shader program from OpenGL
 * Delete shader program entry from shaders
 */
void ShaderManager::removeShader(std::string name) {
}


/* Find first occurence of shader program by programID
 * Delete shader program from OpenGL
 * Delete shader program entry from shaders
 */
void ShaderManager::removeShader(GLuint programID) {
}


GLuint ShaderManager::getShader(std::string name) {
    return shaders.at(name);
}
