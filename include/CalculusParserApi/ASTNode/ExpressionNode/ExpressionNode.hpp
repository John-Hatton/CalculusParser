#ifndef CALCULUSPARSER_EXPRESSIONNODE_HPP
#define CALCULUSPARSER_EXPRESSIONNODE_HPP

#include <ASTNode/ASTNode.hpp>

/**
 * ExpressionNode: represents a mathematical expression composed of terms and operators.
 */
class ExpressionNode : public ASTNode {
public:


    // We take in a Token, but we should be taking in terms.

    // We have Factors -> Terms -> Expressions
    // Factors compose numbers and variables, and terms are one or more factors.
    // The expression is to be a combination of two or more terms, and an operator.
    // This means we should be always taking a first parameter, optionally a second,
    // and then we need the operator as well. This is all wrapped up in the two terms
    // and one operator. Oh boy, I do indeed have a TermNode implemented!

    // Perhaps this project won't go to shit afterall!
    /**
     * ExpressionNode Constructor: creates an expression node with a given token
     * @param token the token that the node represents in the source code
     */
    explicit ExpressionNode(const Token& token) : ASTNode(token), exprToken(token) {
        int x = 0;
    }


    /**
     * Move Constructor: creates a new ExpressionNode by moving the given node
     * @param other the ExpressionNode to be moved
     */
    ExpressionNode(ExpressionNode &&other) noexcept : ASTNode(std::move(other.token)), children(std::move(other.children)),
                                                                       exprToken(token) {}

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
    Token exprToken;
public:
    const Token &getExprToken() const {
        return exprToken;
    }

    void setExprToken(const Token &exprToken) {
        ExpressionNode::exprToken = exprToken;
    }

};

#endif //CALCULUSPARSER_EXPRESSIONNODE_HPP
