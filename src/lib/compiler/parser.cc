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
#line 2 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"

#include <compiler/ParseTree.h>
#include "remap.h"
#include "parser_extra.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
    
using std::malloc;
using std::free;
using jags::ParseTree;

  void yyerror(const char *);
  int yylex();
  int yylex_destroy();
  extern int yylineno;
  
#define YYDEBUG 1
  
  static std::vector<ParseTree *> * _pvariables = nullptr;
  static ParseTree *_pdata = nullptr;
  static ParseTree *_prelations = nullptr;
  
  static void setName(ParseTree *p, std::string *name);
  static void setParameters(ParseTree *p, std::vector<ParseTree*> *parameters);
  static void setParameters(ParseTree *p, ParseTree *param1);
  static void setParameters(ParseTree *p, ParseTree *param1, 
			    ParseTree *param2);
  static void setParameters(ParseTree *p, ParseTree *param1, ParseTree *param2,
			    ParseTree *param3);
  static ParseTree *Truncated (std::vector<ParseTree *> *bounds);
  static ParseTree *Interval(std::vector<ParseTree *> *bounds);
  

#line 110 "parser.cc"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HH_INCLUDED
# define YY_YY_PARSER_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

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
    DATA = 259,                    /* DATA  */
    MODEL = 260,                   /* MODEL  */
    NAME = 261,                    /* NAME  */
    SPECIAL = 262,                 /* SPECIAL  */
    BADCHAR = 263,                 /* BADCHAR  */
    IN = 264,                      /* IN  */
    ARROW = 265,                   /* ARROW  */
    FOR = 266,                     /* FOR  */
    GT = 267,                      /* GT  */
    GE = 268,                      /* GE  */
    LT = 269,                      /* LT  */
    LE = 270,                      /* LE  */
    EQ = 271,                      /* EQ  */
    NE = 272,                      /* NE  */
    AND = 273,                     /* AND  */
    OR = 274,                      /* OR  */
    LENGTH = 275,                  /* LENGTH  */
    DIM = 276,                     /* DIM  */
    PIPE = 277,                    /* PIPE  */
    DOUBLE = 278,                  /* DOUBLE  */
    INT = 279,                     /* INT  */
    NOT = 280,                     /* NOT  */
    NEG = 281                      /* NEG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VAR 258
#define DATA 259
#define MODEL 260
#define NAME 261
#define SPECIAL 262
#define BADCHAR 263
#define IN 264
#define ARROW 265
#define FOR 266
#define GT 267
#define GE 268
#define LT 269
#define LE 270
#define EQ 271
#define NE 272
#define AND 273
#define OR 274
#define LENGTH 275
#define DIM 276
#define PIPE 277
#define DOUBLE 278
#define INT 279
#define NOT 280
#define NEG 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"

  /*
    We can't put any C++ class that requires a constructor in
    union. In particular, we can't have strings.  To get round this
    limitation, we put a pointer to a string in the union, and then
    get the lexical analyzer to return a pointer to a dynamically
    allocated string.  The parser frees the memory when it is done.
    This is tedious, but the alternative is to copy character
    arrays using, e.g. strncpy instead.
  */
  double val;
  std::string *stringptr;
  jags::ParseTree *ptree;
  std::vector<jags::ParseTree*> *pvec;

