%{
	#include <iostream>
	#include <string>
	#include <vector>
	#include "Graph.h"
	#include "GraphToDOT.h"
	#include "Tokens.h"
	#include <memory>
	#define YYDEBUG 1
	#define YYSTYPE int
    extern "C" int yyparse();
    extern "C" int yylen();
    extern "C" int yylex();
    extern "C" FILE* yyin;
    extern "C" int yydebug;

    struct token_type {
      int index;
      std::string value;
    };

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

	int create_op_node(std::string value, std::string op, token_type v1, token_type v2) {

                auto node = root.addNodeInBack(value);
                auto op_node = root.addNodeInBack(op);
                root.addLink(node, root.getNodeByIndex(v1.index), Empty{});
                root.addLink(node, op_node, Empty{});
                root.addLink(node, root.getNodeByIndex(v2.index), Empty{});
         	return node.getIndex();

	}

	int create_unar_op_node(std::string value, std::string op, token_type v)
	{
            auto node = root.addNodeInBack(value);
            auto unar_node = root.addNodeInBack(op);
            root.addLink(node, unar_node, Empty{});
            root.addLink(node, root.getNodeByIndex(v.index), Empty{});
            return node.getIndex();
       	}

	int createNode(std::string value, std::vector<token_type> children_index) {
		auto node = root.addNodeInBack(value);
		for(auto ptr = children_index.begin(); ptr != children_index.end(); ++ptr) {
			root.addLink(node, root.getNodeByIndex(ptr->ptr), Empty{});
		}
               	return node.getIndex();
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
		return 0;
	}
%}

%token NonTerminal BREAK CLONE ENDSWITCH HTML WHILE DO FOR FOREACH VARNAME AS SV RETURN INTCONST CHARCONST PAS DIVAS MODAS EQ NE TEQ TNE LEQ GEQ AND OR PP MM UPLUS UMINUS ARRAY ID ARROW NEW PARENT DCOL IF ELSE ELSEIF SWITCH DEFAULT CASE FUNCTION CLASS EXTENDS VAR PUBLIC PRIVATE PROTECTED ECHO_KW MAS MULAS UNDEFINED

%right '='
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
		$$.index = createNode("program", {$1});
	}
        ; 
main_stmt_tag_list  : main_stmt
			{
				$$.index = createNode("main_stmt_tag_list", {$1});
			}
                    | main_stmt_tag_list main_stmt
                    	{
                    		$$.index = createNode("main_stmt_tag_list", {$1, $2});
                    	}
                    | HTML
                    {
			auto node = root.addNodeInBack("main_stmt_tag_list");
                    	auto html_node = root.addNodeInBack(std::make_shared<HtmlToken>($1.string));
                    	root.addLink(node, html_node, Empty{});
                    	$$.index = node.getIndex();

                    }
                    | main_stmt_tag_list HTML
                    {
                    	$$.index = createNode("main_stmt_tag_list", {$1});
                    	auto html_node = root.addNodeInBack(std::string("HTML"));
                    	root.addLink(root.getNodeByIndex($$), html_node, Empty{});
                    }
                    ;
main_stmt   : class_def
	    {
	    	$$.index = createNode("main_stmt", {$1});
	    }
            | function_def
            {
            	$$.index = createNode("main_stmt", {$1});
            }
            | stmt
            {
            	$$.index = createNode("main_stmt", {$1});
            }
            ;

stmt_list   : stmt
	   {
	    	$$.index = createNode("stmt_list", {$1});
	    }
            | stmt_list stmt
            {
            	$$.index = createNode("stmt_list", {$1, $2});
            }
            ; 

stmt_list_e :  /*empty*/
	    {
	    	auto node = root.addNodeInBack("stmt_list_e");
	    	auto empty = root.addNodeInBack("empty");
	    	root.addLink(node, empty, Empty{});
	    	$$.index = node.getIndex();
	    }
            | stmt_list
            {
            	auto node = root.addNodeInBack("stmt_list_e");
            	root.addLink(node, root.getNodeByIndex($1), Empty{});
            	$$.index = node.getIndex();
            }
            ;
            
lost_close_par  : ')'	%prec ')'
		{
			auto node = root.addNodeInBack("lost_close_par");
			auto braket_node = root.addNodeInBack(")");
			root.addLink(node, braket_node, Empty{});
			$$.index = node.getIndex();
		}
                | error %prec ')'
                {
                	$$.index = createNode("lost_close_par", {$1});
                }
                ;
lost_open_par  : '('	%prec '('
		{
			auto node = root.addNodeInBack("lost_open_par");
			auto braket_node = root.addNodeInBack("(");
			root.addLink(node, braket_node, Empty{});
			$$.index = node.getIndex();
		}
                | error %prec '('
                {
                	$$ = createNode("lost_close_par", {$1});
                }
                ;
