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

/* Substitute the type names.  */
#define YYSTYPE         ZZSTYPE
/* Substitute the variable and function names.  */
#define yyparse         zzparse
#define yylex           zzlex
#define yyerror         zzerror
#define yydebug         zzdebug
#define yynerrs         zznerrs
#define yylval          zzlval
#define yychar          zzchar

/* First part of user prologue.  */
#line 3 "../../../../mcmc-jags/src/terminal/parser.yy"

#include <config.h>

#ifdef Win32
#include <windows.h>   /* For getCurrentDirectory */
#include <io.h>        /* For chdir */
#else
#include <unistd.h>    /* For getcwd, chdir */
#endif

//#include <limits.h>

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
#include <string>
#include <utility>

#include <dirent.h>
#include <time.h>
#include <errno.h>

#include <Console.h>
#include <module/Module.h>
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
    static jags::Console *console;
    bool interactive;
    extern int command_buffer_count;
    void setName(jags::ParseTree *p, std::string *name);
    std::map<std::string, jags::SArray> _data_table;
    std::deque<lt_dlhandle> _dyn_lib;
    bool open_data_buffer(std::string const *name);
    bool open_command_buffer(std::string const *name);
    void return_to_main_buffer();
    void setMonitor(jags::ParseTree const *var, std::string const &stat, std::string const &summary, int thin);
    void clearMonitor(jags::ParseTree const *var, std::string const &stat, std::string const &summary);
    void doCoda (jags::ParseTree const *var, std::string const &stem, std::string const &stat, std::string const &summary);
    void doAllCoda (std::string const &stem, std::string const &stat, std::string const &summary);
    void dumpNodeNames (std::string const &file, std::string const &type);
    void doDump (std::string const &file, jags::ValueType type, unsigned int chain);
    void dumpMonitors(std::string const &file, std::string const &stat, std::string const &summary);
    void doSystem(std::string const *command);
    std::string ExpandFileName(char const *s);

    static bool getWorkingDirectory(std::string &name);
    static void errordump();
    static void updatestar(long niter, long refresh, int width);
	// Run adaptation phase until adapted, regardless of iterations:
    static void autoadaptstar(long maxiter, long refresh, int width);
    static void adaptstar(long niter, long refresh, int width, bool force);
    static void setParameters(jags::ParseTree *p, jags::ParseTree *param1);
    static void setParameters(jags::ParseTree *p, std::vector<jags::ParseTree*> *parameters);
    static void setParameters(jags::ParseTree *p, jags::ParseTree *param1, jags::ParseTree *param2);
    static void loadModule(std::string const &name);
    static void unloadModule(std::string const &name);
    static void dumpSamplers(std::string const &file);
    static void delete_pvec(std::vector<jags::ParseTree*> *);
    static void print_unused_variables(std::map<std::string, jags::SArray> const &table, bool data);
    static void listFactories(jags::FactoryType type);
	static void listModules();
    static void setFactory(std::string const &name, jags::FactoryType type,
                           std::string const &status);
    static void setSeed(unsigned int seed);
    static bool Jtry(bool ok);
	// Needed for update (and adapt) functions to dump variable states:
    static bool Jtry_dump(bool ok);
	// Note: on !ok, Jtry(_dump) only exits if !interactive and otherwise returns ok, 
	// so the parent function should evaluate the value and return; if appriopriate
    

#line 175 "parser.cc"

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
#ifndef YY_ZZ_PARSER_HH_INCLUDED
# define YY_ZZ_PARSER_HH_INCLUDED
/* Debug traces.  */
#ifndef ZZDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define ZZDEBUG 1
#  else
#   define ZZDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define ZZDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined ZZDEBUG */
#if ZZDEBUG
extern int zzdebug;
#endif

/* Token kinds.  */
#ifndef ZZTOKENTYPE
# define ZZTOKENTYPE
  enum zztokentype
  {
    ZZEMPTY = -2,
    ZZEOF = 0,                     /* "end of file"  */
    ZZerror = 256,                 /* error  */
    ZZUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    DOUBLE = 259,                  /* DOUBLE  */
    NAME = 260,                    /* NAME  */
    STRING = 261,                  /* STRING  */
    SYSCMD = 262,                  /* SYSCMD  */
    ENDCMD = 263,                  /* ENDCMD  */
    MODEL = 264,                   /* MODEL  */
    DATA = 265,                    /* DATA  */
    IN = 266,                      /* IN  */
    TO = 267,                      /* TO  */
    INITS = 268,                   /* INITS  */
    PARAMETERS = 269,              /* PARAMETERS  */
    COMPILE = 270,                 /* COMPILE  */
    INITIALIZE = 271,              /* INITIALIZE  */
    ADAPT = 272,                   /* ADAPT  */
    AUTOADAPT = 273,               /* AUTOADAPT  */
    FORCEADAPT = 274,              /* FORCEADAPT  */
    UPDATE = 275,                  /* UPDATE  */
    BY = 276,                      /* BY  */
    MONITORS = 277,                /* MONITORS  */
    NODENAMES = 278,               /* NODENAMES  */
    MONITOR = 279,                 /* MONITOR  */
    TYPE = 280,                    /* TYPE  */
    SET = 281,                     /* SET  */
    CLEAR = 282,                   /* CLEAR  */
    THIN = 283,                    /* THIN  */
    CODA = 284,                    /* CODA  */
    STEM = 285,                    /* STEM  */
    STAT = 286,                    /* STAT  */
    SUMMARY = 287,                 /* SUMMARY  */
    EXIT = 288,                    /* EXIT  */
    NCHAINS = 289,                 /* NCHAINS  */
    NTHREADS = 290,                /* NTHREADS  */
    CHAIN = 291,                   /* CHAIN  */
    LOAD = 292,                    /* LOAD  */
    UNLOAD = 293,                  /* UNLOAD  */
    SAMPLER = 294,                 /* SAMPLER  */
    SAMPLERS = 295,                /* SAMPLERS  */
    RNGTOK = 296,                  /* RNGTOK  */
    FACTORY = 297,                 /* FACTORY  */
    FACTORIES = 298,               /* FACTORIES  */
    MODULES = 299,                 /* MODULES  */
    SEED = 300,                    /* SEED  */
    LIST = 301,                    /* LIST  */
    STRUCTURE = 302,               /* STRUCTURE  */
    DIM = 303,                     /* DIM  */
    NA = 304,                      /* NA  */
    R_NULL = 305,                  /* R_NULL  */
    DIMNAMES = 306,                /* DIMNAMES  */
    ITER = 307,                    /* ITER  */
    ARROW = 308,                   /* ARROW  */
    ENDDATA = 309,                 /* ENDDATA  */
    ASINTEGER = 310,               /* ASINTEGER  */
    DOTDATA = 311,                 /* DOTDATA  */
    NREP = 312,                    /* NREP  */
    DIRECTORY = 313,               /* DIRECTORY  */
    CD = 314,                      /* CD  */
    PWD = 315,                     /* PWD  */
    RUN = 316,                     /* RUN  */
    ENDSCRIPT = 317                /* ENDSCRIPT  */
  };
  typedef enum zztokentype zztoken_kind_t;
#endif
/* Token kinds.  */
#define ZZEMPTY -2
#define ZZEOF 0
#define ZZerror 256
#define ZZUNDEF 257
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
#define AUTOADAPT 273
#define FORCEADAPT 274
#define UPDATE 275
#define BY 276
#define MONITORS 277
#define NODENAMES 278
#define MONITOR 279
#define TYPE 280
#define SET 281
#define CLEAR 282
#define THIN 283
#define CODA 284
#define STEM 285
#define STAT 286
#define SUMMARY 287
#define EXIT 288
#define NCHAINS 289
#define NTHREADS 290
#define CHAIN 291
#define LOAD 292
#define UNLOAD 293
#define SAMPLER 294
#define SAMPLERS 295
#define RNGTOK 296
#define FACTORY 297
#define FACTORIES 298
#define MODULES 299
#define SEED 300
#define LIST 301
#define STRUCTURE 302
#define DIM 303
#define NA 304
#define R_NULL 305
#define DIMNAMES 306
#define ITER 307
#define ARROW 308
#define ENDDATA 309
#define ASINTEGER 310
#define DOTDATA 311
#define NREP 312
#define DIRECTORY 313
#define CD 314
#define PWD 315
#define RUN 316
#define ENDSCRIPT 317

/* Value type.  */
#if ! defined ZZSTYPE && ! defined ZZSTYPE_IS_DECLARED
union ZZSTYPE
{
#line 101 "../../../../mcmc-jags/src/terminal/parser.yy"

  int intval;
  double val;
  std::string *stringptr;
  jags::ParseTree *ptree;
  std::vector<jags::ParseTree*> *pvec;
  std::vector<double> *vec;
  std::vector<long> *ivec;

#line 370 "parser.cc"

};
typedef union ZZSTYPE ZZSTYPE;
# define ZZSTYPE_IS_TRIVIAL 1
# define ZZSTYPE_IS_DECLARED 1
#endif


extern ZZSTYPE zzlval;


int zzparse (void);


