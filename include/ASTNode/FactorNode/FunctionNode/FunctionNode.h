//
// Created by John on 4/17/2023.
//

#ifndef CALCULUSPARSER_FUNCTIONNODE_H
#define CALCULUSPARSER_FUNCTIONNODE_H

#include "ASTNode/FactorNode/FactorNode.h"
#include <string>

/**
 * FunctionNode class represents a function in the AST.
 * A FunctionNode contains a name and a list of arguments.
 */
class FunctionNode : public FactorNode {
public:
    /**
     * Constructor for the FunctionNode class.
     * @param token Token object containing the function's token information.
     * @param name Name of the function.
     */
    FunctionNode(Token token, std::string name);

    /**
     * Destructor for the FunctionNode class.
     */
    virtual ~FunctionNode() = default;

    /**
     * Getter method for the name of the function.
     * @return The name of the function.
     */
    std::string getName() const;

private:
    std::string name; /**< The name of the function. */
};

/**
 * Implementation of the FunctionNode constructor.
 * @param token Token object containing the function's token information.
 * @param name Name of the function.
 */
FunctionNode::FunctionNode(Token token, std::string name)
        : FactorNode(std::move(token), FactorType::FUNCTION), name(std::move(name)) {}

/**
 * Implementation of the FunctionNode getName method.
 * @return The name of the function.
 */
std::string FunctionNode::getName() const {
    return name;
}

#endif //CALCULUSPARSER_FUNCTIONNODE_H
