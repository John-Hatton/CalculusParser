#ifndef CALCULUSPARSER_TERMNODE_H
#define CALCULUSPARSER_TERMNODE_H

#include <ASTNode/ASTNode.h>

/**
 * TermNode: represents a mathematical term, which is a product or division of factors.
 */
class TermNode : public ASTNode {
public:
    /**
     * TermNode Constructor: creates a term node with a given token
     * @param token the token that the node represents in the source code
     */
    explicit TermNode(Token token) : ASTNode(std::move(token)) {}

    /**
     * Move Constructor: creates a new TermNode by moving the given node
     * @param other the TermNode to be moved
     */
    TermNode(TermNode&& other) noexcept : ASTNode(std::move(other.token)), children(std::move(other.children)) {}

    /**
     * addChild: adds a child node to the term node
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
     * toString: returns a string representation of the term node and its children
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

#endif //CALCULUSPARSER_TERMNODE_H
