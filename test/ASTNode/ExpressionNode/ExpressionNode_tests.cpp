//
// Created by John on 4/17/2023.
//
#include <gtest/gtest.h>

#include <ASTNode/FactorNode/NumberNode/NumberNode.h>
#include <ASTNode/OperatorNode/BinaryOperatorNode/AddNode/AddNode.h>
#include "../source/ASTNode/ExpressionNode/ExpressionNode.cpp"


TEST(ExpressionNodeTest, EvaluateTest)
{
// 1. Setup

auto factor1 = std::make_shared<FactorNode>(std::make_shared<NumberNode<int>>(Token(TokenType::NUMBER, "2"), 2), Token(TokenType::NUMBER, "2"));
auto factor2 = std::make_shared<FactorNode>(std::make_shared<NumberNode<int>>(Token(TokenType::NUMBER, "3"), 3), Token(TokenType::NUMBER, "3"));
auto plusOp = std::make_shared<AddNode<FactorNode>>(factor1, factor2);
auto expr = std::make_shared<ExpressionNode>(plusOp->getToken());

// 2. Exercise
auto result = expr->toString();

// 3. Verify
EXPECT_EQ(result, "2+3");
}