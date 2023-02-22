#pragma once
#include "src/Shader/Shader.h"
#include "src/Texture/Texture.h"
#include "RenderInfo.h"

class Entity;

class Renderer
{
	Shader* shader;
public:
	explicit Renderer(Shader& _shader);
	~Renderer();
    void draw(const Entity& e);
	void draw(const RenderInfo& drawData);
	void enable2D();
	void enable3D();
    Shader& getShader() {return *shader;}
};

