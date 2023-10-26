//
// Created by gamed on 08-10-2023.
//

#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include "vec3.hpp"
#include "detail/type_mat.hpp"

namespace starlight {

    class ShaderProgram {
    protected:
        virtual void bindAttributes();
        void bindAttribute(int attribute, const char *variable);

        //Uniform locations
        int getUniformLocation(std::string uniformName);

        virtual void getAllUniformLocations();

        //Uniform loaders
        void loadFloat(int location,float value);
        void loadVector(int location, glm::vec3 vector);
        void loadBool(int location,bool value);
        void loadMatrix(int location, glm::mat4 matrix);
    private:
        int programId;
        int vertexShaderId;
        int fragmentShaderId;
    private:
        static int loadShader(std::string filename,int type);
    public:
        ShaderProgram(std::string VERTEXFILE,std::string FRAGMENTFILE);
        ~ShaderProgram();
        void start();
        void stop();


    };

} // starlight
