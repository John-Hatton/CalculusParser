//
// Created by John on 4/17/2023.
//

#ifndef CALCULUSPARSER_OPERATORNODE_H
#define CALCULUSPARSER_OPERATORNODE_H

#include "ASTNode/ASTNode.h"
#include <string>

/**
 * Represents an operator in the abstract syntax tree.
 */
class OperatorNode : public ASTNode {
public:
    /**
     * Constructs an OperatorNode with the specified token and symbol.
     *
     * @param token The token representing the operator.
     * @param symbol The symbol for the operator.
     */
    OperatorNode(Token token, std::string symbol);
    virtual ~OperatorNode() = default;

    /**
     * Returns the symbol for the operator.
     *
     * @return The symbol for the operator.
     */
    std::string getSymbol() const;

private:
    std::string symbol; /**< The symbol for the operator. */
};

#endif //CALCULUSPARSER_OPERATORNODE_H

