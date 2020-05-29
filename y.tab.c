/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bison.y" /* yacc.c:339  */

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

	int create_op_node(std::string value, std::string op, int v1, int v2) {

                auto node = root.addNodeInBack(value);
                auto op_node = root.addNodeInBack(op);
                root.addLink(node, root.getNodeByIndex(v1), Empty{});
                root.addLink(node, op_node, Empty{});
                root.addLink(node, root.getNodeByIndex(v2), Empty{});
         	return node.getIndex();

	}

	int create_unar_op_node(std::string value, std::string op, int v)
	{
            auto node = root.addNodeInBack(value);
            auto unar_node = root.addNodeInBack(op);
            root.addLink(node, unar_node, Empty{});
            root.addLink(node, root.getNodeByIndex(v), Empty{});
            return node.getIndex();
       	}

	int createNode(std::string value, std::vector<int> children_index) {
		auto node = root.addNodeInBack(value);
		for(auto ptr = children_index.begin(); ptr != children_index.end(); ++ptr) {
			root.addLink(node, root.getNodeByIndex(*ptr), Empty{});
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

#line 137 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BREAK = 258,
    CLONE = 259,
    ENDSWITCH = 260,
    HTML = 261,
    WHILE = 262,
    DO = 263,
    FOR = 264,
    FOREACH = 265,
    VARNAME = 266,
    AS = 267,
    SV = 268,
    RETURN = 269,
    INTCONST = 270,
    CHARCONST = 271,
    PAS = 272,
    DIVAS = 273,
    MODAS = 274,
    EQ = 275,
    NE = 276,
    TEQ = 277,
    TNE = 278,
    LEQ = 279,
    GEQ = 280,
    AND = 281,
    OR = 282,
    PP = 283,
    MM = 284,
    UPLUS = 285,
    UMINUS = 286,
    ARRAY = 287,
    ID = 288,
    ARROW = 289,
    NEW = 290,
    PARENT = 291,
    DCOL = 292,
    IF = 293,
    ELSE = 294,
    ELSEIF = 295,
    SWITCH = 296,
    DEFAULT = 297,
    CASE = 298,
    FUNCTION = 299,
    CLASS = 300,
    EXTENDS = 301,
    VAR = 302,
    PUBLIC = 303,
    PRIVATE = 304,
    PROTECTED = 305,
    ECHO_KW = 306,
    MAS = 307,
    MULAS = 308,
    UNDEFINED = 309
  };
#endif
/* Tokens.  */
#define BREAK 258
#define CLONE 259
#define ENDSWITCH 260
#define HTML 261
#define WHILE 262
#define DO 263
#define FOR 264
#define FOREACH 265
#define VARNAME 266
#define AS 267
#define SV 268
#define RETURN 269
#define INTCONST 270
#define CHARCONST 271
#define PAS 272
#define DIVAS 273
#define MODAS 274
#define EQ 275
#define NE 276
#define TEQ 277
#define TNE 278
#define LEQ 279
#define GEQ 280
#define AND 281
#define OR 282
#define PP 283
#define MM 284
#define UPLUS 285
#define UMINUS 286
#define ARRAY 287
#define ID 288
#define ARROW 289
#define NEW 290
#define PARENT 291
#define DCOL 292
#define IF 293
#define ELSE 294
#define ELSEIF 295
#define SWITCH 296
#define DEFAULT 297
#define CASE 298
#define FUNCTION 299
#define CLASS 300
#define EXTENDS 301
#define VAR 302
#define PUBLIC 303
#define PRIVATE 304
#define PROTECTED 305
#define ECHO_KW 306
#define MAS 307
#define MULAS 308
#define UNDEFINED 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 293 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  261

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,     2,     2,    68,     2,     2,
      56,    57,    60,    58,    72,    59,    67,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    73,    62,
      69,    55,    70,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     2,    64,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   100,   102,   106,   110,   118,   125,   129,
     133,   139,   143,   150,   156,   164,   171,   176,   183,   188,
     196,   200,   204,   215,   236,   253,   268,   288,   298,   307,
     317,   329,   336,   343,   350,   361,   365,   369,   373,   377,
     381,   385,   389,   393,   397,   401,   402,   406,   410,   414,
     418,   422,   426,   430,   434,   438,   442,   446,   450,   454,
     458,   466,   474,   478,   482,   490,   500,   514,   524,   536,
     546,   559,   568,   580,   589,   601,   618,   624,   632,   638,
     650,   656,   665,   671,   679,   686,   696,   706,   722,   728,
     736,   743,   754,   763,   770,   781,   795,   807,   824,   835,
     849,   864,   886,   897,   911,   930,   944,   964,   975,   986,
     997,  1008,  1014,  1022,  1030,  1039,  1045,  1055,  1061
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BREAK", "CLONE", "ENDSWITCH", "HTML",
  "WHILE", "DO", "FOR", "FOREACH", "VARNAME", "AS", "SV", "RETURN",
  "INTCONST", "CHARCONST", "PAS", "DIVAS", "MODAS", "EQ", "NE", "TEQ",
  "TNE", "LEQ", "GEQ", "AND", "OR", "PP", "MM", "UPLUS", "UMINUS", "ARRAY",
  "ID", "ARROW", "NEW", "PARENT", "DCOL", "IF", "ELSE", "ELSEIF", "SWITCH",
  "DEFAULT", "CASE", "FUNCTION", "CLASS", "EXTENDS", "VAR", "PUBLIC",
  "PRIVATE", "PROTECTED", "ECHO_KW", "MAS", "MULAS", "UNDEFINED", "'='",
  "'('", "')'", "'+'", "'-'", "'*'", "'/'", "';'", "'{'", "'}'", "'['",
  "']'", "'.'", "'%'", "'<'", "'>'", "'!'", "','", "':'", "$accept",
  "program", "main_stmt_tag_list", "main_stmt", "stmt_list", "stmt_list_e",
  "lost_close_par", "lost_open_par", "stmt", "expr", "expr_e", "expr_list",
  "expr_list_e", "var_list_e", "var_list", "array_members_list_e",
  "array_members_list", "array_member", "if_stmt", "elseif_stmt",
  "switch_stmt", "case_stmt_list", "function_def", "class_def",
  "class_body_element", "class_body", "class_body_e", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    61,    40,    41,    43,    45,
      42,    47,    59,   123,   125,    91,    93,    46,    37,    60,
      62,    33,    44,    58
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     594,   -95,   -58,   -95,     8,   -53,     8,     8,   -95,   865,
     -95,   -95,   917,   917,     8,     8,    11,   -12,     8,     8,
      -2,    10,   917,   -95,   917,   917,   789,   917,    36,   528,
     -95,   917,   -95,  1218,   -24,   -95,   -95,   -95,   -95,   -95,
     917,   789,   865,   917,   -14,  1218,  1218,   648,   713,   268,
     330,    17,   917,   917,     8,   -18,  1144,  1292,  1292,   -58,
     659,   -10,   -95,  1218,   -95,   -95,   -95,   937,   917,   917,
     917,   917,   917,   917,   917,   917,   917,   917,   917,   -95,
     -95,    16,   917,   917,   917,   917,   917,   917,   917,   917,
     917,   917,   917,   917,   -95,   937,    -9,    -5,   991,   -95,
    1011,     5,   -16,   -95,  1218,   -13,     5,   713,   713,     8,
     937,   937,    47,    32,    51,   -95,   -95,   -95,   -95,   -95,
     -95,  1218,  1218,  1218,  1218,  1218,  1218,  1218,  1218,  1218,
    1218,  1218,   392,   454,  1218,  1218,  1218,  1238,  1238,  1292,
    1292,  1164,  1218,  1218,  1218,  1218,   854,    59,   865,    69,
     917,   -95,   917,   917,   -95,     5,     5,   713,   854,    30,
      48,     5,    38,    39,   100,    -4,    -3,     9,   -95,   -95,
      51,    49,   713,   713,   -95,   -95,     8,    50,     4,  1218,
     -95,  1218,   -95,   -95,     5,   -21,    71,   917,    52,   105,
      51,    55,    56,   -95,    58,   -95,    60,   -95,   -95,   -95,
       5,     5,   917,   778,   110,   854,   -95,   854,     8,    -6,
     917,   -27,  1218,   789,    68,    62,   -95,   -95,   -95,   -95,
     -95,   -95,   937,     5,     5,   -95,   -95,   917,   854,     8,
    1065,    54,   917,   -95,    64,   917,   -95,    67,   854,   854,
     937,   -95,   917,   724,   789,  1087,   -95,  1218,   -95,   -95,
     -95,   854,   937,   -95,    72,   724,   -95,   854,   -95,   -95,
     -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,     3,     6,     0,     0,     0,     0,    31,     0,
      32,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,     0,     0,     0,     0,     0,
       4,     0,    10,    77,     0,    20,    21,     9,     8,    28,
       0,     0,     0,     0,     0,    58,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    63,     0,
       0,     0,    11,    57,     1,     7,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    29,
      93,     0,    89,    90,    78,    81,     0,     0,     0,     0,
       0,     0,    82,     0,   117,    27,    12,    30,    16,    15,
      64,    37,    43,    45,    47,    48,    49,    50,    52,    54,
      55,    56,     0,     0,    39,    41,    46,    36,    38,    40,
      42,     0,    35,    44,    51,    53,     0,     0,     0,     0,
       0,    65,     0,     0,    66,     0,     0,     0,     0,     0,
      84,     0,    83,     0,     0,     0,     0,     0,   111,   115,
     118,     0,     0,     0,    34,    22,     0,     0,     0,    92,
      91,    79,    74,    72,     0,    94,     0,     0,     0,     0,
     117,     0,     0,   112,     0,   113,     0,   114,   116,   105,
       0,     0,     0,     0,     0,     0,    75,     0,     0,    96,
       0,     0,    85,     0,    86,     0,   107,   108,   109,   110,
      70,    68,     0,     0,     0,    25,    95,     0,     0,     0,
       0,     0,     0,   100,     0,     0,   106,     0,     0,     0,
       0,    97,     0,     0,     0,     0,   104,    87,    23,    24,
      26,     0,     0,   102,     0,     0,    98,     0,   101,   103,
      99
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -95,   -95,    95,   -95,   -40,    24,    90,     0,    -1,
      -7,   -95,   -94,   -95,   -95,   -95,   -95,   -20,   -95,   -95,
     -95,   -95,     3,   -95,   -39,   -95,   -57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    30,    60,    61,   120,    31,    62,    33,
      34,   105,   106,   161,   162,   101,   102,   103,    35,   209,
      36,   211,   168,    38,   169,   170,   171
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    96,    44,    37,    39,   118,   118,   192,   194,     1,
      41,    45,    46,   155,   156,   231,   232,   204,   207,   208,
     196,    56,    49,    57,    58,    51,    63,   132,   113,    32,
      67,    54,    37,   228,   229,    97,    64,   233,    94,    95,
      20,    20,    98,    55,    50,   114,   100,   104,    99,   133,
     109,   110,   111,    20,   117,   147,   152,   148,   160,   153,
     116,   119,   119,   184,    23,   163,   176,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   200,   201,
     178,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   186,    40,    20,    42,    43,   164,   165,
     166,   167,   190,   187,    47,    48,   104,   104,    52,    53,
     189,   191,   203,   199,   210,   213,   214,   216,   217,   146,
     218,   224,   219,   235,    66,   151,   236,   244,   246,   248,
     154,   198,   180,   215,   158,   159,   258,     0,     0,   107,
     108,   177,     0,     0,   112,     0,   175,     0,     0,   179,
       0,   100,   181,     0,     0,     0,   104,     0,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,   195,
     197,   104,   104,   234,     0,     0,     0,     0,     0,   182,
     183,     0,     0,     0,     0,   188,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   223,     0,     0,   157,
       0,   222,   205,   253,   254,   225,     0,   226,   206,   230,
       0,     0,     0,     0,     0,   259,     0,     0,     0,     0,
       0,     0,   172,   173,   220,   221,   240,     0,   241,     0,
       0,   245,     0,     0,   247,     0,     0,     0,   249,   250,
       0,   252,     0,     0,     0,     0,   237,   238,   239,     0,
       0,   256,     0,     0,     0,     0,     0,   260,     0,     0,
       0,     0,     0,     0,   251,     0,   202,     0,     0,     1,
       0,     0,     0,     0,     0,     0,   257,     0,     0,     0,
     -73,   -73,     0,     0,     0,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   227,     0,
       0,     0,   -73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
     -73,   -73,     0,   -73,    23,   -73,   -73,   -73,   -73,   -73,
     -73,     1,     0,   -73,   -73,   -73,   -73,   -73,   -73,     0,
     -73,   -73,   -71,   -71,     0,     0,     0,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
       0,     0,     0,     0,   -71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -71,   -71,     0,   -71,    23,   -71,   -71,   -71,
     -71,   -71,   -71,     1,     0,   -71,   -71,   -71,   -71,   -71,
     -71,     0,   -71,   -71,   -69,   -69,     0,     0,     0,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,     0,     0,     0,     0,   -69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -69,   -69,     0,   -69,    23,   -69,
     -69,   -69,   -69,   -69,   -69,     1,     0,   -69,   -69,   -69,
     -69,   -69,   -69,     0,   -69,   -69,   -67,   -67,     0,     0,
       0,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,     0,     0,     0,     0,   -67,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -67,   -67,     0,   -67,
      23,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,   -67,
     -67,   -67,   -67,   -67,   -67,     0,   -67,   -67,    -2,     1,
       0,    59,     0,     0,    65,     4,     5,     6,     7,     8,
       0,     0,     9,    10,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,     0,     0,
      14,    15,     0,    16,    17,     0,    18,     0,     0,    19,
       0,     0,    20,    21,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,    23,     0,    24,    25,     0,     0,
     -76,    26,     0,     0,     0,     1,     0,     2,     0,    27,
       3,     4,     5,     6,     7,     8,     0,     0,     9,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,     0,     0,    14,    15,     0,    16,
      17,     0,    18,     0,     0,    19,     0,     0,    20,    21,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     1,
      23,     0,    24,    25,     0,     0,   -76,    26,     0,     8,
       1,     0,    59,    10,    11,    27,     4,     5,     6,     7,
       8,     0,     0,     9,    10,    11,    12,    13,     0,     0,
      14,    15,     0,    16,    17,     0,     0,    12,    13,     0,
       0,    14,    15,     0,    16,    17,     0,    18,     0,     0,
      19,   -14,   -14,     0,    23,   -88,    24,    25,     0,     0,
      22,     0,     0,     0,     1,    23,     0,    24,    25,    27,
       0,   -76,    26,   -14,     8,     1,     0,    59,    10,    11,
      27,     4,     5,     6,     7,     8,     0,     0,     9,    10,
      11,    12,    13,     0,     0,    14,    15,     0,    16,    17,
       0,     0,    12,    13,     0,     0,    14,    15,     0,    16,
      17,     0,    18,     0,     0,    19,   -13,   -13,     0,    23,
     -80,    24,    25,     0,     0,    22,     0,     0,     0,     1,
      23,     0,    24,    25,    27,     0,   -76,    26,   -13,     8,
       1,     0,    59,    10,    11,    27,     4,     5,     6,     7,
       8,     0,     0,     9,    10,    11,    12,    13,     0,     0,
      14,    15,     0,    16,    17,     0,     0,    12,    13,     0,
       0,    14,    15,     0,    16,    17,     0,    18,     0,     0,
      19,     0,     0,     0,    23,   -76,    24,    25,     0,     0,
      22,     0,     0,     0,     0,    23,     0,    24,    25,    27,
       0,   -76,    26,   -13,     0,     1,     0,    59,     0,     0,
      27,     4,     5,     6,     7,     8,     1,     0,     9,    10,
      11,     0,     0,     0,     0,     0,     8,     0,     0,     0,
      10,    11,    12,    13,     0,     0,    14,    15,     0,    16,
      17,     0,    18,    12,    13,    19,     0,    14,    15,     0,
      16,    17,     0,     0,     0,    22,     0,     0,     0,     0,
      23,     0,    24,    25,     0,     0,   -76,    26,     1,     0,
       0,    23,     0,    24,    25,    27,     0,   -76,     8,     0,
       0,     0,    10,    11,     0,     0,    27,     0,   118,     0,
       0,     0,     0,     0,     0,    12,    13,     0,     0,    14,
      15,     0,    16,    17,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,     0,     0,     0,
       0,    81,     0,    23,     0,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    82,
      83,     0,    84,     0,   119,    85,    86,    87,    88,     0,
       0,     0,    89,   149,    90,    91,    92,    93,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,     0,     0,     0,   150,    81,     0,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,     0,     0,    82,    83,    81,    84,     0,     0,    85,
      86,    87,    88,     0,     0,     0,    89,     0,    90,    91,
      92,    93,     0,    82,    83,     0,    84,     0,     0,    85,
      86,    87,    88,     0,     0,     0,    89,     0,    90,    91,
      92,    93,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,     0,     0,     0,     0,    81,
       0,     0,     0,     0,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    82,    83,     0,
      84,    81,     0,    85,    86,    87,    88,     0,     0,     0,
      89,     0,    90,    91,    92,    93,     0,     0,   243,    82,
      83,     0,    84,     0,     0,    85,    86,    87,    88,     0,
       0,     0,    89,     0,    90,    91,    92,    93,     0,     0,
     255,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,     0,     0,     0,    81,     0,
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,     0,    82,    83,    81,    84,
       0,     0,    85,    86,    87,    88,   115,     0,     0,    89,
       0,    90,    91,    92,    93,     0,    82,    83,     0,    84,
       0,     0,    85,    86,    87,    88,     0,     0,     0,    89,
     174,    90,    91,    92,    93,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,     0,
       0,     0,    81,     0,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,     0,
      82,    83,    81,    84,     0,     0,    85,    86,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,     0,
      82,    83,     0,     0,     0,     0,     0,     0,    87,    88,
       0,     0,     0,    89,     0,    90,    91,    92,    93,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,     0,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,    90,
      91,    92,    93
};

