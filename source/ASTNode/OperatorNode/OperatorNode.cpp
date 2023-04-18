//
// Created by John on 4/17/2023.
//

#include <ASTNode/OperatorNode/OperatorNode.h>


OperatorNode::OperatorNode(Token token, std::string symbol) : ASTNode(std::move(token)), symbol(std::move(symbol)) {}

std::string OperatorNode::getSymbol() const {
    return symbol;
}