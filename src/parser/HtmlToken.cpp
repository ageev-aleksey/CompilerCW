//
// Created by nrx on 29.05.2020.
//

#include "parser/HtmlToken.h"

HtmlToken::HtmlToken(std::string value) : Token(TokenType::HTML, "HTML"), value(value) {}

std::string HtmlToken::getValue() {
    return value;
}
