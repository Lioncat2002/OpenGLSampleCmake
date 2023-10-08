//
// Created by gamed on 08-10-2023.
//

#pragma once

#include "RawModel.h"
#include "glad/glad.h"

namespace starlight{

        class Renderer {
        public:
            void prepare();
            void render(RawModel model);
        };

} // starlight
