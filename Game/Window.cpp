//
//  Window.cpp
//  Game
//
//  Created by Jakub Hladik on 1/1/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "Window.hpp"

Window::Window(std::string title, int width, int height, int framerate)
{
    // initialize glfw
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    
    // set up opengl core 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    // create a window
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (window == nullptr)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    
    // set current context to the window
    glfwMakeContextCurrent(window);
    
    // initialize glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Failed to initialize GLAD");
    }
    
    // set up frame rate cap
    msPerFrame = (int)((1.0f / framerate) * 1000);
}

void Window::update()
{
    // sync frame timing
    static float lastFrame = 0.0f;
    float currentFrame = glfwGetTime();
    float deltaTime = currentFrame - lastFrame;
    if (deltaTime < msPerFrame) {
        // TODO: figure out if deltaTime is seconds or ms.. do appropriate math here
        //std::this_thread::sleep_for(std::chrono::milliseconds(msPerFrame - (int)(deltaTime)));
    }
    lastFrame = currentFrame;

    // swap buffers
    glfwSwapBuffers(window);
    
    // poll events
    glfwPollEvents();
}

Window::~Window()
{
    glfwTerminate();
}

int Window::isCloseRequested()
{
    return glfwWindowShouldClose(window);
}

void Window::requestClose()
{
    glfwSetWindowShouldClose(window, true);
}
