//
// Created by gamed on 08-10-2023.
//

#include <iostream>
#include "Loader.h"

namespace starlight {
    RawModel Loader::loadToVao(float *positions,int positions_len) {
        int vaoId=createVao();
        storeDataInAttributeList(0,positions,positions_len);
        unbindVao();
        return {vaoId, positions_len/3};
    }

    unsigned int Loader::createVao() {
        unsigned int vaoId;
        glGenVertexArrays(1,&vaoId);
        vaos.push_back(vaoId);
        glBindVertexArray(vaoId);
        return vaoId;
    }

    void Loader::storeDataInAttributeList(int attributeNumber, float *data,int length) {
        unsigned int vboId;
        glGenBuffers(1,&vboId);
        vbos.push_back(vboId);
        glBindBuffer(GL_ARRAY_BUFFER,vboId);
        glBufferData(GL_ARRAY_BUFFER, length*sizeof(float), data, GL_STATIC_DRAW);
        glVertexAttribPointer(attributeNumber,3,GL_FLOAT,GL_FALSE,0,NULL);
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }

    void Loader::unbindVao() {
        glBindVertexArray(0);
    }

    Loader::~Loader() {
        for (auto vao: vaos) {
            glDeleteVertexArrays(1,&vao);
        }
        for (auto vbo: vbos) {
            glDeleteVertexArrays(1,&vbo);
        }
    }
} // starlight