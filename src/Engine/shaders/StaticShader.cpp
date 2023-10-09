//
// Created by gamed on 09-10-2023.
//

#include "StaticShader.h"
#include "detail/type_mat4x4.hpp"

namespace starlight {
    StaticShader::StaticShader(std::string VERTEX_FILE, std::string FRAGMENT_FILE) : ShaderProgram(VERTEX_FILE,
                                                                                                   FRAGMENT_FILE) {

    }

    void StaticShader::bindAttributes() {
        bindAttribute(0,"position");
        bindAttribute(1,"textureCoords");
        ShaderProgram::bindAttributes();
    }

    void StaticShader::getAllUniformLocations() {
        location_transformationMatrix=ShaderProgram::getUniformLocation("transformationMatrix");

        ShaderProgram::getAllUniformLocations();
    }

    void StaticShader::loadTransformationMatrix(glm::mat4 matrix) {
        ShaderProgram::loadMatrix(location_transformationMatrix,matrix);
    }


} // starlight