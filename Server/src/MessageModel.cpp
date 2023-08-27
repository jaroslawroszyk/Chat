#include "../include/MessageModel.hpp"

MessageModel::MessageModel(UserModel Sender, std::vector<MessageModel> ReciverGroup)
{
}

auto MessageModel::isRecived() -> bool
{
    return false;
}

auto MessageModel::getReciver() -> std::string
{
    return std::string();
}

auto MessageModel::getSender() -> std::string
{
    return std::string();
}
