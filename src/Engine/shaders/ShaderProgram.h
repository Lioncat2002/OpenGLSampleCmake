//
// Created by gamed on 08-10-2023.
//

#pragma once

#include <string>
#include <fstream>
#include <iostream>

namespace starlight {

    class ShaderProgram {
    protected:
        virtual void bindAttributes();
        void bindAttribute(int attribute, const char *variable);
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
