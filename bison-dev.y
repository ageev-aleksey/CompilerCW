%{
	#include "help_functions.h"
	#include "Graph.h"
	#include "Tokens.h"
	#include <memory>
        #define YYDEBUG 1
        #define YYSTYPE struct token_type
        extern Graph<std::shared_ptr<Token>, Empty> root;
%}

%token  NON_TERM BREAK CLONE ENDSWITCH HTML WHILE DO FOR FOREACH VARNAME AS SV RETURN INTCONST CHARCONST PAS DIVAS MODAS EQ NE TEQ TNE LEQ GEQ AND OR PP MM UPLUS UMINUS ARRAY ID ARROW NEW PARENT DCOL IF ELSE ELSEIF SWITCH DEFAULT CASE FUNCTION CLASS EXTENDS VAR PUBLIC PRIVATE PROTECTED ECHO_KW MAS MULAS UNDEFINED

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
                    | html
			{
				$$.index = createNode("main_stmt_tag_list", {$1});
			}
                    | main_stmt_tag_list html
			{
				$$.index = createNode("main_stmt_tag_list", {$1, $2});
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
            	$$.index = createNode("stmt_list_e", {});
            }
            | stmt_list
            {
            	$$.index = createNode("stmt_list_e", {$1});
            }
            ;

lost_close_par  : ')'	%prec ')'
		{

		}
                | error %prec ')'
		{
		}
                ;

lost_open_par  : '('	%prec '('
		{

		}
                | error %prec '('
                {

                }
                ;


expr    : var_name
	{
		$$.index = $1.index;
	}
        | int_const
        {
		$$.index = $1.index;
        }
        | char_const
        {
        	$$.index = $1.index;
        }
        | expr '[' expr ']'
        {
		//TODO !
        }
        | expr '.' expr
        {
		$$.index = createBinaryOperation(".",BinaryOperation::Type::FUNCTION_CALL, $1, $3);
        }
        | expr '+' expr
        {
		$$.index = createBinaryOperation("+",BinaryOperation::Type::MATH, $1, $3);
        }
        | expr PAS expr
        {
		$$.index = createBinaryOperation("PAS",BinaryOperation::Type::MATH, $1, $3);
        }
        | expr '-' expr
        {
		$$.index = createBinaryOperation("-",BinaryOperation::Type::MATH, $1, $3);
        }
        | expr MAS expr
        {
		$$.index = createBinaryOperation("MAS",BinaryOperation::Type::MATH, $1, $3);
        }
        | expr '*' expr
        {
		$$.index = createBinaryOperation("*", BinaryOperation::Type::MATH, $1, $3);
        }
        | expr MULAS expr
        {
		$$.index = createBinaryOperation("MULAS",BinaryOperation::Type::MATH, $1, $3);
        }
        | expr '/' expr
        {
		$$.index = createBinaryOperation("/",BinaryOperation::Type::MATH, $1, $3);
        }
        | expr DIVAS expr
        {
		$$.index = createBinaryOperation("DIVAS",BinaryOperation::Type::MATH, $1, $3);
        }
        | expr '%' expr
        {
		$$.index = createBinaryOperation("%",BinaryOperation::Type::MATH, $1, $3);
        }
        | expr MODAS expr
        {
		$$.index = createBinaryOperation("MODAS",BinaryOperation::Type::MATH, $1, $3);
        }
        | expr '=' expr
	{
		$$.index = createBinaryOperation("=",BinaryOperation::Type::MATH, $1, $3);
        }
        | expr EQ expr
        {
		$$.index = createBinaryOperation($2.string,BinaryOperation::Type::LOGICAL, $1, $3);
        }
        | expr NE expr
         {
		$$.index = createBinaryOperation($2.string,BinaryOperation::Type::LOGICAL, $1, $3);
         }
        | expr TEQ expr
        {
		$$.index = createBinaryOperation($2.string,BinaryOperation::Type::LOGICAL, $1, $3);
        }
        | expr TNE expr
         {
		$$.index = createBinaryOperation($2.string,BinaryOperation::Type::LOGICAL, $1, $3);
         }
        | expr '<' expr
        {
		$$.index = createBinaryOperation($2.string,BinaryOperation::Type::LOGICAL, $1, $3);
        }
        | expr LEQ expr
        {
		$$.index = createBinaryOperation($2.string,BinaryOperation::Type::LOGICAL, $1, $3);
        }
        | expr '>' expr
        {
		$$.index = createBinaryOperation($2.string,BinaryOperation::Type::LOGICAL, $1, $3);
        }
        | expr GEQ expr
        {
		$$.index = createBinaryOperation($2.string,BinaryOperation::Type::LOGICAL, $1, $3);
        }
        | expr AND expr
        {
		$$.index = createBinaryOperation($2.string,BinaryOperation::Type::LOGICAL, $1, $3);
        }
        | expr OR expr
        {
		$$.index = createBinaryOperation($2.string,BinaryOperation::Type::LOGICAL, $1, $3);
        }
        | '!' expr
        {
		$$.index = createUnaryOperation($1.string,UnaryOperation::Type::LOGICAL, $2);
        }
        | PP expr
        {
		$$.index = createUnaryOperation($1.string, UnaryOperation::Type::LOGICAL, $2);
	}
        | MM expr
        {
		$$.index = createUnaryOperation($1.string,UnaryOperation::Type::LOGICAL, $2);
	}
        | expr PP
        {
		//TODO ?
	}
        | expr MM
        {
		//TODO ?
	}
        | '+' expr %prec UPLUS
        {
		$$.index = createUnaryOperation($1.string,UnaryOperation::Type::LOGICAL, $2);
        }
        | '-' expr %prec UMINUS
        {
		$$.index = createUnaryOperation($1.string,UnaryOperation::Type::LOGICAL, $2);
        }
        | lost_open_par expr lost_close_par
        {
		$$ = $2;
        }
        | ARRAY lost_open_par array_members_list_e lost_close_par
        {

        }
        | ID lost_open_par expr_list_e lost_close_par
        {


        }
        | expr ARROW ID
        {

        }
        | expr ARROW ID lost_open_par expr_list_e lost_close_par
        {

        }
        | expr ARROW VARNAME
        {

        }
        | expr ARROW VARNAME lost_open_par expr_list_e lost_close_par
        {

        }
        | NEW ID
        {

        }
        | NEW ID lost_open_par expr_list_e lost_close_par
        {
		//call function
        }
        | NEW VARNAME
        {
		//create ?
        }
        | NEW VARNAME lost_open_par expr_list_e lost_close_par
        {
		//create ?
        }
        | PARENT DCOL ID lost_open_par expr_list_e lost_close_par
        {
		//?
        }
        ;


