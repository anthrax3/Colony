/**
 *   @file: Line2DRenderItem.h
 *
 *   @date: May 30, 2016
 * @author: mateusz
 */

#ifndef SOURCE_LINE2DRENDERITEM_H_
#define SOURCE_LINE2DRENDERITEM_H_

#include <QtGui/QOpenGLFunctions>
#include <QtGui/QOpenGLShaderProgram>
#include "RenderItem.h"

/**
 * @class   Line2DRenderItem
 * @brief   Renderable Item representing horizontal line, 3 units long
 */
class Line2DRenderItem: public RenderItem, protected QOpenGLFunctions  {
    std::unique_ptr<QOpenGLShaderProgram> shaderProgram;
    void initShaderProgram();

public:
    Line2DRenderItem();
    virtual ~Line2DRenderItem();

    void update(const float dt) override {}
    void prepareRenderSnashot() override {}
    void render(const std::shared_ptr<QMatrix4x4> &m) override;
};

#endif /* SOURCE_LINE2DRENDERITEM_H_ */
