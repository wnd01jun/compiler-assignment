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


#define YYSTYPE_IS_DECLARED  1

typedef long long YYSTYPE; 

/* First part of user prologue.  */
#line 1 "lee.y"

#include "type.h"
extern int line_no, syntax_err;
extern A_NODE *root;
extern A_ID *current_id;
extern int current_level;
extern A_TYPE *int_type;    

#line 80 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    AUTO_SYM = 258,                /* AUTO_SYM  */
    BREAK_SYM = 259,               /* BREAK_SYM  */
    CASE_SYM = 260,                /* CASE_SYM  */
    CONTINUE_SYM = 261,            /* CONTINUE_SYM  */
    DEFAULT_SYM = 262,             /* DEFAULT_SYM  */
    DO_SYM = 263,                  /* DO_SYM  */
    ELSE_SYM = 264,                /* ELSE_SYM  */
    ENUM_SYM = 265,                /* ENUM_SYM  */
    FOR_SYM = 266,                 /* FOR_SYM  */
    IF_SYM = 267,                  /* IF_SYM  */
    RETURN_SYM = 268,              /* RETURN_SYM  */
    SIZEOF_SYM = 269,              /* SIZEOF_SYM  */
    STATIC_SYM = 270,              /* STATIC_SYM  */
    STRUCT_SYM = 271,              /* STRUCT_SYM  */
    SWITCH_SYM = 272,              /* SWITCH_SYM  */
    TYPEDEF_SYM = 273,             /* TYPEDEF_SYM  */
    UNION_SYM = 274,               /* UNION_SYM  */
    WHILE_SYM = 275,               /* WHILE_SYM  */
    PLUSPLUS = 276,                /* PLUSPLUS  */
    MINUSMINUS = 277,              /* MINUSMINUS  */
    ARROW = 278,                   /* ARROW  */
    LSS = 279,                     /* LSS  */
    GTR = 280,                     /* GTR  */
    LEQ = 281,                     /* LEQ  */
    GEQ = 282,                     /* GEQ  */
    EQL = 283,                     /* EQL  */
    NEQ = 284,                     /* NEQ  */
    AMPAMP = 285,                  /* AMPAMP  */
    BARBAR = 286,                  /* BARBAR  */
    DOTDOTDOT = 287,               /* DOTDOTDOT  */
    LP = 288,                      /* LP  */
    RP = 289,                      /* RP  */
    LB = 290,                      /* LB  */
    RB = 291,                      /* RB  */
    LR = 292,                      /* LR  */
    RR = 293,                      /* RR  */
    COLON = 294,                   /* COLON  */
    PERIOD = 295,                  /* PERIOD  */
    COMMA = 296,                   /* COMMA  */
    EXCL = 297,                    /* EXCL  */
    STAR = 298,                    /* STAR  */
    SLASH = 299,                   /* SLASH  */
    PERCENT = 300,                 /* PERCENT  */
    AMP = 301,                     /* AMP  */
    SEMICOLON = 302,               /* SEMICOLON  */
    PLUS = 303,                    /* PLUS  */
    MINUS = 304,                   /* MINUS  */
    ASSIGN = 305,                  /* ASSIGN  */
    INTEGER_CONSTANT = 306,        /* INTEGER_CONSTANT  */
    FLOAT_CONSTANT = 307,          /* FLOAT_CONSTANT  */
    STRING_LITERAL = 308,          /* STRING_LITERAL  */
    CHARACTER_CONSTANT = 309,      /* CHARACTER_CONSTANT  */
    CONST_SYM = 310,               /* CONST_SYM  */
    ACCENT = 311,                  /* ACCENT  */
    BAR = 312,                     /* BAR  */
    QUESTION = 313,                /* QUESTION  */
    TILDE = 314,                   /* TILDE  */
    IDENTIFIER = 315,              /* IDENTIFIER  */
    TYPE_IDENTIFIER = 316,         /* TYPE_IDENTIFIER  */
    GOTO_SYM = 317,                /* GOTO_SYM  */
    LSHIFT = 318,                  /* LSHIFT  */
    RSHIFT = 319                   /* RSHIFT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AUTO_SYM 258
#define BREAK_SYM 259
#define CASE_SYM 260
#define CONTINUE_SYM 261
#define DEFAULT_SYM 262
#define DO_SYM 263
#define ELSE_SYM 264
#define ENUM_SYM 265
#define FOR_SYM 266
#define IF_SYM 267
#define RETURN_SYM 268
#define SIZEOF_SYM 269
#define STATIC_SYM 270
#define STRUCT_SYM 271
#define SWITCH_SYM 272
#define TYPEDEF_SYM 273
#define UNION_SYM 274
#define WHILE_SYM 275
#define PLUSPLUS 276
#define MINUSMINUS 277
#define ARROW 278
#define LSS 279
#define GTR 280
#define LEQ 281
#define GEQ 282
#define EQL 283
#define NEQ 284
#define AMPAMP 285
#define BARBAR 286
#define DOTDOTDOT 287
#define LP 288
#define RP 289
#define LB 290
#define RB 291
#define LR 292
#define RR 293
#define COLON 294
#define PERIOD 295
#define COMMA 296
#define EXCL 297
#define STAR 298
#define SLASH 299
#define PERCENT 300
#define AMP 301
#define SEMICOLON 302
#define PLUS 303
#define MINUS 304
#define ASSIGN 305
#define INTEGER_CONSTANT 306
#define FLOAT_CONSTANT 307
#define STRING_LITERAL 308
#define CHARACTER_CONSTANT 309
#define CONST_SYM 310
#define ACCENT 311
#define BAR 312
#define QUESTION 313
#define TILDE 314
#define IDENTIFIER 315
#define TYPE_IDENTIFIER 316
#define GOTO_SYM 317
#define LSHIFT 318
#define RSHIFT 319

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AUTO_SYM = 3,                   /* AUTO_SYM  */
  YYSYMBOL_BREAK_SYM = 4,                  /* BREAK_SYM  */
  YYSYMBOL_CASE_SYM = 5,                   /* CASE_SYM  */
  YYSYMBOL_CONTINUE_SYM = 6,               /* CONTINUE_SYM  */
  YYSYMBOL_DEFAULT_SYM = 7,                /* DEFAULT_SYM  */
  YYSYMBOL_DO_SYM = 8,                     /* DO_SYM  */
  YYSYMBOL_ELSE_SYM = 9,                   /* ELSE_SYM  */
  YYSYMBOL_ENUM_SYM = 10,                  /* ENUM_SYM  */
  YYSYMBOL_FOR_SYM = 11,                   /* FOR_SYM  */
  YYSYMBOL_IF_SYM = 12,                    /* IF_SYM  */
  YYSYMBOL_RETURN_SYM = 13,                /* RETURN_SYM  */
  YYSYMBOL_SIZEOF_SYM = 14,                /* SIZEOF_SYM  */
  YYSYMBOL_STATIC_SYM = 15,                /* STATIC_SYM  */
  YYSYMBOL_STRUCT_SYM = 16,                /* STRUCT_SYM  */
  YYSYMBOL_SWITCH_SYM = 17,                /* SWITCH_SYM  */
  YYSYMBOL_TYPEDEF_SYM = 18,               /* TYPEDEF_SYM  */
  YYSYMBOL_UNION_SYM = 19,                 /* UNION_SYM  */
  YYSYMBOL_WHILE_SYM = 20,                 /* WHILE_SYM  */
  YYSYMBOL_PLUSPLUS = 21,                  /* PLUSPLUS  */
  YYSYMBOL_MINUSMINUS = 22,                /* MINUSMINUS  */
  YYSYMBOL_ARROW = 23,                     /* ARROW  */
  YYSYMBOL_LSS = 24,                       /* LSS  */
  YYSYMBOL_GTR = 25,                       /* GTR  */
  YYSYMBOL_LEQ = 26,                       /* LEQ  */
  YYSYMBOL_GEQ = 27,                       /* GEQ  */
  YYSYMBOL_EQL = 28,                       /* EQL  */
  YYSYMBOL_NEQ = 29,                       /* NEQ  */
  YYSYMBOL_AMPAMP = 30,                    /* AMPAMP  */
  YYSYMBOL_BARBAR = 31,                    /* BARBAR  */
  YYSYMBOL_DOTDOTDOT = 32,                 /* DOTDOTDOT  */
  YYSYMBOL_LP = 33,                        /* LP  */
  YYSYMBOL_RP = 34,                        /* RP  */
  YYSYMBOL_LB = 35,                        /* LB  */
  YYSYMBOL_RB = 36,                        /* RB  */
  YYSYMBOL_LR = 37,                        /* LR  */
  YYSYMBOL_RR = 38,                        /* RR  */
  YYSYMBOL_COLON = 39,                     /* COLON  */
  YYSYMBOL_PERIOD = 40,                    /* PERIOD  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_EXCL = 42,                      /* EXCL  */
  YYSYMBOL_STAR = 43,                      /* STAR  */
  YYSYMBOL_SLASH = 44,                     /* SLASH  */
  YYSYMBOL_PERCENT = 45,                   /* PERCENT  */
  YYSYMBOL_AMP = 46,                       /* AMP  */
  YYSYMBOL_SEMICOLON = 47,                 /* SEMICOLON  */
  YYSYMBOL_PLUS = 48,                      /* PLUS  */
  YYSYMBOL_MINUS = 49,                     /* MINUS  */
  YYSYMBOL_ASSIGN = 50,                    /* ASSIGN  */
  YYSYMBOL_INTEGER_CONSTANT = 51,          /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 52,            /* FLOAT_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 53,            /* STRING_LITERAL  */
  YYSYMBOL_CHARACTER_CONSTANT = 54,        /* CHARACTER_CONSTANT  */
  YYSYMBOL_CONST_SYM = 55,                 /* CONST_SYM  */
  YYSYMBOL_ACCENT = 56,                    /* ACCENT  */
  YYSYMBOL_BAR = 57,                       /* BAR  */
  YYSYMBOL_QUESTION = 58,                  /* QUESTION  */
  YYSYMBOL_TILDE = 59,                     /* TILDE  */
  YYSYMBOL_IDENTIFIER = 60,                /* IDENTIFIER  */
  YYSYMBOL_TYPE_IDENTIFIER = 61,           /* TYPE_IDENTIFIER  */
  YYSYMBOL_GOTO_SYM = 62,                  /* GOTO_SYM  */
  YYSYMBOL_LSHIFT = 63,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 64,                    /* RSHIFT  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_translation_unit = 67,          /* translation_unit  */
  YYSYMBOL_external_declaration = 68,      /* external_declaration  */
  YYSYMBOL_function_definition = 69,       /* function_definition  */
  YYSYMBOL_70_1 = 70,                      /* @1  */
  YYSYMBOL_71_2 = 71,                      /* @2  */
  YYSYMBOL_declaration_list_opt = 72,      /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 73,          /* declaration_list  */
  YYSYMBOL_declaration = 74,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 75,    /* declaration_specifiers  */
  YYSYMBOL_storage_class_specifier = 76,   /* storage_class_specifier  */
  YYSYMBOL_type_qualifier_opt = 77,        /* type_qualifier_opt  */
  YYSYMBOL_type_qualifier = 78,            /* type_qualifier  */
  YYSYMBOL_init_declarator_list_opt = 79,  /* init_declarator_list_opt  */
  YYSYMBOL_init_declarator_list = 80,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 81,           /* init_declarator  */
  YYSYMBOL_type_specifier = 82,            /* type_specifier  */
  YYSYMBOL_struct_specifier = 83,          /* struct_specifier  */
  YYSYMBOL_84_3 = 84,                      /* @3  */
  YYSYMBOL_85_4 = 85,                      /* @4  */
  YYSYMBOL_86_5 = 86,                      /* @5  */
  YYSYMBOL_87_6 = 87,                      /* @6  */
  YYSYMBOL_struct_or_union = 88,           /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 89,   /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 90,        /* struct_declaration  */
  YYSYMBOL_struct_declarator_list = 91,    /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 92,         /* struct_declarator  */
  YYSYMBOL_enum_specifier = 93,            /* enum_specifier  */
  YYSYMBOL_94_7 = 94,                      /* @7  */
  YYSYMBOL_95_8 = 95,                      /* @8  */
  YYSYMBOL_enumerator_list = 96,           /* enumerator_list  */
  YYSYMBOL_enumerator = 97,                /* enumerator  */
  YYSYMBOL_98_9 = 98,                      /* @9  */
  YYSYMBOL_declarator = 99,                /* declarator  */
  YYSYMBOL_pointer = 100,                  /* pointer  */
  YYSYMBOL_direct_declarator = 101,        /* direct_declarator  */
  YYSYMBOL_102_10 = 102,                   /* @10  */
  YYSYMBOL_constant_expression_opt = 103,  /* constant_expression_opt  */
  YYSYMBOL_parameter_type_list_opt = 104,  /* parameter_type_list_opt  */
  YYSYMBOL_parameter_type_list = 105,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 106,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 107,    /* parameter_declaration  */
  YYSYMBOL_abstract_declarator_opt = 108,  /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 109,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 110, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 111,              /* initializer  */
  YYSYMBOL_initializer_list = 112,         /* initializer_list  */
  YYSYMBOL_statement_list_opt = 113,       /* statement_list_opt  */
  YYSYMBOL_statement_list = 114,           /* statement_list  */
  YYSYMBOL_statement = 115,                /* statement  */
  YYSYMBOL_labeled_statement = 116,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 117,       /* compound_statement  */
  YYSYMBOL_expression_statement = 118,     /* expression_statement  */
  YYSYMBOL_selection_statement = 119,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 120,      /* iteration_statement  */
  YYSYMBOL_for_expression = 121,           /* for_expression  */
  YYSYMBOL_expression_opt = 122,           /* expression_opt  */
  YYSYMBOL_jump_statement = 123,           /* jump_statement  */
  YYSYMBOL_primary_expression = 124,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 125,       /* postfix_expression  */
  YYSYMBOL_arg_expression_list_opt = 126,  /* arg_expression_list_opt  */
  YYSYMBOL_arg_expression_list = 127,      /* arg_expression_list  */
  YYSYMBOL_unary_expression = 128,         /* unary_expression  */
  YYSYMBOL_cast_expression = 129,          /* cast_expression  */
  YYSYMBOL_type_name = 130,                /* type_name  */
  YYSYMBOL_multiplicative_expression = 131, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 132,      /* additive_expression  */
  YYSYMBOL_shift_expression = 133,         /* shift_expression  */
  YYSYMBOL_relational_expression = 134,    /* relational_expression  */
  YYSYMBOL_equality_expression = 135,      /* equality_expression  */
  YYSYMBOL_bitwise_and_expression = 136,   /* bitwise_and_expression  */
  YYSYMBOL_bitwise_xor_expression = 137,   /* bitwise_xor_expression  */
  YYSYMBOL_bitwise_or_expression = 138,    /* bitwise_or_expression  */
  YYSYMBOL_logical_AND_expression = 139,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 140,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 141,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 142,    /* assignment_expression  */
  YYSYMBOL_expression = 143,               /* expression  */
  YYSYMBOL_constant_expression = 144       /* constant_expression  */
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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   546

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  294

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    19,    19,    23,    24,    27,    28,    31,    31,    33,
      33,    37,    38,    41,    42,    45,    48,    49,    50,    51,
      54,    54,    54,    57,    58,    61,    64,    65,    68,    69,
      72,    73,    76,    77,    78,    83,    84,    82,    86,    86,
      86,    89,    93,    94,    97,    98,   101,   106,   107,   110,
     115,   114,   117,   117,   119,   123,   124,   127,   130,   129,
     134,   135,   138,   139,   143,   144,   145,   147,   147,   153,
     154,   157,   158,   161,   162,   165,   166,   169,   171,   175,
     176,   179,   180,   181,   184,   185,   187,   189,   191,   195,
     196,   199,   200,   203,   204,   207,   208,   211,   212,   213,
     214,   215,   216,   220,   222,   227,   232,   233,   237,   239,
     241,   245,   247,   249,   253,   257,   258,   261,   263,   265,
     269,   271,   272,   273,   274,   275,   278,   279,   281,   283,
     285,   287,   289,   293,   294,   298,   300,   305,   306,   308,
     310,   312,   314,   316,   318,   320,   322,   327,   328,   333,
     338,   339,   341,   343,   348,   349,   351,   356,   360,   361,
     363,   365,   367,   372,   373,   375,   385,   389,   393,   397,
     398,   403,   404,   409,   413,   414,   419,   423
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
  "\"end of file\"", "error", "\"invalid token\"", "AUTO_SYM",
  "BREAK_SYM", "CASE_SYM", "CONTINUE_SYM", "DEFAULT_SYM", "DO_SYM",
  "ELSE_SYM", "ENUM_SYM", "FOR_SYM", "IF_SYM", "RETURN_SYM", "SIZEOF_SYM",
  "STATIC_SYM", "STRUCT_SYM", "SWITCH_SYM", "TYPEDEF_SYM", "UNION_SYM",
  "WHILE_SYM", "PLUSPLUS", "MINUSMINUS", "ARROW", "LSS", "GTR", "LEQ",
  "GEQ", "EQL", "NEQ", "AMPAMP", "BARBAR", "DOTDOTDOT", "LP", "RP", "LB",
  "RB", "LR", "RR", "COLON", "PERIOD", "COMMA", "EXCL", "STAR", "SLASH",
  "PERCENT", "AMP", "SEMICOLON", "PLUS", "MINUS", "ASSIGN",
  "INTEGER_CONSTANT", "FLOAT_CONSTANT", "STRING_LITERAL",
  "CHARACTER_CONSTANT", "CONST_SYM", "ACCENT", "BAR", "QUESTION", "TILDE",
  "IDENTIFIER", "TYPE_IDENTIFIER", "GOTO_SYM", "LSHIFT", "RSHIFT",
  "$accept", "program", "translation_unit", "external_declaration",
  "function_definition", "@1", "@2", "declaration_list_opt",
  "declaration_list", "declaration", "declaration_specifiers",
  "storage_class_specifier", "type_qualifier_opt", "type_qualifier",
  "init_declarator_list_opt", "init_declarator_list", "init_declarator",
  "type_specifier", "struct_specifier", "@3", "@4", "@5", "@6",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "enum_specifier", "@7",
  "@8", "enumerator_list", "enumerator", "@9", "declarator", "pointer",
  "direct_declarator", "@10", "constant_expression_opt",
  "parameter_type_list_opt", "parameter_type_list", "parameter_list",
  "parameter_declaration", "abstract_declarator_opt",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement_list_opt", "statement_list", "statement",
  "labeled_statement", "compound_statement", "expression_statement",
  "selection_statement", "iteration_statement", "for_expression",
  "expression_opt", "jump_statement", "primary_expression",
  "postfix_expression", "arg_expression_list_opt", "arg_expression_list",
  "unary_expression", "cast_expression", "type_name",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "bitwise_and_expression",
  "bitwise_xor_expression", "bitwise_or_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_expression", "expression",
  "constant_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-221)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     291,  -221,   -28,  -221,  -221,  -221,  -221,    54,    -6,  -221,
    -221,    66,   291,  -221,  -221,  -221,    54,    60,    60,  -221,
      36,  -221,  -221,     0,   -10,    69,    83,    78,  -221,    79,
    -221,  -221,  -221,    26,    87,  -221,    -8,  -221,  -221,    95,
     137,   140,   -10,  -221,   427,   145,   113,  -221,  -221,  -221,
      54,   391,   140,   146,  -221,    60,  -221,    60,   450,   486,
     486,   223,   427,   427,   427,   427,   427,  -221,  -221,  -221,
    -221,  -221,   152,  -221,   163,   139,  -221,   136,    -4,  -221,
     126,   135,  -221,  -221,  -221,   162,   166,  -221,  -221,  -221,
    -221,   113,   143,    39,  -221,  -221,   150,   391,  -221,  -221,
    -221,  -221,    31,   355,    60,  -221,    54,    -5,   167,  -221,
     161,  -221,   223,  -221,   427,  -221,  -221,    68,   184,   185,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,   160,
     427,   427,   164,   427,   427,   427,   427,   427,   427,   427,
     427,   427,   427,   427,   427,   427,   427,    67,   171,  -221,
     113,  -221,    75,    31,    54,    88,  -221,   175,   427,   176,
     186,   355,   194,   195,   427,   196,   197,  -221,   193,   355,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,   188,  -221,   270,
     427,  -221,    55,  -221,  -221,    29,  -221,    21,   198,   322,
      84,  -221,   427,  -221,  -221,   206,   202,  -221,   210,  -221,
    -221,  -221,  -221,  -221,   136,   136,  -221,  -221,  -221,  -221,
     126,   126,  -221,   162,  -221,   427,  -221,  -221,   391,   138,
     -21,  -221,  -221,  -221,  -221,  -221,   208,  -221,   355,   230,
     427,   427,   204,  -221,   427,   427,  -221,  -221,  -221,   218,
     219,   221,    29,    60,   427,  -221,  -221,  -221,  -221,  -221,
     427,  -221,  -221,  -221,  -221,    54,  -221,   355,  -221,   222,
     220,   211,   225,  -221,   226,   227,  -221,  -221,  -221,   228,
     231,  -221,  -221,  -221,   427,   355,   427,   355,   355,   355,
    -221,  -221,   234,  -221,   217,   261,  -221,  -221,   232,   427,
     355,  -221,  -221,  -221
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    52,    21,    42,    22,    43,     0,    23,    64,
      34,     0,     2,     3,     5,     6,    26,    17,    16,    32,
      38,    33,     9,     0,    61,    54,     0,     0,    25,    62,
      24,     1,     4,     0,    27,    28,    30,    19,    18,    41,
       0,     0,    60,    67,    69,     0,     0,    65,    63,    15,
       0,     0,     0,     0,    39,    11,    10,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,   122,   124,
     123,   120,     0,   126,   137,   147,   150,   154,   157,   158,
     163,   166,   167,   168,   169,   171,   173,   174,   176,   177,
      70,     0,    57,     0,    55,    29,    30,     0,    31,    89,
       8,    36,     0,    93,    12,    13,    26,    79,     0,    72,
      73,    75,     0,   145,     0,   138,   139,    79,     0,     0,
     147,   142,   141,   140,   144,   143,    66,   131,   132,     0,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,    91,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,     0,     0,   115,     0,     0,   106,     0,    94,
      95,    97,    98,    99,   100,   101,   102,     0,    14,    71,
      69,    77,    81,    78,    80,    82,    68,     0,     0,    71,
      81,   149,     0,   125,   130,     0,   134,   135,     0,   129,
     175,   151,   152,   153,   155,   156,   159,   160,   161,   162,
     164,   165,   170,   172,    51,     0,    56,    90,     0,     0,
       0,    47,    49,    40,    45,   119,     0,   118,     0,     0,
     115,     0,     0,   116,     0,     0,   105,    96,   107,     0,
       0,     0,    83,    71,    69,    74,    76,   146,   148,   128,
       0,   127,    59,    92,    37,     0,    46,     0,   104,     0,
       0,     0,     0,   117,     0,     0,    86,    84,    85,     0,
       0,   136,    48,   103,     0,     0,   115,     0,     0,     0,
      88,    87,     0,   113,     0,   108,   110,   111,     0,   115,
       0,   112,   114,   109
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,  -221,   266,  -221,  -221,  -221,  -221,  -221,   -37,
      34,  -221,  -221,  -221,  -221,  -221,   237,   -94,  -221,  -221,
    -221,  -221,  -221,  -221,   128,  -148,  -221,    35,  -221,  -221,
    -221,   191,   141,  -221,    -7,   -24,   -20,  -221,  -163,   -56,
    -221,  -221,   105,   178,  -121,   -80,   -91,  -221,  -221,  -221,
    -134,  -221,    13,  -221,  -221,  -221,  -221,  -220,  -221,  -221,
    -221,  -221,  -221,    71,   -50,   181,    30,  -221,    19,    27,
    -221,  -221,  -221,   151,   153,  -221,  -221,  -111,   -40,   -49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    11,    12,    13,    14,    52,    41,   103,   104,    15,
     107,    17,    29,    30,    33,    34,    35,    18,    19,    53,
     153,    40,   102,    20,   155,   156,   220,   221,    21,    45,
      26,    93,    94,   148,    22,    23,    24,    57,    72,   239,
     109,   110,   111,   183,   184,   185,    98,   152,   168,   169,
     170,   171,   172,   173,   174,   175,   260,   232,   176,    73,
      74,   195,   196,    75,    76,   118,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,   177,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,   108,    99,    42,    89,    48,   151,   224,   154,    36,
     261,    89,   121,   122,   123,   124,   125,   241,   105,   197,
     255,   119,   200,    43,     1,    44,   256,   229,   179,    -7,
     180,     2,    25,     7,    16,   237,     3,     4,     8,     5,
       6,     2,    51,    96,   137,   138,    16,     4,    99,    28,
       6,    37,    38,   245,    56,     9,   284,    89,   240,   154,
       9,   154,   243,     1,   244,   100,    31,   178,   240,   292,
       2,   224,   119,    49,   119,     3,     4,   149,     5,     6,
     150,   270,    10,   182,   201,   202,   203,     7,   179,   106,
     180,   198,    10,   190,   258,   117,    39,     8,     2,    96,
     181,   189,   242,   180,     4,   214,   -50,     6,   150,   226,
     242,     8,    47,   217,     9,     9,   218,   189,    89,   180,
      46,    10,     8,   273,   233,   154,   223,   253,    50,   113,
     115,   116,   -35,   120,   120,   120,   120,   120,   106,   271,
      89,   283,   248,   285,   286,   287,   117,   222,     2,    10,
     139,   140,   141,   142,     4,   182,   293,     6,   206,   207,
     208,   209,    42,   143,   144,   190,   252,   204,   205,    99,
     210,   211,    27,    92,    54,    89,   254,    55,    89,   134,
     135,   136,    91,   101,   127,   128,   129,   269,   126,   133,
     233,   262,   145,   -58,   264,   265,   130,   146,   131,    10,
      51,   186,   187,   132,    89,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   192,   193,
     194,   215,   225,   227,   199,   228,     1,   230,   231,   234,
     235,   236,   247,     2,   282,   238,   233,    58,     3,     4,
     249,     5,     6,   250,    59,    60,   251,   257,   222,   233,
     259,   263,   266,   267,   275,   274,    61,   268,   276,   277,
     278,   279,   280,   120,   289,    62,    63,   281,   288,    64,
     290,    65,    66,     1,    67,    68,    69,    70,    32,   291,
       2,   219,   147,    71,    10,     3,     4,    95,     5,     6,
     272,   216,   246,   188,     1,   191,   212,     0,     0,   213,
       0,     2,     0,   179,     0,   180,     3,     4,     0,     5,
       6,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     1,     0,     0,     0,     0,
       9,    10,     2,     0,     8,     0,     0,     3,     4,     0,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    10,     0,     0,   189,     0,   180,     0,   157,
     158,   159,   160,   161,     0,     8,   162,   163,   164,    58,
       0,     0,   165,     0,     0,   166,    59,    60,     0,     0,
       0,     0,     0,    10,     0,     0,     0,     0,    61,     0,
       0,     0,    55,     0,     0,     0,     0,    62,    63,     0,
       0,    64,   167,    65,    66,    58,    67,    68,    69,    70,
       0,     0,    59,    60,     0,    71,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,     0,    97,     0,
       0,     0,     0,    62,    63,     0,     0,    64,     0,    65,
      66,    58,    67,    68,    69,    70,     0,     0,    59,    60,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,     0,    58,     0,     0,     0,     0,    62,
      63,    59,    60,    64,     0,    65,    66,     0,    67,    68,
      69,    70,     0,   112,     0,     0,     0,    71,     0,     0,
       0,     0,    62,    63,     0,     0,    64,     0,    65,    66,
      58,    67,    68,    69,    70,     0,     0,    59,    60,     0,
      71,     0,     0,     0,     0,     0,     0,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63,
       0,     0,    64,     0,    65,    66,     0,    67,    68,    69,
      70,     0,     0,     0,     0,     0,    71
};

