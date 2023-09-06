#include <iostream>
#include "Server.hpp"
#include <boost/asio.hpp>

namespace
{
    unsigned short port = 8888;
}

int main()
{
    try
    {
        boost::asio::io_context ioContext;
        Server server(ioContext, port);
        server.start();
        ioContext.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
