#version 430 core

in vec3 outColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D Texture;
uniform float currentTime;

void main()
{
color = texture(Texture, TexCoord);

//color = vec4(0.0f, 1.0f, 0.0f, 1.0f);
}