#include "bm/bm.h"
#include "bm/shaders.h"

unsigned int bmCreateShader(const char* shaderSource, unsigned int shaderType) {
	unsigned int shader;
	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);

	return shader;
}
unsigned int bmCreateShaderProgram(unsigned int* shaders, int shaderCount) {
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	for (int i = 0; i < shaderCount; i++) {
		glAttachShader(shaders[i*2], shaders[i*2 + 1]);
	}
	glLinkProgram(shaderProgram);

	return shaderProgram;
}