static const yytype_int16 yycheck[] =
{
       0,    41,     9,     0,    62,     1,     1,    11,    11,     1,
      63,    12,    13,   107,   108,    42,    43,    13,    39,    40,
      11,    22,    11,    24,    25,    37,    27,    11,    46,    29,
      31,    33,    29,    39,    40,    42,     0,    64,    62,    40,
      44,    44,    43,    33,    33,    63,    47,    48,    62,    33,
      33,    52,    53,    44,    64,    64,    72,    62,    11,    72,
      60,    57,    57,   157,    56,    33,     7,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,   172,   173,
      11,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    63,     4,    44,     6,     7,    47,    48,
      49,    50,    63,    55,    14,    15,   107,   108,    18,    19,
      72,    11,    62,    64,    43,    63,    11,    62,    62,    95,
      62,    11,    62,    55,    29,   101,    64,    73,    64,    62,
     106,   170,   152,   190,   110,   111,    64,    -1,    -1,    49,
      50,   148,    -1,    -1,    54,    -1,   146,    -1,    -1,   150,
      -1,   152,   153,    -1,    -1,    -1,   157,    -1,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,   172,   173,   213,    -1,    -1,    -1,    -1,    -1,   155,
     156,    -1,    -1,    -1,    -1,   161,   187,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,   109,
      -1,   202,   178,   243,   244,   205,    -1,   207,   184,   210,
      -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,   200,   201,   227,    -1,   228,    -1,
      -1,   232,    -1,    -1,   235,    -1,    -1,    -1,   238,   239,
      -1,   242,    -1,    -1,    -1,    -1,   222,   223,   224,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,    -1,    -1,   240,    -1,   176,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,   208,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,     1,    -1,    65,    66,    67,    68,    69,    70,    -1,
      72,    73,    12,    13,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,     1,    -1,    65,    66,    67,    68,    69,
      70,    -1,    72,    73,    12,    13,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,     1,    -1,    65,    66,    67,
      68,    69,    70,    -1,    72,    73,    12,    13,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    70,    -1,    72,    73,     0,     1,
      -1,     3,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    33,    -1,    35,    36,    -1,    38,    -1,    -1,    41,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    56,    -1,    58,    59,    -1,    -1,
      62,    63,    -1,    -1,    -1,     1,    -1,     3,    -1,    71,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    33,    -1,    35,
      36,    -1,    38,    -1,    -1,    41,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,     1,
      56,    -1,    58,    59,    -1,    -1,    62,    63,    -1,    11,
       1,    -1,     3,    15,    16,    71,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    16,    28,    29,    -1,    -1,
      32,    33,    -1,    35,    36,    -1,    -1,    28,    29,    -1,
      -1,    32,    33,    -1,    35,    36,    -1,    38,    -1,    -1,
      41,    42,    43,    -1,    56,    57,    58,    59,    -1,    -1,
      51,    -1,    -1,    -1,     1,    56,    -1,    58,    59,    71,
      -1,    62,    63,    64,    11,     1,    -1,     3,    15,    16,
      71,     7,     8,     9,    10,    11,    -1,    -1,    14,    15,
      16,    28,    29,    -1,    -1,    32,    33,    -1,    35,    36,
      -1,    -1,    28,    29,    -1,    -1,    32,    33,    -1,    35,
      36,    -1,    38,    -1,    -1,    41,    42,    43,    -1,    56,
      57,    58,    59,    -1,    -1,    51,    -1,    -1,    -1,     1,
      56,    -1,    58,    59,    71,    -1,    62,    63,    64,    11,
       1,    -1,     3,    15,    16,    71,     7,     8,     9,    10,
      11,    -1,    -1,    14,    15,    16,    28,    29,    -1,    -1,
      32,    33,    -1,    35,    36,    -1,    -1,    28,    29,    -1,
      -1,    32,    33,    -1,    35,    36,    -1,    38,    -1,    -1,
      41,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,    71,
      -1,    62,    63,    64,    -1,     1,    -1,     3,    -1,    -1,
      71,     7,     8,     9,    10,    11,     1,    -1,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      15,    16,    28,    29,    -1,    -1,    32,    33,    -1,    35,
      36,    -1,    38,    28,    29,    41,    -1,    32,    33,    -1,
      35,    36,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      56,    -1,    58,    59,    -1,    -1,    62,    63,     1,    -1,
      -1,    56,    -1,    58,    59,    71,    -1,    62,    11,    -1,
      -1,    -1,    15,    16,    -1,    -1,    71,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,
      33,    -1,    35,    36,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    34,    -1,    56,    -1,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    52,
      53,    -1,    55,    -1,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    12,    67,    68,    69,    70,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    13,    34,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    52,    53,    34,    55,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    65,    -1,    67,    68,
      69,    70,    -1,    52,    53,    -1,    55,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    65,    -1,    67,    68,
      69,    70,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    52,    53,    -1,
      55,    34,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      65,    -1,    67,    68,    69,    70,    -1,    -1,    73,    52,
      53,    -1,    55,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    -1,    67,    68,    69,    70,    -1,    -1,
      73,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    52,    53,    34,    55,
      -1,    -1,    58,    59,    60,    61,    62,    -1,    -1,    65,
      -1,    67,    68,    69,    70,    -1,    52,    53,    -1,    55,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      52,    53,    34,    55,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    65,    -1,    67,    68,    69,    70,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    65,    -1,    67,    68,    69,    70,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    67,
      68,    69,    70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     6,     7,     8,     9,    10,    11,    14,
      15,    16,    28,    29,    32,    33,    35,    36,    38,    41,
      44,    45,    51,    56,    58,    59,    63,    71,    75,    76,
      77,    81,    82,    83,    84,    92,    94,    96,    97,    62,
      81,    63,    81,    81,    84,    83,    83,    81,    81,    11,
      33,    37,    81,    81,    33,    33,    83,    83,    83,     3,
      78,    79,    82,    83,     0,     6,    77,    83,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    34,    52,    53,    55,    58,    59,    60,    61,    65,
      67,    68,    69,    70,    62,    83,    79,    84,    83,    62,
      83,    89,    90,    91,    83,    85,    86,    81,    81,    33,
      83,    83,    81,    46,    63,    62,    82,    64,     1,    57,
      80,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    11,    33,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    80,    64,    62,    12,
      13,    80,    72,    72,    80,    86,    86,    81,    80,    80,
      11,    87,    88,    33,    47,    48,    49,    50,    96,    98,
      99,   100,    81,    81,    66,    82,     7,    84,    11,    83,
      91,    83,    80,    80,    86,    82,    63,    55,    80,    72,
      63,    11,    11,    96,    11,    96,    11,    96,    98,    64,
      86,    86,    81,    62,    13,    80,    80,    39,    40,    93,
      43,    95,    83,    63,    11,   100,    62,    62,    62,    62,
      80,    80,    83,    84,    11,    82,    82,    81,    39,    40,
      83,    42,    43,    64,    79,    55,    64,    80,    80,    80,
      83,    82,    81,    73,    73,    83,    64,    83,    62,    82,
      82,    80,    83,    79,    79,    73,    82,    80,    64,    79,
      82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    76,    76,    77,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    92,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     2,     1,     1,
       1,     1,     2,     0,     1,     1,     1,     1,     1,     2,
       1,     1,     5,     9,     9,     7,     9,     3,     2,     3,
       3,     1,     1,     1,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     2,     3,     4,     4,     3,     6,     3,
       6,     2,     5,     2,     5,     6,     0,     1,     1,     3,
       0,     1,     0,     1,     1,     3,     3,     5,     0,     1,
       1,     3,     3,     1,     5,     7,     6,     8,     5,     6,
       7,    10,     4,     5,     8,     5,     7,     3,     3,     3,
       3,     1,     2,     2,     2,     1,     2,     0,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 97 "bison.y" /* yacc.c:1646  */
    {
		(yyval) = createNode("program", {(yyvsp[0])});
	}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 103 "bison.y" /* yacc.c:1646  */
    {
				(yyval) = createNode("main_stmt_tag_list", {(yyvsp[0])});
			}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 107 "bison.y" /* yacc.c:1646  */
    {
                    		(yyval) = createNode("main_stmt_tag_list", {(yyvsp[-1]), (yyvsp[0])});
                    	}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 111 "bison.y" /* yacc.c:1646  */
    {
			auto node = root.addNodeInBack("main_stmt_tag_list");
                    	auto html_node = root.addNodeInBack(std::string("HTML"));
                    	root.addLink(node, html_node, Empty{});
                    	(yyval) = node.getIndex();

                    }
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 119 "bison.y" /* yacc.c:1646  */
    {
                    	(yyval) = createNode("main_stmt_tag_list", {(yyvsp[-1])});
                    	auto html_node = root.addNodeInBack(std::string("HTML"));
                    	root.addLink(root.getNodeByIndex((yyval)), html_node, Empty{});
                    }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "bison.y" /* yacc.c:1646  */
    {
	    	(yyval) = createNode("main_stmt", {(yyvsp[0])});
	    }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 130 "bison.y" /* yacc.c:1646  */
    {
            	(yyval) = createNode("main_stmt", {(yyvsp[0])});
            }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 134 "bison.y" /* yacc.c:1646  */
    {
            	(yyval) = createNode("main_stmt", {(yyvsp[0])});
            }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 140 "bison.y" /* yacc.c:1646  */
    {
	    	(yyval) = createNode("stmt_list", {(yyvsp[0])});
	    }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 144 "bison.y" /* yacc.c:1646  */
    {
            	(yyval) = createNode("stmt_list", {(yyvsp[-1]), (yyvsp[0])});
            }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 150 "bison.y" /* yacc.c:1646  */
    {
	    	auto node = root.addNodeInBack("stmt_list_e");
	    	auto empty = root.addNodeInBack("empty");
	    	root.addLink(node, empty, Empty{});
	    	(yyval) = node.getIndex();
	    }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 157 "bison.y" /* yacc.c:1646  */
    {
            	auto node = root.addNodeInBack("stmt_list_e");
            	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
            	(yyval) = node.getIndex();
            }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 165 "bison.y" /* yacc.c:1646  */
    {
			auto node = root.addNodeInBack("lost_close_par");
			auto braket_node = root.addNodeInBack(")");
			root.addLink(node, braket_node, Empty{});
			(yyval) = node.getIndex();
		}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 172 "bison.y" /* yacc.c:1646  */
    {
                	(yyval) = createNode("lost_close_par", {(yyvsp[0])});
                }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 177 "bison.y" /* yacc.c:1646  */
    {
			auto node = root.addNodeInBack("lost_open_par");
			auto braket_node = root.addNodeInBack("(");
			root.addLink(node, braket_node, Empty{});
			(yyval) = node.getIndex();
		}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 184 "bison.y" /* yacc.c:1646  */
    {
                	(yyval) = createNode("lost_close_par", {(yyvsp[0])});
                }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 189 "bison.y" /* yacc.c:1646  */
    {
		auto node = root.addNodeInBack("stmt");
		auto semicolon_node = root.addNodeInBack(";");
		root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
		root.addLink(node, semicolon_node, Empty{});
		(yyval) = node.getIndex();
	}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 197 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = createNode("stmt", {(yyvsp[0])});
        }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 201 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = createNode("stmt", {(yyvsp[0])});
        }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 205 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("stmt");
        	auto while_node = root.addNodeInBack("while");
        	root.addLink(node, while_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-3])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
        	(yyval) = node.getIndex();
        }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 216 "bison.y" /* yacc.c:1646  */
    {
		auto node = root.addNodeInBack("stmt");
        	auto do_node = root.addNodeInBack("do");
        	auto openbreacket_node = root.addNodeInBack("{");
        	auto closebreacket_node = root.addNodeInBack("{");
        	auto while_node = root.addNodeInBack("while");
        	auto semicolon_node = root.addNodeInBack(";");
        	root.addLink(node, do_node, Empty{});
        	root.addLink(node, openbreacket_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-6])), Empty{});
        	root.addLink(node, closebreacket_node, Empty{});
        	root.addLink(node, while_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-3])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, semicolon_node, Empty{});

        	(yyval) = node.getIndex();

        }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 237 "bison.y" /* yacc.c:1646  */
    {
		auto node = root.addNodeInBack("stmt");
		auto for_node = root.addNodeInBack("FOR");
		auto semicolon_node1 = root.addNodeInBack(";");
		auto semicolon_node2 = root.addNodeInBack(";");
		root.addLink(node, for_node, Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[-7])), Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[-6])), Empty{});
		root.addLink(node, semicolon_node1, Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[-4])), Empty{});
		root.addLink(node, semicolon_node2, Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
		(yyval) = node.getIndex();
        }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 254 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("stmt");
        	auto foreach_node = root.addNodeInBack("FOREACH");
        	auto as_node = root.addNodeInBack("AS");
        	auto varname_node = root.addNodeInBack("VARNAME");
        	root.addLink(node, foreach_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-5])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-4])), Empty{});
        	root.addLink(node, as_node, Empty{});
        	root.addLink(node, varname_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
        	(yyval) = node.getIndex();
        }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 269 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("stmt");
                auto foreach_node = root.addNodeInBack("FOREACH");
                auto as_node = root.addNodeInBack("AS");
                auto varname_node1 = root.addNodeInBack("VARNAME");
                auto sv_node = root.addNodeInBack("SV");
                auto varname_node2 = root.addNodeInBack("VARNAME");
                root.addLink(node, foreach_node, Empty{});
                root.addLink(node, root.getNodeByIndex((yyvsp[-7])), Empty{});
                root.addLink(node, root.getNodeByIndex((yyvsp[-6])), Empty{});
                root.addLink(node, as_node, Empty{});
                root.addLink(node, varname_node1, Empty{});
                root.addLink(node, sv_node, Empty{});
                root.addLink(node, varname_node2, Empty{});
                root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
                root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
                (yyval) = node.getIndex();
        }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 289 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("stmt");
        	auto echo_node = root.addNodeInBack("ECHO_KW");
        	auto semicolon_node = root.addNodeInBack(";");
        	root.addLink(node, echo_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, semicolon_node, Empty{});
        	(yyval) = node.getIndex();
        }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 299 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("stmt");
        	auto break_node = root.addNodeInBack("BREAK");
        	auto semicolon_node = root.addNodeInBack(";");
        	root.addLink(node, break_node, Empty{});
        	root.addLink(node, semicolon_node, Empty{});
        	(yyval) = node.getIndex();
        }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 308 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("stmt");
        	auto return_node = root.addNodeInBack("RETURN");
        	auto semicolon_node = root.addNodeInBack(";");
        	root.addLink(node, return_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, semicolon_node, Empty{});
        	(yyval) = node.getIndex();
        }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 318 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("stmt");
        	auto openbreaket_node = root.addNodeInBack("{");
        	auto closebreaket_node = root.addNodeInBack("}");
        	root.addLink(node, openbreaket_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, closebreaket_node, Empty{});
        	(yyval) = node.getIndex();
        }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 330 "bison.y" /* yacc.c:1646  */
    {
		auto node = root.addNodeInBack("expr");
		auto varname_node = root.addNodeInBack("VARNAME");
		root.addLink(node, varname_node, Empty{});
		(yyval) = node.getIndex();
	}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 337 "bison.y" /* yacc.c:1646  */
    {
                auto node = root.addNodeInBack("expr");
        	auto intconst_node = root.addNodeInBack("INTCONST");
        	root.addLink(node, intconst_node, Empty{});
        	(yyval) = node.getIndex();
        }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 344 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto charconst_node = root.addNodeInBack("CHARCONST");
        	root.addLink(node, charconst_node, Empty{});
        	(yyval) = node.getIndex();
        }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 351 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto openbreaket_node = root.addNodeInBack("[");
        	auto closebreaket_node = root.addNodeInBack("]");
        	root.addLink(node, root.getNodeByIndex((yyvsp[-3])), Empty{});
        	root.addLink(node, openbreaket_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, closebreaket_node, Empty{});
        	(yyval) = node.getIndex();
        }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 362 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", ".", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 366 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "+", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 370 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "PAS", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 374 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "-", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 378 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "MAS", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 382 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "*", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 386 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "MULAS", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 390 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "/", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 394 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "DIVAS", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 398 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "%", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 403 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "=", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 407 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "==", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 411 "bison.y" /* yacc.c:1646  */
    {
         	(yyval) = create_op_node("expr", "!=", (yyvsp[-2]), (yyvsp[0]));
         }
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 415 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "TEQ", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 419 "bison.y" /* yacc.c:1646  */
    {
         	(yyval) = create_op_node("expr", "TNE", (yyvsp[-2]), (yyvsp[0]));
         }
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 423 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "<", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 427 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "<=", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 431 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", ">", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 435 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", ">=", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 439 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "&&", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 443 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_op_node("expr", "||", (yyvsp[-2]), (yyvsp[0]));
        }
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 447 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_unar_op_node("expr", "!", (yyvsp[0]));
        }
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 451 "bison.y" /* yacc.c:1646  */
    {
		(yyval) = create_unar_op_node("expr", "PP", (yyvsp[0]));
	}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 455 "bison.y" /* yacc.c:1646  */
    {
		(yyval) = create_unar_op_node("expr", "MM", (yyvsp[0]));
	}
