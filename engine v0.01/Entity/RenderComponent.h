#pragma once
#include"engine v0.01/Texture/Texture.h"

class RenderComponent
{
	Texture* texture;
	int texture_element_count;
	int current_texture;
public:
	RenderComponent(Texture* _texture, int textureCount, int curr_texture);
	void setCurrentTexture(int _new_texture);
	Texture* getTexture();
	int getTextureCount();
	int getCurrentTexturePointer();
};

