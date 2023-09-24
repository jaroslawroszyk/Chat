#include "Client.hpp"

#include <iostream>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <thread>

Client::Client(boost::asio::io_context& ioContext, const std::string& serverHost, const std::string& serverPort)
    : ioContext(ioContext), resolver(ioContext), serverHost(serverHost), serverPort(serverPort), isConnected(true)
{
}

auto Client::run() -> void
try
{
    tcp::resolver::results_type endpoints = resolver.resolve(serverHost, serverPort);
    tcp::socket socket(ioContext);

    boost::asio::connect(socket, endpoints);

    ws::stream<tcp::socket> websocket(std::move(socket));
    websocket.handshake(serverHost, "/");

    std::thread(&Client::receiveMessages, this, std::ref(websocket)).detach();

    handleUserInput(websocket);

}
catch (const std::exception& e)
{
    std::cerr << "Client error: " << e.what() << std::endl;
}

auto Client::handleUserInput(ws::stream<tcp::socket>& websocket) -> void
{
    while (isConnected.load())
    {
        std::string message{};
        std::cout << "Enter a message to send (or 'quit' to exit): ";
        std::cin >> message;

        if (message == "quit")
        {
            isConnected.store(false);
            break;
        }

        websocket.text(true);
        websocket.write(boost::asio::buffer(message));
    }
}

auto Client::receiveMessages(ws::stream<tcp::socket>& websocket) -> void
try
{
    while (isConnected.load())
    {
        boost::beast::flat_buffer buffer;
        websocket.read(buffer);

        if (websocket.got_text())
        {
            std::string message = boost::beast::buffers_to_string(buffer.data());
            std::cout << "Received message: " << message << std::endl;
        }
    }
}
catch (const boost::beast::websocket::close_reason& reason)
{
    if (isConnected.load())
    {
        std::cerr << "WebSocket connection closed: " << reason.reason << std::endl;
        isConnected.store(false);
    }
}
catch (const std::exception& e)
{
    if (isConnected.load())
    {
        std::cerr << "WebSocket receive error: " << e.what() << std::endl;
        isConnected.store(false);
    }
}
