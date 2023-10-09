//
// Created by gamed on 08-10-2023.
//

#pragma once

#include "Engine/models/RawModel.h"
#include "glad/glad.h"
#include "stb_image.h"
#include <vector>
namespace starlight{

        class Loader {
        private:
            std::vector<unsigned int> vaos;
            std::vector<unsigned int> vbos;
            std::vector<unsigned int> textures;

        public:
            unsigned int loadTexture(std::string filename);
            RawModel loadToVao(float *positions,int positions_len,float *textureCoords, int textures_len);
            ~Loader();
        private:
            unsigned int createVao();
            void bindIndicesBuffer(int *indices,int length);
            void storeDataInAttributeList(int coordinateSize,int attributeNumber, float data[],int positions_length);
            void unbindVao();
        };

} // starlight
