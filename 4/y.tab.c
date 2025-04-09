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
  YYSYMBOL_declaration_list_opt = 70,      /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 71,          /* declaration_list  */
  YYSYMBOL_declaration = 72,               /* declaration  */
  YYSYMBOL_declaration_specifiers = 73,    /* declaration_specifiers  */
  YYSYMBOL_storage_class_specifier = 74,   /* storage_class_specifier  */
  YYSYMBOL_type_qualifier_opt = 75,        /* type_qualifier_opt  */
  YYSYMBOL_type_qualifier = 76,            /* type_qualifier  */
  YYSYMBOL_init_declarator_list_opt = 77,  /* init_declarator_list_opt  */
  YYSYMBOL_init_declarator_list = 78,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 79,           /* init_declarator  */
  YYSYMBOL_type_specifier = 80,            /* type_specifier  */
  YYSYMBOL_struct_specifier = 81,          /* struct_specifier  */
  YYSYMBOL_struct_or_union = 82,           /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 83,   /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 84,        /* struct_declaration  */
  YYSYMBOL_struct_declarator_list = 85,    /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 86,         /* struct_declarator  */
  YYSYMBOL_enum_specifier = 87,            /* enum_specifier  */
  YYSYMBOL_enumerator_list = 88,           /* enumerator_list  */
  YYSYMBOL_enumerator = 89,                /* enumerator  */
  YYSYMBOL_declarator = 90,                /* declarator  */
  YYSYMBOL_pointer = 91,                   /* pointer  */
  YYSYMBOL_direct_declarator = 92,         /* direct_declarator  */
  YYSYMBOL_constant_expression_opt = 93,   /* constant_expression_opt  */
  YYSYMBOL_parameter_type_list_opt = 94,   /* parameter_type_list_opt  */
  YYSYMBOL_parameter_type_list = 95,       /* parameter_type_list  */
  YYSYMBOL_parameter_list = 96,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 97,     /* parameter_declaration  */
  YYSYMBOL_abstract_declarator_opt = 98,   /* abstract_declarator_opt  */
  YYSYMBOL_abstract_declarator = 99,       /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 100, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 101,              /* initializer  */
  YYSYMBOL_initializer_list = 102,         /* initializer_list  */
  YYSYMBOL_statement_list_opt = 103,       /* statement_list_opt  */
  YYSYMBOL_statement_list = 104,           /* statement_list  */
  YYSYMBOL_statement = 105,                /* statement  */
  YYSYMBOL_labeled_statement = 106,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 107,       /* compound_statement  */
  YYSYMBOL_expression_statement = 108,     /* expression_statement  */
  YYSYMBOL_selection_statement = 109,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 110,      /* iteration_statement  */
  YYSYMBOL_expression_opt = 111,           /* expression_opt  */
  YYSYMBOL_jump_statement = 112,           /* jump_statement  */
  YYSYMBOL_primary_expression = 113,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 114,       /* postfix_expression  */
  YYSYMBOL_arg_expression_list_opt = 115,  /* arg_expression_list_opt  */
  YYSYMBOL_arg_expression_list = 116,      /* arg_expression_list  */
  YYSYMBOL_unary_expression = 117,         /* unary_expression  */
  YYSYMBOL_cast_expression = 118,          /* cast_expression  */
  YYSYMBOL_type_name = 119,                /* type_name  */
  YYSYMBOL_multiplicative_expression = 120, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 121,      /* additive_expression  */
  YYSYMBOL_shift_expression = 122,         /* shift_expression  */
  YYSYMBOL_relational_expression = 123,    /* relational_expression  */
  YYSYMBOL_equality_expression = 124,      /* equality_expression  */
  YYSYMBOL_AND_expression = 125,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 126,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 127,  /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 128,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 129,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 130,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 131,    /* assignment_expression  */
  YYSYMBOL_expression = 132,               /* expression  */
  YYSYMBOL_constant_expression = 133       /* constant_expression  */
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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   552

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

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
       0,    10,    10,    13,    14,    17,    18,    21,    22,    25,
      26,    29,    30,    33,    36,    37,    38,    39,    40,    41,
      44,    44,    44,    47,    48,    51,    54,    55,    58,    59,
      62,    63,    66,    67,    68,    72,    73,    74,    77,    78,
      81,    82,    85,    89,    90,    93,    94,    95,    98,    99,
     100,   103,   104,   107,   108,   111,   112,   115,   116,   120,
     121,   122,   123,   126,   127,   130,   131,   134,   135,   138,
     139,   142,   143,   146,   147,   150,   151,   152,   155,   156,
     157,   158,   159,   162,   163,   166,   167,   170,   171,   174,
     175,   178,   179,   180,   181,   182,   183,   187,   188,   192,
     196,   197,   201,   202,   203,   206,   207,   208,   211,   212,
     215,   216,   217,   218,   221,   222,   223,   224,   225,   226,
     229,   230,   231,   232,   233,   234,   235,   238,   239,   243,
     244,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   262,   263,   267,   271,   272,   273,   274,   278,
     279,   280,   283,   284,   285,   289,   290,   291,   292,   293,
     297,   298,   299,   303,   304,   308,   309,   313,   314,   318,
     319,   323,   324,   328,   329,   333,   334,   338,   342
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
  "function_definition", "declaration_list_opt", "declaration_list",
  "declaration", "declaration_specifiers", "storage_class_specifier",
  "type_qualifier_opt", "type_qualifier", "init_declarator_list_opt",
  "init_declarator_list", "init_declarator", "type_specifier",
  "struct_specifier", "struct_or_union", "struct_declaration_list",
  "struct_declaration", "struct_declarator_list", "struct_declarator",
  "enum_specifier", "enumerator_list", "enumerator", "declarator",
  "pointer", "direct_declarator", "constant_expression_opt",
  "parameter_type_list_opt", "parameter_type_list", "parameter_list",
  "parameter_declaration", "abstract_declarator_opt",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement_list_opt", "statement_list", "statement",
  "labeled_statement", "compound_statement", "expression_statement",
  "selection_statement", "iteration_statement", "expression_opt",
  "jump_statement", "primary_expression", "postfix_expression",
  "arg_expression_list_opt", "arg_expression_list", "unary_expression",
  "cast_expression", "type_name", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "AND_expression", "exclusive_OR_expression",
  "inclusive_OR_expression", "logical_AND_expression",
  "logical_OR_expression", "conditional_expression",
  "assignment_expression", "expression", "constant_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-205)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     367,  -205,     7,  -205,  -205,  -205,  -205,    76,   -42,  -205,
    -205,  -205,    34,   367,  -205,  -205,  -205,    76,   124,   124,
     124,  -205,    44,  -205,    27,    -1,   112,    15,    71,    48,
      58,  -205,  -205,  -205,    73,    89,  -205,   -23,  -205,  -205,
    -205,   125,    96,   124,  -205,   112,   124,   433,   127,    61,
    -205,    15,  -205,  -205,  -205,    76,   397,  -205,     0,    60,
    -205,   125,   246,   124,  -205,    76,    45,   140,  -205,   156,
    -205,   456,   492,   492,   299,   433,   433,   433,   433,   433,
    -205,  -205,  -205,  -205,   433,  -205,   165,  -205,   251,   170,
    -205,   160,    64,    74,    98,   153,   175,   166,   177,   206,
      16,  -205,  -205,  -205,  -205,   433,  -205,    15,    69,  -205,
     187,   397,  -205,  -205,   433,    59,  -205,   199,  -205,  -205,
     168,   195,   433,   196,   207,   246,   214,   215,   433,   222,
     223,  -205,   202,   226,   246,  -205,  -205,  -205,  -205,  -205,
    -205,  -205,   218,  -205,   346,   433,  -205,   -12,  -205,  -205,
     176,  -205,   377,   299,  -205,   433,  -205,  -205,    -5,   235,
     236,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,   211,   433,   433,   216,   433,   433,   433,   433,   433,
     433,   433,   433,   433,   433,   433,   433,   433,   433,   433,
     433,   433,   433,   433,   433,  -205,  -205,  -205,  -205,    90,
    -205,     0,  -205,   433,  -205,  -205,   238,  -205,   246,   255,
     433,   433,   231,  -205,   433,   433,   233,  -205,  -205,  -205,
     247,   248,   249,   176,   124,   433,  -205,  -205,   253,   180,
     179,  -205,   433,  -205,  -205,   256,   260,  -205,   267,  -205,
    -205,  -205,  -205,  -205,   160,   160,    64,    64,    74,    74,
      74,    74,    98,    98,   153,   175,   166,   177,   206,   257,
    -205,   397,  -205,  -205,   246,  -205,   271,   263,   273,  -205,
     277,   278,  -205,  -205,  -205,  -205,   282,   283,  -205,  -205,
    -205,   433,  -205,   433,  -205,  -205,   433,   433,   246,   246,
     246,  -205,  -205,  -205,  -205,   288,   276,   315,  -205,  -205,
     279,   433,   246,  -205,   291,  -205,   246,  -205
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,     0,    21,    38,    22,    39,     0,    23,    25,
      59,    34,     0,     2,     3,     5,     6,    26,    15,    16,
      14,    32,     0,    33,     0,     0,    56,     0,    50,     0,
      57,    24,     1,     4,     0,    27,    28,    30,    18,    19,
      17,     0,    37,     9,     8,    55,    65,    63,    53,     0,
      51,     0,    60,    58,    13,     0,     0,     7,     0,     0,
      40,     0,    87,    10,    11,    26,    73,     0,    66,    67,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   118,   117,     0,   114,     0,   120,   131,   142,
     145,   149,   152,   155,   160,   163,   165,   167,   169,   171,
     173,   175,   177,   178,    64,     0,    49,     0,     0,    29,
      30,     0,    31,    83,     0,     0,    43,    45,    36,    41,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,   100,     0,     0,    88,    89,    91,    92,    93,    94,
      95,    96,     0,    12,    65,    63,    71,    75,    72,    74,
      76,    62,     0,     0,   140,     0,   132,   133,    73,     0,
       0,   142,   136,   135,   134,   138,   137,   139,    61,   125,
     126,     0,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    52,    48,    85,     0,
      46,     0,    42,     0,    35,   112,     0,   111,     0,     0,
     108,     0,     0,   109,     0,     0,     0,    99,    90,   101,
       0,     0,     0,    77,    65,    63,    68,    70,     0,    65,
      75,   144,     0,   119,   124,     0,   128,   129,     0,   123,
     176,   146,   147,   148,   150,   151,   153,   154,   156,   157,
     158,   159,   161,   162,   164,   166,   168,   170,   172,     0,
      84,     0,    44,    47,     0,    98,     0,     0,     0,   110,
       0,     0,   113,    80,    78,    79,     0,     0,   141,   143,
     122,     0,   121,     0,    86,    97,     0,   108,     0,     0,
       0,    82,    81,   130,   174,     0,     0,   102,   104,   105,
       0,   108,     0,   106,     0,   103,     0,   107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -205,  -205,  -205,   314,  -205,  -205,  -205,   -18,    22,  -205,
    -205,   320,  -205,  -205,   274,   -30,  -205,  -205,   269,   -49,
    -205,   130,  -205,   284,   227,    29,   -29,   -21,  -136,   -44,
    -205,  -205,   181,   178,  -137,  -127,   -85,  -205,  -205,  -205,
     -57,  -205,    49,  -205,  -205,  -205,  -204,  -205,  -205,  -205,
    -205,  -205,   -22,   -60,   184,     9,    35,     8,    31,   149,
     150,   148,   151,   162,  -205,    63,  -167,   -62,   -53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    12,    13,    14,    15,    62,    63,    16,    66,    18,
      30,    19,    34,    35,    36,    20,    21,    22,    59,    60,
     115,   116,    23,    49,    50,    24,    25,    26,    86,   220,
      68,    69,    70,   148,   149,   150,   112,   199,   133,   134,
     135,   136,   137,   138,   139,   140,   212,   141,    87,    88,
     235,   236,    89,    90,   159,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     142,    53,    67,   113,    45,   237,   267,   221,   240,   222,
     119,    58,   160,     9,    43,   162,   163,   164,   165,   166,
     223,   144,    17,   145,   167,    64,   198,    56,   229,    58,
     145,    58,     7,     7,    32,    17,    29,   147,     8,   114,
      38,    39,    40,     8,    27,   143,    37,   193,    10,   154,
     156,   157,   195,   161,   161,   161,   161,   161,   113,    10,
      10,   200,   161,   142,    43,    65,   213,    28,   209,   206,
       2,   119,   142,    44,   194,    48,     4,   218,   144,     6,
     145,    41,    52,   296,   110,    65,    57,   117,     8,   277,
      58,   160,   221,   160,   110,   146,   158,   304,   118,   106,
     201,     8,   107,   223,    42,    10,   202,   197,    51,     7,
     107,   238,   179,   180,   293,   147,   241,   242,   243,     8,
      54,    11,   183,   184,   185,   186,    45,     1,   260,   230,
      55,   261,   259,    61,     2,     2,    10,   181,   182,     3,
       4,     4,     5,     6,     6,    46,   142,    47,   213,   268,
     263,   265,   270,   271,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   279,    29,   151,   158,   284,   105,     2,     9,
     276,   187,   188,     1,     4,    11,    11,     6,   244,   245,
       2,   248,   249,   250,   251,     3,     4,   152,     5,     6,
     230,   168,   142,   176,   177,   178,   204,   285,   113,   224,
     161,   225,   229,   229,   145,   145,   246,   247,   252,   253,
     175,   189,   190,     8,   295,   213,   142,   142,   142,    11,
     117,   297,   298,   299,   191,     9,   192,    56,   203,   213,
     142,    11,   205,   207,   142,   305,   208,   210,   211,   307,
     121,   122,   123,   124,   125,   214,   215,   126,   127,   128,
      71,   161,   216,   129,   217,   219,   130,    72,    73,   232,
     233,   234,   169,   170,   171,   266,   239,   264,   269,    74,
     272,   273,   274,    43,   172,   275,   173,   278,    75,    76,
     280,   174,    77,   131,    78,    79,   283,    80,    81,    82,
      83,   281,     1,   282,   286,    84,    85,   288,   132,     2,
     287,   289,   290,    71,     3,     4,   291,     5,     6,   292,
      72,    73,   300,   301,   302,   306,   303,    33,    31,   109,
     120,   262,    74,   227,   196,   108,   231,   228,   254,   256,
     255,    75,    76,   257,     0,    77,   294,    78,    79,     1,
      80,    81,    82,    83,     9,   258,     2,     0,    84,    85,
      11,     3,     4,     0,     5,     6,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     2,     0,   144,
       1,   145,     3,     4,     0,     5,     6,     2,     0,     8,
       0,     0,     3,     4,     0,     5,     6,     0,     0,     0,
       7,     9,     0,     0,     0,     0,    10,    11,     0,   226,
       8,    71,     0,     0,     0,     0,     0,     0,    72,    73,
       0,     0,     9,     0,     0,     0,     0,    10,    11,     0,
      74,     0,     9,     0,   111,     0,     0,     0,    11,    75,
      76,     0,     0,    77,     0,    78,    79,    71,    80,    81,
      82,    83,     0,     0,    72,    73,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
      71,     0,     0,     0,     0,    75,    76,    72,    73,    77,
       0,    78,    79,     0,    80,    81,    82,    83,     0,   153,
       0,     0,    84,    85,     0,     0,     0,     0,    75,    76,
       0,     0,    77,     0,    78,    79,    71,    80,    81,    82,
      83,     0,     0,    72,    73,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,   155,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     0,     0,    77,     0,
      78,    79,     0,    80,    81,    82,    83,     0,     0,     0,
       0,    84,    85
};

