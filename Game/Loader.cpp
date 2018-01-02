//
//  Loader.cpp
//  Game
//
//  Created by Jakub Hladik on 1/1/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "Loader.hpp"

GLuint Loader::createVao()
{
    GLuint vaoId;
    glGenVertexArrays(1, &vaoId);
    vaos.push_back(vaoId);
    glBindVertexArray(vaoId);
    return vaoId;
}

void Loader::storeDataInAttributeList(int attributeNumber, const std::vector<float>& data)
{
    GLuint vboId;
    glGenBuffers(1, &vboId);
    vbos.push_back(vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)(0));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::unbindVao()
{
    glBindVertexArray(0);
}

RawModel Loader::loadToVao(const std::vector<float>& positions)
{
    GLuint vaoId = createVao();
    storeDataInAttributeList(0, positions);
    unbindVao();
    RawModel model(vaoId, (GLuint)(positions.size()) / 3);
    return model;
}

Loader::~Loader()
{
    for(auto vaoId : vaos)
        glDeleteVertexArrays(1, &vaoId);
    
    for(auto vboId : vbos)
        glDeleteBuffers(1, &vboId);
}
