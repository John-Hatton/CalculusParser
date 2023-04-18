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

#endif //CALCULUSPARSER_VARIABLENODE_H
