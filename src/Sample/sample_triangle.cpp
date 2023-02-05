#include "sample_triangle.h"
#include "GL/glew.h"


RenderInfo get_sample_triangle_data()
{
    float data[] = {-0.5f, -0.5f,
                    0.5f, -0.5f,
                    0.0f, 0.5f};

    unsigned indicies[] = {0, 1, 2,
                           2, 3, 0};
    RenderInfo result;
    glGenVertexArrays(1, &result.VAO);
    unsigned VBO;
    glGenBuffers(1, &VBO);
    glBindVertexArray(result.VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (const void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenBuffers(1, &result.IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, result.IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned) * 6, indicies, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
    result.numIndicies = 6;

    glDeleteBuffers(1, &VBO);
    return result;
}