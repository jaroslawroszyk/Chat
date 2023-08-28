#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <iostream>

namespace net = boost::asio;
namespace http = boost::beast::http;
using tcp = boost::asio::ip::tcp;

auto handle_request(tcp::socket& socket) -> void
{
    http::response<http::string_body> response;
    response.version(11);
    response.result(http::status::ok);
    response.set(http::field::server, "Server");
    response.set(http::field::content_type, "text/html");
    response.body() = "Hello, I'm an Asio and Beast server";
    response.prepare_payload();

    http::write(socket, response);
}

/*
    How it works?
    open web browser and type:
    localhost:8080 or http://127.0.0.1:8080/
*/
auto main() -> int
{
    net::io_context ioc;
    constexpr int PORT = 8080;
    tcp::acceptor acceptor(ioc, tcp::endpoint(tcp::v4(), PORT));

    while (true)
    {
        tcp::socket socket(ioc);
        acceptor.accept(socket);

        handle_request(socket);

        boost::system::error_code ec;
        socket.shutdown(tcp::socket::shutdown_send, ec);
    }

    return 0;
}
