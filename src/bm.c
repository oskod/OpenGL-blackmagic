#include "bm/bm.h"
#include "bm/shaders.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#pragma region STATE HANDLERS

// temporary shader src
const char* vertexShaderSrc =
"#version 460 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main() {\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSrc =
"#version 460 core\n"
"out vec4 FragColor;\n"
"void main() {\n"
"	FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n"
"}\0";

//init
void bmInitState(bmProgramState* programState) {
	programState->currentTime = glfwGetTime();
}
void bmInitRender(bmProgramState* programState) {
	// shader compilation
	unsigned int vertexShader, fragmentShader;
	vertexShader = bmCreateShader(vertexShaderSrc, GL_VERTEX_SHADER);
	fragmentShader = bmCreateShader(fragmentShaderSrc, GL_FRAGMENT_SHADER);

	unsigned int shaderProgram;
	shaderProgram = bmCreateShaderProgram((unsigned int[]){vertexShader, fragmentShader}, 2);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// triangle
	float vertices[] = {
		 0.0, 0.5, 0.0,
		-0.5, -0.5, 0.0,
		 0.5, -0.5, 0.0
	};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	programState->currentShaderProgram = shaderProgram;
	programState->VAO = VAO;
}
void bmInitMain(bmProgramState* programState) {
	bmInitState(programState);
	bmInitRender(programState);
}

// loops
void bmProcessInput(bmProgramState* programState) {
	if (glfwGetKey(programState->window, GLFW_KEY_ESCAPE) == true)
		glfwSetWindowShouldClose(programState->window, true);
}
void bmLogic(bmProgramState* programState) {
	// time and delta
	double currentTime = glfwGetTime();
	programState->delta = currentTime - programState->currentTime;
	programState->currentTime = currentTime;

	programState->pos.x = cosf(currentTime) / 5.0;
	programState->pos.y = sinf(currentTime) / 5.0;
}
void bmRender(bmProgramState* programState) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(programState->currentShaderProgram);
	glBindVertexArray(programState->VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
void bmProcessGL(bmProgramState* programState) {
	glfwSwapBuffers(programState->window);

	glfwPollEvents();
}
void bmMainLoop(bmProgramState* programState) {
	bmProcessInput(programState);
	bmLogic(programState);
	bmRender(programState);
	bmProcessGL(programState);
}

#pragma endregion