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
        0, 1, 3, // top triangle
        3, 1, 2  // bottom triangle
    };
    
    std::vector<GLfloat> textureCoordinates = {
        0.0f, 0.0f, // v0
        0.0f, 1.0f, // v1
        1.0f, 1.0f, // v2
        1.0f, 0.0f  // v3
    };
    
    RawModel model = loader.loadToVao(vertices, textureCoordinates, indices);
    ModelTexture texture(loader.loadTexture("textures/awesomeface.png"));
    TexturedModel texturedModel(model, texture);
    
    while(!window.isCloseRequested())
    {
        renderer.prepare();
        shaderProgram.start();
        renderer.render(texturedModel);
        shaderProgram.stop();
        window.update();
    }
    
    return 0;
}
