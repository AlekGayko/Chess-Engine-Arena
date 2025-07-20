#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStackedWidget>
#include <QWidget>

namespace ChessEngineArena {

    class MainWindow : public QMainWindow {
        Q_OBJECT
    public:
        explicit MainWindow(QWidget* parent = nullptr);
        ~MainWindow() = default;
    private:
        enum Page {
            HOME,
            CONFIG
        };
        QStackedWidget* stackedWidget;
    };

    class HomePage : public QWidget {
        Q_OBJECT
    public:
        explicit HomePage(QWidget* parent = nullptr);
        ~HomePage() = default;
    };

    class Menu : public QMenuBar {
        Q_OBJECT
    public:
        explicit Menu(QWidget* parent = nullptr);
        ~Menu() = default;
    };

}

#endif