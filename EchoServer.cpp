#include "EchoServer.h"

EchoServer::EchoServer(boost::asio::io_context &context, short port)
: acceptor_(context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {
    do_accept();
    std::cout << "Echo server initialized on port " << port << std::endl;
}

void EchoServer::do_accept() {
    acceptor_.async_accept(
            [this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket){
               if(!ec){
                   std::make_shared<session>(std::move(socket))->start();
               }
               do_accept();
            });
}