#pragma once
#include "engine v0.01/Vendor/glm/glm/glm.hpp"
#include "engine v0.01/Vendor/glm/glm/gtx/transform.hpp"

class TransformComponent
{
	glm::vec2 position, scale;
	float rotation;
	glm::mat4x4 model;

public:
	TransformComponent(glm::vec2 _position, glm::vec2 _scale, float _rotation);
	void setPosition(glm::vec2 _new_position);
	void addPosition(glm::vec2 _add_position);
	void setRotation(float _new_rotation);
	void addRotation(float _add_rotation);
	void setScale(glm::vec2 _new_scale);
	void updateMatrix();
	glm::mat4x4 getMatrix();
};

