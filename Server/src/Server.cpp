#include "Server.hpp"
#include <iostream>
#include "ClientSession.hpp"
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <thread>
#include <atomic>
#include <memory>

using tcp = boost::asio::ip::tcp;
namespace ws = boost::beast::websocket;

Server::Server(boost::asio::io_context& ioContext, unsigned short port)
    : ioContext(ioContext), acceptor(ioContext, tcp::endpoint(tcp::v4(), port)), next_client_id(0)
{
    std::cout << "Server is listening on port 8888..." << std::endl;
}

void Server::start()
{
    while (true)
    {
        tcp::socket socket(ioContext);
        acceptor.accept(socket);

        int client_id = next_client_id++;
        auto client = std::make_shared<ClientSession>(client_id, std::move(socket));
        std::thread(&Server::handleSession, this, client).detach();
    }
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
