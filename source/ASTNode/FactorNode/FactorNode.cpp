//
// Created by John on 4/17/2023.
//

#include <utility>

#include "ASTNode/FactorNode/FactorNode.h"
FactorNode::FactorNode(std::shared_ptr<ASTNode> child, Token myToken)
        : ASTNode(Token(child->getTokenType())), myToken(myToken) {
    arguments.push_back(child);
}
FactorNode::FactorNode(Token token, FactorType factorType, Token myToken)
        : ASTNode(std::move(token)), factorType(factorType), myToken(myToken) {}

FactorNode::FactorNode(const FactorNode &other, Token myToken)
        : ASTNode(other), factorType(other.factorType), arguments(other.arguments), myToken(myToken) {}

FactorNode::FactorNode(FactorNode &&other, Token myToken) noexcept
        : ASTNode(std::move(other)), factorType(other.factorType), arguments(std::move(other.arguments)),
          myToken(myToken) {}

FactorNode& FactorNode::operator=(const FactorNode& other) {
    if (this != &other) {
        ASTNode::operator=(other);
        factorType = other.factorType;
        arguments = other.arguments;
    }
    return *this;
}

FactorNode& FactorNode::operator=(FactorNode&& other) noexcept {
    if (this != &other) {
        ASTNode::operator=(std::move(other));
        factorType = other.factorType;
        arguments = std::move(other.arguments);
    }
    return *this;
}

FactorNode::FactorType FactorNode::getType() const {
    return factorType;
}

std::vector<std::shared_ptr<ASTNode>> FactorNode::getChildren() const {
    return arguments;
}

std::string FactorNode::toString() const {
//    switch (factorType) {
//        case FactorType::NUMBER:
//
//            return token.getLexeme();
//        case FactorType::VARIABLE:
//            return token.getLexeme();
//        case FactorType::FUNCTION: {
//            std::string result = token.getLexeme() + "(";
//            for (size_t i = 0; i < arguments.size(); ++i) {
//                result += arguments[i]->toString();
//                if (i < arguments.size() - 1) {
//                    result += ", ";
//                }
//            }
//            result += ")";
//            return result;
//        }
//        case FactorType::SUB_EXPRESSION:
//            return "(" + arguments[0]->toString() + ")";
//        default:
//            return "";
//    }
    std::stringstream ss;
    for (auto arg : arguments)
    {
        ss << arg->getToken().getLexeme();
    }
    std::string retStr = ss.str();


    return retStr;
}

void FactorNode::addArgument(std::shared_ptr<ASTNode> argument) {
    arguments.push_back(std::move(argument));
}

Token FactorNode::getMyToken() const {
    return myToken;
}

void FactorNode::setMyToken(Token myToken) {
    FactorNode::myToken = std::move(myToken);
}

template<typename T>
T FactorNode::getValue() {

}

template<typename T>
T FactorNode::evaluate() {


    return this->getValue<T>();
}
