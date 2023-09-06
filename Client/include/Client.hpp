#pragma once

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <thread>
#include <atomic>

using tcp = boost::asio::ip::tcp;
namespace ws = boost::beast::websocket;

class Client
{
public:
    Client(boost::asio::io_context&, const std::string& serverHost, const std::string& serverPort);

    void run();

private:
    auto handleUserInput(ws::stream<tcp::socket>&) -> void;
    auto receiveMessages(ws::stream<tcp::socket>&) -> void;

    boost::asio::io_context& ioContext;
    tcp::resolver resolver;
    std::string serverHost;
    std::string serverPort;
    std::atomic<bool> is_connected;
};
