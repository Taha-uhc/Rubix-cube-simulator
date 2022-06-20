#pragma once
#ifndef MYGLFUNC
#define MYGLFUNC
#include "ReadShaders.h"
#include "glew.h"
#include "glfw3.h"
#include "../glm/glm/glm.hpp"
#include "../glm/glm/ext.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"


#include <iostream>
#include <vector>
#include <string>
#include <fstream>



bool init_gl(GLFWwindow** RCMAINWINDOW) {
	if (!glfwInit())
		return false;
	*RCMAINWINDOW = glfwCreateWindow(1280, 720, "x33", NULL, NULL);

	if (!RCMAINWINDOW)
	{
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(*RCMAINWINDOW);

	if (glewInit() != GLEW_OK) {
		return false;
	}

}

void draw(GLuint* vertexbuffer) {

	glClear(GL_COLOR_BUFFER_BIT);


	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, *vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
}

void transform(GLuint programID, float FOV, int ratiox, int ratioy, glm::mat4* View) {
	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective<float>(glm::radians(FOV), (float)ratiox / (float)ratioy, 0.1f, 100.0f);




	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4(1.0f);
	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 mvp = Projection * (*View) * Model; // Remember, matrix multiplication is the other way around


	GLuint MatrixID = glGetUniformLocation(programID, "MVP");


	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);
}

#endif