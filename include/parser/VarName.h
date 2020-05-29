//
// Created by nrx on 29.05.2020.
//

#ifndef DUMMY_PARSER_VARNAME_H
#define DUMMY_PARSER_VARNAME_H

#include "Token.h"

class VarName : public Token {
public:
    VarName(std::string value);
private:
};

std::ostream& operator<< (std::ostream &stream, const VarName &var);

#endif //DUMMY_PARSER_VARNAME_H
