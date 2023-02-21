#include "Entity.h"

Entity::Entity()
{
    position = {0, 0, 0};
    rotation = {0, 0, 0};
    scale = {1, 1, 1};
}
void Entity::update(glm::vec3 posIncrement, glm::vec3 rotIncrement, glm::vec3 scaleIncrement)
{
    this->position = posIncrement;
    this->rotation = rotIncrement;
    this->scale = scaleIncrement;
}