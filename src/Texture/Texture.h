#pragma once
#include "GL/glew.h"
#include <string>
#include <iostream>

class Texture
{
	unsigned int textureBuffer;
	int width, height;
public:
	Texture();
	~Texture();
	void createFromFile(const std::string& filename);
	void bind() const;
};

