//
//  Camera.hpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#pragma clang diagnostic ignored "-Wdocumentation"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#pragma clang diagnostic pop
#include "Window.hpp"

class Camera
{
private:
    Window window;
    glm::vec3 position;
    glm::vec3 rotation;
public:
    Camera(Window &win);
    void move();
    glm::vec3 getPosition();
    glm::vec3 getRotation();
    float getPitch();
    float getRoll();
    float getYaw();
};

#endif /* Camera_hpp */
