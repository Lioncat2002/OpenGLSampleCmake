//
// Created by gamed on 08-10-2023.
//

#include "RawModel.h"

namespace starlight {
    RawModel::RawModel(int vaoId, int vertexCount) {
        this->vaoId=vaoId;
        this->vertexCount=vertexCount;
    }

    int RawModel::getVaoId() {
        return vaoId;
    }
    int RawModel::getVertexCount() {
        return vertexCount;
    }

    RawModel::RawModel() {

    }
} // starlight