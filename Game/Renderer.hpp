//
//  Renderer.hpp
//  Game
//
//  Created by Jakub Hladik on 1/1/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <glad/glad.h>
#include "Entity.hpp"
#include "StaticShader.hpp"
#include "utils.hpp"
#pragma clang diagnostic ignored "-Wdocumentation"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#pragma clang diagnostic pop

class Renderer
{
private:
    glm::mat4 projectionMatrix;
public:
    Renderer(StaticShader &shader);
    void prepare();
    void render(Entity &entity, StaticShader &shader);
    void createProjectionMatrix();
};

#endif /* Renderer_hpp */
