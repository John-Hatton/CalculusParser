#include <ASTNode/OperatorNode/BinaryOperatorNode/AddNode/AddNode.h>


template<typename T>
T AddNode<T>::evaluate() {
    //auto left = std::dynamic_pointer_cast<FactorNode>(getLeftChild())->evaluate();
//    auto left = getLeftChild()->evaluate();
//    auto right = getRightChild()->evaluate();
    return -1;
}

template<typename T>
std::string AddNode<T>::toString() const {
    return this->toString();
}