#ifndef TYPES_H
#define TYPES_H

namespace ChessEngineArena {

    enum Page : int {
        HOME,
        CONFIG,
        TOURNAMENT
    };

    constexpr int DEFAULT_TOURNAMENT_SIZE = 10;
    constexpr int MIN_TOURNAMENT_SIZE = 1;
    constexpr int MAX_TOURNAMENT_SIZE = 1000;

    constexpr double DEFAULT_MOVETIME = 1.0;
    constexpr double MIN_MOVETIME = 0.1;
    constexpr double MAX_MOVETIME = 60.0;

}

#endif