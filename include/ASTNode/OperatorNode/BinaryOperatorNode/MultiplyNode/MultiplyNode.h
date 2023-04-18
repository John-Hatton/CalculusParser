//
// Created by John on 4/18/2023.
//

#ifndef CALCULUSPARSER_MULTIPLYNODE_H
#define CALCULUSPARSER_MULTIPLYNODE_H


#include <ASTNode/OperatorNode/BinaryOperatorNode/BinaryOperatorNode.h>
#include <ASTNode/FactorNode/FactorNode.h>

template<typename T>
class MultiplyNode : public BinaryOperatorNode {
public:

    MultiplyNode(std::shared_ptr<FactorNode> leftChild, std::shared_ptr<FactorNode> rightChild)
            : BinaryOperatorNode(Token(TokenType::MULTIPLY, "*"), "*") {
        setLeftChild(leftChild);
        setRightChild(rightChild);
    }

    T evaluate();

    std::string toString() const override;
};


#endif //CALCULUSPARSER_MULTIPLYNODE_H
