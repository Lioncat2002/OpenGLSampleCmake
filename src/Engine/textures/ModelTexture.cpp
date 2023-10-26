//
// Created by gamed on 09-10-2023.
//

#include "ModelTexture.h"

namespace starlight {
    ModelTexture::ModelTexture(unsigned int id) {
        this->textureId=id;
    }

    unsigned int ModelTexture::getId() {
        return textureId;
    }

    ModelTexture::ModelTexture() {

    }
} // starlight