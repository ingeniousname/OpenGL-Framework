#pragma once

#include "engine v0.01/Renderer/Renderer.h"
#include "engine v0.01/ResourceHolder.h"
#include "engine v0.01/Camera/Camera.h"


class App
{
	Renderer* renderer;
	GLFWwindow* window;
	Camera camera;
	
	bool closed = false;
public:
	App(int width, int height);
	~App();
	void clear(float r, float g, float b, float a);
	void update();
	void draw();
	bool isClosed() { return closed; };
};

