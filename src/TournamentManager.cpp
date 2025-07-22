#include "TournamentManager.h"

#include "GameManager.h"

namespace ChessEngineArena {

    TournamentManager::TournamentManager(std::array<std::string_view, ENGINE_NB> engineDirs, int numGames)
    : numGames(numGames), numGamesLeft(numGames) {
        this->engineDirs[ENGINE_ONE] = engineDirs[ENGINE_ONE];
        this->engineDirs[ENGINE_TWO] = engineDirs[ENGINE_TWO];

        this->numThreads = std::thread::hardware_concurrency();
    }

    void TournamentManager::run() {
        initGames();

        while (numGamesLeft.load() > 0) {
            for (int i = 0; i < currGames.size(); ++i) {
                if (currGames[i].manager.isGameFinished()) {
                    updateStats(currGames[i]);
                    currGames.erase(currGames.begin() + i);
                }
            }

            if (currGames.size() < numThreads) {
                for (int i = 0; i < (numThreads - currGames.size()); ++i) {
                    addGame();
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    void TournamentManager::initGames() {
        currGames.reserve(numThreads);
        for (int i = 0; i < numThreads; ++i) {
            addGame();
        }
    }
    void TournamentManager::addGame() {
        EngineNum whiteEngine = numGames % 2 == 0 ? ENGINE_ONE : ENGINE_TWO;
        std::string_view whiteDir = whiteEngine == ENGINE_ONE ? engineDirs[ENGINE_ONE] : engineDirs[ENGINE_TWO];
        std::string_view blackDir = whiteEngine == ENGINE_TWO ? engineDirs[ENGINE_ONE] : engineDirs[ENGINE_TWO];

        TournamentManager::GameInfo info{ GameManager(whiteDir, blackDir), std::future<GameResult>(), whiteEngine };
        if (moveTime.has_value()) {
            info.gameFuture = std::async(std::launch::async, static_cast<GameResult (GameManager::*)(int)>(&GameManager::playGame), 
                &info.manager, moveTime.value());
        } else {
            info.gameFuture = std::async(std::launch::async, 
                static_cast<GameResult (GameManager::*)(int, int, int, int)>(&GameManager::playGame), &info.manager, wTime.value(), 
                bTime.value(), wInc.value(), bInc.value());
        }
        std::lock_guard<std::mutex> lock(currGamesLock);
        currGames.push_back(info);
    }

    void TournamentManager::updateStats(GameInfo& info) {
        GameResult result = info.gameFuture.get();

        if (result == DRAW) {
            draws.fetch_add(1);
            numGamesLeft.fetch_sub(1);
        } else if (result == WHITE_WIN) {
            wins[info.whiteEngine].fetch_add(1);
        } else if (result == BLACK_WIN) {
            EngineNum blackEngine = info.whiteEngine == ENGINE_ONE ? ENGINE_ONE : ENGINE_TWO;
            wins[blackEngine].fetch_add(1);
        }
    }
}