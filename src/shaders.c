#include <stdio.h>
#include "bm/bm.h"
#include "bm/shaders.h"

unsigned int bmCreateShader(const char* shaderSource, unsigned int shaderType) {
	unsigned int shader;
	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);

	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		char errorLog[512];
		glGetShaderInfoLog(shader, 512, NULL, errorLog);
		printf("SHADER COMPILE ERROR:\n\t%s\n", errorLog);
	}

	return shader;
}
unsigned int bmCreateShaderProgram(unsigned int* shaders, int shaderCount) {
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	for (int i = 0; i < shaderCount; i++) {
		printf("Attaching shader %d\n", shaders[i]);
		glAttachShader(shaderProgram, shaders[i]);
	}
	glLinkProgram(shaderProgram);

	int success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		char errorLog[512];
		glGetShaderInfoLog(shaderProgram, 512, NULL, errorLog);
		printf("SHADER PROGRAM LINK ERROR:\n\t%s\n", errorLog);
	}

	return shaderProgram;
}