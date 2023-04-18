//
// Created by John on 4/18/2023.
//
#include <gtest/gtest.h>

#include <ASTNode/FactorNode/NumberNode/NumberNode.h>
#include <ASTNode/OperatorNode/OperatorNode.h>
#include "../source/ASTNode/TermNode/TermNode.cpp"

TEST (TermNodeTests, Initialization_Test)
{

    // 1. Setup
    auto num1 = std::make_shared<NumberNode<int>>(Token(TokenType::NUMBER, "2"), 2);
    auto num2 = std::make_shared<NumberNode<int>>(Token(TokenType::NUMBER, "3"), 3);
    auto op = std::make_shared<MultiplyNode>(Token(TokenType::MULTIPLY, "*"), "*");
    auto term = std::make_shared<TermNode>(num1);

    // 2. Test multiplication
    term->addFactor(op, num2);
    EXPECT_EQ(term->evaluate(), 6);

    // 3. Test division
    auto num3 = std::make_shared<NumberNode<double>>(Token(TokenType::NUMBER, "4.0"), 4.0);
    auto num4 = std::make_shared<NumberNode<double>>(Token(TokenType::NUMBER, "2.0"), 2.0);
    auto op2 = std::make_shared<DivideNode>(Token(TokenType::DIVIDE, "/"), "/");
    auto term2 = std::make_shared<TermNode<double>>(num3);
    term2->addFactor(op2, num4);
    EXPECT_EQ(term2->evaluate(), 2.0);


    EXPECT_EQ(1,1);
}