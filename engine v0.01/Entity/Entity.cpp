#include "Entity.h"

Entity::Entity(glm::vec2 pos, glm::vec2 scale, float rotation, Texture* texture, int textureCount, int currTexture)
	: render(texture, textureCount, currTexture), transform(pos, scale, rotation)
{
}

void Entity::sendDrawRequest(std::queue<DrawRequest>& requestQueue)
{
	requestQueue.push(DrawRequest(this->transform.getMatrix(), this->render.getTexture(), this->render.getTextureCount(), this->render.getCurrentTexturePointer()));
}

void Entity::update()
{
}
