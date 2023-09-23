#include "ClientSession.hpp"
#include "Server.hpp"
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <iostream>
#include <memory>
#include <thread>

using tcp = boost::asio::ip::tcp;
namespace ws = boost::beast::websocket;

Server::Server(boost::asio::io_context& ioContext, unsigned short port)
    : ioContext(ioContext), acceptor(ioContext, tcp::endpoint(tcp::v4(), port)), next_client_id(0), is_running(true)
{
    std::cout << "Server is listening on port: " << port << std::endl;
}

Server::~Server()
try
{
    acceptor.cancel();
    acceptor.close();
    is_running.store(false, std::memory_order_relaxed);
    for (auto& thread : threads)
    {
        if (thread.joinable())
        {
            thread.join();
        }
    }
}
catch (const std::exception& e)
{
    std::cerr << "Error in Server destructor: " << e.what() << std::endl;
}

void Server::start()
{
    while (is_running.load(std::memory_order_relaxed))
    {
        tcp::socket socket(ioContext);
        boost::system::error_code ec;

        acceptor.accept(socket, ec);
        if (ec == boost::asio::error::operation_aborted)
        {
            break;
        }

        int client_id = next_client_id++;
        auto client = std::make_shared<ClientSession>(client_id, std::move(socket));
        threads.emplace_back([client]
            {
                try
                {
                    client->handleCommunication();
                }
                catch (const std::exception& e)
                {
                    std::cerr << "Exception in session: " << e.what() << std::endl;
                }
            });
    }

    for (auto& thread : threads)
    {
        thread.join();
    }
}

void Server::stop()
{
    is_running.store(false, std::memory_order_relaxed);
    acceptor.cancel();
}

void Server::handleSession(std::shared_ptr<ClientSession> client)
try
{
    client->handleCommunication();
}
catch (const std::exception& e)
{
    std::cerr << "Exception in session: " << e.what() << std::endl;
}