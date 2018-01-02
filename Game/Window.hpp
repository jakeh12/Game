//
//  Window.hpp
//  Game
//
//  Created by Jakub Hladik on 1/1/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <glad/glad.h>
#pragma clang diagnostic ignored "-Wdocumentation"
#include <GLFW/glfw3.h>
#pragma clang diagnostic pop
#include <iostream>
#include <chrono>
#include <thread>

class Window
{
    GLFWwindow* window;
    float sPerFrame;
public:
    Window(std::string title, int width = 800, int height = 600, int framerate = 60);
    void update();
    ~Window();
    int isCloseRequested();
    void requestClose();
};

#endif /* Window_hpp */