#endif /* !YY_ZZ_PARSER_HH_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_DOUBLE = 4,                     /* DOUBLE  */
  YYSYMBOL_NAME = 5,                       /* NAME  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_SYSCMD = 7,                     /* SYSCMD  */
  YYSYMBOL_ENDCMD = 8,                     /* ENDCMD  */
  YYSYMBOL_MODEL = 9,                      /* MODEL  */
  YYSYMBOL_DATA = 10,                      /* DATA  */
  YYSYMBOL_IN = 11,                        /* IN  */
  YYSYMBOL_TO = 12,                        /* TO  */
  YYSYMBOL_INITS = 13,                     /* INITS  */
  YYSYMBOL_PARAMETERS = 14,                /* PARAMETERS  */
  YYSYMBOL_COMPILE = 15,                   /* COMPILE  */
  YYSYMBOL_INITIALIZE = 16,                /* INITIALIZE  */
  YYSYMBOL_ADAPT = 17,                     /* ADAPT  */
  YYSYMBOL_AUTOADAPT = 18,                 /* AUTOADAPT  */
  YYSYMBOL_FORCEADAPT = 19,                /* FORCEADAPT  */
  YYSYMBOL_UPDATE = 20,                    /* UPDATE  */
  YYSYMBOL_BY = 21,                        /* BY  */
  YYSYMBOL_MONITORS = 22,                  /* MONITORS  */
  YYSYMBOL_NODENAMES = 23,                 /* NODENAMES  */
  YYSYMBOL_MONITOR = 24,                   /* MONITOR  */
  YYSYMBOL_TYPE = 25,                      /* TYPE  */
  YYSYMBOL_SET = 26,                       /* SET  */
  YYSYMBOL_CLEAR = 27,                     /* CLEAR  */
  YYSYMBOL_THIN = 28,                      /* THIN  */
  YYSYMBOL_CODA = 29,                      /* CODA  */
  YYSYMBOL_STEM = 30,                      /* STEM  */
  YYSYMBOL_STAT = 31,                      /* STAT  */
  YYSYMBOL_SUMMARY = 32,                   /* SUMMARY  */
  YYSYMBOL_EXIT = 33,                      /* EXIT  */
  YYSYMBOL_NCHAINS = 34,                   /* NCHAINS  */
  YYSYMBOL_NTHREADS = 35,                  /* NTHREADS  */
  YYSYMBOL_CHAIN = 36,                     /* CHAIN  */
  YYSYMBOL_LOAD = 37,                      /* LOAD  */
  YYSYMBOL_UNLOAD = 38,                    /* UNLOAD  */
  YYSYMBOL_SAMPLER = 39,                   /* SAMPLER  */
  YYSYMBOL_SAMPLERS = 40,                  /* SAMPLERS  */
  YYSYMBOL_RNGTOK = 41,                    /* RNGTOK  */
  YYSYMBOL_FACTORY = 42,                   /* FACTORY  */
  YYSYMBOL_FACTORIES = 43,                 /* FACTORIES  */
  YYSYMBOL_MODULES = 44,                   /* MODULES  */
  YYSYMBOL_SEED = 45,                      /* SEED  */
  YYSYMBOL_LIST = 46,                      /* LIST  */
  YYSYMBOL_STRUCTURE = 47,                 /* STRUCTURE  */
  YYSYMBOL_DIM = 48,                       /* DIM  */
  YYSYMBOL_NA = 49,                        /* NA  */
  YYSYMBOL_R_NULL = 50,                    /* R_NULL  */
  YYSYMBOL_DIMNAMES = 51,                  /* DIMNAMES  */
  YYSYMBOL_ITER = 52,                      /* ITER  */
  YYSYMBOL_ARROW = 53,                     /* ARROW  */
  YYSYMBOL_ENDDATA = 54,                   /* ENDDATA  */
  YYSYMBOL_ASINTEGER = 55,                 /* ASINTEGER  */
  YYSYMBOL_DOTDATA = 56,                   /* DOTDATA  */
  YYSYMBOL_NREP = 57,                      /* NREP  */
  YYSYMBOL_DIRECTORY = 58,                 /* DIRECTORY  */
  YYSYMBOL_CD = 59,                        /* CD  */
  YYSYMBOL_PWD = 60,                       /* PWD  */
  YYSYMBOL_RUN = 61,                       /* RUN  */
  YYSYMBOL_ENDSCRIPT = 62,                 /* ENDSCRIPT  */
  YYSYMBOL_63_ = 63,                       /* ','  */
  YYSYMBOL_64_ = 64,                       /* '('  */
  YYSYMBOL_65_ = 65,                       /* ')'  */
  YYSYMBOL_66_ = 66,                       /* '['  */
  YYSYMBOL_67_ = 67,                       /* ']'  */
  YYSYMBOL_68_ = 68,                       /* '*'  */
  YYSYMBOL_69_ = 69,                       /* ':'  */
  YYSYMBOL_70_ = 70,                       /* ';'  */
  YYSYMBOL_71_ = 71,                       /* '`'  */
  YYSYMBOL_72_ = 72,                       /* '='  */
  YYSYMBOL_73_c_ = 73,                     /* 'c'  */
  YYSYMBOL_YYACCEPT = 74,                  /* $accept  */
  YYSYMBOL_input = 75,                     /* input  */
  YYSYMBOL_line = 76,                      /* line  */
  YYSYMBOL_command = 77,                   /* command  */
  YYSYMBOL_model = 78,                     /* model  */
  YYSYMBOL_data_in = 79,                   /* data_in  */
  YYSYMBOL_data_to = 80,                   /* data_to  */
  YYSYMBOL_data = 81,                      /* data  */
  YYSYMBOL_data_clear = 82,                /* data_clear  */
  YYSYMBOL_parameters_in = 83,             /* parameters_in  */
  YYSYMBOL_parameters_to = 84,             /* parameters_to  */
  YYSYMBOL_parameters = 85,                /* parameters  */
  YYSYMBOL_compile = 86,                   /* compile  */
  YYSYMBOL_initialize = 87,                /* initialize  */
  YYSYMBOL_autoadapt = 88,                 /* autoadapt  */
  YYSYMBOL_forceadapt = 89,                /* forceadapt  */
  YYSYMBOL_adapt = 90,                     /* adapt  */
  YYSYMBOL_update = 91,                    /* update  */
  YYSYMBOL_exit = 92,                      /* exit  */
  YYSYMBOL_var = 93,                       /* var  */
  YYSYMBOL_range_list = 94,                /* range_list  */
  YYSYMBOL_range_element = 95,             /* range_element  */
  YYSYMBOL_monitor = 96,                   /* monitor  */
  YYSYMBOL_monitor_set = 97,               /* monitor_set  */
  YYSYMBOL_monitor_clear = 98,             /* monitor_clear  */
  YYSYMBOL_monitors_to = 99,               /* monitors_to  */
  YYSYMBOL_node_names_to = 100,            /* node_names_to  */
  YYSYMBOL_file_name = 101,                /* file_name  */
  YYSYMBOL_coda = 102,                     /* coda  */
  YYSYMBOL_load = 103,                     /* load  */
  YYSYMBOL_unload = 104,                   /* unload  */
  YYSYMBOL_samplers_to = 105,              /* samplers_to  */
  YYSYMBOL_list_factories = 106,           /* list_factories  */
  YYSYMBOL_list_modules = 107,             /* list_modules  */
  YYSYMBOL_set_factory = 108,              /* set_factory  */
  YYSYMBOL_set_seed = 109,                 /* set_seed  */
  YYSYMBOL_r_compact_sequence = 110,       /* r_compact_sequence  */
  YYSYMBOL_r_assignment_list = 111,        /* r_assignment_list  */
  YYSYMBOL_r_assignment = 112,             /* r_assignment  */
  YYSYMBOL_r_name = 113,                   /* r_name  */
  YYSYMBOL_r_data = 114,                   /* r_data  */
  YYSYMBOL_r_structure = 115,              /* r_structure  */
  YYSYMBOL_r_attribute_list = 116,         /* r_attribute_list  */
  YYSYMBOL_r_dim = 117,                    /* r_dim  */
  YYSYMBOL_r_collection = 118,             /* r_collection  */
  YYSYMBOL_r_integer_collection = 119,     /* r_integer_collection  */
  YYSYMBOL_r_value_collection = 120,       /* r_value_collection  */
  YYSYMBOL_r_value_list = 121,             /* r_value_list  */
  YYSYMBOL_r_value = 122,                  /* r_value  */
  YYSYMBOL_r_real_value = 123,             /* r_real_value  */
  YYSYMBOL_r_int_value = 124,              /* r_int_value  */
  YYSYMBOL_r_na_value = 125,               /* r_na_value  */
  YYSYMBOL_r_generic_attribute = 126,      /* r_generic_attribute  */
  YYSYMBOL_r_discard_vector = 127,         /* r_discard_vector  */
  YYSYMBOL_r_discard_arglist = 128,        /* r_discard_arglist  */
  YYSYMBOL_r_discard_arglist_element = 129, /* r_discard_arglist_element  */
  YYSYMBOL_r_discard_numvector = 130,      /* r_discard_numvector  */
  YYSYMBOL_r_discard_numeric_arglist = 131, /* r_discard_numeric_arglist  */
  YYSYMBOL_r_discard_charvector = 132,     /* r_discard_charvector  */
  YYSYMBOL_r_discard_string_arglist = 133, /* r_discard_string_arglist  */
  YYSYMBOL_get_working_dir = 134,          /* get_working_dir  */
  YYSYMBOL_set_working_dir = 135,          /* set_working_dir  */
  YYSYMBOL_read_dir = 136,                 /* read_dir  */
  YYSYMBOL_run_script = 137                /* run_script  */
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
typedef yytype_int16 yy_state_t;

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
         || (defined ZZSTYPE_IS_TRIVIAL && ZZSTYPE_IS_TRIVIAL)))

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   448

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  380

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


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
      64,    65,    68,     2,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,    70,
       2,    72,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,     2,     2,    71,     2,     2,    73,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if ZZDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   188,   188,   192,   198,   199,   200,   201,   202,   203,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   235,   247,   252,
     260,   266,   272,   284,   290,   316,   330,   333,   337,   343,
     352,   364,   368,   372,   380,   385,   390,   397,   401,   406,
     410,   415,   419,   424,   428,   433,   436,   439,   445,   448,
     453,   454,   457,   458,   461,   465,   469,   473,   477,   482,
     487,   493,   501,   504,   508,   512,   519,   525,   533,   539,
     551,   552,   555,   558,   561,   565,   568,   571,   576,   579,
     582,   589,   594,   599,   605,   611,   618,   625,   633,   641,
     646,   649,   652,   657,   662,   667,   672,   680,   681,   682,
     687,   688,   692,   701,   708,   709,   710,   711,   714,   717,
     722,   723,   726,   729,   733,   739,   740,   743,   744,   745,
     748,   751,   754,   760,   763,   764,   765,   766,   767,   768,
     771,   772,   775,   776,   779,   780,   781,   782,   785,   786,
     787,   788,   791,   792,   795,   796,   801,   812,   820,   844
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if ZZDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "DOUBLE",
  "NAME", "STRING", "SYSCMD", "ENDCMD", "MODEL", "DATA", "IN", "TO",
  "INITS", "PARAMETERS", "COMPILE", "INITIALIZE", "ADAPT", "AUTOADAPT",
  "FORCEADAPT", "UPDATE", "BY", "MONITORS", "NODENAMES", "MONITOR", "TYPE",
  "SET", "CLEAR", "THIN", "CODA", "STEM", "STAT", "SUMMARY", "EXIT",
  "NCHAINS", "NTHREADS", "CHAIN", "LOAD", "UNLOAD", "SAMPLER", "SAMPLERS",
  "RNGTOK", "FACTORY", "FACTORIES", "MODULES", "SEED", "LIST", "STRUCTURE",
  "DIM", "NA", "R_NULL", "DIMNAMES", "ITER", "ARROW", "ENDDATA",
  "ASINTEGER", "DOTDATA", "NREP", "DIRECTORY", "CD", "PWD", "RUN",
  "ENDSCRIPT", "','", "'('", "')'", "'['", "']'", "'*'", "':'", "';'",
  "'`'", "'='", "'c'", "$accept", "input", "line", "command", "model",
  "data_in", "data_to", "data", "data_clear", "parameters_in",
  "parameters_to", "parameters", "compile", "initialize", "autoadapt",
  "forceadapt", "adapt", "update", "exit", "var", "range_list",
  "range_element", "monitor", "monitor_set", "monitor_clear",
  "monitors_to", "node_names_to", "file_name", "coda", "load", "unload",
  "samplers_to", "list_factories", "list_modules", "set_factory",
  "set_seed", "r_compact_sequence", "r_assignment_list", "r_assignment",
  "r_name", "r_data", "r_structure", "r_attribute_list", "r_dim",
  "r_collection", "r_integer_collection", "r_value_collection",
  "r_value_list", "r_value", "r_real_value", "r_int_value", "r_na_value",
  "r_generic_attribute", "r_discard_vector", "r_discard_arglist",
  "r_discard_arglist_element", "r_discard_numvector",
  "r_discard_numeric_arglist", "r_discard_charvector",
  "r_discard_string_arglist", "get_working_dir", "set_working_dir",
  "read_dir", "run_script", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-283)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -283,   123,  -283,     9,    22,  -283,    93,    83,    43,   162,
      49,    56,    75,   125,   141,   145,    94,   142,    81,     0,
      21,  -283,    87,   166,   163,    91,  -283,    87,  -283,    87,
     182,  -283,   183,  -283,  -283,  -283,    19,  -283,  -283,  -283,
      19,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,    87,  -283,    87,
      87,  -283,    87,    87,    87,   158,   136,   131,   132,   133,
     134,    87,    87,   135,   193,   193,   137,   153,   196,   139,
     140,  -283,  -283,  -283,  -283,    87,   143,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,   199,    46,  -283,   152,    55,  -283,
    -283,  -283,  -283,  -283,   144,   146,   148,   187,   188,   190,
     192,   151,   154,   212,   156,   157,    90,   211,   213,  -283,
     191,   194,  -283,   197,   159,  -283,    19,  -283,    10,   160,
     189,   223,   224,   164,   165,   167,   168,   202,   209,  -283,
     -28,  -283,  -283,   169,   207,   155,   172,   173,   176,   178,
     179,   180,   181,   184,  -283,  -283,  -283,  -283,   186,  -283,
     195,   198,  -283,  -283,  -283,  -283,  -283,  -283,  -283,   169,
    -283,   203,   200,   201,    36,   240,   243,   244,   246,   204,
     205,   212,  -283,   212,   206,   208,   210,   248,   247,   249,
     228,   230,    87,    87,    -1,    18,    15,    33,   214,   253,
     222,   255,  -283,   215,   216,   217,   218,   256,   258,  -283,
    -283,   257,   260,   262,   219,   220,   221,   225,   226,   227,
     229,   231,   232,   233,   234,    48,  -283,  -283,   235,    64,
    -283,   268,   236,   238,   239,  -283,  -283,  -283,  -283,   242,
     245,   250,   251,   252,  -283,   241,  -283,   -14,   237,   264,
     272,  -283,  -283,  -283,    30,    57,  -283,  -283,    33,  -283,
     254,  -283,   274,  -283,   259,  -283,  -283,   261,  -283,   263,
     265,   266,   267,   269,   270,  -283,   271,   273,    92,  -283,
    -283,  -283,  -283,   275,   277,   278,   282,  -283,  -283,  -283,
     283,   294,    25,    30,    57,  -283,  -283,   300,   303,   279,
     281,   284,   285,  -283,  -283,   286,   287,  -283,   288,   289,
    -283,  -283,  -283,  -283,  -283,   169,  -283,  -283,   290,   291,
     292,   280,   293,   276,     3,     3,     8,   147,  -283,  -283,
     295,   296,   297,  -283,   298,  -283,    99,  -283,   102,   299,
     301,  -283,  -283,  -283,   103,   107,   306,   308,   309,    25,
       3,  -283,  -283,   175,  -283,   185,  -283,   305,  -283,   302,
     304,   307,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     4,     0,     0,     0,     0,
      51,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,     0,   168,     0,   166,     0,
       0,     3,     0,    10,    11,    12,    40,    13,    14,    15,
      46,    16,    17,    19,    20,    18,    21,    28,    22,    72,
      73,    23,    24,    25,    26,    27,    32,    33,    34,    35,
      36,    30,    31,    29,     7,     6,     9,     0,    38,     0,
       0,    43,     0,     0,     0,     0,     0,    61,    57,    59,
      63,     0,     0,    66,     0,     0,    76,     0,     0,    95,
      92,    90,    91,    98,    99,     0,     0,   104,   167,   169,
       8,     5,   118,   117,     0,     0,   110,     0,     0,    37,
      42,    41,    50,    49,    47,     0,     0,     0,     0,     0,
       0,    86,    88,     0,    74,    82,     0,     0,     0,   108,
       0,     0,   100,     0,     0,    39,     0,   111,     0,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,    68,    71,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   112,   140,   116,     0,   142,
       0,     0,   115,   113,   114,   130,   131,   133,   137,   138,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,    55,     0,     0,     0,     0,     0,     0,    69,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,   138,     0,     0,
     135,     0,     0,     0,     0,    62,    58,    60,    64,     0,
       0,     0,     0,     0,    77,    78,    79,     0,     0,    96,
      93,   103,   101,   102,     0,     0,   123,   132,     0,   134,
       0,    48,     0,    56,     0,    89,    75,    83,    84,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   124,
     125,   136,    45,     0,     0,     0,     0,   107,   106,   105,
       0,     0,     0,     0,     0,   122,    53,     0,     0,     0,
       0,     0,   155,   154,   162,     0,     0,   149,     0,     0,
     143,   144,   146,   129,   128,    70,   126,   127,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,    87,    85,
       0,     0,     0,   156,     0,   152,     0,   150,     0,     0,
       0,   159,   158,   164,     0,     0,     0,     0,     0,     0,
       0,   147,   148,     0,   145,     0,   157,     0,   163,     0,
       0,     0,   153,   151,   161,   160,   165,    81,    97,    94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,    12,
    -283,  -189,  -283,  -283,  -283,  -283,  -283,   -26,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,   310,   317,   -21,  -283,
    -283,  -283,  -283,   -29,  -201,  -283,   112,  -283,  -202,  -283,
    -123,  -283,    17,  -282,   -13,   -37,   -12,  -283,  -283,  -283,
    -283,  -283,  -283,  -283
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    86,
     150,   151,    48,    49,    50,    51,    52,    93,    53,    54,
      55,    56,    57,    58,    59,    60,   152,   105,   106,   107,
     235,   173,   288,   289,   174,   175,   176,   239,   177,   178,
     237,   180,   290,   345,   346,   347,   321,   354,   322,   355,
      61,    62,    63,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     153,    98,   219,    99,   236,   240,   312,   313,   344,   314,
     280,   312,   313,   149,   166,   179,   167,    65,   149,   166,
     320,   149,   166,   231,   102,   103,    83,   281,   312,   313,
      66,   314,    90,   149,   166,   191,   149,   166,   232,   192,
     233,   109,    87,   110,   111,    88,   112,   113,   114,   315,
     316,   102,   103,   317,    72,   121,   122,   168,   318,   169,
     102,   103,   286,   285,   169,   170,   291,   169,   153,   132,
     220,   315,   316,   170,   234,   317,   319,   372,    77,   169,
     318,   349,   169,   171,   137,   170,    83,   137,   171,    89,
     104,   171,    91,    92,    69,    70,   124,   125,   319,   211,
     135,   212,   324,   171,    67,   287,    81,    84,    85,   139,
      71,   265,    75,   266,   323,   165,   136,   104,   156,    76,
      68,   157,   158,     2,     3,   136,   104,   268,    78,   269,
       4,     5,     6,     7,    96,    97,     8,     9,    10,    11,
      12,    13,    14,    15,    79,    16,    17,    18,    80,    19,
     351,   352,    20,   353,    82,   304,    21,   305,   127,   128,
      22,    23,   360,    24,   361,   360,   365,   362,   366,    25,
     367,    94,   368,    73,    74,    95,   229,   230,   351,   352,
     325,    26,    27,    28,    29,    30,   195,   196,   374,   375,
     100,   101,   115,   116,   117,   118,   119,   120,    83,   129,
     126,   123,   130,   131,   134,   138,   133,   140,   143,   144,
     141,   145,   142,   146,   147,   149,   159,   148,   160,   154,
     155,   161,   163,   181,   162,   182,   183,   184,   185,   186,
     164,   187,   188,   189,   190,   194,   197,   198,   193,   208,
     199,   200,   201,   213,   202,   203,   214,   215,   204,   216,
     205,   224,   225,   227,   226,   228,   242,   243,   244,   206,
     251,   249,   207,   250,   209,   252,   210,   253,   217,   218,
     221,   270,   222,   279,   223,   326,   282,   293,   241,   343,
     245,   246,   247,   248,   254,   255,   256,   309,   310,   257,
     258,   294,   259,   295,   260,   283,   261,   262,   263,   311,
     267,   271,   272,   284,   273,   328,   264,   274,   329,   369,
     275,   376,   341,   370,   371,   276,   277,   278,   238,   292,
     340,   327,   348,   373,   350,   342,     0,   296,     0,     0,
     297,   298,   299,   300,   301,     0,     0,     0,     0,     0,
     306,   307,   308,   302,   330,   303,   331,     0,     0,   332,
     334,   335,   336,   337,   333,   338,   339,   108,     0,   356,
     357,   358,     0,   363,     0,     0,   364,   377,     0,   378,
     359,     0,   379,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172
};

