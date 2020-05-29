//
// Created by nrx on 22.05.2020.
//

#ifndef DUMMY_PARSER_TOKENINFO_H
#define DUMMY_PARSER_TOKENINFO_H
#include "bison.h"

class Token {
public:
    Token(const yytokentype &type);
    yytokentype getType() const;

protected:
    yytokentype type;
};


#endif //DUMMY_PARSER_TOKENINFO_H
