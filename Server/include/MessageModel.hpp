#ifndef CHAT_MESSAGEMODEL_HPP
#define CHAT_MESSAGEMODEL_HPP

#include <string>
#include <vector>
#include "UserModel.hpp"

class MessageModel{
    std::vector
public:
    MessageModel(UserModel Sender, std::vector<MessageModel> ReciverGroup);

    std::string getSender();

    std::string getReciver();

    bool isRecived();



};

#endif // CHAT_MESSAGEMODEL_HPP
