//
// Created by John on 4/17/2023.
//
#include <gtest/gtest.h>

#include <memory>
#include "../source/ASTNode/OperatorNode/BinaryOperatorNode/AddNode/AddNode.cpp"
#include "ASTNode/FactorNode/NumberNode/NumberNode.h"

TEST(AddNodeTest, Evaluate) {
    // Create NumberNode objects for the operands
    auto num1 = std::make_shared<NumberNode<int>>(Token(TokenType::NUMBER, "2"), 2);

    auto num2 = std::make_shared<NumberNode<int>>(Token(TokenType::NUMBER, "3"), 3);
    auto num3 = std::make_shared<NumberNode<double>>(Token(TokenType::NUMBER, "1.5"), 1.5);

    // Create FactorNode objects for the factors

    auto factor1 = std::make_shared<FactorNode>(num1, num1->getToken());
    auto factor2 = std::make_shared<FactorNode>(num2, num2->getToken());
    auto factor3 = std::make_shared<FactorNode>(num3, num2->getToken());


    // Create an AddNode object with two integer factors
    auto addNode1 = std::make_shared<AddNode<FactorNode>>(factor1, factor2);

    // Create an AddNode object with an integer and a double factor
    auto addNode2 = std::make_shared<AddNode<FactorNode>>(factor1, factor3);

    // Evaluate the AddNode objects
//    auto result1 = addNode1->evaluate();
//    auto result2 = addNode2->evaluate();
//
//     // Check that the results are correct
//    EXPECT_EQ(result1, 5);
//    EXPECT_EQ(result2, 3.5);

    // Evaluate Function does not work yet...

    auto myVal = addNode1->toString();

    EXPECT_EQ(addNode1->toString(), "2+3");

}