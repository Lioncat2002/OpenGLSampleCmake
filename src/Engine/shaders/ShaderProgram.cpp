//
// Created by gamed on 08-10-2023.
//

#include "ShaderProgram.h"

#include <utility>
#include "glad.h"

namespace starlight {

    ShaderProgram::ShaderProgram(std::string VERTEXFILE, std::string FRAGMENTFILE) {
        vertexShaderId= loadShader(VERTEXFILE,GL_VERTEX_SHADER);
        fragmentShaderId= loadShader(FRAGMENTFILE,GL_FRAGMENT_SHADER);
        programId=glCreateProgram();
        glAttachShader(programId,vertexShaderId);
        glAttachShader(programId,fragmentShaderId);

        glLinkProgram(programId);
        glValidateProgram(programId);

        bindAttributes();
    }

    int ShaderProgram::loadShader(std::string filename, int type) {

        std::ifstream file(filename);
        std::string buffer;
        std::string src="";
        if(!file.good()){
            std::cout<<"ERROR::File not found at path: "<<filename<<"\n";
            std::exit(-1);
        }
        if (file.is_open()) {
            while (file) {
                std::getline(file,buffer);
                src += buffer+'\n';
                buffer = "";
            }
            file.close();
        }
        int shaderId=glCreateShader(type);
        const char* src_str = src.c_str();

        glShaderSource(shaderId,1,&src_str, NULL);
        glCompileShader(shaderId);

        int success;
        char infoLog[512];
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
        std::cout<<success<<"\n";
        if (!success) {
            glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog;
            std::exit(-1);
        }
        return shaderId;
    }

    void ShaderProgram::start() {
        glUseProgram(programId);
    }

    void ShaderProgram::stop() {
        glUseProgram(0);
    }

    ShaderProgram::~ShaderProgram() {
        stop();
        glDetachShader(programId,vertexShaderId);
        glDetachShader(programId,fragmentShaderId);
        glDeleteShader(vertexShaderId);
        glDeleteShader(fragmentShaderId);
        glDeleteProgram(programId);
    }

    void ShaderProgram::bindAttribute(int attribute, const GLchar *variable) {
        glBindAttribLocation(programId,attribute,variable);
    }

    void ShaderProgram::bindAttributes() {

    }

} // starlight