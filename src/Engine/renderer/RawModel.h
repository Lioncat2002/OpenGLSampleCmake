//
// Created by gamed on 08-10-2023.
//

#pragma once

namespace starlight {

    class RawModel {
    private:
        int vaoId;
        int vertexCount;
    public:
        RawModel(int vaoId,int vertexCount);
        int getVaoId();
        int getVertexCount();

        RawModel();
    };

} // starlight

