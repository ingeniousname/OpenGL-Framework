#pragma once
#include "GL/glew.h"
#include <string>
#include <iostream>

class Texture
{
	unsigned int textureBuffer;
	int width, height;
public:
	Texture(std::string filename);
	~Texture();
	void bind() const;
};