#line 231 "parser.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HH_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL_DATA = 4,                       /* DATA  */
  YYSYMBOL_MODEL = 5,                      /* MODEL  */
  YYSYMBOL_NAME = 6,                       /* NAME  */
  YYSYMBOL_SPECIAL = 7,                    /* SPECIAL  */
  YYSYMBOL_BADCHAR = 8,                    /* BADCHAR  */
  YYSYMBOL_IN = 9,                         /* IN  */
  YYSYMBOL_ARROW = 10,                     /* ARROW  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_GT = 12,                        /* GT  */
  YYSYMBOL_GE = 13,                        /* GE  */
  YYSYMBOL_LT = 14,                        /* LT  */
  YYSYMBOL_LE = 15,                        /* LE  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_NE = 17,                        /* NE  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_LENGTH = 20,                    /* LENGTH  */
  YYSYMBOL_DIM = 21,                       /* DIM  */
  YYSYMBOL_PIPE = 22,                      /* PIPE  */
  YYSYMBOL_DOUBLE = 23,                    /* DOUBLE  */
  YYSYMBOL_INT = 24,                       /* INT  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_26_ = 26,                       /* '+'  */
  YYSYMBOL_27_ = 27,                       /* '-'  */
  YYSYMBOL_28_ = 28,                       /* '*'  */
  YYSYMBOL_29_ = 29,                       /* '/'  */
  YYSYMBOL_30_ = 30,                       /* ':'  */
  YYSYMBOL_NEG = 31,                       /* NEG  */
  YYSYMBOL_32_ = 32,                       /* '^'  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* '['  */
  YYSYMBOL_36_ = 36,                       /* ']'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '='  */
  YYSYMBOL_42_ = 42,                       /* '~'  */
  YYSYMBOL_43_T_ = 43,                     /* 'T'  */
  YYSYMBOL_44_I_ = 44,                     /* 'I'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_input = 46,                     /* input  */
  YYSYMBOL_var_stmt = 47,                  /* var_stmt  */
  YYSYMBOL_dec_list = 48,                  /* dec_list  */
  YYSYMBOL_node_dec = 49,                  /* node_dec  */
  YYSYMBOL_data_stmt = 50,                 /* data_stmt  */
  YYSYMBOL_model_stmt = 51,                /* model_stmt  */
  YYSYMBOL_relations = 52,                 /* relations  */
  YYSYMBOL_relation_list = 53,             /* relation_list  */
  YYSYMBOL_relation = 54,                  /* relation  */
  YYSYMBOL_for_loop = 55,                  /* for_loop  */
  YYSYMBOL_counter = 56,                   /* counter  */
  YYSYMBOL_assignment = 57,                /* assignment  */
  YYSYMBOL_determ_relation = 58,           /* determ_relation  */
  YYSYMBOL_stoch_relation = 59,            /* stoch_relation  */
  YYSYMBOL_product = 60,                   /* product  */
  YYSYMBOL_sum = 61,                       /* sum  */
  YYSYMBOL_expression = 62,                /* expression  */
  YYSYMBOL_arg_list = 63,                  /* arg_list  */
  YYSYMBOL_arg = 64,                       /* arg  */
  YYSYMBOL_distribution = 65,              /* distribution  */
  YYSYMBOL_truncated = 66,                 /* truncated  */
  YYSYMBOL_interval = 67,                  /* interval  */
  YYSYMBOL_var = 68                        /* var  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   244

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


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
      39,    40,    28,    26,    34,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    30,    33,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    43,     2,     2,     2,     2,     2,
       2,    35,     2,    36,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,    42,     2,     2,     2,
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
      25,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,    99,   100,   101,   102,   105,   106,   109,
     110,   113,   116,   122,   129,   136,   142,   143,   146,   147,
     148,   149,   150,   153,   159,   165,   166,   169,   173,   189,
     193,   197,   201,   205,   209,   213,   219,   224,   234,   239,
     248,   249,   250,   254,   258,   262,   266,   270,   274,   278,
     282,   286,   290,   294,   298,   302,   306,   310,   314,   318,
     322,   326,   329,   336,   339,   344,   351,   353,   355,   358
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
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "DATA", "MODEL",
  "NAME", "SPECIAL", "BADCHAR", "IN", "ARROW", "FOR", "GT", "GE", "LT",
  "LE", "EQ", "NE", "AND", "OR", "LENGTH", "DIM", "PIPE", "DOUBLE", "INT",
  "NOT", "'+'", "'-'", "'*'", "'/'", "':'", "NEG", "'^'", "';'", "','",
  "'['", "']'", "'{'", "'}'", "'('", "')'", "'='", "'~'", "'T'", "'I'",
  "$accept", "input", "var_stmt", "dec_list", "node_dec", "data_stmt",
  "model_stmt", "relations", "relation_list", "relation", "for_loop",
  "counter", "assignment", "determ_relation", "stoch_relation", "product",
  "sum", "expression", "arg_list", "arg", "distribution", "truncated",
  "interval", "var", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     128,    11,   -28,    36,    21,    72,    80,   -44,    71,   131,
     -44,    49,    49,   -44,    80,   -44,   -44,    42,   -44,    11,
     -29,    77,    14,   -44,   -44,    83,   102,   112,    12,    52,
     -44,    78,   -44,    42,    42,    42,   133,   137,   140,   100,
     -44,   -44,   -44,    42,   169,   177,   -44,   -44,    49,   -44,
     -44,   -44,   -44,   -44,     6,    42,   -44,    42,   188,   152,
      82,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,   -44,
     108,   150,   146,   178,    64,   149,   158,   159,   -17,   140,
     -21,   -44,    54,    75,   116,   212,   212,   212,   212,   212,
     212,   188,   164,    75,    75,    54,    54,   130,   152,   -44,
     -44,    18,    42,   -44,    42,   183,   183,   106,   160,   167,
     -44,   -44,   -44,    42,   111,   -16,   173,   174,   -44,   -44,
      42,    42,   140,   -44,   -44,    42,    42,    22,    34,    38,
      81,   -44,   -44,   -44,   -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     3,    11,     7,
       9,     0,     0,     1,     0,     4,     5,    63,     8,     0,
      68,     0,     0,    16,    20,     0,    19,    18,     0,     0,
       6,    68,    41,     0,     0,     0,    43,    45,    64,     0,
      61,    40,    10,    63,     0,     0,    13,    17,     0,    23,
      22,    21,    25,    26,     0,     0,    14,    63,    48,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    12,
       0,    68,     0,     0,     0,     0,     0,     0,    29,    27,
       0,    60,    37,    39,    59,    50,    51,    52,    53,    54,
      55,    56,    57,    38,    46,    36,    44,    49,    58,    62,
      69,     0,     0,    15,    63,     0,     0,     0,     0,     0,
      30,    31,    42,     0,     0,     0,     0,     0,    34,    35,
      63,    63,    28,    24,    65,    63,    63,     0,     0,     0,
       0,    66,    67,    32,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   -44,   -44,   -44,   190,   205,     2,   -44,     3,   -18,
     -44,   -44,   101,   -44,   -44,   -44,   -44,   -32,   -43,   135,
      58,    94,   104,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     9,    10,     6,     7,    49,    22,    23,
      24,    25,    55,    26,    27,    36,    37,    38,    39,    40,
      88,   120,   121,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,    58,    59,    60,    47,   117,    43,    15,    16,    11,
      44,    47,    85,    78,    90,    29,    30,     8,    78,   122,
      20,    13,    52,    89,   134,    21,   118,   119,    52,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    28,    28,    31,    86,
      87,    84,    46,    53,    54,    20,    78,    28,    20,    53,
      21,    63,   141,    21,    28,    32,    47,    33,    78,    34,
      20,   125,    78,    12,   142,    21,     2,     3,   143,    82,
     124,    35,    63,    28,    76,     3,    77,   137,   138,    63,
      56,   132,   139,   140,    64,    65,    66,    67,    68,    69,
      70,    71,   113,    74,    75,    76,    17,    77,    72,    73,
      74,    75,    76,    43,    77,    78,    45,    57,    63,    28,
      48,   144,    91,    64,    65,    66,    67,    68,    69,    70,
      71,     1,     2,     3,    78,    50,    79,    72,    73,    74,
      75,    76,    78,    77,   110,    51,    76,    63,    77,   118,
     119,   133,    64,    65,    66,    67,    68,    69,    70,    71,
      -1,    61,    77,    62,    18,    19,    72,    73,    74,    75,
      76,    63,    77,   126,   127,    81,    64,    65,    66,    67,
      68,    69,    70,    83,    77,    43,   111,   112,   114,    85,
      72,    73,    74,    75,    76,    63,    77,   115,   116,   130,
      64,    65,    66,    67,    68,    69,   131,   135,   136,    42,
      14,   128,   123,   109,    72,    73,    74,    75,    76,    63,
      77,   129,     0,     0,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
      74,    75,    76,     0,    77
};

static const yytype_int16 yycheck[] =
{
      43,    33,    34,    35,    22,    22,    35,     5,     6,    37,
      39,    29,     6,    34,    57,    12,    14,     6,    34,    40,
       6,     0,    10,    55,    40,    11,    43,    44,    10,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    11,    12,     6,    43,
      44,    48,    38,    41,    42,     6,    34,    22,     6,    41,
      11,     7,    40,    11,    29,    23,    84,    25,    34,    27,
       6,   114,    34,    37,    40,    11,     4,     5,    40,    44,
     112,    39,     7,    48,    30,     5,    32,   130,   131,     7,
      38,   123,   135,   136,    12,    13,    14,    15,    16,    17,
      18,    19,    38,    28,    29,    30,    35,    32,    26,    27,
      28,    29,    30,    35,    32,    34,    39,    39,     7,    84,
      37,    40,    40,    12,    13,    14,    15,    16,    17,    18,
      19,     3,     4,     5,    34,    33,    36,    26,    27,    28,
      29,    30,    34,    32,    36,    33,    30,     7,    32,    43,
      44,    40,    12,    13,    14,    15,    16,    17,    18,    19,
      30,    28,    32,    26,    33,    34,    26,    27,    28,    29,
      30,     7,    32,   115,   116,     6,    12,    13,    14,    15,
      16,    17,    18,     6,    32,    35,    40,     9,    39,     6,
      26,    27,    28,    29,    30,     7,    32,    39,    39,    39,
      12,    13,    14,    15,    16,    17,    39,    34,    34,    19,
       5,   117,   111,    78,    26,    27,    28,    29,    30,     7,
      32,   117,    -1,    -1,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    46,    47,    50,    51,     6,    48,
      49,    37,    37,     0,    50,    51,    51,    35,    33,    34,
       6,    11,    53,    54,    55,    56,    58,    59,    68,    53,
      51,     6,    23,    25,    27,    39,    60,    61,    62,    63,
      64,    68,    49,    35,    39,    39,    38,    54,    37,    52,
      33,    33,    10,    41,    42,    57,    38,    39,    62,    62,
      62,    28,    26,     7,    12,    13,    14,    15,    16,    17,
      18,    19,    26,    27,    28,    29,    30,    32,    34,    36,
      63,     6,    68,     6,    53,     6,    43,    44,    65,    62,
      63,    40,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    64,
      36,    40,     9,    38,    39,    39,    39,    22,    43,    44,
      66,    67,    40,    57,    62,    63,    65,    65,    66,    67,
      39,    39,    62,    40,    40,    34,    34,    63,    63,    63,
      63,    40,    40,    40,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    46,    46,    46,    47,    47,    48,
      48,    49,    49,    50,    51,    52,    53,    53,    54,    54,
      54,    54,    54,    55,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    65,    66,    67,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     2,     2,     3,     2,     3,     1,
       3,     1,     4,     4,     4,     3,     1,     2,     1,     1,
       1,     2,     2,     2,     6,     1,     1,     3,     6,     3,
       4,     4,     8,     8,     5,     5,     3,     3,     3,     3,
       1,     1,     4,     1,     3,     1,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     0,     1,     4,     4,     4,     1,     4
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
  case 7: /* var_stmt: VAR dec_list  */