stmt    : expr_e ';'
	{
		auto node = root.addNodeInBack("stmt");
		auto semicolon_node = root.addNodeInBack(";");
		root.addLink(node, root.getNodeByIndex($1), Empty{});
		root.addLink(node, semicolon_node, Empty{});
		$$ = node.getIndex();
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
		root.addLink(node, root.getNodeByIndex($3), Empty{});
		root.addLink(node, semicolon_node1, Empty{});
		root.addLink(node, root.getNodeByIndex($5), Empty{});
		root.addLink(node, semicolon_node2, Empty{});
		root.addLink(node, root.getNodeByIndex($7), Empty{});
		root.addLink(node, root.getNodeByIndex($8), Empty{});
		root.addLink(node, root.getNodeByIndex($9), Empty{});
		$$ = node.getIndex();
        }
        | FOREACH lost_open_par expr AS VARNAME lost_close_par stmt
        {
        	auto node = root.addNodeInBack("stmt");
        	auto foreach_node = root.addNodeInBack("FOREACH");
        	auto as_node = root.addNodeInBack("AS");
        	auto varname_node = root.addNodeInBack("VARNAME");
        	root.addLink(node, foreach_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($2), Empty{});
        	root.addLink(node, root.getNodeByIndex($3), Empty{});
        	root.addLink(node, as_node, Empty{});
        	root.addLink(node, varname_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($6), Empty{});
        	root.addLink(node, root.getNodeByIndex($7), Empty{});
        	$$ = node.getIndex();
        }
        | FOREACH lost_open_par expr AS VARNAME SV VARNAME lost_close_par stmt
        {
        	auto node = root.addNodeInBack("stmt");
                auto foreach_node = root.addNodeInBack("FOREACH");
                auto as_node = root.addNodeInBack("AS");
                auto varname_node1 = root.addNodeInBack("VARNAME");
                auto sv_node = root.addNodeInBack("SV");
                auto varname_node2 = root.addNodeInBack("VARNAME");
                root.addLink(node, foreach_node, Empty{});
                root.addLink(node, root.getNodeByIndex($2), Empty{});
                root.addLink(node, root.getNodeByIndex($3), Empty{});
                root.addLink(node, as_node, Empty{});
                root.addLink(node, varname_node1, Empty{});
                root.addLink(node, sv_node, Empty{});
                root.addLink(node, varname_node2, Empty{});
                root.addLink(node, root.getNodeByIndex($8), Empty{});
                root.addLink(node, root.getNodeByIndex($9), Empty{});
                $$ = node.getIndex();
        }

        | ECHO_KW expr ';'
        {
        	auto node = root.addNodeInBack("stmt");
        	auto echo_node = root.addNodeInBack("ECHO_KW");
        	auto semicolon_node = root.addNodeInBack(";");
        	root.addLink(node, echo_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($2), Empty{});
        	root.addLink(node, semicolon_node, Empty{});
        	$$ = node.getIndex();
        }
        | BREAK ';'
        {
        	auto node = root.addNodeInBack("stmt");
        	auto break_node = root.addNodeInBack("BREAK");
        	auto semicolon_node = root.addNodeInBack(";");
        	root.addLink(node, break_node, Empty{});
        	root.addLink(node, semicolon_node, Empty{});
        	$$ = node.getIndex();
        }
        | RETURN expr_e ';'
        {
        	auto node = root.addNodeInBack("stmt");
        	auto return_node = root.addNodeInBack("RETURN");
        	auto semicolon_node = root.addNodeInBack(";");
        	root.addLink(node, return_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($2), Empty{});
        	root.addLink(node, semicolon_node, Empty{});
        	$$ = node.getIndex();
        }
        | '{' stmt_list_e '}'
        {
        	auto node = root.addNodeInBack("stmt");
        	auto openbreaket_node = root.addNodeInBack("{");
        	auto closebreaket_node = root.addNodeInBack("}");
        	root.addLink(node, openbreaket_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($2), Empty{});
        	root.addLink(node, closebreaket_node, Empty{});
        	$$ = node.getIndex();
        }
        ; 
 
