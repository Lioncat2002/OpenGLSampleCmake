//
// Created by gamed on 09-10-2023.
//

#include "StaticShader.h"

namespace starlight {
    StaticShader::StaticShader(std::string VERTEX_FILE, std::string FRAGMENT_FILE) : ShaderProgram(VERTEX_FILE,
                                                                                                   FRAGMENT_FILE) {

    }

    void StaticShader::bindAttributes() {
        bindAttribute(0,"position");
        bindAttribute(1,"textureCoords");
        ShaderProgram::bindAttributes();
    }

} // starlight