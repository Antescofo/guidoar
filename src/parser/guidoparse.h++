/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 146 "guidoparse.h++"
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


