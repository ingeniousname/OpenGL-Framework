#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "/Users/Mi³osz/source/repos/openglV3/glm/glm/glm.hpp"
#include "/Users/Mi³osz/source/repos/openglV3/glm/glm/gtx/transform.hpp"


void glClearError();
bool glCheckError();


#define Call(x) x; \
				glCheckError() 


std::string read_from_file(const std::string& filename);

class Shader
{
	std::unordered_map<std::string, int> locationCache;
	unsigned int m_RendererID;
public:
	Shader() { m_RendererID = 0; };
	Shader(const std::vector<std::string>& filepaths, const std::vector<unsigned int>& types);
	void bind() const;
	void unbind() const;
	void setUniform1f(const std::string& name, float v0);
	void setUniform3f(const std::string& name, glm::vec3 v);
	void setUniform4f(const std::string& name, glm::vec4 v);
	void setUniformMat4fv(const std::string& name, glm::mat4 matrix);
private:
	int GetUniformLocation(const std::string& name);
	unsigned int CreateShader(GLenum type, const std::string& strShaderFile);
	unsigned int CompileProgram(std::vector<unsigned int> shaderList);
};

