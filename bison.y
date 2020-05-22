%{
	#include <iostream>
	#include <string>
	#include <vector>
	#include "Graph.h"
	#include "GraphToDOT.h"
	#define YYDEBUG 1
	#define YYSTYPE int
    extern "C" int yyparse();
    extern "C" int yylen();
    extern "C" int yylex();
    extern "C" FILE* yyin;
    extern "C" int yydebug;


	Graph<std::string, Empty> root;

	void yyerror(const char *str) {
		std::cout << "-===========-" << std::endl;
		std::cout << "error: " << str << std::endl; 
		std::cout << "-===========-" << std::endl;
	}

	int yywarp() {
		return 1;
	}

	int createNode(std::string value, std::vector<int> children_index) {
		auto node = root.addNodeInBack(value);
		for(auto ptr = children_index.begin(); ptr != children_index.end(); ++ptr) {
			root.addLink(node, root.getNodeByIndex(*ptr), Empty{});
		}
               	return node.getIndex();
	}


	createLink(int index1, int index2) {
		root.addLink(root.getNodeByIndex(index1), root.getNodeByIndex(index2), Empty{});
	}

	int main() {
		yydebug = 1;
		std::cout << "Compiler!" << std::endl;
            	yyin = fopen("flex_input.php", "r");
		yyparse();
		std::cout << "end!" << std::endl;
		saveImageGV(graphToDOT(root), "graph");
		return 0;
	}
%}

%token  BREAK CLONE ENDSWITCH HTML WHILE DO FOR FOREACH VARNAME AS SV RETURN INTCONST CHARCONST PAS DIVAS MODAS EQ NE TEQ TNE LEQ GEQ AND OR PP MM UPLUS UMINUS ARRAY ID ARROW NEW PARENT DCOL IF ELSE ELSEIF SWITCH DEFAULT CASE FUNCTION CLASS EXTENDS VAR PUBLIC PRIVATE PROTECTED ECHO_KW MAS MULAS UNDEFINED

%left '(' ')'
%left '+' '-'
%left '*' '/'
%right UPLUS UMINUS

/*
HTML ')' '(' ';' WHILE DO '{' '}' FOR FOREACH VARNAME
AS SV BREAK RETURN  INTCONST  CHARCONST '['  ']' 
'.'  '+'  PAS  '-'  '*' '/' DIVAS  '%' MODAS '='
EQ  NE TEQ TNE '<' LEQ '>' GEQ  AND  OR  '!'  PP 
MM UPLUS UMINUS ARRAY ID ARROW  ID  NEW PARENT DCOL  ',' 
IF ELSE ELSEIF  SWITCH   DEFAULT  ':' CASE FUNCTION 
CLASS EXTENDS VAR PUBLIC  PRIVATE PROTECTED PUBLIC PRIVATE
PROTECTED 
*/

%%

program : main_stmt_tag_list
	{
		$$ = createNode("program", {$1});
	}
        ; 
main_stmt_tag_list  : main_stmt
			{
				$$ = createNode("main_stmt_tag_list", {$1});
			}
                    | main_stmt_tag_list main_stmt
                    	{
                    		$$ = createNode("main_stmt_tag_list", {$1, $2});
                    	}
                    | HTML
                    {
			auto node = root.addNodeInBack("main_stmt_tag_list");
                    	auto html_node = root.addNodeInBack(std::string("HTML"));
                    	root.addLink(node, html_node, Empty{});
                    	$$ = node.getIndex();

                    }
                    | main_stmt_tag_list HTML
                    {
                    	$$ = createNode("main_stmt_tag_list", {$1});
                    	auto html_node = root.addNodeInBack(std::string("HTML"));
                    	root.addLink(root.getNodeByIndex($$), html_node, Empty{});
                    }
                    ;
main_stmt   : class_def
	    {
	    	$$ = createNode("main_stmt", {$1});
	    }
            | function_def
            {
            	$$ = createNode("main_stmt", {$1});
            }
            | stmt
            {
            	$$ = createNode("main_stmt", {$1});
            }
            ;

stmt_list   : stmt
	   {
	    	$$ = createNode("stmt_list", {$1});
	    }
            | stmt_list stmt
            {
            	$$ = createNode("stmt_list", {$1, $2});
            }
            ; 

