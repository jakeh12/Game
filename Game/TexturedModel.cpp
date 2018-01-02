//
//  TexturedModel.cpp
//  Game
//
//  Created by Jakub Hladik on 1/2/18.
//  Copyright © 2018 Jakub Hladik. All rights reserved.
//

#include "TexturedModel.hpp"

TexturedModel::TexturedModel(RawModel model, ModelTexture texture) : rawModel(model), modelTexture(texture)
{
}

RawModel TexturedModel::getRawModel()
{
    return rawModel;
}

ModelTexture TexturedModel::getModelTexture()
{
    return modelTexture;
}