#line 105 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                       { _pvariables = (yyvsp[0].pvec); }
#line 1387 "parser.cc"
    break;

  case 8: /* var_stmt: VAR dec_list ';'  */
#line 106 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                   { _pvariables = (yyvsp[-1].pvec); }
#line 1393 "parser.cc"
    break;

  case 9: /* dec_list: node_dec  */
#line 109 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                   { (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[0].ptree)); }
#line 1399 "parser.cc"
    break;

  case 10: /* dec_list: dec_list ',' node_dec  */
#line 110 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                        { (yyval.pvec) = (yyvsp[-2].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree)); }
#line 1405 "parser.cc"
    break;

  case 11: /* node_dec: NAME  */
#line 113 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
               {
    (yyval.ptree) = new ParseTree(jags::P_VAR, yylineno); setName((yyval.ptree), (yyvsp[0].stringptr)); 
}
#line 1413 "parser.cc"
    break;

  case 12: /* node_dec: NAME '[' arg_list ']'  */
#line 116 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                        {
    (yyval.ptree) = new ParseTree(jags::P_VAR, yylineno); setName((yyval.ptree), (yyvsp[-3].stringptr));
    setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 1422 "parser.cc"
    break;

  case 13: /* data_stmt: DATA '{' relation_list '}'  */
