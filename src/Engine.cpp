#include "Engine.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <format>
#include <sstream>

#include <boost/asio/write.hpp>
#include <boost/asio/read_until.hpp>

namespace ChessEngineArena {

    Engine::Engine(std::string_view binPath) {
        const auto path = boost::filesystem::path(binPath);
        
        eng = std::unique_ptr<bp::popen>(new bp::popen( 
            ctx.get_executor(),
            path,
            {}
        ));
    }

    Engine::~Engine() {
        eng.get()->terminate();
    }

    std::string Engine::getBestMove(int moveTime) { 
        std::string command = std::format("go movetime {} \r\n", moveTime);

        writeToEngine(command);

        return getBestMove();
    }

    std::string Engine::getBestMove(int wTime, int bTime, int wInc, int bInc) {
        std::string command = std::format("go wtime {} btime {} winc {} binc {} \r\n", wTime, bTime, wInc, bInc);

        writeToEngine(command);

        return getBestMove();
    }

    std::string Engine::getBestMove() { 
        std::string move;
        std::string line;

        while (move.empty()) {
            line = readFromEngine();

            std::stringstream ss(line);
            std::string firstWord;
            ss >> firstWord;

            if (firstWord == "info") {
            // info parsing
            }

            if (firstWord != "bestmove") continue;

            ss >> move;
        }

        return move;
    }

    void Engine::updatePosition(std::string_view fen, std::vector<std::string>& moves) {
        std::string command = std::format("position fen {} \r\n", fen);
        if (moves.size() > 0) {
            command += " moves ";

            for (std::string& move : moves) {
                command += move + " ";
            }
        }

        command += "\r\n";

        writeToEngine(command);
    }

    void Engine::writeToEngine(std::string_view command) {
        asio::write(*eng.get(), asio::buffer(command));
    }

    std::string Engine::readFromEngine() { 
        std::string line;
        asio::read_until(*eng.get(), asio::dynamic_buffer(line), '\n');
        return line;
    }

}