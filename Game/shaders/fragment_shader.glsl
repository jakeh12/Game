#version 400 core

in vec2 passTextureCoordinates;
out vec4 fragColor;

uniform sampler2D textureSampler;

void main()
{
    fragColor = texture(textureSampler, passTextureCoordinates);
}
