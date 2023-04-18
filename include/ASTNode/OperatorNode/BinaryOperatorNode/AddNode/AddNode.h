#ifndef CALCULUSPARSER_ADDNODE_H
#define CALCULUSPARSER_ADDNODE_H

#include <ASTNode/OperatorNode/BinaryOperatorNode/BinaryOperatorNode.h>
#include <ASTNode/FactorNode/FactorNode.h>

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



#endif //CALCULUSPARSER_ADDNODE_H
