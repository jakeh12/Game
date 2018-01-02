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

void Renderer::render(RawModel &model)
{
    glBindVertexArray(model.getVaoId());
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, (GLvoid *)(0));
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}
