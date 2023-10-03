#pragma once

#include "ClientSession.hpp"
#include <atomic>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <memory>
#include <iostream>
#include <unordered_set>

using tcp = boost::asio::ip::tcp;
namespace ws = boost::beast::websocket;

class Server
{
public:
    Server(boost::asio::io_context&, unsigned short port);
    ~Server();

    void start();
    void stop();
    void disconnectClients()
    {
        for (auto& client : clients)
        {
            try
            {
                client->disconnect();  // Implement this method in your ClientSession class
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error disconnecting client: " << e.what() << std::endl;
            }
        }
    }

private:
    boost::asio::io_context& ioContext;
    tcp::acceptor acceptor;
    std::atomic<int> next_client_id;
    std::atomic<bool> is_running;
    std::vector<std::thread> threads;
    std::unordered_set<std::shared_ptr<ClientSession>> clients;

    void handleSession(std::shared_ptr<ClientSession>);
};
