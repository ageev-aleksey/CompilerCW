//
// Created by nrx on 29.05.2020.
//

#ifndef DUMMY_PARSER_INTCONST_H
#define DUMMY_PARSER_INTCONST_H
#include "Token.h"

class IntConst : public Token {
public:
    IntConst(std::string value);
    int getValue();
private:
    int value;

};
#endif //DUMMY_PARSER_INTCONST_H
