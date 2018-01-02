//
//  Renderer.cpp
//  Game
//
//  Created by Jakub Hladik on 1/1/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "Renderer.hpp"

Renderer::Renderer(StaticShader &shader)
{
    createProjectionMatrix();
    shader.start();
    shader.loadProjectionMatrix(projectionMatrix);
    shader.stop();
}

void Renderer::prepare()
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Renderer::render(Entity &entity, StaticShader &shader)
{
    TexturedModel model = entity.getModel();
    RawModel rawModel(model.getRawModel());
    glBindVertexArray(rawModel.getVaoId());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    
    glm::mat4 transformationMatrix = createTransformationMatrix(entity.getPosition(), entity.getRotation(), entity.getScale());
    shader.loadTransformationMatrix(transformationMatrix);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, model.getModelTexture().getId());
    glDrawElements(GL_TRIANGLES, rawModel.getVertexCount(), GL_UNSIGNED_INT, (GLvoid *)(0));
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}

void Renderer::createProjectionMatrix()
{
    projectionMatrix = glm::perspective(glm::radians(60.0f), 4.0f/3.0f, 0.1f, 1000.0f);
}
