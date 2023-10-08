//
// Created by gamed on 08-10-2023.
//

#pragma once

#include <string>

namespace starlight {

    class ShaderProgram {
    private:
        int programId;
        int vertexShadderId;
        int fragmentShaderId;
    private:
        static int loadShader(std::string file,int type);

    };

} // starlight
