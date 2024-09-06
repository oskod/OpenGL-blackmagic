#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define TAU 6.28318530718

#define terminate(message) { \
	printf("TERMINATED:\n\t%s\n", message); \
	glfwTerminate(); \
	return -1; \
}

typedef struct {
	GLFWwindow* window;
	double currentTime;
	double delta;
} bmProgramState;

void logic(bmProgramState* programState) {
	// time and delta
	double currentTime = glfwGetTime();
	programState->delta = currentTime - programState->currentTime;
	programState->currentTime = currentTime;
}
void render(bmProgramState* programState) {
	glClearColor(
		cosf(programState->currentTime) * 0.5 + 0.5,
		cosf(programState->currentTime - TAU / 3.0) * 0.5 + 0.5,
		cosf(programState->currentTime - TAU / 1.5) * 0.5 + 0.5,
	1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}
void process(bmProgramState* programState) {
	glfwSwapBuffers(programState->window);

	glfwPollEvents();
}
void mainLoop(bmProgramState* programState) {
	logic(programState);
	render(programState);
	process(programState);
}

int main() {
	// Initialize GLFW, glad and rendering context
	if (glfwInit() != 1) {
		printf("Failed to initialize GLFW");
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(800, 600, "My awesome window", NULL, NULL);
	if (!window) terminate("Failed to create window");

	glfwMakeContextCurrent(window);

	if (gladLoadGL() == 0) terminate("Could not initialize OpenGL context");

	bmProgramState programState;
	programState.window = window;

	// main loop
	while (!glfwWindowShouldClose(window)) mainLoop(&programState);

	glfwTerminate();
	return 0;
}