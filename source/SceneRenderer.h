/**
 *   @file: SceneRenderer.h
 *
 *   @date: May 26, 2016
 * @author: mateusz
 */

#ifndef SOURCE_SCENERENDERER_H_
#define SOURCE_SCENERENDERER_H_

#include <memory>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QOpenGLShaderProgram>
#include "GameObject.h"

/**
 * @class   SceneRenderer
 * @brief   Prepares OpenGl machinery and renders Scene Graph on demand
 */
class SceneRenderer : public QObject, protected QOpenGLFunctions {
    Q_OBJECT
    QSize viewportSize;
    QMatrix4x4 projectionMatrix;

    void renderSceneNode(const std::shared_ptr<GameObject> &node) const;
public:
    SceneRenderer();
    virtual ~SceneRenderer();


    void initialize();
    void invalidate() {}
    void setViewportSize(const QSize &size);
    void render(const std::shared_ptr<GameObject> &scene_graph_root);

};

#endif /* SOURCE_SCENERENDERER_H_ */
