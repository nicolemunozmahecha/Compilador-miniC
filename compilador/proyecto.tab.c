/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "proyecto.y"

#include <stdio.h>
#include "listaSimbolos.h"
#include "listaCodigo.h"
Lista tablaSimb;
extern int yylex();
extern char* yytext;
void yyerror();
extern int yylineno;
int contadorCadenas = 0;
int errSemanticos = 0;
int errSintacticos = 0;
extern int errLexicos;
extern int varError;

#line 87 "proyecto.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "proyecto.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL_CONST = 4,                      /* CONST  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_READ = 9,                       /* READ  */
  YYSYMBOL_PRINT = 10,                     /* PRINT  */
  YYSYMBOL_LPAREN = 11,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 12,                    /* RPAREN  */
  YYSYMBOL_PUNTOCOMA = 13,                 /* PUNTOCOMA  */
  YYSYMBOL_COMA = 14,                      /* COMA  */
  YYSYMBOL_IGUAL = 15,                     /* IGUAL  */
  YYSYMBOL_LCORCHETE = 16,                 /* LCORCHETE  */
  YYSYMBOL_RCORCHETE = 17,                 /* RCORCHETE  */
  YYSYMBOL_INTERR = 18,                    /* INTERR  */
  YYSYMBOL_DOSP = 19,                      /* DOSP  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_ID = 21,                        /* ID  */
  YYSYMBOL_STRING = 22,                    /* STRING  */
  YYSYMBOL_NUM = 23,                       /* NUM  */
  YYSYMBOL_MAYOR = 24,                     /* MAYOR  */
  YYSYMBOL_MENOR = 25,                     /* MENOR  */
  YYSYMBOL_MAYORIGUAL = 26,                /* MAYORIGUAL  */
  YYSYMBOL_MENORIGUAL = 27,                /* MENORIGUAL  */
  YYSYMBOL_IGUALIGUAL = 28,                /* IGUALIGUAL  */
  YYSYMBOL_DISTINTO = 29,                  /* DISTINTO  */
  YYSYMBOL_SUMA = 30,                      /* SUMA  */
  YYSYMBOL_MENOS = 31,                     /* MENOS  */
  YYSYMBOL_MULT = 32,                      /* MULT  */
  YYSYMBOL_DIV = 33,                       /* DIV  */
  YYSYMBOL_UMENOS = 34,                    /* UMENOS  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_37_1 = 37,                      /* $@1  */
  YYSYMBOL_declaration = 38,               /* declaration  */
  YYSYMBOL_tipo = 39,                      /* tipo  */
  YYSYMBOL_var_list = 40,                  /* var_list  */
  YYSYMBOL_const_list = 41,                /* const_list  */
  YYSYMBOL_statement_list = 42,            /* statement_list  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_print_list = 44,                /* print_list  */
  YYSYMBOL_print_item = 45,                /* print_item  */
  YYSYMBOL_read_list = 46,                 /* read_list  */
  YYSYMBOL_expression = 47                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   227

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    36,    36,    36,    42,    43,    44,    46,    48,    50,
      53,    57,    62,    63,    65,    71,    72,    73,    74,    75,
      76,    77,    79,    80,    82,    83,    85,    90,    97,    98,
      99,   100,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   114
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "CONST", "INT",
  "IF", "ELSE", "WHILE", "READ", "PRINT", "LPAREN", "RPAREN", "PUNTOCOMA",
  "COMA", "IGUAL", "LCORCHETE", "RCORCHETE", "INTERR", "DOSP", "DO", "ID",
  "STRING", "NUM", "MAYOR", "MENOR", "MAYORIGUAL", "MENORIGUAL",
  "IGUALIGUAL", "DISTINTO", "SUMA", "MENOS", "MULT", "DIV", "UMENOS",
  "$accept", "program", "$@1", "declaration", "tipo", "var_list",
  "const_list", "statement_list", "statement", "print_list", "print_item",
  "read_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -58,     2,   -13,   -58,     0,    39,    29,   -58,    26,    48,
      48,   138,   -58,    34,    46,    43,    57,    58,    59,   -58,
     -58,    55,    60,   -58,   -58,    18,    62,    33,   122,   122,
      51,   119,   154,   -58,   122,   -58,   110,   122,   -58,   111,
     122,   -58,   -58,   122,    32,    54,   -58,    -7,   -58,    14,
     -58,    75,   -58,   170,    96,   -58,    75,   120,    -8,   -58,
     186,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   186,   121,   115,   124,   119,   130,   -58,   122,   -58,
     122,   132,   194,   194,   194,   194,   194,   194,    16,    16,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   140,    75,   184,
     186,   122,   122,   -58,    64,    86,   136,   -58,   -58
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     6,    13,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     0,    13,
       3,     0,     0,    12,     8,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     4,     0,     0,     5,     0,
       0,    41,    42,     0,     0,     0,    26,     0,    25,     0,
      22,    24,    15,     0,     0,     9,    10,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    40,
       0,    17,    32,    33,    34,    35,    36,    37,    28,    29,
      30,    31,    18,    20,    27,    19,    23,     0,    11,     0,
       0,     0,     0,    16,     0,     0,     0,    38,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   -58,   -58,   142,   -58,   -58,    -6,   -57,   -58,
      81,   -58,   -28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     8,    13,    25,    27,    11,    23,    49,
      50,    47,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    45,     3,    81,    79,    72,    54,    73,     4,    56,
      80,     5,    58,    32,    92,    59,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    74,    53,    75,     9,
      10,    35,    36,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   103,    60,     7,    38,    39,    69,    70,
      98,     6,    99,    12,    28,    24,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    26,    29,    30,
      31,    33,    46,   104,   105,    34,   106,    37,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,   107,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    77,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      40,    55,    57,    40,    93,    78,    94,    95,    97,   100,
      41,    48,    42,    41,    15,    42,    16,    17,    18,   108,
      43,   101,    14,    43,    19,    20,    96,     0,    21,    22,
      15,     0,    16,    17,    18,     0,     0,     0,     0,     0,
      19,    52,     0,     0,    21,    22,    15,     0,    16,    17,
      18,     0,     0,     0,     0,     0,    19,    76,     0,     0,
      21,    22,    15,     0,    16,    17,    18,     0,     0,     0,
       0,     0,    19,   102,     0,     0,    21,    22,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70
};

