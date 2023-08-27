#pragma once

#include <string>
#include <vector>
#include "UserModel.hpp"

class MessageModel
{
public:
    MessageModel(UserModel Sender, std::vector<MessageModel> ReciverGroup);

    std::string getSender();

    std::string getReciver();

    bool isRecived();
};