expr_list_e :  /*empty*/
	   {

	   }
            | expr_list
            {

            }
            ;

expr_list   : expr
	   {

           }
            | expr_list ',' expr
            {

            }
            ;


stmt    : expr_e semicolon
	{
		auto node = root.addNodeInBack(std::make_shared<Token>("stmt"));
		root.addLink(node, root.getNodeByIndex($1.index), Empty{});
		$$.index = node.getIndex();
	}
        | if_stmt
        {
        	$$.index = createNode("stmt", {$1});
        }
        | switch_stmt
        {
        	$$.index = createNode("stmt", {$1});
        }
        | while lost_open_par expr lost_close_par stmt
        {
		$$.index = createNode("main_stmt", {$1, $2, $3, $4, $5});
        }
        | do open_breaket stmt_list_e close_breaket while lost_open_par expr lost_close_par semicolon
        {
		$$ = $1;
		auto node = root.get($$.index);
		root.addLink(node, root.get($3.index), Empty{});
		root.addLink(node, root.get($7.index), Empty{});
        }
        | for lost_open_par expr_e semicolon expr_e semicolon expr_e lost_close_par stmt
        {
        	$$ = $1;
        	auto node = root.get($$.index);
        	auto condition_node = root.newNode(std::make_shared<Token>("condition"));
        	root.addLink(node, condition_node, Empty{});
        	root.addLink(condition_node, root.get($3.index), Empty{});
        	root.addLink(condition_node, root.get($5.index), Empty{});
        	root.addLink(condition_node, root.get($7.index), Empty{});
        	root.addLink(node, root.get($9.index), Empty{});
        }
        | foreach lost_open_par expr as var_name lost_close_par stmt
        {
        	$$ = $1;
                auto node = root.get($$.index);
                auto condition_node = root.newNode(std::make_shared<Token>("condition"));
                root.addLink(node, condition_node, Empty{});
                root.addLink(condition_node, root.get($3.index), Empty{});
                root.addLink(condition_node, root.get($5.index), Empty{});
                root.addLink(node, root.get($7.index), Empty{});
        }
        | foreach lost_open_par expr as var_name sv var_name lost_close_par stmt
        {
        	$$ = $1;
                auto node = root.get($$.index);
                auto condition_node = root.newNode(std::make_shared<Token>("condition"));
                root.addLink(node, condition_node, Empty{});
                root.addLink(condition_node, root.get($3.index), Empty{});
                root.addLink(condition_node, root.get($5.index), Empty{});
                root.addLink(condition_node, root.get($7.index), Empty{});
                root.addLink(node, root.get($9.index), Empty{});
        }

        | echo_kw expr semicolon
        {
        	$$.index = createNode("main_stmt", {$1, $2});
        }
        | break semicolon
        {
        	$$.index = createNode("main_stmt", {$1});
        }
        | return expr_e semicolon
        {
        	$$.index = createNode("main_stmt", {$1, $2});
        }
        | open_breaket stmt_list_e close_breaket
        {
        	$$.index = createNode("main_stmt", {$2});
        }
        ;

