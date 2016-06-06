#include <memory>
#include <cmath>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

#include "SceneView.h"
#include "SceneBuilder.h"

using namespace std;


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    SceneView view;
    view.scene_graph_root = SceneBuilder::buildNumerousAnts();
    view.resize(640, 480);
    view.showCentralized();

    return app.exec();
}
