#pragma once

#include "ClientSession.hpp"
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <atomic>
#include <memory>

using tcp = boost::asio::ip::tcp;
namespace ws = boost::beast::websocket;

class Server
{
public:
    Server(boost::asio::io_context&, unsigned short port);
    void start();

private:
    boost::asio::io_context& ioContext;
    tcp::acceptor acceptor;
    std::atomic<int> next_client_id;

    void handleSession(std::shared_ptr<ClientSession>);
};