#line 2335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 459 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto unar_node = root.addNodeInBack("PP");
        	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
        	root.addLink(node, unar_node, Empty{});
        	(yyval) = node.getIndex();
	}
#line 2347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 467 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto unar_node = root.addNodeInBack("MM");
        	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
        	root.addLink(node, unar_node, Empty{});
        	(yyval) = node.getIndex();
	}
#line 2359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 475 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_unar_op_node("expr", "UNAR +", (yyvsp[0]));
        }
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 479 "bison.y" /* yacc.c:1646  */
    {
        	(yyval) = create_unar_op_node("expr", "UNAR -", (yyvsp[0]));
        }
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 483 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
        	(yyval) = node.getIndex();
        }
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 491 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto array_node = root.addNodeInBack("ARRAY");
        	root.addLink(node, array_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
        	(yyval) = node.getIndex();
        }
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 501 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto id_node = root.addNodeInBack("ID");
        	root.addLink(node, id_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, id_node, Empty{});
                root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
               	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
               	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
               	(yyval) = node.getIndex();

        }
#line 2419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 515 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto arrow_node = root.addNodeInBack("ARROW");
        	auto id_node = root.addNodeInBack("ID");
        	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
        	root.addLink(node, arrow_node, Empty{});
        	root.addLink(node, id_node, Empty{});
        	(yyval) = node.getIndex();
        }
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 525 "bison.y" /* yacc.c:1646  */
    {
               	auto node = root.addNodeInBack("expr");
               	auto arrow_node = root.addNodeInBack("ARROW");
                auto id_node = root.addNodeInBack("ID");
                root.addLink(node, root.getNodeByIndex((yyvsp[-5])), Empty{});
                root.addLink(node, arrow_node, Empty{});
                root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
                root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
                root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
                (yyval) = node.getIndex();
        }
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 537 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto arrow_node = root.addNodeInBack("ARROW");
        	auto varname_node = root.addNodeInBack("VARNAME");
        	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
        	root.addLink(node, arrow_node, Empty{});
        	root.addLink(node, varname_node, Empty{});
        	(yyval) = node.getIndex();
        }
