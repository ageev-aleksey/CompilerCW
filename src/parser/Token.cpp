
#include "parser/Token.h"
#include "bison.h"
#include <unordered_map>
#include <cassert>


Token::Token(std::string token_value) {
    construct(TokenType::NonTerminal, token_value);
}

Token::Token(TokenType::ENUM type,const std::string &token_value) {
    construct(type, token_value);
}

void Token::construct(TokenType::ENUM type,const std::string &token_value) {
    this->type = type;
    this->token_name = token_value;
}

TokenType::ENUM Token::getType() const {
    return type;
}

std::string Token::str() const {
    return std::string("{") + std::string("Name = ") + token_name + std::string("; Type = ") +
            TokenType::str(type) + std::string("}");
}

std::ostream& operator<<(std::ostream& stream, const Token& token) {
    stream << token.str();
    return stream;
}


std::string TokenType::str(TokenType::ENUM type) {
    std::unordered_map<TokenType::ENUM, std::string> map {
            {TokenType::NonTerminal, "NonTerminal"},
            {TokenType::BinaryOperation, "BinaryOperation"},
            {TokenType::UnaryOperation, "UnaryOperation"},
            {TokenType::If, "If"},
            {TokenType::HTML, "HTML"},
            {TokenType::WHILE, "WHILE"},
            {TokenType::DO, "DO"},
            {TokenType::FOR, "FOR"},
            {TokenType::FOREACH, "FOREACH"},
            {TokenType::ELSEIF, "ELSEIF"},
            {TokenType::ECHO, "ECHO"},
            {TokenType::VARNAME, "VARNAME"},
            {TokenType::BREAK, "BREAK"},
            {TokenType::CHARCONST, "CHARCONST"},
            {TokenType::INTCONST, "INTCONST"},
            {TokenType::ARRAY_INDEX, "ARRAY_INDEX"},
            {TokenType::CREATE_ARRAY, "CREATE_ARRAY"},
            {TokenType::FUNC_CALL, "FUNC_CALL"},
            {TokenType::METHOD_CALL, "METHOD_CALL"},
            {TokenType::ID, "ID"},
            {TokenType::NEW, "NEW"},
            {TokenType::KeyValueElement, "KeyValueElement"},
            {TokenType::RETURN, "RETURN"},
            {TokenType::SWITCH, "SWITCH"},
            {TokenType::CASE, "CASE"},
            {TokenType::FUNCTION_DEF, "FUNCTION_DEF"},
            {TokenType::CLASS_DEF, "CLASS_DEF"},
            {TokenType::CLASS_EXTENDS, "CLASS_EXTENDS"},
            {TokenType::ACCESS_MODIFIER, "ACCESS_MODIFIER"},
            {TokenType::DefaultValue, "DefaultValue"},
    };
    std::unordered_map<TokenType::ENUM, std::string>::iterator itr = map.find(type);

    assert(itr != map.end());

    return itr->second;
}


std::ostream& operator<<(std::ostream& stream, TokenType::ENUM type) {
    stream << TokenType::str(type);
}

