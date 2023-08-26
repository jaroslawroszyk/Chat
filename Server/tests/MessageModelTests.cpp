//
// Created by barti on 15.08.2023.
//
#include <gtest/gtest.h>
#include "../include/MessageModel.hpp"



TEST_F(MessageModelTest, messageModelConstruktor)
{
    MessageModel message();

    EXPECT_EQ("Bartek", message.getSender());
    EXPECT_EQ("Nina", message.getReciver());
}
