//
// Created by gamed on 09-10-2023.
//

#pragma once
#include "ShaderProgram.h"
namespace starlight {

    class StaticShader: public ShaderProgram {
    protected:
        void bindAttributes() override;
    public:
        StaticShader(std::string VERTEX_FILE,std::string FRAGMENT_FILE);
    };

} // starlight
