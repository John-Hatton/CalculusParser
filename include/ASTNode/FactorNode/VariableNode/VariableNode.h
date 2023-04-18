//
// Created by John on 4/17/2023.
//
#ifndef CALCULUSPARSER_VARIABLENODE_H
#define CALCULUSPARSER_VARIABLENODE_H

#include "ASTNode/FactorNode/FactorNode.h"

class VariableNode : public FactorNode {
public:
    VariableNode(Token token, std::string name);
    virtual ~VariableNode() = default;

    std::string getName() const;

private:
    std::string name;
};

/**
 * Constructor for the VariableNode class.
 *
 * @param token The token associated with the variable.
 * @param name The name of the variable.
 */
VariableNode::VariableNode(Token token, std::string name) : FactorNode(std::move(token), FactorType::VARIABLE), name(std::move(name)) {}

/**
 * Gets the name of the variable.
 *
 * @return The name of the variable.
 */
std::string VariableNode::getName() const {
    return name;
}

#endif //CALCULUSPARSER_VARIABLENODE_H
