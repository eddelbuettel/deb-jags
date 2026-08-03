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

#line 209 "parser.hh"

};
typedef union ZZSTYPE ZZSTYPE;
# define ZZSTYPE_IS_TRIVIAL 1
# define ZZSTYPE_IS_DECLARED 1
#endif


extern ZZSTYPE zzlval;


int zzparse (void);


#endif /* !YY_ZZ_PARSER_HH_INCLUDED  */
