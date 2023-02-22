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
	ResourceManager<Texture> Textures;
	ResourceManager<Shader> Shaders;
	ResourceManager<RenderInfo> Models;
};

