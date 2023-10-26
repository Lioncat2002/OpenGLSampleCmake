//
// Created by gamed on 09-10-2023.
//

#include <iostream>
#include "Math.h"
#include "detail/type_mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
namespace starlight {
    glm::mat4 Math::createTransformationMatrix(glm::vec3 translation, glm::vec3 rotation, float scale) {
        glm::mat4 matrix = glm::mat4(1.0f); // Initialize as identity matrix
        matrix = glm::translate(matrix, translation);

        matrix = glm::rotate(matrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // Rotation around the X-axis
        matrix = glm::rotate(matrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotation around the Y-axis
        matrix = glm::rotate(matrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // Rotation around the Z-axis

        matrix = glm::scale(matrix, glm::vec3(scale));
        return matrix;
    }

    glm::mat4 Math::createViewMatrix(Camera camera) {
        //glm::mat4 viewMatrix=glm::lookAt(camera.getPosition(),camera.getPosition()+glm::vec3{0.0f,0.0f,-1.0f},{0.0f,1.0f,0.0f});
        glm::mat4  viewMatrix=glm::mat4(1.0f);
        viewMatrix=glm::rotate(viewMatrix,glm::radians(camera.getPitch()),glm::vec3(1,0,0));
        viewMatrix=glm::rotate(viewMatrix,glm::radians(camera.getYaw()),glm::vec3(0,1,0));
        glm::vec3 cameraPos=camera.getPosition();
        glm::vec3 negativeCameraPos=-cameraPos;
        viewMatrix=glm::translate(viewMatrix,negativeCameraPos);
        return viewMatrix;
    }
} // starlight