expr_e   :  /*empty*/
	{
		auto node = root.addNodeInBack(std::make_shared<Token>("expr_e"));
		$$.index = node.getIndex();
	}
         | expr
         {
		auto node = root.addNodeInBack(std::make_shared<Token>("expr_e"));
		root.addLink(node, root.get($1.index), Empty{});
		$$.index = node.getIndex();
         }
         ;


if_stmt : if lost_open_par expr lost_close_par stmt
	{
		$$ = $1;
		auto node = root.get($$.index);
		root.addLink(node, root.get($3.index), Empty{});
		root.addLink(node, root.get($5.index), Empty{});
	}
        | if lost_open_par expr lost_close_par stmt ELSE stmt
        {
		$$ = $1;
		auto node = root.get($$.index);
		root.addLink(node, root.get($3.index), Empty{});
		root.addLink(node, root.get($5.index), Empty{});
		root.addLink(node, root.get($7.index), Empty{});
        }
        | if lost_open_par expr lost_close_par stmt elseif_stmt
	{
		$$ = $1;
		auto node = root.get($$.index);
		root.addLink(node, root.get($3.index), Empty{});
		root.addLink(node, root.get($5.index), Empty{});
		root.addLink(node, root.get($6.index), Empty{});
	}
        | if lost_open_par expr lost_close_par stmt elseif_stmt ELSE stmt
        {
		$$ = $1;
		auto node = root.get($$.index);
		root.addLink(node, root.get($3.index), Empty{});
		root.addLink(node, root.get($5.index), Empty{});
		root.addLink(node, root.get($6.index), Empty{});
		root.addLink(node, root.get($8.index), Empty{});
        }
        ;

array_member    : expr SV expr
		{

		}
                | expr
                {

                }
                ;

array_members_list_e    : /*empty*/
			{

			}
                        | array_members_list
                        {

                        }
                        ;

array_members_list  : array_member
		    {


		    }
                    | array_members_list ',' array_member
                    {

                    }
                    ;

elseif_stmt : ELSEIF lost_open_par expr lost_close_par stmt
	    {

	    }
            | elseif_stmt ELSEIF lost_open_par expr lost_close_par stmt
            {

            }
            ;

switch_stmt : SWITCH lost_open_par expr lost_close_par '{' case_stmt_list '}'
	    {

	    }
            | SWITCH lost_open_par expr lost_close_par '{' case_stmt_list DEFAULT ':' stmt_list_e '}'
	    {

	    }
            ;

case_stmt_list : CASE expr ':' stmt_list_e
	       {

	       }
               | case_stmt_list  CASE expr ':' stmt_list_e
               {

               }
              ;




