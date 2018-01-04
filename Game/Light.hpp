//
//  Light.hpp
//  Game
//
//  Created by Jakub Hladik on 1/4/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef Light_hpp
#define Light_hpp

#pragma clang diagnostic ignored "-Wdocumentation"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#pragma clang diagnostic pop

class Light
{
private:
    glm::vec3 position;
    glm::vec3 color;
public:
    Light(glm::vec3 position_, glm::vec3 color_);
    glm::vec3 getPosition();
    void setPosition(glm::vec3 position_);
    glm::vec3 getColor();
    void setColor(glm::vec3 color_);
};

#endif /* Light_hpp */
