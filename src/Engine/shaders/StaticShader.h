//
// Created by gamed on 09-10-2023.
//

#pragma once
#include "ShaderProgram.h"
namespace starlight {

    class StaticShader: public ShaderProgram {
    private:
        int location_transformationMatrix;
    protected:
        void bindAttributes() override;
        void getAllUniformLocations() override;
    public:
        StaticShader(std::string VERTEX_FILE,std::string FRAGMENT_FILE);
        void loadTransformationMatrix(glm::mat4 matrix);
    };

} // starlight
