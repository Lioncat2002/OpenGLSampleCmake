//
// Created by gamed on 08-10-2023.
//

#include "ShaderProgram.h"

#include <utility>
#include "glad.h"
#include "detail/type_mat4x4.hpp"
#include "gtc/type_ptr.hpp"
#include "StaticShader.h"

namespace starlight {

    ShaderProgram::ShaderProgram(std::string VERTEXFILE, std::string FRAGMENTFILE) {
        vertexShaderId= loadShader(std::move(VERTEXFILE),GL_VERTEX_SHADER);
        fragmentShaderId= loadShader(std::move(FRAGMENTFILE),GL_FRAGMENT_SHADER);
        programId=glCreateProgram();
        glAttachShader(programId,vertexShaderId);
        glAttachShader(programId,fragmentShaderId);
        bindAttributes();
        glLinkProgram(programId);
        glValidateProgram(programId);
        getAllUniformLocations();
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

        glShaderSource(shaderId,1,&src_str, nullptr);
        glCompileShader(shaderId);

        int success;
        char infoLog[512];
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shaderId, 512, nullptr, infoLog);
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

    int ShaderProgram::getUniformLocation(std::string uniformName) {
        return glGetUniformLocation(programId,uniformName.c_str());
    }

    void ShaderProgram::getAllUniformLocations() {
        std::cout<<"Parent class Uniform called\n";
    }

    void ShaderProgram::loadFloat(int location, float value) {
        glUniform1f(location,value);
    }

    void ShaderProgram::loadVector(int location, glm::vec3 vector) {
        glUniform3f(location,vector.x,vector.y,vector.z);
    }

    void ShaderProgram::loadBool(int location, bool value) {
        float toLoad=value ? 1 : 0;//no support for native bools
        glUniform1f(location,toLoad);
    }

    void ShaderProgram::loadMatrix(int location, glm::mat4 matrix) {
        glUniformMatrix4fv(location, 1, false, glm::value_ptr(matrix));
    }


} // starlight