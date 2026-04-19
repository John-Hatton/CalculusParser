# Grammar for Calculus Parser

This document defines the formal grammar for the calculus expressions that the parser can handle. The grammar is specified using Extended Backus-Naur Form (EBNF).

## Overview

The parser supports basic arithmetic expressions including addition, subtraction, multiplication, division, numbers, variables, and trigonometric functions. The grammar is designed for recursive descent parsing.

## EBNF Grammar

```
Expression ::= Term ((ADD | SUBTRACT) Term)*

Term ::= Factor ((MULTIPLY | DIVIDE) Factor)*

Factor ::= NUMBER
         | VARIABLE
         | FUNCTION LEFT_PAREN Expression RIGHT_PAREN
         | LEFT_PAREN Expression RIGHT_PAREN

NUMBER ::= [0-9]+ ('.' [0-9]+)?

VARIABLE ::= [a-zA-Z]

FUNCTION ::= 'sin' | 'cos' | 'tan'

ADD ::= '+'

SUBTRACT ::= '-'

MULTIPLY ::= '*'

DIVIDE ::= '/'

LEFT_PAREN ::= '('

RIGHT_PAREN ::= ')'
```

## Notes

- **Expression**: Represents the top-level expression, composed of terms combined with addition or subtraction.
- **Term**: Represents a term, composed of factors combined with multiplication or division.
- **Factor**: The basic building block, which can be a number, variable, function call, or a parenthesized expression.
- **NUMBER**: Supports integers and floating-point numbers.
- **VARIABLE**: Single-letter variables (e.g., 'x', 'y').
- **FUNCTION**: Currently supports sine, cosine, and tangent functions.
- Operators have standard precedence: multiplication and division before addition and subtraction. Parentheses can override precedence.

## Future Extensions

- Add exponentiation (^)
- Add more functions (e.g., log, exp)
- Support for calculus operations (derivatives, integrals)