//
// Created by gamed on 08-10-2023.
//

#pragma once

#include "RawModel.h"
#include "glad/glad.h"
#include <vector>
namespace starlight{

        class Loader {
        private:
            std::vector<unsigned int> vaos;
            std::vector<unsigned int> vbos;

        public:
            RawModel loadToVao(float *positions,int positions_len);
            ~Loader();
        private:
            unsigned int createVao();
            void storeDataInAttributeList(int attributeNumber, float data[],int positions_length);
            void unbindVao();
        };

} // starlight
