/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IDENTIFIER = 258,
    CONSTANT = 259,
    CHAR_CONSTANT = 260,
    INT_CONSTANT = 261,
    FLOAT_CONSTANT = 262,
    STRING_LITERAL = 263,
    SIZEOF = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    H = 271,
    AND_OP = 272,
    OR_OP = 273,
    MUL_ASSIGN = 274,
    DIV_ASSIGN = 275,
    MOD_ASSIGN = 276,
    ADD_ASSIGN = 277,
    SUB_ASSIGN = 278,
    CHAR = 279,
    SHORT = 280,
    INT = 281,
    LONG = 282,
    FLOAT = 283,
    DOUBLE = 284,
    VOID = 285,
    IF = 286,
    ELSE = 287,
    WHILE = 288,
    DO = 289,
    CONTINUE = 290,
    BREAK = 291,
    RETURN = 292,
    HASH = 293,
    INCLUDE = 294,
    LIBRARY = 295
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define CHAR_CONSTANT 260
#define INT_CONSTANT 261
#define FLOAT_CONSTANT 262
#define STRING_LITERAL 263
#define SIZEOF 264
#define INC_OP 265
#define DEC_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define H 271
#define AND_OP 272
#define OR_OP 273
#define MUL_ASSIGN 274
#define DIV_ASSIGN 275
#define MOD_ASSIGN 276
#define ADD_ASSIGN 277
#define SUB_ASSIGN 278
#define CHAR 279
#define SHORT 280
#define INT 281
#define LONG 282
#define FLOAT 283
#define DOUBLE 284
#define VOID 285
#define IF 286
#define ELSE 287
#define WHILE 288
#define DO 289
#define CONTINUE 290
#define BREAK 291
#define RETURN 292
#define HASH 293
#define INCLUDE 294
#define LIBRARY 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 125 "icg.y" /* yacc.c:1909  */

	int ival;
	char string[128];

#line 139 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
