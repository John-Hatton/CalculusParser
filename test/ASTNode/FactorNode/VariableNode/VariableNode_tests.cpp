//
// Created by John on 4/17/2023.
//
#include <gtest/gtest.h>
#include "../source/ASTNode/FactorNode/VariableNode/VariableNode.cpp"


TEST(VariableNodeTest, InitTest)
{
    // 1. Setup
    auto var1 = std::make_shared<VariableNode>(Token(TokenType::VARIABLE, "x"), "x");

    EXPECT_EQ(var1->getName(), "x");
}