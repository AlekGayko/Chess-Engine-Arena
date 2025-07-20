#ifndef ENGINE_H
#define ENGINE_H

#include <atomic>
#include <string_view>

namespace ChessEngineArena {

    class Engine {
    public:
        Engine(std::string_view binPath);
        ~Engine();
    private:
    };

}

#endif ENGINE_H