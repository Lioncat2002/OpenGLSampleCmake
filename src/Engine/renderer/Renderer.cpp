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


        //std::cout<<"pussen"<<projectionMatrix[2][3];
        /*shader->start();
        shader->loadProjectionMatrix(projectionMatrix);
        shader->stop();*/
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
        createProjectionMatrix();
        shader->loadProjectionMatrix(projectionMatrix);
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
        //projectionMatrix=glm::perspective(glm::radians(60.0f),aspectRatio,0.1f,1000.0f);
        float y_scale=(1.0f/glm::tan(glm::radians(70.0f/2.0f)))*aspectRatio;
        float x_scale=y_scale/aspectRatio;

        float frustrum_length=FAR_PLANE-NEAR_PLANE;
        projectionMatrix=glm::mat4 {0};
        projectionMatrix[0][0]=x_scale;
        projectionMatrix[1][1]=y_scale;
        projectionMatrix[2][2]=-((FAR_PLANE+NEAR_PLANE)/frustrum_length);
        projectionMatrix[2][3]=-1;
        projectionMatrix[3][2]=-((2*NEAR_PLANE*FAR_PLANE)/frustrum_length);
        projectionMatrix[3][3]=0;
    }


} // starlight