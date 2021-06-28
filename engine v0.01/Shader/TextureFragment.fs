#version 330 core

out vec4 out_color;

in vec2 textureXY;
uniform sampler2D textureSampler;

uniform int currTexture;
uniform int textureCount;

void main()
{
	out_color = texture(textureSampler,  vec2(1.0f /float(textureCount) * textureXY.x + float(currTexture) / float(textureCount), textureXY.y));
}