var_list_e  :  /*empty*/
	   {

	   }
            | var_list
            {

            }
            ;


var_list    : VARNAME
	    {

	    }
	    | VARNAME '=' expr
	    {

	    }
            | var_list ',' VARNAME
	    {

	    }
            | var_list ',' VARNAME '=' expr
	    {

	    }
            ;

function_def : FUNCTION ID lost_open_par var_list_e lost_close_par '{' stmt_list_e '}'
	     {

	     }
             ;

class_def : CLASS ID '{' class_body_e '}'
	  {

	  }
          | CLASS ID EXTENDS ID '{' class_body_e '}'
          {

          }
          ;

class_body_element  : VAR VARNAME ';'
		    {

		    }
                    | PUBLIC VARNAME ';'
		    {

		    }
                    | PRIVATE VARNAME ';'
		    {

		    }
                    | PROTECTED VARNAME ';'
		    {

		    }
                    | function_def
                    {

                    }
                    | PUBLIC function_def
                    {

                    }
                    | PRIVATE function_def
                    {

                    }
                    | PROTECTED function_def
                    {

                    }
                    ;
class_body : class_body_element
	   {

	   }
           |class_body class_body_element
	   {

	   }
           ;

class_body_e : /*empty*/
             {

             }
             |class_body
             {

             }
             ;


var_name : VARNAME
	 {
		auto node = root.addNodeInBack(std::make_shared<VarName>($1.string));
		$$.index = node.getIndex();
	 }
	 ;





semicolon: ';'
	{

	}
	;

html : HTML
     {
     	auto node = root.addNodeInBack(std::make_shared<HtmlToken>($1.string));
        $$.index = node.getIndex();
     }

var_name : VARNAME
	 {
		auto node = root.addNodeInBack(std::make_shared<VarName>($1.string));
		$$.string = $1.string;
		$$.index = node.getIndex();
	 }
	 ;

open_breaket: '{'
	    {

	    }
	    ;

close_breaket: '}'
	    {

	    }
	    ;

while: WHILE
     {
     	auto node = root.addNodeInBack(std::make_shared<Token>(TokenType::WHILE, $1.string));
     	$$.index = node.getIndex();
     }
     ;

do: DO
     {
     	auto node = root.addNodeInBack(std::make_shared<Token>(TokenType::DO, $1.string));
     	$$.index = node.getIndex();
     }
     ;

for: FOR
     {
     	auto node = root.addNodeInBack(std::make_shared<Token>(TokenType::FOR, $1.string));
     	$$.index = node.getIndex();
     }
     ;

foreach: FOREACH
     {
     	auto node = root.addNodeInBack(std::make_shared<Token>(TokenType::FOREACH, $1.string));
     	$$.index = node.getIndex();
     }
     ;
as: AS
   {
   	auto node = root.addNodeInBack(std::make_shared<Token>(TokenType::FOREACH, $1.string));
       $$.index = node.getIndex();
   }
   ;

sv: SV
   {

   }

echo_kw: ECHO_KW
     	{
     		auto node = root.addNodeInBack(std::make_shared<Token>(TokenType::ECHO, $1.string));
     		$$.index = node.getIndex();
     	}
     	;

break: BREAK
     	{
     		auto node = root.addNodeInBack(std::make_shared<Token>(TokenType::BREAK, $1.string));
     		$$.index = node.getIndex();
     	}
     	;

return: RETURN
     	{
     		auto node = root.addNodeInBack(std::make_shared<Token>(TokenType::RETURN, $1.string));
     		$$.index = node.getIndex();
     	}
     	;

if: IF
     	{
     		auto node = root.addNodeInBack(std::make_shared<Token>(TokenType::If, $1.string));
     		$$.index = node.getIndex();
     	}
     	;

char_const: CHARCONST
     	{
     		auto node = root.addNodeInBack(std::make_shared<Token>(TokenType::CHARCONST, $1.string));
     		$$.index = node.getIndex();
     	}
     	;

int_const: INTCONST
     	{
     		auto node = root.addNodeInBack(std::make_shared<Token>(TokenType::INTCONST, $1.string));
     		$$.index = node.getIndex();
     	}
     	;


