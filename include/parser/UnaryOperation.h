//
// Created by nrx on 29.05.2020.
//

#ifndef DUMMY_PARSER_UNARYOPERATION_H
#define DUMMY_PARSER_UNARYOPERATION_H
#include "parser/Token.h"



class UnaryOperation : public Token {
public:
    enum class Type {
        LOGICAL,
        MATH,
        UNKNOWN
    };
    UnaryOperation(std::string symbol, Type type);
    Type getOpType();
private:
    Type type;
};
#endif //DUMMY_PARSER_UNARYOPERATION_H
