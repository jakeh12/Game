//
//  ModelTexture.hpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef ModelTexture_hpp
#define ModelTexture_hpp

#include <glad/glad.h>

class ModelTexture
{
    GLuint textureId;
public:
    ModelTexture(GLuint textureId);
    GLuint getId();
};

#endif /* ModelTexture_hpp */