static const yytype_int16 yycheck[] =
{
     123,    27,   191,    29,   205,   207,     3,     4,     5,     6,
      24,     3,     4,     3,     4,   138,     6,     8,     3,     4,
     302,     3,     4,    24,     5,     6,     5,    41,     3,     4,
       8,     6,    20,     3,     4,    63,     3,     4,    39,    67,
      41,    67,    42,    69,    70,    45,    72,    73,    74,    46,
      47,     5,     6,    50,    11,    81,    82,    47,    55,    49,
       5,     6,     5,   264,    49,    55,   268,    49,   191,    95,
     193,    46,    47,    55,    56,    50,    73,   359,     3,    49,
      55,    73,    49,    73,   105,    55,     5,   108,    73,    68,
      71,    73,     5,     6,    11,    12,    84,    85,    73,    63,
      54,    65,   303,    73,    11,    48,    12,    26,    27,    54,
      27,    63,    63,    65,   303,   136,    70,    71,    28,    63,
      27,    31,    32,     0,     1,    70,    71,    63,     3,    65,
       7,     8,     9,    10,    43,    44,    13,    14,    15,    16,
      17,    18,    19,    20,     3,    22,    23,    24,     3,    26,
       3,     4,    29,     6,    12,    63,    33,    65,     5,     6,
      37,    38,    63,    40,    65,    63,    63,    65,    65,    46,
      63,     5,    65,    11,    12,    12,   202,   203,     3,     4,
     303,    58,    59,    60,    61,    62,    31,    32,     3,     4,
       8,     8,    34,    57,    63,    63,    63,    63,     5,     3,
      63,    66,    63,    63,     5,    53,    63,    63,    21,    21,
      64,    21,    64,    21,    63,     3,     5,    63,     5,    63,
      63,    30,    25,    63,    30,    36,     3,     3,    64,    64,
      71,    64,    64,    31,    25,    28,    64,    64,    69,    36,
      64,    63,    63,     3,    64,    64,     3,     3,    64,     3,
      64,     3,     5,    25,     5,    25,     3,    35,     3,    64,
       3,     5,    64,     5,    64,     5,    65,     5,    64,    64,
      64,     3,    64,    32,    64,   304,    39,     3,    64,     3,
      65,    65,    65,    65,    65,    65,    65,     5,     5,    64,
      64,    32,    65,    32,    65,    31,    65,    65,    65,     5,
      65,    65,    64,    31,    65,     5,    72,    65,     5,     3,
      65,     6,    32,     5,     5,    65,    65,    65,   206,    65,
      28,   304,   335,   360,   336,    32,    -1,    64,    -1,    -1,
      65,    65,    65,    64,    64,    -1,    -1,    -1,    -1,    -1,
      65,    64,    64,    72,    65,    72,    65,    -1,    -1,    65,
      64,    64,    64,    64,    69,    65,    65,    40,    -1,    64,
      64,    64,    -1,    64,    -1,    -1,    65,    65,    -1,    65,
      72,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,     0,     1,     7,     8,     9,    10,    13,    14,
      15,    16,    17,    18,    19,    20,    22,    23,    24,    26,
      29,    33,    37,    38,    40,    46,    58,    59,    60,    61,
      62,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    96,    97,
      98,    99,   100,   102,   103,   104,   105,   106,   107,   108,
     109,   134,   135,   136,   137,     8,     8,    11,    27,    11,
      12,    27,    11,    11,    12,    63,    63,     3,     3,     3,
       3,    12,    12,     5,    26,    27,    93,    42,    45,    68,
      93,     5,     6,   101,     5,    12,    43,    44,   101,   101,
       8,     8,     5,     6,    71,   111,   112,   113,   111,   101,
     101,   101,   101,   101,   101,    34,    57,    63,    63,    63,
      63,   101,   101,    66,    93,    93,    63,     5,     6,     3,
      63,    63,   101,    63,     5,    54,    70,   112,    53,    54,
      63,    64,    64,    21,    21,    21,    21,    63,    63,     3,
      94,    95,   110,   124,    63,    63,    28,    31,    32,     5,
       5,    30,    30,    25,    71,   112,     4,     6,    47,    49,
      55,    73,   110,   115,   118,   119,   120,   122,   123,   124,
     125,    63,    36,     3,     3,    64,    64,    64,    64,    31,
      25,    63,    67,    69,    28,    31,    32,    64,    64,    64,
      63,    63,    64,    64,    64,    64,    64,    64,    36,    64,
      65,    63,    65,     3,     3,     3,     3,    64,    64,    95,
     124,    64,    64,    64,     3,     5,     5,    25,    25,   101,
     101,    24,    39,    41,    56,   114,   118,   124,   120,   121,
     122,    64,     3,    35,     3,    65,    65,    65,    65,     5,
       5,     3,     5,     5,    65,    65,    65,    64,    64,    65,
      65,    65,    65,    65,    72,    63,    65,    65,    63,    65,
       3,    65,    64,    65,    65,    65,    65,    65,    65,    32,
      24,    41,    39,    31,    31,   118,     5,    48,   116,   117,
     126,   122,    65,     3,    32,    32,    64,    65,    65,    65,
      64,    64,    72,    72,    63,    65,    65,    64,    64,     5,
       5,     5,     3,     4,     6,    46,    47,    50,    55,    73,
     127,   130,   132,    95,   118,   124,   117,   126,     5,     5,
      65,    65,    65,    69,    64,    64,    64,    64,    65,    65,
      28,    32,    32,     3,     5,   127,   128,   129,   128,    73,
     130,     3,     4,     6,   131,   133,    64,    64,    64,    72,
      63,    65,    65,    64,    65,    63,    65,    63,    65,     3,
       5,     5,   127,   129,     3,     4,     6,    65,    65,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    79,
      79,    80,    81,    82,    83,    83,    83,    84,    84,    85,
      85,    86,    86,    86,    87,    87,    87,    88,    88,    89,
      89,    90,    90,    91,    91,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    97,    97,    97,    97,    97,    97,
      97,    97,    98,    98,    98,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   102,   102,   102,   102,   103,   104,
     105,   106,   106,   106,   107,   108,   108,   108,   109,   110,
     111,   111,   111,   112,   112,   112,   112,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   116,   116,   117,   117,
     118,   118,   119,   120,   120,   121,   121,   122,   122,   122,
     123,   124,   125,   126,   127,   127,   127,   127,   127,   127,
     128,   128,   129,   129,   130,   130,   130,   130,   131,   131,
     131,   131,   132,   132,   133,   133,   134,   135,   136,   137
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       1,     3,     3,     2,     3,     8,     1,     3,     8,     3,
       3,     1,     6,    10,     1,     6,     8,     2,     7,     2,
       7,     2,     7,     2,     7,     1,     1,     4,     1,     3,
       1,     1,     1,     1,     3,     8,     2,     7,     7,     7,
      11,    15,     3,     8,     8,    12,     3,    12,     3,     8,
       1,     1,     2,     7,    15,     2,     7,    15,     2,     2,
       3,     7,     7,     7,     2,     9,     9,     9,     3,     3,
       1,     2,     3,     3,     3,     3,     3,     1,     1,     3,
       1,     3,     6,     4,     1,     1,     3,     3,     3,     3,
       1,     1,     4,     1,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     1,     4,     4,     1,
       1,     3,     1,     3,     1,     1,     3,     4,     1,     1,
       3,     3,     1,     4,     1,     3,     1,     2,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = ZZEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == ZZEMPTY)                                        \
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
   Use ZZerror or ZZUNDEF. */
