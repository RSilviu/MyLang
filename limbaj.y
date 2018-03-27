%{
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

%}

%union{
      int ival;
      double rval;
      char* strval;
}

%token BGIN END

%token INT_POZ REAL_POZ TEXT_VAL BOOL_VAL

%token BOOL INT REAL TEXT USER_TYPE USE INTO

%token IF THEN ELSE FOR WHILE DO

%token RET FUNC_ID RIGHT_ARROW

%token PRINT FACTORIAL MAX

%token CONST_ID VAR_ID  

%token ASSIGN

%token TIMES 

%token INC DEC

%token TO_UPPER

%token LOGICAL_NOT EQ NEQ LT LTE GT GTE

%left   ','

%right  ASSIGN

%left   '|'

%left   '&'

%left   EQ NEQ

%left  LT LTE GT GTE

%left   '+'  '-'

%left   '*'  '/'  '%'

%right   TO_UPPER LOGICAL_NOT INC DEC UMINUS UPLUS

%left    '@' '(' ')' '[' ']'

%nonassoc IFX
%nonassoc ELSE

%start pgm

%%

pgm : user_type_decl pgm
      | decl pgm
      | func_def pgm
      | BGIN stmt_list END {printf("\nprogram corect sintactic!\n");}
      ;

primitive_type : BOOL
      | INT
      | REAL
      | TEXT
      ;

type : primitive_type   
      | USER_TYPE       
      ;


/*array_type : type WS INT_VAL TIMES  
            ;   /* Int 10x10x */

/*
aexp_list : aexp
      | aexp_list ',' aexp
      ;*/

exp : constant
      | access_exp
      | access_exp ASSIGN exp 
      | INC access_exp exp    
      | DEC access_exp exp
      | TO_UPPER exp
      | access_func
      | func_call
      | '(' exp ')'
      ;

exp : FACTORIAL '(' exp ')'
      | MAX '(' exp ',' exp ')'
      | exp '+' exp 
      | exp '-' exp
      | exp '*' exp
      | exp '/' exp
      | exp '%' exp
      ;

exp : exp LT exp
      | exp LTE exp
      | exp GT exp
      | exp GTE exp
      | exp EQ exp
      | exp NEQ exp
      | exp '&' exp
      | exp '|' exp
      | LOGICAL_NOT exp
      ;
/*
array_decl_body : array_size data_id
      ;
*/
user_type_decl : USE decls INTO USER_TYPE ';' 
            ;     

decls : decl
      | decls decl
      ;

decl : data_decl ';'    
      | func_decl ';'   
      ;

data_id : VAR_ID        
        | CONST_ID      
        ;

/*
if(decl_type)
{
      cauta in decl din current_scope;
      
      if(exista) eroare;
      
      else{
            data_type = decl_type;
            name = 
            var = 
            init = 

      } 
}
else
{
      if(nu apare in declaratii) eroare;
}
*/


access_exp : data_id
      | access_exp '[' exp ']'
      | access_exp '@' data_id
      ;

access_func : access_exp '@' func_call
            ;

func_call :  FUNC_ID '(' ')'
      | FUNC_ID '(' exp_list ')'
      ;

exp_list : exp
      | exp_list ',' exp
      ;

stmt_block : '{' '}'
      | '{' stmt_list '}'
      ;

stmt : decl 
      | stmt_block
      | exp ';'
      | IF exp THEN stmt %prec IFX 
      | IF exp THEN stmt ELSE stmt 
      | FOR exp_list ';' exp ';' exp_list DO stmt
      | WHILE exp DO stmt
      ;

stmt : PRINT '(' exp ')' ';'
      ;

stmt_list : stmt
      | stmt_list stmt
      ;

data_decl : type  data_decl_body 
      ;

/*
data_decl_body : var_decl_body
      | const_decl_body
      ;

var_decl_body : var_init_decl_body stmt assign || var assign rules 
      | VAR_ID
      ;

var_init_decl_body : VAR_ID ASSIGN initializer ; /* assign stmt ? 

var_init_list : var_init_decl
      | var_init_list ',' var_init_decl
      ;

var_decl : type var_list ;

const_init : CONST_ID ASSIGN initializer ;      /* N : 10 

const_decl_body : const_init ;

const_init_list : const_init
      | const_init_list ',' const_init
      ;*/

func_decl : FUNC_ID '(' params ')' RIGHT_ARROW type  
          | FUNC_ID '(' ')' RIGHT_ARROW type
          ;

ret_stmt : exp RET ';'
      ;

func_body : '{' ret_stmt '}'
      | '{' stmt_list ret_stmt '}'
      ;

func_def : func_decl func_body 
      ; 


/*    
simple_decl_body : var_list
      | const_init_list
      | var_init_list
      | array_decl_body
      ;*/

/*
array_size : INT_VAL TIMES 
      | array_size INT_VAL TIMES
      ;*/

data_decl_body_simple : data_id
      | INT_POZ TIMES  data_decl_body_simple
      ;

data_decl_body_init : data_decl_body_simple ASSIGN initializer
      ;

num_const : INT_POZ                 
      | '+' INT_POZ %prec UPLUS     
      | '-' INT_POZ %prec UMINUS    
      | REAL_POZ                    
      | '+' REAL_POZ %prec UPLUS    
      | '-' REAL_POZ %prec UMINUS   
      ;

constant : num_const
      | BOOL_VAL        
      | TEXT_VAL        
      ;

initializer :  constant
            | '{' initializer_list '}'
            ;

initializer_list : initializer
      | initializer_list ',' initializer
      ;

/*
data_decl_body_simple : VAR_ID
      | const_init
      | var_init_decl_body
      | array_decl_body
      ;*/      

data_decl_body : data_decl_body_simple
      | data_decl_body_init
      | data_decl_body ',' data_decl_body_simple
      | data_decl_body ',' data_decl_body_init
      ;

/*
data_ids : data_id
         | data_ids ',' data_id
         ;*/
   
/*
var : VAR_ID
      | VAR_ID '[' int_exp ']'
      ;

const_data : CONST_ID
      | CONST_ID '[' int_exp ']'
      ;

array_elem : data_id '[' int_exp ']'
      | array_elem '[' int_exp ']'
      ;

var_list : VAR_ID
      | var_list ',' VAR_ID       
      ;*/ 

param : type data_decl_body_simple
      ; 

params : param
       | params ','  param 
       ;     
     
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 