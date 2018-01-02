//
//  Entity.cpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "Entity.hpp"

Entity::Entity(TexturedModel texturedModel, glm::vec3 position, glm::vec3 rotation, GLfloat scale) : model(texturedModel)
{
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
}

void Entity::translate(glm::vec3 deltaPosition)
{
    position = position + deltaPosition;
}

void Entity::rotate(glm::vec3 deltaRotation)
{
    rotation = rotation + deltaRotation;
}

TexturedModel Entity::getModel()
{
    return model;
}

glm::vec3 Entity::getPosition()
{
    return position;
}

glm::vec3 Entity::getRotation()
{
    return rotation;
}

GLfloat Entity::getScale()
{
    return scale;
}

