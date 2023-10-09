//
// Created by gamed on 09-10-2023.
//

#pragma once

namespace starlight {

    class ModelTexture {
    private:
        unsigned int textureId;
    public:
        ModelTexture();
        ModelTexture(unsigned int id);
        unsigned int getId();
    };

} // starlight
