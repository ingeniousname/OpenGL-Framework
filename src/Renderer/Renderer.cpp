#include "Renderer.h"
#include "src/Entity/Entity.h"

Renderer::Renderer()
{
	colorShader.createFromFile("src/Shader/Color");
	textureShader.createFromFile("src/Shader/Texture");
}

Renderer::~Renderer()
{
}

void Renderer::draw(const RenderInfo& drawData)
{
	colorShader.bind();
	Call(glBindVertexArray(drawData.VAO));
	Call(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, drawData.IBO));
	Call(glDrawElements(GL_TRIANGLES, drawData.numIndicies, GL_UNSIGNED_INT, nullptr));
}

void Renderer::draw(const Entity& e)
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, e.getPosition());
    model = glm::rotate(model, glm::radians(e.getRotation().x), {0.f, 1.f, 0.f});
    model = glm::scale(model, e.getScale());
    colorShader.setUniformMat4fv("model", model);
    this->draw(e.getRenderInfo());
}

void Renderer::enable3D()
{
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
}

void Renderer::updateProjectionViewMatrix(glm::mat4x4 VP)
{
	colorShader.setUniformMat4fv("VP", VP);
	//textureShader.setUniformMat4fv("VP", VP);
}

void Renderer::enable2D()
{
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
}



