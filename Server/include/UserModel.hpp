#pragma once

#include "string"

class UserModel
{
public:
    UserModel(int, std::string, std::string, std::string, int);

    [[nodiscard]] auto getLogin() const -> std::string;
    [[nodiscard]] auto getIndex() const -> int;
    [[nodiscard]] auto getPassword() const -> std::string;
    [[nodiscard]] auto getEmail() const -> std::string;
    [[nodiscard]] auto getPhoneNumber() const -> int;

private:
    int index;
    std::string login;
    std::string password;
    std::string email;
    int phoneNumber;
};
