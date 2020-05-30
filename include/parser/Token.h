//
// Created by nrx on 22.05.2020.
//

#ifndef DUMMY_PARSER_TOKENINFO_H
#define DUMMY_PARSER_TOKENINFO_H
#include <string>
#include<ostream>

class TokenType {
public:
    enum ENUM {
        NonTerminal,
        BinaryOperation,
        UnaryOperation,
        If,
        HTML,
        WHILE,
        DO,
        FOR,
        FOREACH,
        ELSEIF,
        ECHO,
        VARNAME,
        BREAK,
        RETURN,
        CHARCONST,
        INTCONST,
        ARRAY_INDEX,
        CREATE_ARRAY,
        FUNC_CALL,
        ID,
        METHOD_CALL,
        NEW,
        KeyValueElement,
        SWITCH,
        CASE,
        FUNCTION_DEF,
        CLASS_DEF,
        CLASS_EXTENDS,
        ACCESS_MODIFIER,
        DefaultValue,

    };

    static std::string str(TokenType::ENUM);
};


std::ostream& operator<<(std::ostream& stream, TokenType type);


class Token {
public:

    Token(std::string token_value);
    Token(TokenType::ENUM type, const std::string &token_value);
    TokenType::ENUM getType() const;
    virtual std::string str() const;

    friend std::ostream& operator<<(std::ostream &stream, const Token &token);
protected:
    TokenType::ENUM type;
    std::string token_name;
private:
    void construct(TokenType::ENUM type, const std::string &token_value);
};


std::ostream& operator<<(std::ostream &stream, const Token &token);



#endif //DUMMY_PARSER_TOKENINFO_H