static const yytype_int16 yycheck[] =
{
       7,    57,    51,    23,    44,    29,    97,   155,   102,    16,
     230,    51,    62,    63,    64,    65,    66,   180,    55,   130,
      41,    61,   133,    33,     3,    35,    47,   161,    33,    37,
      35,    10,    60,    33,     0,   169,    15,    16,    43,    18,
      19,    10,    50,    50,    48,    49,    12,    16,    97,    55,
      19,    17,    18,    32,    41,    60,   276,    97,   179,   153,
      60,   155,    33,     3,    35,    52,     0,   104,   189,   289,
      10,   219,   112,    47,   114,    15,    16,    38,    18,    19,
      41,   244,    61,   107,   134,   135,   136,    33,    33,    55,
      35,   131,    61,   117,   228,    61,    60,    43,    10,   106,
     107,    33,   182,    35,    16,    38,    37,    19,    41,   158,
     190,    43,    34,    38,    60,    60,    41,    33,   158,    35,
      37,    61,    43,   257,   164,   219,    38,   218,    41,    58,
      59,    60,    37,    62,    63,    64,    65,    66,   104,   250,
     180,   275,   192,   277,   278,   279,   112,   154,    10,    61,
      24,    25,    26,    27,    16,   179,   290,    19,   139,   140,
     141,   142,   182,    28,    29,   189,   215,   137,   138,   218,
     143,   144,   179,    60,    37,   215,    38,    37,   218,    43,
      44,    45,    37,    37,    21,    22,    23,   243,    36,    50,
     230,   231,    30,    50,   234,   235,    33,    31,    35,    61,
      50,    34,    41,    40,   244,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    34,    34,
      60,    50,    47,    47,    60,    39,     3,    33,    33,    33,
      33,    38,    34,    10,   274,    47,   276,    14,    15,    16,
      34,    18,    19,    41,    21,    22,    36,    39,   255,   289,
      20,    47,    34,    34,    34,    33,    33,    36,    47,    34,
      34,    34,    34,   192,    47,    42,    43,    36,    34,    46,
       9,    48,    49,     3,    51,    52,    53,    54,    12,    47,
      10,   153,    91,    60,    61,    15,    16,    50,    18,    19,
     255,   150,   187,   112,     3,   117,   145,    -1,    -1,   146,
      -1,    10,    -1,    33,    -1,    35,    15,    16,    -1,    18,
      19,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,     3,    -1,    -1,    -1,    -1,
      60,    61,    10,    -1,    43,    -1,    -1,    15,    16,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    33,    -1,    35,    -1,     4,
       5,     6,     7,     8,    -1,    43,    11,    12,    13,    14,
      -1,    -1,    17,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    46,    47,    48,    49,    14,    51,    52,    53,    54,
      -1,    -1,    21,    22,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    46,    -1,    48,
      49,    14,    51,    52,    53,    54,    -1,    -1,    21,    22,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    42,
      43,    21,    22,    46,    -1,    48,    49,    -1,    51,    52,
      53,    54,    -1,    33,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    46,    -1,    48,    49,
      14,    51,    52,    53,    54,    -1,    -1,    21,    22,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    46,    -1,    48,    49,    -1,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    10,    15,    16,    18,    19,    33,    43,    60,
      61,    66,    67,    68,    69,    74,    75,    76,    82,    83,
      88,    93,    99,   100,   101,    60,    95,    99,    55,    77,
      78,     0,    68,    79,    80,    81,    99,    75,    75,    60,
      86,    71,   101,    33,    35,    94,    37,    34,   100,    47,
      41,    50,    70,    84,    37,    37,   117,   102,    14,    21,
      22,    33,    42,    43,    46,    48,    49,    51,    52,    53,
      54,    60,   103,   124,   125,   128,   129,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    37,    60,    96,    97,    81,    99,    37,   111,   144,
     117,    37,    87,    72,    73,    74,    75,    75,   104,   105,
     106,   107,    33,   128,    33,   128,   128,    75,   130,   143,
     128,   129,   129,   129,   129,   129,    36,    21,    22,    23,
      33,    35,    40,    50,    43,    44,    45,    48,    49,    24,
      25,    26,    27,    28,    29,    30,    31,    96,    98,    38,
      41,   111,   112,    85,    82,    89,    90,     4,     5,     6,
       7,     8,    11,    12,    13,    17,    20,    47,   113,   114,
     115,   116,   117,   118,   119,   120,   123,   143,    74,    33,
      35,    99,   100,   108,   109,   110,    34,    41,   130,    33,
     100,   108,    34,    34,    60,   126,   127,   142,   143,    60,
     142,   129,   129,   129,   131,   131,   133,   133,   133,   133,
     134,   134,   138,   139,    38,    50,    97,    38,    41,    89,
      91,    92,    99,    38,    90,    47,   144,    47,    39,   115,
      33,    33,   122,   143,    33,    33,    38,   115,    47,   104,
     109,   103,   110,    33,    35,    32,   107,    34,   129,    34,
      41,    36,   144,   111,    38,    41,    47,    39,   115,    20,
     121,   122,   143,    47,   143,   143,    34,    34,    36,   104,
     103,   142,    92,   115,    33,    34,    47,    34,    34,    34,
      34,    36,   143,   115,   122,   115,   115,   115,    34,    47,
       9,    47,   122,   115
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    70,    69,    71,
      69,    72,    72,    73,    73,    74,    75,    75,    75,    75,
      76,    76,    76,    77,    77,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    82,    84,    85,    83,    86,    87,
      83,    83,    88,    88,    89,    89,    90,    91,    91,    92,
      94,    93,    95,    93,    93,    96,    96,    97,    98,    97,
      99,    99,   100,   100,   101,   101,   101,   102,   101,   103,
     103,   104,   104,   105,   105,   106,   106,   107,   107,   108,
     108,   109,   109,   109,   110,   110,   110,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   115,
     115,   115,   115,   116,   116,   117,   118,   118,   119,   119,
     119,   120,   120,   120,   121,   122,   122,   123,   123,   123,
     124,   124,   124,   124,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   129,   129,   130,
     131,   131,   131,   131,   132,   132,   132,   133,   134,   134,
     134,   134,   134,   135,   135,   135,   136,   137,   138,   139,
     139,   140,   140,   141,   142,   142,   143,   144
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     4,     0,
       3,     0,     1,     1,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     0,     1,     1,     0,     1,     1,     3,
       1,     3,     1,     1,     1,     0,     0,     7,     0,     0,
       6,     2,     1,     1,     1,     2,     3,     1,     3,     1,
       0,     6,     0,     5,     2,     1,     3,     1,     0,     4,
       2,     1,     2,     3,     1,     3,     4,     0,     5,     0,
       1,     0,     1,     1,     3,     1,     3,     2,     2,     0,
       1,     1,     1,     2,     3,     3,     3,     4,     4,     1,
       3,     1,     3,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     4,     3,     4,     1,     2,     5,     7,
       5,     5,     7,     5,     5,     0,     1,     3,     2,     2,
       1,     1,     1,     1,     1,     3,     1,     4,     4,     3,
       3,     2,     2,     0,     1,     1,     3,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     4,     1,     4,     2,
       1,     3,     3,     3,     1,     3,     3,     1,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     3,     1,     1
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
  case 2: /* program: translation_unit  */
#line 20 "lee.y"
        {root = makeNode(N_PROGRAM, NIL, yyvsp[0], NIL); checkForwardReference();}
#line 1665 "y.tab.c"
    break;

  case 3: /* translation_unit: external_declaration  */
#line 23 "lee.y"
                            {yyval = yyvsp[0];}
#line 1671 "y.tab.c"
    break;

  case 4: /* translation_unit: translation_unit external_declaration  */
#line 24 "lee.y"
                                            {yyval = linkDeclaratorList(yyvsp[-1], yyvsp[0]);}
#line 1677 "y.tab.c"
    break;

  case 5: /* external_declaration: function_definition  */
#line 27 "lee.y"
                            {yyval = yyvsp[0];}
#line 1683 "y.tab.c"
    break;

  case 6: /* external_declaration: declaration  */
#line 28 "lee.y"
                    {yyval = yyvsp[0];}
#line 1689 "y.tab.c"
    break;

  case 7: /* @1: %empty  */
#line 31 "lee.y"
                                        {yyval = setFunctionDeclaratorSpecifier(yyvsp[0], yyvsp[-1]);}
#line 1695 "y.tab.c"
    break;

  case 8: /* function_definition: declaration_specifiers declarator @1 compound_statement  */
#line 32 "lee.y"
                        {yyval = setFunctionDeclaratorBody(yyvsp[-1], yyvsp[0]);}
#line 1701 "y.tab.c"
    break;

  case 9: /* @2: %empty  */
#line 33 "lee.y"
                 {yyval = setFunctionDeclaratorSpecifier(yyvsp[0], makeSpecifier(int_type, 0));}
#line 1707 "y.tab.c"
    break;

  case 10: /* function_definition: declarator @2 compound_statement  */
#line 34 "lee.y"
                        {yyval = setFunctionDeclaratorBody(yyvsp[-1], yyvsp[0]);}
#line 1713 "y.tab.c"
    break;

  case 11: /* declaration_list_opt: %empty  */
#line 37 "lee.y"
                  {yyval = NIL;}
#line 1719 "y.tab.c"
    break;

  case 12: /* declaration_list_opt: declaration_list  */
#line 38 "lee.y"
                       {yyval = yyvsp[0];}
#line 1725 "y.tab.c"
    break;

  case 13: /* declaration_list: declaration  */
#line 41 "lee.y"
                  {yyval = yyvsp[0];}
#line 1731 "y.tab.c"
    break;

  case 14: /* declaration_list: declaration_list declaration  */
#line 42 "lee.y"
                                   {yyval = linkDeclaratorList(yyvsp[-1],yyvsp[0]);}
#line 1737 "y.tab.c"
    break;

  case 15: /* declaration: declaration_specifiers init_declarator_list_opt SEMICOLON  */
#line 45 "lee.y"
                                                                {yyval = setDeclaratorListSpecifier(yyvsp[-1], yyvsp[-2]);}
#line 1743 "y.tab.c"
    break;

  case 16: /* declaration_specifiers: type_specifier  */
#line 48 "lee.y"
                     {yyval = makeSpecifier(yyvsp[0], 0);}
#line 1749 "y.tab.c"
    break;

  case 17: /* declaration_specifiers: storage_class_specifier  */
#line 49 "lee.y"
                              {yyval = makeSpecifier(0, yyvsp[0]);}
#line 1755 "y.tab.c"
    break;

  case 18: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 50 "lee.y"
                                            {yyval = updateSpecifier(yyvsp[0], yyvsp[-1], 0);}
#line 1761 "y.tab.c"
    break;

  case 19: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 51 "lee.y"
                                                     {yyval = updateSpecifier(yyvsp[0], 0, yyvsp[-1]);}
#line 1767 "y.tab.c"
    break;

  case 20: /* storage_class_specifier: AUTO_SYM  */
#line 54 "lee.y"
               {yyval = S_AUTO;}
#line 1773 "y.tab.c"
    break;

  case 21: /* storage_class_specifier: STATIC_SYM  */
#line 54 "lee.y"
                                           {yyval = S_STATIC;}
#line 1779 "y.tab.c"
    break;

  case 22: /* storage_class_specifier: TYPEDEF_SYM  */
#line 54 "lee.y"
                                                                          {yyval = S_TYPEDEF;}
#line 1785 "y.tab.c"
    break;

  case 26: /* init_declarator_list_opt: %empty  */
#line 64 "lee.y"
                    {yyval = makeDummyIdentifier();}
#line 1791 "y.tab.c"
    break;

  case 27: /* init_declarator_list_opt: init_declarator_list  */
#line 65 "lee.y"
                           {yyval = yyvsp[0];}
#line 1797 "y.tab.c"
    break;

  case 28: /* init_declarator_list: init_declarator  */
#line 68 "lee.y"
                      {yyval = yyvsp[0];}
#line 1803 "y.tab.c"
    break;

  case 29: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 69 "lee.y"
                                                 {yyval = linkDeclaratorList(yyvsp[-2], yyvsp[0]);}
#line 1809 "y.tab.c"
    break;

  case 30: /* init_declarator: declarator  */
#line 72 "lee.y"
                 {yyval = yyvsp[0];}
#line 1815 "y.tab.c"
    break;

  case 31: /* init_declarator: declarator ASSIGN initializer  */
#line 73 "lee.y"
                                    {yyval = setDeclaratorInit(yyvsp[-2], yyvsp[0]);}
#line 1821 "y.tab.c"
    break;

  case 32: /* type_specifier: struct_specifier  */
#line 76 "lee.y"
                       {yyval = yyvsp[0];}
#line 1827 "y.tab.c"
    break;

  case 33: /* type_specifier: enum_specifier  */
#line 77 "lee.y"
                     {yyval = yyvsp[0];}
#line 1833 "y.tab.c"
    break;

  case 34: /* type_specifier: TYPE_IDENTIFIER  */
#line 78 "lee.y"
                      {yyval = yyvsp[0];}
#line 1839 "y.tab.c"
    break;

  case 35: /* @3: %empty  */
#line 83 "lee.y"
    {yyval = setTypeStructOrEnumIdentifier(yyvsp[-1], yyvsp[0], ID_STRUCT);}
#line 1845 "y.tab.c"
    break;

  case 36: /* @4: %empty  */
#line 84 "lee.y"
       {yyval = current_id; current_level++;}
#line 1851 "y.tab.c"
    break;

  case 37: /* struct_specifier: struct_or_union IDENTIFIER @3 LR @4 struct_declaration_list RR  */
#line 85 "lee.y"
    {checkForwardReference(); yyval = setTypeField(yyvsp[-4], yyvsp[-1]); current_level--; current_id = yyvsp[-2];}
#line 1857 "y.tab.c"
    break;

  case 38: /* @5: %empty  */
#line 86 "lee.y"
                      {yyval = makeType(yyvsp[0]);}
#line 1863 "y.tab.c"
    break;

  case 39: /* @6: %empty  */
#line 86 "lee.y"
                                              {yyval = current_id; current_level++;}
#line 1869 "y.tab.c"
    break;

  case 40: /* struct_specifier: struct_or_union @5 LR @6 struct_declaration_list RR  */
#line 87 "lee.y"
                                {checkForwardReference(); yyval = setTypeField(yyvsp[-4], yyvsp[-1]);
     current_level--; current_id = yyvsp[-2];}
#line 1876 "y.tab.c"
    break;

  case 41: /* struct_specifier: struct_or_union IDENTIFIER  */
#line 90 "lee.y"
    {yyval = getTypeOfStructOrEnumRefIdentifier(yyvsp[-1], yyvsp[0], ID_STRUCT);}
#line 1882 "y.tab.c"
    break;

  case 42: /* struct_or_union: STRUCT_SYM  */
#line 93 "lee.y"
                 {yyval = T_STRUCT;}
#line 1888 "y.tab.c"
    break;

  case 43: /* struct_or_union: UNION_SYM  */
#line 94 "lee.y"
                {yyval = T_UNION;}
#line 1894 "y.tab.c"
    break;

  case 44: /* struct_declaration_list: struct_declaration  */
#line 97 "lee.y"
                         {yyval = yyvsp[0];}
#line 1900 "y.tab.c"
    break;

  case 45: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 98 "lee.y"
                                                 {yyval = linkDeclaratorList(yyvsp[-1], yyvsp[0]);}
#line 1906 "y.tab.c"
    break;

  case 46: /* struct_declaration: type_specifier struct_declarator_list SEMICOLON  */
#line 102 "lee.y"
    {yyval = setStructDeclaratorListSpecifier(yyvsp[-1], yyvsp[-2]);}
#line 1912 "y.tab.c"
    break;

  case 47: /* struct_declarator_list: struct_declarator  */
#line 106 "lee.y"
                        {yyval = yyvsp[0];}
#line 1918 "y.tab.c"
    break;

  case 48: /* struct_declarator_list: struct_declarator_list COMMA struct_declarator  */
#line 107 "lee.y"
                                                     {yyval = linkDeclaratorList(yyvsp[-2], yyvsp[0]);}
#line 1924 "y.tab.c"
    break;

  case 49: /* struct_declarator: declarator  */
#line 110 "lee.y"
                 {yyval = yyvsp[0];}
#line 1930 "y.tab.c"
    break;

  case 50: /* @7: %empty  */
#line 115 "lee.y"
      {yyval = setTypeStructOrEnumIdentifier(T_ENUM, yyvsp[0], ID_ENUM);}
#line 1936 "y.tab.c"
    break;

  case 51: /* enum_specifier: ENUM_SYM IDENTIFIER @7 LR enumerator_list RR  */
#line 116 "lee.y"
                           {yyval = setTypeField(yyvsp[-3], yyvsp[-1]);}
#line 1942 "y.tab.c"
    break;

  case 52: /* @8: %empty  */
#line 117 "lee.y"
               {yyval = makeType(T_ENUM);}
#line 1948 "y.tab.c"
    break;

  case 53: /* enum_specifier: ENUM_SYM @8 LR enumerator_list RR  */
#line 118 "lee.y"
                          {yyval = setTypeField(yyvsp[-3], yyvsp[-1]);}
#line 1954 "y.tab.c"
    break;

  case 54: /* enum_specifier: ENUM_SYM IDENTIFIER  */
#line 120 "lee.y"
    {yyval = getTypeOfStructOrEnumRefIdentifier(T_ENUM, yyvsp[0], ID_ENUM);}
#line 1960 "y.tab.c"
    break;

  case 55: /* enumerator_list: enumerator  */
#line 123 "lee.y"
                 {yyval = yyvsp[0];}
#line 1966 "y.tab.c"
    break;

  case 56: /* enumerator_list: enumerator_list COMMA enumerator  */
#line 124 "lee.y"
                                       {yyval = linkDeclaratorList(yyvsp[-2], yyvsp[0]);}
#line 1972 "y.tab.c"
    break;

  case 57: /* enumerator: IDENTIFIER  */
#line 128 "lee.y"
    {yyval = setDeclaratorKind(makeIdentifier(yyvsp[0]), ID_ENUM_LITERAL);}
#line 1978 "y.tab.c"
    break;

  case 58: /* @9: %empty  */
#line 130 "lee.y"
     {yyval = setDeclaratorKind(makeIdentifier(yyvsp[0]), ID_ENUM_LITERAL);}
#line 1984 "y.tab.c"
    break;

  case 59: /* enumerator: IDENTIFIER @9 ASSIGN constant_expression  */
#line 131 "lee.y"
                                {yyval=setDeclaratorInit(yyvsp[-2], yyvsp[0]);}
#line 1990 "y.tab.c"
    break;

  case 60: /* declarator: pointer direct_declarator  */
#line 134 "lee.y"
                                {yyval = setDeclaratorElementType(yyvsp[0], yyvsp[-1]);}
#line 1996 "y.tab.c"
    break;

  case 61: /* declarator: direct_declarator  */
#line 135 "lee.y"
                        {yyval = yyvsp[0];}
#line 2002 "y.tab.c"
    break;

  case 62: /* pointer: STAR type_qualifier_opt  */
#line 138 "lee.y"
                              {yyval = makeType(T_POINTER);}
#line 2008 "y.tab.c"
    break;

  case 63: /* pointer: STAR type_qualifier_opt pointer  */
#line 139 "lee.y"
                                      {yyval = setTypeElementType(yyvsp[-1], makeType(T_POINTER));}
#line 2014 "y.tab.c"
    break;

  case 64: /* direct_declarator: IDENTIFIER  */
#line 143 "lee.y"
                 {yyval = makeIdentifier(yyvsp[0]);}
#line 2020 "y.tab.c"
    break;

  case 65: /* direct_declarator: LP declarator RP  */
#line 144 "lee.y"
                       {yyval = yyvsp[-1];}
#line 2026 "y.tab.c"
    break;

  case 66: /* direct_declarator: direct_declarator LB constant_expression_opt RB  */
#line 146 "lee.y"
    {yyval = setDeclaratorElementType(yyvsp[-3], setTypeExpr(makeType(T_ARRAY), yyvsp[-1]));}
#line 2032 "y.tab.c"
    break;

  case 67: /* @10: %empty  */
#line 147 "lee.y"
                           {yyval = current_id; current_level++;}
#line 2038 "y.tab.c"
    break;

  case 68: /* direct_declarator: direct_declarator LP @10 parameter_type_list_opt RP  */
#line 149 "lee.y"
    {checkForwardReference(); current_id = yyvsp[-2]; current_level--;
    yyval = setDeclaratorElementType(yyvsp[-4], setTypeField(makeType(T_FUNC), yyvsp[-1]));}
#line 2045 "y.tab.c"
    break;

  case 69: /* constant_expression_opt: %empty  */
#line 153 "lee.y"
                  {yyval = NIL;}
#line 2051 "y.tab.c"
    break;

  case 70: /* constant_expression_opt: constant_expression  */
#line 154 "lee.y"
                          {yyval = yyvsp[0];}
#line 2057 "y.tab.c"
    break;

  case 71: /* parameter_type_list_opt: %empty  */
#line 157 "lee.y"
                  {yyval = NIL;}
#line 2063 "y.tab.c"
    break;

  case 72: /* parameter_type_list_opt: parameter_type_list  */
#line 158 "lee.y"
                          {yyval = yyvsp[0];}
#line 2069 "y.tab.c"
    break;

  case 73: /* parameter_type_list: parameter_list  */
#line 161 "lee.y"
                     {yyval = yyvsp[0];}
#line 2075 "y.tab.c"
    break;

  case 74: /* parameter_type_list: parameter_list COMMA DOTDOTDOT  */
#line 162 "lee.y"
                                     {yyval = linkDeclaratorList(yyvsp[-2], setDeclaratorKind(makeDummyIdentifier(), ID_PARM));}
#line 2081 "y.tab.c"
    break;

  case 75: /* parameter_list: parameter_declaration  */
#line 165 "lee.y"
                            {yyval = yyvsp[0];}
#line 2087 "y.tab.c"
    break;

  case 76: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 166 "lee.y"
                                                 {yyval = linkDeclaratorList(yyvsp[-2], yyvsp[0]);}
#line 2093 "y.tab.c"
    break;

  case 77: /* parameter_declaration: declaration_specifiers declarator  */
#line 170 "lee.y"
     {yyval = setParameterDeclaratorSpecifier(yyvsp[0], yyvsp[-1]);}
#line 2099 "y.tab.c"
    break;

  case 78: /* parameter_declaration: declaration_specifiers abstract_declarator_opt  */
#line 172 "lee.y"
     {yyval = setParameterDeclaratorSpecifier(setDeclaratorType(makeDummyIdentifier(), yyvsp[0]), yyvsp[-1]);}
#line 2105 "y.tab.c"
    break;

  case 79: /* abstract_declarator_opt: %empty  */
#line 175 "lee.y"
                  {yyval = NIL;}
#line 2111 "y.tab.c"
    break;

  case 80: /* abstract_declarator_opt: abstract_declarator  */
#line 176 "lee.y"
                          {yyval = yyvsp[0];}
#line 2117 "y.tab.c"
    break;

  case 81: /* abstract_declarator: pointer  */
#line 179 "lee.y"
              {yyval = makeType(T_POINTER);}
#line 2123 "y.tab.c"
    break;

  case 82: /* abstract_declarator: direct_abstract_declarator  */
#line 180 "lee.y"
                                 {yyval = yyvsp[0];}
#line 2129 "y.tab.c"
    break;

  case 83: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 181 "lee.y"
                                         {yyval = setTypeElementType(yyvsp[0], makeType(T_POINTER));}
#line 2135 "y.tab.c"
    break;

  case 84: /* direct_abstract_declarator: LP abstract_declarator RP  */
#line 184 "lee.y"
                                {yyval = yyvsp[-1];}
#line 2141 "y.tab.c"
    break;

  case 85: /* direct_abstract_declarator: LB constant_expression_opt RB  */
#line 186 "lee.y"
     {yyval = setTypeExpr(makeType(T_ARRAY), yyvsp[-1]);}
#line 2147 "y.tab.c"
    break;

  case 86: /* direct_abstract_declarator: LP parameter_type_list_opt RP  */
#line 188 "lee.y"
     {yyval = setTypeExpr(makeType(T_FUNC), yyvsp[-1]);}
#line 2153 "y.tab.c"
    break;

  case 87: /* direct_abstract_declarator: direct_abstract_declarator LB constant_expression_opt RB  */
#line 190 "lee.y"
     {yyval = setTypeElementType(yyvsp[-3], setTypeExpr(makeType(T_ARRAY), yyvsp[-1]));}
#line 2159 "y.tab.c"
    break;

  case 88: /* direct_abstract_declarator: direct_abstract_declarator LP parameter_type_list_opt RP  */
#line 192 "lee.y"
     {yyval = setTypeElementType(yyvsp[-3], setTypeExpr(makeType(T_FUNC), yyvsp[-1]));}
#line 2165 "y.tab.c"
    break;

  case 89: /* initializer: constant_expression  */
#line 195 "lee.y"
                          {yyval = makeNode(N_INIT_LIST_ONE, NIL, yyvsp[0], NIL);}
#line 2171 "y.tab.c"
    break;

  case 90: /* initializer: LR initializer_list RR  */
#line 196 "lee.y"
                             {yyval = yyvsp[-1];}
#line 2177 "y.tab.c"
    break;

  case 91: /* initializer_list: initializer  */
#line 199 "lee.y"
                  {yyval = makeNode(N_INIT_LIST, yyvsp[0], NIL, makeNode(N_INIT_LIST_NIL, NIL, NIL, NIL));}
#line 2183 "y.tab.c"
    break;

  case 92: /* initializer_list: initializer_list COMMA initializer  */
#line 200 "lee.y"
                                         {yyval = makeNodeList(N_INIT_LIST, yyvsp[-2], yyvsp[0]);}
#line 2189 "y.tab.c"
    break;

  case 93: /* statement_list_opt: %empty  */
#line 203 "lee.y"
                  {yyval = makeNode(N_STMT_LIST_NIL, NIL, NIL, NIL);}
#line 2195 "y.tab.c"
    break;

  case 94: /* statement_list_opt: statement_list  */
#line 204 "lee.y"
                     {yyval = yyvsp[0];}
#line 2201 "y.tab.c"
    break;

  case 97: /* statement: labeled_statement  */
#line 211 "lee.y"
                        {yyval = yyvsp[0];}
#line 2207 "y.tab.c"
    break;

  case 98: /* statement: compound_statement  */
#line 212 "lee.y"
                         {yyval = yyvsp[0];}
#line 2213 "y.tab.c"
    break;

  case 99: /* statement: expression_statement  */
#line 213 "lee.y"
                           {yyval = yyvsp[0];}
#line 2219 "y.tab.c"
    break;

  case 100: /* statement: selection_statement  */
#line 214 "lee.y"
                          {yyval = yyvsp[0];}
#line 2225 "y.tab.c"
    break;

  case 101: /* statement: iteration_statement  */
#line 215 "lee.y"
                          {yyval = yyvsp[0];}
#line 2231 "y.tab.c"
    break;

  case 102: /* statement: jump_statement  */
#line 216 "lee.y"
                     {yyval = yyvsp[0];}
#line 2237 "y.tab.c"
    break;

  case 103: /* labeled_statement: CASE_SYM constant_expression COLON statement  */
#line 221 "lee.y"
     {yyval = makeNode(N_STMT_LABEL_CASE, yyvsp[-2], NIL, yyvsp[0]);}
#line 2243 "y.tab.c"
    break;

  case 104: /* labeled_statement: DEFAULT_SYM COLON statement  */
#line 223 "lee.y"
     {yyval = makeNode(N_STMT_LABEL_DEFAULT, NIL, yyvsp[0], NIL);}
#line 2249 "y.tab.c"
    break;

  case 105: /* compound_statement: LR declaration_list_opt statement_list_opt RR  */
#line 228 "lee.y"
     {checkForwardReference(); yyval = makeNode(N_STMT_COMPOUND, yyvsp[-1], NIL, yyvsp[0]); current_id = yyvsp[-2];}
#line 2255 "y.tab.c"
    break;

  case 106: /* expression_statement: SEMICOLON  */
#line 232 "lee.y"
                {yyval = makeNode(N_STMT_EMPTY, NIL, NIL, NIL);}
#line 2261 "y.tab.c"
    break;

  case 107: /* expression_statement: expression SEMICOLON  */
#line 233 "lee.y"
                           {yyval = makeNode(N_STMT_EXPRESSION, NIL, yyvsp[-1], NIL);}
#line 2267 "y.tab.c"
    break;

  case 108: /* selection_statement: IF_SYM LP expression RP statement  */
#line 238 "lee.y"
     {yyval = makeNode(N_STMT_IF, yyvsp[-2], NIL, yyvsp[0]);}
#line 2273 "y.tab.c"
    break;

  case 109: /* selection_statement: IF_SYM LP expression RP statement ELSE_SYM statement  */
#line 240 "lee.y"
     {yyval = makeNode(N_STMT_IF_ELSE, yyvsp[-4], yyvsp[-2], yyvsp[0]);}
#line 2279 "y.tab.c"
    break;

  case 110: /* selection_statement: SWITCH_SYM LP expression RP statement  */
#line 242 "lee.y"
     {yyval = makeNode(N_STMT_SWITCH, yyvsp[-2], NIL, yyvsp[0]);}
#line 2285 "y.tab.c"
    break;

  case 111: /* iteration_statement: WHILE_SYM LP expression RP statement  */
#line 246 "lee.y"
     {yyval = makeNode(N_STMT_WHILE, yyvsp[-2], NIL, yyvsp[0]);}
#line 2291 "y.tab.c"
    break;

  case 112: /* iteration_statement: DO_SYM statement WHILE_SYM LP expression RP SEMICOLON  */
#line 248 "lee.y"
     {yyval = makeNode(N_STMT_DO, yyvsp[-5], NIL, yyvsp[-2]);}
#line 2297 "y.tab.c"
    break;

  case 113: /* iteration_statement: FOR_SYM LP for_expression RP statement  */
#line 250 "lee.y"
     {yyval = makeNode(N_STMT_FOR, yyvsp[-2], NIL, yyvsp[0]);}
#line 2303 "y.tab.c"
    break;

  case 114: /* for_expression: expression_opt SEMICOLON expression_opt SEMICOLON expression_opt  */
#line 254 "lee.y"
     {yyval = makeNode(N_FOR_EXP, yyvsp[-4], yyvsp[-3], yyvsp[-2]);}
#line 2309 "y.tab.c"
    break;

  case 115: /* expression_opt: %empty  */
#line 257 "lee.y"
                  {yyval = NIL;}
#line 2315 "y.tab.c"
    break;

  case 116: /* expression_opt: expression  */
#line 258 "lee.y"
                 {yyval = yyvsp[0];}
#line 2321 "y.tab.c"
    break;

  case 117: /* jump_statement: RETURN_SYM expression_opt SEMICOLON  */
#line 262 "lee.y"
     {yyval = makeNode(N_STMT_RETURN, NIL, yyvsp[-1], NIL);}
#line 2327 "y.tab.c"
    break;

  case 118: /* jump_statement: CONTINUE_SYM SEMICOLON  */
#line 264 "lee.y"
     {yyval = makeNode(N_STMT_CONTINUE, NIL, NIL, NIL);}
#line 2333 "y.tab.c"
    break;

  case 119: /* jump_statement: BREAK_SYM SEMICOLON  */
#line 266 "lee.y"
     {yyval = makeNode(N_STMT_BREAK, NIL, NIL, NIL);}
#line 2339 "y.tab.c"
    break;

  case 120: /* primary_expression: IDENTIFIER  */
#line 270 "lee.y"
     {yyval = makeNode(N_EXP_IDENT, NIL, getIdentifierDeclared(yyvsp[0]), NIL);}
#line 2345 "y.tab.c"
    break;

  case 121: /* primary_expression: INTEGER_CONSTANT  */
#line 271 "lee.y"
                       {yyval = makeNode(N_EXP_INT_CONST, NIL, yyvsp[0], NIL);}
#line 2351 "y.tab.c"
    break;

  case 122: /* primary_expression: FLOAT_CONSTANT  */
#line 272 "lee.y"
                     {yyval = makeNode(N_EXP_FLOAT_CONST, NIL, yyvsp[0], NIL);}
#line 2357 "y.tab.c"
    break;

  case 123: /* primary_expression: CHARACTER_CONSTANT  */
#line 273 "lee.y"
                         {yyval = makeNode(N_EXP_CHAR_CONST, NIL, yyvsp[0], NIL);}
#line 2363 "y.tab.c"
    break;

  case 124: /* primary_expression: STRING_LITERAL  */
#line 274 "lee.y"
                     {yyval = makeNode(N_EXP_STRING_LITERAL, NIL, yyvsp[0], NIL);}
#line 2369 "y.tab.c"
    break;

  case 125: /* primary_expression: LP expression RP  */
#line 275 "lee.y"
                       {yyval = yyvsp[-1];}
#line 2375 "y.tab.c"
    break;

  case 126: /* postfix_expression: primary_expression  */
#line 278 "lee.y"
                         {yyval = yyvsp[0];}
#line 2381 "y.tab.c"
    break;

  case 127: /* postfix_expression: postfix_expression LB expression RB  */
#line 280 "lee.y"
     {yyval = makeNode(N_EXP_ARRAY, yyvsp[-3], NIL, yyvsp[-1]);}
#line 2387 "y.tab.c"
    break;

  case 128: /* postfix_expression: postfix_expression LP arg_expression_list_opt RP  */
#line 282 "lee.y"
     {yyval = makeNode(N_EXP_FUNCTION_CALL, yyvsp[-3], NIL, yyvsp[-1]);}
#line 2393 "y.tab.c"
    break;

  case 129: /* postfix_expression: postfix_expression PERIOD IDENTIFIER  */
#line 284 "lee.y"
     {yyval = makeNode(N_EXP_STRUCT, yyvsp[-2], NIL, yyvsp[0]);}
#line 2399 "y.tab.c"
    break;

  case 130: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 286 "lee.y"
     {yyval = makeNode(N_EXP_ARROW, yyvsp[-2], NIL, yyvsp[0]);}
#line 2405 "y.tab.c"
    break;

  case 131: /* postfix_expression: postfix_expression PLUSPLUS  */
#line 288 "lee.y"
     {yyval = makeNode(N_EXP_POST_INC, NIL, yyvsp[-1], NIL);}
#line 2411 "y.tab.c"
    break;

  case 132: /* postfix_expression: postfix_expression MINUSMINUS  */
#line 290 "lee.y"
     {yyval = makeNode(N_EXP_POST_DEC, NIL, yyvsp[-1], NIL);}
#line 2417 "y.tab.c"
    break;

  case 133: /* arg_expression_list_opt: %empty  */
#line 293 "lee.y"
                  {yyval = makeNode(N_ARG_LIST, NIL, NIL, NIL);}
#line 2423 "y.tab.c"
    break;

  case 134: /* arg_expression_list_opt: arg_expression_list  */
#line 294 "lee.y"
                          {yyval = yyvsp[0];}
#line 2429 "y.tab.c"
    break;

  case 135: /* arg_expression_list: assignment_expression  */
#line 299 "lee.y"
     {yyval = makeNode(N_ARG_LIST, yyvsp[0], NIL, makeNode(N_ARG_LIST_NIL, NIL, NIL, NIL));}
#line 2435 "y.tab.c"
    break;

  case 136: /* arg_expression_list: arg_expression_list COMMA assignment_expression  */
#line 301 "lee.y"
     {yyval = makeNodeList(N_ARG_LIST, yyvsp[-2], yyvsp[0]);}
#line 2441 "y.tab.c"
    break;

  case 137: /* unary_expression: postfix_expression  */
#line 305 "lee.y"
                         {yyval = yyvsp[0];}
#line 2447 "y.tab.c"
    break;

  case 138: /* unary_expression: PLUSPLUS unary_expression  */
#line 307 "lee.y"
     {yyval = makeNode(N_EXP_PRE_INC, NIL, yyvsp[0], NIL);}
#line 2453 "y.tab.c"
    break;

  case 139: /* unary_expression: MINUSMINUS unary_expression  */
#line 309 "lee.y"
     {yyval = makeNode(N_EXP_PRE_DEC, NIL, yyvsp[0], NIL);}
#line 2459 "y.tab.c"
    break;

  case 140: /* unary_expression: AMP cast_expression  */
#line 311 "lee.y"
     {yyval = makeNode(N_EXP_AMP, NIL, yyvsp[0], NIL);}
#line 2465 "y.tab.c"
    break;

  case 141: /* unary_expression: STAR cast_expression  */
#line 313 "lee.y"
     {yyval = makeNode(N_EXP_STAR, NIL, yyvsp[0], NIL);}
#line 2471 "y.tab.c"
    break;

  case 142: /* unary_expression: EXCL cast_expression  */
#line 315 "lee.y"
     {yyval = makeNode(N_EXP_NOT, NIL, yyvsp[0], NIL);}
#line 2477 "y.tab.c"
    break;

  case 143: /* unary_expression: MINUS cast_expression  */
#line 317 "lee.y"
     {yyval = makeNode(N_EXP_MINUS, NIL, yyvsp[0], NIL);}
#line 2483 "y.tab.c"
    break;

  case 144: /* unary_expression: PLUS cast_expression  */
#line 319 "lee.y"
     {yyval = makeNode(N_EXP_PLUS, NIL, yyvsp[0], NIL);}
#line 2489 "y.tab.c"
    break;

  case 145: /* unary_expression: SIZEOF_SYM unary_expression  */
#line 321 "lee.y"
     {yyval = makeNode(N_EXP_SIZE_EXP, NIL, yyvsp[0], NIL);}
#line 2495 "y.tab.c"
    break;

  case 146: /* unary_expression: SIZEOF_SYM LP type_name RP  */
#line 323 "lee.y"
     {yyval = makeNode(N_EXP_SIZE_TYPE, NIL, yyvsp[-2], NIL);}
#line 2501 "y.tab.c"
    break;

  case 147: /* cast_expression: unary_expression  */
#line 327 "lee.y"
                       {yyval = yyvsp[0];}
#line 2507 "y.tab.c"
    break;

  case 148: /* cast_expression: LP type_name RP cast_expression  */
#line 329 "lee.y"
     {yyval = makeNode(N_EXP_CAST, yyvsp[-2], NIL, yyvsp[0]);}
#line 2513 "y.tab.c"
    break;

  case 149: /* type_name: declaration_specifiers abstract_declarator_opt  */
#line 334 "lee.y"
     {yyval = setTypeNameSpecifier(yyvsp[0], yyvsp[-1]);}
#line 2519 "y.tab.c"
    break;

  case 150: /* multiplicative_expression: cast_expression  */
#line 338 "lee.y"
                      {yyval = yyvsp[0];}
#line 2525 "y.tab.c"
    break;

  case 151: /* multiplicative_expression: multiplicative_expression STAR cast_expression  */
#line 340 "lee.y"
     {yyval = makeNode(N_EXP_MUL, yyvsp[-2], NIL, yyvsp[0]);}
#line 2531 "y.tab.c"
    break;

  case 152: /* multiplicative_expression: multiplicative_expression SLASH cast_expression  */
#line 342 "lee.y"
     {yyval = makeNode(N_EXP_DIV, yyvsp[-2], NIL, yyvsp[0]);}
#line 2537 "y.tab.c"
    break;

  case 153: /* multiplicative_expression: multiplicative_expression PERCENT cast_expression  */
#line 344 "lee.y"
     {yyval = makeNode(N_EXP_MOD, yyvsp[-2], NIL, yyvsp[0]);}
#line 2543 "y.tab.c"
    break;

  case 154: /* additive_expression: multiplicative_expression  */
#line 348 "lee.y"
                                {yyval = yyvsp[0];}
#line 2549 "y.tab.c"
    break;

  case 155: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 350 "lee.y"
     {yyval = makeNode(N_EXP_ADD, yyvsp[-2], NIL, yyvsp[0]);}
#line 2555 "y.tab.c"
    break;

  case 156: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 352 "lee.y"
     {yyval = makeNode(N_EXP_SUB, yyvsp[-2], NIL, yyvsp[0]);}
#line 2561 "y.tab.c"
    break;

  case 157: /* shift_expression: additive_expression  */
#line 356 "lee.y"
                          {yyval = yyvsp[0];}
#line 2567 "y.tab.c"
    break;

  case 158: /* relational_expression: shift_expression  */
#line 360 "lee.y"
                       {yyval = yyvsp[0];}
#line 2573 "y.tab.c"
    break;

  case 159: /* relational_expression: relational_expression LSS shift_expression  */
#line 362 "lee.y"
     {yyval = makeNode(N_EXP_LSS, yyvsp[-2], NIL, yyvsp[0]);}
#line 2579 "y.tab.c"
    break;

  case 160: /* relational_expression: relational_expression GTR shift_expression  */
#line 364 "lee.y"
     {yyval = makeNode(N_EXP_GTR, yyvsp[-2], NIL, yyvsp[0]);}
#line 2585 "y.tab.c"
    break;

  case 161: /* relational_expression: relational_expression LEQ shift_expression  */
#line 366 "lee.y"
     {yyval = makeNode(N_EXP_LEQ, yyvsp[-2], NIL, yyvsp[0]);}
#line 2591 "y.tab.c"
    break;

  case 162: /* relational_expression: relational_expression GEQ shift_expression  */
#line 368 "lee.y"
     {yyval = makeNode(N_EXP_GEQ, yyvsp[-2], NIL, yyvsp[0]);}
#line 2597 "y.tab.c"
    break;

  case 163: /* equality_expression: relational_expression  */
#line 372 "lee.y"
                            {yyval = yyvsp[0];}
#line 2603 "y.tab.c"
    break;

  case 164: /* equality_expression: equality_expression EQL relational_expression  */
#line 374 "lee.y"
     {yyval = makeNode(N_EXP_EQL, yyvsp[-2], NIL, yyvsp[0]);}
#line 2609 "y.tab.c"
    break;

  case 165: /* equality_expression: equality_expression NEQ relational_expression  */
#line 376 "lee.y"
     {yyval = makeNode(N_EXP_NEQ, yyvsp[-2], NIL, yyvsp[0]);}
#line 2615 "y.tab.c"
    break;

  case 166: /* bitwise_and_expression: equality_expression  */
#line 385 "lee.y"
                          {yyval = yyvsp[0];}
#line 2621 "y.tab.c"
    break;

  case 167: /* bitwise_xor_expression: bitwise_and_expression  */
#line 389 "lee.y"
                             {yyval = yyvsp[0];}
#line 2627 "y.tab.c"
    break;

  case 168: /* bitwise_or_expression: bitwise_xor_expression  */
#line 393 "lee.y"
                             {yyval = yyvsp[0];}
#line 2633 "y.tab.c"
    break;

  case 169: /* logical_AND_expression: bitwise_or_expression  */
#line 397 "lee.y"
                            {yyval = yyvsp[0];}
#line 2639 "y.tab.c"
    break;

  case 170: /* logical_AND_expression: logical_AND_expression AMPAMP bitwise_or_expression  */
#line 399 "lee.y"
     {yyval = makeNode(N_EXP_AND, yyvsp[-2], NIL, yyvsp[0]);}
#line 2645 "y.tab.c"
    break;

  case 171: /* logical_OR_expression: logical_AND_expression  */
#line 403 "lee.y"
                             {yyval = yyvsp[0];}
#line 2651 "y.tab.c"
    break;

  case 172: /* logical_OR_expression: logical_OR_expression BARBAR logical_AND_expression  */
#line 405 "lee.y"
     {yyval = makeNode(N_EXP_OR, yyvsp[-2], NIL, yyvsp[0]);}
#line 2657 "y.tab.c"
    break;

  case 173: /* conditional_expression: logical_OR_expression  */
#line 409 "lee.y"
                            {yyval = yyvsp[0];}
#line 2663 "y.tab.c"
    break;

  case 174: /* assignment_expression: conditional_expression  */
#line 413 "lee.y"
                             {yyval = yyvsp[0];}
#line 2669 "y.tab.c"
    break;

  case 175: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 415 "lee.y"
     {yyval = makeNode(N_EXP_ASSIGN, yyvsp[-2], NIL, yyvsp[0]);}
#line 2675 "y.tab.c"
    break;

  case 176: /* expression: assignment_expression  */
#line 419 "lee.y"
                            {yyval = yyvsp[0];}
#line 2681 "y.tab.c"
    break;

  case 177: /* constant_expression: expression  */
#line 423 "lee.y"
                 {yyval = yyvsp[0];}
#line 2687 "y.tab.c"
    break;


#line 2691 "y.tab.c"

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

