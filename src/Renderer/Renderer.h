#pragma once
#include "src/Shader/Shader.h"
#include "src/Texture/Texture.h"
#include "RenderInfo.h"

class Entity;

class Renderer
{
	Shader textureShader, colorShader;
	void draw(const RenderInfo& drawData);
public:
	Renderer();
	~Renderer();
    void draw(const Entity& e);
	void enable2D();
	void enable3D();
	void updateProjectionViewMatrix(glm::mat4x4 VP);
};