#define YYERRCODE ZZUNDEF


/* Enable debugging if requested.  */
#if ZZDEBUG

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
#else /* !ZZDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !ZZDEBUG */


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

  yychar = ZZEMPTY; /* Cause a token to be read.  */

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
  if (yychar == ZZEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= ZZEOF)
    {
      yychar = ZZEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == ZZerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = ZZUNDEF;
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
  yychar = ZZEMPTY;
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
  case 2: /* input: %empty  */
#line 188 "../../../../mcmc-jags/src/terminal/parser.yy"
              {
    if (interactive && command_buffer_count == 0) 
	std::cout << ". " << std::flush;
}
#line 1764 "parser.cc"
    break;

  case 3: /* input: input line  */
#line 192 "../../../../mcmc-jags/src/terminal/parser.yy"
             {
    if (interactive && command_buffer_count == 0) 
	std::cout << ". " << std::flush;
}
#line 1773 "parser.cc"
    break;

  case 4: /* line: ENDCMD  */
#line 198 "../../../../mcmc-jags/src/terminal/parser.yy"
             {}
#line 1779 "parser.cc"
    break;

  case 5: /* line: command ENDCMD  */
#line 199 "../../../../mcmc-jags/src/terminal/parser.yy"
                 {}
#line 1785 "parser.cc"
    break;

  case 6: /* line: error ENDCMD  */
#line 200 "../../../../mcmc-jags/src/terminal/parser.yy"
               {if(interactive) yyerrok; else exit(1); }
#line 1791 "parser.cc"
    break;

  case 7: /* line: run_script  */
#line 201 "../../../../mcmc-jags/src/terminal/parser.yy"
             {}
#line 1797 "parser.cc"
    break;

  case 8: /* line: ENDSCRIPT ENDCMD  */
#line 202 "../../../../mcmc-jags/src/terminal/parser.yy"
                   {}
#line 1803 "parser.cc"
    break;

  case 9: /* line: SYSCMD ENDCMD  */
#line 203 "../../../../mcmc-jags/src/terminal/parser.yy"
                { doSystem((yyvsp[-1].stringptr)); delete (yyvsp[-1].stringptr);}
#line 1809 "parser.cc"
    break;

  case 37: /* model: MODEL IN file_name  */
#line 235 "../../../../mcmc-jags/src/terminal/parser.yy"
                          {
    std::FILE *file = std::fopen(ExpandFileName(((yyvsp[0].stringptr))->c_str()).c_str(), "r");
    if (!file) {
	std::cerr << "Failed to open file " << *((yyvsp[0].stringptr)) << std::endl;
	if (!interactive) exit(1);
    }
    else {
	Jtry(console->checkModel(file));
	std::fclose(file);
    }
    delete (yyvsp[0].stringptr);
 }
#line 1826 "parser.cc"
    break;

  case 38: /* model: MODEL CLEAR  */
#line 247 "../../../../mcmc-jags/src/terminal/parser.yy"
              {
    console->clearModel();
 }
#line 1834 "parser.cc"
    break;

  case 39: /* data_in: data r_assignment_list ENDDATA  */
#line 252 "../../../../mcmc-jags/src/terminal/parser.yy"
                                        {
    std::string rngname;
    readRData((yyvsp[-1].pvec), _data_table, rngname);
    if (rngname.size() != 0) {
	std::cerr << "WARNING: .RNG.name assignment ignored" << std::endl;
    }
    delete_pvec((yyvsp[-1].pvec));
 }
#line 1847 "parser.cc"
    break;

  case 40: /* data_in: data  */
#line 260 "../../../../mcmc-jags/src/terminal/parser.yy"
       {
    // Failed to open the data file 
    if (!interactive) exit(1);
  }
#line 1856 "parser.cc"
    break;

  case 41: /* data_to: DATA TO file_name  */
#line 266 "../../../../mcmc-jags/src/terminal/parser.yy"
                           {
    doDump(*(yyvsp[0].stringptr), jags::DATA_VALUES, 1);
    delete (yyvsp[0].stringptr);
}
#line 1865 "parser.cc"
    break;

  case 42: /* data: DATA IN file_name  */
#line 272 "../../../../mcmc-jags/src/terminal/parser.yy"
                        {
    if(open_data_buffer((yyvsp[0].stringptr))) {
	std::cout << "Reading data file " << *(yyvsp[0].stringptr) << std::endl;
    }
    else {
	std::cerr << "Unable to open file " << *(yyvsp[0].stringptr) << std::endl << std::flush;
	if (!interactive) exit(1);
    }
    delete (yyvsp[0].stringptr);
 }
#line 1880 "parser.cc"
    break;

  case 43: /* data_clear: DATA CLEAR  */
#line 284 "../../../../mcmc-jags/src/terminal/parser.yy"
                       {
    std::cout << "Clearing data table " << std::endl;
    _data_table.clear();
}
#line 1889 "parser.cc"
    break;

  case 44: /* parameters_in: parameters r_assignment_list ENDDATA  */
#line 291 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    std::map<std::string, jags::SArray> parameter_table;
    std::string rngname;
    readRData((yyvsp[-1].pvec), parameter_table, rngname);
    delete_pvec((yyvsp[-1].pvec));
    /* Set all chains to the same state. If the user sets the
       RNG state in addition to the parameter values then all
       chains will be identical!
    */
    if (console->model() == 0) {
	std::cout << "ERROR: Initial values ignored. "
		  <<  "(You must compile the model first)" << std::endl;
	if (!interactive) exit(1);
    }
    for (unsigned int i = 1; i <= console->nchain(); ++i) {
	/* We have to set the name first, because the state or seed
	   might be embedded in the parameter_table */
	if (rngname.size() != 0) {
	    Jtry(console->setRNGname(rngname, i));
	}
	Jtry(console->setParameters(parameter_table, i));
    }
    print_unused_variables(parameter_table, false);

}
#line 1919 "parser.cc"
    break;

  case 45: /* parameters_in: parameters r_assignment_list ENDDATA ',' CHAIN '(' INT ')'  */
#line 317 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    std::map<std::string, jags::SArray> parameter_table;
    std::string rngname;
    readRData((yyvsp[-6].pvec), parameter_table, rngname);
    delete (yyvsp[-6].pvec);
    /* We have to set the name first, because the state or seed
       might be embedded in the parameter_table */
    if (rngname.size() != 0) {
        Jtry(console->setRNGname(rngname, (yyvsp[-1].intval)));
    }
    Jtry(console->setParameters(parameter_table, (yyvsp[-1].intval)));
    print_unused_variables(parameter_table, false);
}
#line 1937 "parser.cc"
    break;

  case 46: /* parameters_in: parameters  */
#line 330 "../../../../mcmc-jags/src/terminal/parser.yy"
             {}
#line 1943 "parser.cc"
    break;

  case 47: /* parameters_to: PARAMETERS TO file_name  */
#line 333 "../../../../mcmc-jags/src/terminal/parser.yy"
                                       {
    doDump(*(yyvsp[0].stringptr), jags::PARAMETER_VALUES, 1);
    delete (yyvsp[0].stringptr);
}
#line 1952 "parser.cc"
    break;

  case 48: /* parameters_to: PARAMETERS TO file_name ',' CHAIN '(' INT ')'  */
#line 337 "../../../../mcmc-jags/src/terminal/parser.yy"
                                                {
    doDump(*(yyvsp[-5].stringptr), jags::PARAMETER_VALUES, (yyvsp[-1].intval));
    delete (yyvsp[-5].stringptr);
}
#line 1961 "parser.cc"
    break;

  case 49: /* parameters: PARAMETERS IN file_name  */
#line 343 "../../../../mcmc-jags/src/terminal/parser.yy"
                                    {
  if(open_data_buffer((yyvsp[0].stringptr))) {
    std::cout << "Reading parameter file " << *(yyvsp[0].stringptr) << std::endl;
  }
  else {
    std::cerr << "Unable to open file " << *(yyvsp[0].stringptr) << std::endl << std::flush;
  }
  delete (yyvsp[0].stringptr);
}
#line 1975 "parser.cc"
    break;

  case 50: /* parameters: INITS IN file_name  */
#line 352 "../../../../mcmc-jags/src/terminal/parser.yy"
                     {
  /* Legacy option to not break existing scripts */
  if(open_data_buffer((yyvsp[0].stringptr))) {
    std::cout << "Reading initial values file " << *(yyvsp[0].stringptr) << std::endl;
  }
  else {
    std::cerr << "Unable to open file " << *(yyvsp[0].stringptr) << std::endl << std::flush;
  }
  delete (yyvsp[0].stringptr);
}
#line 1990 "parser.cc"
    break;

  case 51: /* compile: COMPILE  */
#line 364 "../../../../mcmc-jags/src/terminal/parser.yy"
                 {
    Jtry(console->compile(_data_table, 1U, true));
    print_unused_variables(_data_table, true);
 }
#line 1999 "parser.cc"
    break;

  case 52: /* compile: COMPILE ',' NCHAINS '(' INT ')'  */
#line 368 "../../../../mcmc-jags/src/terminal/parser.yy"
                                  {
    Jtry(console->compile(_data_table, (yyvsp[-1].intval), true));
    print_unused_variables(_data_table, true);
}
#line 2008 "parser.cc"
    break;

  case 53: /* compile: COMPILE ',' NCHAINS '(' INT ')' NTHREADS '(' INT ')'  */
#line 372 "../../../../mcmc-jags/src/terminal/parser.yy"
                                                       {
    Jtry(console->compile(_data_table, (yyvsp[-5].intval), true));
    console->setNThread((yyvsp[-1].intval));
    print_unused_variables(_data_table, true);
}
#line 2018 "parser.cc"
    break;

  case 54: /* initialize: INITIALIZE  */
#line 380 "../../../../mcmc-jags/src/terminal/parser.yy"
                       {
    if (!console->initialize(10000U, 10000U)) {
	errordump();
    }
}
#line 2028 "parser.cc"
    break;

  case 55: /* initialize: INITIALIZE ',' NREP '(' INT ')'  */
#line 385 "../../../../mcmc-jags/src/terminal/parser.yy"
                                  {
    if (!console->initialize((yyvsp[-1].intval), (yyvsp[-1].intval))) {
	errordump();
    }
}
#line 2038 "parser.cc"
    break;

  case 56: /* initialize: INITIALIZE ',' NREP '(' INT ',' INT ')'  */
#line 390 "../../../../mcmc-jags/src/terminal/parser.yy"
                                          {
    if (!console->initialize((yyvsp[-3].intval), (yyvsp[-1].intval))) {
	errordump();
    }
}
#line 2048 "parser.cc"
    break;

  case 57: /* autoadapt: AUTOADAPT INT  */
#line 397 "../../../../mcmc-jags/src/terminal/parser.yy"
                         {
    long refresh = interactive ? (yyvsp[0].intval)/50 : 0;
    autoadaptstar((yyvsp[0].intval), refresh, 50);
}
#line 2057 "parser.cc"
    break;

  case 58: /* autoadapt: AUTOADAPT INT ',' BY '(' INT ')'  */
#line 401 "../../../../mcmc-jags/src/terminal/parser.yy"
                                   {
    autoadaptstar((yyvsp[-5].intval),(yyvsp[-1].intval), 50);
}
#line 2065 "parser.cc"
    break;

  case 59: /* forceadapt: FORCEADAPT INT  */
#line 406 "../../../../mcmc-jags/src/terminal/parser.yy"
                           {
    long refresh = interactive ? (yyvsp[0].intval)/50 : 0;
    adaptstar((yyvsp[0].intval), refresh, 50, true);
}
#line 2074 "parser.cc"
    break;

  case 60: /* forceadapt: FORCEADAPT INT ',' BY '(' INT ')'  */
