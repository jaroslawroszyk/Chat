
#include <gtest/gtest.h>
#include "Client.hpp"

namespace IDS
{
    constexpr int FirstID = 1;
}

class ClientsTests : public ::testing::Test
{
};

TEST_F(ClientsTests, ShouldReturnFirstIdClient)
{
    Client firstClient(1);
    EXPECT_EQ(firstClient.getId(), IDS::FirstID);
}

TEST_F(ClientsTests, ShouldCheckCorrectIds)
{
    Client firstClient(21);
    EXPECT_FALSE(firstClient.getId() == IDS::FirstID);
}