#line 122 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                      {
    ParseTree *p = new ParseTree(jags::P_RELATIONS, yylineno);
    setParameters(p, (yyvsp[-1].pvec));
    _pdata = p;
}
#line 1432 "parser.cc"
    break;

  case 14: /* model_stmt: MODEL '{' relation_list '}'  */
#line 129 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                        { 
    ParseTree *p = new ParseTree(jags::P_RELATIONS, yylineno);
    setParameters(p, (yyvsp[-1].pvec));
    _prelations = p;
}
#line 1442 "parser.cc"
    break;

  case 15: /* relations: '{' relation_list '}'  */
#line 136 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                 {
    (yyval.ptree) = new ParseTree(jags::P_RELATIONS, yylineno);
    setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 1451 "parser.cc"
    break;

  case 16: /* relation_list: relation  */
#line 142 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                         { (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[0].ptree)); }
#line 1457 "parser.cc"
    break;

  case 17: /* relation_list: relation_list relation  */
#line 143 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                         { (yyval.pvec)=(yyvsp[-1].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree)); }
#line 1463 "parser.cc"
    break;

  case 23: /* for_loop: counter relations  */
#line 153 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                            {
    (yyval.ptree) = new ParseTree(jags::P_FOR, yylineno);
    setParameters((yyval.ptree), (yyvsp[-1].ptree), (yyvsp[0].ptree));
}
#line 1472 "parser.cc"
    break;

  case 24: /* counter: FOR '(' NAME IN expression ')'  */
