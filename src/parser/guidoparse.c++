/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse guidoarparse
#define yylex   guidoarlex
#define yyerror guidoarerror
#define yylval  guidoarlval
#define yychar  guidoarchar
#define yydebug guidoardebug
#define yynerrs guidoarnerrs
#define yylloc guidoarlloc

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     PNUMBER = 259,
     NNUMBER = 260,
     FLOAT = 261,
     STARTCHORD = 262,
     ENDCHORD = 263,
     STARTSEQ = 264,
     ENDSEQ = 265,
     STARTPARAM = 266,
     ENDPARAM = 267,
     STARTRANGE = 268,
     ENDRANGE = 269,
     SEP = 270,
     IDSEP = 271,
     BAR = 272,
     TAGNAME = 273,
     IDT = 274,
     DIATONIC = 275,
     CHROMATIC = 276,
     SOLFEGE = 277,
     EMPTYT = 278,
     RESTT = 279,
     DOT = 280,
     DDOT = 281,
     TDOT = 282,
     SHARPT = 283,
     FLATT = 284,
     TAB = 285,
     MLS = 286,
     SEC = 287,
     UNIT = 288,
     MULT = 289,
     DIV = 290,
     EQUAL = 291,
     STRING = 292,
     EXTRA = 293,
     ENDVAR = 294,
     VARNAME = 295,
     FRETTE = 296,
     COMMENT = 297
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define PNUMBER 259
#define NNUMBER 260
#define FLOAT 261
#define STARTCHORD 262
#define ENDCHORD 263
#define STARTSEQ 264
#define ENDSEQ 265
#define STARTPARAM 266
#define ENDPARAM 267
#define STARTRANGE 268
#define ENDRANGE 269
#define SEP 270
#define IDSEP 271
#define BAR 272
#define TAGNAME 273
#define IDT 274
#define DIATONIC 275
#define CHROMATIC 276
#define SOLFEGE 277
#define EMPTYT 278
#define RESTT 279
#define DOT 280
#define DDOT 281
#define TDOT 282
#define SHARPT 283
#define FLATT 284
#define TAB 285
#define MLS 286
#define SEC 287
#define UNIT 288
#define MULT 289
#define DIV 290
#define EQUAL 291
#define STRING 292
#define EXTRA 293
#define ENDVAR 294
#define VARNAME 295
#define FRETTE 296
#define COMMENT 297




/* Copy the first part of user declarations.  */
#line 1 "guido.y"


#include <string>
#include <iostream>
#include <vector>
#include <assert.h>

#include "guidoelement.h"
#include "gmnreader.h"
#include "guidorational.h"

#include "guidoparser.h"
#include "guidoparse.h++"
// #include "guidolex.c++"


#ifdef WIN32
# pragma warning (disable : 4267 4005)
#endif

// #define YYERROR_VERBOSE
static void guidotagerror (guido::guidoparser* p, const std::string* str, int line, int col);
static int guidoarerror (YYLTYPE* locp, guido::guidoparser* context, const char*s);
int yylex(YYSTYPE* lvalp, YYLTYPE* llocp, void* scanner);

// #define parseDebug 
#ifdef parseDebug
#define debug(msg)		cerr << msg << endl;
#define vdebug(msg,v)	cerr << msg << " " << v << endl;
#else
#define debug(msg)
#define vdebug(msg, v)
#endif
#define forcedebug(msg)			cerr << msg << endl;
#define forcevdebug(msg, v)		cerr << msg << " " << v << endl;


#define scanner context->fScanner

using namespace std;
using namespace guido;


static void vadd (std::vector<guido::Sguidoelement>* v1, std::vector<guido::Sguidoelement>* v2)
{
	for (auto elt: *v2)
		v1->push_back(elt);
}

