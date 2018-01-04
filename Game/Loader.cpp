//
//  Loader.cpp
//  Game
//
//  Created by Jakub Hladik on 1/1/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "Loader.hpp"

GLuint Loader::createVao()
{
    GLuint vaoId;
    glGenVertexArrays(1, &vaoId);
    vaos.push_back(vaoId);
    glBindVertexArray(vaoId);
    return vaoId;
}

void Loader::storeDataInAttributeList(int attributeNumber, int coordinateSize, const std::vector<GLfloat>& data)
{
    GLuint vboId;
    glGenBuffers(1, &vboId);
    vbos.push_back(vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), &data[0], GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, coordinateSize, GL_FLOAT, GL_FALSE, 0, (GLvoid*)(0));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::unbindVao()
{
    glBindVertexArray(0);
}

void Loader::bindIndicesBuffer(const std::vector<GLuint>& indices)
{
    GLuint vboId;
    glGenBuffers(1, &vboId);
    vbos.push_back(vboId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
}

RawModel Loader::loadToVao(const std::vector<GLfloat>& positions, const std::vector<GLfloat>& textureCoordinates,  const std::vector<GLfloat>& normals, const std::vector<GLuint>& indices)
{
    GLuint vaoId = createVao();
    bindIndicesBuffer(indices);
    storeDataInAttributeList(0, 3, positions);
    storeDataInAttributeList(1, 2, textureCoordinates);
    storeDataInAttributeList(2, 3, normals);
    unbindVao();
    RawModel model(vaoId, (GLuint)(indices.size()));
    return model;
}

GLuint Loader::loadTexture(std::string path)
{
    // generate texture id
    GLuint textureId;
    glGenTextures(1, &textureId);
    textures.push_back(textureId);
    
    // load png data
    int width, height, components;
    GLubyte *data = stbi_load(path.c_str(), &width, &height, &components, 0);
    if (data)
    {
        GLenum format;
        if (components == 1)
            format = GL_RED;
        else if (components == 3)
            format = GL_RGB;
        else if (components == 4)
            format = GL_RGBA;
        else
            throw std::runtime_error("Failed to load texture (unknown format) from " + path);
        
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        stbi_image_free(data);
    }
    else
    {
        throw std::runtime_error("Failed to load texture from " + path);
    }
    return textureId;
}

Loader::~Loader()
{
    for(auto vaoId : vaos)
        glDeleteVertexArrays(1, &vaoId);
    
    for(auto vboId : vbos)
        glDeleteBuffers(1, &vboId);
    
    for(auto textureId : textures)
        glDeleteTextures(1, &textureId);
}
