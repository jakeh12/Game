//
//  StaticShader.hpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef StaticShader_hpp
#define StaticShader_hpp

#include "ShaderProgram.hpp"
#pragma clang diagnostic ignored "-Wdocumentation"
#include <glm/glm.hpp>
#pragma clang diagnostic pop
#include "Camera.hpp"
#include "utils.hpp"

class StaticShader : public ShaderProgram
{
private:
    GLuint transformationMatrixLocation;
    GLuint projectionMatrixLocation;
    GLuint viewMatrixLocation;
public:
    StaticShader();
    void loadTransformationMatrix(glm::mat4 matrix);
    void loadProjectionMatrix(glm::mat4 matrix);
    void loadViewMatrix(Camera &camera);
};

#endif /* StaticShader_hpp */
