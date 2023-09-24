#pragma once

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <memory>

using tcp = boost::asio::ip::tcp;
namespace ws = boost::beast::websocket;

struct ClientSession : public std::enable_shared_from_this<ClientSession>
{
    ClientSession(int clientId, tcp::socket);
    auto handleCommunication() -> void;
    auto getClientId() -> int;
    void start();

private:
    int clientId;
    ws::stream<tcp::socket> websocket;
    auto runSession() -> void;
};
