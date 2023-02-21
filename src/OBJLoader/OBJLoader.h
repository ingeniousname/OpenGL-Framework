#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <sstream>

#include "src/Renderer/RenderInfo.h"

struct VertexData
{
    std::vector<float> verticies;
    std::vector<float> textures;
    std::vector<float> normals;
    std::vector<unsigned int> vertexBuildData;
};


VertexData getVertexDataFromOBJ(const std::string& filepath);
RenderInfo buildRenderInfoFromData(const VertexData& data);