#line 159 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                        {
    (yyval.ptree) = new ParseTree(jags::P_COUNTER, yylineno); setName((yyval.ptree), (yyvsp[-3].stringptr));
    setParameters((yyval.ptree), (yyvsp[-1].ptree));
}
#line 1481 "parser.cc"
    break;

  case 27: /* determ_relation: var assignment expression  */
#line 169 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                           {
    (yyval.ptree) = new ParseTree(jags::P_DETRMREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1490 "parser.cc"
    break;

  case 28: /* determ_relation: NAME '(' var ')' assignment expression  */
#line 173 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                         {

  /* 
     The link function is given using an S-style replacement function
     notation.  We need to turn this round so the inverse link
     function is applied to the RHS of the deterministic relation
  */
     
    ParseTree *p = new ParseTree(jags::P_LINK, yylineno); setName(p, (yyvsp[-5].stringptr));
    setParameters(p, (yyvsp[0].ptree));
    
    (yyval.ptree) = new ParseTree(jags::P_DETRMREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[-3].ptree), p);
}
#line 1509 "parser.cc"
    break;

  case 29: /* stoch_relation: var '~' distribution  */
#line 189 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                     {
    (yyval.ptree) = new ParseTree(jags::P_STOCHREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1518 "parser.cc"
    break;

  case 30: /* stoch_relation: var '~' distribution truncated  */
#line 193 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                 {
    (yyval.ptree) = new ParseTree(jags::P_STOCHREL, yylineno); 
    setParameters((yyval.ptree), (yyvsp[-3].ptree), (yyvsp[-1].ptree), (yyvsp[0].ptree));
}
#line 1527 "parser.cc"
    break;

  case 31: /* stoch_relation: var '~' distribution interval  */
