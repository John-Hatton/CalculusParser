//
// Created by John on 4/17/2023.
//

#ifndef CALCULUSPARSER_NUMBERNODE_H
#define CALCULUSPARSER_NUMBERNODE_H

#include "ASTNode/FactorNode/FactorNode.h"

/**
 * A class representing a number in the abstract syntax tree.
 * The value of the number can be of any type T.
 *
 * @tparam T The type of the number value.
 */
template<typename T>
class NumberNode : public FactorNode {
public:
    /**
     * Constructs a NumberNode with the specified token and value.
     *
     * @param token The token representing the number.
     * @param value The value of the number.
     */
    NumberNode(Token token, T value);

    virtual ~NumberNode() = default;

    /**
     * Gets the value of the number.
     *
     * @return The value of the number.
     */
    T getValue() const;

private:
    T value;
};

template class NumberNode<int>;
template class NumberNode<double>;

#endif //CALCULUSPARSER_NUMBERNODE_H
