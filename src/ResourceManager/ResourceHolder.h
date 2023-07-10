#pragma once
#include "ResourceManager.h"
#include "src/Shader/Shader.h"
#include "src/Texture/Texture.h"
#include "src/Renderer/RenderInfo.h"

class ResourceHolder
{
private:
	ResourceHolder();
public:
	static ResourceHolder& get();

	UniqueResourceManager<Texture> Textures;
	UniqueResourceManager<RenderInfo> Models;

	SharedResourceManager<Shader> Shaders;
};

