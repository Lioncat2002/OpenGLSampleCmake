//
// Created by gamed on 08-10-2023.
//

#include <iostream>
#include "Renderer.h"

namespace starlight {
    void Renderer::prepare() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::render(RawModel model) {
        glBindVertexArray(model.getVaoId());
        glEnableVertexAttribArray(0);
        glDrawArrays(GL_TRIANGLES,0,model.getVertexCount());
        glBindVertexArray(0);
    }
} // starlight