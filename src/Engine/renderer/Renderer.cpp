//
// Created by gamed on 08-10-2023.
//

#include <iostream>
#include "Renderer.h"
#include "glad.h"
#include "Engine/entities/Entity.h"
#include "detail/type_mat4x4.hpp"
#include "Engine/utils/Math.h"
#include "trigonometric.hpp"
#include "gtc/matrix_transform.hpp"

namespace starlight {
    const int WINDOW_WIDTH=1024;
    const int WINDOW_HEIGHT=768;

    Renderer::Renderer(StaticShader *shader) {
        this->FOV=70.0f;
        this->NEAR_PLANE=0.1f;
        this->FAR_PLANE=1000.0f;
        //std::cout<<"pussen"<<projectionMatrix[2][3];
        createProjectionMatrix();
        shader->start();
        shader->loadProjectionMatrix(projectionMatrix);
        shader->stop();
    }

    void Renderer::prepare() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::render(Entity entity,StaticShader *shader) {
        TexturedModel texturedModel=entity.getModel();
        RawModel model=texturedModel.getRawModel();

        glBindVertexArray(model.getVaoId());
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glm::mat4 transformationMatrix=Math::createTransformationMatrix(entity.getPosition(),entity.getRotation(),entity.getScale());
        shader->loadTransformationMatrix(transformationMatrix);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,texturedModel.getTexture().getId());
        glDrawElements(GL_TRIANGLES,model.getVertexCount(),GL_UNSIGNED_INT, nullptr);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(0);
        glBindVertexArray(0);
    }

    void Renderer::createProjectionMatrix() {
        float aspectRatio=1024.0f/768.0f;
        projectionMatrix=glm::perspective(glm::radians(FOV),aspectRatio,NEAR_PLANE,FAR_PLANE);
    }


} // starlight