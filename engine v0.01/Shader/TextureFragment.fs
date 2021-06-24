#version 330 core

uniform vec3 color;
out vec4 out_color;

in vec2 textureXY;

uniform sampler2D textureSampler;

void main()
{
	out_color = vec4(color, 1.0f) * texture(textureSampler, textureXY);
}