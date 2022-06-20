#include "x33.h"

#include "glew.h"
#include "glfw3.h"
#include "glm/glm/glm.hpp"
#include "glm/glm/ext.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "Shaders/MyGLfunctions.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


GLFWwindow* RCMAINWINDOW;



int main() {

	init_gl(&RCMAINWINDOW);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	static const GLfloat g_vertex_buffer_data[] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	GLuint programID = LoadShaders("Shaders/Vertex_main.glsl", "Shaders/Fragment_white.glsl");

	glUseProgram(programID);

	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(4, 3, 3), // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);

	transform(programID,45,4,3,&View);


	while (!glfwWindowShouldClose(RCMAINWINDOW))
	{
		
		draw(&vertexbuffer);

		glfwSwapBuffers(RCMAINWINDOW);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}

