#include <iostream>
#include "Client.hpp"

Client::Client() : id(0) {}

Client::Client(int id) : id(id) {}

auto Client::print() -> void
{
    std::cout << "Hello I'm a Client";
}

auto Client::getId() -> int
{
    return id;
}
