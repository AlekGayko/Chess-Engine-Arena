#include "MainWindow.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include <QToolBar>
#include <QAction>
#include <QIcon>
#include <QDebug>

#include <QMenu>
#include <QPixmap>

#include <QApplication>

#include "ConfigPage.h"
#include "Styles.h"

namespace ChessEngineArena {

    MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
        this->resize(600, 400);
        this->setWindowTitle("Chess Engine Arena");

        this->stackedWidget = new QStackedWidget(this);

        auto *homePage = new HomePage(this);
        auto *configPage = new ConfigPage(this);
        
        stackedWidget->addWidget(homePage);
        stackedWidget->addWidget(configPage);

        setCentralWidget(stackedWidget);

        // === Menu Bar ===
        QMenuBar* menuBar = this->menuBar();

        // === File Menu ===
        QMenu* fileMenu = menuBar->addMenu("File");

        QAction* newGameAction = fileMenu->addAction("New Game");
        QAction* exitAction = fileMenu->addAction("Exit");

        // === Help Menu ===
        QMenu* helpMenu = menuBar->addMenu("Help");
        QAction* aboutAction = helpMenu->addAction("About");

        // === Connect Actions ===
        connect(newGameAction, &QAction::triggered, this, []() {
            qDebug() << "New Game selected!";
        });

        connect(exitAction, &QAction::triggered, this, &QCoreApplication::quit);

        connect(aboutAction, &QAction::triggered, this, []() {
            qDebug() << "About selected!";
        });
    }

    HomePage::HomePage(QWidget* parent = nullptr) : QWidget(parent) {
        auto *layout = new QVBoxLayout(this);

        QLabel* title = new QLabel("Chess Engine Arena");

        title->setFont(titleFont);
        layout->addWidget(title);

        QPushButton *startBtn = new QPushButton("Start");
        layout->addWidget(startBtn);

        // Connect button signal to slot (lambda)
        connect(startBtn, &QPushButton::clicked, this, [startBtn]() {
            qDebug("Button clicked!");
        });
    }   
}