expr    : var_name
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
        {
        	auto node = root.addNodeInBack("expr");
        	auto charconst_node = root.addNodeInBack("CHARCONST");
        	root.addLink(node, charconst_node, Empty{});
        	$$ = node.getIndex();
        }
        | expr '[' expr ']'
        {
        	auto node = root.addNodeInBack("expr");
        	auto openbreaket_node = root.addNodeInBack("[");
        	auto closebreaket_node = root.addNodeInBack("]");
        	root.addLink(node, root.getNodeByIndex($1), Empty{});
        	root.addLink(node, openbreaket_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($3), Empty{});
        	root.addLink(node, closebreaket_node, Empty{});
        	$$ = node.getIndex();
        }
        | expr '.' expr
        {
        	$$ = create_op_node("expr", ".", $1, $3);
        }
        | expr '+' expr
        {
        	$$ = create_op_node("expr", "+", $1, $3);
        }
        | expr PAS expr
        {
        	$$ = create_op_node("expr", "PAS", $1, $3);
        }
        | expr '-' expr
        {
        	$$ = create_op_node("expr", "-", $1, $3);
        }
        | expr MAS expr
        {
        	$$ = create_op_node("expr", "MAS", $1, $3);
        }
        | expr '*' expr
        {
        	$$ = create_op_node("expr", "*", $1, $3);
        }
        | expr MULAS expr
        {
        	$$ = create_op_node("expr", "MULAS", $1, $3);
        }
        | expr '/' expr
        {
        	$$ = create_op_node("expr", "/", $1, $3);
        }
        | expr DIVAS expr
        {
        	$$ = create_op_node("expr", "DIVAS", $1, $3);
        }
        | expr '%' expr
        {
        	$$ = create_op_node("expr", "%", $1, $3);
        }
        | expr MODAS expr
        | expr '=' expr
        {
        	$$ = create_op_node("expr", "=", $1, $3);
        }
        | expr EQ expr
        {
        	$$ = create_op_node("expr", "==", $1, $3);
        }
        | expr NE expr
         {
         	$$ = create_op_node("expr", "!=", $1, $3);
         }
        | expr TEQ expr
        {
        	$$ = create_op_node("expr", "TEQ", $1, $3);
        }
        | expr TNE expr
         {
         	$$ = create_op_node("expr", "TNE", $1, $3);
         }
        | expr '<' expr
        {
        	$$ = create_op_node("expr", "<", $1, $3);
        }
        | expr LEQ expr
        {
        	$$ = create_op_node("expr", "<=", $1, $3);
        }
        | expr '>' expr
        {
        	$$ = create_op_node("expr", ">", $1, $3);
        }
        | expr GEQ expr
        {
        	$$ = create_op_node("expr", ">=", $1, $3);
        }
        | expr AND expr
        {
        	$$ = create_op_node("expr", "&&", $1, $3);
        }
        | expr OR expr
        {
        	$$ = create_op_node("expr", "||", $1, $3);
        }
        | '!' expr
        {
        	$$ = create_unar_op_node("expr", "!", $2);
        }
        | PP expr
        {
		$$ = create_unar_op_node("expr", "PP", $2);
	}
        | MM expr
        {
		$$ = create_unar_op_node("expr", "MM", $2);
	}
        | expr PP
        {
        	auto node = root.addNodeInBack("expr");
        	auto unar_node = root.addNodeInBack("PP");
        	root.addLink(node, root.getNodeByIndex($2), Empty{});
        	root.addLink(node, unar_node, Empty{});
        	$$ = node.getIndex();
	}
        | expr MM
        {
        	auto node = root.addNodeInBack("expr");
        	auto unar_node = root.addNodeInBack("MM");
        	root.addLink(node, root.getNodeByIndex($2), Empty{});
        	root.addLink(node, unar_node, Empty{});
        	$$ = node.getIndex();
	}
        | '+' expr %prec UPLUS
        {
        	$$ = create_unar_op_node("expr", "UNAR +", $2);
        }
        | '-' expr %prec UMINUS
        {
        	$$ = create_unar_op_node("expr", "UNAR -", $2);
        }
        | lost_open_par expr lost_close_par
        {
        	auto node = root.addNodeInBack("expr");
        	root.addLink(node, root.getNodeByIndex($1), Empty{});
        	root.addLink(node, root.getNodeByIndex($2), Empty{});
        	root.addLink(node, root.getNodeByIndex($3), Empty{});
        	$$ = node.getIndex();
        }
        | ARRAY lost_open_par array_members_list_e lost_close_par
        {
        	auto node = root.addNodeInBack("expr");
        	auto array_node = root.addNodeInBack("ARRAY");
        	root.addLink(node, array_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($2), Empty{});
        	root.addLink(node, root.getNodeByIndex($3), Empty{});
        	root.addLink(node, root.getNodeByIndex($4), Empty{});
        	$$ = node.getIndex();
        }
        | ID lost_open_par expr_list_e lost_close_par
        {
        	auto node = root.addNodeInBack("expr");
        	auto id_node = root.addNodeInBack("ID");
        	root.addLink(node, id_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($2), Empty{});
        	root.addLink(node, root.getNodeByIndex($3), Empty{});
               	root.addLink(node, root.getNodeByIndex($4), Empty{});
               	$$ = node.getIndex();

        }
        | expr ARROW ID
        {
        	auto node = root.addNodeInBack("expr");
        	auto arrow_node = root.addNodeInBack("ARROW");
        	auto id_node = root.addNodeInBack("ID");
        	root.addLink(node, root.getNodeByIndex($1), Empty{});
        	root.addLink(node, arrow_node, Empty{});
        	root.addLink(node, id_node, Empty{});
        	$$ = node.getIndex();
        }
        | expr ARROW ID lost_open_par expr_list_e lost_close_par
        {
               	auto node = root.addNodeInBack("expr");
               	auto arrow_node = root.addNodeInBack("ARROW");
                auto id_node = root.addNodeInBack("ID");
                root.addLink(node, root.getNodeByIndex($1), Empty{});
                root.addLink(node, arrow_node, Empty{});
                root.addLink(node, root.getNodeByIndex($4), Empty{});
                root.addLink(node, root.getNodeByIndex($5), Empty{});
                root.addLink(node, root.getNodeByIndex($6), Empty{});
                $$ = node.getIndex();
        }
        | expr ARROW VARNAME
        {
        	auto node = root.addNodeInBack("expr");
        	auto arrow_node = root.addNodeInBack("ARROW");
        	auto varname_node = root.addNodeInBack("VARNAME");
        	root.addLink(node, root.getNodeByIndex($1), Empty{});
        	root.addLink(node, arrow_node, Empty{});
        	root.addLink(node, varname_node, Empty{});
        	$$ = node.getIndex();
        }
        | expr ARROW VARNAME lost_open_par expr_list_e lost_close_par
        {
        	auto node = root.addNodeInBack("expr");
                auto arrow_node = root.addNodeInBack("ARROW");
                auto varname_node = root.addNodeInBack("VARNAME");
                root.addLink(node, root.getNodeByIndex($1), Empty{});
                root.addLink(node, arrow_node, Empty{});
                root.addLink(node, varname_node, Empty{});
                root.addLink(node, root.getNodeByIndex($4), Empty{});
                root.addLink(node, root.getNodeByIndex($5), Empty{});
                root.addLink(node, root.getNodeByIndex($6), Empty{});
                $$ = node.getIndex();
        }
        | NEW ID
        {
        	auto node = root.addNodeInBack("expr");
        	auto new_node = root.addNodeInBack("NEW");
        	auto id_node = root.addNodeInBack("ID");
        	root.addLink(node, new_node, Empty{});
        	root.addLink(node, id_node, Empty{});
        	$$ = node.getIndex();
        }
        | NEW ID lost_open_par expr_list_e lost_close_par
        {
        	auto node = root.addNodeInBack("expr");
        	auto new_node = root.addNodeInBack("NEW");
        	auto id_node = root.addNodeInBack("ID");
        	root.addLink(node, new_node, Empty{});
        	root.addLink(node, id_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($3), Empty{});
        	root.addLink(node, root.getNodeByIndex($4), Empty{});
        	root.addLink(node, root.getNodeByIndex($5), Empty{});
        	$$ = node.getIndex();
        }
        | NEW VARNAME
        {
        	auto node = root.addNodeInBack("expr");
        	auto new_node = root.addNodeInBack("NEW");
        	auto varname_node = root.addNodeInBack("VARNAME");
        	root.addLink(node, new_node, Empty{});
        	root.addLink(node, varname_node, Empty{});
        	$$ = node.getIndex();
        }
        | NEW VARNAME lost_open_par expr_list_e lost_close_par
        {
        	auto node = root.addNodeInBack("expr");
        	auto new_node = root.addNodeInBack("NEW");
        	auto varname_node = root.addNodeInBack("VARNAME");
        	root.addLink(node, new_node, Empty{});
        	root.addLink(node, varname_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($3), Empty{});
        	root.addLink(node, root.getNodeByIndex($4), Empty{});
        	root.addLink(node, root.getNodeByIndex($5), Empty{});
        	$$ = node.getIndex();
        }
        | PARENT DCOL ID lost_open_par expr_list_e lost_close_par
        {
        	auto node = root.addNodeInBack("expr");
        	auto parent_node = root.addNodeInBack("PARENT");
        	auto dcol_node = root.addNodeInBack("DCOL");
        	auto id_node = root.addNodeInBack("ID");
        	root.addLink(node, parent_node, Empty{});
        	root.addLink(node, dcol_node, Empty{});
        	root.addLink(node, id_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($4), Empty{});
        	root.addLink(node, root.getNodeByIndex($5), Empty{});
        	root.addLink(node, root.getNodeByIndex($6), Empty{});
        	$$ = node.getIndex();
        }
        ;
			
