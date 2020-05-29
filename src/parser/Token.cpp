
#include "parser/Token.h"
#include "bison.h"

Token::Token(const yytokentype &type) {
    this->type = type;
}

yytokentype Token::getType() const {
    return type;
}