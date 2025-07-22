#ifndef TOURNAMENTMANAGER_H
#define TOURNAMENTMANAGER_H

#include <array>
#include <atomic>
#include <thread>
#include <unordered_set>
#include <memory>
#include <mutex>
#include <future>
#include <queue>
#include <vector>
#include <string>
#include <optional>
#include <string_view>

#include "Types.h"

namespace ChessEngineArena {

    class GameManager;

    class TournamentManager {
        enum EngineNum : int {
            ENGINE_ONE,
            ENGINE_TWO,
            ENGINE_NB
        };
    public:
        struct TournamentResults {
            int engineOneWins;
            int engineTwoWins;
            int draws;
        };

        TournamentManager(std::array<std::string_view, ENGINE_NB> engineDirs, int numGames = DEFAULT_TOURNAMENT_SIZE);
        ~TournamentManager() = default;

        void start() { 
            if (tournamentThread.joinable()) {
                return;
            }
            tournamentThread = std::thread(&TournamentManager::run, this); 
        };
        void run();

        TournamentResults getResults() { 
            return { wins[ENGINE_ONE].load(), wins[ENGINE_TWO].load(), draws.load() }; 
        }

    private:
        struct GameInfo {
            GameManager manager;
            std::future<GameResult> gameFuture;
            EngineNum whiteEngine;
        };

        std::array<std::string, ENGINE_NB> engineDirs;

        std::array<std::atomic<int>, ENGINE_NB> wins;
        std::atomic<int> draws{ 0 };

        int numGames{ DEFAULT_TOURNAMENT_SIZE };
        std::atomic<int> numGamesLeft{ numGames };
        int numThreads{ 1 };
        std::vector<GameInfo> currGames;
        std::thread tournamentThread;

        std::optional<int> moveTime;

        std::optional<int> wTime, bTime;
        std::optional<int> wInc, bInc;

        std::mutex currGamesLock;

        void initGames();
        void addGame();
        void updateStats(GameInfo& info);
    };

}

#endif