expr_e   :  /*empty*/
	{
		auto node = root.addNodeInBack("expr_e");
		auto empty = root.addNodeInBack("empty");
		root.addLink(node, empty, Empty{});
		$$ = node.getIndex();
	}
         | expr
         {
         	auto node = root.addNodeInBack("expr_e");
         	root.addLink(node, root.getNodeByIndex($1), Empty{});
         	$$ = node.getIndex();
         }
         ;

expr_list   : expr
	   {
		auto node = root.addNodeInBack("expr_list");
		root.addLink(node, root.getNodeByIndex($1), Empty{});
		$$ = node.getIndex();
           }
            | expr_list ',' expr
            {
            	auto node = root.addNodeInBack("expr_list");
            	auto dot_node = root.addNodeInBack(",");
            	root.addLink(node, root.getNodeByIndex($1), Empty{});
            	root.addLink(node, dot_node, Empty{});
            	root.addLink(node, root.getNodeByIndex($3), Empty{});
            	$$ = node.getIndex();
            }
            ; 
            
expr_list_e :  /*empty*/
	   {
	   	auto node = root.addNodeInBack("expr_list");
	   	auto empty = root.addNodeInBack("empty");
	   	root.addLink(node, empty, Empty{});
	   	$$ = node.getIndex();
	   }
            | expr_list
            {
            	auto node = root.addNodeInBack("expr_list");
            	root.addLink(node, root.getNodeByIndex($1), Empty{});
            	$$ = node.getIndex();
            }
            ;

