/**
 *   @file: SceneRenderer.cpp
 *
 *   @date: May 26, 2016
 * @author: mateusz
 */

#include "SceneRenderer.h"
#include "GraphicsComponent.h"

using namespace std;

SceneRenderer::SceneRenderer() {
}

SceneRenderer::~SceneRenderer() {
}

/**
 * @name    setViewportSize
 * @brief   configure viewport size and projection matrix
 * @param   size New viewport width and height
 */
void SceneRenderer::setViewportSize(const QSize &size) {
    viewportSize = size;
    projectionMatrix = make_shared<QMatrix4x4>();
    //projectionMatrix.perspective(45.0, (float) viewportSize.width() / viewportSize.height(), 1.0, 1000.0);
    projectionMatrix->ortho(QRect(0, 0, size.width(), size.height()));
    glViewport(0, 0, viewportSize.width(), viewportSize.height());
}

/**
 * @name    initialize
 * @brief   initialize underlying OpenGl machinery
 */
void SceneRenderer::initialize() {
    initializeOpenGLFunctions();
}

/**
 * @name    render
 * @brief   recursively render the scene graph
 * @param   scene_graph_root Node to start the recursive rendering from
 */
void SceneRenderer::render(const shared_ptr<GameObject> &scene_graph_root) {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5, 0.5, 1.0, 1);
    glClearDepthf(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    renderSceneNode(scene_graph_root);
}

void SceneRenderer::renderSceneNode(const std::shared_ptr<GameObject> &node) const {
    const auto graphics_component = node->findComponentByType<GraphicsComponent>();

    if (graphics_component)
        graphics_component->render(projectionMatrix);

    for (const auto child : node->children) {
        const auto game_object = static_pointer_cast<GameObject>(child);
        renderSceneNode(game_object);
    }
}
