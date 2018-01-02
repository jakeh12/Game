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
}

void StaticShader::loadTransformationMatrix(glm::mat4 matrix)
{
    loadMatrix(transformationMatrixLocation, matrix);
}

void StaticShader::loadProjectionMatrix(glm::mat4 matrix)
{
    loadMatrix(projectionMatrixLocation, matrix);
}
