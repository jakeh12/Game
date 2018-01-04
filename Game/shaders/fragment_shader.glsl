#version 400 core

in vec2 passTextureCoordinates;
in vec3 surfaceNormal;
in vec3 toLightVector;
in vec3 toCameraVector;

out vec4 fragColor;

uniform sampler2D textureSampler;
uniform vec3 lightColor;
uniform float shineDamper;
uniform float reflectivity;

void main()
{
    vec3 unitSurfaceNormal = normalize(surfaceNormal);
    vec3 unitToLightVector = normalize(toLightVector);
    
    float nDotL = dot(unitSurfaceNormal, unitToLightVector);
    float brightness = max(nDotL, 0.0);
    vec3 diffuse = brightness * lightColor;
    
    vec3 unitToCameraVector = normalize(toCameraVector);
    vec3 lightDirection = -unitToLightVector;
    vec3 reflectedLightDirection = reflect(lightDirection, unitSurfaceNormal);
    
    float specularFactor = dot(reflectedLightDirection, unitToCameraVector);
    specularFactor = max(specularFactor, 0.0);
    
    float dampedFactor = pow(specularFactor, shineDamper);
    vec3 finalSpecular = dampedFactor * reflectivity * lightColor;
    
    fragColor = vec4(diffuse, 1.0) * texture(textureSampler, passTextureCoordinates) + vec4(finalSpecular, 1.0);
}
