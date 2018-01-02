//
//  utils.cpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "utils.hpp"

glm::mat4 createTransformationMatrix(glm::vec3 position, glm::vec3 rotation, GLfloat scale)
{
    glm::mat4 matrix;
    matrix = glm::translate(matrix, position);
    matrix = glm::rotate(matrix, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    matrix = glm::rotate(matrix, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    matrix = glm::rotate(matrix, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
    matrix = glm::scale(matrix, glm::vec3(scale));
    return matrix;
}
