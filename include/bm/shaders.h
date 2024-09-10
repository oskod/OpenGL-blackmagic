#ifndef __bm_shaders_h_
#define __bm_shaders_h_

// temporary shaders
const char* vertexShaderSrc =
"#version 460 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main() {\n"
"	gl_position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSrc =
"#version 460 core\n"
"out vec4 fragColor\n"
"void main() {\n"
"	fragColor = vec(1.0, 0.5, 0.2, 1.0);"
"}\0";

// functions
unsigned int bmCreateShader(const char* shaderSource, unsigned int shaderType);
unsigned int bmCreateShaderProgram(unsigned int* shaders, int shaderCount);

#endif