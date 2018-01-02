//
//  ShaderProgram.cpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram(std::string vertexPath, std::string fragmentPath)
{
    vertexShaderId = loadShader(vertexPath, GL_VERTEX_SHADER);
    fragmentShaderId = loadShader(fragmentPath, GL_FRAGMENT_SHADER);
    programId = glCreateProgram();
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);
    glValidateProgram(programId);
}

void ShaderProgram::start()
{
    glUseProgram(programId);
}

void ShaderProgram::stop()
{
    glUseProgram(0);
}

GLuint ShaderProgram::loadShader(std::string path, GLenum type)
{
    std::ifstream inputFileStream;
    inputFileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    std::string fileContentString;
    
    try
    {
        inputFileStream.open(path);
        std::stringstream stringStream;
        stringStream << inputFileStream.rdbuf();
        fileContentString = stringStream.str();
    }
    catch (std::ifstream::failure e)
    {
        throw std::runtime_error("Failed to read shader source file.");
    }
    
    const char* fileContentCharArray = fileContentString.c_str();
    
    GLuint shaderId = glCreateShader(type);
    glShaderSource(shaderId, 1, &fileContentCharArray, nullptr);
    glCompileShader(shaderId);
    
    GLint success;
    // get status of compilation
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint length;
        // get compilation log
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
        GLchar* info = new GLchar[length];
        glGetShaderInfoLog(shaderId, length, &length, info);
        std::string infoString(info);
        delete[] info;
        throw std::runtime_error("Failed to compile shader source file:\n" + infoString);
    }
    
    return shaderId;
}

ShaderProgram::~ShaderProgram()
{
    stop();
    glDetachShader(programId, vertexShaderId);
    glDetachShader(programId, fragmentShaderId);
    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
    glDeleteProgram(programId);
}

GLuint ShaderProgram::getUniformLocation(std::string uniformName)
{
    return glGetUniformLocation(programId, uniformName.c_str());
}

void ShaderProgram::loadBoolean(GLuint location, bool value)
{
    GLboolean toLoad = GL_FALSE;
    if (value)
        toLoad = GL_TRUE;
    glUniform1ui(location, toLoad);
}

void ShaderProgram::loadFloat(GLuint location, GLfloat value)
{
    glUniform1f(location, value);
}

void ShaderProgram::loadVector(GLuint location, glm::vec3 vector)
{
    glUniform3f(location, vector.x, vector.y, vector.z);
}

void ShaderProgram::loadMatrix(GLuint location, glm::mat4 matrix)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

