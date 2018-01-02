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

void Loader::storeDataInAttributeList(int attributeNumber, const std::vector<GLfloat>& data)
{
    GLuint vboId;
    glGenBuffers(1, &vboId);
    vbos.push_back(vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), &data[0], GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)(0));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::unbindVao()
{
    glBindVertexArray(0);
}

void Loader::bindIndicesBuffer(const std::vector<GLuint>& indices)
{
    GLuint vboId;
    glGenBuffers(1, &vboId);
    vbos.push_back(vboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
}

RawModel Loader::loadToVao(const std::vector<GLfloat>& positions, const std::vector<GLuint>& indices)
{
    GLuint vaoId = createVao();
    bindIndicesBuffer(indices);
    storeDataInAttributeList(0, positions);
    unbindVao();
    RawModel model(vaoId, (GLuint)(indices.size()));
    return model;
}

Loader::~Loader()
{
    for(auto vaoId : vaos)
        glDeleteVertexArrays(1, &vaoId);
    
    for(auto vboId : vbos)
        glDeleteBuffers(1, &vboId);
}
