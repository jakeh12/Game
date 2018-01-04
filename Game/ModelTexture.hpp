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
    GLfloat shineDamper = 1.0f;
    GLfloat reflectivity = 0.0f;
public:
    ModelTexture(GLuint textureId);
    GLuint getId();
    GLfloat getShineDamper();
    void setShineDamper(GLfloat shineDamper_);
    GLfloat getReflectivity();
    void setReflectivity(GLfloat reflectivity_);
};

#endif /* ModelTexture_hpp */
