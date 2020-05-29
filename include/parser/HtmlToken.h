//
// Created by nrx on 29.05.2020.
//

#ifndef DUMMY_PARSER_HTMLTOKEN_H
#define DUMMY_PARSER_HTMLTOKEN_H
#include "parser/Token.h"
#include "bison.h"
class HtmlToken : public Token {
public:
    explicit HtmlToken(std::string value);
    std::string getValue();
private:
    std::string value;
};
#endif //DUMMY_PARSER_HTMLTOKEN_H
