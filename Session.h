//
// Created by vadim on 01.10.2025.
//

#ifndef ASYNC_ECHO_SERVER_SESSION_H
#define ASYNC_ECHO_SERVER_SESSION_H

#include <iostream>
#include <boost/asio.hpp>

class session : public std::enable_shared_from_this<session>{
public:
    explicit session(boost::asio::ip::tcp::socket socket);
    void start();

private:
    void do_read();
    void do_write(size_t length);

    boost::asio::ip::tcp::socket socket_;
    enum {max_length = 1024};
    char data_[max_length];
};


#endif //ASYNC_ECHO_SERVER_SESSION_H
