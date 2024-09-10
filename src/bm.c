#include "bm/bm.h"
#include "bm/shaders.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#pragma region STATE HANDLERS

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
	shaderProgram = bmCreateShaderProgram((unsigned int[]){
		vertexShader, GL_VERTEX_SHADER,
		fragmentShader, GL_FRAGMENT_SHADER
	}, 2);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// triangle
	float vertices[] = {
		 0.0, 0.5, 0.0,
		-0.5, -0.5, 0.0,
		 0.5, -0.5, 0.0
	};

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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
	glClearColor(
		cosf(programState->currentTime) * 0.5 + 0.5,
		cosf(programState->currentTime - TAU / 3.0) * 0.5 + 0.5,
		cosf(programState->currentTime - TAU / 1.5) * 0.5 + 0.5,
	1.0);
	glClear(GL_COLOR_BUFFER_BIT);
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