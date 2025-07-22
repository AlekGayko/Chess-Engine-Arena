#ifndef TYPES_H
#define TYPES_H

namespace ChessEngineArena {

    enum Color : int {
        BLACK,
        WHITE,
        COLOR_NB
    };

    enum Page : int {
        HOME,
        CONFIG,
        TOURNAMENT
    };

    enum GameResult : int {
        BLACK_WIN,
        WHITE_WIN,
        DRAW
    };

    constexpr int DEFAULT_TOURNAMENT_SIZE = 1;
    constexpr int MIN_TOURNAMENT_SIZE = 1;
    constexpr int MAX_TOURNAMENT_SIZE = 1000;

    constexpr double DEFAULT_MOVETIME = 1.0;
    constexpr double MIN_MOVETIME = 0.1;
    constexpr double MAX_MOVETIME = 60.0;

}

#endif