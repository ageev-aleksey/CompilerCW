//
// Created by nrx on 29.05.2020.
//

#include "parser/UnaryOperation.h"

UnaryOperation::UnaryOperation(std::string symbol, UnaryOperation::Type type) : Token(TokenType::UnaryOperation, symbol){
   this->type = type;
}

UnaryOperation::Type UnaryOperation::getOpType() {
    return type;
}