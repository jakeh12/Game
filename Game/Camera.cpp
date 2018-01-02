//
//  Camera.cpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera(Window &win) : window(win)
{
    position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Camera::move()
{
    if (window.isKeyDown(GLFW_KEY_W))
    {
        position.z -= 0.2f;
    }
    if (window.isKeyDown(GLFW_KEY_D))
    {
        position.x += 0.2f;
    }
    if (window.isKeyDown(GLFW_KEY_A))
    {
        position.x -= 0.2f;
    }
}

glm::vec3 Camera::getPosition()
{
    return position;
}

glm::vec3 Camera::getRotation()
{
    return rotation;
}

float Camera::getPitch()
{
    return rotation.x;
}

float Camera::getRoll()
{
    return rotation.z;
}

float Camera::getYaw()
{
    return rotation.y;
}
