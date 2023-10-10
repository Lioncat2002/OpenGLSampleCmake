//
// Created by gamed on 10-10-2023.
//

#include "Camera.h"
#include "GLFW/glfw3.h"

namespace starlight {
    Camera::Camera() {

    }

    glm::vec3 Camera::getPosition() {
        return position;
    }

    float Camera::getPitch() {
        return pitch;
    }

    float Camera::getYaw() {
        return yaw;
    }

    float Camera::getRoll() {
        return roll;
    }

    void Camera::move(int key) {
        if(key==GLFW_KEY_W){
            position.z-=0.02f;
        }
        if(key==GLFW_KEY_S){
            position.x+=0.02f;
        }
        if(key==GLFW_KEY_A){
            position.x-=0.02f;
        }
        if(key==GLFW_KEY_D){
            position.z+=0.02f;
        }
    }
} // starlight