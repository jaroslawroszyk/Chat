#ifndef CHAT_USER_HPP
#define CHAT_USER_HPP
#include "string"
//#include <nlohmann/json.hpp>;
class UserModel{
public:

    UserModel(int index, std::string login, std::string password, std::string email, int phoneNumber);


    [[nodiscard]] std::string getLogin() const;

    [[nodiscard]] int getIndex() const;

    [[nodiscard]] std::string getPassword() const;

    [[nodiscard]] std::string getEmail() const;

    [[nodiscard]] int getPhoneNumber() const;

private:
    int index;
    std::string login;
    std::string password;
    std::string email;
    int phoneNumber;



};
#endif // CHAT_USER_HPP
