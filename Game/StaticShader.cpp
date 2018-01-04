//
//  StaticShader.cpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "StaticShader.hpp"

StaticShader::StaticShader() : ShaderProgram("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl")
{
    transformationMatrixLocation = getUniformLocation("transformationMatrix");
    projectionMatrixLocation = getUniformLocation("projectionMatrix");
    viewMatrixLocation = getUniformLocation("viewMatrix");
    lightPositionLocation = getUniformLocation("lightPosition");
    lightColorLocation = getUniformLocation("lightColor");
    shineDamperLocation = getUniformLocation("shineDamper");
    reflectivityLocation = getUniformLocation("reflectivity");
}

void StaticShader::loadTransformationMatrix(glm::mat4 matrix)
{
    loadMatrix(transformationMatrixLocation, matrix);
}

void StaticShader::loadProjectionMatrix(glm::mat4 matrix)
{
    loadMatrix(projectionMatrixLocation, matrix);
}

void StaticShader::loadViewMatrix(Camera &camera)
{
    loadMatrix(viewMatrixLocation, createViewMatrix(camera));
}

void StaticShader::loadLight(Light &light)
{
    loadVector(lightPositionLocation, light.getPosition());
    loadVector(lightColorLocation, light.getColor());

}

void StaticShader::loadShineVariables(GLfloat shineDamper, GLfloat reflectivity)
{
    loadFloat(shineDamperLocation, shineDamper);
    loadFloat(reflectivityLocation, reflectivity);
}
