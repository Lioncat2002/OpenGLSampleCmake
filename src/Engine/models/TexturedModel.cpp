//
// Created by gamed on 09-10-2023.
//

#include "TexturedModel.h"

namespace starlight {
    TexturedModel::TexturedModel(RawModel model, ModelTexture texture){
        this->rawModel=model;
        this->texture=texture;
    }

    RawModel TexturedModel::getRawModel() {
        return rawModel;
    }

    ModelTexture TexturedModel::getTexture() {
        return texture;
    }


} // starlight