#line 2463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 547 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
                auto arrow_node = root.addNodeInBack("ARROW");
                auto varname_node = root.addNodeInBack("VARNAME");
                root.addLink(node, root.getNodeByIndex((yyvsp[-5])), Empty{});
                root.addLink(node, arrow_node, Empty{});
                root.addLink(node, varname_node, Empty{});
                root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
                root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
                root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
                (yyval) = node.getIndex();
        }
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 560 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto new_node = root.addNodeInBack("NEW");
        	auto id_node = root.addNodeInBack("ID");
        	root.addLink(node, new_node, Empty{});
        	root.addLink(node, id_node, Empty{});
        	(yyval) = node.getIndex();
        }
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 569 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto new_node = root.addNodeInBack("NEW");
        	auto id_node = root.addNodeInBack("ID");
        	root.addLink(node, new_node, Empty{});
        	root.addLink(node, id_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
        	(yyval) = node.getIndex();
        }
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 581 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto new_node = root.addNodeInBack("NEW");
        	auto varname_node = root.addNodeInBack("VARNAME");
        	root.addLink(node, new_node, Empty{});
        	root.addLink(node, varname_node, Empty{});
        	(yyval) = node.getIndex();
        }
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 590 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto new_node = root.addNodeInBack("NEW");
        	auto varname_node = root.addNodeInBack("VARNAME");
        	root.addLink(node, new_node, Empty{});
        	root.addLink(node, varname_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
        	(yyval) = node.getIndex();
        }
