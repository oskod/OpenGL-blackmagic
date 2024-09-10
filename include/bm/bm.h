#ifndef __bm_main_h_
#define __bm_main_h_

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
void bmInitState(bmProgramState* programState);
void bmInitRender(bmProgramState* programState);
void bmInitMain(bmProgramState* programState);

// loops
void bmProcessInput(bmProgramState* programState);
void bmLogic(bmProgramState* programState);
void bmRender(bmProgramState* programState);
void bmProcessGL(bmProgramState* programState);
void bmMainLoop(bmProgramState* programState);

#pragma endregion

#endif