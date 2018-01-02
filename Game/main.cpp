//
//  main.cpp
//  Game
//
//  Created by Jakub Hladik on 1/1/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "Window.hpp"
#include "Loader.hpp"
#include "Renderer.hpp"
#include "ShaderProgram.hpp"

int main(int argc, const char * argv[]) {
    
    Window window("Test");
    Loader loader;
    Renderer renderer;
    
    ShaderProgram shaderProgram("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
    
    std::vector<GLfloat> vertices = {
        -0.5f,  0.5f,  0.0f, // v0
        -0.5f, -0.5f,  0.0f, // v1
         0.5f, -0.5f,  0.0f, // v2
         0.5f,  0.5f,  0.0f, // v3
    };
    
    std::vector<GLuint> indices = {
        0, 1, 3, // top
        3, 1, 2  // bottom
    };
    
    RawModel model = loader.loadToVao(vertices, indices);
    
    while(!window.isCloseRequested())
    {
        renderer.prepare();
        shaderProgram.start();
        renderer.render(model);
        shaderProgram.stop();
        window.update();
    }
    
    return 0;
}
