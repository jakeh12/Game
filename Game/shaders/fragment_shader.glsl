#version 400 core

in vec2 passTextureCoordinates;
in vec3 surfaceNormal;
in vec3 toLight;

out vec4 fragColor;

uniform sampler2D textureSampler;
uniform vec3 lightColor;

void main()
{
    vec3 unitSurfaceNormal = normalize(surfaceNormal);
    vec3 unitToLight = normalize(toLight);
    float nDotL = dot(unitSurfaceNormal, unitToLight);
    float brightness = max(nDotL, 0.0);
    vec3 diffuse = brightness * lightColor;
    
    fragColor = vec4(diffuse, 1.0) * texture(textureSampler, passTextureCoordinates);
}
