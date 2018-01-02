//
//  Renderer.cpp
//  Game
//
//  Created by Jakub Hladik on 1/1/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "Renderer.hpp"


void Renderer::prepare()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Renderer::render(TexturedModel &texturedModel)
{
    RawModel model(texturedModel.getRawModel());
    glBindVertexArray(model.getVaoId());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texturedModel.getModelTexture().getId());
    glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, (GLvoid *)(0));
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}
