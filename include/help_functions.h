//
// Created by nrx on 29.05.2020.
//

#ifndef DUMMY_PARSER_HELP_FUNCTIONS_H
#define DUMMY_PARSER_HELP_FUNCTIONS_H
#include <string>
#include <vector>
#include "Tokens.h"
#include "bison.h"

extern "C" int yylen();
extern "C" int yylex();
extern "C" FILE* yyin;
extern "C" int yydebug;




int createNode(std::string value, std::vector<token_type> children_index);
int createBinaryOperation(std::string bvalue, BinaryOperation::Type btype, token_type n1, token_type n2);
int createUnaryOperation(std::string bvalue, UnaryOperation::Type btype, token_type n1);
void yyerror(const char *str);
int yywarp();

#endif //DUMMY_PARSER_HELP_FUNCTIONS_H
