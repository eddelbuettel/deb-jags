
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         zzparse
#define yylex           zzlex
#define yyerror         zzerror
#define yylval          zzlval
#define yychar          zzchar
#define yydebug         zzdebug
#define yynerrs         zznerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "parser.yy"

#include <config.h>

#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <dirent.h>

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
#include <list>
#include <iterator>

#include <Console.h>
#include <compiler/ParseTree.h>
#include <util/nainf.h>
#include <cstring>
#include <ltdl.h>

#include <cstdio>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
#include <list>

#include <Console.h>
#include <compiler/ParseTree.h>
#include <util/nainf.h>
#include <cstring>
#include <ltdl.h>

//Required for warning about masked distributions after module loading
#include <deque>
#include <distribution/Distribution.h>
#include <compiler/Compiler.h>

#include "ReadData.h"

    typedef void(*pt2Func)();

    int zzerror(const char *);
    int zzlex();
    int zzlex_destroy();
#define YYERROR_VERBOSE 0
    static Console *console;
    bool interactive;
    extern int command_buffer_count;
    void setName(ParseTree *p, std::string *name);
    std::map<std::string, SArray> _data_table;
    std::deque<lt_dlhandle> _modules;
    bool open_data_buffer(std::string const *name);
    bool open_command_buffer(std::string const *name);
    void return_to_main_buffer();
    void setMonitor(ParseTree const *var, int thin, std::string const &type);
    void clearMonitor(ParseTree const *var, std::string const &type);
    void setDefaultMonitors(std::string const &type, unsigned int thin);
    void doCoda (ParseTree const *var, std::string const &stem);
    void doAllCoda (std::string const &stem);
    void doDump (std::string const &file, DumpType type, unsigned int chain);
    void dumpMonitors(std::string const &file, std::string const &type);
    void doSystem(std::string const *command);

    static bool getWorkingDirectory(std::string &name);
    static void errordump();
    static void updatestar(long niter, long refresh, int width);
    static void adaptstar(long niter, long refresh, int width);
    static void setParameters(ParseTree *p, ParseTree *param1);
    static void setParameters(ParseTree *p, std::vector<ParseTree*> *parameters);
    static void setParameters(ParseTree *p, ParseTree *param1, ParseTree *param2);
    static void loadModule(std::string const &name);
    static void dumpSamplers(std::string const &file);
    static void delete_pvec(std::vector<ParseTree*> *);
    static void print_unused_variables();
    

/* Line 189 of yacc.c  */
#line 168 "parser.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     DOUBLE = 259,
     NAME = 260,
     STRING = 261,
     SYSCMD = 262,
     ENDCMD = 263,
     MODEL = 264,
     DATA = 265,
     IN = 266,
     TO = 267,
     INITS = 268,
     PARAMETERS = 269,
     COMPILE = 270,
     INITIALIZE = 271,
     ADAPT = 272,
     UPDATE = 273,
     BY = 274,
     MONITORS = 275,
     MONITOR = 276,
     TYPE = 277,
     SET = 278,
     CLEAR = 279,
     THIN = 280,
     CODA = 281,
     STEM = 282,
     EXIT = 283,
     NCHAINS = 284,
     CHAIN = 285,
     LOAD = 286,
     SAMPLERS = 287,
     LIST = 288,
     STRUCTURE = 289,
     DIM = 290,
     NA = 291,
     R_NULL = 292,
     DIMNAMES = 293,
     ITER = 294,
     ARROW = 295,
     ENDDATA = 296,
     ASINTEGER = 297,
     DIRECTORY = 298,
     CD = 299,
     PWD = 300,
     RUN = 301,
     ENDSCRIPT = 302
   };
#endif
/* Tokens.  */
#define INT 258
#define DOUBLE 259
#define NAME 260
#define STRING 261
#define SYSCMD 262
#define ENDCMD 263
#define MODEL 264
#define DATA 265
#define IN 266
#define TO 267
#define INITS 268
#define PARAMETERS 269
#define COMPILE 270
#define INITIALIZE 271
#define ADAPT 272
#define UPDATE 273
#define BY 274
#define MONITORS 275
#define MONITOR 276
#define TYPE 277
#define SET 278
#define CLEAR 279
#define THIN 280
#define CODA 281
#define STEM 282
#define EXIT 283
#define NCHAINS 284
#define CHAIN 285
#define LOAD 286
#define SAMPLERS 287
#define LIST 288
#define STRUCTURE 289
#define DIM 290
#define NA 291
#define R_NULL 292
#define DIMNAMES 293
#define ITER 294
#define ARROW 295
#define ENDDATA 296
#define ASINTEGER 297
#define DIRECTORY 298
#define CD 299
#define PWD 300
#define RUN 301
#define ENDSCRIPT 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 91 "parser.yy"

  int intval;
  double val;
  std::string *stringptr;
  ParseTree *ptree;
  std::vector<ParseTree*> *pvec;
  std::vector<double> *vec;
  std::vector<long> *ivec;



