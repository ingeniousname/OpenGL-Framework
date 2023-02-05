#include "Camera.h"


glm::mat4x4 Camera::projection;

void Camera::updateVectors(glm::vec3 direction)
{
    cameraFront = glm::normalize(direction);
    cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
    cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));
}


Camera::Camera(int width, int height, bool is2D)
{
    cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    worldUp = cameraUp;
    cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));

    if (is2D)
        projection = glm::ortho(0.f, static_cast<float>(width), static_cast<float>(height), 0.f, -1.f, 1.f);
    else projection = glm::perspective(glm::radians(45.0f), static_cast<float>(width) / static_cast<float>(height), 0.01f, 200.0f);
}


glm::mat4x4 Camera::getProjectionViewMatrix(glm::vec3 position)
{
    if (is2D)
        return projection;
    else return projection * glm::lookAt(position, position + cameraFront, cameraUp);
}


