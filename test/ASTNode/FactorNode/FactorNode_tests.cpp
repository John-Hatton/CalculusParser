//
// Created by John on 4/17/2023.
//

#include <gtest/gtest.h>
#include "ASTNode/FactorNode/NumberNode/NumberNode.h"
#include "../source/ASTNode/FactorNode/FactorNode.cpp"


TEST(FactorNodeTest, InitTest)
{
    // 1. Setup
    auto num1 = std::make_shared<NumberNode<int>>(Token(TokenType::NUMBER, "2"), 2);

    auto factor1 = std::make_shared<FactorNode>(num1);

    EXPECT_EQ(factor1->toString(), "2");
}

TEST(FactorNodeTest, DoubleTest)
{
    // 1. Setup
    auto num1 = std::make_shared<NumberNode<double>>(Token(TokenType::NUMBER, "2.5"), 2.5);

    auto factor1 = std::make_shared<FactorNode>(num1);

    EXPECT_EQ(factor1->toString(), "2.5");
}