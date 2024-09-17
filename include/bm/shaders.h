#ifndef __bm_shaders_h_
#define __bm_shaders_h_

// functions
unsigned int bmCreateShader(const char* shaderSource, unsigned int shaderType);
unsigned int bmCreateShaderProgram(unsigned int* shaders, int shaderCount);

#endif