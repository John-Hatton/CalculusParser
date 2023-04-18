//
// Created by John on 4/17/2023.
//

#include "ASTNode/FactorNode/VariableNode/VariableNode.h"

/**
 * Constructor for the VariableNode class.
 *
 * @param token The token associated with the variable.
 * @param name The name of the variable.
 */
VariableNode::VariableNode(Token token, std::string name) : FactorNode(std::move(token), FactorType::VARIABLE,
                                                                       Token(token.getType(), token.getLexeme())), name(std::move(name)) {}

/**
 * Gets the name of the variable.
 *
 * @return The name of the variable.
 */
std::string VariableNode::getName() const {
    return name;
}