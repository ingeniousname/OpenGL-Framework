#pragma once
#include "Vendor/glm/glm/glm.hpp"
#include "Vendor/glm/glm/gtx/transform.hpp"
#include <GLFW/glfw3.h>

class Camera
{
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::vec3 cameraRight;
	glm::vec3 worldUp;

	static glm::mat4x4 projection;
	bool is2D;

public:
	Camera(int width, int height, bool is2D);
	void updateVectors(glm::vec3 direction);
	glm::mat4x4 getProjectionViewMatrix(glm::vec3 position = {0.f, 0.f, 0.f});
	glm::vec3 getCameraFrontVector() { return cameraFront; };
	glm::vec3 getCameraRightVector() { return cameraRight; };

};

