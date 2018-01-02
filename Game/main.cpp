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
#include "StaticShader.hpp"

#include "TestCube.h"

int main(int argc, const char * argv[]) {
    Window window("Game");
    Loader loader;
    StaticShader shader;
    Renderer renderer(shader);
    
    RawModel model = loader.loadToVao(vertices, textureCoordinates, indices);
    TexturedModel staticModel(model, ModelTexture(loader.loadTexture("textures/awesomeface.png")));
    Entity entity(staticModel, glm::vec3(1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);
    
    Camera camera(window);
    
    while(!window.isCloseRequested())
    {
        entity.translate(glm::vec3(0.0f, 0.0f, -0.01f));
        entity.rotate(glm::vec3(0.0f, 0.0f, 0.02f));
        
        camera.move();
        renderer.prepare();
        shader.start();
        shader.loadViewMatrix(camera);
        renderer.render(entity, shader);
        shader.stop();
        
        window.update();
    }
    
    return 0;
}
