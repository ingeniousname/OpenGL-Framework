#include "TransformComponent.h"

void TransformComponent::updateMatrix()
{
	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(position, 0.0f));

	if (rotation != 0)
	{
		model = glm::translate(model, glm::vec3(0.5f * scale.x, 0.5f * scale.y, 0.0f));
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::translate(model, glm::vec3(-0.5f * scale.x, -0.5f * scale.y, 0.0f));
	}

	model = glm::scale(model, glm::vec3(scale, 1.0f));
}

TransformComponent::TransformComponent(glm::vec2 _position = glm::vec2(0.0f, 0.0f), glm::vec2 _scale = glm::vec2(1.0f, 1.0f), float _rotation = 0.0f) : position(_position), scale(_scale), rotation(_rotation)
{
	updateMatrix();
}

void TransformComponent::setPosition(glm::vec2 _new_position)
{
	this->position = _new_position;
}

void TransformComponent::addPosition(glm::vec2 _add_position)
{
	this->position += _add_position;
}

void TransformComponent::setRotation(float _new_rotation)
{
	this->rotation = _new_rotation;
}

void TransformComponent::addRotation(float _add_rotation)
{
	this->rotation = _add_rotation;
}

void TransformComponent::setScale(glm::vec2 _new_scale)
{
	this->scale = _new_scale;
}

glm::mat4x4 TransformComponent::getMatrix()
{
	return this->model;
}
