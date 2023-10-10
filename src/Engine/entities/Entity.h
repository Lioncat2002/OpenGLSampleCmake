//
// Created by gamed on 10-10-2023.
//

#pragma once

#include "Engine/models/TexturedModel.h"
#include "detail/type_vec3.hpp"

namespace starlight {

    class Entity {
    private:
        TexturedModel model;
        glm::vec3 position{};
        glm::vec3 rotation{};
        float scale{};
    public:
        Entity(TexturedModel model,glm::vec3 position,glm::vec3 rotation,float scale);
        void increasePosition(glm::vec3 position);
        void increaseRotation(glm::vec3 rotation);
        //getters
        TexturedModel getModel();
        glm::vec3 getPosition();
        glm::vec3 getRotation();
        float getScale();
        //setters
        void setModel(TexturedModel model);
        void setPosition(glm::vec3 position);
        void setRotation(glm::vec3 rotation);
        void setScale(float scale);
    };

} // starlight