#line 410 "../../../../mcmc-jags/src/terminal/parser.yy"
                                    {
    adaptstar((yyvsp[-5].intval),(yyvsp[-1].intval), 50, true);
}
#line 2082 "parser.cc"
    break;

  case 61: /* adapt: ADAPT INT  */
#line 415 "../../../../mcmc-jags/src/terminal/parser.yy"
                 {
    long refresh = interactive ? (yyvsp[0].intval)/50 : 0;
    adaptstar((yyvsp[0].intval), refresh, 50, false);
}
#line 2091 "parser.cc"
    break;

  case 62: /* adapt: ADAPT INT ',' BY '(' INT ')'  */
#line 419 "../../../../mcmc-jags/src/terminal/parser.yy"
                               {
    adaptstar((yyvsp[-5].intval),(yyvsp[-1].intval), 50, false);
}
#line 2099 "parser.cc"
    break;

  case 63: /* update: UPDATE INT  */
#line 424 "../../../../mcmc-jags/src/terminal/parser.yy"
                   {
    long refresh = interactive ? (yyvsp[0].intval)/50 : 0;
    updatestar((yyvsp[0].intval), refresh, 50);
}
#line 2108 "parser.cc"
    break;

  case 64: /* update: UPDATE INT ',' BY '(' INT ')'  */
#line 428 "../../../../mcmc-jags/src/terminal/parser.yy"
                                {
  updatestar((yyvsp[-5].intval),(yyvsp[-1].intval), 50);
}
#line 2116 "parser.cc"
    break;

  case 65: /* exit: EXIT  */
#line 433 "../../../../mcmc-jags/src/terminal/parser.yy"
           { return 0; }
#line 2122 "parser.cc"
    break;

  case 66: /* var: NAME  */
#line 436 "../../../../mcmc-jags/src/terminal/parser.yy"
          {
  (yyval.ptree) = new jags::ParseTree(jags::P_VAR); setName((yyval.ptree), (yyvsp[0].stringptr));
}
#line 2130 "parser.cc"
    break;

  case 67: /* var: NAME '[' range_list ']'  */
#line 439 "../../../../mcmc-jags/src/terminal/parser.yy"
                          {
  (yyval.ptree) = new jags::ParseTree(jags::P_VAR); setName((yyval.ptree), (yyvsp[-3].stringptr));
  setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 2139 "parser.cc"
    break;

  case 68: /* range_list: range_element  */
#line 445 "../../../../mcmc-jags/src/terminal/parser.yy"
                          {
  (yyval.pvec) = new std::vector<jags::ParseTree*>(1, (yyvsp[0].ptree)); 
}
#line 2147 "parser.cc"
    break;

  case 69: /* range_list: range_list ',' range_element  */
#line 448 "../../../../mcmc-jags/src/terminal/parser.yy"
                               {
  (yyval.pvec)=(yyvsp[-2].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 2155 "parser.cc"
    break;

  case 74: /* monitor_set: MONITOR SET var  */
#line 461 "../../../../mcmc-jags/src/terminal/parser.yy"
                              { 
    setMonitor((yyvsp[0].ptree), "value", "trace", 1);
    delete (yyvsp[0].ptree);
}
#line 2164 "parser.cc"
    break;

  case 75: /* monitor_set: MONITOR SET var ',' THIN '(' INT ')'  */
#line 465 "../../../../mcmc-jags/src/terminal/parser.yy"
                                       { 
    setMonitor((yyvsp[-5].ptree), "value", "trace", (yyvsp[-1].intval));
    delete (yyvsp[-5].ptree);
}
#line 2173 "parser.cc"
    break;

  case 76: /* monitor_set: MONITOR var  */
#line 469 "../../../../mcmc-jags/src/terminal/parser.yy"
              {
    setMonitor((yyvsp[0].ptree), "value", "trace", 1);
    delete (yyvsp[0].ptree);
}
#line 2182 "parser.cc"
    break;

  case 77: /* monitor_set: MONITOR var ',' THIN '(' INT ')'  */
#line 473 "../../../../mcmc-jags/src/terminal/parser.yy"
                                   { 
    setMonitor((yyvsp[-5].ptree), "value", "trace", (yyvsp[-1].intval));
    delete (yyvsp[-5].ptree);
}
#line 2191 "parser.cc"
    break;

  case 78: /* monitor_set: MONITOR var ',' STAT '(' NAME ')'  */
#line 477 "../../../../mcmc-jags/src/terminal/parser.yy"
                                     {
    setMonitor((yyvsp[-5].ptree), *(yyvsp[-1].stringptr), "trace", 1);
    delete (yyvsp[-5].ptree);
    delete (yyvsp[-1].stringptr);
}
#line 2201 "parser.cc"
    break;

  case 79: /* monitor_set: MONITOR var ',' SUMMARY '(' NAME ')'  */
#line 482 "../../../../mcmc-jags/src/terminal/parser.yy"
                                       {
    setMonitor((yyvsp[-5].ptree), "value", *(yyvsp[-1].stringptr), 1);
    delete (yyvsp[-5].ptree);
    delete (yyvsp[-1].stringptr);
}
#line 2211 "parser.cc"
    break;

  case 80: /* monitor_set: MONITOR var ',' STAT '(' NAME ')' SUMMARY '(' NAME ')'  */
#line 487 "../../../../mcmc-jags/src/terminal/parser.yy"
                                                         {
    setMonitor((yyvsp[-9].ptree), *(yyvsp[-5].stringptr), *(yyvsp[-1].stringptr), 1); 
    delete (yyvsp[-9].ptree);
    delete (yyvsp[-5].stringptr);
    delete (yyvsp[-1].stringptr);
}
#line 2222 "parser.cc"
    break;

  case 81: /* monitor_set: MONITOR var ',' STAT '(' NAME ')' SUMMARY '(' NAME ')' THIN '(' INT ')'  */
#line 493 "../../../../mcmc-jags/src/terminal/parser.yy"
                                                                          {
    setMonitor((yyvsp[-13].ptree), *(yyvsp[-9].stringptr), *(yyvsp[-5].stringptr), (yyvsp[-1].intval));
    delete (yyvsp[-13].ptree);
    delete (yyvsp[-9].stringptr);
    delete (yyvsp[-5].stringptr);
}
#line 2233 "parser.cc"
    break;

  case 82: /* monitor_clear: MONITOR CLEAR var  */
#line 501 "../../../../mcmc-jags/src/terminal/parser.yy"
                                 {
    clearMonitor((yyvsp[0].ptree), "value", "trace"); delete (yyvsp[0].ptree);
}
#line 2241 "parser.cc"
    break;

  case 83: /* monitor_clear: MONITOR CLEAR var ',' STAT '(' NAME ')'  */
#line 504 "../../../../mcmc-jags/src/terminal/parser.yy"
                                          {
    clearMonitor((yyvsp[-5].ptree), *(yyvsp[-1].stringptr), "trace");
    delete (yyvsp[-1].stringptr);
}
#line 2250 "parser.cc"
    break;

  case 84: /* monitor_clear: MONITOR CLEAR var ',' SUMMARY '(' NAME ')'  */
#line 508 "../../../../mcmc-jags/src/terminal/parser.yy"
                                             {
    clearMonitor((yyvsp[-5].ptree), "value", *(yyvsp[-1].stringptr));
    delete (yyvsp[-1].stringptr);
}
#line 2259 "parser.cc"
    break;

  case 85: /* monitor_clear: MONITOR CLEAR var ',' STAT '(' NAME ')' SUMMARY '(' NAME ')'  */
#line 512 "../../../../mcmc-jags/src/terminal/parser.yy"
                                                               {
    clearMonitor((yyvsp[-9].ptree), *(yyvsp[-5].stringptr), *(yyvsp[-1].stringptr));
    delete (yyvsp[-5].stringptr);
}
#line 2268 "parser.cc"
    break;

  case 86: /* monitors_to: MONITORS TO file_name  */
#line 520 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    dumpMonitors(*(yyvsp[0].stringptr), "value", "trace");
    delete (yyvsp[0].stringptr);
}
#line 2277 "parser.cc"
    break;

  case 87: /* monitors_to: MONITORS TO file_name ',' STAT '(' NAME ')' SUMMARY '(' NAME ')'  */
#line 525 "../../../../mcmc-jags/src/terminal/parser.yy"
                                                                 {
    dumpMonitors(*(yyvsp[-9].stringptr), *(yyvsp[-5].stringptr), *(yyvsp[-1].stringptr));
    delete (yyvsp[-9].stringptr);
    delete (yyvsp[-5].stringptr);
    delete (yyvsp[-1].stringptr);
}
#line 2288 "parser.cc"
    break;

  case 88: /* node_names_to: NODENAMES TO file_name  */
#line 534 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    dumpNodeNames(*(yyvsp[0].stringptr), "all");
    delete (yyvsp[0].stringptr);
}
#line 2297 "parser.cc"
    break;

  case 89: /* node_names_to: NODENAMES TO file_name ',' TYPE '(' NAME ')'  */
#line 539 "../../../../mcmc-jags/src/terminal/parser.yy"
                                             {
    dumpNodeNames(*(yyvsp[-5].stringptr), *(yyvsp[-1].stringptr));
    delete (yyvsp[-5].stringptr);
    delete (yyvsp[-1].stringptr); 
}
#line 2307 "parser.cc"
    break;

  case 90: /* file_name: NAME  */
#line 551 "../../../../mcmc-jags/src/terminal/parser.yy"
                { (yyval.stringptr) = (yyvsp[0].stringptr);}
#line 2313 "parser.cc"
    break;

  case 91: /* file_name: STRING  */
#line 552 "../../../../mcmc-jags/src/terminal/parser.yy"
         { (yyval.stringptr) = (yyvsp[0].stringptr); }
#line 2319 "parser.cc"
    break;

  case 92: /* coda: CODA var  */
#line 555 "../../../../mcmc-jags/src/terminal/parser.yy"
               {
    doCoda ((yyvsp[0].ptree), "CODA", "*", "*"); delete (yyvsp[0].ptree);
}
#line 2327 "parser.cc"
    break;

  case 93: /* coda: CODA var ',' STEM '(' file_name ')'  */
#line 558 "../../../../mcmc-jags/src/terminal/parser.yy"
                                      {
    doCoda ((yyvsp[-5].ptree), *(yyvsp[-1].stringptr), "*", "*"); delete (yyvsp[-5].ptree); delete (yyvsp[-1].stringptr);
}
#line 2335 "parser.cc"
    break;

  case 94: /* coda: CODA var ',' STEM '(' file_name ')' STAT '(' NAME ')' SUMMARY '(' NAME ')'  */
#line 561 "../../../../mcmc-jags/src/terminal/parser.yy"
                                                                             {
    doCoda ((yyvsp[-13].ptree), *(yyvsp[-9].stringptr), *(yyvsp[-5].stringptr), *(yyvsp[-1].stringptr));
    delete (yyvsp[-13].ptree); delete (yyvsp[-9].stringptr); delete (yyvsp[-5].stringptr); delete (yyvsp[-1].stringptr);
}
#line 2344 "parser.cc"
    break;

  case 95: /* coda: CODA '*'  */
#line 565 "../../../../mcmc-jags/src/terminal/parser.yy"
           {
  doAllCoda ("CODA", "*", "*"); 
}
#line 2352 "parser.cc"
    break;

  case 96: /* coda: CODA '*' ',' STEM '(' file_name ')'  */
#line 568 "../../../../mcmc-jags/src/terminal/parser.yy"
                                      {
    doAllCoda (*(yyvsp[-1].stringptr), "*", "*" ); delete (yyvsp[-1].stringptr); 
}
#line 2360 "parser.cc"
    break;

  case 97: /* coda: CODA '*' ',' STEM '(' file_name ')' STAT '(' NAME ')' SUMMARY '(' NAME ')'  */
#line 571 "../../../../mcmc-jags/src/terminal/parser.yy"
                                                                             {
    doAllCoda (*(yyvsp[-9].stringptr), *(yyvsp[-5].stringptr), *(yyvsp[-1].stringptr)); delete (yyvsp[-9].stringptr); delete (yyvsp[-5].stringptr); delete (yyvsp[-1].stringptr);
}
#line 2368 "parser.cc"
    break;

  case 98: /* load: LOAD file_name  */
#line 576 "../../../../mcmc-jags/src/terminal/parser.yy"
                     { loadModule(*(yyvsp[0].stringptr)); }
#line 2374 "parser.cc"
    break;

  case 99: /* unload: UNLOAD NAME  */
#line 579 "../../../../mcmc-jags/src/terminal/parser.yy"
                    { unloadModule(*(yyvsp[0].stringptr)); }
#line 2380 "parser.cc"
    break;

  case 100: /* samplers_to: SAMPLERS TO file_name  */
#line 583 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    dumpSamplers(*(yyvsp[0].stringptr));
    delete (yyvsp[0].stringptr);
}
#line 2389 "parser.cc"
    break;

  case 101: /* list_factories: LIST FACTORIES ',' TYPE '(' SAMPLER ')'  */