var_list_e  :  /*empty*/
	   {
	   	auto node = root.addNodeInBack("var_list_e");
	   	auto empty = root.addNodeInBack("empty");
	   	root.addLink(node, empty, Empty{});
	   	$$ = node.getIndex();
	   }
            | var_list
            {
            	auto node = root.addNodeInBack("var_list_e");
            	root.addLink(node, root.getNodeByIndex($1), Empty{});
            	$$ = node.getIndex();
            }
            ;

var_list    : VARNAME
	    {
	    	auto node = root.addNodeInBack("var_list");
	    	auto varname_node = root.addNodeInBack("VARNAME");
	    	root.addLink(node, varname_node, Empty{});
	    	$$ = node.getIndex();
	    }
	    | VARNAME '=' expr
	    {
	    	auto node = root.addNodeInBack("var_list");
	    	auto varname_node = root.addNodeInBack("VARNAME");
	    	auto assignment_node = root.addNodeInBack("=");
	    	root.addLink(node, varname_node, Empty{});
	    	root.addLink(node, assignment_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex($3), Empty{});
	    	$$ = node.getIndex();
	    }
            | var_list ',' VARNAME
	    {
	    	auto node = root.addNodeInBack("var_list");
	    	auto comma_node = root.addNodeInBack(",");
	    	auto varname_node = root.addNodeInBack("VARNAME");
	    	root.addLink(node, root.getNodeByIndex($1), Empty{});
	    	root.addLink(node, comma_node, Empty{});
	    	root.addLink(node, varname_node, Empty{});
	    	$$ = node.getIndex();
	    }
            | var_list ',' VARNAME '=' expr
	    {
	    	auto node = root.addNodeInBack("var_list");
	    	auto comma_node = root.addNodeInBack(",");
	    	auto varname_node = root.addNodeInBack("VARNAME");
	    	auto assignment_node = root.addNodeInBack("=");
	    	root.addLink(node, root.getNodeByIndex($1), Empty{});
	    	root.addLink(node, comma_node, Empty{});
	    	root.addLink(node, varname_node, Empty{});
	    	root.addLink(node, assignment_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex($5), Empty{});
	    	$$ = node.getIndex();
	    }
            ;
 
array_members_list_e    : /*empty*/
			{
				auto node = root.addNodeInBack("array_members_list_e");
				auto empty_node = root.addNodeInBack("empty");
				root.addLink(node, empty_node, Empty{});
				$$ = node.getIndex();
			}
                        | array_members_list
                        {
                        	auto node = root.addNodeInBack("array_members_list_e");
				root.addLink(node, root.getNodeByIndex($1), Empty{});
				$$ = node.getIndex();
                        }
                        ;

array_members_list  : array_member
		    {
                        	auto node = root.addNodeInBack("array_members_list");
                        	root.addLink(node, root.getNodeByIndex($1), Empty{});
                        	$$ = node.getIndex();

		    }
                    | array_members_list ',' array_member
                    {
                    	auto node = root.addNodeInBack("array_members_list");
                    	auto comma_node = root.addNodeInBack(",");
                    	root.addLink(node, root.getNodeByIndex($1), Empty{});
                    	root.addLink(node, comma_node, Empty{});
                    	root.addLink(node, root.getNodeByIndex($3), Empty{});
                    	$$ = node.getIndex();
                    }
                    ;
                    
