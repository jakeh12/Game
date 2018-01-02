//
//  TexturedModel.hpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#ifndef TexturedModel_hpp
#define TexturedModel_hpp

#include "RawModel.hpp"
#include "ModelTexture.hpp"

class TexturedModel
{
    RawModel rawModel;
    ModelTexture modelTexture;
public:
    TexturedModel(RawModel model, ModelTexture texture);
    RawModel getRawModel();
    ModelTexture getModelTexture();
};

#endif /* TexturedModel_hpp */
