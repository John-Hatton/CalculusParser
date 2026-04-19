# Epic 2: Create Parser Logic and AST

## Overview
This epic focuses on implementing the recursive descent parser and completing the Abstract Syntax Tree (AST) node implementations to enable full mathematical expression parsing and evaluation.

## Status: 🔄 IN PROGRESS

## Completed Tasks

### ✅ AST Node Framework
- [x] Base `ASTNode` class with Token integration
- [x] `FactorNode` hierarchy (NumberNode, VariableNode, FunctionNode)
- [x] `BinaryOperatorNode` base class
- [x] `AddNode` implementation with templates
- [x] Smart pointer memory management

### ✅ Basic Node Implementations
- [x] `NumberNode<T>` with template support for int/double
- [x] `VariableNode` for single-letter variables
- [x] `AddNode<T>` with evaluation and string representation
- [x] Basic node construction and inheritance

### ✅ Testing Infrastructure
- [x] Unit tests for AddNode functionality
- [x] AST node construction validation
- [x] String representation testing
- [x] Template instantiation verification

## In Progress Tasks

### 🔄 Parser Implementation
- [x] Parser class structure defined
- [ ] `parseExpression()` method implementation
- [ ] `parseTerm()` method implementation
- [ ] `parseFactor()` method implementation
- [ ] Operator precedence handling
- [ ] Error handling and reporting

### 🔄 AST Node Completion
- [x] Basic node classes implemented
- [ ] `SubtractNode`, `MultiplyNode`, `DivideNode` operators
- [ ] `FunctionNode` evaluation logic
- [ ] `ExpressionNode` and `TermNode` implementation
- [ ] Node traversal and evaluation methods

### 🔄 Integration Testing
- [ ] End-to-end parsing tests
- [ ] Complex expression parsing validation
- [ ] AST construction verification
- [ ] Evaluation result testing

## Remaining Work

### Parser Core Implementation

The parser needs to implement recursive descent parsing according to the grammar:

```cpp
class Parser {
public:
    Parser(std::vector<Token> tokens) : tokens(tokens) {}

    std::shared_ptr<ASTNode> parse() {
        return parseExpression();
    }

private:
    std::vector<Token> tokens;
    size_t current = 0;

    std::shared_ptr<ASTNode> parseExpression();
    std::shared_ptr<ASTNode> parseTerm();
    std::shared_ptr<ASTNode> parseFactor();

    // Utility methods
    Token peek() const;
    Token advance();
    bool isAtEnd() const;
    bool match(TokenType type);
    Token consume(TokenType type, const std::string& message);
};
```

### Missing Operator Nodes

Need to implement:
- `SubtractNode<T>` for subtraction operations
- `MultiplyNode<T>` for multiplication
- `DivideNode<T>` for division

Each should follow the same pattern as `AddNode`:
- Template class for type safety
- Constructor taking left/right operands
- `evaluate()` method
- `toString()` method

### Expression and Term Nodes

Implement higher-level nodes:
- `ExpressionNode`: Handles addition/subtraction sequences
- `TermNode`: Handles multiplication/division sequences

### Function Node Enhancement

Complete `FunctionNode`:
- Argument parsing and storage
- Function evaluation (sin, cos, tan)
- Error handling for invalid arguments

## Current Capabilities

### ✅ Working Features
- Lexer produces correct token streams
- Basic AST node construction
- AddNode evaluation and string representation
- Template-based type safety

### 🔄 Partially Working
- AST node hierarchy (structure exists, evaluation incomplete)
- Basic operator framework (AddNode works, others pending)

### ❌ Not Yet Implemented
- Full parser implementation
- Complex expression parsing
- Multiplication and division operations
- Function evaluation

## Test Results

### Passing Tests ✅
- Lexer tokenization tests
- AddNode construction and evaluation
- Basic AST node creation

### Failing/Incomplete Tests ❌
- Complex expression parsing (no parser yet)
- Multiplication/division operations (nodes not implemented)
- Function evaluation (incomplete implementation)

## Technical Challenges

### Parser Implementation
- Correct precedence handling (multiplication before addition)
- Left-associative operator chaining
- Error recovery and reporting

### AST Design Issues
- Template instantiation complexity
- Shared pointer management in complex trees
- Evaluation context (variable bindings)

### Integration Points
- Lexer-to-parser token stream handoff
- Parser-to-AST node construction
- AST evaluation with variable substitution

## Next Steps

### Immediate Priorities
1. **Implement Parser Class**: Core parsing logic for expressions
2. **Add Missing Operators**: SubtractNode, MultiplyNode, DivideNode
3. **Complete Expression/Term Nodes**: Higher-level AST construction
4. **Function Node Completion**: Trigonometric function evaluation

### Medium-term Goals
1. **Integration Testing**: End-to-end expression parsing
2. **Error Handling**: Comprehensive error reporting
3. **Performance Optimization**: AST evaluation efficiency
4. **Extensibility**: Framework for new operators/functions

## Dependencies

### Completed Dependencies ✅
- Epic 0: Build system and project structure
- Epic 1: Lexer and token system

### External Dependencies
- C++ standard library (smart pointers, strings, vectors)
- Google Test framework (for testing)

## Risk Assessment

### High Risk
- Parser implementation complexity (recursive descent with precedence)
- Template metaprogramming for type-safe operations

### Medium Risk
- AST evaluation with variable substitution
- Error handling and recovery

### Low Risk
- Additional operator node implementations (follow AddNode pattern)
- Function node completion

## Success Criteria

### Functional Requirements
- [ ] Parse expressions like `"2 + 3 * x - sin(y)"`
- [ ] Build correct AST representations
- [ ] Evaluate expressions with variable bindings
- [ ] Handle operator precedence correctly

### Quality Requirements
- [ ] Comprehensive test coverage (>90%)
- [ ] Clean error messages for invalid input
- [ ] Memory leak-free operation
- [ ] Reasonable performance for typical expressions

## Files to Create/Modify

### New Files Needed
- `include/Parser/Parser.h` - Parser interface
- `source/Parser/Parser.cpp` - Parser implementation
- `include/ASTNode/OperatorNode/BinaryOperatorNode/SubtractNode/SubtractNode.h`
- `include/ASTNode/OperatorNode/BinaryOperatorNode/MultiplyNode/MultiplyNode.h`
- `include/ASTNode/OperatorNode/BinaryOperatorNode/DivideNode/DivideNode.h`
- Corresponding .cpp implementation files

### Files to Enhance
- `source/ASTNode/FactorNode/FunctionNode/FunctionNode.cpp` - Add evaluation
- `source/ASTNode/ExpressionNode/ExpressionNode.cpp` - Implement parsing logic
- `source/ASTNode/TermNode/TermNode.cpp` - Implement parsing logic

## Testing Strategy

### Unit Tests
- Individual parser method testing
- AST node construction validation
- Operator precedence verification
- Error condition handling

### Integration Tests
- Full expression parsing and evaluation
- Complex nested expressions
- Variable substitution scenarios
- Performance benchmarking

This epic represents the core functionality of the Calculus Parser. Successful completion will enable parsing and evaluation of mathematical expressions, providing the foundation for calculus operations in future epics.