//
// Created by nrx on 29.05.2020.
//

#ifndef DUMMY_PARSER_VARLIST_H
#define DUMMY_PARSER_VARLIST_H

#include "Token.h"
#include "VarName.h"

class VarList : public Token {
public:
    VarList(VarName name);
};

#endif //DUMMY_PARSER_VARLIST_H
