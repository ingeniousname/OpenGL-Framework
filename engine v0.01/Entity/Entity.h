#pragma once
#include "RenderComponent.h"
#include "TransformComponent.h"
#include <queue>

class Entity
{
	RenderComponent render;
	TransformComponent transform;
public:
	Entity(glm::vec2 pos, glm::vec2 scale, float rotation, Texture* texture, int textureCount, int currTexture);
	void update();

};

