/**
 *   @file: SceneView.h
 *
 *   @date: May 26, 2016
 * @author: Mateusz Midor
 */

#ifndef SOURCE_SCENEVIEW_H_
#define SOURCE_SCENEVIEW_H_

#include <QtQuick/QQuickView>
#include "SceneRenderer.h"

/**
 * @class   SceneView
 * @brief   provide QML-enabled render window with OpenGl context for custom OpenGl rendering
 */
class SceneView : public QQuickView {
    Q_OBJECT

public:
    std::shared_ptr<GameObject> scene_graph_root;
    SceneRenderer renderer;

    SceneView();
    virtual ~SceneView();
    void showCentralized();

signals:

public slots:
    void initializeUnderlay();
    void synchronizeUnderlay();
    void renderUnderlay();
    void invalidateUnderlay();
//    void onTimer();
};

#endif /* SOURCE_SCENEVIEW_H_ */
