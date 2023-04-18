add_library(CalculusParser
        Lexer/Lexer.cpp
        Lexer/Token.cpp
        ASTNode/ExpressionNode/ExpressionNode.cpp
        ASTNode/TermNode/TermNode.cpp ASTNode/OperatorNode/BinaryOperatorNode/AddNode/AddNode.cpp ASTNode/OperatorNode/BinaryOperatorNode/BinaryOperatorNode.cpp ASTNode/OperatorNode/OperatorNode.cpp)