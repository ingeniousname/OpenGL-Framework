#pragma once
#include "engine v0.01/Vendor/glm/glm/glm.hpp"
#include "engine v0.01/Texture/Texture.h"

class DrawRequest
{
public:
	glm::mat4x4 model;
	Texture* texture;
	int textureCount;
	int currTexture;
	DrawRequest(glm::mat4x4 _model, Texture* _texture, int _textureCount, int _currTexture);

};

