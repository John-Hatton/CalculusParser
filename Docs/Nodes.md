# AST Node Types

This document describes all the Abstract Syntax Tree (AST) node types implemented in the Calculus Parser. Each node type represents a different construct in the parsed mathematical expressions.

## Base Classes

### ASTNode
The root base class for all AST nodes. Provides common functionality:
- Token storage
- Basic constructors and destructors
- Virtual methods for evaluation and string representation

### OperatorNode
Base class for all operator nodes (binary and potentially unary operators).
- Extends ASTNode
- Provides operator-specific functionality

### FactorNode
Base class for all factor nodes (numbers, variables, functions, sub-expressions).
- Extends ASTNode
- Contains factor type enumeration

## Expression Nodes

### ExpressionNode
Represents a complete expression, which can be a single term or multiple terms combined with addition/subtraction.
- Inherits from ASTNode
- Contains a list of terms and operators

### TermNode
Represents a term, which can be a single factor or multiple factors combined with multiplication/division.
- Inherits from ASTNode
- Contains a list of factors and operators

## Factor Nodes

### NumberNode<T>
Represents numeric literals (integers or floating-point numbers).
- Template class supporting different numeric types (int, double, etc.)
- Stores the numeric value
- Template instantiations provided for int and double

### VariableNode
Represents single-letter variables (x, y, z, etc.).
- Stores the variable name as a string
- Supports evaluation when variable values are provided

### FunctionNode
Represents function calls (sin, cos, tan, etc.).
- Stores the function name
- Contains a pointer to the argument expression
- Supports trigonometric and other mathematical functions

## Operator Nodes

### BinaryOperatorNode
Base class for binary operators (addition, subtraction, multiplication, division).
- Contains left and right child nodes
- Provides methods for setting/getting children

### AddNode<T>
Represents addition operations.
- Inherits from BinaryOperatorNode
- Template class for type safety
- Implements evaluation and string representation

## Node Hierarchy

```
ASTNode (base)
├── OperatorNode
│   └── BinaryOperatorNode
│       └── AddNode<T>
├── FactorNode
│   ├── NumberNode<T>
│   ├── VariableNode
│   └── FunctionNode
├── ExpressionNode
└── TermNode
```

## Node Responsibilities

### Construction
- All nodes are constructed with appropriate Token objects
- Binary operators require left and right child nodes
- Factor nodes may require additional parameters (values, names)

### Evaluation
- Each node implements an `evaluate()` method
- Evaluation may require variable bindings or context
- Returns appropriate types based on node semantics

### String Representation
- `toString()` method for debugging and output
- Generates human-readable representations of expressions

## Future Extensions

- **UnaryOperatorNode**: For unary minus, factorial, etc.
- **PowerNode**: For exponentiation (^)
- **DerivativeNode**: For calculus operations
- **IntegralNode**: For integration
- **AssignmentNode**: For variable assignments

## Usage Examples

```cpp
// Create a simple addition: 2 + x
auto numNode = std::make_shared<NumberNode<int>>(Token(TokenType::NUMBER, "2"), 2);
auto varNode = std::make_shared<VariableNode>(Token(TokenType::VARIABLE, "x"), "x");
auto addNode = std::make_shared<AddNode<int>>(numNode, varNode);

// String representation
std::cout << addNode->toString(); // Outputs: "2+x"
```

## Implementation Notes

- All nodes use smart pointers (shared_ptr) for memory management
- Template classes allow type-safe numeric operations
- Virtual destructors ensure proper cleanup in inheritance hierarchies
- Nodes are designed for recursive evaluation and traversal