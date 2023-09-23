#pragma once

#include "ClientSession.hpp"
#include <atomic>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <memory>

using tcp = boost::asio::ip::tcp;
namespace ws = boost::beast::websocket;

class Server
{
public:
    Server(boost::asio::io_context&, unsigned short port);
    ~Server();

    void start();
    void stop();

private:
    boost::asio::io_context& ioContext;
    tcp::acceptor acceptor;
    std::atomic<int> next_client_id;
    std::atomic<bool> is_running;
    std::vector<std::thread> threads;

    void handleSession(std::shared_ptr<ClientSession>);
};