static const yytype_int8 yycheck[] =
{
      28,    29,     0,    60,    12,    12,    34,    14,    21,    37,
      18,    11,    40,    19,    71,    43,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    12,    33,    14,     3,
       4,    13,    14,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,   100,    12,    16,    13,    14,    32,    33,
      78,    12,    80,     5,    11,    21,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    12,    21,    11,    11,
      11,    16,    21,   101,   102,    15,    12,    15,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    12,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    13,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      11,    21,    21,    11,    13,    15,    21,    13,     8,     7,
      21,    22,    23,    21,     6,    23,     8,     9,    10,    13,
      31,    11,    10,    31,    16,    17,    75,    -1,    20,    21,
       6,    -1,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    20,    21,     6,    -1,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,
      20,    21,     6,    -1,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    16,    19,    -1,    -1,    20,    21,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,     0,    21,    11,    12,    16,    38,     3,
       4,    42,     5,    39,    39,     6,     8,     9,    10,    16,
      17,    20,    21,    43,    21,    40,    21,    41,    11,    11,
      11,    11,    42,    16,    15,    13,    14,    15,    13,    14,
      11,    21,    23,    31,    47,    47,    21,    46,    22,    44,
      45,    47,    17,    42,    47,    21,    47,    21,    47,    47,
      12,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    12,    12,    14,    12,    14,    17,    13,    15,    12,
      18,    43,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    43,    13,    21,    13,    45,     8,    47,    47,
       7,    11,    19,    43,    47,    47,    12,    12,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    37,    36,    38,    38,    38,    39,    40,    40,
      41,    41,    42,    42,    43,    43,    43,    43,    43,    43,
      43,    43,    44,    44,    45,    45,    46,    46,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     5,     5,     0,     1,     1,     3,
       3,     5,     2,     0,     4,     3,     7,     5,     5,     5,
       5,     9,     1,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     7,     2,
       3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* $@1: %empty  */
#line 36 "proyecto.y"
                        {tablaSimb = creaLS(); }
#line 1204 "proyecto.tab.c"
    break;

  case 3: /* program: $@1 ID LPAREN RPAREN LCORCHETE declaration statement_list RCORCHETE  */
#line 38 "proyecto.y"
                        {if(varError == 1){printf("\n\nErrores lexicos: %d\nErrores sintacticos: %d\nErrores semanticos: %d\n", errLexicos, errSintacticos, errSemanticos);
			}else{imprimeTabla(tablaSimb); imprimeLista((yyvsp[-2].codigo), (yyvsp[-1].codigo)); liberaLC((yyvsp[-2].codigo)); liberaLC((yyvsp[-1].codigo));} liberaLS(tablaSimb); }
#line 1211 "proyecto.tab.c"
    break;

  case 4: /* declaration: declaration VAR tipo var_list PUNTOCOMA  */
#line 42 "proyecto.y"
                                                                                {(yyval.codigo) = (yyvsp[-4].codigo);}
#line 1217 "proyecto.tab.c"
    break;

  case 5: /* declaration: declaration CONST tipo const_list PUNTOCOMA  */
#line 43 "proyecto.y"
                                                                                {concatenaLC((yyvsp[-4].codigo), (yyvsp[-1].codigo)); liberaLC((yyvsp[-1].codigo)); (yyval.codigo) = (yyvsp[-4].codigo);}
#line 1223 "proyecto.tab.c"
    break;

  case 6: /* declaration: %empty  */
#line 44 "proyecto.y"
                        {(yyval.codigo) = creaLC();}
#line 1229 "proyecto.tab.c"
    break;

  case 8: /* var_list: ID  */
#line 48 "proyecto.y"
                                                {if (!pertenece((yyvsp[0].lexema1), tablaSimb)){insertaTabla((yyvsp[0].lexema1), tablaSimb, VARIABLE);  }
						else{printf("\nError en linea %d: variable %s ya declarada", yylineno, (yyvsp[0].lexema1)); varError = 1; errSemanticos++;};}
#line 1236 "proyecto.tab.c"
    break;

  case 9: /* var_list: var_list COMA ID  */
#line 50 "proyecto.y"
                                                {if (!pertenece((yyvsp[0].lexema1), tablaSimb)){insertaTabla((yyvsp[0].lexema1), tablaSimb, VARIABLE); }
						else{printf("\nError en linea %d: variable %s ya declarada", yylineno, (yyvsp[0].lexema1)); varError = 1; errSemanticos++;};}
#line 1243 "proyecto.tab.c"
    break;

  case 10: /* const_list: ID IGUAL expression  */
#line 53 "proyecto.y"
                                                                {if(!pertenece((yyvsp[-2].lexema1), tablaSimb)){insertaTabla((yyvsp[-2].lexema1), tablaSimb, CONSTANTE);
								(yyval.codigo) = asignacion((yyvsp[0].codigo), (yyvsp[-2].lexema1)); liberaLC((yyvsp[0].codigo));}
								else{printf("\nError en linea %d: variable %s ya declarada", yylineno, (yyvsp[-2].lexema1)); (yyval.codigo) = creaLC();
								varError = 1; errSemanticos++;};}
#line 1252 "proyecto.tab.c"
    break;

  case 11: /* const_list: const_list COMA ID IGUAL expression  */
#line 57 "proyecto.y"
                                                                {if(!pertenece((yyvsp[-2].lexema1), tablaSimb)){insertaTabla((yyvsp[-2].lexema1), tablaSimb, CONSTANTE);
								(yyval.codigo) = asignaConstList((yyvsp[-4].codigo), (yyvsp[-2].lexema1), (yyvsp[0].codigo)); liberaLC((yyvsp[-4].codigo));}
								else{printf("\nError en linea %d: variable %s ya declarada", yylineno, (yyvsp[-2].lexema1)); (yyval.codigo) = creaLC();
								varError = 1; errSemanticos++;};}
#line 1261 "proyecto.tab.c"
    break;

  case 12: /* statement_list: statement_list statement  */
#line 62 "proyecto.y"
                                                        {(yyval.codigo) = concatenar((yyvsp[-1].codigo), (yyvsp[0].codigo)); liberaLC((yyvsp[0].codigo)); liberaLC((yyvsp[-1].codigo)); }
#line 1267 "proyecto.tab.c"
    break;

  case 13: /* statement_list: %empty  */
#line 63 "proyecto.y"
                        {(yyval.codigo) = creaLC((yyval.codigo));}
#line 1273 "proyecto.tab.c"
    break;

  case 14: /* statement: ID IGUAL expression PUNTOCOMA  */
#line 65 "proyecto.y"
                                                        {if (!pertenece((yyvsp[-3].lexema1), tablaSimb)){printf("\nError en linea %d: variable %s no declarada", yylineno, (yyvsp[-3].lexema1)); 
							(yyval.codigo) = creaLC();varError = 1; errSemanticos++;}
							else{if (!compruebaTipo((yyvsp[-3].lexema1), tablaSimb)){printf("\nError en linea %d: variable %s es constante", yylineno, (yyvsp[-3].lexema1)); 
							(yyval.codigo) = creaLC();varError = 1; errSemanticos++;}
							else{(yyval.codigo) = asignacion((yyvsp[-1].codigo), (yyvsp[-3].lexema1)); liberaLC((yyvsp[-1].codigo)); }}}
#line 1283 "proyecto.tab.c"
    break;

  case 15: /* statement: LCORCHETE statement_list RCORCHETE  */
#line 71 "proyecto.y"
                                                                                                        {(yyval.codigo) = asignaIgual((yyvsp[-1].codigo)); liberaLC((yyvsp[-1].codigo)); }
#line 1289 "proyecto.tab.c"
    break;

  case 16: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 72 "proyecto.y"
                                                                                                        {(yyval.codigo) = asignaIfElse((yyvsp[-4].codigo), (yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1295 "proyecto.tab.c"
    break;

  case 17: /* statement: IF LPAREN expression RPAREN statement  */
#line 73 "proyecto.y"
                                                                                                        {(yyval.codigo) = asignaIf((yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1301 "proyecto.tab.c"
    break;

  case 18: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 74 "proyecto.y"
                                                                                                        {(yyval.codigo) = asignaWhile((yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1307 "proyecto.tab.c"
    break;

  case 19: /* statement: PRINT LPAREN print_list RPAREN PUNTOCOMA  */
#line 75 "proyecto.y"
                                                                                                        {(yyval.codigo) = asignaIgual((yyvsp[-2].codigo)); liberaLC((yyvsp[-2].codigo));}
#line 1313 "proyecto.tab.c"
    break;

  case 20: /* statement: READ LPAREN read_list RPAREN PUNTOCOMA  */
#line 76 "proyecto.y"
                                                                                                        {(yyval.codigo) = asignaIgual((yyvsp[-2].codigo)); liberaLC((yyvsp[-2].codigo)); }
#line 1319 "proyecto.tab.c"
    break;

  case 21: /* statement: DO LCORCHETE statement_list RCORCHETE WHILE LPAREN expression RPAREN PUNTOCOMA  */
#line 77 "proyecto.y"
                                                                                                                {(yyval.codigo) = asignaDoWhile((yyvsp[-6].codigo), (yyvsp[-2].codigo));}
#line 1325 "proyecto.tab.c"
    break;

  case 22: /* print_list: print_item  */
#line 79 "proyecto.y"
                                                        {(yyval.codigo) = asignaIgual((yyvsp[0].codigo)); liberaLC((yyvsp[0].codigo)); }
#line 1331 "proyecto.tab.c"
    break;

  case 23: /* print_list: print_list COMA print_item  */
#line 80 "proyecto.y"
                                                        {(yyval.codigo) = concatenar((yyvsp[-2].codigo), (yyvsp[0].codigo)); liberaLC((yyvsp[-2].codigo)); liberaLC((yyvsp[0].codigo));}
#line 1337 "proyecto.tab.c"
    break;

  case 24: /* print_item: expression  */
#line 82 "proyecto.y"
                                                        {(yyval.codigo) = asignaPrint2((yyvsp[0].codigo)); liberaLC((yyvsp[0].codigo)); }
#line 1343 "proyecto.tab.c"
    break;

  case 25: /* print_item: STRING  */
#line 83 "proyecto.y"
                                                        {insertaTabla((yyvsp[0].lexema1), tablaSimb, CADENA); contadorCadenas++; (yyval.codigo) = asignaPrint();}
#line 1349 "proyecto.tab.c"
    break;

  case 26: /* read_list: ID  */
#line 85 "proyecto.y"
                                                        {if (!pertenece((yyvsp[0].lexema1), tablaSimb)){printf("\nError en linea %d: variable %s no declarada", yylineno, (yyvsp[0].lexema1));
							 (yyval.codigo) = creaLC();varError = 1; errSemanticos++;}
							else{if (!compruebaTipo((yyvsp[0].lexema1), tablaSimb)){printf("\nError en linea %d: variable %s es constante", yylineno, (yyvsp[0].lexema1)); 
							(yyval.codigo) = creaLC();varError = 1; errSemanticos++;}
							else{(yyval.codigo) = asignaRead((yyvsp[0].lexema1)); }}}
#line 1359 "proyecto.tab.c"
    break;

  case 27: /* read_list: read_list COMA ID  */
#line 90 "proyecto.y"
                                                        {if (!pertenece((yyvsp[0].lexema1), tablaSimb)){printf("\nError en linea %d: variable %s no declarada", yylineno, (yyvsp[0].lexema1));
							varError = 1; errSemanticos++;}
							else{if (!compruebaTipo((yyvsp[0].lexema1), tablaSimb)){printf("\nError en linea %d: variable %s es constante", yylineno, (yyvsp[0].lexema1)); 
							(yyval.codigo) = creaLC();varError = 1; errSemanticos++;}
							else{(yyval.codigo) = asignaRead2((yyvsp[-2].codigo), (yyvsp[0].lexema1)); liberaLC((yyvsp[-2].codigo)); }}}
#line 1369 "proyecto.tab.c"
    break;

  case 28: /* expression: expression SUMA expression  */
#line 97 "proyecto.y"
                                                                {(yyval.codigo) = asignacionAritmetica((yyvsp[-2].codigo), (yyvsp[0].codigo), "\tadd"); liberaLC((yyvsp[-2].codigo)); liberaLC((yyvsp[0].codigo));}
#line 1375 "proyecto.tab.c"
    break;

  case 29: /* expression: expression MENOS expression  */
#line 98 "proyecto.y"
                                                                {(yyval.codigo) = asignacionAritmetica((yyvsp[-2].codigo), (yyvsp[0].codigo), "\tsub"); liberaLC((yyvsp[-2].codigo)); liberaLC((yyvsp[0].codigo));}
#line 1381 "proyecto.tab.c"
    break;

  case 30: /* expression: expression MULT expression  */
#line 99 "proyecto.y"
                                                                {(yyval.codigo) = asignacionAritmetica((yyvsp[-2].codigo), (yyvsp[0].codigo), "\tmul"); liberaLC((yyvsp[-2].codigo)); liberaLC((yyvsp[0].codigo));}
#line 1387 "proyecto.tab.c"
    break;

  case 31: /* expression: expression DIV expression  */
#line 100 "proyecto.y"
                                                                {(yyval.codigo) = asignacionAritmetica((yyvsp[-2].codigo), (yyvsp[0].codigo), "\tdiv"); liberaLC((yyvsp[-2].codigo)); liberaLC((yyvsp[0].codigo));}
#line 1393 "proyecto.tab.c"
    break;

  case 32: /* expression: expression MAYOR expression  */
#line 102 "proyecto.y"
                                                                {(yyval.codigo) = asignacionAritmetica((yyvsp[0].codigo), (yyvsp[-2].codigo), "\tslt"); liberaLC((yyvsp[-2].codigo)); liberaLC((yyvsp[0].codigo));}
#line 1399 "proyecto.tab.c"
    break;

  case 33: /* expression: expression MENOR expression  */
#line 103 "proyecto.y"
                                                                {(yyval.codigo) = asignacionAritmetica((yyvsp[-2].codigo), (yyvsp[0].codigo), "\tslt"); liberaLC((yyvsp[-2].codigo)); liberaLC((yyvsp[0].codigo));}
#line 1405 "proyecto.tab.c"
    break;

  case 34: /* expression: expression MAYORIGUAL expression  */
#line 104 "proyecto.y"
                                                                {(yyval.codigo) = asignacionMayorIgual((yyvsp[0].codigo), (yyvsp[-2].codigo)); }
#line 1411 "proyecto.tab.c"
    break;

  case 35: /* expression: expression MENORIGUAL expression  */
#line 105 "proyecto.y"
                                                                {(yyval.codigo) = asignacionMayorIgual((yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1417 "proyecto.tab.c"
    break;

  case 36: /* expression: expression IGUALIGUAL expression  */
#line 106 "proyecto.y"
                                                                {(yyval.codigo) = asignacionIgualIgual((yyvsp[-2].codigo), (yyvsp[0].codigo)); }
#line 1423 "proyecto.tab.c"
    break;

  case 37: /* expression: expression DISTINTO expression  */
#line 107 "proyecto.y"
                                                                {(yyval.codigo) = asignacionAritmetica((yyvsp[-2].codigo), (yyvsp[0].codigo), "\txor"); liberaLC((yyvsp[-2].codigo)); liberaLC((yyvsp[0].codigo));}
#line 1429 "proyecto.tab.c"
    break;

  case 38: /* expression: LPAREN expression INTERR expression DOSP expression RPAREN  */
#line 108 "proyecto.y"
                                                                                        {(yyval.codigo) = asignacionInterr((yyvsp[-5].codigo), (yyvsp[-3].codigo), (yyvsp[-1].codigo));}
#line 1435 "proyecto.tab.c"
    break;

  case 39: /* expression: MENOS expression  */
#line 109 "proyecto.y"
                                                                {(yyval.codigo) = asignaNeg((yyvsp[0].codigo)); liberaLC((yyvsp[0].codigo));}
#line 1441 "proyecto.tab.c"
    break;

  case 40: /* expression: LPAREN expression RPAREN  */
#line 110 "proyecto.y"
                                                                {(yyval.codigo) = (yyvsp[-1].codigo);}
#line 1447 "proyecto.tab.c"
    break;

  case 41: /* expression: ID  */
#line 111 "proyecto.y"
                                                                {if (!pertenece((yyvsp[0].lexema1), tablaSimb)){printf("\nError en linea %d: variable %s no declarada", yylineno, (yyvsp[0].lexema1)); 
								(yyval.codigo) = creaLC();varError = 1; errSemanticos++;}
								else{(yyval.codigo) = asignaId((yyvsp[0].lexema1), "\tlw");}}
#line 1455 "proyecto.tab.c"
    break;

  case 42: /* expression: NUM  */
#line 114 "proyecto.y"
                                                                {(yyval.codigo) = asignaNum((yyvsp[0].lexema1), "\tli");}
#line 1461 "proyecto.tab.c"
    break;


#line 1465 "proyecto.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 117 "proyecto.y"




void yyerror()
{
	if(errLexicos >= 1 ){
		//varError = 1;
		printf("\nErrores léxicos: %d\nErrores sintacticos: %d\nErrores semanticos: %d\n", errLexicos, errSintacticos, errSemanticos);
	}
	else{	printf("\nError sintactico en linea: %d, variable %s\n", yylineno, yytext);
		errSintacticos++;
		printf("\nErrores léxicos: %d\nErrores sintacticos: %d\nErrores semanticos: %d\n", errLexicos, errSintacticos, errSemanticos);
	}

}


