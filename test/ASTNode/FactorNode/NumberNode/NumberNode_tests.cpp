//
// Created by John on 4/17/2023.
//
#include <gtest/gtest.h>
#include "../source/ASTNode/FactorNode/NumberNode/NumberNode.cpp"


TEST(NumberNodeTest, InitTest)
{
    // 1. Setup
    auto num1 = std::make_shared<NumberNode<int>>(Token(TokenType::NUMBER, "2"), 2);

    EXPECT_EQ(num1->getValue(), 2);
}

TEST(NumberNodeTest, DoubleTest)
{
    // 1. Setup
    auto num1 = std::make_shared<NumberNode<int>>(Token(TokenType::NUMBER, "2.5"), 2.5);

    EXPECT_EQ(num1->getValue(), 2.5);
}