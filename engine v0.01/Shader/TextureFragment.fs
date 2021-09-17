#version 330 core

out vec4 out_color;

in vec2 textureXY;
uniform sampler2D textureSampler;


void main()
{
	out_color = texture(textureSampler,  textureXY);
}