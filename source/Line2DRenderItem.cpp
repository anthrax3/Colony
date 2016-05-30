/**
 *   @file: Line2DRenderItem.cpp
 *
 *   @date: May 30, 2016
 * @author: mateusz
 */

#include "Line2DRenderItem.h"

using namespace std;

Line2DRenderItem::Line2DRenderItem() : shaderProgram(nullptr) {
}

/**
 * @name    initShaderProgram
 * @brief   creates GLSL shading program for line rendering
 */
void Line2DRenderItem::initShaderProgram() {
    const char VERT[] =
        "attribute vec4 vertices;"
        "uniform mat4 mvp_matrix;"
        "void main() {"
            "gl_Position =  mvp_matrix * vertices;"
        "}";

    const char FRAG[] =
        "void main() {"
            "gl_FragColor = vec4(1.0, 1.0, 0.0, 1.0);"
        "}";


    initializeOpenGLFunctions();

    shaderProgram = make_unique<QOpenGLShaderProgram>();
    shaderProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, VERT);
    shaderProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, FRAG);
    shaderProgram->bindAttributeLocation("vertices", 0);
    shaderProgram->link();
}

Line2DRenderItem::~Line2DRenderItem() {
}

const float* getLineVertices() {
    static const float VERTICES[] = {
            -1.0f, 0.0f,
             1.0f, 0.0f
    };

    return VERTICES;
}

void Line2DRenderItem::render(const std::shared_ptr<QMatrix4x4> &m) {

    if (!shaderProgram)
        initShaderProgram();

    shaderProgram->bind();
    shaderProgram->enableAttributeArray(0);

    // assign actual data to "vertices" attribute bound at index 0. 2 components (x and y)
    shaderProgram->setAttributeArray(0, GL_FLOAT, getLineVertices(), 2);
    shaderProgram->setUniformValue("mvp_matrix", *m );

    // draw "vertices". 2 vertices
    glDrawArrays(GL_LINES, 0, 2);

    shaderProgram->disableAttributeArray(0);
    shaderProgram->release();
}
