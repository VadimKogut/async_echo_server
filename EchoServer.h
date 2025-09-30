#ifndef ASYNC_ECHO_SERVER_ECHOSERVER_H
#define ASYNC_ECHO_SERVER_ECHOSERVER_H

#include <iostream>

#include <boost/asio.hpp>
#include "Session.h"

class EchoServer {
public:
    explicit EchoServer(boost::asio::io_context& context, short port);
private:
    void do_accept();

    boost::asio::ip::tcp::acceptor acceptor_;
};


#endif //ASYNC_ECHO_SERVER_ECHOSERVER_H
