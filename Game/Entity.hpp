//
//  Entity.hpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "TexturedModel.hpp"
#pragma clang diagnostic ignored "-Wdocumentation"
#include <glm/glm.hpp>
#pragma clang diagnostic pop

class Entity
{
private:
    TexturedModel model;
    glm::vec3 position;
    glm::vec3 rotation;
    GLfloat scale;
public:
    Entity(TexturedModel texturedModel, glm::vec3 position, glm::vec3 rotation, GLfloat scale);
    void translate(glm::vec3 deltaPosition);
    void rotate(glm::vec3 deltaRotation);
    TexturedModel getModel();
    glm::vec3 getPosition();
    glm::vec3 getRotation();
    GLfloat getScale();
};

#endif /* Entity_hpp */
