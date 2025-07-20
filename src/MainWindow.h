#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStackedWidget>
#include <QWidget>

#include <functional>

#include "Types.h"

namespace ChessEngineArena {

    class MainWindow : public QMainWindow {
        Q_OBJECT
    public:
        explicit MainWindow(QWidget* parent = nullptr);
        ~MainWindow() = default;
    private:
        QStackedWidget* stackedWidget;
    };

    class HomePage : public QWidget {
        Q_OBJECT
    public:
        explicit HomePage(std::function<void(Page)> switchPage, QWidget* parent = nullptr);
        ~HomePage() = default;
    };

}

#endif