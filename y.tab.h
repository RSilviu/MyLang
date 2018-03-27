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
extern YYSTYPE yylval;