static const yytype_int16 yycheck[] =
{
      62,    30,    46,    56,    25,   172,   210,   144,   175,   145,
      59,    41,    74,    55,    37,    75,    76,    77,    78,    79,
     147,    33,     0,    35,    84,    43,   111,    50,    33,    59,
      35,    61,    33,    33,     0,    13,     7,    66,    43,    39,
      18,    19,    20,    43,    37,    63,    17,    31,    60,    71,
      72,    73,   105,    75,    76,    77,    78,    79,   111,    60,
      60,   114,    84,   125,    37,    43,   128,    60,   125,   122,
      10,   120,   134,    24,    58,    60,    16,   134,    33,    19,
      35,    37,    34,   287,    55,    63,    37,    58,    43,   225,
     120,   153,   229,   155,    65,    66,    74,   301,    38,    38,
      41,    43,    41,   230,    60,    60,    47,    38,    37,    33,
      41,   173,    48,    49,   281,   144,   176,   177,   178,    43,
      47,    61,    24,    25,    26,    27,   147,     3,    38,   158,
      41,    41,   194,    37,    10,    10,    60,    63,    64,    15,
      16,    16,    18,    19,    19,    33,   208,    35,   210,   211,
     203,   208,   214,   215,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   232,   144,    34,   153,   261,    50,    10,    55,
     224,    28,    29,     3,    16,    61,    61,    19,   179,   180,
      10,   183,   184,   185,   186,    15,    16,    41,    18,    19,
     229,    36,   264,    43,    44,    45,    38,   264,   261,    33,
     232,    35,    33,    33,    35,    35,   181,   182,   187,   188,
      50,    46,    56,    43,   286,   287,   288,   289,   290,    61,
     201,   288,   289,   290,    57,    55,    30,    50,    39,   301,
     302,    61,    47,    47,   306,   302,    39,    33,    33,   306,
       4,     5,     6,     7,     8,    33,    33,    11,    12,    13,
      14,   283,    60,    17,    38,    47,    20,    21,    22,    34,
      34,    60,    21,    22,    23,    20,    60,    39,    47,    33,
      47,    34,    34,    37,    33,    36,    35,    34,    42,    43,
      34,    40,    46,    47,    48,    49,    39,    51,    52,    53,
      54,    41,     3,    36,    33,    59,    60,    34,    62,    10,
      47,    34,    34,    14,    15,    16,    34,    18,    19,    36,
      21,    22,    34,    47,     9,    34,    47,    13,     8,    55,
      61,   201,    33,   152,   107,    51,   158,   153,   189,   191,
     190,    42,    43,   192,    -1,    46,   283,    48,    49,     3,
      51,    52,    53,    54,    55,   193,    10,    -1,    59,    60,
      61,    15,    16,    -1,    18,    19,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    33,
       3,    35,    15,    16,    -1,    18,    19,    10,    -1,    43,
      -1,    -1,    15,    16,    -1,    18,    19,    -1,    -1,    -1,
      33,    55,    -1,    -1,    -1,    -1,    60,    61,    -1,    32,
      43,    14,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    61,    -1,
      33,    -1,    55,    -1,    37,    -1,    -1,    -1,    61,    42,
      43,    -1,    -1,    46,    -1,    48,    49,    14,    51,    52,
      53,    54,    -1,    -1,    21,    22,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    42,    43,    21,    22,    46,
      -1,    48,    49,    -1,    51,    52,    53,    54,    -1,    33,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    46,    -1,    48,    49,    14,    51,    52,    53,
      54,    -1,    -1,    21,    22,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    46,    -1,
      48,    49,    -1,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    10,    15,    16,    18,    19,    33,    43,    55,
      60,    61,    66,    67,    68,    69,    72,    73,    74,    76,
      80,    81,    82,    87,    90,    91,    92,    37,    60,    90,
      75,    76,     0,    68,    77,    78,    79,    90,    73,    73,
      73,    37,    60,    37,   107,    92,    33,    35,    60,    88,
      89,    37,    34,    91,    47,    41,    50,   107,    80,    83,
      84,    37,    70,    71,    72,    73,    73,    94,    95,    96,
      97,    14,    21,    22,    33,    42,    43,    46,    48,    49,
      51,    52,    53,    54,    59,    60,    93,   113,   114,   117,
     118,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,    50,    38,    41,    88,    79,
      90,    37,   101,   133,    39,    85,    86,    90,    38,    84,
      83,     4,     5,     6,     7,     8,    11,    12,    13,    17,
      20,    47,    62,   103,   104,   105,   106,   107,   108,   109,
     110,   112,   132,    72,    33,    35,    90,    91,    98,    99,
     100,    34,    41,    33,   117,    33,   117,   117,    73,   119,
     132,   117,   118,   118,   118,   118,   118,   118,    36,    21,
      22,    23,    33,    35,    40,    50,    43,    44,    45,    48,
      49,    63,    64,    24,    25,    26,    27,    28,    29,    46,
      56,    57,    30,    31,    58,   133,    89,    38,   101,   102,
     133,    41,    47,    39,    38,    47,   133,    47,    39,   105,
      33,    33,   111,   132,    33,    33,    60,    38,   105,    47,
      94,    99,    93,   100,    33,    35,    32,    97,   119,    33,
      91,    98,    34,    34,    60,   115,   116,   131,   132,    60,
     131,   118,   118,   118,   120,   120,   121,   121,   122,   122,
     122,   122,   123,   123,   124,   125,   126,   127,   128,   132,
      38,    41,    86,   133,    39,   105,    20,   111,   132,    47,
     132,   132,    47,    34,    34,    36,    94,    93,    34,   118,
      34,    41,    36,    39,   101,   105,    33,    47,    34,    34,
      34,    34,    36,   131,   130,   132,   111,   105,   105,   105,
      34,    47,     9,    47,   111,   105,    34,   105
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    72,    73,    73,    73,    73,    73,    73,
      74,    74,    74,    75,    75,    76,    77,    77,    78,    78,
      79,    79,    80,    80,    80,    81,    81,    81,    82,    82,
      83,    83,    84,    85,    85,    86,    86,    86,    87,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,    99,   100,   100,
     100,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   105,   105,   105,   105,   106,   106,   107,
     108,   108,   109,   109,   109,   110,   110,   110,   111,   111,
     112,   112,   112,   112,   113,   113,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   115,   115,   116,
     116,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   118,   119,   120,   120,   120,   120,   121,
     121,   121,   122,   122,   122,   123,   123,   123,   123,   123,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   132,   133
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     2,     0,
       1,     1,     2,     3,     1,     1,     1,     2,     2,     2,
       1,     1,     1,     0,     1,     1,     0,     1,     1,     3,
       1,     3,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     1,     3,     1,     2,     3,     5,     4,
       2,     1,     3,     1,     3,     2,     1,     2,     3,     1,
       3,     4,     4,     0,     1,     0,     1,     1,     3,     1,
       3,     2,     2,     0,     1,     1,     1,     2,     3,     3,
       3,     4,     4,     1,     3,     1,     3,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     4,     3,     4,
       1,     2,     5,     7,     5,     5,     7,     9,     0,     1,
       3,     2,     2,     3,     1,     1,     1,     1,     1,     3,
       1,     4,     4,     3,     3,     2,     2,     0,     1,     1,
       3,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     1,     4,     2,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1
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

#line 1642 "y.tab.c"

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

