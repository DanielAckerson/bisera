#include <glad/glad.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <bisera/mainwindow.hpp>
#include <bisera/texture.hpp>
#include <bisera/mesh.hpp>
#include <bisera/shader.hpp>
using namespace std;


int main() {
    MainWindow window;
    Mesh mesh("assets/cube.obj");
    Shader basicShader(
            "assets/textures.vs",
            "assets/textures.fs");
    Texture texture1("assets/checkered.png");

    mesh.bind();
    texture1.bind();
    basicShader.bind();

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);
	  
	// Or, for an ortho camera :
	//glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates
	  
	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
		glm::vec3(0,0,0), // and looks at the origin
		glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
		);
	  
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4(1.0f);
	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 mvp = Projection * View * Model; // Remember, matrix multiplication is the other way around<Paste>

    //render
    while(!glfwWindowShouldClose(window.context())) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, mesh.elementCount(), GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window.context());
    }

    return 0;
}
