///
// Created by John on 4/17/2023.
//

#ifndef CALCULUSPARSER_BINARYOPERATORNODE_H
#define CALCULUSPARSER_BINARYOPERATORNODE_H

#include <ASTNode/OperatorNode/OperatorNode.h>
#include "ASTNode/FactorNode/FactorNode.h"
#include <memory>
#include <vector>

/**
 * @brief A binary operator node represents an operator that takes two operands.
 *
 * This class extends the OperatorNode class to represent binary operators, such as addition or multiplication.
 * It contains two child nodes, which represent the operands of the binary operator.
 * The getChildren() method returns a vector of shared pointers to the child nodes.
 * The setLeftChild() and setRightChild() methods set the left and right child nodes, respectively.
 * The getLeftChild() and getRightChild() methods return shared pointers to the left and right child nodes, respectively.
 */
class BinaryOperatorNode : public OperatorNode {
public:
    /**
     * @brief Constructs a BinaryOperatorNode object.
     *
     * @param token The Token object associated with the operator.
     * @param symbol The string symbol representation of the operator.
     */
    BinaryOperatorNode(Token token, std::string symbol);


    BinaryOperatorNode(std::shared_ptr<FactorNode> left, std::shared_ptr<FactorNode> right, Token myToken)
            : OperatorNode(myToken, myToken.getLexeme()), leftChild(std::move(left)), rightChild(std::move(right)) {}
    /**
     * @brief Default destructor for the BinaryOperatorNode class.
     */
    virtual ~BinaryOperatorNode() = default;

    /**
     * @brief Returns a vector of shared pointers to the child nodes.
     *
     * @return A vector of shared pointers to the child nodes.
     */
    std::vector<std::shared_ptr<ASTNode>> getChildren() const override;
    /**
     * @brief Sets the left child node.
     *
     * @param leftChild A shared pointer to the left child node.
     */
    void setLeftChild(std::shared_ptr<FactorNode> leftChild);
    /**
     * @brief Sets the right child node.
     *
     * @param rightChild A shared pointer to the right child node.
     */
    void setRightChild(std::shared_ptr<FactorNode> rightChild);
    /**
     * @brief Returns a shared pointer to the left child node.
     *
     * @return A shared pointer to the left child node.
     */
    std::shared_ptr<FactorNode> getLeftChild() const;
    /**
     * @brief Returns a shared pointer to the right child node.
     *
     * @return A shared pointer to the right child node.
     */
    std::shared_ptr<FactorNode> getRightChild() const;


    template <typename T>
    T evaluate() const;

private:
    std::shared_ptr<FactorNode> leftChild; /**< A shared pointer to the left child node. */
    std::shared_ptr<FactorNode> rightChild; /**< A shared pointer to the right child node. */
};

#endif //CALCULUSPARSER_BINARYOPERATORNODE_H