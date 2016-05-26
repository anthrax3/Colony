#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include "SceneView.h"

using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    SceneView view;
    view.resize(640, 480);
    view.showCentralized();

    return app.exec();
}
