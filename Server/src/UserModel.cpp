#include <utility>

#include "../include/UserModel.hpp"

UserModel::UserModel(int index, std::string login, std::string password, std::string email, int phoneNumber) : index(index), login(login), password(password), email(email), phoneNumber(phoneNumber)
{
}

auto UserModel::getLogin() const -> std::string
{
    return login;
}

auto UserModel::getIndex() const -> int
{
    return index;
}

auto UserModel::getPassword() const -> std::string
{
    return password;
}

auto UserModel::getEmail() const -> std::string
{
    return email;
}

auto UserModel::getPhoneNumber() const -> int
{
    return phoneNumber;
}
