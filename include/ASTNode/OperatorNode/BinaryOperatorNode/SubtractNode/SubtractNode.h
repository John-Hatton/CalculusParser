//
// Created by John on 4/18/2023.
//

#ifndef CALCULUSPARSER_SUBTRACTNODE_H
#define CALCULUSPARSER_SUBTRACTNODE_H


#include <ASTNode/OperatorNode/BinaryOperatorNode/BinaryOperatorNode.h>
#include <ASTNode/FactorNode/FactorNode.h>

template<typename T>
class SubtractNode : public BinaryOperatorNode {
public:

    SubtractNode(std::shared_ptr<FactorNode> leftChild, std::shared_ptr<FactorNode> rightChild)
            : BinaryOperatorNode(Token(TokenType::SUBTRACT, "-"), "-") {
        setLeftChild(leftChild);
        setRightChild(rightChild);
    }

    T evaluate();

    std::string toString() const override;
};

#endif //CALCULUSPARSER_SUBTRACTNODE_H
