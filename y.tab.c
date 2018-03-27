/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "limbaj.y"
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno; 

int   decl_type = -1;
char* user_type_arr[16];

#define STACK_SIZE 512

int exp_type_stack[STACK_SIZE];
int t1, t2, t;
int top = 0;

void PushExpType(int exp_type)
{
      if(top < STACK_SIZE) exp_type_stack[top++] = exp_type;
}

int PopExpType()
{
      return exp_type_stack[--top];
}

typedef struct{
      char* name;
      int data_type;
      union{
            int* i;
            
            double* d;
            char* c;
      }val;
} Id;

Id id_table[128];

#line 41 "limbaj.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
      int ival;
      double rval;
      char* strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 72 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define BGIN 257
#define END 258
#define INT_POZ 259
#define REAL_POZ 260
#define TEXT_VAL 261
#define BOOL_VAL 262
#define BOOL 263
#define INT 264
#define REAL 265
#define TEXT 266
#define USER_TYPE 267
#define USE 268
#define INTO 269
#define IF 270
#define THEN 271
#define ELSE 272
#define FOR 273
#define WHILE 274
#define DO 275
#define RET 276
#define FUNC_ID 277
#define RIGHT_ARROW 278
#define PRINT 279
#define FACTORIAL 280
#define MAX 281
#define CONST_ID 282
#define VAR_ID 283
#define ASSIGN 284
#define TIMES 285
#define INC 286
#define DEC 287
#define TO_UPPER 288
#define LOGICAL_NOT 289
#define EQ 290
#define NEQ 291
#define LT 292
#define LTE 293
#define GT 294
#define GTE 295
#define UMINUS 296
#define UPLUS 297
#define IFX 298
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    5,    5,    5,    5,    6,    6,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    1,   12,   12,    2,    2,
   15,   15,    9,    9,    9,   10,   11,   11,   16,   16,
   17,   17,   18,   18,   18,   18,   18,   18,   18,   18,
    4,    4,   13,   14,   14,   21,   22,   22,    3,   23,
   23,   24,   26,   26,   26,   26,   26,   26,    8,    8,
    8,   25,   25,   27,   27,   19,   19,   19,   19,   28,
   20,   20,
};
static const YYINT yylen[] = {                            2,
    2,    2,    2,    3,    1,    1,    1,    1,    1,    1,
    1,    1,    3,    3,    3,    2,    1,    1,    3,    4,
    6,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    5,    1,    2,    2,    2,
    1,    1,    1,    4,    3,    3,    3,    4,    1,    3,
    2,    3,    1,    1,    2,    4,    6,    8,    4,    5,
    1,    2,    2,    6,    5,    3,    3,    4,    2,    1,
    3,    3,    1,    2,    2,    1,    2,    2,    1,    1,
    1,    1,    3,    1,    3,    1,    1,    3,    3,    2,
    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    5,    6,    7,    8,   10,    0,    0,    0,    0,
    0,    0,    9,    0,    0,    0,   73,   76,   81,   80,
    0,    0,    0,    0,    0,    0,    0,   42,   41,    0,
    0,    0,    0,    0,    0,    0,    0,   53,    0,    0,
   11,    0,   17,   18,    0,   43,   54,   61,   79,   37,
    0,    0,    1,    2,    3,    0,   70,    0,    0,   87,
   39,   40,    0,   69,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   16,   35,   74,   77,   75,
   78,    0,   51,    0,    4,   62,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   55,
    0,    0,    0,    0,   38,    0,    0,    0,   91,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   14,   15,   19,   52,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   24,   25,   26,    0,   46,   45,    0,    0,    0,   90,
    0,    0,   71,    0,   89,    0,   82,   72,    0,    0,
   67,   47,    0,    0,    0,   59,   48,    0,   20,    0,
   44,   36,   65,   92,    0,   84,    0,   68,   66,    0,
    0,   60,    0,   64,    0,   83,   57,    0,   21,   85,
    0,   58,
};
static const YYINT yydgoto[] = {                          9,
   10,   38,   12,   39,   13,   14,   40,   41,   42,   43,
   44,   51,   15,   45,   46,  122,   47,   48,   58,  108,
  115,   64,   59,   60,  158,   49,  177,  109,
};
static const YYINT yysindex[] = {                       284,
  684,    0,    0,    0,    0,    0,   49,   -1,    0,  284,
  284,  284,    0, -245,  -28,  -50,    0,    0,    0,    0,
  817,  817,  817,   20,   28,   31,   46,    0,    0, -256,
 -256,  817,  817, -121,  -96,  817,  567,    0,  356,   -2,
    0,  -36,    0,    0,   29,    0,    0,    0,    0,    0,
  -59,  -21,    0,    0,    0, -182,    0,   71, -175,    0,
    0,    0,  684,    0,   77,   16,  123,    7,   27,  716,
  817,  817,  817,  296,  296,    0,    0,    0,    0,    0,
    0,   38,    0,  621,    0,    0,  817,  817,  817,  817,
  817,  817,  817,  817,  817,  817,  817,  817,  817,    0,
  817,  -68,  817, -136,    0, -135, -245,  104,    0, -245,
 -245,   90,  684,  -26,   22,  773,  684,  817,  817,  684,
 -135,  208,   52,   63,   76, -256,    0,    0,    0,    0,
  147,  147,  418,  418,  418,  418,  136,    5,   65,   65,
    0,    0,    0,  123,    0,    0,   87,   93,  -35,    0,
  -35, -122,    0, -175,    0,   90,    0,    0,   42,  110,
    0,    0, -101,  123,   99,    0,    0,  132,    0,  817,
    0,    0,    0,    0,  -35,    0,  -41,    0,    0,  684,
  817,    0,  112,    0,   90,    0,    0,  -42,    0,    0,
  684,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -37,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  153,   23,    0,
    0,    0,    0,    0,    0,    0,  144,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -13,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  479,  501,  394,  440,  447,  472,  403,  590,  181,  405,
    0,    0,    0,  660,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   33,    0,    0,    0,    0,    0,    0,
    0,    0,  523,  158,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                       249,
    0,  186,    0,  -14,    0,   26, 1048,  -94,  190,    0,
   80,    0,    0,  116,  398,   -9,    0,  491,    0,    0,
   82,    0,  165,  105, -141,    0,    0,   84,
};
#define YYTABLESIZE 1229
static const YYINT yytable[] = {                         12,
   12,  118,  185,   12,   12,   12,   12,   12,   62,   12,
   99,   94,   68,   56,  176,   97,   95,  157,   96,  106,
   98,   12,   84,   47,   47,   28,   29,  102,   47,   47,
   61,   47,  100,   47,   99,   94,   28,   29,   52,   97,
   95,   99,   96,  190,   98,   47,   97,   95,  113,   96,
  118,   98,   99,   94,  103,   12,  100,   97,   95,   70,
   96,  157,   98,   99,   94,  119,   86,   71,   97,   95,
   72,   96,   63,   98,   99,   94,   88,  107,  129,   97,
   95,   86,   96,  186,   98,   73,   12,   62,   99,   94,
  157,   88,  168,   97,   95,  107,   96,   93,   98,   99,
   94,   99,  110,  169,   97,   95,   97,   96,  112,   98,
   47,   98,   99,   94,  111,   16,  116,   97,   95,  170,
   96,   93,   98,   99,   94,   16,   16,   16,   97,   95,
  148,   96,   34,   98,   35,   99,   94,   78,   79,   93,
   97,   95,  149,   96,  152,   98,  161,  151,   99,   94,
   93,  172,  189,   97,   95,  175,   96,  181,   98,   99,
   94,   93,   80,   81,   97,   95,  178,   96,  179,   98,
  180,  188,   99,   94,  173,   93,  107,   97,   95,  171,
   96,  145,   98,   99,   49,   11,   93,   49,   97,   95,
  182,   96,   50,   98,  159,   11,   11,   11,   50,   93,
  184,   50,   49,    2,    3,    4,    5,    6,   65,  104,
   93,   63,  156,   28,   29,  155,   50,    8,   22,   74,
   75,   22,   93,   22,   22,   22,    0,    2,    3,    4,
    5,    6,  191,   12,  174,   93,  105,   12,   12,   22,
    0,    2,    3,    4,    5,    6,   93,  101,  167,  160,
    0,  118,   12,   12,   12,   12,   12,   12,   53,   54,
   55,    0,   47,   87,   88,   89,   90,   91,   92,    0,
    0,  150,    0,   22,  153,  154,   47,   47,   47,   47,
   47,   47,    0,    0,    0,    0,  117,   87,   88,   89,
   90,   91,   92,    0,   87,   88,   89,   90,   91,   92,
    0,  120,    0,    0,   22,   87,   88,   89,   90,   91,
   92,    2,    3,    4,    5,    6,   87,   88,   89,   90,
   91,   92,    0,    0,    0,    8,    0,   87,   88,   89,
   90,   91,   92,    0,    0,   36,    0,    0,   34,    0,
   35,   87,   88,   89,   90,   91,   92,    0,   17,   18,
   19,   20,   87,   88,   89,   90,   91,   92,    0,  126,
    0,    0,    0,    0,    0,   87,   88,   89,   90,   91,
   92,    0,    0,    0,    0,    0,   87,   88,   89,   90,
   91,   92,    0,    0,    0,    0,  103,    0,   87,   88,
   89,   90,   91,   92,    0,   36,    0,    0,   34,    0,
   35,   87,   88,   89,   90,   91,   92,    0,    0,    0,
    0,   57,   87,   88,   89,   90,   91,   92,   49,    0,
    0,    0,    0,    0,    0,   87,   88,   89,   90,   91,
   92,   27,   50,    0,   27,    0,    0,   27,   89,   90,
   91,   92,   23,   34,    0,   23,   34,   23,   23,   23,
    0,   22,   27,    0,   99,   22,   22,    0,    0,   97,
   95,   34,   96,   23,   98,    0,    0,    0,    0,    0,
   22,   22,   22,   22,   22,   22,    0,   28,   37,    0,
   28,    0,    0,   28,   29,    0,   27,   29,    0,    0,
   29,    0,    0,    0,    0,   34,    0,   23,   28,  146,
    0,    0,    0,    0,   57,   29,    0,   57,   57,   30,
    0,    0,   30,    0,    0,   30,   31,   27,    0,   31,
    0,    0,   31,  146,    0,    0,   34,    0,   23,   86,
   30,    0,   28,    0,    0,    0,    0,   31,   32,   29,
    1,   32,    0,    0,   32,    0,    2,    3,    4,    5,
    6,    7,    0,    0,   17,   18,   19,   20,    0,   32,
    8,    0,   56,   28,   30,   56,    0,   56,    0,    0,
   29,   31,   65,    0,   86,   26,   27,   28,   29,    0,
    0,   30,   31,   32,   33,    0,    0,    0,    0,    0,
    0,    0,    0,   32,    0,   30,    0,    0,    0,    0,
    0,    0,   31,   86,    0,    0,   36,  163,    0,   34,
  166,   35,    0,   85,   17,   18,   19,   20,    2,    3,
    4,    5,    6,    0,   32,   21,    0,   33,   22,   23,
   33,    0,   24,   33,   25,   26,   27,   28,   29,    0,
    0,   30,   31,   32,   33,   56,    0,   56,   33,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   36,    0,    0,   34,   27,   35,    0,    0,   27,   27,
  187,    0,    0,   34,    0,   23,    0,   34,   34,   23,
   23,  192,   33,   27,   27,   27,   27,   27,   27,   37,
    0,   83,    0,    0,   23,   23,   23,   23,   23,   23,
   13,    0,    0,   13,    0,    0,    0,    0,    0,    0,
   28,    0,    0,   33,   28,   28,    0,   29,   13,    0,
    0,   29,   29,   36,    0,    0,   34,    0,   35,   28,
   28,   28,   28,   28,   28,    0,   29,   29,   29,   29,
   29,   29,   30,   37,    0,  130,   30,   30,    0,   31,
    0,    0,   13,   31,   31,   36,  121,    0,   34,    0,
   35,   30,   30,   30,   30,   30,   30,    0,   31,   31,
    0,   32,    0,    0,    0,   32,   32,    0,    0,    0,
   56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
   32,   32,   56,    0,    0,   56,   56,    0,    0,   56,
    0,   56,   56,   56,   56,   56,   37,    0,   56,   56,
   56,   56,   36,  162,    0,   34,    0,   35,    0,    0,
    0,    0,    0,    0,    0,   17,   18,   19,   20,    2,
    3,    4,    5,    6,    0,    0,   21,    0,    0,   22,
   23,    0,    0,   24,    0,   25,   26,   27,   28,   29,
    0,    0,   30,   31,   32,   33,   36,    0,    0,   34,
   33,   35,    0,    0,   33,   33,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   17,
   18,   19,   20,    2,    3,    4,    5,    6,    0,    0,
   21,    0,    0,   22,   23,    0,    0,   24,    0,   25,
   26,   27,   28,   29,    0,    0,   30,   31,   32,   33,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   13,    0,    0,    0,   13,   13,    0,    0,    0,    0,
    0,    0,   17,   18,   19,   20,    2,    3,    4,    5,
    6,    0,    0,   21,    0,    0,   22,   23,    0,    0,
   24,    0,   25,   26,   27,   28,   29,    0,    0,   30,
   31,   32,   33,    0,   17,   18,   19,   20,    2,    3,
    4,    5,    6,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   65,    0,    0,   26,   27,   28,   29,    0,
    0,   30,   31,   32,   33,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   17,   18,   19,   20,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   65,
    0,    0,   26,   27,   28,   29,    0,    0,   30,   31,
   32,   33,    0,    0,    0,    0,    0,    0,   66,   67,
   69,    0,    0,    0,    0,   17,   18,   19,   20,   76,
   77,    0,    0,   82,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   65,    0,    0,   26,   27,   28,   29,
    0,    0,   30,   31,   32,   33,    0,    0,    0,    0,
  114,    0,    0,    0,    0,    0,    0,   67,  123,  124,
  125,  127,  128,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  131,  132,  133,  134,  135,  136,
  137,  138,  139,  140,  141,  142,  143,    0,  144,    0,
  147,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  114,    0,    0,   67,    0,  164,  165,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  183,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   67,
};
static const YYINT yycheck[] = {                         37,
   38,   44,   44,   41,   42,   43,   44,   45,   59,   47,
   37,   38,   22,  259,  156,   42,   43,  112,   45,   41,
   47,   59,   37,   37,   38,  282,  283,   64,   42,   43,
   59,   45,   59,   47,   37,   38,  282,  283,   40,   42,
   43,   37,   45,  185,   47,   59,   42,   43,   63,   45,
   44,   47,   37,   38,   91,   93,   59,   42,   43,   40,
   45,  156,   47,   37,   38,   59,   44,   40,   42,   43,
   40,   45,  123,   47,   37,   38,   44,   52,   41,   42,
   43,   59,   45,  125,   47,   40,  124,   59,   37,   38,
  185,   59,   41,   42,   43,   70,   45,  124,   47,   37,
   38,   37,  285,   41,   42,   43,   42,   45,  284,   47,
  124,   47,   37,   38,   44,    0,   40,   42,   43,   44,
   45,  124,   47,   37,   38,   10,   11,   12,   42,   43,
  267,   45,   43,   47,   45,   37,   38,  259,  260,  124,
   42,   43,  278,   45,   41,   47,  125,   44,   37,   38,
  124,   59,   41,   42,   43,  278,   45,   59,   47,   37,
   38,  124,  259,  260,   42,   43,  125,   45,   59,   47,
  272,  181,   37,   38,  149,  124,  151,   42,   43,   93,
   45,  102,   47,   37,   41,    0,  124,   44,   42,   43,
   59,   45,    7,   47,  113,   10,   11,   12,   41,  124,
  175,   44,   59,  263,  264,  265,  266,  267,  277,  269,
  124,   59,  123,  282,  283,  111,   59,  277,   38,   30,
   31,   41,  124,   43,   44,   45,   -1,  263,  264,  265,
  266,  267,  275,  271,  151,  124,   51,  275,  276,   59,
   -1,  263,  264,  265,  266,  267,  124,  284,   41,  276,
   -1,   44,  290,  291,  292,  293,  294,  295,   10,   11,
   12,   -1,  276,  290,  291,  292,  293,  294,  295,   -1,
   -1,  107,   -1,   93,  110,  111,  290,  291,  292,  293,
  294,  295,   -1,   -1,   -1,   -1,  271,  290,  291,  292,
  293,  294,  295,   -1,  290,  291,  292,  293,  294,  295,
   -1,  275,   -1,   -1,  124,  290,  291,  292,  293,  294,
  295,  263,  264,  265,  266,  267,  290,  291,  292,  293,
  294,  295,   -1,   -1,   -1,  277,   -1,  290,  291,  292,
  293,  294,  295,   -1,   -1,   40,   -1,   -1,   43,   -1,
   45,  290,  291,  292,  293,  294,  295,   -1,  259,  260,
  261,  262,  290,  291,  292,  293,  294,  295,   -1,   64,
   -1,   -1,   -1,   -1,   -1,  290,  291,  292,  293,  294,
  295,   -1,   -1,   -1,   -1,   -1,  290,  291,  292,  293,
  294,  295,   -1,   -1,   -1,   -1,   91,   -1,  290,  291,
  292,  293,  294,  295,   -1,   40,   -1,   -1,   43,   -1,
   45,  290,  291,  292,  293,  294,  295,   -1,   -1,   -1,
   -1,   14,  290,  291,  292,  293,  294,  295,  275,   -1,
   -1,   -1,   -1,   -1,   -1,  290,  291,  292,  293,  294,
  295,   38,  275,   -1,   41,   -1,   -1,   44,  292,  293,
  294,  295,   38,   41,   -1,   41,   44,   43,   44,   45,
   -1,  271,   59,   -1,   37,  275,  276,   -1,   -1,   42,
   43,   59,   45,   59,   47,   -1,   -1,   -1,   -1,   -1,
  290,  291,  292,  293,  294,  295,   -1,   38,  123,   -1,
   41,   -1,   -1,   44,   38,   -1,   93,   41,   -1,   -1,
   44,   -1,   -1,   -1,   -1,   93,   -1,   93,   59,  102,
   -1,   -1,   -1,   -1,  107,   59,   -1,  110,  111,   38,
   -1,   -1,   41,   -1,   -1,   44,   38,  124,   -1,   41,
   -1,   -1,   44,  126,   -1,   -1,  124,   -1,  124,   39,
   59,   -1,   93,   -1,   -1,   -1,   -1,   59,   38,   93,
  257,   41,   -1,   -1,   44,   -1,  263,  264,  265,  266,
  267,  268,   -1,   -1,  259,  260,  261,  262,   -1,   59,
  277,   -1,   40,  124,   93,   43,   -1,   45,   -1,   -1,
  124,   93,  277,   -1,   84,  280,  281,  282,  283,   -1,
   -1,  286,  287,  288,  289,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   93,   -1,  124,   -1,   -1,   -1,   -1,
   -1,   -1,  124,  113,   -1,   -1,   40,  117,   -1,   43,
  120,   45,   -1,  258,  259,  260,  261,  262,  263,  264,
  265,  266,  267,   -1,  124,  270,   -1,   38,  273,  274,
   41,   -1,  277,   44,  279,  280,  281,  282,  283,   -1,
   -1,  286,  287,  288,  289,  123,   -1,  125,   59,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   40,   -1,   -1,   43,  271,   45,   -1,   -1,  275,  276,
  180,   -1,   -1,  271,   -1,  271,   -1,  275,  276,  275,
  276,  191,   93,  290,  291,  292,  293,  294,  295,  123,
   -1,  125,   -1,   -1,  290,  291,  292,  293,  294,  295,
   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,
  271,   -1,   -1,  124,  275,  276,   -1,  271,   59,   -1,
   -1,  275,  276,   40,   -1,   -1,   43,   -1,   45,  290,
  291,  292,  293,  294,  295,   -1,  290,  291,  292,  293,
  294,  295,  271,  123,   -1,  125,  275,  276,   -1,  271,
   -1,   -1,   93,  275,  276,   40,   41,   -1,   43,   -1,
   45,  290,  291,  292,  293,  294,  295,   -1,  290,  291,
   -1,  271,   -1,   -1,   -1,  275,  276,   -1,   -1,   -1,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  290,  291,  270,   -1,   -1,  273,  274,   -1,   -1,  277,
   -1,  279,  280,  281,  282,  283,  123,   -1,  286,  287,
  288,  289,   40,   41,   -1,   43,   -1,   45,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  259,  260,  261,  262,  263,
  264,  265,  266,  267,   -1,   -1,  270,   -1,   -1,  273,
  274,   -1,   -1,  277,   -1,  279,  280,  281,  282,  283,
   -1,   -1,  286,  287,  288,  289,   40,   -1,   -1,   43,
  271,   45,   -1,   -1,  275,  276,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,
  260,  261,  262,  263,  264,  265,  266,  267,   -1,   -1,
  270,   -1,   -1,  273,  274,   -1,   -1,  277,   -1,  279,
  280,  281,  282,  283,   -1,   -1,  286,  287,  288,  289,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  271,   -1,   -1,   -1,  275,  276,   -1,   -1,   -1,   -1,
   -1,   -1,  259,  260,  261,  262,  263,  264,  265,  266,
  267,   -1,   -1,  270,   -1,   -1,  273,  274,   -1,   -1,
  277,   -1,  279,  280,  281,  282,  283,   -1,   -1,  286,
  287,  288,  289,   -1,  259,  260,  261,  262,  263,  264,
  265,  266,  267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  277,   -1,   -1,  280,  281,  282,  283,   -1,
   -1,  286,  287,  288,  289,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  259,  260,  261,  262,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  277,
   -1,   -1,  280,  281,  282,  283,   -1,   -1,  286,  287,
  288,  289,   -1,   -1,   -1,   -1,   -1,   -1,   21,   22,
   23,   -1,   -1,   -1,   -1,  259,  260,  261,  262,   32,
   33,   -1,   -1,   36,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  277,   -1,   -1,  280,  281,  282,  283,
   -1,   -1,  286,  287,  288,  289,   -1,   -1,   -1,   -1,
   63,   -1,   -1,   -1,   -1,   -1,   -1,   70,   71,   72,
   73,   74,   75,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   87,   88,   89,   90,   91,   92,
   93,   94,   95,   96,   97,   98,   99,   -1,  101,   -1,
  103,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  113,   -1,   -1,  116,   -1,  118,  119,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  170,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  181,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 298
#define YYUNDFTOKEN 329
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,
0,0,0,"';'",0,0,0,0,"'@'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",
"'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"BGIN","END","INT_POZ","REAL_POZ","TEXT_VAL",
"BOOL_VAL","BOOL","INT","REAL","TEXT","USER_TYPE","USE","INTO","IF","THEN",
"ELSE","FOR","WHILE","DO","RET","FUNC_ID","RIGHT_ARROW","PRINT","FACTORIAL",
"MAX","CONST_ID","VAR_ID","ASSIGN","TIMES","INC","DEC","TO_UPPER","LOGICAL_NOT",
"EQ","NEQ","LT","LTE","GT","GTE","UMINUS","UPLUS","IFX",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : pgm",
"pgm : user_type_decl pgm",
"pgm : decl pgm",
"pgm : func_def pgm",
"pgm : BGIN stmt_list END",
"primitive_type : BOOL",
"primitive_type : INT",
"primitive_type : REAL",
"primitive_type : TEXT",
"type : primitive_type",
"type : USER_TYPE",
"exp : constant",
"exp : access_exp",
"exp : access_exp ASSIGN exp",
"exp : INC access_exp exp",
"exp : DEC access_exp exp",
"exp : TO_UPPER exp",
"exp : access_func",
"exp : func_call",
"exp : '(' exp ')'",
"exp : FACTORIAL '(' exp ')'",
"exp : MAX '(' exp ',' exp ')'",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : exp '*' exp",
"exp : exp '/' exp",
"exp : exp '%' exp",
"exp : exp LT exp",
"exp : exp LTE exp",
"exp : exp GT exp",
"exp : exp GTE exp",
"exp : exp EQ exp",
"exp : exp NEQ exp",
"exp : exp '&' exp",
"exp : exp '|' exp",
"exp : LOGICAL_NOT exp",
"user_type_decl : USE decls INTO USER_TYPE ';'",
"decls : decl",
"decls : decls decl",
"decl : data_decl ';'",
"decl : func_decl ';'",
"data_id : VAR_ID",
"data_id : CONST_ID",
"access_exp : data_id",
"access_exp : access_exp '[' exp ']'",
"access_exp : access_exp '@' data_id",
"access_func : access_exp '@' func_call",
"func_call : FUNC_ID '(' ')'",
"func_call : FUNC_ID '(' exp_list ')'",
"exp_list : exp",
"exp_list : exp_list ',' exp",
"stmt_block : '{' '}'",
"stmt_block : '{' stmt_list '}'",
"stmt : decl",
"stmt : stmt_block",
"stmt : exp ';'",
"stmt : IF exp THEN stmt",
"stmt : IF exp THEN stmt ELSE stmt",
"stmt : FOR exp_list ';' exp ';' exp_list DO stmt",
"stmt : WHILE exp DO stmt",
"stmt : PRINT '(' exp ')' ';'",
"stmt_list : stmt",
"stmt_list : stmt_list stmt",
"data_decl : type data_decl_body",
"func_decl : FUNC_ID '(' params ')' RIGHT_ARROW type",
"func_decl : FUNC_ID '(' ')' RIGHT_ARROW type",
"ret_stmt : exp RET ';'",
"func_body : '{' ret_stmt '}'",
"func_body : '{' stmt_list ret_stmt '}'",
"func_def : func_decl func_body",
"data_decl_body_simple : data_id",
"data_decl_body_simple : INT_POZ TIMES data_decl_body_simple",
"data_decl_body_init : data_decl_body_simple ASSIGN initializer",
"num_const : INT_POZ",
"num_const : '+' INT_POZ",
"num_const : '-' INT_POZ",
"num_const : REAL_POZ",
"num_const : '+' REAL_POZ",
"num_const : '-' REAL_POZ",
"constant : num_const",
"constant : BOOL_VAL",
"constant : TEXT_VAL",
"initializer : constant",
"initializer : '{' initializer_list '}'",
"initializer_list : initializer",
"initializer_list : initializer_list ',' initializer",
"data_decl_body : data_decl_body_simple",
"data_decl_body : data_decl_body_init",
"data_decl_body : data_decl_body ',' data_decl_body_simple",
"data_decl_body : data_decl_body ',' data_decl_body_init",
"param : type data_decl_body_simple",
"params : param",
"params : params ',' param",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 356 "limbaj.y"
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
#line 664 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 4:
#line 101 "limbaj.y"
	{printf("\nprogram corect sintactic!\n");}
break;
#line 870 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