namespace guido
{



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 86 "guido.y"
{         
	long int		num;
	float			real;
	const char*		token;
	std::string*	str;
	char			c;
	guido::Sguidoelement *		elt;
	guido::Sguidoattribute*		attr;
	std::vector<guido::Sguidoelement>*	 velt;
	std::vector<guido::Sguidoattribute>* vattr;
	guido::rational *		r;
}
/* Line 193 of yacc.c.  */
#line 255 "guidoparse.c++"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 280 "guidoparse.c++"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    15,    18,    21,
      25,    27,    30,    32,    35,    39,    41,    44,    48,    51,
      52,    55,    58,    61,    64,    67,    72,    77,    82,    84,
      86,    88,    90,    95,   100,   102,   104,   108,   110,   112,
     114,   117,   120,   122,   124,   126,   128,   132,   134,   138,
     142,   144,   148,   150,   153,   156,   160,   162,   164,   167,
     170,   175,   177,   180,   182,   184,   188,   195,   200,   206,
     208,   213,   215,   217,   219,   221,   223,   226,   228,   230,
     231,   233,   234,   239,   242,   246,   250,   253,   254,   256,
     258,   260,   262,   264,   267,   269,   271,   273,   275,   277,
     279,   281
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    46,    -1,    45,    46,    -1,    77,    -1,
      51,    -1,    45,    51,    -1,    45,    77,    -1,     7,     8,
      -1,     7,    47,     8,    -1,    49,    -1,    46,    77,    -1,
      49,    -1,    78,    49,    -1,    47,    48,    49,    -1,    15,
      -1,    15,    78,    -1,     9,    50,    10,    -1,    49,    77,
      -1,    -1,    50,    67,    -1,    50,    53,    -1,    50,    61,
      -1,    50,    52,    -1,    50,    77,    -1,    52,    36,    37,
      39,    -1,    52,    36,    84,    39,    -1,    52,    36,    83,
      39,    -1,    40,    -1,    54,    -1,    55,    -1,    57,    -1,
      57,    11,    60,    12,    -1,    54,    13,    50,    14,    -1,
      18,    -1,    56,    -1,    56,    16,    80,    -1,    17,    -1,
      84,    -1,    83,    -1,    84,    33,    -1,    83,    33,    -1,
      37,    -1,    79,    -1,    52,    -1,    58,    -1,    79,    36,
      58,    -1,    59,    -1,    60,    15,    59,    -1,     7,    62,
       8,    -1,    63,    -1,    62,    15,    63,    -1,    64,    -1,
      66,    64,    -1,    64,    66,    -1,    66,    64,    66,    -1,
      67,    -1,    65,    -1,    64,    77,    -1,    77,    64,    -1,
      54,    13,    63,    14,    -1,    54,    -1,    66,    54,    -1,
      69,    -1,    68,    -1,    24,    75,    76,    -1,    24,    11,
       3,    12,    75,    76,    -1,    70,    74,    75,    76,    -1,
      70,    72,    74,    75,    76,    -1,    71,    -1,    71,    11,
       3,    12,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    73,    -1,    72,    73,    -1,    28,    -1,    29,    -1,
      -1,    84,    -1,    -1,    34,    80,    35,    80,    -1,    34,
      80,    -1,    34,    80,    31,    -1,    34,    80,    32,    -1,
      35,    80,    -1,    -1,    25,    -1,    26,    -1,    27,    -1,
      42,    -1,    77,    -1,    78,    77,    -1,    19,    -1,     3,
      -1,     4,    -1,     5,    -1,     6,    -1,    80,    -1,    81,
      -1,    82,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   118,   118,   119,   122,   123,   124,   125,   128,   129,
     130,   131,   134,   135,   136,   139,   140,   143,   144,   147,
     148,   149,   150,   151,   152,   155,   156,   157,   160,   165,
     166,   169,   170,   173,   176,   179,   180,   181,   184,   185,
     186,   187,   188,   189,   190,   193,   194,   197,   198,   204,
     207,   208,   211,   212,   213,   214,   217,   218,   219,   220,
     223,   226,   227,   233,   234,   237,   238,   241,   242,   245,
     246,   249,   250,   251,   252,   255,   256,   259,   260,   263,
     264,   267,   268,   269,   270,   271,   272,   275,   276,   277,
     278,   284,   287,   288,   291,   293,   295,   297,   299,   301,
     302,   303
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "PNUMBER", "NNUMBER", "FLOAT",
  "STARTCHORD", "ENDCHORD", "STARTSEQ", "ENDSEQ", "STARTPARAM", "ENDPARAM",
  "STARTRANGE", "ENDRANGE", "SEP", "IDSEP", "BAR", "TAGNAME", "IDT",
  "DIATONIC", "CHROMATIC", "SOLFEGE", "EMPTYT", "RESTT", "DOT", "DDOT",
  "TDOT", "SHARPT", "FLATT", "TAB", "MLS", "SEC", "UNIT", "MULT", "DIV",
  "EQUAL", "STRING", "EXTRA", "ENDVAR", "VARNAME", "FRETTE", "COMMENT",
  "$accept", "gmn", "header", "score", "voicelist", "sep", "voice",
  "symbols", "vardecl", "varname", "tag", "positiontag", "rangetag",
  "tagname", "tagid", "tagarg", "tagparam", "tagparams", "chord",
  "chordsymbols", "tagchordsymbol", "chordsymbol", "rangechordtag",
  "taglist", "music", "rest", "note", "noteid", "notename", "accidentals",
  "accidental", "octave", "duration", "dots", "comment", "comments", "id",
  "number", "pnumber", "nnumber", "floatn", "signednumber", 0
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
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    45,    46,    46,
      46,    46,    47,    47,    47,    48,    48,    49,    49,    50,
      50,    50,    50,    50,    50,    51,    51,    51,    52,    53,
      53,    54,    54,    55,    56,    57,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    59,    59,    60,    60,    61,
      62,    62,    63,    63,    63,    63,    64,    64,    64,    64,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      76,    77,    78,    78,    79,    80,    81,    82,    83,    84,
      84,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     2,     2,     3,
       1,     2,     1,     2,     3,     1,     2,     3,     2,     0,
       2,     2,     2,     2,     2,     4,     4,     4,     1,     1,
       1,     1,     4,     4,     1,     1,     3,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     1,     3,     3,
       1,     3,     1,     2,     2,     3,     1,     1,     2,     2,
       4,     1,     2,     1,     1,     3,     6,     4,     5,     1,
       4,     1,     1,     1,     1,     1,     2,     1,     1,     0,
       1,     0,     4,     2,     3,     3,     2,     0,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    19,    28,    91,     0,     0,     2,    10,     5,
       0,     4,     8,     0,    12,    92,     0,     0,     1,     3,
       6,     7,    11,    18,     0,     9,    15,     0,    13,    93,
       0,    17,    37,    34,    71,    72,    73,    74,    81,    23,
      21,    29,    30,    35,    31,    22,    20,    64,    63,    79,
      69,    24,    95,    96,    97,    98,     0,    99,   100,   101,
       0,     0,    16,    14,    61,     0,    50,    52,    57,     0,
      56,     0,     0,     0,     0,    87,    19,     0,     0,    77,
      78,    79,    75,    81,    80,     0,    25,    27,    26,     0,
      49,     0,    61,    54,    58,    62,    53,     0,    59,     0,
      83,    86,    88,    89,    90,    65,     0,    36,    94,    42,
      44,    45,    47,     0,    43,    39,    38,    76,    81,    87,
       0,     0,    51,    62,    55,    81,    84,    85,     0,    33,
      32,     0,     0,    41,    40,    87,    67,    70,    60,    87,
      82,    48,    46,    43,    68,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    13,    27,     8,    17,     9,   110,
      40,    64,    42,    43,    44,   111,   112,   113,    45,    65,
      66,    67,    68,    69,    70,    47,    48,    49,    50,    81,
      82,    83,    75,   105,    71,    16,   114,    57,    58,    59,
     115,   116
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -89
static const yytype_int16 yypact[] =
{
      35,    50,   -89,   -89,   -89,    15,    35,    -5,    -5,   -89,
       9,   -89,   -89,    28,    -5,   -89,    -2,    63,   -89,    -5,
     -89,   -89,   -89,   -89,    29,   -89,    -5,    58,    -5,   -89,
     103,   -89,   -89,   -89,   -89,   -89,   -89,   -89,    67,   -89,
     -89,    61,   -89,    66,    86,   -89,   -89,   -89,   -89,    90,
      93,   -89,   -89,   -89,   -89,   -89,    78,   -89,   -89,   -89,
      83,    89,    -5,    -5,   118,    38,   -89,    54,   -89,   103,
     -89,   103,   139,   140,   140,   110,   -89,   140,    20,   -89,
     -89,    90,   -89,    21,   -89,   141,   -89,   -89,   -89,   103,
     -89,   103,   -89,    45,   -89,   118,    54,   118,    -5,   134,
      98,   -89,   -89,   -89,   -89,   -89,    92,   -89,   -89,   -89,
     -89,   -89,   -89,    76,   111,   115,   116,   -89,    21,   110,
     138,   137,   -89,   -89,    45,    21,   -89,   -89,   140,   -89,
     -89,    20,    20,   -89,   -89,   110,   -89,   -89,   -89,   110,
     -89,   -89,   -89,   -89,   -89,   -89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -89,   -89,   146,   -89,   -89,    11,    77,   148,     5,
     -89,   -17,   -89,   -89,   -89,    23,    25,   -89,   -89,   -89,
      49,    70,   -89,   -47,   -16,   -89,   -89,   -89,   -89,   -89,
      79,    80,   -77,   -88,     2,   131,    26,   -60,   -89,   -89,
     135,   -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      41,    46,    11,    15,    61,    10,   119,     2,    21,    22,
      23,    10,    14,   100,   101,    18,    23,   107,    29,    51,
      93,    22,    39,    52,    53,    54,    55,    28,    15,    84,
      23,   136,    52,    53,    54,    55,    25,     4,    63,   108,
       4,   135,     1,    26,     2,    24,    90,   144,   139,   124,
      92,   145,    95,    91,    97,    73,    74,   109,    12,     2,
       3,    84,    32,    33,    29,    23,    56,     2,   140,    94,
      30,    32,    33,    31,    76,     3,   123,     4,    72,    92,
      32,    33,    77,    34,    35,    36,    37,    38,   130,    41,
      46,   131,     4,    52,    53,    54,     4,    78,    94,    30,
      94,    73,    74,     3,    85,     4,   129,   123,    51,    32,
      33,    39,    34,    35,    36,    37,    38,    86,    79,    80,
      32,    33,    87,    34,    35,    36,    37,    38,    88,   126,
     127,    89,     3,   128,     4,   102,   103,   104,   121,    96,
     122,    98,    99,    52,   120,     4,   125,   132,   133,   134,
     137,   138,    19,   106,    20,   142,   141,    62,   143,    60,
     117,   118
};

static const yytype_uint8 yycheck[] =
{
      17,    17,     0,     1,    24,     0,    83,     9,     6,     7,
       8,     6,     1,    73,    74,     0,    14,    77,    16,    17,
      67,    19,    17,     3,     4,     5,     6,    16,    26,    49,
      28,   119,     3,     4,     5,     6,     8,    42,    27,    19,
      42,   118,     7,    15,     9,    36,     8,   135,   125,    96,
      67,   139,    69,    15,    71,    34,    35,    37,     8,     9,
      40,    81,    17,    18,    62,    63,    37,     9,   128,    67,
       7,    17,    18,    10,    13,    40,    93,    42,    11,    96,
      17,    18,    16,    20,    21,    22,    23,    24,    12,   106,
     106,    15,    42,     3,     4,     5,    42,    11,    96,     7,
      98,    34,    35,    40,    11,    42,    14,   124,   106,    17,
      18,   106,    20,    21,    22,    23,    24,    39,    28,    29,
      17,    18,    39,    20,    21,    22,    23,    24,    39,    31,
      32,    13,    40,    35,    42,    25,    26,    27,    89,    69,
      91,    71,     3,     3,     3,    42,    12,    36,    33,    33,
      12,    14,     6,    76,     6,   132,   131,    26,   132,    24,
      81,    81
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     9,    40,    42,    44,    45,    46,    49,    51,
      52,    77,     8,    47,    49,    77,    78,    50,     0,    46,
      51,    77,    77,    77,    36,     8,    15,    48,    49,    77,
       7,    10,    17,    18,    20,    21,    22,    23,    24,    52,
      53,    54,    55,    56,    57,    61,    67,    68,    69,    70,
      71,    77,     3,     4,     5,     6,    37,    80,    81,    82,
      83,    84,    78,    49,    54,    62,    63,    64,    65,    66,
      67,    77,    11,    34,    35,    75,    13,    16,    11,    28,
      29,    72,    73,    74,    84,    11,    39,    39,    39,    13,
       8,    15,    54,    66,    77,    54,    64,    54,    64,     3,
      80,    80,    25,    26,    27,    76,    50,    80,    19,    37,
      52,    58,    59,    60,    79,    83,    84,    73,    74,    75,
       3,    63,    63,    54,    66,    12,    31,    32,    35,    14,
      12,    15,    36,    33,    33,    75,    76,    12,    14,    75,
      80,    59,    58,    79,    76,    76
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
      yyerror (&yylloc, context, YY_("syntax error: cannot back up")); \
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, scanner)
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
		  Type, Value, Location, context); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, guido::guidoparser* context)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, context)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    guido::guidoparser* context;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (context);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, guido::guidoparser* context)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, context)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    guido::guidoparser* context;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, context);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, guido::guidoparser* context)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, context)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    guido::guidoparser* context;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , context);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, context); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, guido::guidoparser* context)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, context)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    guido::guidoparser* context;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (context);

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
int yyparse (guido::guidoparser* context);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

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
yyparse (guido::guidoparser* context)
#else
int
yyparse (context)
    guido::guidoparser* context;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 119 "guido.y"
    { debug("header score"); context->setHeader((yyvsp[(1) - (2)].velt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 4:
#line 122 "guido.y"
    { debug("header comment"); (yyval.velt) = new vector<Sguidoelement>; (yyval.velt)->push_back(*(yyvsp[(1) - (1)].elt)); delete (yyvsp[(1) - (1)].elt);;}
    break;

  case 5:
#line 123 "guido.y"
    { debug("header variable"); (yyval.velt) = new vector<Sguidoelement>; (yyval.velt)->push_back(*(yyvsp[(1) - (1)].elt)); delete (yyvsp[(1) - (1)].elt);;}
    break;

  case 6:
#line 124 "guido.y"
    { debug("header + variable"); (yyval.velt)=(yyvsp[(1) - (2)].velt); (yyvsp[(1) - (2)].velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 7:
#line 125 "guido.y"
    { debug("header + comment"); (yyval.velt)=(yyvsp[(1) - (2)].velt); (yyvsp[(1) - (2)].velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 8:
#line 128 "guido.y"
    { debug("new score"); (yyval.elt) = context->newScore(); ;}
    break;

  case 9:
#line 129 "guido.y"
    { debug("score voicelist"); (yyval.elt) = context->newScore(); (*(yyval.elt))->push( *(yyvsp[(2) - (3)].velt)); delete (yyvsp[(2) - (3)].velt); ;}
    break;

  case 10:
#line 130 "guido.y"
    { debug("score voice"); (yyval.elt) = context->newScore(); (*(yyval.elt))->push( *(yyvsp[(1) - (1)].elt)); delete (yyvsp[(1) - (1)].elt); ;}
    break;

  case 11:
#line 131 "guido.y"
    { debug("score comment"); (yyval.elt) = (yyvsp[(1) - (2)].elt); context->addFooter(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 12:
#line 134 "guido.y"
    { debug("new voicelist"); (yyval.velt) = new vector<Sguidoelement>; (yyval.velt)->push_back (*(yyvsp[(1) - (1)].elt)); delete (yyvsp[(1) - (1)].elt); ;}
    break;

  case 13:
#line 135 "guido.y"
    { debug("add voicelist"); (yyval.velt) = new vector<Sguidoelement>; if ((yyvsp[(1) - (2)].velt)) { for (auto c: *(yyvsp[(1) - (2)].velt)) context->beforeVoice((yyvsp[(2) - (2)].elt), c); }; (yyval.velt)->push_back (*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 14:
#line 136 "guido.y"
    { debug("add voicelist"); (yyval.velt) = (yyvsp[(1) - (3)].velt); (yyval.velt)->push_back (*(yyvsp[(3) - (3)].elt)); delete (yyvsp[(3) - (3)].elt); ;}
    break;

  case 15:
#line 139 "guido.y"
    { debug("SEP"); (yyval.velt)=0; ;}
    break;

  case 16:
#line 140 "guido.y"
    { debug("SEP comments"); (yyval.velt)=(yyvsp[(2) - (2)].velt); ;}
    break;

  case 17:
#line 143 "guido.y"
    { debug("new voice"); (yyval.elt) = context->newVoice(); (*(yyval.elt))->push( *(yyvsp[(2) - (3)].velt)); delete (yyvsp[(2) - (3)].velt); ;}
    break;

  case 18:
#line 144 "guido.y"
    { debug("voice comment"); (yyval.elt) = (yyvsp[(1) - (2)].elt); context->afterVoice((yyval.elt), *(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 19:
#line 147 "guido.y"
    { debug("new symbols"); (yyval.velt) = new vector<Sguidoelement>; ;}
    break;

  case 20:
#line 148 "guido.y"
    { debug("add music"); (yyval.velt) = (yyvsp[(1) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 21:
#line 149 "guido.y"
    { debug("add tag"); (yyval.velt) = (yyvsp[(1) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 22:
#line 150 "guido.y"
    { debug("add chord"); (yyval.velt) = (yyvsp[(1) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 23:
#line 151 "guido.y"
    { debug("add varname"); (yyval.velt) = (yyvsp[(1) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 24:
#line 152 "guido.y"
    { debug("add comment"); (yyval.velt) = (yyvsp[(1) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 25:
#line 155 "guido.y"
    { vdebug("vardecl string", *(yyvsp[(1) - (4)].elt)); (yyval.elt) = (yyvsp[(1) - (4)].elt); context->variableDecl (*(yyvsp[(1) - (4)].elt), context->fText.c_str(), guidoparser::kString);  ;}
    break;

  case 26:
#line 156 "guido.y"
    { vdebug("vardecl int", *(yyvsp[(1) - (4)].elt)); (yyval.elt) = (yyvsp[(1) - (4)].elt); context->variableDecl (*(yyvsp[(1) - (4)].elt), context->fText.c_str(), guidoparser::kInt);  ;}
    break;

  case 27:
#line 157 "guido.y"
    { vdebug("vardecl float", *(yyvsp[(1) - (4)].elt)); (yyval.elt) = (yyvsp[(1) - (4)].elt); context->variableDecl (*(yyvsp[(1) - (4)].elt), context->fText.c_str(), guidoparser::kFloat); ;}
    break;

  case 28:
#line 160 "guido.y"
    { vdebug("varname", context->fText); (yyval.elt) =  context->newVariable(context->fText); ;}
    break;

  case 29:
#line 165 "guido.y"
    { debug("position tag "); (yyval.elt) = (yyvsp[(1) - (1)].elt); ;}
    break;

  case 30:
#line 166 "guido.y"
    { debug("range tag "); (yyval.elt) = (yyvsp[(1) - (1)].elt); ;}
    break;

  case 31:
#line 169 "guido.y"
    { debug("new position tag "); (yyval.elt) = (yyvsp[(1) - (1)].elt); ;}
    break;

  case 32:
#line 170 "guido.y"
    { debug("new tag + params"); (yyval.elt) = (yyvsp[(1) - (4)].elt); (*(yyvsp[(1) - (4)].elt))->add (*(yyvsp[(3) - (4)].vattr)); delete (yyvsp[(3) - (4)].vattr); ;}
    break;

  case 33:
#line 173 "guido.y"
    { debug("new range tag "); (yyval.elt) = (yyvsp[(1) - (4)].elt); (*(yyvsp[(1) - (4)].elt))->push (*(yyvsp[(3) - (4)].velt)); delete (yyvsp[(3) - (4)].velt); ;}
    break;

  case 34:
#line 176 "guido.y"
    { debug("tag name "); (yyval.str) = new string(context->fText); ;}
    break;

  case 35:
#line 179 "guido.y"
    { vdebug("new tag", *(yyvsp[(1) - (1)].str)); (yyval.elt) = context->newTag(*(yyvsp[(1) - (1)].str), 0); if (!(yyval.elt)) { guidotagerror(context, (yyvsp[(1) - (1)].str), (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column); YYERROR;} delete (yyvsp[(1) - (1)].str); ;}
    break;

  case 36:
#line 180 "guido.y"
    { debug("new tag::id");  (yyval.elt) = context->newTag(*(yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].num)); if (!(yyval.elt)) { guidotagerror(context, (yyvsp[(1) - (3)].str), (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); YYERROR;} delete (yyvsp[(1) - (3)].str); ;}
    break;

  case 37:
#line 181 "guido.y"
    { debug("new bar"); (yyval.elt) = context->newTag("\\bar", 0); ;}
    break;

  case 38:
#line 184 "guido.y"
    { debug("new signednumber arg"); (yyval.attr) = context->newAttribute((yyvsp[(1) - (1)].num)); ;}
    break;

  case 39:
#line 185 "guido.y"
    { debug("new FLOAT arg"); (yyval.attr) = context->newAttribute((yyvsp[(1) - (1)].real)); ;}
    break;

  case 40:
#line 186 "guido.y"
    { debug("new signednumber UNIT arg"); (yyval.attr) = context->newAttribute((yyvsp[(1) - (2)].num)); (*(yyval.attr))->setUnit(context->fText); ;}
    break;

  case 41:
#line 187 "guido.y"
    { debug("new FLOAT UNIT arg"); (yyval.attr) = context->newAttribute((yyvsp[(1) - (2)].real)); (*(yyval.attr))->setUnit(context->fText); ;}
    break;

  case 42:
#line 188 "guido.y"
    { debug("new STRING arg"); (yyval.attr) = context->newAttribute(context->fText, true); ;}
    break;

  case 43:
#line 189 "guido.y"
    { debug("new ID arg"); (yyval.attr) = context->newAttribute(*(yyvsp[(1) - (1)].str), false); delete (yyvsp[(1) - (1)].str); ;}
    break;

  case 44:
#line 190 "guido.y"
    { debug("new var arg"); (yyval.attr) = context->newAttribute((*(yyvsp[(1) - (1)].elt))->getName(), false); delete (yyvsp[(1) - (1)].elt); ;}
    break;

  case 45:
#line 193 "guido.y"
    { debug("tagparam"); (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 46:
#line 194 "guido.y"
    { debug("tagparam"); (yyval.attr) = (yyvsp[(3) - (3)].attr); (*(yyvsp[(3) - (3)].attr))->setName(*(yyvsp[(1) - (3)].str)); delete (yyvsp[(1) - (3)].str); ;}
    break;

  case 47:
#line 197 "guido.y"
    { (yyval.vattr) = new vector<Sguidoattribute>; (yyval.vattr)->push_back(*(yyvsp[(1) - (1)].attr)); delete (yyvsp[(1) - (1)].attr); ;}
    break;

  case 48:
#line 198 "guido.y"
    { (yyval.vattr) = (yyvsp[(1) - (3)].vattr); (yyval.vattr)->push_back(*(yyvsp[(3) - (3)].attr)); delete (yyvsp[(3) - (3)].attr); ;}
    break;

  case 49:
#line 204 "guido.y"
    { debug("new chord"); (yyval.elt) = context->newChord(); (*(yyval.elt))->push(*(yyvsp[(2) - (3)].velt)); delete (yyvsp[(2) - (3)].velt); ;}
    break;

  case 50:
#line 207 "guido.y"
    { (yyval.velt) = new vector<Sguidoelement>; vadd((yyval.velt), (yyvsp[(1) - (1)].velt)); delete (yyvsp[(1) - (1)].velt); ;}
    break;

  case 51:
#line 208 "guido.y"
    { (yyval.velt) = (yyvsp[(1) - (3)].velt); vadd((yyval.velt), (yyvsp[(3) - (3)].velt)); delete (yyvsp[(3) - (3)].velt); ;}
    break;

  case 52:
#line 211 "guido.y"
    { (yyval.velt) = (yyvsp[(1) - (1)].velt);;}
    break;

  case 53:
#line 212 "guido.y"
    { (yyval.velt) = (yyvsp[(1) - (2)].velt); vadd((yyval.velt), (yyvsp[(2) - (2)].velt)); delete (yyvsp[(2) - (2)].velt); ;}
    break;

  case 54:
#line 213 "guido.y"
    { (yyval.velt) = (yyvsp[(1) - (2)].velt); vadd((yyval.velt), (yyvsp[(2) - (2)].velt)); delete (yyvsp[(2) - (2)].velt); ;}
    break;

  case 55:
#line 214 "guido.y"
    { (yyval.velt) = (yyvsp[(1) - (3)].velt); vadd((yyval.velt), (yyvsp[(2) - (3)].velt)); delete (yyvsp[(2) - (3)].velt); vadd((yyval.velt), (yyvsp[(3) - (3)].velt)); delete (yyvsp[(3) - (3)].velt); ;}
    break;

  case 56:
#line 217 "guido.y"
    { (yyval.velt) = new vector<Sguidoelement>; (yyval.velt)->push_back(*(yyvsp[(1) - (1)].elt)); delete (yyvsp[(1) - (1)].elt); ;}
    break;

  case 57:
#line 218 "guido.y"
    { (yyval.velt) = new vector<Sguidoelement>; (yyval.velt)->push_back(*(yyvsp[(1) - (1)].elt)); delete (yyvsp[(1) - (1)].elt); ;}
    break;

  case 58:
#line 219 "guido.y"
    { (yyval.velt) = (yyvsp[(1) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 59:
#line 220 "guido.y"
    { debug("comment chord"); (yyval.velt) = (yyvsp[(2) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(1) - (2)].elt)); delete (yyvsp[(1) - (2)].elt); ;}
    break;

  case 60:
#line 223 "guido.y"
    { debug("range chord tag"); (yyval.elt) = (yyvsp[(1) - (4)].elt); (*(yyval.elt))->push(*(yyvsp[(3) - (4)].velt)); delete (yyvsp[(3) - (4)].velt); ;}
    break;

  case 61:
#line 226 "guido.y"
    { debug("new taglist 1"); (yyval.velt) = new vector<Sguidoelement>; (yyval.velt)->push_back(*(yyvsp[(1) - (1)].elt)); delete (yyvsp[(1) - (1)].elt); ;}
    break;

  case 62:
#line 227 "guido.y"
    { debug("new taglist 2"); (yyval.velt) = (yyvsp[(1) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 63:
#line 233 "guido.y"
    { (yyval.elt) = (yyvsp[(1) - (1)].elt); ;}
    break;

  case 64:
#line 234 "guido.y"
    { (yyval.elt) = (yyvsp[(1) - (1)].elt); ;}
    break;

  case 65:
#line 237 "guido.y"
    { debug("new rest 1"); (yyval.elt) = context->newRest((yyvsp[(2) - (3)].r), (yyvsp[(3) - (3)].num)); delete (yyvsp[(2) - (3)].r); ;}
    break;

  case 66:
#line 238 "guido.y"
    { debug("new rest 2"); (yyval.elt) = context->newRest((yyvsp[(5) - (6)].r), (yyvsp[(6) - (6)].num)); delete (yyvsp[(5) - (6)].r); ;}
    break;

  case 67:
#line 241 "guido.y"
    { debug("new note v1"); (yyval.elt) = context->newNote(*(yyvsp[(1) - (4)].str), 0, (yyvsp[(2) - (4)].num), (yyvsp[(3) - (4)].r), (yyvsp[(4) - (4)].num)); delete (yyvsp[(1) - (4)].str); delete (yyvsp[(3) - (4)].r); ;}
    break;

  case 68:
#line 242 "guido.y"
    { debug("new note v2"); (yyval.elt) = context->newNote(*(yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].num), (yyvsp[(3) - (5)].num), (yyvsp[(4) - (5)].r), (yyvsp[(5) - (5)].num)); delete (yyvsp[(1) - (5)].str); delete (yyvsp[(4) - (5)].r); ;}
    break;

  case 69:
#line 245 "guido.y"
    { vdebug("notename", *(yyvsp[(1) - (1)].str)); (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 70:
#line 246 "guido.y"
    { (yyval.str) = (yyvsp[(1) - (4)].str); ;}
    break;

  case 71:
#line 249 "guido.y"
    { debug("new diatonic note"); (yyval.str) = new string(context->fText); ;}
    break;

  case 72:
#line 250 "guido.y"
    { debug("new chromatic note"); (yyval.str) = new string(context->fText); ;}
    break;

  case 73:
#line 251 "guido.y"
    { debug("new solfege note"); (yyval.str) = new string(context->fText); ;}
    break;

  case 74:
#line 252 "guido.y"
    { debug("new empty note"); (yyval.str) = new string(context->fText); ;}
    break;

  case 75:
#line 255 "guido.y"
    { debug("accidental"); (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;

  case 76:
#line 256 "guido.y"
    { debug("accidentals"); (yyval.num) = (yyvsp[(1) - (2)].num) + (yyvsp[(2) - (2)].num); ;}
    break;

  case 77:
#line 259 "guido.y"
    { debug("sharp"); (yyval.num) = 1; ;}
    break;

  case 78:
#line 260 "guido.y"
    { debug("flat"); (yyval.num) = -1; ;}
    break;

  case 79:
#line 263 "guido.y"
    { debug("no octave"); (yyval.num) = -1000; ;}
    break;

  case 80:
#line 264 "guido.y"
    { debug("octave"); (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;

  case 81:
#line 267 "guido.y"
    { debug("implicit duration"); (yyval.r) = new rational(-1, 1); ;}
    break;

  case 82:
#line 268 "guido.y"
    { debug("duration ./."); (yyval.r) = new rational((yyvsp[(2) - (4)].num), (yyvsp[(4) - (4)].num)); ;}
    break;

  case 83:
#line 269 "guido.y"
    { debug("duration *"); (yyval.r) = new rational((yyvsp[(2) - (2)].num), 1); ;}
    break;

  case 84:
#line 270 "guido.y"
    { debug("duration ms"); (yyval.r) = new rational(context->ms2rational((yyvsp[(2) - (3)].num))); ;}
    break;

  case 85:
#line 271 "guido.y"
    { debug("duration s"); (yyval.r) = new rational(context->sec2rational((yyvsp[(2) - (3)].num))); ;}
    break;

  case 86:
#line 272 "guido.y"
    { debug("duration /"); (yyval.r) = new rational(1, (yyvsp[(2) - (2)].num)); ;}
    break;

  case 87:
#line 275 "guido.y"
    { debug("dots 0"); (yyval.num) = 0; ;}
    break;

  case 88:
#line 276 "guido.y"
    { debug("dots 1"); (yyval.num) = 1; ;}
    break;

  case 89:
#line 277 "guido.y"
    { debug("dots 2"); (yyval.num) = 2; ;}
    break;

  case 90:
#line 278 "guido.y"
    { debug("dots 3"); (yyval.num) = 3; ;}
    break;

  case 91:
#line 284 "guido.y"
    { vdebug("comment", context->fText);  (yyval.elt) = context->newComment(context->fText); ;}
    break;

  case 92:
#line 287 "guido.y"
    { vdebug("comments", context->fText);  (yyval.velt) = new vector<Sguidoelement>; (yyval.velt)->push_back(*(yyvsp[(1) - (1)].elt)); delete (yyvsp[(1) - (1)].elt); ;}
    break;

  case 93:
#line 288 "guido.y"
    { vdebug("comments", context->fText);  (yyval.velt) = (yyvsp[(1) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 94:
#line 291 "guido.y"
    { (yyval.str) = new string(context->fText); ;}
    break;

  case 95:
#line 293 "guido.y"
    { vdebug("NUMBER", context->fText); (yyval.num) = atol(context->fText.c_str()); ;}
    break;

  case 96:
#line 295 "guido.y"
    { vdebug("PNUMBER", context->fText); (yyval.num) = atol(context->fText.c_str()); ;}
    break;

  case 97:
#line 297 "guido.y"
    { vdebug("NNUMBER", context->fText); (yyval.num) = atol(context->fText.c_str()); ;}
    break;

  case 98:
#line 299 "guido.y"
    { vdebug("FLOAT", context->fText); (yyval.real) = atof(context->fText.c_str()); ;}
    break;

  case 99:
#line 301 "guido.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;

  case 100:
#line 302 "guido.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;

  case 101:
#line 303 "guido.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2153 "guidoparse.c++"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
      yyerror (&yylloc, context, YY_("syntax error"));
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
	    yyerror (&yylloc, context, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, context, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc, context);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, context);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, context, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, context);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, context);
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


#line 305 "guido.y"


} // namespace

#ifdef TEST
int	gParseErrorLine = 0;
#else
extern int	gParseErrorLine;
#endif

extern YYLTYPE* yylloc;

static int _error(int line, int column, guido::guidoparser* p, const char* msg) {
	p->error (msg, line, column);
	return 0;
}

static void guidotagerror (guido::guidoparser* p, const std::string* tag, int line, int col) {
	std::string msg ("unknown tag ");
	msg += *tag;
	_error (line, col, p, msg.c_str());
}

static int guidoarerror(YYLTYPE* loc, guido::guidoparser* p, const char*s) {
	return _error (loc->last_line, loc->first_column, p, s);
}

int guido::guidoparser::_yyparse()		{ return yyparse (this); }

