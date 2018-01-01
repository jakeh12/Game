//
//  RawModel.cpp
//  Game
//
//  Created by Jakub Hladik on 1/1/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "RawModel.hpp"

RawModel::RawModel(GLuint vaoId, GLuint vertexCount)
{
    this->vaoId = vaoId;
    this->vertexCount = vertexCount;
}

GLuint RawModel::getVaoId()
{
    return vaoId;
}

GLuint RawModel::getVertexCount()
{
    return vertexCount;
}