#line 2538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 602 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("expr");
        	auto parent_node = root.addNodeInBack("PARENT");
        	auto dcol_node = root.addNodeInBack("DCOL");
        	auto id_node = root.addNodeInBack("ID");
        	root.addLink(node, parent_node, Empty{});
        	root.addLink(node, dcol_node, Empty{});
        	root.addLink(node, id_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
        	(yyval) = node.getIndex();
        }
#line 2556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 618 "bison.y" /* yacc.c:1646  */
    {
		auto node = root.addNodeInBack("expr_e");
		auto empty = root.addNodeInBack("empty");
		root.addLink(node, empty, Empty{});
		(yyval) = node.getIndex();
	}
#line 2567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 625 "bison.y" /* yacc.c:1646  */
    {
         	auto node = root.addNodeInBack("expr_e");
         	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
         	(yyval) = node.getIndex();
         }
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 633 "bison.y" /* yacc.c:1646  */
    {
		auto node = root.addNodeInBack("expr_list");
		root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
		(yyval) = node.getIndex();
           }
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 639 "bison.y" /* yacc.c:1646  */
    {
            	auto node = root.addNodeInBack("expr_list");
            	auto dot_node = root.addNodeInBack(",");
            	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
            	root.addLink(node, dot_node, Empty{});
            	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
            	(yyval) = node.getIndex();
            }
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 650 "bison.y" /* yacc.c:1646  */
    {
	   	auto node = root.addNodeInBack("expr_list");
	   	auto empty = root.addNodeInBack("empty");
	   	root.addLink(node, empty, Empty{});
	   	(yyval) = node.getIndex();
	   }
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 657 "bison.y" /* yacc.c:1646  */
    {
            	auto node = root.addNodeInBack("expr_list");
            	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
            	(yyval) = node.getIndex();
            }
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 665 "bison.y" /* yacc.c:1646  */
    {
	   	auto node = root.addNodeInBack("var_list_e");
	   	auto empty = root.addNodeInBack("empty");
	   	root.addLink(node, empty, Empty{});
	   	(yyval) = node.getIndex();
	   }
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 672 "bison.y" /* yacc.c:1646  */
    {
            	auto node = root.addNodeInBack("var_list_e");
            	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
            	(yyval) = node.getIndex();
            }
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 680 "bison.y" /* yacc.c:1646  */
    {
	    	auto node = root.addNodeInBack("var_list");
	    	auto varname_node = root.addNodeInBack("VARNAME");
	    	root.addLink(node, varname_node, Empty{});
	    	(yyval) = node.getIndex();
	    }
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 687 "bison.y" /* yacc.c:1646  */
    {
	    	auto node = root.addNodeInBack("var_list");
	    	auto varname_node = root.addNodeInBack("VARNAME");
	    	auto assignment_node = root.addNodeInBack("=");
	    	root.addLink(node, varname_node, Empty{});
	    	root.addLink(node, assignment_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
	    	(yyval) = node.getIndex();
	    }
#line 2667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 697 "bison.y" /* yacc.c:1646  */
    {
	    	auto node = root.addNodeInBack("var_list");
	    	auto comma_node = root.addNodeInBack(",");
	    	auto varname_node = root.addNodeInBack("VARNAME");
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
	    	root.addLink(node, comma_node, Empty{});
	    	root.addLink(node, varname_node, Empty{});
	    	(yyval) = node.getIndex();
	    }
#line 2681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 707 "bison.y" /* yacc.c:1646  */
    {
	    	auto node = root.addNodeInBack("var_list");
	    	auto comma_node = root.addNodeInBack(",");
	    	auto varname_node = root.addNodeInBack("VARNAME");
	    	auto assignment_node = root.addNodeInBack("=");
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-4])), Empty{});
	    	root.addLink(node, comma_node, Empty{});
	    	root.addLink(node, varname_node, Empty{});
	    	root.addLink(node, assignment_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
	    	(yyval) = node.getIndex();
	    }
