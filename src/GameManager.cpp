#include "GameManager.h"

#include "Engine.h"

namespace ChessEngineArena {

    GameManager::GameManager(std::string_view whiteBinPath,  std::string_view blackBinPath, 
        std::string_view fen) {
        board.setFen(fen);

        engines[WHITE] = std::make_unique<Engine>(whiteBinPath);
        engines[WHITE].get()->updatePosition(fen, moves);

        engines[BLACK] = std::make_unique<Engine>(blackBinPath);
        engines[BLACK].get()->updatePosition(fen, moves);
    }

    GameResult GameManager::playGame(int moveTime) { 
        while (board.isGameOver().first == chess::GameResultReason::NONE) {
            std::string uciMove;
            if (board.sideToMove() == chess::Color::WHITE) {
                uciMove = getMove(WHITE, moveTime);
            } else {
                uciMove = getMove(BLACK, moveTime);
            }
            moves.push_back(uciMove);

            chess::Move move = chess::uci::uciToMove(board, uciMove);
            board.makeMove(move);
        }
        auto result = board.isGameOver();
        if (result.second == chess::GameResult::DRAW) {
            return DRAW;
        } else {
            return board.sideToMove() == chess::Color::WHITE ? BLACK_WIN : WHITE_WIN; 
        }
    }

    GameResult GameManager::playGame(int wTime, int bTime, int wInc, int bInc) { 
        while (board.isGameOver().first == chess::GameResultReason::NONE) {
            std::string uciMove;
            if (board.sideToMove() == chess::Color::WHITE) {
                uciMove = getMove(WHITE, wTime, bTime, wInc, bInc);
            } else {
                uciMove = getMove(BLACK, wTime, bTime, wInc, bInc);
            }
            moves.push_back(uciMove);

            chess::Move move = chess::uci::uciToMove(board, uciMove);
            board.makeMove(move);
        }
        auto result = board.isGameOver();
        if (result.second == chess::GameResult::DRAW) {
            return DRAW;
        } else {
            return board.sideToMove() == chess::Color::WHITE ? BLACK_WIN : WHITE_WIN; 
        }
    }

    std::string GameManager::getMove(Color color, int wTime, int bTime, int wInc, int bInc) {
        engines[color].get()->updatePosition(board.getFen(), moves);
        return engines[color].get()->getBestMove(wTime, bTime, wInc, bInc);
    }

    std::string GameManager::getMove(Color color, int moveTime) {
        engines[color].get()->updatePosition(board.getFen(), moves);
        return engines[color].get()->getBestMove(moveTime);
    }   

}