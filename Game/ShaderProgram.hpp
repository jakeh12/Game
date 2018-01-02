//
//  ShaderProgram.hpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef ShaderProgram_hpp
#define ShaderProgram_hpp

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <glad/glad.h>

class ShaderProgram
{
    GLuint programId;
    GLuint vertexShaderId;
    GLuint fragmentShaderId;
public:
    ShaderProgram(std::string vertexPath, std::string fragmentPath);
    void start();
    void stop();
    static GLuint loadShader(std::string path, GLenum type);
    ~ShaderProgram();
};

#endif /* ShaderProgram_hpp */
