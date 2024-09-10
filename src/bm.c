#include "bm/bm.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#pragma region STATE HANDLERS

//init
void initState(bmProgramState* programState) {
	programState->currentTime = glfwGetTime();
}
void initRender(bmProgramState* programState) {
}
void initMain(bmProgramState* programState) {
	initState(programState);
	initRender(programState);
}

// loops
void processInput(bmProgramState* programState) {
	if (glfwGetKey(programState->window, GLFW_KEY_ESCAPE) == true)
		glfwSetWindowShouldClose(programState->window, true);
}
void logic(bmProgramState* programState) {
	// time and delta
	double currentTime = glfwGetTime();
	programState->delta = currentTime - programState->currentTime;
	programState->currentTime = currentTime;

	programState->pos.x = cosf(currentTime) / 5.0;
	programState->pos.y = sinf(currentTime) / 5.0;
}
void render(bmProgramState* programState) {
	glClearColor(
		cosf(programState->currentTime) * 0.5 + 0.5,
		cosf(programState->currentTime - TAU / 3.0) * 0.5 + 0.5,
		cosf(programState->currentTime - TAU / 1.5) * 0.5 + 0.5,
	1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}
void processGL(bmProgramState* programState) {
	glfwSwapBuffers(programState->window);

	glfwPollEvents();
}
void mainLoop(bmProgramState* programState) {
	processInput(programState);
	logic(programState);
	render(programState);
	processGL(programState);
}

#pragma endregion