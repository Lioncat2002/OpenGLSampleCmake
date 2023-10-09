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

    void Renderer::render(TexturedModel texturedModel) {
        RawModel model=texturedModel.getRawModel();
        glBindVertexArray(model.getVaoId());
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,texturedModel.getTexture().getId());
        glDrawArrays(GL_TRIANGLES,0,model.getVertexCount());
        glBindVertexArray(0);
        glEnableVertexAttribArray(1);
    }
} // starlight