//
//  Light.cpp
//  Game
//
//  Created by Jakub Hladik on 1/4/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "Light.hpp"

Light::Light(glm::vec3 position_, glm::vec3 color_)
{
    position = position_;
    color = color_;
}

glm::vec3 Light::getPosition()
{
    return position;
}

void Light::setPosition(glm::vec3 position_)
{
    position = position_;
}

glm::vec3 Light::getColor()
{
    return color;
}

void Light::setColor(glm::vec3 color_)
{
    color = color_;
}
