#include "RenderInfo.h"
#include "GL/glew.h"
#include <numeric>
#include <functional>

void RenderInfo::generate(std::vector<float> verticiesData, std::vector<unsigned int> indiciesData, std::vector<unsigned> structure)
{
    glGenVertexArrays(1, &this->VAO);
    unsigned VBO;
    glGenBuffers(1, &VBO);
    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticiesData.size(), verticiesData.data(), GL_STATIC_DRAW);
    unsigned vertexDataSize = std::accumulate(std::begin(structure), std::end(structure), 0, std::plus<>());
    unsigned vertexDataOffset = 0;
    for(int i = 0; i < structure.size(); i++)
    {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, structure[i], GL_FLOAT, GL_FALSE, vertexDataSize * sizeof(float), (const void*)vertexDataOffset);
        vertexDataOffset += structure[i];
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glGenBuffers(1, &this->IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned) * indiciesData.size(), indiciesData.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
    this->numIndicies = indiciesData.size();
}