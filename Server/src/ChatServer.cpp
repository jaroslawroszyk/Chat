#include "../include/Server.hpp"
#include <iostream>
#include <csignal>

namespace
{
    unsigned short port = 8888;
}

auto main() -> int
{
    try
    {
        boost::asio::io_context ioContext;
        Server server(ioContext, port);

        boost::asio::signal_set signals(ioContext, SIGINT);
        //Not work at all Repair this
        signals.async_wait([&](const boost::system::error_code& error_code, int /*signal_number*/)
            {
                if (not error_code)
                {
                    std::cout << "Received Ctrl+C. Shutting down the server..." << std::endl;
                    server.stop();
                }
            });

        server.start();
        ioContext.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}