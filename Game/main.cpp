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
    
    std::vector<float> vertices = {
        // left bottom triangle
        -0.5f,  0.5f,  0.0f,
        -0.5f, -0.5f,  0.0f,
        0.5f, -0.5f,  0.0f,
        // right top triangle
        0.5f, -0.5f, 0.0f,
        0.5f,  0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
    };
    
    RawModel model = loader.loadToVao(vertices);
    
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
