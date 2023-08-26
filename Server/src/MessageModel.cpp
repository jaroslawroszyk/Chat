#include "../include/MessageModel.hpp"

bool MessageModel::isRecived() {
    return false;
}

std::string MessageModel::getReciver() {
    return std::string();
}

std::string MessageModel::getSender() {
    return std::string();
}

MessageModel::MessageModel(UserModel Sender, std::vector<MessageModel> ReciverGroup) {

}
