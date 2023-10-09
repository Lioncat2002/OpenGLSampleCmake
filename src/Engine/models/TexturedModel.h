//
// Created by gamed on 09-10-2023.
//

#pragma once

#include "RawModel.h"
#include "Engine/textures/ModelTexture.h"

namespace starlight {

    class TexturedModel {
    private:
        RawModel rawModel;
        ModelTexture texture;

    public:
        TexturedModel(RawModel model, ModelTexture texture);
        RawModel getRawModel();
        ModelTexture getTexture();
    };

} // starlight
