# Parsing Strategy: Recursive Descent

This document outlines the recursive descent parsing strategy used in the Calculus Parser, including implementation details, precedence handling, and error recovery.

## Overview

The Calculus Parser uses a **recursive descent parser** with **operator precedence parsing** to handle mathematical expressions. This approach is chosen for its simplicity, readability, and ability to handle complex grammars with clear precedence rules.

## Parser Architecture

### Core Components

1. **Lexer**: Tokenizes input string into Token stream
2. **Parser**: Implements recursive descent with precedence
3. **AST Builder**: Constructs Abstract Syntax Tree nodes
4. **Error Handler**: Reports syntax errors with location information

### Parser Class Structure

```cpp
class Parser {
private:
    std::vector<Token> tokens;
    size_t current = 0;

    // Parsing methods for each grammar rule
    std::shared_ptr<ASTNode> parseExpression();
    std::shared_ptr<ASTNode> parseTerm();
    std::shared_ptr<ASTNode> parseFactor();

    // Utility methods
    Token peek() const;
    Token advance();
    bool isAtEnd() const;
    bool match(TokenType type);
    void consume(TokenType type, const std::string& message);
};
```

## Grammar and Precedence

### Expression Grammar (EBNF)

```
Expression ::= Term ((ADD | SUBTRACT) Term)*
Term       ::= Factor ((MULTIPLY | DIVIDE) Factor)*
Factor     ::= NUMBER
             | VARIABLE
             | FUNCTION LEFT_PAREN Expression RIGHT_PAREN
             | LEFT_PAREN Expression RIGHT_PAREN
```

### Operator Precedence (Highest to Lowest)

1. **Parentheses**: `(expression)`
2. **Functions**: `sin(x)`, `cos(x)`, etc.
3. **Multiplication/Division**: `*`, `/`
4. **Addition/Subtraction**: `+`, `-`

## Recursive Descent Implementation

### Expression Parsing

```cpp
std::shared_ptr<ASTNode> Parser::parseExpression() {
    auto left = parseTerm();  // Parse left operand

    while (match(ADD) || match(SUBTRACT)) {
        Token operatorToken = previous();
        auto right = parseTerm();  // Parse right operand

        // Create binary operator node
        if (operatorToken.getType() == ADD) {
            left = std::make_shared<AddNode>(left, right);
        } else {
            left = std::make_shared<SubtractNode>(left, right);
        }
    }

    return left;
}
```

### Term Parsing (Multiplication/Division)

```cpp
std::shared_ptr<ASTNode> Parser::parseTerm() {
    auto left = parseFactor();

    while (match(MULTIPLY) || match(DIVIDE)) {
        Token operatorToken = previous();
        auto right = parseFactor();

        if (operatorToken.getType() == MULTIPLY) {
            left = std::make_shared<MultiplyNode>(left, right);
        } else {
            left = std::make_shared<DivideNode>(left, right);
        }
    }

    return left;
}
```

### Factor Parsing

```cpp
std::shared_ptr<ASTNode> Parser::parseFactor() {
    if (match(NUMBER)) {
        return std::make_shared<NumberNode>(previous(), std::stod(previous().getLexeme()));
    }

    if (match(VARIABLE)) {
        return std::make_shared<VariableNode>(previous());
    }

    if (match(SIN) || match(COS) || match(TAN)) {
        Token functionToken = previous();
        consume(LEFT_PAREN, "Expected '(' after function name");
        auto argument = parseExpression();
        consume(RIGHT_PAREN, "Expected ')' after function argument");

        return std::make_shared<FunctionNode>(functionToken, argument);
    }

    if (match(LEFT_PAREN)) {
        auto expression = parseExpression();
        consume(RIGHT_PAREN, "Expected ')' after expression");
        return expression;  // Parenthesized expression
    }

    throw std::runtime_error("Expected factor");
}
```

## Left-Associative vs Right-Associative Operators

### Left-Associative (Most Binary Operators)
For operators like `+`, `-`, `*`, `/`, the parser builds left-leaning trees:

**Expression:** `a + b + c`
**Tree Structure:**
```
    +
   / \
  +   c
 / \
a   b
```

### Right-Associative (Future: Exponentiation)
For operators like `^` (power), the tree would lean right:

**Expression:** `a ^ b ^ c`
**Tree Structure:**
```
  ^
 / \
a   ^
   / \
  b   c
```

## Error Handling and Recovery

### Syntax Error Detection

```cpp
void Parser::consume(TokenType type, const std::string& message) {
    if (check(type)) {
        advance();
        return;
    }

    throw ParseError(message, peek());
}
```

### Error Recovery Strategies

1. **Panic Mode**: Skip tokens until a synchronization point
2. **Statement Boundaries**: Use semicolons or newlines as sync points
3. **Bracket Matching**: Ensure parentheses are properly closed

### Error Reporting

- Include line/column information
- Show unexpected token and expected tokens
- Provide helpful suggestions for common mistakes

## Handling Complex Expressions

### Example: `2 * (3 + x) * sin(y)`

**Parsing Steps:**
1. `parseExpression()` → calls `parseTerm()`
2. `parseTerm()` → parses `2`, sees `*`, calls `parseFactor()`
3. `parseFactor()` → sees `(`, parses `3 + x`, sees `)`
4. `parseTerm()` → sees `*`, calls `parseFactor()`
5. `parseFactor()` → sees `sin`, parses `(y)`

**Resulting AST:**
```
    *
   / \
  *   sin(y)
 / \
2   (3 + x)
```

## Performance Considerations

### Time Complexity
- **O(n)**: Single pass through tokens
- **O(n)** space: AST nodes proportional to input size

### Memory Management
- Smart pointers prevent memory leaks
- AST can be traversed multiple times
- Efficient for typical mathematical expressions

## Extensibility

### Adding New Operators

1. Add TokenType for new operator
2. Update Lexer to recognize operator
3. Add parsing logic in appropriate precedence level
4. Create new AST node class
5. Add evaluation logic

### Adding New Functions

1. Add TokenType for function name
2. Update Lexer identifier parsing
3. Extend Factor parsing for new function
4. Create FunctionNode subclass if needed
5. Implement function evaluation

## Testing Strategy

### Unit Tests
- Test each parsing method individually
- Test operator precedence
- Test error conditions
- Test edge cases (empty expressions, etc.)

### Integration Tests
- End-to-end parsing and evaluation
- Complex expression parsing
- Error message validation

## Future Enhancements

### Advanced Features
- **Exponentiation**: Right-associative power operator
- **Unary Operators**: Unary minus, factorial
- **Assignment**: Variable assignment parsing
- **Lists/Arrays**: Matrix and vector notation

### Optimization
- **Constant Folding**: Evaluate constant expressions at parse time
- **AST Optimization**: Simplify redundant operations
- **Memoization**: Cache repeated subexpression results

### Error Recovery
- **Suggestion System**: Provide fix suggestions for common errors
- **Partial Parsing**: Parse what we can, report issues
- **Context-Aware Messages**: Better error messages based on context

This parsing strategy provides a solid foundation for mathematical expression parsing with clear precedence rules, good error handling, and room for future enhancements.