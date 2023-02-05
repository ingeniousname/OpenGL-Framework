#version 330 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texCoords;


uniform mat4 projection;
uniform mat4 model;

out vec2 textureXY;

void main()
{
	gl_Position = projection * model * vec4(position, 0.0f, 1.0f);
	textureXY = texCoords;
}
