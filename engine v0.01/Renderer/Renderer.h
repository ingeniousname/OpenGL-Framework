#pragma once
#include "engine v0.01/Shader/Shader.h"


class Renderer
{
protected:
	unsigned int VAO, VBO;
	Shader shader;
	void initData(float* data, int datasize);
	void preDrawFunction(glm::vec2 position, glm::vec2 scale, glm::vec3 color, float rotation = 0.0f);
public:
	Renderer(Shader& shader);
	~Renderer();
};

