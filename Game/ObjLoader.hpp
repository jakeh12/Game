//
//  ObjLoader.hpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef ObjLoader_hpp
#define ObjLoader_hpp

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <glad/glad.h>
#include "RawModel.hpp"
#include "Loader.hpp"
#pragma clang diagnostic ignored "-Wdocumentation"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#pragma clang diagnostic pop

class VertexReferences
{
public:
    GLuint v;
    GLuint vt;
    GLuint vn;
    VertexReferences(GLuint v_, GLuint vt_, GLuint vn_);
};

class ObjLoader
{
public:
    static RawModel loadObjModel(std::string path, Loader &loader);
};

#endif /* ObjLoader_hpp */
