//
// Created by John on 4/18/2023.
//

#ifndef CALCULUSPARSER_DIVIDENODE_H
#define CALCULUSPARSER_DIVIDENODE_H


#include <ASTNode/OperatorNode/BinaryOperatorNode/BinaryOperatorNode.h>
#include <ASTNode/FactorNode/FactorNode.h>

template<typename T>
class DivideNode : public BinaryOperatorNode {
public:

    DivideNode(std::shared_ptr<FactorNode> leftChild, std::shared_ptr<FactorNode> rightChild)
            : BinaryOperatorNode(Token(TokenType::DIVIDE, "/"), "/") {
        setLeftChild(leftChild);
        setRightChild(rightChild);
    }

    T evaluate();

    std::string toString() const override;
};

#endif //CALCULUSPARSER_DIVIDENODE_H
