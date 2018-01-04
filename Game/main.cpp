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
#include "ObjLoader.hpp"

int main(int argc, const char * argv[]) {
    Window window("Game");
    Loader loader;
    StaticShader shader;
    Renderer renderer(shader);
    
    ObjLoader objLoader;
    RawModel model = objLoader.loadObjModel("models/dragon/dragon.obj", loader);
    TexturedModel staticModel(model, ModelTexture(loader.loadTexture("models/dragon/dragon.png")));
    Entity entity(staticModel, glm::vec3(0.0f, -4.0f, -15.0f), glm::vec3(glm::radians(0.0f), glm::radians(180.0f), glm::radians(0.0f)), 1.0f);
    Light light(glm::vec3(0.0f, 0.0f, -10.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    Camera camera(window);
    
    while(!window.isCloseRequested())
    {
        entity.translate(glm::vec3(0.0f, 0.0f, -0.01f));
        entity.rotate(glm::vec3(0.0f, -0.01f, 0.0f));
        
        camera.move();
        renderer.prepare();
        shader.start();
        shader.loadLight(light);
        shader.loadViewMatrix(camera);
        renderer.render(entity, shader);
        shader.stop();
        
        window.update();
    }
    
    return 0;
}