array_member    : expr SV expr
		{
			auto node = root.addNodeInBack("array_member");
			auto sv_node = root.addNodeInBack("=>");
			root.addLink(node, root.getNodeByIndex($1), Empty{});
			root.addLink(node, sv_node, Empty{});
			root.addLink(node, root.getNodeByIndex($3), Empty{});
			$$ = node.getIndex();
		}
                | expr
                {
                	auto node = root.addNodeInBack("array_member");
                	root.addLink(node, root.getNodeByIndex($1), Empty{});
                }
                ;
            
if_stmt : IF lost_open_par expr lost_close_par stmt
	{
		auto node = root.addNodeInBack("if_stmt");
		auto if_node = root.addNodeInBack("if");
		root.addLink(node, if_node, Empty{});
		root.addLink(node, root.getNodeByIndex($2), Empty{});
		root.addLink(node, root.getNodeByIndex($3), Empty{});
		root.addLink(node, root.getNodeByIndex($4), Empty{});
		root.addLink(node, root.getNodeByIndex($5), Empty{});
		$$ = node.getIndex();
	}
        | IF lost_open_par expr lost_close_par stmt ELSE stmt
        {
        		auto node = root.addNodeInBack("if_stmt");
        		auto if_node = root.addNodeInBack("if");
        		auto else_node = root.addNodeInBack("else");
        		root.addLink(node, if_node, Empty{});
        		root.addLink(node, root.getNodeByIndex($2), Empty{});
        		root.addLink(node, root.getNodeByIndex($3), Empty{});
        		root.addLink(node, root.getNodeByIndex($4), Empty{});
        		root.addLink(node, root.getNodeByIndex($5), Empty{});
        		root.addLink(node, else_node, Empty{});
        		root.addLink(node, root.getNodeByIndex($7), Empty{});
        		$$ = node.getIndex();
        }
        | IF lost_open_par expr lost_close_par stmt elseif_stmt
	{
		auto node = root.addNodeInBack("if_stmt");
		auto if_node = root.addNodeInBack("if");
		root.addLink(node, if_node, Empty{});
		root.addLink(node, root.getNodeByIndex($2), Empty{});
		root.addLink(node, root.getNodeByIndex($3), Empty{});
		root.addLink(node, root.getNodeByIndex($4), Empty{});
		root.addLink(node, root.getNodeByIndex($5), Empty{});
		root.addLink(node, root.getNodeByIndex($6), Empty{});
		$$ = node.getIndex();
	}
        | IF lost_open_par expr lost_close_par stmt elseif_stmt ELSE stmt
        {
        	auto node = root.addNodeInBack("if_stmt");
        	auto if_node = root.addNodeInBack("if");
        	auto else_node = root.addNodeInBack("else");
        	root.addLink(node, if_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($2), Empty{});
        	root.addLink(node, root.getNodeByIndex($3), Empty{});
        	root.addLink(node, root.getNodeByIndex($4), Empty{});
        	root.addLink(node, root.getNodeByIndex($5), Empty{});
        	root.addLink(node, root.getNodeByIndex($6), Empty{});
        	root.addLink(node, else_node, Empty{});
        	root.addLink(node, root.getNodeByIndex($8), Empty{});
        	$$ = node.getIndex();
        }
        ;

elseif_stmt : ELSEIF lost_open_par expr lost_close_par stmt
	    {
	    	auto node = root.addNodeInBack("elseif_stmt");
	    	auto elseif_node = root.addNodeInBack("elseif");
	    	root.addLink(node, elseif_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex($2), Empty{});
	    	root.addLink(node, root.getNodeByIndex($3), Empty{});
	    	root.addLink(node, root.getNodeByIndex($4), Empty{});
	    	root.addLink(node, root.getNodeByIndex($5), Empty{});
	    	$$ = node.getIndex();
	    }
            | elseif_stmt ELSEIF lost_open_par expr lost_close_par stmt
            {
            	auto node = root.addNodeInBack("elseif_stmt");
            	auto elseif_node = root.addNodeInBack("elseif");
            	root.addLink(node, root.getNodeByIndex($1), Empty{});
            	root.addLink(node, elseif_node, Empty{});
            	root.addLink(node, root.getNodeByIndex($3), Empty{});
            	root.addLink(node, root.getNodeByIndex($4), Empty{});
            	root.addLink(node, root.getNodeByIndex($5), Empty{});
            	root.addLink(node, root.getNodeByIndex($6), Empty{});
            	$$ = node.getIndex();
            }
            ;
            