#line 2698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 722 "bison.y" /* yacc.c:1646  */
    {
				auto node = root.addNodeInBack("array_members_list_e");
				auto empty_node = root.addNodeInBack("empty");
				root.addLink(node, empty_node, Empty{});
				(yyval) = node.getIndex();
			}
#line 2709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 729 "bison.y" /* yacc.c:1646  */
    {
                        	auto node = root.addNodeInBack("array_members_list_e");
				root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
				(yyval) = node.getIndex();
                        }
#line 2719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 737 "bison.y" /* yacc.c:1646  */
    {
                        	auto node = root.addNodeInBack("array_members_list");
                        	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
                        	(yyval) = node.getIndex();

		    }
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 744 "bison.y" /* yacc.c:1646  */
    {
                    	auto node = root.addNodeInBack("array_members_list");
                    	auto comma_node = root.addNodeInBack(",");
                    	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
                    	root.addLink(node, comma_node, Empty{});
                    	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
                    	(yyval) = node.getIndex();
                    }
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 755 "bison.y" /* yacc.c:1646  */
    {
			auto node = root.addNodeInBack("array_member");
			auto sv_node = root.addNodeInBack("=>");
			root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
			root.addLink(node, sv_node, Empty{});
			root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
			(yyval) = node.getIndex();
		}
