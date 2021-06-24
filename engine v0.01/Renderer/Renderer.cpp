#include "Renderer.h"

void Renderer::initData(float* data, int datasize)
{

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, datasize* sizeof(float), data, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


void Renderer::preDrawFunction(glm::vec2 position, glm::vec2 scale, glm::vec3 color, float rotation)
{
	shader.bind();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(position, 0.0f));

	if (rotation != 0)
	{
		// rotation around the center
		//model = glm::translate(model, glm::vec3(0.5f * scale.x, 0.5f * scale.y, 0.0f));
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
		//model = glm::translate(model, glm::vec3(-0.5f * scale.x, -0.5f * scale.y, 0.0f));
	}

	model = glm::scale(model, glm::vec3(scale, 1.0f));
	shader.setUniformMat4fv("model", model);
	shader.setUniform3f("color", color);
}

Renderer::Renderer(Shader& shader)
{
	this->shader = shader;
	Call(glGenVertexArrays(1, &VAO));
	Call(glBindVertexArray(VAO));
}

Renderer::~Renderer()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}
