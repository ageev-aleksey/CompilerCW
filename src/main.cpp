//////
////// Created by nrx on 29.05.2020.
//////
////
#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include "GraphToDOT.h"
#include "Tokens.h"
#include <memory>
#include <unordered_set>
#include "help_functions.h"
#define YYDEBUG 1
extern "C" int yylen();
extern "C" int yylex();
extern "C" FILE* yyin;
extern "C" int yydebug;



#define YYSTYPE struct token_type

Graph<std::shared_ptr<Token>, Empty> root;

void yyerror(const char *str) {
    std::cout << "-===========-" << std::endl;
    std::cout << "error: " << str << std::endl;
    std::cout << "-===========-" << std::endl;
}

int yywarp() {
    return 1;
}
/*
int create_op_node(std::string value, std::string op, token_type v1, token_type v2) {

    auto node = root.addNodeInBack(std::make_shared<NonTerm>(value));
    auto op_node = root.addNodeInBack(std::make_shared<Token>());
    root.addLink(node, root.getNodeByIndex(v1.index), Empty{});
    root.addLink(node, op_node, Empty{});
    root.addLink(node, root.getNodeByIndex(v2.index), Empty{});
    return node.getIndex();

}*/

std::pair<std::unordered_set<Token>,std::unordered_set<Token>> createTableOfConstants() {
    std::pair<std::unordered_set<Token>,std::unordered_set<Token>> res;
    for(Graph<std::shared_ptr<Token>, Empty>::iterator itr = root.begin(); itr != root.end(); ++itr) {
        if(itr.getData()->getType() == TokenType::CHARCONST) {
            res.first.insert(*itr.getData());
        } else if(itr.getData()->getType() == TokenType::INTCONST) {
            res.second.insert(*itr.getData());
        }
    }
    return res;
}

int createNode(std::string value, std::vector<token_type> children_index) {
    auto node = root.addNodeInBack(std::make_shared<Token>(value));
    for(auto ptr = children_index.begin(); ptr != children_index.end(); ++ptr) {
        root.addLink(node, root.get(ptr->index), Empty{});
    }
    return node.getIndex();
}

int createBinaryOperation(std::string bvalue, BinaryOperation::Type btype, token_type n1, token_type n2) {
    auto node = root.newNode(std::make_shared<BinaryOperation>(bvalue, btype));
    root.addLink(node, root.get(n1.index), Empty{});
    root.addLink(node, root.get(n2.index), Empty{});
    return  node.getIndex();
}

int createUnaryOperation(std::string bvalue, UnaryOperation::Type btype, token_type n1) {
    auto node = root.newNode(std::make_shared<UnaryOperation>(bvalue, btype));
    root.addLink(node, root.get(n1.index), Empty{});
    return  node.getIndex();
}


void createLink(int index1, int index2) {
    root.addLink(root.getNodeByIndex(index1), root.getNodeByIndex(index2), Empty{});
}

int main() {
    yydebug = 1;
    std::cout << "Compiler!" << std::endl;
    yyin = fopen("flex_input.php", "r");
    yyparse();
    std::cout << "end!" << std::endl;
    saveImageGV(toDotByDepthStep(root), "graph");
    auto table = createTableOfConstants();
    std::cout << "--===CharConstants===--\n";
    for(auto t : table.first) {
        std::cout << t << "\n";
    }
    std::cout << std::flush;
    std::cout << "--===IntConstants===--\n";
    for(auto t : table.second) {
        std::cout << t << "\n";
    }
    std::cout << std::flush;
    return 0;
}





















//
//
//
//#include <iostream>
//#include "bison.h"
//extern "C" int yywrap();
//extern "C" int yylex();
//extern "C" char* yytext;
//extern "C" FILE* yyin;
//void loop() {
//    int token = 0;
//    do{
//        token = yylex();
//        std::cout << "token id: " << token << std::endl;
//        std::cout << "token val: " << yylval.string << std::endl << std::endl;
//    }while(token != 0);
//}
//
//token_type yylval;
//
//int main(int argc, char** argv) {
//    std::cout << "Compiler!" << std::endl;
//    yyin = fopen("flex_input.php", "r");
//    loop();
//    return 0;
//}
//
//
//


