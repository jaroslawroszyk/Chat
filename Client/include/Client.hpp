#pragma once

//Todo: Should be a CLASS
struct Client
{
    int id;
    Client(int);
    Client();
    auto print() -> void;
    auto getId() -> int;
};