#ifndef CALCULUSPARSER_FACTORNODE_H
#define CALCULUSPARSER_FACTORNODE_H

#include <vector>
#include <memory>
#include "ASTNode/ASTNode.h"

class FactorNode : public ASTNode {
public:
    // Enumeration of factor types
    enum class FactorType {
        NUMBER, // A numeric constant
        VARIABLE, // A variable
        FUNCTION, // A function call
        SUB_EXPRESSION // A sub-expression enclosed in parentheses
    };

    // Constructor that takes a token and a factor type
    FactorNode(Token token, FactorType factorType);

    FactorNode(std::shared_ptr<ASTNode> child);

    // Destructor (defaulted)
    virtual ~FactorNode() = default;

    // Copy constructor
    FactorNode(const FactorNode& other);

    // Move constructor
    FactorNode(FactorNode&& other) noexcept;

    // Copy assignment operator
    FactorNode& operator=(const FactorNode& other);

    // Move assignment operator
    FactorNode& operator=(FactorNode&& other) noexcept;

    // Get the factor type
    FactorType getType() const;

    // Get the children of the node (empty vector since factors have no children)
    std::vector<std::shared_ptr<ASTNode>> getChildren() const override;

    // Convert the node to a string representation
    std::string toString() const override;

    // Add an argument to the node (for functions and sub-expressions)
    void addArgument(std::shared_ptr<ASTNode> argument);

    template <typename T>
    T evaluate();

    template <typename T>
    T getValue();



private:
    FactorType factorType; // The factor type
    std::vector<std::shared_ptr<ASTNode>> arguments; // Arguments for functions and sub-expressions
};



#endif //CALCULUSPARSER_FACTORNODE_H

