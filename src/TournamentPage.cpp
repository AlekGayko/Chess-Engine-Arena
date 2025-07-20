#include "TournamentPage.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QDebug>
#include <QElapsedTimer>

namespace ChessEngineArena {

    TournamentPage::TournamentPage(std::function<void(Page)> switchPage, QWidget* parent) : QWidget(parent) {
        auto* layout = new QVBoxLayout(this);

        auto* gamesLeft = new QLabel("Games Left: ");
        auto* engine1Wins = new QLabel("Wins: ");
        auto* draws = new QLabel("Draws: ");
        auto* engine2Wins = new QLabel("Wins: ");
        auto* elapsedTimeLabel = new QLabel("Elapsed Time: 0 sec");

        layout->addWidget(gamesLeft);
        layout->addWidget(engine1Wins);
        layout->addWidget(draws);
        layout->addWidget(engine2Wins);
        layout->addWidget(elapsedTimeLabel);

        auto* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, [this, elapsedTimeLabel]() {
            qDebug() << "Tournament Timer!!";
            QString newTimeStr = "Elapsed Time: " + QString::number(elapsedTimer->elapsed() / 1000) + " sec";
            elapsedTimeLabel->setText(newTimeStr);
        });
        timer->start(100);
    }

    void TournamentPage::showEvent(QShowEvent* event) {
        elapsedTimer->start();
    }

    void TournamentPage::hideEvent(QHideEvent* event) {
        elapsedTimer = std::make_unique<QElapsedTimer>();
        tManager = std::make_unique<TournamentManager>();
    }
}