#include "SpriteRenderer.h"




SpriteRenderer::SpriteRenderer(glm::mat4 projection)
{
	this->colorShader = new Shader(std::vector<std::string>{"Shader/ColorVertex.vs", "Shader/ColorFragment.fs"}, std::vector<unsigned int>{GL_VERTEX_SHADER, GL_FRAGMENT_SHADER});
	this->textureShader = new Shader(std::vector<std::string>{"Shader/TextureVertex.vs", "Shader/TextureFragment.fs"}, std::vector<unsigned int>{GL_VERTEX_SHADER, GL_FRAGMENT_SHADER});

	this->colorShader->bind();
	this->colorShader->setUniformMat4fv("projection", projection);

	this->textureShader->bind();
	this->textureShader->setUniformMat4fv("projection", projection);


	Call(glGenVertexArrays(1, &VAO));
	Call(glBindVertexArray(VAO));


	float quad[] = {  0.0f, 1.0f, 0.0f, 1.0f,
					  1.0f, 0.0f, 1.0f, 0.0f,
					  0.0f, 0.0f, 0.0f, 0.0f,

					  0.0f, 1.0f, 0.0f, 1.0f,
					  1.0f, 1.0f, 1.0f, 1.0f,
					  1.0f, 0.0f, 1.0f, 0.0f };

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), quad, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (const void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (const void*)(sizeof(float) * 2));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

SpriteRenderer::~SpriteRenderer()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	delete colorShader;
	delete textureShader;
}

void SpriteRenderer::draw(glm::vec2 position, glm::vec2 scale, glm::vec3 color, float rotation)
{
	colorShader->bind();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(position, 0.0f));

	if (rotation != 0)
	{
		model = glm::translate(model, glm::vec3(0.5f * scale.x, 0.5f * scale.y, 0.0f));
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::translate(model, glm::vec3(-0.5f * scale.x, -0.5f * scale.y, 0.0f));
	}

	model = glm::scale(model, glm::vec3(scale, 1.0f));
	colorShader->setUniformMat4fv("model", model);
	colorShader->setUniform3f("color", color);


	Call(glBindVertexArray(VAO));
	Call(glDrawArrays(GL_TRIANGLES, 0, 6));
	glBindVertexArray(0);
}

void SpriteRenderer::draw(Texture& texture, glm::vec2 position, glm::vec2 scale, glm::vec3 color, float rotation)
{
	textureShader->bind();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(position, 0.0f));

	if (rotation != 0)
	{
		model = glm::translate(model, glm::vec3(0.5f * scale.x, 0.5f * scale.y, 0.0f));
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::translate(model, glm::vec3(-0.5f * scale.x, -0.5f * scale.y, 0.0f));
	}

	model = glm::scale(model, glm::vec3(scale, 1.0f));
	textureShader->setUniformMat4fv("model", model);
	textureShader->setUniform3f("color", color);

	glActiveTexture(GL_TEXTURE0);
	texture.bind();

	Call(glBindVertexArray(VAO));
	Call(glDrawArrays(GL_TRIANGLES, 0, 6));
	glBindVertexArray(0);
}