switch_stmt : SWITCH lost_open_par expr lost_close_par '{' case_stmt_list '}'
	    {
	    	auto node = root.addNodeInBack("switch_stmt");
	    	auto switch_node = root.addNodeInBack("switch");
	    	auto openbreacket_node = root.addNodeInBack("{");
	    	auto closebreacket_node = root.addNodeInBack("}");
	    	root.addLink(node, switch_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex($2), Empty{});
	    	root.addLink(node, root.getNodeByIndex($3), Empty{});
	    	root.addLink(node, root.getNodeByIndex($4), Empty{});
	    	root.addLink(node, openbreacket_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex($6), Empty{});
	    	root.addLink(node, closebreacket_node, Empty{});
	    	$$ = node.getIndex();
	    }
            | SWITCH lost_open_par expr lost_close_par '{' case_stmt_list DEFAULT ':' stmt_list_e '}'
	    {
	    	auto node = root.addNodeInBack("switch_stmt");
	    	auto switch_node = root.addNodeInBack("switch");
	    	auto openbreacket_node = root.addNodeInBack("{");
	    	auto closebreacket_node = root.addNodeInBack("}");
	    	auto default_node = root.addNodeInBack("default");
	    	auto colon_node = root.addNodeInBack(":");
	    	root.addLink(node, switch_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex($2), Empty{});
	    	root.addLink(node, root.getNodeByIndex($3), Empty{});
	    	root.addLink(node, root.getNodeByIndex($4), Empty{});
	    	root.addLink(node, openbreacket_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex($6), Empty{});
	    	root.addLink(node, default_node, Empty{});
	    	root.addLink(node, colon_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex($9), Empty{});
	    	root.addLink(node, closebreacket_node, Empty{});
	    	$$ = node.getIndex();
	    }
            ;

case_stmt_list : CASE expr ':' stmt_list_e
	       {
			auto node = root.addNodeInBack("case_stmt_list");
			auto case_node = root.addNodeInBack("case");
			auto colon_node = root.addNodeInBack(":");
			root.addLink(node, case_node, Empty{});
			root.addLink(node, root.getNodeByIndex($2), Empty{});
			root.addLink(node, colon_node, Empty{});
			root.addLink(node, root.getNodeByIndex($4), Empty{});
			$$ = node.getIndex();
	       }
               | case_stmt_list  CASE expr ':' stmt_list_e
               {
               		auto node = root.addNodeInBack("case_stmt_list");
               		auto case_node = root.addNodeInBack("case");
               		auto colon_node = root.addNodeInBack(":");
               		root.addLink(node, root.getNodeByIndex($1), Empty{});
               		root.addLink(node, case_node, Empty{});
               		root.addLink(node, root.getNodeByIndex($3), Empty{});
               		root.addLink(node, colon_node, Empty{});
               		root.addLink(node, root.getNodeByIndex($5), Empty{});
               		$$ = node.getIndex();
               }
              ;

function_def : FUNCTION ID lost_open_par var_list_e lost_close_par '{' stmt_list_e '}'
	     {
	     	auto node = root.addNodeInBack("function_def");
	     	auto function_node = root.addNodeInBack("function");
	     	auto id_node = root.addNodeInBack("ID");
	     	auto openbreaket_node = root.addNodeInBack("{");
	     	auto closebreaket_node = root.addNodeInBack("}");
	     	root.addLink(node, function_node, Empty{});
	     	root.addLink(node, id_node, Empty{});
	     	root.addLink(node, root.getNodeByIndex($3), Empty{});
	     	root.addLink(node, root.getNodeByIndex($4), Empty{});
	     	root.addLink(node, root.getNodeByIndex($5), Empty{});
	     	root.addLink(node, openbreaket_node, Empty{});
	     	root.addLink(node, root.getNodeByIndex($7), Empty{});
	     	root.addLink(node, closebreaket_node, Empty{});
	     	$$ = node.getIndex();
	     }
             ;

class_def : CLASS ID '{' class_body_e '}'
	  {
	  	auto node = root.addNodeInBack("class_def");
	  	auto class_node = root.addNodeInBack("class");
	  	auto id_node = root.addNodeInBack("ID");
	  	auto openbreaket_node = root.addNodeInBack("{");
	  	auto closebreaket_node = root.addNodeInBack("}");
	  	root.addLink(node, class_node, Empty{});
	  	root.addLink(node, id_node, Empty{});
	  	root.addLink(node, openbreaket_node, Empty{});
	  	root.addLink(node, root.getNodeByIndex($4), Empty{});
	  	root.addLink(node, closebreaket_node, Empty{});
	  	$$ = node.getIndex();
	  }
          | CLASS ID EXTENDS ID '{' class_body_e '}'
          {
		auto node = root.addNodeInBack("class_def");
	  	auto class_node = root.addNodeInBack("class");
	  	auto id1_node = root.addNodeInBack("ID");
	  	auto extends_node = root.addNodeInBack("extends");
	  	auto id2_node = root.addNodeInBack("ID");
	  	auto openbreaket_node = root.addNodeInBack("{");
	  	auto closebreaket_node = root.addNodeInBack("}");
	  	root.addLink(node, class_node, Empty{});
	  	root.addLink(node, id1_node, Empty{});
	  	root.addLink(node, extends_node, Empty{});
	  	root.addLink(node, id2_node, Empty{});
	  	root.addLink(node, openbreaket_node, Empty{});
	  	root.addLink(node, root.getNodeByIndex($6), Empty{});
	  	root.addLink(node, closebreaket_node, Empty{});
	  	$$ = node.getIndex();
          }
          ;

