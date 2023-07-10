#pragma once

#include "src/Renderer/Renderer.h"
#include "src/ResourceManager/ResourceHolder.h"
#include "src/Camera/Camera.h"
#include "src/Entity/Entity.h"

#include <memory>

class GLFWwindowDeleter
{
public:
    void operator()(GLFWwindow* ptr)
    {
        glfwDestroyWindow(ptr);
    }
};

class App
{
	std::unique_ptr<Renderer> renderer;
    std::unique_ptr<GLFWwindow, GLFWwindowDeleter> window;
	Camera camera;
	Entity entity;

public:
	App(int width, int height);
	~App();
	void clear(float r, float g, float b, float a);
	void update();
	void draw();
	[[nodiscard]] bool isClosed() const { return glfwWindowShouldClose(window.get()); };
};