stmt_list_e :  /*empty*/
	    {
	    	$$ = createNode("stmt_list", {});
	    	auto empty = root.addNodeInBack("empty");
	    	root.addLink(root.getNodeByIndex($$), empty, Empty{});
	    }
            | stmt_list
            {
            	$$ = createNode("stmt_list", {$1});
            }
            ;
            
lost_close_par  : ')'	%prec ')'
		{
			$$ = createNode("lost_close_par", {});
			auto braket_node = root.addNodeInBack(")");
			root.addLink(root.getNodeByIndex($$), braket_node, Empty{});
		}
                | error %prec ')'
                {
                	$$ = createNode("lost_close_par", {$1});
                }
                ;
lost_open_par  : '('	%prec '('
		{
			$$ = createNode("lost_close_par", {});
			auto braket_node = root.addNodeInBack("(");
			root.addLink(root.getNodeByIndex($$), braket_node, Empty{});
		}
                | error %prec '('
                {
                	$$ = createNode("lost_close_par", {$1});
                }
                ;
stmt    : expr_e ';'
	{
		$$ = createNode("stmt", {$1});
		auto braket_node = root.addNodeInBack(";");
		root.addLink(root.getNodeByIndex($$), braket_node, Empty{});
	}
        | if_stmt
        {
        	$$ = createNode("stmt", {$1});
        }
        | switch_stmt
        {
        	$$ = createNode("stmt", {$1});
        }
        | WHILE lost_open_par expr lost_close_par stmt
        {
        	auto node = root.addNodeInBack("stmt");
        	auto while_node = root.addNodeInBack("while");
        	root.addLink(node, while_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($2), Empty{});
        	root.addLink(node, root.getNodeByIndex($3), Empty{});
        	root.addLink(node, root.getNodeByIndex($4), Empty{});
        	root.addLink(node, root.getNodeByIndex($5), Empty{});
        	$$ = node.getIndex();
        }
        | DO '{' stmt_list_e '}' WHILE lost_open_par expr lost_close_par ';'
        {
		auto node = root.addNodeInBack("stmt");
        	auto do_node = root.addNodeInBack("do");
        	auto openbreacket_node = root.addNodeInBack("{");
        	auto closebreacket_node = root.addNodeInBack("{");
        	auto while_node = root.addNodeInBack("while");
        	auto semicolon_node = root.addNodeInBack(";");
        	root.addLink(node, do_node, Empty{});
        	root.addLink(node, openbreacket_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($3), Empty{});
        	root.addLink(node, closebreacket_node, Empty{});
        	root.addLink(node, while_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($6), Empty{});
        	root.addLink(node, root.getNodeByIndex($7), Empty{});
        	root.addLink(node, root.getNodeByIndex($8), Empty{});
        	root.addLink(node, semicolon_node, Empty{});

        	$$ = node.getIndex();

        }
        | FOR lost_open_par expr_e ';' expr_e ';' expr_e lost_close_par stmt
        {
		auto node = root.addNodeInBack("stmt");
		auto for_node = root.addNodeInBack("FOR");
		auto semicolon_node1 = root.addNodeInBack(";");
		auto semicolon_node2 = root.addNodeInBack(";");
		root.addLink(node, for_node, Empty{});
		root.addLink(node, root.getNodeByIndex($2), Empty{});
		root.addLink(node, root.getNodeByIndex($3). Empty{});
		root.addLink(node, semicolon_node1, Empty{});
		root.addLink(node, $5, Empty{});
		root.addLink(node, semicolon_node2, Empty{});
		root.addLink(node, root.getNodeByIndex($7), Empty{});
		root.addLink(node, root.getNodeByIndex($8), Empty{});
		root.addLink(node, root.getNodeByIndex($9), Empty{});
        }
        | FOREACH lost_open_par expr AS VARNAME lost_close_par stmt
        {
        	auto foreach_node = root.addNodeInFront("FOREACH");

        }
        | FOREACH lost_open_par expr AS VARNAME SV VARNAME lost_close_par stmt
        | ECHO_KW expr ';'
        | BREAK ';'
        | RETURN expr_e ';'
        | '{' stmt_list_e '}'
        ; 
 
