#include "shader.hpp"

#include <fstream>
#include <iostream>
#include <vector>
#include <utility>

/* helper function for reading shaders
 */
std::string readFile(const std::string &filePath) {
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


Shader::Shader()
    :   program(0) {}


Shader::~Shader() {
    glDeleteProgram(program);
}


//TODO throw if error
//TODO box up redundant code
Shader::Shader(std::string vertPath, std::string fragPath) 
    :   vertPath(vertPath), fragPath(fragPath) {
    const char *vertSrc = readFile(vertPath).c_str();
    const char *fragSrc = readFile(fragPath).c_str();
    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    GLint result = GL_FALSE;
    int logLength;

    std::cout << "Compiling vertex shader." << std::endl;
    glShaderSource(vertShader, 1, &vertSrc, NULL);
    glCompileShader(vertShader);

    // Check vertex shader
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
    std::cout << &vertShaderError[0] << std::endl;

    std::cout << "Compiling fragment shader." << std::endl;
    glShaderSource(fragShader, 1, &fragSrc, NULL);
    glCompileShader(fragShader);

    // Check fragment shader
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
    std::cout << &fragShaderError[0] << std::endl;

    std::cout << "Linking program." << std::endl;
    program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);

    // Check shader program
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> programError( (logLength > 1) ? logLength : 1 );
    glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
    std::cout << &programError[0] << std::endl;
}


// explicit move may not be necessary
Shader::Shader(Shader &&shader) 
    :   program(shader.program) {
    vertPath = std::move(shader.vertPath);
    fragPath = std::move(shader.fragPath);
    shader.program = 0;
}


// explicit move may not be necessary
Shader &Shader::operator=(Shader &&shader) {
    program = shader.program;
    vertPath = std::move(shader.vertPath);
    fragPath = std::move(shader.fragPath);
    shader.program = 0;
}


void Shader::bind() const {
    glUseProgram(program);
}


//TODO Create new shader then move if OK
void Shader::reload() {
}
