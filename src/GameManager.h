#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <array>
#include <memory>
#include <string_view>
#include <vector>

#include "Types.h"

#include <chess.hpp>

namespace ChessEngineArena {
    
    class Engine;

    class GameManager {
    public:
        GameManager(std::string_view whiteBinPath, std::string_view blackBinPath, std::string_view fen=startPos);
        ~GameManager() = default;
        
        bool isGameFinished() const { return gameFinished; }
        GameResult playGame(int wTime, int bTime, int wInc, int bInc);
        GameResult playGame(int movetime);
    private:
        std::string getMove(Color color, int wTime, int bTime, int wInc, int bInc);
        std::string getMove(Color color, int moveTime);

        static constexpr std::string_view startPos{"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"};
        chess::Board board;
        std::vector<std::string> moves;
        std::array<std::unique_ptr<Engine>, COLOR_NB> engines;
        bool gameFinished{false};
    };

}

#endif