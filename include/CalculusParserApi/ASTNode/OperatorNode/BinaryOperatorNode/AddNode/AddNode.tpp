//
// Created by John on 4/19/2026.
// Template implementation file for AddNode class
//

#ifndef CALCULUSPARSER_ADDNODE_TPP
#define CALCULUSPARSER_ADDNODE_TPP

#include <ASTNode/OperatorNode/BinaryOperatorNode/AddNode/AddNode.hpp>
#include <sstream>

template<typename T>
T AddNode<T>::evaluate() {
    //auto left = std::dynamic_pointer_cast<FactorNode>(getLeftChild())->evaluate();
//    auto left = getLeftChild()->evaluate();
//    auto right = getRightChild()->evaluate();
    return -1;
}

template<typename T>
std::string AddNode<T>::toString() const {

    std::stringstream ss;

    // Get Left Child lexeme
    ss << getLeftChild().get()->getMyToken().getLexeme();

    ss << token.getLexeme();

    // Get Right Child lexeme
    ss << getRightChild().get()->getMyToken().getLexeme();


    return ss.str();
}

#endif //CALCULUSPARSER_ADDNODE_TPP