//
// Created by nrx on 29.05.2020.
//

#ifndef DUMMY_PARSER_BINARYOPERATION_H
#define DUMMY_PARSER_BINARYOPERATION_H

#include "Token.h"


class BinaryOperation : public Token {
public:
    enum class Type{
        MATH,
        LOGICAL,
        FUNCTION_CALL,
        ARRAY_INDEX
    };
    BinaryOperation(std::string op_symbol, Type type);
    Type getOpType();
private:
    Type type;
};


#endif //DUMMY_PARSER_BINARYOPERATION_H