#line 2756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 764 "bison.y" /* yacc.c:1646  */
    {
                	auto node = root.addNodeInBack("array_member");
                	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
                }
#line 2765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 771 "bison.y" /* yacc.c:1646  */
    {
		auto node = root.addNodeInBack("if_stmt");
		auto if_node = root.addNodeInBack("if");
		root.addLink(node, if_node, Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[-3])), Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
		(yyval) = node.getIndex();
	}
#line 2780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 782 "bison.y" /* yacc.c:1646  */
    {
        		auto node = root.addNodeInBack("if_stmt");
        		auto if_node = root.addNodeInBack("if");
        		auto else_node = root.addNodeInBack("else");
        		root.addLink(node, if_node, Empty{});
        		root.addLink(node, root.getNodeByIndex((yyvsp[-5])), Empty{});
        		root.addLink(node, root.getNodeByIndex((yyvsp[-4])), Empty{});
        		root.addLink(node, root.getNodeByIndex((yyvsp[-3])), Empty{});
        		root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
        		root.addLink(node, else_node, Empty{});
        		root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
        		(yyval) = node.getIndex();
        }
#line 2798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 796 "bison.y" /* yacc.c:1646  */
    {
		auto node = root.addNodeInBack("if_stmt");
		auto if_node = root.addNodeInBack("if");
		root.addLink(node, if_node, Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[-4])), Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[-3])), Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
		(yyval) = node.getIndex();
	}
#line 2814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 808 "bison.y" /* yacc.c:1646  */
    {
        	auto node = root.addNodeInBack("if_stmt");
        	auto if_node = root.addNodeInBack("if");
        	auto else_node = root.addNodeInBack("else");
        	root.addLink(node, if_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-6])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-5])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-4])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-3])), Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
        	root.addLink(node, else_node, Empty{});
        	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
        	(yyval) = node.getIndex();
        }
#line 2833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 825 "bison.y" /* yacc.c:1646  */
    {
	    	auto node = root.addNodeInBack("elseif_stmt");
	    	auto elseif_node = root.addNodeInBack("elseif");
	    	root.addLink(node, elseif_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-3])), Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
	    	(yyval) = node.getIndex();
	    }
#line 2848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 836 "bison.y" /* yacc.c:1646  */
    {
            	auto node = root.addNodeInBack("elseif_stmt");
            	auto elseif_node = root.addNodeInBack("elseif");
            	root.addLink(node, root.getNodeByIndex((yyvsp[-5])), Empty{});
            	root.addLink(node, elseif_node, Empty{});
            	root.addLink(node, root.getNodeByIndex((yyvsp[-3])), Empty{});
            	root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
            	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
            	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
            	(yyval) = node.getIndex();
            }
#line 2864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 850 "bison.y" /* yacc.c:1646  */
    {
	    	auto node = root.addNodeInBack("switch_stmt");
	    	auto switch_node = root.addNodeInBack("switch");
	    	auto openbreacket_node = root.addNodeInBack("{");
	    	auto closebreacket_node = root.addNodeInBack("}");
	    	root.addLink(node, switch_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-5])), Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-4])), Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-3])), Empty{});
	    	root.addLink(node, openbreacket_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
	    	root.addLink(node, closebreacket_node, Empty{});
	    	(yyval) = node.getIndex();
	    }
#line 2883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 865 "bison.y" /* yacc.c:1646  */
    {
	    	auto node = root.addNodeInBack("switch_stmt");
	    	auto switch_node = root.addNodeInBack("switch");
	    	auto openbreacket_node = root.addNodeInBack("{");
	    	auto closebreacket_node = root.addNodeInBack("}");
	    	auto default_node = root.addNodeInBack("default");
	    	auto colon_node = root.addNodeInBack(":");
	    	root.addLink(node, switch_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-8])), Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-7])), Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-6])), Empty{});
	    	root.addLink(node, openbreacket_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-4])), Empty{});
	    	root.addLink(node, default_node, Empty{});
	    	root.addLink(node, colon_node, Empty{});
	    	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
	    	root.addLink(node, closebreacket_node, Empty{});
	    	(yyval) = node.getIndex();
	    }
