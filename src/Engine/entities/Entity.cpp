//
// Created by gamed on 10-10-2023.
//

#include "Entity.h"

namespace starlight {
    Entity::Entity(TexturedModel model, glm::vec3 position, glm::vec3 rotation, float scale) {
        this->model=model;
        this->position=position;
        this->rotation=rotation;
        this->scale=scale;
    }

    TexturedModel Entity::getModel() {
        return this->model;
    }

    glm::vec3 Entity::getPosition() {
        return this->position;
    }

    glm::vec3 Entity::getRotation() {
        return this->rotation;
    }

    float Entity::getScale() {
        return this->scale;
    }

    void Entity::setModel(TexturedModel model) {
        this->model=model;
    }

    void Entity::setPosition(glm::vec3 position) {
        this->position=position;
    }

    void Entity::setRotation(glm::vec3 rotation) {
        this->rotation=rotation;
    }

    void Entity::setScale(float scale) {
        this->scale=scale;
    }

    void Entity::increasePosition(glm::vec3 position) {
        this->position+=position;
    }

    void Entity::increaseRotation(glm::vec3 rotation) {
        this->rotation+=rotation;
    }

} // starlight