/* Line 214 of yacc.c  */
#line 310 "parser.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 322 "parser.cc"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNRULES -- Number of states.  */
#define YYNSTATES  271

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,    54,     2,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    55,
       2,    57,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,    56,     2,     2,    58,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    17,    20,
      23,    25,    27,    29,    31,    33,    35,    37,    39,    41,
      43,    45,    47,    49,    51,    53,    55,    57,    59,    61,
      65,    68,    72,    74,    78,    82,    85,    89,    98,   100,
     104,   113,   117,   121,   123,   130,   132,   135,   143,   146,
     154,   156,   158,   163,   165,   169,   171,   175,   177,   179,
     181,   185,   194,   197,   205,   213,   225,   237,   248,   259,
     266,   273,   275,   279,   288,   292,   301,   303,   305,   308,
     316,   319,   327,   330,   334,   336,   339,   343,   347,   351,
     355,   357,   359,   363,   370,   372,   374,   378,   382,   386,
     388,   390,   395,   397,   402,   404,   408,   410,   412,   416,
     418,   422,   424,   428,   430,   435,   437,   442,   447,   449,
     451,   456,   458,   462,   464,   469,   471,   475,   477,   480,
     482
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    -1,    60,    61,    -1,     8,    -1,    62,
       8,    -1,     1,     8,    -1,   110,    -1,    47,     8,    -1,
       7,     8,    -1,    63,    -1,    64,    -1,    65,    -1,    67,
      -1,    68,    -1,    69,    -1,    71,    -1,    72,    -1,    73,
      -1,    74,    -1,    80,    -1,    83,    -1,    85,    -1,    86,
      -1,    75,    -1,   109,    -1,   107,    -1,   108,    -1,    87,
      -1,     9,    11,    84,    -1,     9,    24,    -1,    66,    88,
      41,    -1,    66,    -1,    10,    12,    84,    -1,    10,    11,
      84,    -1,    10,    24,    -1,    70,    88,    41,    -1,    70,
      88,    41,    48,    30,    49,     3,    50,    -1,    70,    -1,
      14,    12,    84,    -1,    14,    12,    84,    48,    30,    49,
       3,    50,    -1,    14,    11,    84,    -1,    13,    11,    84,
      -1,    15,    -1,    15,    48,    29,    49,     3,    50,    -1,
      16,    -1,    17,     3,    -1,    17,     3,    48,    19,    49,
       3,    50,    -1,    18,     3,    -1,    18,     3,    48,    19,
      49,     3,    50,    -1,    28,    -1,     5,    -1,     5,    51,
      77,    52,    -1,    78,    -1,    77,    48,    78,    -1,    79,
      -1,    79,    53,    79,    -1,     3,    -1,    81,    -1,    82,
      -1,    21,    23,    76,    -1,    21,    23,    76,    48,    25,
      49,     3,    50,    -1,    21,    76,    -1,    21,    76,    48,
      25,    49,     3,    50,    -1,    21,    76,    48,    22,    49,
       5,    50,    -1,    21,    76,    48,    22,    49,     5,    50,
      25,    49,     3,    50,    -1,    21,    76,    48,    25,    49,
       3,    50,    22,    49,     5,    50,    -1,    21,    48,    25,
      49,     3,    50,    22,    49,     5,    50,    -1,    21,    48,
      22,    49,     5,    50,    25,    49,     3,    50,    -1,    21,
      48,    22,    49,     5,    50,    -1,    21,    48,    25,    49,
       3,    50,    -1,    21,    -1,    21,    24,    76,    -1,    21,
      24,    76,    48,    22,    49,     5,    50,    -1,    20,    12,
      84,    -1,    20,    12,    84,    48,    22,    49,     5,    50,
      -1,     5,    -1,     6,    -1,    26,    76,    -1,    26,    76,
      48,    27,    49,    84,    50,    -1,    26,    54,    -1,    26,
      54,    48,    27,    49,    84,    50,    -1,    31,    84,    -1,
      32,    12,    84,    -1,    89,    -1,    88,    89,    -1,    88,
      55,    89,    -1,    90,    40,    91,    -1,    90,    40,    94,
      -1,    90,    40,     6,    -1,     6,    -1,     5,    -1,    56,
       5,    56,    -1,    34,    49,    94,    48,    92,    50,    -1,
      93,    -1,    99,    -1,    92,    48,    99,    -1,    92,    48,
      93,    -1,    35,    57,    94,    -1,    95,    -1,    96,    -1,
      42,    49,    96,    50,    -1,    98,    -1,    58,    49,    97,
      50,    -1,    98,    -1,    97,    48,    98,    -1,     4,    -1,
      36,    -1,     5,    57,   102,    -1,   101,    -1,   100,    48,
     101,    -1,   102,    -1,     5,    57,   102,    -1,   103,    -1,
      42,    49,   103,    50,    -1,   105,    -1,    33,    49,   100,
      50,    -1,    34,    49,   100,    50,    -1,    37,    -1,     4,
      -1,    58,    49,   104,    50,    -1,     4,    -1,   104,    48,
       4,    -1,     6,    -1,    58,    49,   106,    50,    -1,     6,
      -1,   106,    48,     6,    -1,    45,    -1,    44,    84,    -1,
      43,    -1,    46,    84,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   163,   163,   167,   173,   174,   175,   176,   177,   178,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   202,
     213,   218,   226,   229,   235,   246,   252,   271,   284,   287,
     291,   297,   306,   318,   322,   328,   335,   339,   344,   349,
     354,   357,   360,   366,   369,   374,   377,   383,   386,   387,
     390,   393,   396,   399,   402,   406,   410,   414,   418,   421,
     425,   428,   433,   436,   442,   448,   460,   461,   464,   467,
     470,   473,   478,   481,   490,   493,   496,   501,   504,   509,
     517,   518,   519,   524,   535,   536,   537,   538,   541,   546,
     547,   550,   553,   557,   563,   564,   567,   568,   574,   577,
     578,   581,   582,   585,   586,   587,   588,   589,   590,   593,
     594,   597,   598,   601,   602,   605,   606,   611,   622,   630,
     654
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "DOUBLE", "NAME", "STRING",
  "SYSCMD", "ENDCMD", "MODEL", "DATA", "IN", "TO", "INITS", "PARAMETERS",
  "COMPILE", "INITIALIZE", "ADAPT", "UPDATE", "BY", "MONITORS", "MONITOR",
  "TYPE", "SET", "CLEAR", "THIN", "CODA", "STEM", "EXIT", "NCHAINS",
  "CHAIN", "LOAD", "SAMPLERS", "LIST", "STRUCTURE", "DIM", "NA", "R_NULL",
  "DIMNAMES", "ITER", "ARROW", "ENDDATA", "ASINTEGER", "DIRECTORY", "CD",
  "PWD", "RUN", "ENDSCRIPT", "','", "'('", "')'", "'['", "']'", "':'",
  "'*'", "';'", "'`'", "'='", "'c'", "$accept", "input", "line", "command",
  "model", "data_in", "data_to", "data", "data_clear", "parameters_in",
  "parameters_to", "parameters", "compile", "initialize", "adapt",
  "update", "exit", "var", "range_list", "range_element", "index",
  "monitor", "monitor_set", "monitor_clear", "monitors_to", "file_name",
  "coda", "load", "samplers_to", "r_assignment_list", "r_assignment",
  "r_name", "r_structure", "r_attribute_list", "r_dim", "r_collection",
  "r_integer_collection", "r_value_collection", "r_value_list", "r_value",
  "r_generic_attribute", "r_generic_list", "r_generic_list_element",
  "r_generic_vector", "r_numeric_vector", "r_double_list",
  "r_character_vector", "r_string_list", "get_working_dir",
  "set_working_dir", "read_dir", "run_script", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    44,    40,
      41,    91,    93,    58,    42,    59,    96,    61,    99
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    66,    67,    68,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    73,    73,    74,    74,
      75,    76,    76,    77,    77,    78,    78,    79,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      85,    85,    86,    87,    88,    88,    88,    89,    89,    89,
      90,    90,    90,    91,    92,    92,    92,    92,    93,    94,
      94,    95,    96,    96,    97,    97,    98,    98,    99,   100,
     100,   101,   101,   102,   102,   102,   102,   102,   102,   103,
     103,   104,   104,   105,   105,   106,   106,   107,   108,   109,
     110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     1,     3,     3,     2,     3,     8,     1,     3,
       8,     3,     3,     1,     6,     1,     2,     7,     2,     7,
       1,     1,     4,     1,     3,     1,     3,     1,     1,     1,
       3,     8,     2,     7,     7,    11,    11,    10,    10,     6,
       6,     1,     3,     8,     3,     8,     1,     1,     2,     7,
       2,     7,     2,     3,     1,     2,     3,     3,     3,     3,
       1,     1,     3,     6,     1,     1,     3,     3,     3,     1,
       1,     4,     1,     4,     1,     3,     1,     1,     3,     1,
       3,     1,     3,     1,     4,     1,     4,     4,     1,     1,
       4,     1,     3,     1,     4,     1,     3,     1,     2,     1,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     4,     0,     0,     0,     0,
      43,    45,     0,     0,     0,    71,     0,    50,     0,     0,
     129,     0,   127,     0,     0,     3,     0,    10,    11,    12,
      32,    13,    14,    15,    38,    16,    17,    18,    19,    24,
      20,    58,    59,    21,    22,    23,    28,    26,    27,    25,
       7,     6,     9,     0,    30,     0,     0,    35,     0,     0,
       0,     0,    46,    48,     0,    51,     0,     0,     0,    62,
      80,    78,    76,    77,    82,     0,   128,   130,     8,     5,
      91,    90,     0,     0,    84,     0,     0,    29,    34,    33,
      42,    41,    39,     0,     0,     0,    74,     0,    60,    72,
       0,     0,     0,     0,     0,    83,     0,    31,     0,    85,
       0,    36,     0,     0,     0,     0,     0,    57,     0,    53,
      55,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      86,   106,    89,     0,   107,     0,     0,    87,    88,    99,
     100,   102,     0,     0,     0,     0,     0,     0,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,    54,    56,
       0,     0,    69,    70,     0,     0,     0,     0,     0,     0,
       0,   104,     0,     0,    47,    49,     0,     0,     0,     0,
       0,    64,    63,    81,    79,     0,   101,     0,   103,     0,
      40,    75,    61,    73,     0,     0,     0,     0,     0,     0,
       0,    94,    95,   105,    37,     0,     0,     0,     0,     0,
       0,     0,    93,    68,    67,     0,     0,   119,   123,     0,
       0,   118,     0,     0,   108,   113,   115,    98,    97,    96,
      65,    66,     0,     0,     0,     0,     0,     0,   109,   111,
       0,     0,     0,   121,   125,     0,     0,     0,     0,   116,
     117,     0,   114,     0,   120,     0,   124,   112,   110,   122,
     126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    69,   118,   119,
     120,    40,    41,    42,    43,    74,    44,    45,    46,    83,
      84,    85,   137,   210,   211,   138,   139,   140,   180,   141,
     212,   247,   248,   249,   235,   255,   236,   256,    47,    48,
      49,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -213
