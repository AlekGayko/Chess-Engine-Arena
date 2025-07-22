#ifndef ENGINE_H
#define ENGINE_H

#define BOOST_ASIO_DISABLE_CO_COMPOSE

#include <winsock2.h>
#include <ws2tcpip.h>
#include <boost/process.hpp>

#include <string>
#include <string_view>
#include <memory>
#include <vector>

namespace ChessEngineArena {

    namespace bp = boost::process;
    namespace asio = boost::asio;

    class Engine {
    public:
        Engine(std::string_view binPath);
        ~Engine();

        std::string getBestMove(int moveTime);
        std::string getBestMove(int wTime, int bTime, int wInc, int bInc);
        void updatePosition(std::string_view fen, std::vector<std::string>& moves);
    private:
        asio::io_context ctx;
        std::unique_ptr<bp::popen> eng;

        void writeToEngine(std::string_view command);
        std::string readFromEngine();

        std::string getBestMove();
    };

}

#endif ENGINE_H