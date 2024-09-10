#include "bm/bm.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define terminate(message) { \
	printf("TERMINATED:\n\t%s\n", message); \
	glfwTerminate(); \
	return -1; \
}

#pragma region OPENGL CALLBACKS
void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
#pragma endregion

int main() {
	// Initialize GLFW, glad and rendering context
	if (glfwInit() != 1) {
		printf("Failed to initialize GLFW");
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "My awesome window", NULL, NULL);
	if (!window) terminate("Failed to create window");

	glfwMakeContextCurrent(window);

	if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) == 0) terminate("Could not initialize OpenGL context");

	// init
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	bmProgramState programState;
	programState.window = window;

	bmInitMain(&programState);
	// main loop
	while (!glfwWindowShouldClose(window)) bmMainLoop(&programState);

	glfwTerminate();
	return 0;
}