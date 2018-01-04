//
//  ObjLoader.cpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "ObjLoader.hpp"

VertexReferences::VertexReferences(GLuint v_, GLuint vt_, GLuint vn_)
{
    v = v_;
    vt = vt_;
    vn = vn_;
}

RawModel ObjLoader::loadObjModel(std::string path, Loader &loader)
{
    std::ifstream inputFileStream;
    
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> textureCoordinates;
    std::vector<glm::vec3> normals;
    std::vector<std::vector<VertexReferences>> vertexReferences;
    
    inputFileStream.open(path);
    
    if (!inputFileStream.is_open())
    {
        throw std::runtime_error("Failed to read obj file from " + path);
    }
    std::string line;
    while (std::getline(inputFileStream, line))
    {
        
        if (line.substr(0,2) == "v ")
        {
            // process vertex
            std::istringstream values(line.substr(2));
            glm::vec3 vertex;
            values >> vertex.x;
            values >> vertex.y;
            values >> vertex.z;
            vertices.push_back(vertex);
        }
        else if (line.substr(0,3) == "vt ")
        {
            // process texture coordinate
            std::istringstream values(line.substr(3));
            glm::vec2 texture;
            values >> texture.x;
            values >> texture.y;
            texture.y = 1.0f - texture.y; // from top-left
            textureCoordinates.push_back(texture);
        }
        else if (line.substr(0,3) == "vn ")
        {
            // process normal
            std::istringstream values(line.substr(3));
            glm::vec3 normal;
            values >> normal.x;
            values >> normal.y;
            normal.y = normal.y;
            values >> normal.z;
            normals.push_back(normal);
        }
        else if (line.substr(0,2) == "f ")
        {
            // reached face descriptions, break out
            break;
        }
    }
    
    do
    {
        if (line.substr(0,2) == "f ")
        {
            // process face e.g.: 1/4/5 4/5/2 2/4/2
            std::istringstream values(line.substr(2));
            std::string referenceString;
            std::vector<VertexReferences> triangleReference;
            
            // per each vertex e.g.: 1/4/5
            while(values >> referenceString)
            {
                // parse triangular references
                std::istringstream referenceValue(referenceString);
                std::string vString, vtString, vnString;
                std::getline(referenceValue, vString, '/' );
                std::getline(referenceValue, vtString, '/' );
                std::getline(referenceValue, vnString, '/' );
                GLuint v = stoi(vString) - 1;
                GLuint vt = stoi(vtString) - 1;
                GLuint vn = stoi(vnString) - 1;
                triangleReference.push_back(VertexReferences(v, vt, vn));
            }
            
            // did not get 3 indexes, error
            if (triangleReference.size() != 3)
                throw std::runtime_error("Failed to load obj file (error in face data) from " + path);
            
            // complete face, add it for processing
            vertexReferences.push_back(triangleReference);
        }
    } while(std::getline(inputFileStream, line));
    inputFileStream.close();
    
    // reading done, process vertices
    std::vector<GLfloat> vertexBuffer(vertices.size()*3);
    std::vector<GLfloat> textureCoordinateBuffer(vertices.size()*2);
    std::vector<GLfloat> normalBuffer(vertices.size()*3);
    std::vector<GLuint> indexBuffer;
    
    for (std::vector<VertexReferences> triangleReference : vertexReferences)
    {
        for (VertexReferences vertexReference : triangleReference)
        {
            GLuint currentVertexIndex = vertexReference.v;
            
            glm::vec3 vertex = vertices[vertexReference.v];
            vertexBuffer[currentVertexIndex * 3] = vertex.x;
            vertexBuffer[currentVertexIndex * 3 + 1] = vertex.y;
            vertexBuffer[currentVertexIndex * 3 + 2] = vertex.z;
            
            glm::vec2 textureCoordinate = textureCoordinates[vertexReference.vt];
            textureCoordinateBuffer[currentVertexIndex * 2] = textureCoordinate.x;
            textureCoordinateBuffer[currentVertexIndex * 2 + 1] = textureCoordinate.y;
            
            glm::vec3 normal = normals[vertexReference.vn];
            normalBuffer[currentVertexIndex * 3] = normal.x;
            normalBuffer[currentVertexIndex * 3 + 1] = normal.y;
            normalBuffer[currentVertexIndex * 3 + 2] = normal.z;
            
            indexBuffer.push_back(currentVertexIndex);
        }
    }
    
    return loader.loadToVao(vertexBuffer, textureCoordinateBuffer, normalBuffer, indexBuffer);
}

