#ifndef CALCULUSPARSER_ASTNODE_H
#define CALCULUSPARSER_ASTNODE_H

#include <vector>
#include <memory>
#include <Lexer/Token.h>

/**
 * ASTNode: This is the base class for all AST nodes. It defines common attributes and behaviors that are shared by all
 * nodes in the tree.
 */
class ASTNode {
public:
    /**
     * ASTNode Constructor: creates an ASTNode with a given token
     * @param token the token that the node represents in the source code
     */
    explicit ASTNode(const Token& token) : token(token.getType(), token.toString()) {}

    /**
     * ASTNode Destructor: This is a virtual destructor that is set to the default implementation.
     * This allows child classes to define their own destructors while still being able to call the base class destructor.
     */
    virtual ~ASTNode() = default;

    /**
     * Copy constructor: creates a copy of an ASTNode object
     * @param other the ASTNode object to copy
     */
    ASTNode(const ASTNode& other) : token(other.token) {}

    /**
     * Move constructor: creates an ASTNode object by moving another ASTNode object
     * @param other the ASTNode object to move
     */
    ASTNode(ASTNode&& other) noexcept : token(std::move(other.token)) {}

    /**
     * Copy assignment operator: assigns an ASTNode object to another
     * @param other the ASTNode object to assign
     * @return the newly assigned ASTNode object
     */
    ASTNode& operator=(const ASTNode& other) {
        if (this != &other) {
            token = other.token;
        }
        return *this;
    }

    /**
     * Move assignment operator: assigns an ASTNode object to another by moving
     * @param other the ASTNode object to move and assign
     * @return the newly assigned ASTNode object
     */
    ASTNode& operator=(ASTNode&& other) noexcept {
        if (this != &other) {
            token = std::move(other.token);
        }
        return *this;
    }

    /**
     * getToken: retrieves the token associated with the node
     * @return the token
     */
    TokenType getTokenType() const {
        return token.getType();
    }

    Token getToken() {
        return token;
    };

    /**
     * getChildren: retrieves a vector of child nodes
     * @return a vector of unique_ptrs to child nodes
     */
    virtual std::vector<std::shared_ptr<ASTNode>> getChildren() const {
        return std::vector<std::shared_ptr<ASTNode>>();
    }

    /**
     * toString: returns a string representation of the node and its children, if any
     * @return a string representation of the node
     */
    virtual std::string toString() const = 0;


    //virtual double evaluate() const = 0;

protected:
    Token token;
};

#endif //CALCULUSPARSER_ASTNODE_H