#line 197 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                {
    (yyval.ptree) = new ParseTree(jags::P_STOCHREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[-3].ptree), (yyvsp[-1].ptree), (yyvsp[0].ptree));
}
#line 1536 "parser.cc"
    break;

  case 32: /* stoch_relation: var '~' 'T' '(' distribution ',' arg_list ')'  */
#line 201 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                                {
    (yyval.ptree) = new ParseTree(jags::P_STOCHREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[-7].ptree), (yyvsp[-3].ptree), Truncated((yyvsp[-1].pvec)));
}
#line 1545 "parser.cc"
    break;

  case 33: /* stoch_relation: var '~' 'I' '(' distribution ',' arg_list ')'  */
#line 205 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                                {
    (yyval.ptree) = new ParseTree(jags::P_STOCHREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[-7].ptree), (yyvsp[-3].ptree), Interval((yyvsp[-1].pvec)));
}
#line 1554 "parser.cc"
    break;

  case 34: /* stoch_relation: var '~' distribution PIPE truncated  */
#line 209 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                      {
    (yyval.ptree) = new ParseTree(jags::P_STOCHREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[-4].ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1563 "parser.cc"
    break;

  case 35: /* stoch_relation: var '~' distribution PIPE interval  */
#line 213 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                     {
    (yyval.ptree) = new ParseTree(jags::P_STOCHREL, yylineno);
    setParameters((yyval.ptree), (yyvsp[-4].ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1572 "parser.cc"
    break;

  case 36: /* product: expression '*' expression  */
#line 219 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                   {
  (yyval.pvec) = new std::vector<ParseTree*>;
  (yyval.pvec)->push_back((yyvsp[-2].ptree));
  (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 1582 "parser.cc"
    break;

  case 37: /* product: product '*' expression  */
#line 224 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                         {
  //  This creates a shift-reduce conflict because in the expression
  //  A*B*C, (A*B) is a valid expression. By default, bison shifts,
  //  which is what we want. The warning is suppressed with the %expect
  //  declaration (See also sum: below).
  (yyval.pvec) = (yyvsp[-2].pvec);
  (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 1595 "parser.cc"
    break;

  case 38: /* sum: expression '+' expression  */
#line 234 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                               {
  (yyval.pvec) = new std::vector<ParseTree*>;
  (yyval.pvec)->push_back((yyvsp[-2].ptree));
  (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 1605 "parser.cc"
    break;

  case 39: /* sum: sum '+' expression  */
#line 239 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                     {
  //  This creates a shift-reduce conflict. By default, bison shifts,
  //  which is what we want. The warning is suppressed with the %expect
  //  declaration (See also product: above).
  (yyval.pvec) = (yyvsp[-2].pvec);
  (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 1617 "parser.cc"
    break;

  case 41: /* expression: DOUBLE  */
#line 249 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
         {(yyval.ptree) = new ParseTree(jags::P_VALUE, yylineno); (yyval.ptree)->setValue((yyvsp[0].val));}
#line 1623 "parser.cc"
    break;

  case 42: /* expression: NAME '(' arg_list ')'  */
#line 250 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                        {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); setName((yyval.ptree), (yyvsp[-3].stringptr));
    setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 1632 "parser.cc"
    break;

  case 43: /* expression: product  */
#line 254 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
          {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("*");
    setParameters((yyval.ptree), (yyvsp[0].pvec));
}
#line 1641 "parser.cc"
    break;

  case 44: /* expression: expression '/' expression  */
#line 258 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                            {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("/");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1650 "parser.cc"
    break;

  case 45: /* expression: sum  */
#line 262 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
      {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("+");
    setParameters((yyval.ptree), (yyvsp[0].pvec));
}
#line 1659 "parser.cc"
    break;

  case 46: /* expression: expression '-' expression  */
#line 266 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                            {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("-");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1668 "parser.cc"
    break;

  case 47: /* expression: '-' expression  */
#line 270 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                           {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("NEG");
    setParameters((yyval.ptree), (yyvsp[0].ptree));
}
#line 1677 "parser.cc"
    break;

  case 48: /* expression: NOT expression  */
#line 274 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                 {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("!");
    setParameters((yyval.ptree), (yyvsp[0].ptree));
}
#line 1686 "parser.cc"
    break;

  case 49: /* expression: expression ':' expression  */
#line 278 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                            {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName(":");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1695 "parser.cc"
    break;

  case 50: /* expression: expression GT expression  */
#line 282 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                           {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName(">");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1704 "parser.cc"
    break;

  case 51: /* expression: expression GE expression  */
#line 286 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                           {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName(">=");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1713 "parser.cc"
    break;

  case 52: /* expression: expression LT expression  */
#line 290 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                           {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("<");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1722 "parser.cc"
    break;

  case 53: /* expression: expression LE expression  */
#line 294 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                           {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("<=");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1731 "parser.cc"
    break;

  case 54: /* expression: expression EQ expression  */
#line 298 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                           {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("==");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1740 "parser.cc"
    break;

  case 55: /* expression: expression NE expression  */
#line 302 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                           {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("!=");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1749 "parser.cc"
    break;

  case 56: /* expression: expression AND expression  */
#line 306 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                            {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("&&");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1758 "parser.cc"
    break;

  case 57: /* expression: expression OR expression  */
#line 310 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                           {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("||");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
}
#line 1767 "parser.cc"
    break;

  case 58: /* expression: expression '^' expression  */
#line 314 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                            {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); (yyval.ptree)->setName("^");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
  }
#line 1776 "parser.cc"
    break;

  case 59: /* expression: expression SPECIAL expression  */
#line 318 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                {
    (yyval.ptree) = new ParseTree(jags::P_FUNCTION, yylineno); setName((yyval.ptree), (yyvsp[-1].stringptr));
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 1785 "parser.cc"
    break;

  case 60: /* expression: '(' expression ')'  */
#line 322 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                     { (yyval.ptree) = (yyvsp[-1].ptree); }
#line 1791 "parser.cc"
    break;

  case 61: /* arg_list: arg  */
#line 326 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
              {
    (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[0].ptree));
}
#line 1799 "parser.cc"
    break;

  case 62: /* arg_list: arg_list ',' arg  */
#line 329 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                   {
    (yyval.pvec)=(yyvsp[-2].pvec);
    (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 1808 "parser.cc"
    break;

  case 63: /* arg: %empty  */
#line 336 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
            {
    (yyval.ptree) = new ParseTree(jags::P_NULL, yylineno);
}
#line 1816 "parser.cc"
    break;

  case 64: /* arg: expression  */
#line 339 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
             {
    (yyval.ptree) = (yyvsp[0].ptree);
}
#line 1824 "parser.cc"
    break;

  case 65: /* distribution: NAME '(' arg_list ')'  */
#line 345 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
{
  (yyval.ptree) = new ParseTree(jags::P_DENSITY, yylineno); setName((yyval.ptree), (yyvsp[-3].stringptr));
  setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 1833 "parser.cc"
    break;

  case 66: /* truncated: 'T' '(' arg_list ')'  */
#line 351 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                { (yyval.ptree) = Truncated((yyvsp[-1].pvec)); }
#line 1839 "parser.cc"
    break;

  case 67: /* interval: 'I' '(' arg_list ')'  */
#line 353 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                                { (yyval.ptree) = Interval((yyvsp[-1].pvec)); }
#line 1845 "parser.cc"
    break;

  case 68: /* var: NAME  */
#line 355 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
          {
  (yyval.ptree) = new ParseTree(jags::P_VAR, yylineno); setName((yyval.ptree), (yyvsp[0].stringptr));
}
#line 1853 "parser.cc"
    break;

  case 69: /* var: NAME '[' arg_list ']'  */
#line 358 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"
                        {
  (yyval.ptree) = new ParseTree(jags::P_VAR, yylineno); setName((yyval.ptree), (yyvsp[-3].stringptr));
  setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 1862 "parser.cc"
    break;


#line 1866 "parser.cc"

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

#line 364 "../../../../../mcmc-jags/src/lib/compiler/parser.yy"


static std::string error_buf;

void yyerror (const char *s)
{
    extern char * yytext;
    extern int yylineno;

    std::ostringstream msg;
    msg << std::string(s) << " on line " << yylineno << " near \"" << 
           std::string(yytext) << "\"";
    error_buf = msg.str();
}

static ParseTree *Truncated (std::vector<ParseTree *> *bounds)
{
    //JAGS-Style truncation notation
    ParseTree *p = new ParseTree(jags::P_DISTMOD, yylineno);
    p->setName("T");
    setParameters(p, bounds);
    return p;
}

static ParseTree *Interval (std::vector<ParseTree *> *bounds)
{
    //BUGS-Style interval censoring notation
    ParseTree *p = new ParseTree(jags::P_DISTMOD, yylineno);
    p->setName("I");
    setParameters(p, bounds);
    return p;
}

static void setName(ParseTree *p, std::string *name)
{
  /* 
     The scanner cannot return a string, because a string cannot be
     part of a union.  So instead the scanner returns a pointer to
     a newly allocated string.  This memory must be freed as soon
     as it is used.
  */
  p->setName(*name);
  delete name;
}
	

static void setParameters(ParseTree *p, std::vector<ParseTree*> *parameters)
{
  /* 
     Same as setName (above).  The parser dynamically allocates
     vectors of (pointers to) parameters. These vectors must be
     deleted when we are done with them.
  */
  p->setParameters(*parameters);
  delete parameters; 
}

static void setParameters(ParseTree *p, ParseTree *param1)
{
  /*
    Wrapper function that creates a vector containing param1
    to be passed to ParseTree::setParameters.
  */
  std::vector<ParseTree *> parameters(1, param1);
  p->setParameters(parameters);
}

static void setParameters(ParseTree *p, ParseTree *param1, ParseTree *param2)
{
  /*
    Wrapper function that creates a vector containing param1
    and param2, to be passed to ParseTree::setParameters
  */
  std::vector<ParseTree *> parameters;
  parameters.push_back(param1);
  parameters.push_back(param2);
  p->setParameters(parameters);
}

static void setParameters(ParseTree *p, ParseTree *param1, ParseTree *param2,
			  ParseTree *param3)
{
  /*
    Wrapper function that creates a vector containing param1, param2
    and param3, to be passed to ParseTree::setParameters
  */
  std::vector<ParseTree *> parameters;
  parameters.push_back(param1);
  parameters.push_back(param2);
  parameters.push_back(param3);
  p->setParameters(parameters);
}

int parse_bugs (std::FILE *file, std::vector<ParseTree*> * &dec_list, 
                ParseTree * &data, ParseTree * &relations,
		std::string &message)
{
    extern std::FILE *yyin;
    yyin = file;
    
    int val = 0;
    error_buf.clear();

    if (yyparse() == 0) {
	dec_list = _pvariables; 
	data = _pdata; 
	relations = _prelations;
    }
    else {
	message = error_buf;
	delete _pvariables; 
	delete _prelations; 
	delete _pdata;
	val = 1;
    }
    _pvariables = nullptr;
    _prelations = nullptr;
    _pdata = nullptr;

    yylex_destroy();

    return val;
}
