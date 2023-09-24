#include <iostream>
#include <boost/asio.hpp>
#include "Client.hpp"

int main()
{
    try
    {
        boost::asio::io_context ioContext;

        std::string serverHost = "localhost";
        std::string serverPort = "8888";

        Client client(ioContext, serverHost, serverPort);
        client.run();

        ioContext.run();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
