#pragma once
#include "Renderer.h"


class SpriteRenderer : public Renderer
{
public:
	SpriteRenderer(Shader &shader);
	~SpriteRenderer();
	void draw(glm::vec2 position, glm::vec2 scale, glm::vec3 color, float rotation = 0.0f);
};

