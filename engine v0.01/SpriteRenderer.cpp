#include "SpriteRenderer.h"




SpriteRenderer::SpriteRenderer(Shader& shader) : Renderer(shader)
{
	float quad[12] = { 0.0f, 1.0f,
					  1.0f, 0.0f,
					  0.0f, 0.0f,

					  0.0f, 1.0f,
					  1.0f, 1.0f,
					  1.0f, 0.0f };
	this->initData(quad, 12);
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::draw(glm::vec2 position, glm::vec2 scale, glm::vec3 color, float rotation)
{
	preDrawFunction(position, scale, color, rotation);
	Call(glBindVertexArray(VAO));
	Call(glDrawArrays(GL_TRIANGLES, 0, 6));
	glBindVertexArray(0);
}
