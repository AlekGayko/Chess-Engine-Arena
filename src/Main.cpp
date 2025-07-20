#define WIN32_LEAN_AND_MEAN

#include <boost/process.hpp>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include "MainWindow.h"

using namespace ChessEngineArena;

int main(int argc, char *argv[]) {
    QString pluginPath = "./platforms";
    qputenv("QT_PLUGIN_PATH", pluginPath.toUtf8());

    QApplication app(argc, argv);

    MainWindow window1 = MainWindow();
    window1.show();

    return app.exec();
}