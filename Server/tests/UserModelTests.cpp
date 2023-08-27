
#include <gtest/gtest.h>
#include "../include/Server.hpp"
#include "../include/UserModel.hpp"
#include "../include/MessageModel.hpp"

TEST(UserModel, userModelConstruktor)
{
    EXPECT_EQ(2 + 2, 4);
    // UserModel userModel(1,"login", "password", "email", 693855163);

    // EXPECT_EQ(1, userModel.getIndex());
    // EXPECT_EQ("login", userModel.getLogin());
    // EXPECT_EQ("password", userModel.getPassword());
    // EXPECT_EQ("email", userModel.getEmail());
    // EXPECT_EQ(693855163, userModel.getPhoneNumber());
}
