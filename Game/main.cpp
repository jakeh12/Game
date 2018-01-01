//
//  main.cpp
//  Game
//
//  Created by Jakub Hladik on 1/1/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include <iostream>
#include "Window.hpp"

int main(int argc, const char * argv[]) {
    Window window("Test");
    while(!window.isCloseRequested())
    {
        window.update();
    }
    return 0;
}
