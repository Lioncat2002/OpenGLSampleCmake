//
// Created by gamed on 08-10-2023.
//

#include <iostream>
#include "Loader.h"

namespace starlight {
    RawModel Loader::loadToVao(float *positions,int positions_len,float *textureCoords, int textures_len) {
        int vaoId=createVao();
        storeDataInAttributeList(3,0,positions,positions_len);
        storeDataInAttributeList(2,1,textureCoords,textures_len);
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

    void Loader::storeDataInAttributeList(int coordinateSize,int attributeNumber, float *data,int length) {
        unsigned int vboId;
        glGenBuffers(1,&vboId);
        vbos.push_back(vboId);
        glBindBuffer(GL_ARRAY_BUFFER,vboId);
        glBufferData(GL_ARRAY_BUFFER, length*sizeof(float), data, GL_STATIC_DRAW);
        glVertexAttribPointer(attributeNumber,coordinateSize,GL_FLOAT,GL_FALSE,0,NULL);
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

        for(auto texture:textures){
            glDeleteTextures(1,&texture);
        }
    }

    unsigned int Loader::loadTexture(std::string filename) {
        unsigned int textureId;
        glGenTextures(1,&textureId);
        glBindTexture(GL_TEXTURE_2D,textureId);
        //set the texture wrapping/filtering options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        int width, height, nrChannels;
        unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else {
            std::cout << "Failed to load texture\n";
        }

        textures.push_back(textureId);
        stbi_image_free(data);
        return textureId;
        return 0;
    }

    void Loader::bindIndicesBuffer(int *indices,int length) {
        unsigned int vboId;
        glGenBuffers(1,&vboId);
        vbos.push_back(vboId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,length*sizeof(int),indices,GL_STATIC_DRAW);

    }
} // starlight