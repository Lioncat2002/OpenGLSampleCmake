//
// Created by gamed on 08-10-2023.
//

#pragma once

#include "Engine/models/RawModel.h"
#include "glad/glad.h"
#include "Engine/models/TexturedModel.h"

namespace starlight{

        class Renderer {
        public:
            void prepare();
            void render(TexturedModel texturedModel);
        };

} // starlight
