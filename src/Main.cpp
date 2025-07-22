#define WIN32_LEAN_AND_MEAN

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include <iostream>
#include <stdexcept>

#include "MainWindow.h"
#include "Engine.h"

using namespace ChessEngineArena;

void testEngine() {
    try {
        Engine eng("C:\\Users\\Alek\\Documents\\SandalBotV2 exe versions\\V1.6\\SandalBotV2.exe");
        std::cout << eng.getBestMove(1000) << std::endl;
    } catch (std::exception& e) {
        qDebug() << e.what();
    }
}

int main(int argc, char *argv[]) {
    testEngine();
    // QString pluginPath = "./platforms";
    // qputenv("QT_PLUGIN_PATH", pluginPath.toUtf8());

    // QApplication app(argc, argv);

    // MainWindow window1 = MainWindow();
    // window1.show();

    // return app.exec();
}