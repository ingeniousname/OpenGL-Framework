#pragma once

#include "Renderer/Renderer.h"
#include "ResourceManager/ResourceHolder.h"
#include "Camera/Camera.h"


class App
{
	Renderer* renderer;
	GLFWwindow* window;
	Camera camera;
    RenderInfo sample;
	

public:
	App(int width, int height);
	~App();
	void clear(float r, float g, float b, float a);
	void update();
	void draw();
	[[nodiscard]] bool isClosed() const { return glfwWindowShouldClose(window); };
};

