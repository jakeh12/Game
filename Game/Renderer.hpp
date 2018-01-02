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

class Renderer
{
public:
    void prepare();
    void render(Entity &entity, StaticShader &shader);
};

#endif /* Renderer_hpp */
