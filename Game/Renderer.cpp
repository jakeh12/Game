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
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::render(RawModel &model)
{
    glBindVertexArray(model.getVaoId());
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}
