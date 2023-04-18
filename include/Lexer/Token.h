//
// Created by John on 4/4/2023.
//

#ifndef EMBEDEDCALCULUS_TOKEN_H
#define EMBEDEDCALCULUS_TOKEN_H

#include <string>


/**
 * TokenType: An enumeration of all possible token types in our Embedded Calculus programming language.
 */
enum class TokenType {
    // Non-terminal symbols
    EXPRESSION, // Represents an expression, consisting of one or more terms
    TERM,       // Represents a term, consisting of one or more factors
    FACTOR,     // Represents a factor, which can be a number, variable, function, or an expression enclosed in parentheses

    // Single-character tokens
    LEFT_PAREN, // Represents a left parenthesis, "("
    RIGHT_PAREN,// Represents a right parenthesis, ")"
    ADD,       // Represents an addition operator, "+"
    SUBTRACT,      // Represents a subtraction operator, "-"
    MULTIPLY,   // Represents a multiplication operator, "*"
    DIVIDE,     // Represents a division operator, "/"

    // Literals
    NUMBER,     // Represents a numerical value, such as "2.5" or "100"

    // Keywords
    VARIABLE,   // Represents a single-letter variable, such as "x"
    EQUALS,     // Represents an equals sign, "="
    IDENTIFIER, // Represents an identifier, such as "f", "g", "h", etc.
    FUNCTION,   // Represents a function, such as "sin", "cos", "tan", etc.

    // Trigonometric functions
    SIN,        // Represents the "sine" function, "sin"
    COS,        // Represents the "cosine" function, "cos"
    TAN,        // Represents the "tangent" function, "tan"

    // End-of-file token
    END_OF_FILE // Represents the end of the input string
};

/**
 * Token: A class that represents a single token in our Embedded Calculus programming language. Each token has a type and a
 * lexeme (the actual characters that make up the token in the input string).
 */
class Token {
public:
    /**
     * Token Constructor: Creates a new Token object with a given type and lexeme.
     * @param type The type of the token.
     * @param lexeme The lexeme of the token.
     */
    Token(TokenType type, std::string lexeme);

    explicit Token(TokenType type);

    explicit Token(std::string lexeme);

    /**
     * GetType Function: Returns the type of the token.
     * @return Returns the TokenType of the token.
     */
    TokenType getType() const;

    /**
     * GetLexeme Function: Returns the lexeme of the token.
     * @return Returns the lexeme (as a string) of the token.
     */
    std::string getLexeme() const;

    /**
     * ToString Function: Returns a string representation of the token.
     * @return Returns a string representation of the token in the form "Token(type=TYPE, lexeme=LEXEME)".
     */
    std::string toString() const;



    bool operator==(const Token& other) const;

    bool isEmpty() const;

private:
    TokenType type; // The type of the token
    std::string lexeme; // The lexeme (actual characters) of the token
};

#endif //EMBEDEDCALCULUS_TOKEN_H