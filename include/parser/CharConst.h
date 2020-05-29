//
// Created by nrx on 29.05.2020.
//

#ifndef DUMMY_PARSER_CHARCONST_H
#define DUMMY_PARSER_CHARCONST_H
#include "Token.h"

class CharConst : public Token {
public:
    CharConst(std::string value);
    std::string value() const;

private:
    std::string char_const;
};

#endif //DUMMY_PARSER_CHARCONST_H
