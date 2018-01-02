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
#pragma clang diagnostic ignored "-Wdocumentation"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#pragma clang diagnostic pop

class ShaderProgram
{
private:
    GLuint programId;
    GLuint vertexShaderId;
    GLuint fragmentShaderId;
public:
    ShaderProgram(std::string vertexPath, std::string fragmentPath);
    void prepare();
    void start();
    void stop();
    static GLuint loadShader(std::string path, GLenum type);
    ~ShaderProgram();
    GLuint getUniformLocation(std::string uniformName);
    void loadBoolean(GLuint location, bool value);
    void loadFloat(GLuint location, GLfloat value);
    void loadVector(GLuint location, glm::vec3 vector);
    void loadMatrix(GLuint location, glm::mat4 matrix);
};

#endif /* ShaderProgram_hpp */
