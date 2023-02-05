#pragma once
#include "Shader/Shader.h"
#include "Texture/Texture.h"
#include "RenderInfo.h"


class Renderer
{
	Shader textureShader, colorShader;
public:
	Renderer();
	~Renderer();
	void draw(RenderInfo& drawData);
	void enable2D();
	void enable3D();
	void updateProjectionViewMatrix(glm::mat4x4 VP);
};

