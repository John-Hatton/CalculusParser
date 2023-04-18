//
// Created by John on 4/18/2023.
//
#include <ASTNode/OperatorNode/BinaryOperatorNode/MultiplyNode/MultiplyNode.h>
#include <sstream>


template<typename T>
T MultiplyNode<T>::evaluate() {
    //auto left = std::dynamic_pointer_cast<FactorNode>(getLeftChild())->evaluate();
//    auto left = getLeftChild()->evaluate();
//    auto right = getRightChild()->evaluate();
    return -1;
}

template<typename T>
std::string MultiplyNode<T>::toString() const {

    std::stringstream ss;

    // Get Left Child lexeme
    ss << getLeftChild().get()->getMyToken().getLexeme();

    ss << token.getLexeme();

    // Get Right Child lexeme
    ss << getRightChild().get()->getMyToken().getLexeme();


    return ss.str();
}