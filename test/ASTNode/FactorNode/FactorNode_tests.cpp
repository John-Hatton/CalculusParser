//
// Created by John on 4/17/2023.
//

#include <gtest/gtest.h>
#include "ASTNode/FactorNode/NumberNode/NumberNode.h"
#include "ASTNode/FactorNode/VariableNode/VariableNode.h"
#include "../source/ASTNode/FactorNode/FactorNode.cpp"



TEST(FactorNodeTest, InitTest)
{
    // 1. Setup
    auto num1 = std::make_shared<NumberNode<int>>(Token(TokenType::NUMBER, "2"), 2);

    auto factor1 = std::make_shared<FactorNode>(num1, num1->getToken());

    EXPECT_EQ(factor1->toString(), "2");
}

TEST(FactorNodeTest, DoubleTest)
{
    // 1. Setup
    auto num1 = std::make_shared<NumberNode<double>>(Token(TokenType::NUMBER, "2.5"), 2.5);

    auto factor1 = std::make_shared<FactorNode>(num1,num1->getToken());

    EXPECT_EQ(factor1->toString(), "2.5");
}

TEST(FactorNodeTest, VariableTest)
{
    // 1. Setup

    auto var1 = std::make_shared<VariableNode>(Token(TokenType::VARIABLE, "x"), "x");

    auto factor1 = std::make_shared<FactorNode>(var1, var1->getToken());

    auto myFact = new FactorNode(var1, Token(var1->getTokenType(),var1->toString()));

    auto factorToken = factor1->getMyToken().getType();

    EXPECT_EQ(factor1->toString(), "x");
}