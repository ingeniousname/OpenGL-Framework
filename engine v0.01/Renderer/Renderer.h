#pragma once
#include "engine v0.01/Shader/Shader.h"
#include "engine v0.01/Texture/Texture.h"
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

