//
// Created by gamed on 08-10-2023.
//

#pragma once

#include "Engine/models/RawModel.h"
#include "Engine/models/TexturedModel.h"
#include "Engine/entities/Entity.h"
#include "Engine/shaders/StaticShader.h"
#include "detail/type_mat4x4.hpp"


namespace starlight{

        class Renderer {
        private:
            float FOV;
            float NEAR_PLANE;
            float FAR_PLANE;
            glm::mat4 projectionMatrix;
        public:
            Renderer(StaticShader *shader);
            void prepare();
            void render(Entity entity,StaticShader *shader);
        private:
            void createProjectionMatrix();
        };

} // starlight