#line 590 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    listFactories(jags::SAMPLER_FACTORY);
}
#line 2397 "parser.cc"
    break;

  case 102: /* list_factories: LIST FACTORIES ',' TYPE '(' RNGTOK ')'  */
#line 595 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    listFactories(jags::RNG_FACTORY);
}
#line 2405 "parser.cc"
    break;

  case 103: /* list_factories: LIST FACTORIES ',' TYPE '(' MONITOR ')'  */
#line 600 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    listFactories(jags::MONITOR_FACTORY);
}
#line 2413 "parser.cc"
    break;

  case 104: /* list_modules: LIST MODULES  */
#line 606 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    listModules();
}
#line 2421 "parser.cc"
    break;

  case 105: /* set_factory: SET FACTORY STRING NAME ',' TYPE '(' SAMPLER ')'  */
#line 612 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    setFactory(*(yyvsp[-6].stringptr), jags::SAMPLER_FACTORY, *(yyvsp[-5].stringptr));
    delete (yyvsp[-6].stringptr);
    delete (yyvsp[-5].stringptr);
}
#line 2431 "parser.cc"
    break;

  case 106: /* set_factory: SET FACTORY NAME NAME ',' TYPE '(' RNGTOK ')'  */
#line 619 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    setFactory(*(yyvsp[-6].stringptr), jags::RNG_FACTORY, *(yyvsp[-5].stringptr));
    delete (yyvsp[-6].stringptr);
    delete (yyvsp[-5].stringptr);
}
#line 2441 "parser.cc"
    break;

  case 107: /* set_factory: SET FACTORY NAME NAME ',' TYPE '(' MONITOR ')'  */
#line 626 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    setFactory(*(yyvsp[-6].stringptr), jags::MONITOR_FACTORY, *(yyvsp[-5].stringptr));
    delete (yyvsp[-6].stringptr);
    delete (yyvsp[-5].stringptr);
}
#line 2451 "parser.cc"
    break;

  case 108: /* set_seed: SET SEED INT  */
#line 634 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    setSeed((yyvsp[0].intval));
}
#line 2459 "parser.cc"
    break;

  case 109: /* r_compact_sequence: r_int_value ':' r_int_value  */
#line 641 "../../../../mcmc-jags/src/terminal/parser.yy"
                                                {
    (yyval.ptree) = new jags::ParseTree(jags::P_FUNCTION); (yyval.ptree)->setName(":");
    setParameters((yyval.ptree), (yyvsp[-2].ptree), (yyvsp[0].ptree));
 }
#line 2468 "parser.cc"
    break;

  case 110: /* r_assignment_list: r_assignment  */
#line 646 "../../../../mcmc-jags/src/terminal/parser.yy"
                                {
  (yyval.pvec) = new std::vector<jags::ParseTree*>(1, (yyvsp[0].ptree));
}
#line 2476 "parser.cc"
    break;

  case 111: /* r_assignment_list: r_assignment_list r_assignment  */
#line 649 "../../../../mcmc-jags/src/terminal/parser.yy"
                                 {
  (yyval.pvec) = (yyvsp[-1].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 2484 "parser.cc"
    break;

  case 112: /* r_assignment_list: r_assignment_list ';' r_assignment  */
#line 652 "../../../../mcmc-jags/src/terminal/parser.yy"
                                     {
  (yyval.pvec) = (yyvsp[-2].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree));
}
#line 2492 "parser.cc"
    break;

  case 113: /* r_assignment: r_name ARROW r_structure  */
#line 657 "../../../../mcmc-jags/src/terminal/parser.yy"
                                       {
    (yyval.ptree) = new jags::ParseTree(jags::P_ARRAY);
    setName((yyval.ptree), (yyvsp[-2].stringptr));
    setParameters((yyval.ptree), (yyvsp[0].ptree));
}
#line 2502 "parser.cc"
    break;

  case 114: /* r_assignment: r_name ARROW r_collection  */
#line 662 "../../../../mcmc-jags/src/terminal/parser.yy"
                            {
    (yyval.ptree) = new jags::ParseTree(jags::P_ARRAY);
    setName((yyval.ptree), (yyvsp[-2].stringptr));
    setParameters((yyval.ptree), (yyvsp[0].ptree));
}
#line 2512 "parser.cc"
    break;

  case 115: /* r_assignment: r_name ARROW r_compact_sequence  */
#line 667 "../../../../mcmc-jags/src/terminal/parser.yy"
                                  {
    (yyval.ptree) = new jags::ParseTree(jags::P_ARRAY);
    setName((yyval.ptree), (yyvsp[-2].stringptr));
    setParameters((yyval.ptree), (yyvsp[0].ptree));
}
#line 2522 "parser.cc"
    break;

  case 116: /* r_assignment: r_name ARROW STRING  */
#line 672 "../../../../mcmc-jags/src/terminal/parser.yy"
                      {
    /* Allow this for setting the NAME of the random number generator */
    (yyval.ptree) = new jags::ParseTree(jags::P_ARRAY); setName((yyval.ptree), (yyvsp[-2].stringptr));
    jags::ParseTree *p = new jags::ParseTree(jags::P_VAR); setName(p, (yyvsp[0].stringptr));
    setParameters((yyval.ptree), p);
}
#line 2533 "parser.cc"
    break;

  case 119: /* r_name: '`' NAME '`'  */
#line 682 "../../../../mcmc-jags/src/terminal/parser.yy"
               {
    /* R >= 2.4.0 uses backticks for quoted names */
    (yyval.stringptr) = (yyvsp[-1].stringptr);
}
#line 2542 "parser.cc"
    break;

  case 121: /* r_data: DOTDATA '=' r_collection  */
#line 688 "../../../../mcmc-jags/src/terminal/parser.yy"
                           {
    (yyval.ptree) = (yyvsp[0].ptree);
}
#line 2550 "parser.cc"
    break;

  case 122: /* r_structure: STRUCTURE '(' r_data ',' r_attribute_list ')'  */
#line 692 "../../../../mcmc-jags/src/terminal/parser.yy"
                                                           {
    if ((yyvsp[-1].ptree)) {
	(yyval.ptree) = new jags::ParseTree(jags::P_STRUCT); 
	setParameters((yyval.ptree), (yyvsp[-3].ptree), (yyvsp[-1].ptree));
    }
    else {
	(yyval.ptree) = (yyvsp[-3].ptree);
    }
}
#line 2564 "parser.cc"
    break;

  case 123: /* r_structure: STRUCTURE '(' r_data ')'  */
#line 701 "../../../../mcmc-jags/src/terminal/parser.yy"
                           {
    (yyval.ptree) = (yyvsp[-1].ptree);
}
#line 2572 "parser.cc"
    break;

  case 125: /* r_attribute_list: r_generic_attribute  */
#line 709 "../../../../mcmc-jags/src/terminal/parser.yy"
                      {(yyval.ptree)=0;}
#line 2578 "parser.cc"
    break;

  case 126: /* r_attribute_list: r_attribute_list ',' r_dim  */
#line 710 "../../../../mcmc-jags/src/terminal/parser.yy"
                             {(yyval.ptree)=(yyvsp[0].ptree);}
#line 2584 "parser.cc"
    break;

  case 128: /* r_dim: DIM '=' r_collection  */
#line 714 "../../../../mcmc-jags/src/terminal/parser.yy"
                            {
  (yyval.ptree) = (yyvsp[0].ptree);
}
#line 2592 "parser.cc"
    break;

  case 129: /* r_dim: DIM '=' range_element  */
#line 717 "../../../../mcmc-jags/src/terminal/parser.yy"
                        {
  (yyval.ptree) = (yyvsp[0].ptree);
}
#line 2600 "parser.cc"
    break;

  case 132: /* r_integer_collection: ASINTEGER '(' r_value_collection ')'  */
#line 726 "../../../../mcmc-jags/src/terminal/parser.yy"
                                                           {(yyval.ptree) = (yyvsp[-1].ptree);}
#line 2606 "parser.cc"
    break;

  case 133: /* r_value_collection: r_value  */
#line 729 "../../../../mcmc-jags/src/terminal/parser.yy"
                            { 
  (yyval.ptree) = new jags::ParseTree(jags::P_VECTOR); 
  setParameters((yyval.ptree), (yyvsp[0].ptree));
}
#line 2615 "parser.cc"
    break;

  case 134: /* r_value_collection: 'c' '(' r_value_list ')'  */
#line 733 "../../../../mcmc-jags/src/terminal/parser.yy"
                           {
  (yyval.ptree) = new jags::ParseTree(jags::P_VECTOR);
  setParameters((yyval.ptree), (yyvsp[-1].pvec));
}
#line 2624 "parser.cc"
    break;

  case 135: /* r_value_list: r_value  */
#line 739 "../../../../mcmc-jags/src/terminal/parser.yy"
                      {(yyval.pvec) = new std::vector<jags::ParseTree*>(1, (yyvsp[0].ptree)); }
#line 2630 "parser.cc"
    break;

  case 136: /* r_value_list: r_value_list ',' r_value  */
#line 740 "../../../../mcmc-jags/src/terminal/parser.yy"
                           {(yyval.pvec) = (yyvsp[-2].pvec); (yyval.pvec)->push_back((yyvsp[0].ptree));}
#line 2636 "parser.cc"
    break;

  case 140: /* r_real_value: DOUBLE  */
#line 748 "../../../../mcmc-jags/src/terminal/parser.yy"
                     {(yyval.ptree) = new jags::ParseTree(jags::P_VALUE); (yyval.ptree)->setValue((yyvsp[0].val));}
#line 2642 "parser.cc"
    break;

  case 141: /* r_int_value: INT  */
#line 751 "../../../../mcmc-jags/src/terminal/parser.yy"
                 {(yyval.ptree) = new jags::ParseTree(jags::P_VALUE); (yyval.ptree)->setValue((yyvsp[0].intval));}
#line 2648 "parser.cc"
    break;

  case 142: /* r_na_value: NA  */
#line 754 "../../../../mcmc-jags/src/terminal/parser.yy"
               {(yyval.ptree) = new jags::ParseTree(jags::P_VALUE); (yyval.ptree)->setValue(JAGS_NA);}
#line 2654 "parser.cc"
    break;

  case 143: /* r_generic_attribute: NAME '=' r_discard_vector  */
#line 760 "../../../../mcmc-jags/src/terminal/parser.yy"
                                               {}
#line 2660 "parser.cc"
    break;

  case 144: /* r_discard_vector: r_discard_numvector  */
#line 763 "../../../../mcmc-jags/src/terminal/parser.yy"
                                      {}
#line 2666 "parser.cc"
    break;

  case 145: /* r_discard_vector: ASINTEGER '(' r_discard_numvector ')'  */
#line 764 "../../../../mcmc-jags/src/terminal/parser.yy"
                                        {}
#line 2672 "parser.cc"
    break;

  case 146: /* r_discard_vector: r_discard_charvector  */
#line 765 "../../../../mcmc-jags/src/terminal/parser.yy"
                       {}
#line 2678 "parser.cc"
    break;

  case 147: /* r_discard_vector: LIST '(' r_discard_arglist ')'  */
#line 766 "../../../../mcmc-jags/src/terminal/parser.yy"
                                 {}
#line 2684 "parser.cc"
    break;

  case 148: /* r_discard_vector: STRUCTURE '(' r_discard_arglist ')'  */
#line 767 "../../../../mcmc-jags/src/terminal/parser.yy"
                                      {}
#line 2690 "parser.cc"
    break;

  case 149: /* r_discard_vector: R_NULL  */
#line 768 "../../../../mcmc-jags/src/terminal/parser.yy"
         {}
#line 2696 "parser.cc"
    break;

  case 150: /* r_discard_arglist: r_discard_arglist_element  */
#line 771 "../../../../mcmc-jags/src/terminal/parser.yy"
                                             {}
#line 2702 "parser.cc"
    break;

  case 151: /* r_discard_arglist: r_discard_arglist ',' r_discard_arglist_element  */
#line 772 "../../../../mcmc-jags/src/terminal/parser.yy"
                                                  {}
#line 2708 "parser.cc"
    break;

  case 152: /* r_discard_arglist_element: r_discard_vector  */
#line 775 "../../../../mcmc-jags/src/terminal/parser.yy"
                                            {}
#line 2714 "parser.cc"
    break;

  case 153: /* r_discard_arglist_element: NAME '=' r_discard_vector  */
#line 776 "../../../../mcmc-jags/src/terminal/parser.yy"
                            {}
#line 2720 "parser.cc"
    break;

  case 154: /* r_discard_numvector: DOUBLE  */
#line 779 "../../../../mcmc-jags/src/terminal/parser.yy"
                            {}
#line 2726 "parser.cc"
    break;

  case 155: /* r_discard_numvector: INT  */
#line 780 "../../../../mcmc-jags/src/terminal/parser.yy"
      {}
#line 2732 "parser.cc"
    break;

  case 156: /* r_discard_numvector: INT ':' INT  */
#line 781 "../../../../mcmc-jags/src/terminal/parser.yy"
              {}
#line 2738 "parser.cc"
    break;

  case 158: /* r_discard_numeric_arglist: DOUBLE  */
#line 785 "../../../../mcmc-jags/src/terminal/parser.yy"
                                  {}
#line 2744 "parser.cc"
    break;

  case 159: /* r_discard_numeric_arglist: INT  */
#line 786 "../../../../mcmc-jags/src/terminal/parser.yy"
      {}
#line 2750 "parser.cc"
    break;

  case 160: /* r_discard_numeric_arglist: r_discard_numeric_arglist ',' DOUBLE  */
#line 787 "../../../../mcmc-jags/src/terminal/parser.yy"
                                       {}
#line 2756 "parser.cc"
    break;

  case 161: /* r_discard_numeric_arglist: r_discard_numeric_arglist ',' INT  */
#line 788 "../../../../mcmc-jags/src/terminal/parser.yy"
                                    {}
#line 2762 "parser.cc"
    break;

  case 162: /* r_discard_charvector: STRING  */
#line 791 "../../../../mcmc-jags/src/terminal/parser.yy"
                             {}
#line 2768 "parser.cc"
    break;

  case 163: /* r_discard_charvector: 'c' '(' r_discard_string_arglist ')'  */
#line 792 "../../../../mcmc-jags/src/terminal/parser.yy"
                                       {}
#line 2774 "parser.cc"
    break;

  case 164: /* r_discard_string_arglist: STRING  */
#line 795 "../../../../mcmc-jags/src/terminal/parser.yy"
                                 {}
#line 2780 "parser.cc"
    break;

  case 165: /* r_discard_string_arglist: r_discard_string_arglist ',' STRING  */
#line 796 "../../../../mcmc-jags/src/terminal/parser.yy"
                                      {}
#line 2786 "parser.cc"
    break;

  case 166: /* get_working_dir: PWD  */
#line 802 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    std::string name;
    if (getWorkingDirectory(name)) {
	std::cout << name << std::endl;
    }
    else {
	std::cout << "ERROR: " << name << std::endl;
    }
}
#line 2800 "parser.cc"
    break;

  case 167: /* set_working_dir: CD file_name  */
