/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PROYECTO_TAB_H_INCLUDED
# define YY_YY_PROYECTO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "proyecto.y"

	#include "listaCodigo.h"

#line 53 "proyecto.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VAR = 258,                     /* VAR  */
    CONST = 259,                   /* CONST  */
    INT = 260,                     /* INT  */
    IF = 261,                      /* IF  */
    ELSE = 262,                    /* ELSE  */
    WHILE = 263,                   /* WHILE  */
    READ = 264,                    /* READ  */
    PRINT = 265,                   /* PRINT  */
    LPAREN = 266,                  /* LPAREN  */
    RPAREN = 267,                  /* RPAREN  */
    PUNTOCOMA = 268,               /* PUNTOCOMA  */
    COMA = 269,                    /* COMA  */
    IGUAL = 270,                   /* IGUAL  */
    LCORCHETE = 271,               /* LCORCHETE  */
    RCORCHETE = 272,               /* RCORCHETE  */
    INTERR = 273,                  /* INTERR  */
    DOSP = 274,                    /* DOSP  */
    DO = 275,                      /* DO  */
    ID = 276,                      /* ID  */
    STRING = 277,                  /* STRING  */
    NUM = 278,                     /* NUM  */
    MAYOR = 279,                   /* MAYOR  */
    MENOR = 280,                   /* MENOR  */
    MAYORIGUAL = 281,              /* MAYORIGUAL  */
    MENORIGUAL = 282,              /* MENORIGUAL  */
    IGUALIGUAL = 283,              /* IGUALIGUAL  */
    DISTINTO = 284,                /* DISTINTO  */
    SUMA = 285,                    /* SUMA  */
    MENOS = 286,                   /* MENOS  */
    MULT = 287,                    /* MULT  */
    DIV = 288,                     /* DIV  */
    UMENOS = 289                   /* UMENOS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "proyecto.y"
 
char* lexema1;
ListaC codigo;	

#line 109 "proyecto.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PROYECTO_TAB_H_INCLUDED  */
