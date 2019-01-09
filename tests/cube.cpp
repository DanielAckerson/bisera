#include <glad/glad.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <bisera/mainwindow.hpp>
#include <bisera/texture.hpp>
#include <bisera/mesh.hpp>
#include <bisera/shader.hpp>

int main()
{
    bisera::MainWindow window;
    bisera::Mesh mesh("assets/cube.obj");
    bisera::Shader basicShader(
            "assets/textures.vs",
            "assets/textures.fs");
    bisera::Texture texture1("assets/checkered.png");

    mesh.bind();
    texture1.bind();
    basicShader.bind();

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);
	  
	glm::mat4 View = glm::lookAt(
		glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
		glm::vec3(0,0,0), // and looks at the origin
		glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
	  
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4(1.0f);

	glm::mat4 mvp = Projection * View * Model; // Remember, matrix multiplication is the other way around

    while (!glfwWindowShouldClose(window.context())) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, mesh.elementCount(), GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window.context());
    }

    return 0;
}
