#ifndef CALCULUSPARSER_ADDNODE_HPP
#define CALCULUSPARSER_ADDNODE_HPP

#include <ASTNode/OperatorNode/BinaryOperatorNode/BinaryOperatorNode.hpp>
#include <ASTNode/FactorNode/FactorNode.hpp>

template<typename T>
class AddNode : public BinaryOperatorNode {
public:

    AddNode(std::shared_ptr<FactorNode> leftChild, std::shared_ptr<FactorNode> rightChild)
            : BinaryOperatorNode(Token(TokenType::ADD, "+"), "+") {
        setLeftChild(leftChild);
        setRightChild(rightChild);
    }

    T evaluate();

    std::string toString() const override;
};


#include "AddNode.tpp"

#endif //CALCULUSPARSER_ADDNODE_HPP
