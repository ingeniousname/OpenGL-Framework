#pragma once
#include "engine v0.01/Shader/Shader.h"
#include "engine v0.01/Texture/Texture.h"


class SpriteRenderer
{
	unsigned int VAO, VBO;
	Shader textureShader, colorShader;
public:
	SpriteRenderer(glm::mat4 projection);
	~SpriteRenderer();
	void draw(glm::vec2 position, glm::vec2 scale, glm::vec3 color, float rotation = 0.0f);
	void draw(Texture &texture, glm::vec2 position, glm::vec2 scale, glm::vec3 color, int textureCount, int currTexture, float rotation = 0.0f);
	void draw(Texture* texture, glm::mat4x4 model, glm::vec3 color, int textureCount, int currTexture);
};