expr    : VARNAME
	{
		auto node = root.addNodeInBack("expr");
		auto varname_node = root.addNodeInBack("VARNAME");
		root.addLink(node, varname_node, Empty{});
		$$ = node.getIndex();
	}
        | INTCONST
        {
                auto node = root.addNodeInBack("expr");
        	auto intconst_node = root.addNodeInBack("INTCONST");
        	root.addLink(node, intconst_node, Empty{});
        	$$ = node.getIndex();
        }
        | CHARCONST
        | expr '[' expr ']'
        | expr '.' expr
        | expr '+' expr
        | expr PAS expr
        | expr '-' expr
        | expr MAS expr
        | expr '*' expr
        | expr MULAS expr
        | expr '/' expr
        | expr DIVAS expr
        | expr '%' expr
        | expr MODAS expr
        | expr '=' expr
        {
        	$$ = createNode("expr", {$1, $3});
        	auto assignment_node = root.addNodeInBack("=");
        	root.addLink(root.getNodeByIndex($$), assignment_node, Empty{});
        }
        | expr EQ expr
        | expr NE expr
        | expr TEQ expr
        | expr TNE expr
        | expr '<' expr
        | expr LEQ expr
        | expr '>' expr
        | expr GEQ expr
        | expr AND expr
        | expr OR expr
        | '!' expr
        | PP expr
        | MM expr
        | expr PP
        | expr MM
        | '+' expr %prec UPLUS
        | '-' expr %prec UMINUS
        | lost_open_par expr lost_close_par
        | ARRAY lost_open_par array_members_list_e lost_close_par
        | ID lost_open_par expr_list_e lost_close_par
        | expr ARROW ID
        | expr ARROW ID lost_open_par expr_list_e lost_close_par
        | expr ARROW VARNAME
        | expr ARROW VARNAME lost_open_par expr_list_e lost_close_par
        | NEW ID
        | NEW ID lost_open_par expr_list_e lost_close_par
        | NEW VARNAME 
        | NEW VARNAME lost_open_par expr_list_e lost_close_par
        | PARENT DCOL ID lost_open_par expr_list_e lost_close_par
        ;
			
expr_e   :  /*empty*/
         | expr
         ;

expr_list   : expr 
            | expr_list ',' expr
            ; 
            
expr_list_e :  /*empty*/
            | expr_list
            ;

var_list_e  :  /*empty*/
            | var_list
            ;

var_list    : VARNAME
			| VARNAME '=' expr
            | var_list ',' VARNAME
            | var_list ',' VARNAME '=' expr
            ;
 
array_members_list_e    : /*empty*/
                        | array_members_list
                        ;

array_members_list  : array_member
                    | array_members_list ',' array_member
                    ;
                    
array_member    : expr SV expr
                | expr
                ;
            
if_stmt : IF lost_open_par expr lost_close_par stmt
        | IF lost_open_par expr lost_close_par stmt ELSE stmt
        | IF lost_open_par expr lost_close_par stmt elseif_stmt
        | IF lost_open_par expr lost_close_par stmt elseif_stmt ELSE stmt 
        ;

elseif_stmt : ELSEIF lost_open_par expr lost_close_par stmt
            | elseif_stmt ELSEIF lost_open_par expr lost_close_par stmt 
            ;
            
switch_stmt : SWITCH lost_open_par expr lost_close_par '{' case_stmt_list '}' 
            | SWITCH lost_open_par expr lost_close_par '{' case_stmt_list DEFAULT ':' stmt_list_e '}'
            ;

case_stmt_list : CASE expr ':' stmt_list_e
               | case_stmt_list  CASE expr ':' stmt_list_e
              ;

function_def : FUNCTION ID lost_open_par var_list_e lost_close_par '{' stmt_list_e '}'
             ;

class_def : CLASS ID '{' class_body_e '}'
          | CLASS ID EXTENDS ID '{' class_body_e '}'
          ;

class_body_element  : VAR VARNAME ';'
                    | PUBLIC VARNAME ';'
                    | PRIVATE VARNAME ';'
                    | PROTECTED VARNAME ';' 
                    | function_def
                    | PUBLIC function_def
                    | PRIVATE function_def
                    | PROTECTED function_def
                    ;
class_body : class_body_element
           |class_body class_body_element
           ;

class_body_e : /*empty*/
             |class_body
             ;
