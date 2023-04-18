#ifndef CALCULUSPARSER_EXPRESSIONNODE_H
#define CALCULUSPARSER_EXPRESSIONNODE_H

#include <ASTNode/ASTNode.h>

/**
 * ExpressionNode: represents a mathematical expression composed of terms and operators.
 */
class ExpressionNode : public ASTNode {
public:
    /**
     * ExpressionNode Constructor: creates an expression node with a given token
     * @param token the token that the node represents in the source code
     */
    explicit ExpressionNode(Token token) : ASTNode(std::move(token)) {}


    /**
     * Move Constructor: creates a new ExpressionNode by moving the given node
     * @param other the ExpressionNode to be moved
     */
    ExpressionNode(ExpressionNode&& other) noexcept : ASTNode(std::move(other.token)), children(std::move(other.children)) {}

    /**
     * addChild: adds a child node to the expression node
     * @param child a unique pointer to the child node
     */
    void addChild(std::unique_ptr<ASTNode> child) {
        children.emplace_back(std::move(child));
    }

    /**
     * getChildren: retrieves a vector of child nodes
     * @return a vector of unique pointers to child nodes
     */
    std::vector<std::shared_ptr<ASTNode>> getChildren() const {
        return children;
    }

    /**
     * toString: returns a string representation of the expression node and its children
     * @return the string representation
     */
    std::string toString() const override {
        std::string str = "(" + token.toString() + " ";
        for (const auto& child : children) {
            str += child->toString() + " ";
        }
        str += ")";
        return str;
    }

private:
    std::vector<std::shared_ptr<ASTNode>> children;
};

#endif //CALCULUSPARSER_EXPRESSIONNODE_H
