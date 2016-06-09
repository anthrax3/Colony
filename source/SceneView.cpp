/**
 *   @file: SceneView.cpp
 *
 *   @date: May 26, 2016
 * @author: Mateusz Midor
 */

#include <QtQuick/QQuickWindow>
#include <QtQml/QQmlContext>
#include <QtGui/QScreen>
#include "TransformMatrixCombiner.h"
#include "LocalTransformComponent.h"
#include "SceneView.h"

using namespace std;

SceneView::SceneView() : QQuickView(nullptr)
{
    // create default scene_graph
    scene_graph_root = make_shared<GameObject>();

    // configure rendering surface
    QSurfaceFormat format;
    format.setMajorVersion(3);
    format.setMinorVersion(3);
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(0);
    format.setSamples(8);
    setFormat(format);

    // connect Render thread signals
    connect(this, &QQuickWindow::sceneGraphInitialized, this, &SceneView::initializeUnderlay, Qt::DirectConnection);
    connect(this, &QQuickWindow::beforeSynchronizing, this, &SceneView::synchronizeUnderlay, Qt::DirectConnection);
    connect(this, &QQuickWindow::beforeRendering, this, &SceneView::renderUnderlay, Qt::DirectConnection);
    connect(this, &QQuickWindow::sceneGraphInvalidated, this, &SceneView::invalidateUnderlay, Qt::DirectConnection);

    // connect (camera, &Camera::azimuthChanged, this, &QQuickWindow::update); // force emitting QQuickWindow::beforeSynchronizing

    setClearBeforeRendering(false);
    setPersistentOpenGLContext(true);
    setResizeMode(SizeRootObjectToView);

//    rootContext()->setContextProperty("_rendererControl", &rendererControl);
//    rootContext()->setContextProperty("_cameraControl", &camera);

    // load qml scene
    setSource(QUrl(QStringLiteral("qrc:/main.qml")));

    connect(&timer, &QTimer::timeout, this, &SceneView::onTimer);
    timer.start(16);
    elapsed_timer.start();
}

SceneView::~SceneView() {
}

/**
 * @name    showCentralized
 * @brief   display the render window centralized in the screen
 */
void SceneView::showCentralized() {
    unsigned x = (screen()->size().width() - size().width()) / 2;
    unsigned y = (screen()->size().height() - size().height()) / 2;
    setPosition(x, y);
    QQuickView::show();
}

/**
 * @name    onTimer
 * @brief   acts as GameLoop, updating/rendering; for now its enough
 * @note    Called from GUI thread
 */
void SceneView::onTimer() {

    // Dont change scene graph struct when rendering might be ongoing!!!
    // Use buffered scene node operations eg. bufferedAddChild, and the bufferSync in thread sync phase

    // build absolute transform matrices by combining local transforms
    TransformMatrixCombiner::combineLocalTransforms(scene_graph_root);

    // update the scene graph
    updater.update(scene_graph_root, elapsed_timer.restart() / 1000.0f);

    // repaint the screen
    update();
}

/**
 * @name    initializeUnderlay
 * @brief   initialize the renderer
 * @note    called from render thread
 */
void SceneView::initializeUnderlay() {
    renderer.initialize();
    resetOpenGLState();
}

/**
 * @name    synchronizeUnderlay
 * @brief   copy any data being updated by gui thread for render thread safe access
 * @note    called from render thread when gui thread is frozen and cant modify data
 */
void SceneView::synchronizeUnderlay() {
//    renderer.setAzimuth(camera.getAzimuth());
//    renderer.setElevation(camera.getElevation());
//    renderer.setDistance(camera.getDistance());
//    renderer.setViewportSize(this->size());
//    renderer.setModelFilename(rendererControl.getModelFilename());
//    renderer.prepare(TARGET_DELTA_TIME_SEC);
//    auto transform = scene_graph_root->findComponentByType<LocalTransformComponent>();
//    transform->rotate+= QVector3D(0, 0, 0.5);

    renderer.setViewportSize(this->size());
    synchronizer.sync(scene_graph_root);
}

/**
 * @name    renderUnderlay
 * @brief   do the actual rendering here
 * @note    called from render thread
 */
void SceneView::renderUnderlay() {
    renderer.render(scene_graph_root);
    resetOpenGLState();
}

/**
 * @name    invalidateUnderlay
 * @brief   release the renderer
 * @note    called from render thread
 */
void SceneView::invalidateUnderlay() {
    renderer.invalidate();
    resetOpenGLState();
}