class_body_element  : VAR VARNAME ';'
		    {
		    	auto node = root.addNodeInBack("class_body_element");
		    	auto var_node = root.addNodeInBack("var");
		    	auto varname_node = root.addNodeInBack("VARNAME");
		    	auto semicolon_node = root.addNodeInBack(";");
		    	root.addLink(node, var_node, Empty{});
		    	root.addLink(node, varname_node, Empty{});
		    	root.addLink(node, semicolon_node, Empty{});
		    	$$ = node.getIndex();
		    }
                    | PUBLIC VARNAME ';'
		    {
		    	auto node = root.addNodeInBack("class_body_element");
		    	auto public_node = root.addNodeInBack("public");
		    	auto varname_node = root.addNodeInBack("VARNAME");
		    	auto semicolon_node = root.addNodeInBack(";");
		    	root.addLink(node, public_node, Empty{});
		    	root.addLink(node, varname_node, Empty{});
		    	root.addLink(node, semicolon_node, Empty{});
		    	$$ = node.getIndex();
		    }
                    | PRIVATE VARNAME ';'
		    {
		    	auto node = root.addNodeInBack("class_body_element");
		    	auto private_node = root.addNodeInBack("private");
		    	auto varname_node = root.addNodeInBack("VARNAME");
		    	auto semicolon_node = root.addNodeInBack(";");
		    	root.addLink(node, private_node, Empty{});
		    	root.addLink(node, varname_node, Empty{});
		    	root.addLink(node, semicolon_node, Empty{});
		    	$$ = node.getIndex();
		    }
                    | PROTECTED VARNAME ';'
		    {
		    	auto node = root.addNodeInBack("class_body_element");
		    	auto protected_node = root.addNodeInBack("protected");
		    	auto varname_node = root.addNodeInBack("VARNAME");
		    	auto semicolon_node = root.addNodeInBack(";");
		    	root.addLink(node, protected_node, Empty{});
		    	root.addLink(node, varname_node, Empty{});
		    	root.addLink(node, semicolon_node, Empty{});
		    	$$ = node.getIndex();
		    }
                    | function_def
                    {
                    	auto node = root.addNodeInBack("class_body_element");
                    	root.addLink(node, root.getNodeByIndex($1), Empty{});
                    	$$ = node.getIndex();
                    }
                    | PUBLIC function_def
                    {
                    	auto node = root.addNodeInBack("class_body_element");
                    	auto public_node = root.addNodeInBack("public");
                    	root.addLink(node, public_node, Empty{});
                    	root.addLink(node, root.getNodeByIndex($2), Empty{});
                    	$$ = node.getIndex();
                    }
                    | PRIVATE function_def
                    {
                    	auto node = root.addNodeInBack("class_body_element");
                    	auto private_node = root.addNodeInBack("private");
                    	root.addLink(node, private_node, Empty{});
                    	root.addLink(node, root.getNodeByIndex($2), Empty{});
                    	$$ = node.getIndex();
                    }
                    | PROTECTED function_def
                    {
                    	auto node = root.addNodeInBack("class_body_element");
                    	auto protected_node = root.addNodeInBack("protected");
                    	root.addLink(node, protected_node, Empty{});
                    	root.addLink(node, root.getNodeByIndex($2), Empty{});
                    	$$ = node.getIndex();
                    }
                    ;
class_body : class_body_element
	   {
		auto node = root.addNodeInBack("class_body");
		root.addLink(node, root.getNodeByIndex($1), Empty{});
		$$ = node.getIndex();
	   }
           |class_body class_body_element
	   {
		auto node = root.addNodeInBack("class_body");
		root.addLink(node, root.getNodeByIndex($1), Empty{});
		root.addLink(node, root.getNodeByIndex($2), Empty{});
		$$ = node.getIndex();
	   }
           ;

class_body_e : /*empty*/
             {
		auto node = root.addNodeInBack("class_body_e");
		auto empty_node = root.addNodeInBack("empty");
		root.addLink(node, empty_node, Empty{});
		$$ = node.getIndex();
             }
             |class_body
             {
             	auto node = root.addNodeInBack("class_body_e");
             	root.addLink(node, root.getNodeByIndex($1), Empty{});
             	$$.index = node.getIndex();
             }
             ;


var_name : VARNAME
	 {
		auto node = root.addNodeInBack(std::make_shared<VarName>($1.string))
		$$.string = $1.string;
		$$.index = node.getIndex();
	 }
	 ;