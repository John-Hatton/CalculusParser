//
// Created by John on 4/17/2023.
//
#ifndef CALCULUSPARSER_VARIABLENODE_HPP
#define CALCULUSPARSER_VARIABLENODE_HPP

#include <ASTNode/FactorNode/FactorNode.hpp>

class VariableNode : public FactorNode {
public:
    VariableNode(Token token, std::string name);
    virtual ~VariableNode() = default;

    std::string getName() const;

private:
    std::string name;
};

#endif //CALCULUSPARSER_VARIABLENODE_HPP
