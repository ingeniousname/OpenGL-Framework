#include "OBJLoader.h"
#include "GL/glew.h"
#include <iostream>

RenderInfo createFromFile(const std::string& filepath)
{
    VertexData data = getVertexDataFromOBJ(filepath);
    return buildRenderInfoFromData(data);
}


VertexData getVertexDataFromOBJ(const std::string& filepath)
{
    VertexData data;
    std::ifstream filestream(filepath, std::ios::in);
    std::string firstWord;
    do
    {
        filestream.ignore(1000, '\n');
        filestream >> firstWord;
    } while (firstWord != "v");

    while (firstWord[0] == 'v')
    {
        float x, y, z;
        if (firstWord.size() == 1)
        {
            filestream >> x >> y >> z;
            data.verticies.insert(data.verticies.end(), { x, y, z });
        }
        else
        {
            if (firstWord[1] == 't')
            {
                filestream >> x >> y;
                data.textures.insert(data.textures.end(), { x, y });
            }
            else
            {
                filestream >> x >> y >> z;
                data.normals.insert(data.normals.end(), { x, y, z });
            }
        }


        filestream >> firstWord;
    }

    do
    {
        filestream.ignore(1000, '\n');
        filestream >> firstWord;
    } while (firstWord != "f");

    while (firstWord == "f" && !filestream.eof())
    {
        for (int i = 0; i < 4; i++)
        {
            std::string s;
            std::getline(filestream, s, '/');
            data.vertexBuildData.push_back(stoi(s));

            std::getline(filestream, s, '/');
            data.vertexBuildData.push_back(stoi(s));

            filestream >> s;
            data.vertexBuildData.push_back(stoi(s));
        }
        filestream >> firstWord;
    }

    filestream.close();
    return data;
}

RenderInfo buildRenderInfoFromData(const VertexData& data)
{
    std::vector<float> final_data;
    std::vector<unsigned> indicies;
    for(int i = 0; i < data.vertexBuildData.size(); i += 3)
    {
        final_data.push_back(data.verticies[3 * (data.vertexBuildData[i] - 1)]);
        final_data.push_back(data.verticies[3 * (data.vertexBuildData[i] - 1) + 1]);
        final_data.push_back(data.verticies[3 * (data.vertexBuildData[i] - 1) + 2]);

        final_data.push_back(data.textures[2 * (data.vertexBuildData[i + 1] - 1)]);
        final_data.push_back(data.textures[2 * (data.vertexBuildData[i + 1] - 1) + 1]);

        final_data.push_back(data.normals[3 * (data.vertexBuildData[i + 2] - 1)]);
        final_data.push_back(data.normals[3 * (data.vertexBuildData[i + 2] - 1) + 1]);
        final_data.push_back(data.normals[3 * (data.vertexBuildData[i + 2] - 1) + 2]);
    }

    for(int i = 0; i < 4; i++)
    {
        std::cout << final_data[7*i] << ", " <<  final_data[7*i + 1] << ", " << final_data[7*i + 2] << std::endl;
    }

    for(int i = 0; i < data.vertexBuildData.size() / 12; i++)
    {
        indicies.push_back(4 * i);
        indicies.push_back(4 * i + 1);
        indicies.push_back(4 * i + 2);
        indicies.push_back(4 * i + 2);
        indicies.push_back(4 * i + 3);
        indicies.push_back(4 * i);
    }


    RenderInfo result;
    result.generate(final_data, indicies, {{3, GL_FLOAT}, {2, GL_FLOAT}, {3, GL_FLOAT}});
    return result;
}