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
    COMMA = 258,
    SEMICOLON = 259,
    LPAR = 260,
    RPAR = 261,
    LBRACE = 262,
    RBRACE = 263,
    LBRACKET = 264,
    RBRACKET = 265,
    DOT = 266,
    NEWLINE = 267,
    LETTER = 268,
    NUMBER = 269,
    STRING = 270,
    DEFINE = 271,
    BREAK = 272,
    QUIT = 273,
    LENGTH = 274,
    RETURN = 275,
    FOR = 276,
    IF = 277,
    WHILE = 278,
    SQRT = 279,
    SCALE = 280,
    IBASE = 281,
    OBASE = 282,
    AUTO = 283,
    CONTINUE = 284,
    ELSE = 285,
    PRINT = 286,
    BOOL_OR = 287,
    BOOL_AND = 288,
    BOOL_NOT = 289,
    EQUALS = 290,
    LESS_EQ = 291,
    GREATER_EQ = 292,
    UNEQUALS = 293,
    LESS = 294,
    GREATER = 295,
    ASSIGN_OP = 296,
    PLUS = 297,
    MINUS = 298,
    MULTIPLY = 299,
    DIVIDE = 300,
    REMAINDER = 301,
    EXPONENT = 302,
    UMINUS = 303,
    INCR = 304,
    DECR = 305
  };
#endif
/* Tokens.  */
#define COMMA 258
#define SEMICOLON 259
#define LPAR 260
#define RPAR 261
#define LBRACE 262
#define RBRACE 263
#define LBRACKET 264
#define RBRACKET 265
#define DOT 266
#define NEWLINE 267
#define LETTER 268
#define NUMBER 269
#define STRING 270
#define DEFINE 271
#define BREAK 272
#define QUIT 273
#define LENGTH 274
#define RETURN 275
#define FOR 276
#define IF 277
#define WHILE 278
#define SQRT 279
#define SCALE 280
#define IBASE 281
#define OBASE 282
#define AUTO 283
#define CONTINUE 284
#define ELSE 285
#define PRINT 286
#define BOOL_OR 287
#define BOOL_AND 288
#define BOOL_NOT 289
#define EQUALS 290
#define LESS_EQ 291
#define GREATER_EQ 292
#define UNEQUALS 293
#define LESS 294
#define GREATER 295
#define ASSIGN_OP 296
#define PLUS 297
#define MINUS 298
#define MULTIPLY 299
#define DIVIDE 300
#define REMAINDER 301
#define EXPONENT 302
#define UMINUS 303
#define INCR 304
#define DECR 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 124 "bc.y" /* yacc.c:1909  */

	ssize_t		node;
	struct lvalue	lvalue;
	const char	*str;
	char		*astr;

#line 161 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
