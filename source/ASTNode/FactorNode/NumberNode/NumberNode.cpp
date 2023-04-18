//
// Created by John on 4/17/2023.
//

#include "ASTNode/FactorNode/NumberNode/NumberNode.h"


template<typename T>
NumberNode<T>::NumberNode(Token token, T value) : FactorNode(std::move(token), FactorType::NUMBER), value(value) {}



template<typename T>
T NumberNode<T>::getValue() const {
    return value;
}