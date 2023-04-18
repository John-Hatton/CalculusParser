//
// Created by John on 4/4/2023.
//

#include <gtest/gtest.h>
#include "../source/Lexer/Lexer.cpp"
#include "../source/Lexer/Token.cpp"

TEST(LexerTests, LexerTests_LexerTests__Test01) {
    Lexer lexer("5.5 - -3.5");
    std::vector<Token> expected_tokens = {
            Token(TokenType::NUMBER, "5.5"),
            Token(TokenType::SUBTRACT, "-"),
            Token(TokenType::SUBTRACT, "-"),
            Token(TokenType::NUMBER, "3.5"),
            Token(TokenType::END_OF_FILE, "")
    };

    std::cout << "Hello!" << std::endl;
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}


TEST(LexerTests, LexerTests_LexerTests__Test02) {
    Lexer lexer("2 + 3 * 4 - 2 / 1");
    std::vector<Token> expected_tokens = {
            Token(TokenType::NUMBER, "2"),
            Token(TokenType::ADD, "+"),
            Token(TokenType::NUMBER, "3"),
            Token(TokenType::MULTIPLY, "*"),
            Token(TokenType::NUMBER, "4"),
            Token(TokenType::SUBTRACT, "-"),
            Token(TokenType::NUMBER, "2"),
            Token(TokenType::DIVIDE, "/"),
            Token(TokenType::NUMBER, "1"),
            Token(TokenType::END_OF_FILE, "")
    };



    EXPECT_EQ(expected_tokens, lexer.getTokens());
}

TEST(LexerTests, LexerTests_LexerTests__Test03) {
    Lexer lexer("7.5 / 0.5");
    std::vector<Token> expected_tokens = {
            Token(TokenType::NUMBER, "7.5"),
            Token(TokenType::DIVIDE, "/"),
            Token(TokenType::NUMBER, "0.5"),
            Token(TokenType::END_OF_FILE, "")
    };

    std::vector<Token> actual_tokens = lexer.getTokens();
    Token firstToken = lexer.getTokens()[0];
    EXPECT_EQ(expected_tokens, actual_tokens);
    EXPECT_EQ(firstToken.getType(), TokenType::NUMBER);
}



TEST(LexerTests, LexerTests_TestAddition) {
    Lexer lexer("2 + 3");
    std::vector<Token> expected_tokens = {
            Token(TokenType::NUMBER, "2"),
            Token(TokenType::ADD, "+"),
            Token(TokenType::NUMBER, "3"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}

TEST(LexerTests, LexerTests_TestSubtraction) {
    Lexer lexer("5 - 7");
    std::vector<Token> expected_tokens = {
            Token(TokenType::NUMBER, "5"),
            Token(TokenType::SUBTRACT, "-"),
            Token(TokenType::NUMBER, "7"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}

TEST(LexerTests, LexerTests_TestMultiplication) {
    Lexer lexer("2 * 4");
    std::vector<Token> expected_tokens = {
            Token(TokenType::NUMBER, "2"),
            Token(TokenType::MULTIPLY, "*"),
            Token(TokenType::NUMBER, "4"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}

TEST(LexerTests, LexerTests_TestDivision) {
    Lexer lexer("6 / 3");
    std::vector<Token> expected_tokens = {
            Token(TokenType::NUMBER, "6"),
            Token(TokenType::DIVIDE, "/"),
            Token(TokenType::NUMBER, "3"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}

TEST(LexerTests, LexerTests_TestMultipleOperators) {
    Lexer lexer("2 + 3 * 4 - 5 / 6");
    std::vector<Token> expected_tokens = {
            Token(TokenType::NUMBER, "2"),
            Token(TokenType::ADD, "+"),
            Token(TokenType::NUMBER, "3"),
            Token(TokenType::MULTIPLY, "*"),
            Token(TokenType::NUMBER, "4"),
            Token(TokenType::SUBTRACT, "-"),
            Token(TokenType::NUMBER, "5"),
            Token(TokenType::DIVIDE, "/"),
            Token(TokenType::NUMBER, "6"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}

TEST(LexerTests, LexerTests_TestVariableEqualsIdentifier) {
    Lexer lexer("f(x) = 2x+2");
    std::vector<Token> expected_tokens = {
            Token(TokenType::IDENTIFIER, "f"),
            Token(TokenType::LEFT_PAREN, "("),
            Token(TokenType::VARIABLE, "x"),
            Token(TokenType::RIGHT_PAREN, ")"),
            Token(TokenType::EQUALS, "="),
            Token(TokenType::NUMBER, "2"),
            Token(TokenType::VARIABLE, "x"),
            Token(TokenType::ADD, "+"),
            Token(TokenType::NUMBER, "2"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}

TEST(LexerTests, LexerTests_TestVariableEqualsIdentifier_wName) {
    Lexer lexer("func(x) = 2x+2");
    std::vector<Token> expected_tokens = {
            Token(TokenType::IDENTIFIER, "func"),
            Token(TokenType::LEFT_PAREN, "("),
            Token(TokenType::VARIABLE, "x"),
            Token(TokenType::RIGHT_PAREN, ")"),
            Token(TokenType::EQUALS, "="),
            Token(TokenType::NUMBER, "2"),
            Token(TokenType::VARIABLE, "x"),
            Token(TokenType::ADD, "+"),
            Token(TokenType::NUMBER, "2"),
            Token(TokenType::END_OF_FILE, "")
    };
    EXPECT_EQ(expected_tokens, lexer.getTokens());
}