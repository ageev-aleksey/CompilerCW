//
// Created by nrx on 29.05.2020.
//

#include "parser/BinaryOperation.h"

BinaryOperation::BinaryOperation(std::string oper, Type type) : Token(TokenType::BinaryOperation, oper) {
    this->type = type;
}

BinaryOperation::Type BinaryOperation::getOpType() {
    return type;
}