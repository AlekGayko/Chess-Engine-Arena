#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string_view>

namespace ChessEngineArena {
    
    class GameManager {
    public:
        GameManager(std::string_view whiteBinPath, std::string_view blackBinPath);
        ~GameManager();
    private:
    };

}

#endif