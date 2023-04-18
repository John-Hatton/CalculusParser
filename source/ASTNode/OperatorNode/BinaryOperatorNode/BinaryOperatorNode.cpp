//
// Created by John on 4/17/2023.
//

#include "ASTNode/OperatorNode/BinaryOperatorNode/BinaryOperatorNode.h"


BinaryOperatorNode::BinaryOperatorNode(Token token, std::string symbol)
        : OperatorNode(std::move(token), std::move(symbol)), leftChild(nullptr), rightChild(nullptr) {}

std::vector<std::shared_ptr<ASTNode>> BinaryOperatorNode::getChildren() const {
    std::vector<std::shared_ptr<ASTNode>> children;
    if (leftChild) {
        children.push_back(leftChild);
    }
    if (rightChild) {
        children.push_back(rightChild);
    }
    return children;
}

void BinaryOperatorNode::setLeftChild(std::shared_ptr<ASTNode> leftChild) {
    this->leftChild = std::move(leftChild);
}

void BinaryOperatorNode::setRightChild(std::shared_ptr<ASTNode> rightChild) {
    this->rightChild = std::move(rightChild);
}

std::shared_ptr<ASTNode> BinaryOperatorNode::getLeftChild() const {
    return leftChild;
}

std::shared_ptr<ASTNode> BinaryOperatorNode::getRightChild() const {
    return rightChild;
}

template<typename T>
T BinaryOperatorNode::evaluate() const {
    return nullptr;
}
