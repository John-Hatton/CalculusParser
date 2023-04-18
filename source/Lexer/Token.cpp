//
// Created by John on 4/4/2023.
//

#include <Lexer/Token.h>



Token::Token(TokenType type, std::string lexeme) : type(type), lexeme(std::move(lexeme)) {
}

Token::Token(TokenType type) {
    if (type == TokenType::LEFT_PAREN) {
        lexeme == "(";
    } else if (type == TokenType::RIGHT_PAREN) {
        lexeme = ")";
    } else if (type == TokenType::ADD) {
        lexeme = "+";
    } else if (type == TokenType::SUBTRACT) {
        lexeme = "-";
    } else if (type == TokenType::MULTIPLY) {
        lexeme = "*";
    } else if (type == TokenType::DIVIDE) {
        lexeme = "/";
    } else {
        // If the lexeme is not one of the above single-character tokens, it must be a number.
        type = TokenType::NUMBER;
    }
    this->lexeme = lexeme;
}


Token::Token(std::string lexeme) {
    if (lexeme == "(") {
        type = TokenType::LEFT_PAREN;
    } else if (lexeme == ")") {
        type = TokenType::RIGHT_PAREN;
    } else if (lexeme == "+") {
        type = TokenType::ADD;
    } else if (lexeme == "-") {
        type = TokenType::SUBTRACT;
    } else if (lexeme == "*") {
        type = TokenType::MULTIPLY;
    } else if (lexeme == "/") {
        type = TokenType::DIVIDE;
    } else {
        // If the lexeme is not one of the above single-character tokens, it must be a number.
        type = TokenType::NUMBER;
    }
    this->lexeme = lexeme;
}

TokenType Token::getType() const {
    return type;
}

std::string Token::getLexeme() const {
    return lexeme;
}

std::string Token::toString() const {
    return lexeme;
}


bool Token::operator==(const Token& other) const {
    return (type == other.type) && (lexeme == other.lexeme);
}

bool Token::isEmpty() const {
    return lexeme.empty();
}
