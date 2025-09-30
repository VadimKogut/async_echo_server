//
// Created by vadim on 01.10.2025.
//

#include "Session.h"

session::session(boost::asio::ip::tcp::socket socket): socket_(std::move(socket)){};

void session::start() {
    // Начинаем асинхронное чтение сразу после создания сессии
    do_read();

    std::cout << "Session started for client: "
              << socket_.remote_endpoint().address().to_string()
              << ":" << socket_.remote_endpoint().port() << std::endl;
}

void session::do_read() {
    auto self(shared_from_this());
    socket_.async_read_some(
            boost::asio::buffer(data_,max_length),
            [this,self](boost::system::error_code ec, std::size_t length){
                 if(!ec){
                     do_write(length);
                 }
            });
}

void session::do_write(size_t length) {
    auto self(shared_from_this());
    boost::asio::async_write(
            socket_,
            boost::asio::buffer(data_,length),
            [this,self](boost::system::error_code ec, std::size_t  ){
                if(!ec){
                    do_read();
                }
            });
}