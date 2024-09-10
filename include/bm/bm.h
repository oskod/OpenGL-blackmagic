#include "glad/glad.h"
#include "GLFW/glfw3.h"

#define PI 3.14159265359
#define TAU 6.28318530718

#pragma region STRUCTS & TYPES

typedef struct {
	double x;
	double y;
} vec2;

typedef struct {
	GLFWwindow* window;
	double currentTime;
	double delta;
	vec2 pos;
} bmProgramState;

#pragma endregion
#pragma region STATE HANDLERS

// init
void initState(bmProgramState* programState);
void initRender(bmProgramState* programState);
void initMain(bmProgramState* programState);

// loops
void processInput(bmProgramState* programState);
void logic(bmProgramState* programState);
void render(bmProgramState* programState);
void processGL(bmProgramState* programState);
void mainLoop(bmProgramState* programState);

#pragma endregion