#include "Renderer.h"


Renderer::Renderer()
{
	colorShader.createFromFile("Shader/Color");
	textureShader.createFromFile("Shader/Texture");
}

Renderer::~Renderer()
{
}

void Renderer::draw(RenderInfo& drawData)
{
	colorShader.bind();
	Call(glBindVertexArray(drawData.VAO));
	Call(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, drawData.IBO));
	Call(glDrawElements(GL_TRIANGLES, drawData.numIndicies, GL_UNSIGNED_INT, nullptr));
}

void Renderer::enable3D()
{
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
}

void Renderer::updateProjectionViewMatrix(glm::mat4x4 VP)
{
	colorShader.setUniformMat4fv("VP", VP);
	textureShader.setUniformMat4fv("VP", VP);
}

void Renderer::enable2D()
{
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
}



