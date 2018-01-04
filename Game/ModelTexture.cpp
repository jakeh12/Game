//
//  ModelTexture.cpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "ModelTexture.hpp"

ModelTexture::ModelTexture(GLuint textureId)
{
    this->textureId = textureId;
}

GLuint ModelTexture::getId()
{
    return textureId;
}

GLfloat ModelTexture::getShineDamper()
{
    return shineDamper;
}
void ModelTexture::setShineDamper(GLfloat shineDamper_)
{
    shineDamper = shineDamper_;
}
GLfloat ModelTexture::getReflectivity()
{
    return reflectivity;
}
void ModelTexture::setReflectivity(GLfloat reflectivity_)
{
    reflectivity = reflectivity_;
}