#line 813 "../../../../mcmc-jags/src/terminal/parser.yy"
{
    if (chdir(((yyvsp[0].stringptr))->c_str()) == -1) {
	std::cout << "ERROR: Cannot change working directory" << std::endl;
    }
    delete (yyvsp[0].stringptr);
}
#line 2811 "parser.cc"
    break;

  case 168: /* read_dir: DIRECTORY  */
#line 821 "../../../../mcmc-jags/src/terminal/parser.yy"
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
#line 2838 "parser.cc"
    break;

  case 169: /* run_script: RUN file_name  */
#line 844 "../../../../mcmc-jags/src/terminal/parser.yy"
                          {
    if(open_command_buffer((yyvsp[0].stringptr))) {
	std::cout << "Running script file " << *(yyvsp[0].stringptr) << std::endl;
    }
    else {
	std::cerr << "Unable to open script file " << *(yyvsp[0].stringptr) << std::endl;
    }
    delete (yyvsp[0].stringptr);
 }
#line 2852 "parser.cc"
    break;


#line 2856 "parser.cc"

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
  yytoken = yychar == ZZEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
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

      if (yychar <= ZZEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == ZZEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = ZZEMPTY;
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
  if (yychar != ZZEMPTY)
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

#line 855 "../../../../mcmc-jags/src/terminal/parser.yy"


int zzerror (const char *s)
{
    return_to_main_buffer();
    std::cerr << s << std::endl;
    return 0;
}

static jags::Range getRange(jags::ParseTree const *var)
{
  /* 
     Blank arguments, e.g. foo[] or bar[,1]  are not allowed.
  */
  unsigned int size = var->parameters().size();

  std::vector<unsigned long>  ind_lower(size), ind_upper(size);
  for (unsigned int i = 0; i < size; ++i) {
    jags::ParseTree const *range_element = var->parameters()[i];
    if (range_element->treeClass() == jags::P_VALUE) {
	ind_lower[i] = static_cast<int>(range_element->value());
	ind_upper[i] = ind_lower[i];
    }
    else if (range_element->treeClass() == jags::P_FUNCTION &&
	     range_element->name() == ":")
    {
	ind_lower[i] = static_cast<int>(range_element->parameters()[0]->value());
	ind_upper[i] = static_cast<int>(range_element->parameters()[1]->value());
    }
    else {
	std::cerr << "Unable to parse subset expression for " << var->name() << 
	    ". Taking whole node instead" << std::endl;
	return jags::Range();
    }
  }
  return jags::SimpleRange(ind_lower, ind_upper);
}

void setMonitor(jags::ParseTree const *var, std::string const &stat, std::string const &summary, int thin)
{
    std::string const &name = var->name();
    if (var->parameters().empty()) {
	/* Requesting the whole node */
	console->setMonitor(name, jags::Range(), thin, stat, summary);
    }
    else {
	/* Requesting subset of a multivariate node */
	console->setMonitor(name, getRange(var), thin, stat, summary);
    }
}

void clearMonitor(jags::ParseTree const *var, std::string const &stat, std::string const &summary)
{
    std::string const &name = var->name();
    if (var->parameters().empty()) {
	/* Requesting a whole array */
	console->clearMonitor(name, jags::Range(), stat, summary);
    }
    else {
	/* Requesting subset of an array */
	console->clearMonitor(name, getRange(var), stat, summary);
    }
}

void doAllCoda (std::string const &stem, std::string const &stat, std::string const &summary)
{
    console->coda(stem, stat, summary);
}

void doCoda (jags::ParseTree const *var, std::string const &stem, std::string const &stat, std::string const &summary)
{
    //FIXME: Allow list of several nodes

    std::vector<std::pair<std::string, jags::Range> > dmp;
    if (var->parameters().empty()) {
	/* Requesting the whole node */
	dmp.push_back(std::pair<std::string,jags::Range>(var->name(), jags::Range()));
    }
    else {
	/* Requesting subset of a multivariate node */
	dmp.push_back(std::pair<std::string,jags::Range>(var->name(), getRange(var)));
    }
    console->coda(dmp, stem, stat, summary);
}

/* Helper function for doDump that handles all the special cases
   (missing values etc) when writing a double value */
static void writeValue(double x, std::ostream &out, bool isdiscrete)
{
  using namespace std;

  if (jags_isna(x)) {
    out << "NA";
  }
  else if (isnan(x)) {
    out << "NaN";
  }
  else if (!isfinite(x)) {
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

void doDump(std::string const &file, jags::ValueType type, unsigned int chain)
{
    std::map<std::string,jags::SArray> data_table;
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

    for (std::map<std::string, jags::SArray>::const_iterator p = data_table.begin();
	 p != data_table.end(); ++p) {
	std::string const &name = p->first;
	jags::SArray const &sarray = p->second;
	std::vector<double> const &value = sarray.value();
	long length = sarray.length();
	out << "`" << name << "` <- " << std::endl;
	std::vector<unsigned long> const &dim = sarray.dim(false);
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
	    out << "), dim = c(";
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

void dumpMonitors(std::string const &file, std::string const &stat,
		  std::string const &summary)
{
    std::map<std::string,jags::SArray> data_table;

    if (!console->dumpMonitors(data_table, stat, summary, false)) {
	return;
    }

    /* Open output file */
    std::ofstream out(file.c_str());
    if (!out) {
	std::cerr << "Failed to open file " << file << std::endl;
	return;
    }

    //FIXME: Use recursive list here
    out << "`" << stat << "_" << summary << "` <-\nstructure(list(";

    std::map<std::string, jags::SArray>::const_iterator p;
    for (p = data_table.begin(); p != data_table.end(); ++p) {
	std::string const &name = p->first;
	jags::SArray const &sarray = p->second;
	std::vector<double> const &value = sarray.value();
	long length = sarray.length();

	if (p != data_table.begin()) {
	    out << ", \n";
	}
	out << "\"" << name << "\" = ";
	std::vector<unsigned long> const &dim = sarray.dim(false);
	bool discrete = sarray.isDiscreteValued();
	bool named = !sarray.dimTags().empty();

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
		std::vector<jags::DimTag> const &dnames = sarray.dimTags();
		out << ", .Names = c(";
		for (unsigned int k = 0; k < dnames.size(); ++k) {
		    if (k > 0) {
			out << ",";
		    }
		    out << "\"" << asChar(dnames[k]) << "\"";
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

void dumpNodeNames(std::string const &file, std::string const &type)
{
    std::vector<std::string> node_names;

    /* Open output file */
    std::ofstream out(file.c_str());
    if (!out) {
	std::cerr << "Failed to open file " << file << std::endl;
	return;
    }

	std::vector<std::string> alltypes;
	
	// Special rule for "all" types:
	if ( type == "all" ) {
		alltypes.push_back("constant");
		alltypes.push_back("deterministic");
		alltypes.push_back("stochastic");
		alltypes.push_back("fixed");
		alltypes.push_back("observations");
	}
	else {
		alltypes.push_back(type);
	}
	
	for ( unsigned int i=0; i < alltypes.size(); i++ ){
	
	    out << "`" << alltypes[i] << "` <-\n";
	
		console->dumpNodeNames(node_names, alltypes[i]);

		// If no matching names just write an empty character vector:
	    if ( node_names.size() == 0 ) {
			out << "character(0)\n" << std::endl;
			out.close();
			return;
	    }
	
		out << "c(";
		unsigned int r = 0;
	    for (unsigned int i = 0;  i < node_names.size(); i++) {
			out << "\"" << node_names[i] << "\"";
			if( (i+1) < node_names.size() ) {
				out << ", ";
			}
			r++;
			if( r == 5 ) {
				out << "\n";
				r = 0;
			}
		}
		out << ")\n\n";
	
	}
	
	out.close();
}

static void setParameters(jags::ParseTree *p, std::vector<jags::ParseTree*> *parameters)
{
  /* 
     The parser dynamically allocates vectors of (pointers to)
     parameters. These vectors must be deleted when we are done with
     them.
  */
  p->setParameters(*parameters);
  delete parameters; 
}

static void setParameters(jags::ParseTree *p, jags::ParseTree *param1)
{
  /*
    Wrapper function that creates a vector containing param1
    to be passed to jags::ParseTree::setParameters.
  */
  std::vector<jags::ParseTree *> parameters(1, param1);
  p->setParameters(parameters);
}

static void setParameters(jags::ParseTree *p, jags::ParseTree *param1, jags::ParseTree *param2)
{
  /*
    Wrapper function that creates a vector containing param1
    and param2, to be passed to jags::ParseTree::setParameters
  */
  std::vector<jags::ParseTree *> parameters;
  parameters.push_back(param1);
  parameters.push_back(param2);
  p->setParameters(parameters);
}

void setName(jags::ParseTree *p, std::string *name)
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
		      << console->iter() << " to file " << fname.str() 
		      << std::endl;
	    doDump(fname.str(), jags::ALL_VALUES, i);
	    fname.str("");
	}
	// Moved clearModel from Console.cc CATCH_ERRORS to here
	// to allow doDump to work as described in the manual:
	console->clearModel();
    }
    if (!interactive) exit(1);
}

static void updatestar(long niter, long refresh, int width)
{
    std::cout << "Updating " << niter << std::endl;

    bool adapt = console->isAdapting();
    if (adapt && console->iter() > 0) {
	//Turn off iteration immediately if we have some burn-in
	if (console->adaptOff()) {
	    adapt = false;
	}
	else {
	    std::cout << std::endl;
	    errordump();
	    return;
	}
    }

    if (refresh == 0) {
	if( !Jtry_dump(console->update(niter/2)) ) return;
	bool status = true;
	if (adapt) {
	    if (!console->checkAdaptation(status)) {
		errordump();
		return;
	    }
	    if (!console->adaptOff()) {
		errordump();
		return;
	    }
	}
	if( !Jtry_dump(console->update(niter - niter/2)) ) return;
	if (!status) {
	    std::cerr << "WARNING: Adaptation incomplete\n";
	}
	return;
    }

    if (width > niter / refresh + 1)
	width = niter / refresh + 1;

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
	    if (!console->checkAdaptation(status)) {
		std::cout << std::endl;
		errordump();
		return;
	    }
	    if (console->adaptOff()) {
		adapt = false;
	    }
	    else {
		std::cout << std::endl;
		errordump();
		return;
	    }
	}
	long nupdate = std::min(n, refresh);
	if(Jtry_dump(console->update(nupdate))) {
	    std::cout << "*" << std::flush;
	}
	else {
	    std::cout << std::endl;
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

static void autoadaptstar(long maxiter, long refresh, int width)
{
    if (!console->isAdapting()) {
        std::cout << "Adaptation skipped: model is not in adaptive mode.\n";
		return;
    }
    std::cout << "Autoadapting up to " << maxiter << " iterations" << std::endl;
	
    if (width > maxiter / refresh + 1)
		width = maxiter / refresh + 1;
	
	long i = 0;
	bool status = false;
	
	if ( refresh == 0 ) {
		for (i = 0; i < maxiter; i++) {
			if (!console->checkAdaptation(status)) {
			    errordump();
			    return;
			}
			if(status)
				break;

			if( !Jtry_dump(console->update(1)) ) {
				std::cout << std::endl;
				return;
			}
		}
	}
	else {
	    for (int j = 0; j < width - 1; ++j) {
			std::cout << "-";
	    }
	    std::cout << "| " << std::min(width * refresh, maxiter) << std::endl 
		      << std::flush;

		int col = 0;
	    for (long n = maxiter; n > 0; n -= refresh) {
		    long nupdate = std::min(n, refresh);
			for (long j = 0; j < nupdate; j++) {
				if (!console->checkAdaptation(status)) {
				    errordump();
				    return;
				}
				if(status)
					break;

				if( !Jtry_dump(console->update(1)) ) {
					std::cout << std::endl;
					return;
				}
				i++;
			}
			if(status){
		    	std::cout << std::endl;
				break;
			}

	        std::cout << "+" << std::flush;
	    	col++;
	    	if (col == width || n <= nupdate) {
	    	    int percent = 100 - (n-nupdate) * 100/maxiter;
	    	    std::cout << " " << percent << "%" << std::endl;
	    	    if (n > nupdate) {
	        		col = 0;
		        }
		    }
	    }
	}
		
	if (!console->checkAdaptation(status)) {
	    errordump();
	    return;
	}
	
	if (!status) {
	    std::cerr << "Adaptation incomplete\n";
	}
	else {
		std::cout << "Adaptation completed in " << i << " iterations" << std::endl;
		if (!console->adaptOff()) {
			std::cout << std::endl;
			errordump();
			return;
	    }
	}
    return;
}

static void adaptstar(long niter, long refresh, int width, bool force)
{
    if (!console->isAdapting()) {
	    if( force ) {
			// Missing endl is deliberate - updatestar will write to the same line:
		    std::cout << "Model not in adaptive mode: ";
			updatestar(niter, refresh, width);			
		}
		else {
	        std::cerr << "Adaptation skipped: model is not in adaptive mode.\n";
		}
		return;
    }
    std::cout << "Adapting " << niter << std::endl;
    
    bool status = true;
    if (refresh == 0) {
	if( !Jtry_dump(console->update(niter)) ) return;
	if (!console->checkAdaptation(status)) {
	    errordump();
	    return;
	}
	if (!status) {
	    std::cerr << "Adaptation incomplete\n";
	    return;
	}
	else {
	    std::cerr << "Adaptation successful\n";
	    return;
	}
    }

    if (width > niter / refresh + 1)
	width = niter / refresh + 1;

    for (int i = 0; i < width - 1; ++i) {
	std::cout << "-";
    }
    std::cout << "| " << std::min(width * refresh, niter) << std::endl 
	      << std::flush;

    int col = 0;
    for (long n = niter; n > 0; n -= refresh) {
	long nupdate = std::min(n, refresh);
	if(Jtry_dump(console->update(nupdate)))
	    std::cout << "+" << std::flush;
	else {
	    std::cout << std::endl;
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
    if (!console->checkAdaptation(status)) {
	std::cout << std::endl;
	errordump();
	return;
    }
    if (!status) {
	std::cerr << "Adaptation incomplete.\n";
    }
    else {
	std::cerr << "Adaptation successful\n";
    }
}

static void loadModule(std::string const &name)
{
    if (name == "dic") {
	// For backward-compatibility. Turn this into a warning later.
	std::cout << "The dic module is now a stub." << std::endl;
	std::cout << "Deviance-based diagnostics are in the pre-loaded diag module." << std::endl;
    }
    
    std::cout << "Loading module: " << name;
    lt_dlhandle mod = lt_dlopenext(name.c_str());
    if (mod == NULL) {
	std::cout << ": " << lt_dlerror() << std::endl;
    }
    else {
	std::cout << ": ok" << std::endl;
	_dyn_lib.push_front(mod);
	jags::Console::loadModule(name);
    }
}

static void unloadModule(std::string const &name)
{
    std::cout << "Unloading module: " << name << std::endl;
    jags::Console::unloadModule(name);
}

void exiting() {
	std::cout << "Exiting JAGS" << std::endl;
}

int main (int argc, char **argv)
{
  std::atexit(exiting);

  extern std::FILE *zzin;

  std::FILE *cmdfile = 0;
  if (argc > 2) {
    std::cerr << "Too many arguments" << std::endl;
  }
  else if (argc == 2) {
    interactive = false;
    cmdfile = std::fopen(ExpandFileName(argv[1]).c_str(),"r");
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

#ifndef _WIN32
  /* 
     - Allows emulation of dynamic loading on platforms that do not
     support it by preloading modules. 
     - Causes build failures on mingw-w64 (as at 21 April 2010) so
     not used on Windows platform.
  */
  LTDL_SET_PRELOADED_SYMBOLS();
#endif

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
  loadModule("diag");
  
  console = new jags::Console(std::cout, std::cerr);

  zzparse();
  zzlex_destroy();

  if (argc==2) {
      std::fclose(cmdfile);
  }
  
  //Unload modules
  std::vector<std::string> mods = jags::Console::listModules();
  for (unsigned int i = 0; i < mods.size(); ++i) {
      jags::Console::unloadModule(mods[i]);
  }
  delete console;
  //Release dynamic libraries. 
  for (unsigned int i = 0; i < _dyn_lib.size(); ++i) {
      lt_dlclose(_dyn_lib[i]);
  }
  
  lt_dlexit();
}

static bool getWorkingDirectory(std::string &name)
{
    char buf[FILENAME_MAX];
#ifdef Win32
    if (getCurrentDirectory(FILENAME_MAX, buf)) {
	name = buf;
	return true;
    }
    else {
	name = "Error in getCurrentDirectory";
	return false;
    }
#else
    if (getcwd(buf, FILENAME_MAX)) {
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
#endif
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

static void delete_pvec(std::vector<jags::ParseTree*> *pv)
{
    for (unsigned int i = 0; i < pv->size(); ++i) {
	delete (*pv)[i];
    }
    delete pv;
}

static void print_unused_variables(std::map<std::string, jags::SArray> const &table,
				   bool data)
{
    std::vector<std::string> supplied_vars;
    for (std::map<std::string, jags::SArray>::const_iterator p = table.begin();
	 p != table.end(); ++p)
    {
	supplied_vars.push_back(p->first);
    }
    
    std::vector<std::string> unused_vars;
    std::vector<std::string> model_vars = console->variableNames();
    if (!data) {
	// Initial values table may legitimately contain these names
	model_vars.push_back(".RNG.name");
	model_vars.push_back(".RNG.seed");
	model_vars.push_back(".RNG.state");
    }
	
	// Make sure both vectors are sorted to avoid false positive WARNINGs:
	std::sort(model_vars.begin(), model_vars.end());
	std::sort(supplied_vars.begin(), supplied_vars.end());
	
	/*  Test code to check vectors:
	if(data){
		std::cout << "Variables in model:\n";
		std::copy(model_vars.begin(), model_vars.end(),
			  std::ostream_iterator<std::string>(std::cout, ", "));
		std::cout << "\n";

		std::cout << "Supplied vars:\n";
		std::copy(supplied_vars.begin(), supplied_vars.end(),
			  std::ostream_iterator<std::string>(std::cout, ", "));
		std::cout << "\n";
	}  
	*/
	
    std::set_difference(supplied_vars.begin(), supplied_vars.end(),
			model_vars.begin(), model_vars.end(),
			std::inserter(unused_vars, unused_vars.begin()));

    if (!unused_vars.empty()) {
	std::cerr << "\nWARNING: Unused variable(s) in ";
	if (data) {
	    std::cerr << "data table:\n";
	}
	else {
	    std::cerr << "initial value table:\n";
	}
	std::copy(unused_vars.begin(), unused_vars.end(),
		  std::ostream_iterator<std::string>(std::cerr, "\n"));
	std::cerr << "\n";
    }

}

std::string ExpandFileName(char const *s)
{
    if(s[0] != '~') return s;
    std::string name = s;
    if(name.size() > 1 && s[1] != '/') return s;

    char const *p = getenv("HOME");
    if (p) {
	std::string UserHOME = p;
	if (!UserHOME.empty()) {
	    if (name.size() == 1) 
		return UserHOME;
	    else
		return UserHOME + name.substr(1);
	}
    }
    return name;
}


void doSystem(std::string const *command)
{
    std::system(command->c_str());
}

void listModules(){
  std::vector<std::string> mods = jags::Console::listModules();
  std::cout << "Modules:" << std::endl;
  for (unsigned int i = 0; i < mods.size(); ++i) {
      std::cout << "  " << mods[i] << std::endl;
  }
}


void listFactories(jags::FactoryType type)
{
    std::vector<std::pair<std::string, bool> > faclist = 
	jags::Console::listFactories(type);

    std::vector<std::pair<std::string, bool> >::const_iterator p;
    unsigned int max_strlen = 0;
    for (p = faclist.begin(); p != faclist.end(); ++p) {
	if (p->first.length() > max_strlen)
	    max_strlen = p->first.length();
    }
    if (max_strlen < 4)
	max_strlen = 4;

    //Header
    std::cout << "Name";
    for (int i = max_strlen - 4; i >=0; --i) {
	std::cout << " ";
    }
    std::cout << "Status\n";

    //Body
    for (p = faclist.begin(); p != faclist.end(); ++p) {
	std::cout << p->first << " ";
	for (int i = max_strlen - p->first.length(); i >= 0; --i) {
	    std::cout << " ";
	}
	if (p->second) {
	    std::cout << "on";
	}
	else {
	    std::cout << "off";
	}
	std::cout << "\n";
    }
}

void setFactory(std::string const &name, jags::FactoryType type, 
		std::string const &status)
{
    if (status == "on") {
	jags::Console::setFactoryActive(name, type, true);
    }
    else if (status == "off") {
	jags::Console::setFactoryActive(name, type, false);
    }
    else {
	std::cout << "status should be \"on\" or \"off\"";
    }
}

void setSeed(unsigned int seed)
{
    if (seed == 0) {
	std::cout << "seed must be non-zero";
    }
    else {
	jags::Console::setRNGSeed(seed);
    }
}
	    
bool Jtry(bool ok)
{
    if (!ok && !interactive) 
	exit(1);
    else
	return ok;
}

bool Jtry_dump(bool ok)
{
	// Allows doDump to work as described in the manual:
	if (!ok) {
	errordump();
	console->clearModel();
    if (!interactive) 
	exit(1);
	}
	return ok;
}
