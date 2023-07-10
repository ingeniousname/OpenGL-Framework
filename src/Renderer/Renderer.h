#pragma once
#include "src/Shader/Shader.h"
#include "src/Texture/Texture.h"
#include "RenderInfo.h"

#include <memory>

class Entity;

class Renderer
{
	std::shared_ptr<Shader> shader;
public:
	explicit Renderer(std::shared_ptr<Shader>& _shader);
    void draw(const Entity& e);
	void draw(const RenderInfo& drawData);
	void enable2D();
	void enable3D();
    Shader& getShader() {return *shader;}
};