static const yytype_int16 yypact[] =
{
    -213,    82,  -213,    -2,     6,  -213,    94,    61,    18,    75,
     -15,  -213,    58,    64,    81,    83,    10,  -213,    19,    99,
    -213,    19,  -213,    19,    86,  -213,   108,  -213,  -213,  -213,
       4,  -213,  -213,  -213,     4,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,    19,  -213,    19,    19,  -213,    19,    19,
      19,    95,    96,    97,    19,    72,   125,   125,   -17,    98,
     100,   101,  -213,  -213,  -213,    19,  -213,  -213,  -213,  -213,
    -213,  -213,   137,    22,  -213,   103,    25,  -213,  -213,  -213,
    -213,  -213,   102,   104,   128,   132,   106,   149,   107,   109,
     110,   111,    87,   129,   131,  -213,   105,  -213,     4,  -213,
      17,   114,   133,   161,   117,   118,   143,  -213,   -26,  -213,
     115,   144,   148,   166,   169,   124,   126,   127,   130,  -213,
    -213,  -213,  -213,   134,  -213,   135,   136,  -213,  -213,  -213,
    -213,  -213,   147,   138,   139,   171,   175,   141,   149,  -213,
     149,   142,   145,   146,   150,   176,   177,    19,    19,     0,
      12,    48,   152,   179,  -213,   153,   154,   181,  -213,  -213,
     185,   187,   168,   173,   155,   156,   157,   158,   151,   159,
      67,  -213,   194,   160,  -213,  -213,   162,   163,   164,   167,
     170,   186,   180,  -213,  -213,    69,  -213,    48,  -213,   165,
    -213,  -213,  -213,  -213,   195,   212,   172,   174,   178,   182,
      71,  -213,  -213,  -213,  -213,   183,   184,   215,   217,    13,
       0,    69,  -213,  -213,  -213,   188,   190,  -213,  -213,   192,
     193,  -213,   196,   197,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,     7,     7,    -1,   116,   191,    84,  -213,  -213,
      85,   198,   199,  -213,  -213,    90,    91,    13,     7,  -213,
    -213,   216,  -213,   220,  -213,   219,  -213,  -213,  -213,  -213,
    -213
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,     2,  -213,    78,
      77,  -213,  -213,  -213,  -213,   -21,  -213,  -213,  -213,   202,
      -7,  -213,  -213,  -213,     8,  -158,  -213,    68,  -213,  -141,
       9,   -12,   -14,  -212,    11,  -213,  -213,  -213,  -213,  -213,
    -213,  -213
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      76,   178,    77,   227,   131,   100,    51,   234,   101,    80,
      81,   227,   246,   228,    52,    65,   131,   227,    71,   228,
     181,   131,   148,   132,    72,    73,   149,    80,    81,    58,
      80,    81,    87,    61,    88,    89,   134,    90,    91,    92,
     229,   230,   135,    96,   231,   267,   229,   230,   134,   232,
     231,   133,   131,   134,   105,   232,   213,   251,   136,   135,
      82,    62,   237,   107,    70,   233,   111,    63,    98,    99,
     136,   233,    55,    56,   208,   136,   109,   108,    82,   109,
     108,    82,     2,     3,   134,    57,    59,    60,    65,     4,
       5,     6,     7,    64,    78,     8,     9,    10,    11,    12,
      13,   130,    14,    15,   209,    53,    66,    67,    16,   125,
      17,    75,   126,    18,    19,   197,    79,   198,    54,   221,
     253,   222,   254,    97,    93,    20,    21,    22,    23,    24,
      65,    68,   258,   258,   259,   260,   176,   177,   263,   265,
     264,   266,   106,   110,    94,    95,   102,   114,   103,   104,
     112,   115,   117,   113,   116,   121,   127,   122,   128,   123,
     124,   129,   142,   143,   144,   147,   145,   146,   150,   151,
     152,   153,   154,   155,   165,   156,   157,   162,   166,   158,
     175,   174,   183,   159,   160,   161,   186,   163,   187,   164,
     167,   170,   188,   189,   171,   190,   172,   199,   215,   195,
     173,   182,   207,   184,   185,   191,   192,   193,   194,   196,
     200,   206,   201,   202,   203,   214,   204,   216,   225,   205,
     253,   217,   226,   218,   269,   270,   168,   169,   179,   238,
     239,   250,     0,   223,   224,   219,    86,     0,   240,   220,
     241,   242,   243,     0,   268,   244,   245,   261,   257,   262,
       0,     0,     0,     0,     0,   252
};

