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
void ShaderManager::load(std::string name, std::string vertexPath std::string fragmentPath) {
    if(programs.count(name)) {
        programs[name].second++;
        return;
    }
    const std::string vertexSource = readFile(vertexPath),
    const std::string fragmentSource = readFile(fragmentPath);
    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    GLint result = GL_FALSE;
    int logLength;

    // Compile vertex shader
    std::cout << "Compiling vertex shader." << std::endl;
    glShaderSource(vertShader, 1, &vertexSource.c_str(), NULL);
    glCompileShader(vertShader);

    // Check vertex shader
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
    std::cout << &vertShaderError[0] << std::endl;

    // Compile fragment shader
    std::cout << "Compiling fragment shader." << std::endl;
    glShaderSource(fragShader, 1, &fragmentSource.c_str(), NULL);
    glCompileShader(fragShader);

    // Check fragment shader
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
    std::cout << &fragShaderError[0] << std::endl;

    // Link program
    std::cout << "Linking program" << std::endl;
    GLuint program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);

    // Get any errors
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> programError( (logLength > 1) ? logLength : 1 );
    glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
    std::cout << &programError[0] << std::endl;

    shaderCache[vertexPath] = vertShader;
    shaderCache[fragmentPath] = fragShader;
    programs[name] = std::make_pair(program, 1);
}


/* Pass whole shader programs as strings
 * Load shaders into OpenGL
 * Enter shader program ID in shaders[name]
 * return program ID
 */
void ShaderManager::loadInline(std::string name, const std::string &vertexSource, const std::string &fragmentSource) {
    if(programs.count(name)) {
        programs[name].second++;
        return;
    }
    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    GLint result = GL_FALSE;
    int logLength;

    // Compile vertex shader
    std::cout << "Compiling vertex shader." << std::endl;
    glShaderSource(vertShader, 1, &vertexSource.c_str(), NULL);
    glCompileShader(vertShader);

    // Check vertex shader
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
    std::cout << &vertShaderError[0] << std::endl;

    // Compile fragment shader
    std::cout << "Compiling fragment shader." << std::endl;
    glShaderSource(fragShader, 1, &fragmentSource.c_str(), NULL);
    glCompileShader(fragShader);

    // Check fragment shader
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
    std::cout << &fragShaderError[0] << std::endl;

    // Link program
    std::cout << "Linking program" << std::endl;
    GLuint program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);

    // Get any errors
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> programError( (logLength > 1) ? logLength : 1 );
    glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
    std::cout << &programError[0] << std::endl;

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
    programs[name] = std::make_pair(program, 1);
}


/* Find shader program by name
 * Delete shader program from OpenGL
 * Delete shader program entry from shaders
 */
void ShaderManager::disown(std::string name) {
}


/* Find shader program by name
 * Tell OpenGL to use that program
 */
void ShaderManager::useProgram(std::string name) {
    glUseProgram(programs.at(name));
}
