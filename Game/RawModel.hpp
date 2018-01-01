//
//  RawModel.hpp
//  Game
//
//  Created by Jakub Hladik on 1/1/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef RawModel_hpp
#define RawModel_hpp

#include <glad/glad.h>

class RawModel
{
    GLuint vaoId;
    GLuint vertexCount;
public:
    RawModel(GLuint vaoId, GLuint vertexCount);
    GLuint getVaoId();
    GLuint getVertexCount();
};
#endif /* RawModel_hpp */
