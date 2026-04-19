//
// Created by John on 4/19/2026.
// Template implementation file for NumberNode class
//

#ifndef CALCULUSPARSER_NUMBERNODE_TPP
#define CALCULUSPARSER_NUMBERNODE_TPP

#include <ASTNode/FactorNode/NumberNode/NumberNode.hpp>

template<typename T>
NumberNode<T>::NumberNode(Token token, T value) : FactorNode(std::move(token), FactorType::NUMBER,
                                                             Token(token.getType(), token.getLexeme())), value(value) {}

template<typename T>
T NumberNode<T>::getValue() const {
    return value;
}

#endif //CALCULUSPARSER_NUMBERNODE_TPP