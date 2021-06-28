#include "RenderComponent.h"

RenderComponent::RenderComponent(Texture* _texture = nullptr, int textureCount = 1, int curr_texture = 0)
	: texture(_texture), texture_element_count(textureCount), current_texture(curr_texture)
{
}

void RenderComponent::setCurrentTexture(int _new_texture)
{
	current_texture = _new_texture;
}

Texture* RenderComponent::getTexture()
{
	return texture;
}

int RenderComponent::getTextureCount()
{
	return texture_element_count;
}

int RenderComponent::getCurrentTexturePointer()
{
	return current_texture;
}
