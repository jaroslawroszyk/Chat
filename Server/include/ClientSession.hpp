#pragma once

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <memory>
#include <iostream>

using tcp = boost::asio::ip::tcp;
namespace ws = boost::beast::websocket;

struct ClientSession : public std::enable_shared_from_this<ClientSession>
{
    ClientSession(int clientId, tcp::socket);
    auto handleCommunication() -> void;
    auto getClientId() -> int;
    void start();
    void disconnect()
    {
        try
        {
            websocket.close(ws::close_code::normal);
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error during client disconnect: " << e.what() << std::endl;
        }
    }

private:
    int clientId;
    ws::stream<tcp::socket> websocket;
    auto runSession() -> void;
};