static const yytype_int16 yycheck[] =
{
      21,   159,    23,     4,     4,    22,     8,   219,    25,     5,
       6,     4,     5,     6,     8,     5,     4,     4,    16,     6,
     161,     4,    48,     6,     5,     6,    52,     5,     6,    11,
       5,     6,    53,    48,    55,    56,    36,    58,    59,    60,
      33,    34,    42,    64,    37,   257,    33,    34,    36,    42,
      37,    34,     4,    36,    75,    42,   197,    58,    58,    42,
      56,     3,   220,    41,    54,    58,    41,     3,    66,    67,
      58,    58,    11,    12,     5,    58,    83,    55,    56,    86,
      55,    56,     0,     1,    36,    24,    11,    12,     5,     7,
       8,     9,    10,    12,     8,    13,    14,    15,    16,    17,
      18,   108,    20,    21,    35,    11,    23,    24,    26,    22,
      28,    12,    25,    31,    32,    48,     8,    50,    24,    48,
       4,    50,     6,    51,    29,    43,    44,    45,    46,    47,
       5,    48,    48,    48,    50,    50,   157,   158,    48,    48,
      50,    50,     5,    40,    48,    48,    48,    19,    48,    48,
      48,    19,     3,    49,    48,    48,    27,    48,    27,    49,
      49,    56,    48,    30,     3,    22,    49,    49,    53,    25,
      22,     5,     3,    49,     3,    49,    49,    30,     3,    49,
       3,     5,     3,    49,    49,    49,     5,    49,     3,    50,
      49,    49,     5,    25,    49,    22,    50,     3,     3,    48,
      50,    49,    22,    50,    50,    50,    50,    50,    50,    50,
      50,    25,    50,    50,    50,    50,    49,     5,     3,    49,
       4,    49,     5,    49,     4,     6,   148,   150,   160,   221,
     221,   243,    -1,    50,    50,    57,    34,    -1,    50,    57,
      50,    49,    49,    -1,   258,    49,    49,    49,    57,    50,
      -1,    -1,    -1,    -1,    -1,   244
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,     0,     1,     7,     8,     9,    10,    13,    14,
      15,    16,    17,    18,    20,    21,    26,    28,    31,    32,
      43,    44,    45,    46,    47,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      80,    81,    82,    83,    85,    86,    87,   107,   108,   109,
     110,     8,     8,    11,    24,    11,    12,    24,    11,    11,
      12,    48,     3,     3,    12,     5,    23,    24,    48,    76,
      54,    76,     5,     6,    84,    12,    84,    84,     8,     8,
       5,     6,    56,    88,    89,    90,    88,    84,    84,    84,
      84,    84,    84,    29,    48,    48,    84,    51,    76,    76,
      22,    25,    48,    48,    48,    84,     5,    41,    55,    89,
      40,    41,    48,    49,    19,    19,    48,     3,    77,    78,
      79,    48,    48,    49,    49,    22,    25,    27,    27,    56,
      89,     4,     6,    34,    36,    42,    58,    91,    94,    95,
      96,    98,    48,    30,     3,    49,    49,    22,    48,    52,
      53,    25,    22,     5,     3,    49,    49,    49,    49,    49,
      49,    49,    30,    49,    50,     3,     3,    49,    78,    79,
      49,    49,    50,    50,     5,     3,    84,    84,    94,    96,
      97,    98,    49,     3,    50,    50,     5,     3,     5,    25,
      22,    50,    50,    50,    50,    48,    50,    48,    50,     3,
      50,    50,    50,    50,    49,    49,    25,    22,     5,    35,
      92,    93,    99,    98,    50,     3,     5,    49,    49,    57,
      57,    48,    50,    50,    50,     3,     5,     4,     6,    33,
      34,    37,    42,    58,   102,   103,   105,    94,    93,    99,
      50,    50,    49,    49,    49,    49,     5,   100,   101,   102,
     100,    58,   103,     4,     6,   104,   106,    57,    48,    50,
      50,    49,    50,    48,    50,    48,    50,   102,   101,     4,
       6
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 163 "parser.yy"
    {
    if (interactive && command_buffer_count == 0) 
	std::cout << ". " << std::flush;
}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 167 "parser.yy"
    {
    if (interactive && command_buffer_count == 0) 
	std::cout << ". " << std::flush;
}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 173 "parser.yy"
    {}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 174 "parser.yy"
    {}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 175 "parser.yy"
    {if(interactive) yyerrok; else exit(1); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 176 "parser.yy"
    {}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 177 "parser.yy"
    {}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 178 "parser.yy"
    { doSystem((yyvsp[(1) - (2)].stringptr)); delete (yyvsp[(1) - (2)].stringptr);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 202 "parser.yy"
    {
    std::FILE *file = std::fopen(((yyvsp[(3) - (3)].stringptr))->c_str(), "r");
    if (!file) {
	std::cerr << "Failed to open file " << *((yyvsp[(3) - (3)].stringptr)) << std::endl;
    }
    else {
	console->checkModel(file);
	std::fclose(file);
    }
    delete (yyvsp[(3) - (3)].stringptr);
}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 213 "parser.yy"
    {
    console->clearModel();
}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 218 "parser.yy"
    {
    std::string rngname;
    readRData((yyvsp[(2) - (3)].pvec), _data_table, rngname);
    if (rngname.size() != 0) {
	std::cerr << "WARNING: .RNG.name assignment ignored" << std::endl;
    }
    delete_pvec((yyvsp[(2) - (3)].pvec));
 }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 226 "parser.yy"
    {}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 229 "parser.yy"
    {
    doDump(*(yyvsp[(3) - (3)].stringptr), DUMP_DATA, 1);
    delete (yyvsp[(3) - (3)].stringptr);
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 235 "parser.yy"
    {
    if(open_data_buffer((yyvsp[(3) - (3)].stringptr))) {
	std::cout << "Reading data file " << *(yyvsp[(3) - (3)].stringptr) << std::endl;
    }
    else {
	std::cerr << "Unable to open file " << *(yyvsp[(3) - (3)].stringptr) << std::endl << std::flush;
    }
    delete (yyvsp[(3) - (3)].stringptr);
 }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 246 "parser.yy"
    {
  std::cout << "Clearing data table " << std::endl;
  _data_table.clear();
}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 253 "parser.yy"
    {
    std::map<std::string, SArray> parameter_table;
    std::string rngname;
    readRData((yyvsp[(2) - (3)].pvec), parameter_table, rngname);
    delete_pvec((yyvsp[(2) - (3)].pvec));
    /* Set all chains to the same state. If the user sets the
       RNG state in addition to the parameter values then all
       chains will be identical!
    */
    for (unsigned int i = 1; i <= console->nchain(); ++i) {
	/* We have to set the name first, because the state or seed
	   might be embedded in the parameter_table */
	if (rngname.size() != 0) {
	    console->setRNGname(rngname, i);
	}
	console->setParameters(parameter_table, i);
    }
}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 272 "parser.yy"
    {
    std::map<std::string, SArray> parameter_table;
    std::string rngname;
    readRData((yyvsp[(2) - (8)].pvec), parameter_table, rngname);
    delete (yyvsp[(2) - (8)].pvec);
    /* We have to set the name first, because the state or seed
       might be embedded in the parameter_table */
    if (rngname.size() != 0) {
        console->setRNGname(rngname, (yyvsp[(7) - (8)].intval));
    }
    console->setParameters(parameter_table, (yyvsp[(7) - (8)].intval));
}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 284 "parser.yy"
    {}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 287 "parser.yy"
    {
    doDump(*(yyvsp[(3) - (3)].stringptr), DUMP_PARAMETERS, 1);
    delete (yyvsp[(3) - (3)].stringptr);
}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 291 "parser.yy"
    {
    doDump(*(yyvsp[(3) - (8)].stringptr), DUMP_PARAMETERS, (yyvsp[(7) - (8)].intval));
    delete (yyvsp[(3) - (8)].stringptr);
}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 297 "parser.yy"
    {
  if(open_data_buffer((yyvsp[(3) - (3)].stringptr))) {
    std::cout << "Reading parameter file " << *(yyvsp[(3) - (3)].stringptr) << std::endl;
  }
  else {
    std::cerr << "Unable to open file " << *(yyvsp[(3) - (3)].stringptr) << std::endl << std::flush;
  }
  delete (yyvsp[(3) - (3)].stringptr);
}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 306 "parser.yy"
    {
  /* Legacy option to not break existing scripts */
  if(open_data_buffer((yyvsp[(3) - (3)].stringptr))) {
    std::cout << "Reading initial values file " << *(yyvsp[(3) - (3)].stringptr) << std::endl;
  }
  else {
    std::cerr << "Unable to open file " << *(yyvsp[(3) - (3)].stringptr) << std::endl << std::flush;
  }
  delete (yyvsp[(3) - (3)].stringptr);
}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 318 "parser.yy"
    {
    console->compile(_data_table, 1, true);
    print_unused_variables();
}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 322 "parser.yy"
    {
    console->compile(_data_table, (yyvsp[(5) - (6)].intval), true);
    print_unused_variables();
}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 328 "parser.yy"
    {
  if (!console->initialize()) {
    errordump();
  }
}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 335 "parser.yy"
    {
    long refresh = (yyvsp[(2) - (2)].intval)/40;
    adaptstar((yyvsp[(2) - (2)].intval), refresh, 40);
}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 339 "parser.yy"
    {
    adaptstar((yyvsp[(2) - (7)].intval),(yyvsp[(6) - (7)].intval),40);
}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 344 "parser.yy"
    {
  //fixme: put refresh option
  long refresh = (yyvsp[(2) - (2)].intval)/40;
  updatestar((yyvsp[(2) - (2)].intval), refresh, 40);
}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 349 "parser.yy"
    {
  updatestar((yyvsp[(2) - (7)].intval),(yyvsp[(6) - (7)].intval), 40);
}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 354 "parser.yy"
    {return 0;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 357 "parser.yy"
    {
  (yyval.ptree) = new ParseTree(P_VAR); setName((yyval.ptree), (yyvsp[(1) - (1)].stringptr));
}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 360 "parser.yy"
    {
  (yyval.ptree) = new ParseTree(P_VAR); setName((yyval.ptree), (yyvsp[(1) - (4)].stringptr));
  setParameters((yyval.ptree), (yyvsp[(3) - (4)].pvec));
}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 366 "parser.yy"
    {
  (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[(1) - (1)].ptree)); 
}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 369 "parser.yy"
    {
  (yyval.pvec)=(yyvsp[(1) - (3)].pvec); (yyval.pvec)->push_back((yyvsp[(3) - (3)].ptree));
}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 374 "parser.yy"
    {
  (yyval.ptree) = new ParseTree(P_RANGE); setParameters((yyval.ptree),(yyvsp[(1) - (1)].ptree));
}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 377 "parser.yy"
    {
  (yyval.ptree) = new ParseTree(P_RANGE); setParameters((yyval.ptree), (yyvsp[(1) - (3)].ptree), (yyvsp[(3) - (3)].ptree));
}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 383 "parser.yy"
    {(yyval.ptree) = new ParseTree(P_VALUE); (yyval.ptree)->setValue((yyvsp[(1) - (1)].intval));}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 390 "parser.yy"
    { 
    setMonitor((yyvsp[(3) - (3)].ptree), 1, "trace"); delete (yyvsp[(3) - (3)].ptree);
}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 393 "parser.yy"
    { 
    setMonitor((yyvsp[(3) - (8)].ptree), (yyvsp[(7) - (8)].intval), "trace"); delete (yyvsp[(3) - (8)].ptree);
}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 396 "parser.yy"
    {
    setMonitor((yyvsp[(2) - (2)].ptree), 1, "trace"); delete (yyvsp[(2) - (2)].ptree);
}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 399 "parser.yy"
    { 
    setMonitor((yyvsp[(2) - (7)].ptree), (yyvsp[(6) - (7)].intval), "trace"); delete (yyvsp[(2) - (7)].ptree);
}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 402 "parser.yy"
    {
    setMonitor((yyvsp[(2) - (7)].ptree), 1, *(yyvsp[(6) - (7)].stringptr));
    delete (yyvsp[(6) - (7)].stringptr);
}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 406 "parser.yy"
    {
    setMonitor((yyvsp[(2) - (11)].ptree), (yyvsp[(10) - (11)].intval), *(yyvsp[(6) - (11)].stringptr)); 
    delete (yyvsp[(6) - (11)].stringptr);
}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 410 "parser.yy"
    {
    setMonitor((yyvsp[(2) - (11)].ptree), (yyvsp[(6) - (11)].intval), *(yyvsp[(10) - (11)].stringptr)); 
    delete (yyvsp[(10) - (11)].stringptr);
}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 414 "parser.yy"
    {
    setDefaultMonitors(*(yyvsp[(9) - (10)].stringptr), (yyvsp[(5) - (10)].intval));
    delete (yyvsp[(9) - (10)].stringptr);
}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 418 "parser.yy"
    {
    setDefaultMonitors(*(yyvsp[(5) - (10)].stringptr), (yyvsp[(9) - (10)].intval));
}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 421 "parser.yy"
    {
    setDefaultMonitors(*(yyvsp[(5) - (6)].stringptr), 1);
    delete (yyvsp[(5) - (6)].stringptr);
}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 425 "parser.yy"
    {
    setDefaultMonitors("trace", (yyvsp[(5) - (6)].intval));
}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 428 "parser.yy"
    {
    setDefaultMonitors("trace", 1);
}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 433 "parser.yy"
    {
    clearMonitor((yyvsp[(3) - (3)].ptree), "trace"); delete (yyvsp[(3) - (3)].ptree);
}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 436 "parser.yy"
    {
    clearMonitor((yyvsp[(3) - (8)].ptree), *(yyvsp[(7) - (8)].stringptr));
    delete (yyvsp[(7) - (8)].stringptr);
}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 443 "parser.yy"
    {
    dumpMonitors(*(yyvsp[(3) - (3)].stringptr), "trace");
    delete (yyvsp[(3) - (3)].stringptr);
}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 448 "parser.yy"
    {
    dumpMonitors(*(yyvsp[(3) - (8)].stringptr), *(yyvsp[(7) - (8)].stringptr));
    delete (yyvsp[(3) - (8)].stringptr);
    delete (yyvsp[(7) - (8)].stringptr); 
}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 460 "parser.yy"
    { (yyval.stringptr) = (yyvsp[(1) - (1)].stringptr);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 461 "parser.yy"
    { (yyval.stringptr) = (yyvsp[(1) - (1)].stringptr); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 464 "parser.yy"
    {
  doCoda ((yyvsp[(2) - (2)].ptree), "CODA"); delete (yyvsp[(2) - (2)].ptree);
}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 467 "parser.yy"
    {
  doCoda ((yyvsp[(2) - (7)].ptree), *(yyvsp[(6) - (7)].stringptr)); delete (yyvsp[(2) - (7)].ptree); delete (yyvsp[(6) - (7)].stringptr);
}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 470 "parser.yy"
    {
  doAllCoda ("CODA"); 
}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 473 "parser.yy"
    {
  doAllCoda (*(yyvsp[(6) - (7)].stringptr)); delete (yyvsp[(6) - (7)].stringptr); 
}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 478 "parser.yy"
    { loadModule(*(yyvsp[(2) - (2)].stringptr)); }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 482 "parser.yy"
    {
    dumpSamplers(*(yyvsp[(3) - (3)].stringptr));
    delete (yyvsp[(3) - (3)].stringptr);
}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 490 "parser.yy"
    {
  (yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[(1) - (1)].ptree));
}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 493 "parser.yy"
    {
  (yyval.pvec) = (yyvsp[(1) - (2)].pvec); (yyval.pvec)->push_back((yyvsp[(2) - (2)].ptree));
}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 496 "parser.yy"
    {
  (yyval.pvec) = (yyvsp[(1) - (3)].pvec); (yyval.pvec)->push_back((yyvsp[(3) - (3)].ptree));
}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 501 "parser.yy"
    {
  (yyval.ptree) = (yyvsp[(3) - (3)].ptree); setName((yyval.ptree), (yyvsp[(1) - (3)].stringptr));
}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 504 "parser.yy"
    {
  (yyval.ptree) = new ParseTree(P_ARRAY);
  setName((yyval.ptree), (yyvsp[(1) - (3)].stringptr));
  setParameters((yyval.ptree), (yyvsp[(3) - (3)].ptree));
}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 509 "parser.yy"
    {
  /* Allow this for setting the NAME of the random number generator */
  (yyval.ptree) = new ParseTree(P_VAR); setName((yyval.ptree), (yyvsp[(1) - (3)].stringptr));
  ParseTree *p = new ParseTree(P_VAR); setName(p, (yyvsp[(3) - (3)].stringptr));
  setParameters((yyval.ptree), p);
}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 519 "parser.yy"
    {
    /* R >= 2.4.0 uses backticks for quoted names */
    (yyval.stringptr) = (yyvsp[(2) - (3)].stringptr);
}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 524 "parser.yy"
    {
  (yyval.ptree) = new ParseTree(P_ARRAY); 
  if ((yyvsp[(5) - (6)].ptree)) 
    setParameters((yyval.ptree), (yyvsp[(3) - (6)].ptree), (yyvsp[(5) - (6)].ptree));
  else
    setParameters((yyval.ptree), (yyvsp[(3) - (6)].ptree));
}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 536 "parser.yy"
    {(yyval.ptree)=0;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 538 "parser.yy"
    {(yyval.ptree)=(yyvsp[(3) - (3)].ptree);}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 541 "parser.yy"
    {
  (yyval.ptree) = (yyvsp[(3) - (3)].ptree);
}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 550 "parser.yy"
    {(yyval.ptree) = (yyvsp[(3) - (4)].ptree);}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 553 "parser.yy"
    { 
  (yyval.ptree) = new ParseTree(P_VECTOR); 
  setParameters((yyval.ptree), (yyvsp[(1) - (1)].ptree));
}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 557 "parser.yy"
    {
  (yyval.ptree) = new ParseTree(P_VECTOR);
  setParameters((yyval.ptree), (yyvsp[(3) - (4)].pvec));
}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 563 "parser.yy"
    {(yyval.pvec) = new std::vector<ParseTree*>(1, (yyvsp[(1) - (1)].ptree)); }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 564 "parser.yy"
    {(yyval.pvec) = (yyvsp[(1) - (3)].pvec); (yyval.pvec)->push_back((yyvsp[(3) - (3)].ptree));}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 567 "parser.yy"
    {(yyval.ptree) = new ParseTree(P_VALUE); (yyval.ptree)->setValue((yyvsp[(1) - (1)].val));}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 568 "parser.yy"
    {(yyval.ptree) = new ParseTree(P_VALUE); (yyval.ptree)->setValue(JAGS_NA);}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 574 "parser.yy"
    {;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 577 "parser.yy"
    {;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 578 "parser.yy"
    {;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 581 "parser.yy"
    {;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 582 "parser.yy"
    {;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 585 "parser.yy"
    {;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 586 "parser.yy"
    {;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 587 "parser.yy"
    {;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 588 "parser.yy"
    {;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 589 "parser.yy"
    {;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 590 "parser.yy"
    {;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 593 "parser.yy"
    {;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 597 "parser.yy"
    {;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 598 "parser.yy"
    {;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 601 "parser.yy"
    {;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 602 "parser.yy"
    {;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 605 "parser.yy"
    {;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 606 "parser.yy"
    {;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 612 "parser.yy"
    {
    std::string name;
    if (getWorkingDirectory(name)) {
	std::cout << name << std::endl;
    }
    else {
	std::cout << "ERROR: " << name << std::endl;
    }
}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 623 "parser.yy"
    {
    if (chdir(((yyvsp[(2) - (2)].stringptr))->c_str()) == -1) {
	std::cout << "ERROR: Cannot change working directory" << std::endl;
    }
    delete (yyvsp[(2) - (2)].stringptr);
}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 631 "parser.yy"
    {
    std::string name;
    if (!getWorkingDirectory(name)) {
	std::cerr << "ERROR: Unable to get working directory name\n"
		  << name << std::endl;
	return 0;
    }
	
    DIR *dir;
    struct dirent *de;
    if ((dir = opendir(name.c_str())) != 0) {
	while ((de = readdir(dir)) != 0) {
	    if (std::strcmp(de->d_name, ".") && std::strcmp(de->d_name, "..")) {
		std::cout << de->d_name << "\n";
	    }
	}
	closedir(dir);
    }
    else {
	std::cerr << "Unable to open working directory" << std::endl;
    }
}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 654 "parser.yy"
    {
    if(open_command_buffer((yyvsp[(2) - (2)].stringptr))) {
	std::cout << "Running script file " << *(yyvsp[(2) - (2)].stringptr) << std::endl;
    }
    else {
	std::cerr << "Unable to open script file " << *(yyvsp[(2) - (2)].stringptr) << std::endl;
    }
    delete (yyvsp[(2) - (2)].stringptr);
 }
    break;



/* Line 1455 of yacc.c  */
#line 2726 "parser.cc"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 665 "parser.yy"


int zzerror (const char *s)
{
    return_to_main_buffer();
    std::cerr << s << std::endl;
    return 0;
}

static Range getRange(ParseTree const *var)
{
  /* 
     Blank arguments, e.g. foo[] or bar[,1]  are not allowed.
  */
  unsigned int size = var->parameters().size();

  std::vector<int>  ind_lower(size), ind_upper(size);
  for (unsigned int i = 0; i < size; ++i) {
    ParseTree const *range_element = var->parameters()[i];
    switch(range_element->parameters().size()) {
    case 1:
      ind_lower[i] = (int) (range_element->parameters()[0]->value() + 1.0E-6);
      ind_upper[i] = ind_lower[i];
      break;
    case 2:
      ind_lower[i] = (int) (range_element->parameters()[0]->value() + 1.0E-6);  
      ind_upper[i] = (int) (range_element->parameters()[1]->value() + 1.0E-6);
      break;
    default:
      //Error! FIXME
      break;
    }
  }
  return Range(ind_lower, ind_upper);
}

void setMonitor(ParseTree const *var, int thin, std::string const &type)
{
    std::string const &name = var->name();
    if (var->parameters().empty()) {
	/* Requesting the whole node */
	console->setMonitor(name, Range(), thin, type);
    }
    else {
	/* Requesting subset of a multivariate node */
	console->setMonitor(name, getRange(var), thin, type);
    }
}

void clearMonitor(ParseTree const *var, std::string const &type)
{
    std::string const &name = var->name();
    if (var->parameters().empty()) {
	/* Requesting the whole node */
	console->clearMonitor(name, Range(), type);
    }
    else {
	/* Requesting subset of a multivariate node */
	console->clearMonitor(name, getRange(var), type);
    }
}

void setDefaultMonitors(std::string const &type, unsigned int thin)
{
    console->setDefaultMonitors(type, thin);
}

/*
void doCoda (ParseTree const *var, std::string const &stem)
{
  unsigned int nchain = console->nchain();

  for (unsigned int n = 0; n < nchain; ++n) {
      std::ostringstream outstream;
    outstream << stem << n << ".out";
    std::string outname = outstream.str();
    std::ofstream out(outname.c_str());
    if (!out) {
      std::cerr << "Failed to open file " << outname << std::endl;
      return;
    }
    std::ostringstream indstream;
    indstream << stem << n << ".ind";
    std::string indname = indstream.str();
    std::ofstream ind(indname.c_str());
    if (!ind) {
      std::cerr << "Failed to open file " << indname << std::endl;
      out.close();
      return;
    }

    if (var->parameters().empty()) {
      console->coda(var->name(), Range(), out, ind, n);
    }
    else {
      console->coda(var->name(), getRange(var), out, ind, n);
    }
    out.close();
    ind.close();
  }
}
*/

void doAllCoda (std::string const &stem)
{

    /* Open index file */
    std::ostringstream indstream;
    indstream << stem << "index.txt";
    std::string indname = indstream.str();
    std::ofstream ind(indname.c_str());
    if (!ind) {
      std::cerr << "Failed to open file " << indname << std::endl;
      return;
    }

    std::vector<std::ofstream*> output;
    for (unsigned int n = 0; n < console->nchain(); ++n) {
	/* Open output file */
	std::ostringstream outstream;
	outstream << stem << "chain" << n + 1 << ".txt";
	std::string outname = outstream.str();
	std::ofstream *out = new std::ofstream(outname.c_str());
        if (*out) {
            output.push_back(out);
        }
	else {
	    ind.close();
	    for (unsigned int i = 0; i < output.size(); ++i) {
		output[i]->close();
	    }
	    std::cerr << "Failed to open file " << outname << std::endl;
	    return;
	}
    }
    console->coda(ind, output);
    ind.close();
    for (unsigned int i = 0; i < output.size(); ++i) {
	output[i]->close();
        delete output[i];
    }
}

void doCoda (ParseTree const *var, std::string const &stem)
{

    /* Open index file */
    std::ostringstream indstream;
    indstream << stem << "index.txt";
    std::string indname = indstream.str();
    std::ofstream ind(indname.c_str());
    if (!ind) {
      std::cerr << "Failed to open file " << indname << std::endl;
      return;
    }

    std::vector<std::ofstream*> output;
    for (unsigned int n = 0; n < console->nchain(); ++n) {
	/* Open output file */
	std::ostringstream outstream;
	outstream << stem << "chain" << n + 1 << ".txt";
	std::string outname = outstream.str();
	std::ofstream *out = new std::ofstream(outname.c_str());

        if (*out) {
            output.push_back(out);
        }
        else {
            ind.close();
            for (unsigned int i = 0; i < output.size(); ++i) {
                output[i]->close();
            }
            std::cerr << "Failed to open file " << outname << std::endl;
            return;
        }
    }

    //FIXME: Allow list of several nodes

    std::vector<std::pair<std::string, Range> > dmp;
    if (var->parameters().empty()) {
	/* Requesting the whole node */
	dmp.push_back(std::pair<std::string,Range>(var->name(), Range()));
    }
    else {
	/* Requesting subset of a multivariate node */
	dmp.push_back(std::pair<std::string,Range>(var->name(), getRange(var)));
    }
    console->coda(dmp, ind, output);

    ind.close();
    for (unsigned int i = 0; i < output.size(); ++i) {
	output[i]->close();
        delete output[i];
    }
}

/* Helper function for doDump that handles all the special cases
   (missing values etc) when writing a double value */
static void writeValue(double x, std::ostream &out, bool isdiscrete)
{
  using namespace std;

  if (x == JAGS_NA) {
    out << "NA";
  }
  else if (jags_isnan(x)) {
    out << "NaN";
  }
  else if (!jags_finite(x)) {
    if (x > 0)
      out << "Inf";
    else
      out << "-Inf";
  }
  else if (isdiscrete) {
      out << static_cast<int>(x) << "L";
  }
  else {
    out << x;
  }
}

void doDump(std::string const &file, DumpType type, unsigned int chain)
{
    std::map<std::string,SArray> data_table;
    std::string rng_name;
    if (!console->dumpState(data_table, rng_name, type, chain)) {
	return;
    }

    /* Open output file */
    std::ofstream out(file.c_str());
    if (!out) {
	std::cerr << "Failed to open file " << file << std::endl;
	return;
    }
  
    if (rng_name.size() != 0) {
	out << "`.RNG.name` <- \"" << rng_name << "\"\n";
    }

    for (std::map<std::string, SArray>::const_iterator p = data_table.begin();
	 p != data_table.end(); ++p) {
	std::string const &name = p->first;
	SArray const &sarray = p->second;
	std::vector<double> const &value = sarray.value();
	long length = sarray.length();
	out << "`" << name << "` <- " << std::endl;
	std::vector<unsigned int> const &dim = sarray.dim(false);
	bool discrete = sarray.isDiscreteValued();

	if (dim.size() == 1) {
	    // Vector 
	    if (dim[0] == 1) {
		// Scalar
		writeValue(value[0], out, discrete);
	    }
	    else {
		// Vector of length > 1
		out << "c(";
		for (int i = 0; i < length; ++i) {
		    if (i > 0) {
			out << ",";
		    }
		    writeValue(value[i], out, discrete);
		}
		out << ")";
	    }
	}
	else {
	    // Array 
	    out << "structure(c(";
	    for (int i = 0; i < length; ++i) {
		if (i > 0) {
		    out << ",";
		}
		writeValue(value[i], out, discrete);
	    }
	    out << "), .Dim = c(";
	    for (unsigned int j = 0; j < dim.size(); ++j) {
		if (j > 0) {
		    out << ",";
		}
		out << dim[j] << "L";
	    }
	    out << "))";
	}
	out << "\n";
    }
    out.close();
}  

void dumpMonitors(std::string const &file, std::string const &type)
{
    std::map<std::string,SArray> data_table;
    std::map<std::string,unsigned int> weight_table;

    if (!console->dumpMonitors(data_table, weight_table, type)) {
	return;
    }

    /* Open output file */
    std::ofstream out(file.c_str());
    if (!out) {
	std::cerr << "Failed to open file " << file << std::endl;
	return;
    }

    out << "`" << type << "` <-\nstructure(list(";

    std::map<std::string, SArray>::const_iterator p;
    for (p = data_table.begin(); p != data_table.end(); ++p) {
	std::string const &name = p->first;
	SArray const &sarray = p->second;
	std::vector<double> const &value = sarray.value();
	long length = sarray.length();

	if (p != data_table.begin()) {
	    out << ", \n";
	}
	out << "\"" << name << "\" = ";
	std::vector<unsigned int> const &dim = sarray.dim(false);
	bool discrete = sarray.isDiscreteValued();
	bool named = !sarray.dimNames().empty();

	if (dim.size() == 1 && !named) {
	    // Vector 
	    if (dim[0] == 1) {
		// Scalar
		writeValue(value[0], out, discrete);
	    }
	    else {
		// Vector of length > 1
		out << "c(";
		for (int i = 0; i < length; ++i) {
		    if (i > 0) {
			out << ",";
		    }
		    writeValue(value[i], out, discrete);
		}
		out << ")";
	    }
	}
	else {
	    // Array 
	    out << "structure(c(";
	    for (int i = 0; i < length; ++i) {
		if (i > 0) {
		    out << ",";
		}
		writeValue(value[i], out, discrete);
	    }
	    out << "), .Dim = ";
	    if (named) {
		out << "structure(";
	    }
	    out << "c(";
	    for (unsigned int j = 0; j < dim.size(); ++j) {
		if (j > 0) {
		    out << ",";
		}
		out << dim[j] << "L";
	    }
	    out << ")";
	    if (named) {
		std::vector<std::string> const &dnames = sarray.dimNames();
		out << ", .Names = c(";
		for (unsigned int k = 0; k < dnames.size(); ++k) {
		    if (k > 0) {
			out << ",";
		    }
		    out << "\"" << dnames[k] << "\"";
		}
		out << "))";
	    }
	    out << ")";
	}
    }

    out << "), \n.Names = c(";
    for (p = data_table.begin(); p != data_table.end(); ++p) {
	if (p != data_table.begin()) {
	    out << ", ";
	}
	std::string const &name = p->first;
	out << "\"" << name << "\"";
    }
    out << "))";
    out.close();
}

void setParameters(ParseTree *p, std::vector<ParseTree*> *parameters)
{
  /* 
     The parser dynamically allocates vectors of (pointers to)
     parameters. These vectors must be deleted when we are done with
     them.
  */
  p->setParameters(*parameters);
  delete parameters; 
}

void setParameters(ParseTree *p, ParseTree *param1)
{
  /*
    Wrapper function that creates a vector containing param1
    to be passed to ParseTree::setParameters.
  */
  std::vector<ParseTree *> parameters(1, param1);
  p->setParameters(parameters);
}

void setParameters(ParseTree *p, ParseTree *param1, ParseTree *param2)
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

void setName(ParseTree *p, std::string *name)
{
  p->setName(*name);
  delete name;
}

static void errordump()
{
  if (console->model()) {
    std::ostringstream fname;
    for (unsigned int i = 1; i <= console->nchain(); ++i) {
       fname << "jags.dump" << i << ".R";
       std::cout << "Dumping chain " << i << " at iteration " 
                 << console->iter() << " to file " << fname.str() << std::endl;
       doDump(fname.str(), DUMP_ALL, i);
       fname.str("");
    }
  }
}

static void updatestar(long niter, long refresh, int width)
{
    bool adapt = console->isAdapting();
	
    if (refresh == 0) {
	console->update(niter/2);
	bool status = true;
	if (adapt && !console->adaptOff(status)) {
	    errordump();
	    return;
	}
	console->update(niter - niter/2);
	if (!status) {
	    std::cerr << "WARNING: Adaptation incomplete\n";
	}
	return;
    }

    if (width > niter / refresh + 1)
	width = niter / refresh + 1;

    std::cout << "Updating " << niter << std::endl;
    for (int i = 0; i < width - 1; ++i) {
	std::cout << "-";
    }
    std::cout << "| " << std::min(width * refresh, niter) << std::endl 
	      << std::flush;

    int col = 0;
    bool status = true;
    for (long n = niter; n > 0; n -= refresh) {
	if (adapt && n <= niter/2) {
	    // Turn off adaptive mode half way through burnin
	    if (console->adaptOff(status)) {
		adapt = false;
	    }
	    else {
		std::cout << std::endl;
		errordump();
		return;
	    }
	}
	long nupdate = std::min(n, refresh);
	if(console->update(nupdate))
	    std::cout << "*" << std::flush;
	else {
	    std::cout << std::endl;
	    errordump();
	    return;
	}
	col++;
	if (col == width || n <= nupdate) {
	    int percent = 100 - (n-nupdate) * 100/niter;
	    std::cout << " " << percent << "%" << std::endl;
	    if (n > nupdate) {
		col = 0;
	    }
	}
    }
    if (!status) {
	std::cerr << "WARNING: Adaptation incomplete\n";
    }
}

static void adaptstar(long niter, long refresh, int width)
{
    if (!console->isAdapting()) {
	std::cerr << "ERROR: Model is not in adaptive mode\n";
    }
	
    bool status = true;
    if (refresh == 0) {
	console->update(niter);
	if (!console->adaptOff(status)) {
	    errordump();
	    return;
	}
	if (!status) {
	    std::cerr << "WARNING: Adaptation incomplete\n";
	}
	return;
    }

    if (width > niter / refresh + 1)
	width = niter / refresh + 1;

    std::cout << "Adapting " << niter << std::endl;
    for (int i = 0; i < width - 1; ++i) {
	std::cout << "-";
    }
    std::cout << "| " << std::min(width * refresh, niter) << std::endl 
	      << std::flush;

    int col = 0;
    for (long n = niter; n > 0; n -= refresh) {
	long nupdate = std::min(n, refresh);
	if(console->update(nupdate))
	    std::cout << "+" << std::flush;
	else {
	    std::cout << std::endl;
	    errordump();
	    return;
	}
	col++;
	if (col == width || n <= nupdate) {
	    int percent = 100 - (n-nupdate) * 100/niter;
	    std::cout << " " << percent << "%" << std::endl;
	    if (n > nupdate) {
		col = 0;
	    }
	}
    }
    if (!console->adaptOff(status)) {
	std::cout << std::endl;
	errordump();
	return;
    }
    if (!status) {
	std::cerr << "WARNING: Adaptation incomplete\n";
    }
}

static void loadModule(std::string const &name)
{
  //Record number of masked distributions before loading module
  std::list<Distribution const *> const &masked_dist = 
     Compiler::distTab().masked();
  unsigned int n_dist = masked_dist.size(); 
  lt_dlhandle mod = lt_dlopenext(name.c_str());
  if (mod == NULL) {
      std::cout << lt_dlerror() << std::endl;
  }
  else {
      _modules.push_front(mod);
      std::cout << "Loading module: " << name << std::endl;
      //Warn about newly masked distributions
      if (masked_dist.size() > n_dist) {
	  std::cerr << "Warning: the following distributions were masked "
		    << "by module " << name << ":\n";
	  std::list<Distribution const *>::const_iterator p = 
             masked_dist.begin();
	  for(unsigned int i = masked_dist.size(); i > n_dist; --i, ++p) {
	      std::cerr << (*p)->name() << "\n";
	  }
	  std::cerr << std::endl;
      }
  }
}

int main (int argc, char **argv)
{
  extern std::FILE *zzin;

  std::FILE *cmdfile = 0;
  if (argc > 2) {
    std::cerr << "Too many arguments" << std::endl;
  }
  else if (argc == 2) {
    interactive = false;
    cmdfile = std::fopen(argv[1],"r");
    if (cmdfile) {
      zzin = cmdfile;
    }
    else {
      std::cerr << "Unable to open command file " << argv[1] << std::endl;
      return 1;
    }
  }
  else {
    interactive = true;
  }

  /* Allows emulation of dynamic loading on platforms that do not
     support it by preloading modules */
  LTDL_SET_PRELOADED_SYMBOLS();

  if(lt_dlinit()) {
      std::cerr << lt_dlerror() << std::endl;
      return 1;
  }

  /*
  pt2Func load_base = (pt2Func)(lt_dlsym(base, "load"));
  if (load_base == NULL) {
      std::cout << lt_dlerror() << std::endl;
      return 1;
  }
  else{
      (*load_base)();
  }
  */
  
  time_t t;
  time(&t);
  std::cout << "Welcome to " << PACKAGE_STRING << " on " << ctime(&t);
  std::cout << "JAGS is free software and comes with ABSOLUTELY NO WARRANTY" 
            << std::endl;
  loadModule("basemod");
  loadModule("bugs");

  console = new Console(std::cout, std::cerr);

  zzparse();
  zzlex_destroy();

  if (argc==2) {
      std::fclose(cmdfile);
  }
  delete console;
  //We have to unload modules *AFTER* deleting the console. 
  for (unsigned int i = 0; i < _modules.size(); ++i) {
      lt_dlclose(_modules[i]);
  }
  lt_dlexit();
}

static bool getWorkingDirectory(std::string &name)
{
    char buf[PATH_MAX];
    if (getcwd(buf, PATH_MAX)) {
	name = buf;
	return true;
    }
    else {
	switch(errno) {
	case EACCES:
	    name = "Access denied";
	    break;
	case ENOENT:
	    name = "Not found";
	    break;
	case ERANGE:
	    name = "Directory name too long";
	    break;
	default:
	    name = "Error in getcwd";
	    break;
	}
	return false;
    }
}

static void dumpSamplers(std::string const &file)
{
    std::ofstream out(file.c_str());
    if (!out) {
	std::cerr << "Failed to open file " << file << std::endl;
	return;
    }

    std::vector<std::vector<std::string> > sampler_list;
    console->dumpSamplers(sampler_list);
    for (unsigned int i = 0; i < sampler_list.size(); ++i) {
	for (unsigned int j = 1; j < sampler_list[i].size(); ++j) {
	    out << i + 1 << "\t" 
		<< sampler_list[i][0] << "\t" //First element is sampler name
		<< sampler_list[i][j] << "\n"; //Rest are node names
	}
    }

    out.close();
}

static void delete_pvec(std::vector<ParseTree*> *pv)
{
    for (unsigned int i = 0; i < pv->size(); ++i) {
	delete (*pv)[i];
    }
    delete pv;
}

static void print_unused_variables()
{
    std::vector<std::string> data_vars;
    for (std::map<std::string, SArray>::const_iterator p = _data_table.begin();
	 p != _data_table.end(); ++p)
    {
	data_vars.push_back(p->first);
    }
    
    std::vector<std::string> unused_vars;
    std::vector<std::string> const &model_vars = console->variableNames();

    std::set_difference(data_vars.begin(), data_vars.end(),
			model_vars.begin(), model_vars.end(),
			std::inserter(unused_vars, unused_vars.begin()));

    if (!unused_vars.empty()) {
	std::cerr << "\nWARNING: Unused variable(s) in data table:\n";
	std::copy(unused_vars.begin(), unused_vars.end(),
		  std::ostream_iterator<std::string>(std::cerr, "\n"));
	std::cerr << "\n";
    }

}

void doSystem(std::string const *command)
{
    std::system(command->c_str());
}

