//
// Created by gamed on 09-10-2023.
//

#include "StaticShader.h"
#include "detail/type_mat4x4.hpp"
#include "../utils/Math.h"
namespace starlight {
    StaticShader::StaticShader(std::string VERTEX_FILE, std::string FRAGMENT_FILE) : ShaderProgram(VERTEX_FILE,
                                                                                                   FRAGMENT_FILE) {

        bindAttributes();
        getAllUniformLocations();
    }

    void StaticShader::bindAttributes() {

        bindAttribute(0,"position");
        bindAttribute(1,"textureCoords");
        //ShaderProgram::bindAttributes();
    }

    void StaticShader::getAllUniformLocations() {
        location_transformationMatrix=ShaderProgram::getUniformLocation("transformationMatrix");
        location_projectionMatrix=ShaderProgram::getUniformLocation("projectionMatrix");
        location_viewMatrix=ShaderProgram::getUniformLocation("viewMatrix");
        ShaderProgram::getAllUniformLocations();
    }

    void StaticShader::loadTransformationMatrix(glm::mat4 matrix) {
        //std::cout<<location_transformationMatrix;
        ShaderProgram::loadMatrix(location_transformationMatrix,matrix);
    }

    void StaticShader::loadProjectionMatrix(glm::mat4 matrix) {
        ShaderProgram::loadMatrix(location_projectionMatrix,matrix);
    }

    void StaticShader::loadViewMatrix(Camera camera) {
        glm::mat4 viewMatrix=Math::createViewMatrix(camera);
        ShaderProgram::loadMatrix(location_viewMatrix,viewMatrix);
    }


} // starlight