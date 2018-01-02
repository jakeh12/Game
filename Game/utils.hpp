//
//  utils.hpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <glad/glad.h>
#pragma clang diagnostic ignored "-Wdocumentation"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#pragma clang diagnostic pop
#include "Camera.hpp"

glm::mat4 createTransformationMatrix(glm::vec3 position, glm::vec3 rotation, GLfloat scale);
glm::mat4 createViewMatrix(Camera &camera);

#endif /* utils_hpp */
