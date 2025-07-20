#ifndef TOURNAMENTPAGE_H
#define TOURNAMENTPAGE_H

#include <QWidget>
#include <QElapsedTimer>

#include <memory>
#include <functional>

#include "TournamentManager.h"
#include "Types.h"

namespace ChessEngineArena {

    class TournamentPage : public QWidget {
        Q_OBJECT
    public:
        explicit TournamentPage(std::function<void(Page)> switchPage, QWidget* parent = nullptr);
        ~TournamentPage() = default;
    private:
        std::unique_ptr<TournamentManager> tManager;
        std::unique_ptr<QElapsedTimer> elapsedTimer;

        void showEvent(QShowEvent* event) override;
        void hideEvent(QHideEvent* event) override;
    };

}

#endif