#line 2907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 887 "bison.y" /* yacc.c:1646  */
    {
			auto node = root.addNodeInBack("case_stmt_list");
			auto case_node = root.addNodeInBack("case");
			auto colon_node = root.addNodeInBack(":");
			root.addLink(node, case_node, Empty{});
			root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
			root.addLink(node, colon_node, Empty{});
			root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
			(yyval) = node.getIndex();
	       }
#line 2922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 898 "bison.y" /* yacc.c:1646  */
    {
               		auto node = root.addNodeInBack("case_stmt_list");
               		auto case_node = root.addNodeInBack("case");
               		auto colon_node = root.addNodeInBack(":");
               		root.addLink(node, root.getNodeByIndex((yyvsp[-4])), Empty{});
               		root.addLink(node, case_node, Empty{});
               		root.addLink(node, root.getNodeByIndex((yyvsp[-2])), Empty{});
               		root.addLink(node, colon_node, Empty{});
               		root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
               		(yyval) = node.getIndex();
               }
#line 2938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 912 "bison.y" /* yacc.c:1646  */
    {
	     	auto node = root.addNodeInBack("function_def");
	     	auto function_node = root.addNodeInBack("function");
	     	auto id_node = root.addNodeInBack("ID");
	     	auto openbreaket_node = root.addNodeInBack("{");
	     	auto closebreaket_node = root.addNodeInBack("}");
	     	root.addLink(node, function_node, Empty{});
	     	root.addLink(node, id_node, Empty{});
	     	root.addLink(node, root.getNodeByIndex((yyvsp[-5])), Empty{});
	     	root.addLink(node, root.getNodeByIndex((yyvsp[-4])), Empty{});
	     	root.addLink(node, root.getNodeByIndex((yyvsp[-3])), Empty{});
	     	root.addLink(node, openbreaket_node, Empty{});
	     	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
	     	root.addLink(node, closebreaket_node, Empty{});
	     	(yyval) = node.getIndex();
	     }
#line 2959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 931 "bison.y" /* yacc.c:1646  */
    {
	  	auto node = root.addNodeInBack("class_def");
	  	auto class_node = root.addNodeInBack("class");
	  	auto id_node = root.addNodeInBack("ID");
	  	auto openbreaket_node = root.addNodeInBack("{");
	  	auto closebreaket_node = root.addNodeInBack("}");
	  	root.addLink(node, class_node, Empty{});
	  	root.addLink(node, id_node, Empty{});
	  	root.addLink(node, openbreaket_node, Empty{});
	  	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
	  	root.addLink(node, closebreaket_node, Empty{});
	  	(yyval) = node.getIndex();
	  }
#line 2977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 945 "bison.y" /* yacc.c:1646  */
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
	  	root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
	  	root.addLink(node, closebreaket_node, Empty{});
	  	(yyval) = node.getIndex();
          }
#line 2999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 965 "bison.y" /* yacc.c:1646  */
    {
		    	auto node = root.addNodeInBack("class_body_element");
		    	auto var_node = root.addNodeInBack("var");
		    	auto varname_node = root.addNodeInBack("VARNAME");
		    	auto semicolon_node = root.addNodeInBack(";");
		    	root.addLink(node, var_node, Empty{});
		    	root.addLink(node, varname_node, Empty{});
		    	root.addLink(node, semicolon_node, Empty{});
		    	(yyval) = node.getIndex();
		    }
#line 3014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 976 "bison.y" /* yacc.c:1646  */
    {
		    	auto node = root.addNodeInBack("class_body_element");
		    	auto public_node = root.addNodeInBack("public");
		    	auto varname_node = root.addNodeInBack("VARNAME");
		    	auto semicolon_node = root.addNodeInBack(";");
		    	root.addLink(node, public_node, Empty{});
		    	root.addLink(node, varname_node, Empty{});
		    	root.addLink(node, semicolon_node, Empty{});
		    	(yyval) = node.getIndex();
		    }
#line 3029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 987 "bison.y" /* yacc.c:1646  */
    {
		    	auto node = root.addNodeInBack("class_body_element");
		    	auto private_node = root.addNodeInBack("private");
		    	auto varname_node = root.addNodeInBack("VARNAME");
		    	auto semicolon_node = root.addNodeInBack(";");
		    	root.addLink(node, private_node, Empty{});
		    	root.addLink(node, varname_node, Empty{});
		    	root.addLink(node, semicolon_node, Empty{});
		    	(yyval) = node.getIndex();
		    }
#line 3044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 998 "bison.y" /* yacc.c:1646  */
    {
		    	auto node = root.addNodeInBack("class_body_element");
		    	auto protected_node = root.addNodeInBack("protected");
		    	auto varname_node = root.addNodeInBack("VARNAME");
		    	auto semicolon_node = root.addNodeInBack(";");
		    	root.addLink(node, protected_node, Empty{});
		    	root.addLink(node, varname_node, Empty{});
		    	root.addLink(node, semicolon_node, Empty{});
		    	(yyval) = node.getIndex();
		    }
#line 3059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1009 "bison.y" /* yacc.c:1646  */
    {
                    	auto node = root.addNodeInBack("class_body_element");
                    	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
                    	(yyval) = node.getIndex();
                    }
#line 3069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1015 "bison.y" /* yacc.c:1646  */
    {
                    	auto node = root.addNodeInBack("class_body_element");
                    	auto public_node = root.addNodeInBack("public");
                    	root.addLink(node, public_node, Empty{});
                    	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
                    	(yyval) = node.getIndex();
                    }
#line 3081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1023 "bison.y" /* yacc.c:1646  */
    {
                    	auto node = root.addNodeInBack("class_body_element");
                    	auto private_node = root.addNodeInBack("private");
                    	root.addLink(node, private_node, Empty{});
                    	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
                    	(yyval) = node.getIndex();
                    }
#line 3093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1031 "bison.y" /* yacc.c:1646  */
    {
                    	auto node = root.addNodeInBack("class_body_element");
                    	auto protected_node = root.addNodeInBack("protected");
                    	root.addLink(node, protected_node, Empty{});
                    	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
                    	(yyval) = node.getIndex();
                    }
#line 3105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1040 "bison.y" /* yacc.c:1646  */
    {
		auto node = root.addNodeInBack("class_body");
		root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
		(yyval) = node.getIndex();
	   }
#line 3115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1046 "bison.y" /* yacc.c:1646  */
    {
		auto node = root.addNodeInBack("class_body");
		root.addLink(node, root.getNodeByIndex((yyvsp[-1])), Empty{});
		root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
		(yyval) = node.getIndex();
	   }
#line 3126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1055 "bison.y" /* yacc.c:1646  */
    {
		auto node = root.addNodeInBack("class_body_e");
		auto empty_node = root.addNodeInBack("empty");
		root.addLink(node, empty_node, Empty{});
		(yyval) = node.getIndex();
             }
#line 3137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1062 "bison.y" /* yacc.c:1646  */
    {
             	auto node = root.addNodeInBack("class_body_e");
             	root.addLink(node, root.getNodeByIndex((yyvsp[0])), Empty{});
             	(yyval) = node.getIndex();
             }
#line 3147 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3151 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
