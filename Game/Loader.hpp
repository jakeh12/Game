//
//  Loader.hpp
//  Game
//
//  Created by Jakub Hladik on 1/1/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef Loader_hpp
#define Loader_hpp

#include "RawModel.hpp"
#include <vector>
#include <glad/glad.h>

class Loader
{
    std::vector<GLuint> vaos;
    std::vector<GLuint> vbos;
    
    GLuint createVao();
    void storeDataInAttributeList(int attributeNumber, const std::vector<float>& data);
    void unbindVao();
public:
    RawModel loadToVao(const std::vector<float>& positions);
    ~Loader();
};

#endif /* Loader_hpp */
