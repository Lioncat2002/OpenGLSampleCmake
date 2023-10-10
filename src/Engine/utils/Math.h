//
// Created by gamed on 09-10-2023.
//

#pragma once

#include "vec3.hpp"
#include "detail/type_mat.hpp"
#include "Engine/entities/Camera.h"

namespace starlight {

    class Math {
    public:
        static glm::mat4 createTransformationMatrix(glm::vec3 translation, glm::vec3 rotation, float scale);
        static glm::mat4 createViewMatrix(Camera camera);
    };

} // starlight
