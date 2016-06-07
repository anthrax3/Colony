/**
 *   @file: CircleRenderItem.h
 *
 *   @date: Jun 7, 2016
 * @author: mateusz
 */

#ifndef SOURCE_CIRCLERENDERITEM_H_
#define SOURCE_CIRCLERENDERITEM_H_

#include <QtGui/QOpenGLFunctions>
#include <QtGui/QOpenGLShaderProgram>
#include "RenderItem.h"

class CircleRenderItem: public RenderItem, protected QOpenGLFunctions {
    std::unique_ptr<QOpenGLShaderProgram> shaderProgram;
    void initShaderProgram();

public:
    CircleRenderItem();
    virtual ~CircleRenderItem();

    void update(const float dt) override {}
    void prepareRenderSnashot() override {}
    void render(const std::shared_ptr<QMatrix4x4> &m) override;
};

#endif /* SOURCE_CIRCLERENDERITEM_H_ */
