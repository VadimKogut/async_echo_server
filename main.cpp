#include <iostream>

#include "EchoServer.h"

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: async_echo_server <port>\n";
            return 1;
        }

        boost::asio::io_context io_context;
        EchoServer server(io_context, std::atoi(argv[1]));

        std::cout << "Echo server listening on port " << argv[1] << std::endl;
        io_context.run();

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}