#pragma once
#include "ResourceManager.h"
#include "Shader/Shader.h"
#include "Texture/Texture.h"


class ResourceHolder
{
private:
	ResourceHolder();
public:
	static ResourceHolder& get();
	ResourceManager<Texture> Textures;
};

