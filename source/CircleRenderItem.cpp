/**
 *   @file: CircleRenderItem.cpp
 *
 *   @date: Jun 7, 2016
 * @author: mateusz
 */

#include "CircleRenderItem.h"

using namespace std;

CircleRenderItem::CircleRenderItem() :
        shaderProgram(nullptr) {
}

CircleRenderItem::~CircleRenderItem() {
}

/**
 * @name    initShaderProgram
 * @brief   creates GLSL shading program for circle rendering
 */
void CircleRenderItem::initShaderProgram() {
    const char VERT[] = "attribute vec4 vertices;"
            "uniform mat4 mvp_matrix;"
            "void main() {"
            "gl_Position =  mvp_matrix * vertices;"
            "}";

    const char FRAG[] = "void main() {"
            "gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);"
            "}";

    initializeOpenGLFunctions();

    shaderProgram = make_unique<QOpenGLShaderProgram>();
    shaderProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, VERT);
    shaderProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, FRAG);
    shaderProgram->bindAttributeLocation("vertices", 0);
    shaderProgram->link();
}

const float* getCircleVertices() {
    static const float VERTICES[] = {
            0.00000, 1.00000,
            0.34202, 0.93969,
            0.64279, 0.76604,
            0.86603, 0.50000,
            0.98481, 0.17365,
            0.98481, -0.17365,
            0.86603, -0.50000,
            0.64279, -0.76604,
            0.34202, -0.93969,
            0.00000, -1.00000,
            -0.34202, -0.93969,
            -0.64279, -0.76604,
            -0.86603, -0.50000,
            -0.98481, -0.17365,
            -0.98481, 0.17365,
            -0.86603, 0.50000,
            -0.64279, 0.76604,
            -0.34202, 0.93969,
            0.00000, 0.00000
    };

    return VERTICES;
}

/**
 * @name    render
 * @brief   Render the item to the screen
 * @param   m Absolute transform matrix to apply for this item
 */
void CircleRenderItem::render(const std::shared_ptr<QMatrix4x4> &m) {

    if (!shaderProgram)
        initShaderProgram();

    shaderProgram->bind();
    shaderProgram->enableAttributeArray(0);

    // assign actual data to "vertices" attribute bound at index 0. 2 components (x and y)
    shaderProgram->setAttributeArray(0, GL_FLOAT, getCircleVertices(), 2);
    shaderProgram->setUniformValue("mvp_matrix", *m);

    // draw "vertices". 18 vertices + center
    glDrawArrays(GL_TRIANGLE_FAN, 0, 19);

    shaderProgram->disableAttributeArray(0);
    shaderProgram->release();
}
