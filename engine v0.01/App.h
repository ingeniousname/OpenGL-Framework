#pragma once
#include "SpriteRenderer.h"
#include <iostream>



class App
{
	GLFWwindow* window;
	bool closed = false;
	Shader color_shader;
	glm::vec3 clear_color;
	double curr_time;
	int width, height;
public:
	App(int width, int height, const char* name);
	~App();
	bool isClosed() { return closed; };
	glm::vec3 clear(float r, float g, float b, float a);
	void update();
};

