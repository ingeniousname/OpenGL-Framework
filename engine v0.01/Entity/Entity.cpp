#include "Entity.h"

Entity::Entity(glm::vec2 pos, glm::vec2 scale, float rotation, Texture* texture, int textureCount, int currTexture)
	: render(texture, textureCount, currTexture), transform(pos, scale, rotation)
{
}


void Entity::update()
{
}
