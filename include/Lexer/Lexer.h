#ifndef EMBEDEDCALCULUS_LEXER_H
#define EMBEDEDCALCULUS_LEXER_H

#include <string>
#include <vector>
#include "Token.h"

/**

    Class Description Lexer: a class that serves as the lexer for our Embedded Calculus programming language. This class

    takes a string as input and tokenizes it according to the grammar of our programming language. The tokens are then

    returned as a vector of Token objects.
    */
class Lexer {
public:

    /**
        Lexer Constructor: Creates a Lexer object with a given input string.
        @param input The input string to be tokenized.
        */
    explicit Lexer(std::string input);

    /**
        GetTokens Function: Tokenizes the input string and returns the tokens as a vector of Token objects.
        @return Returns a vector of Token objects, with each Token representing a token from the input string.
        */
    std::vector<Token> getTokens();

private:
    std::string input; // The input string to be tokenized
    int current; // The current position in the input string
    int start; // The start position of the current token
    int line; // The current line number
    std::vector<Token> tokens;

    void tokenize();

    void number();

    void identifier();

/**
 * IsAtEnd Function: Returns a boolean value indicating whether the lexer has reached the end of the input string.
 * @return Returns true if the lexer has reached the end of the input string, false otherwise.
 */
    bool isAtEnd() const;

/**
 * Advance Function: Advances the current position of the lexer by one character.
 * @return Returns the character at the new current position.
 */
    char advance();

/**
 * Peek Function: Returns the character at the current position without advancing the current position.
 * @return Returns the character at the current position.
 */
    char peek() const;

    char peekNext() const;

    /**
 * Error Function: Throws a runtime error with a given error message.
 * @param message The error message to be included in the runtime error.
 */
    void error(const std::string &message) const;

/**
 * AddToken Function: Adds a new token to the tokens vector.
 * @param type The type of the token.
 * @param literal The literal value of the token.
 */
    void addToken(TokenType type, const std::string &literal);

    TokenType getTokenType(const std::string& tokenString);
};

#endif //EMBEDEDCALCULUS_LEXER_H