#include <utility>

#include "../include/UserModel.hpp"

UserModel::UserModel(int index, std::string login, std::string password, std::string email, int phoneNumber) {
    this -> index = index;
    this -> login = std::move(login);
    this -> password = std::move(password);
    this -> email = std::move(email);
    this -> phoneNumber = phoneNumber;

}

std::string UserModel::getLogin() const {

    return login;
}

int UserModel::getIndex() const {
    return index;
}

std::string UserModel::getPassword() const {
    return password;
}

std::string UserModel::getEmail() const {
    return email;
}

int UserModel::getPhoneNumber() const {
    return phoneNumber;
}

