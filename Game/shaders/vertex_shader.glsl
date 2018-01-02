#version 400 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 textureCoordinates;
out vec2 passTextureCoordinates;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;

void main()
{
    gl_Position = projectionMatrix * transformationMatrix * vec4(position, 1.0);
    passTextureCoordinates = textureCoordinates;
}
