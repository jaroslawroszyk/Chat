#include "ClientSession.hpp"
#include <iostream>
#include <memory>

ClientSession::ClientSession(int clientId, tcp::socket socket)
    : clientId(clientId), websocket(std::move(socket))
{
    websocket.accept();
}

auto ClientSession::handleCommunication() -> void
{
    std::thread(&ClientSession::runSession, shared_from_this()).detach();
}

auto ClientSession::runSession() -> void
try
{
    while (true)
    {
        boost::beast::flat_buffer buffer;
        websocket.read(buffer);

        if (websocket.got_text())
        {
            std::string message = boost::beast::buffers_to_string(buffer.data());
            std::cout << "Received message from client " << getClientId() << ": " << message << std::endl;

            websocket.text(true);
            websocket.write(buffer.data());
        }
    }
}
catch (const std::exception& e)
{
    std::cerr << "WebSocket session error for client " << getClientId() << ": " << e.what() << std::endl;
}

auto ClientSession::getClientId() -> int
{
    return clientId;
}
