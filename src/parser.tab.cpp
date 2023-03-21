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

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CONSTANT = 4,                   /* CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_SIZEOF = 6,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 7,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 8,                     /* INC_OP  */
  YYSYMBOL_DEC_OP = 9,                     /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 10,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 11,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 12,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 13,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 14,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 15,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 16,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 17,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 18,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 19,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 20,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 21,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 22,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 23,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 24,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 25,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 26,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 27,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPE_NAME = 28,                 /* TYPE_NAME  */
  YYSYMBOL_TYPEDEF = 29,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 30,                    /* EXTERN  */
  YYSYMBOL_STATIC = 31,                    /* STATIC  */
  YYSYMBOL_AUTO = 32,                      /* AUTO  */
  YYSYMBOL_REGISTER = 33,                  /* REGISTER  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_SHORT = 35,                     /* SHORT  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_LONG = 37,                      /* LONG  */
  YYSYMBOL_SIGNED = 38,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 39,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 40,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 41,                    /* DOUBLE  */
  YYSYMBOL_CONST = 42,                     /* CONST  */
  YYSYMBOL_VOLATILE = 43,                  /* VOLATILE  */
  YYSYMBOL_VOID = 44,                      /* VOID  */
  YYSYMBOL_STRUCT = 45,                    /* STRUCT  */
  YYSYMBOL_UNION = 46,                     /* UNION  */
  YYSYMBOL_ENUM = 47,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 48,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 49,                      /* CASE  */
  YYSYMBOL_DEFAULT = 50,                   /* DEFAULT  */
  YYSYMBOL_IF = 51,                        /* IF  */
  YYSYMBOL_ELSE = 52,                      /* ELSE  */
  YYSYMBOL_SWITCH = 53,                    /* SWITCH  */
  YYSYMBOL_WHILE = 54,                     /* WHILE  */
  YYSYMBOL_DO = 55,                        /* DO  */
  YYSYMBOL_FOR = 56,                       /* FOR  */
  YYSYMBOL_GOTO = 57,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 58,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 59,                     /* BREAK  */
  YYSYMBOL_RETURN = 60,                    /* RETURN  */
  YYSYMBOL_61_ = 61,                       /* '('  */
  YYSYMBOL_62_ = 62,                       /* ')'  */
  YYSYMBOL_63_ = 63,                       /* '['  */
  YYSYMBOL_64_ = 64,                       /* ']'  */
  YYSYMBOL_65_ = 65,                       /* '.'  */
  YYSYMBOL_66_ = 66,                       /* ','  */
  YYSYMBOL_67_ = 67,                       /* '&'  */
  YYSYMBOL_68_ = 68,                       /* '*'  */
  YYSYMBOL_69_ = 69,                       /* '+'  */
  YYSYMBOL_70_ = 70,                       /* '-'  */
  YYSYMBOL_71_ = 71,                       /* '~'  */
  YYSYMBOL_72_ = 72,                       /* '!'  */
  YYSYMBOL_73_ = 73,                       /* '/'  */
  YYSYMBOL_74_ = 74,                       /* '%'  */
  YYSYMBOL_75_ = 75,                       /* '<'  */
  YYSYMBOL_76_ = 76,                       /* '>'  */
  YYSYMBOL_77_ = 77,                       /* '^'  */
  YYSYMBOL_78_ = 78,                       /* '|'  */
  YYSYMBOL_79_ = 79,                       /* '?'  */
  YYSYMBOL_80_ = 80,                       /* ':'  */
  YYSYMBOL_81_ = 81,                       /* '='  */
  YYSYMBOL_82_ = 82,                       /* ';'  */
  YYSYMBOL_83_ = 83,                       /* '{'  */
  YYSYMBOL_84_ = 84,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 85,                  /* $accept  */
  YYSYMBOL_root = 86,                      /* root  */
  YYSYMBOL_primary_expression = 87,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 88,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 89,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 90,          /* unary_expression  */
  YYSYMBOL_unary_operator = 91,            /* unary_operator  */
  YYSYMBOL_cast_expression = 92,           /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 93, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 94,       /* additive_expression  */
  YYSYMBOL_shift_expression = 95,          /* shift_expression  */
  YYSYMBOL_relational_expression = 96,     /* relational_expression  */
  YYSYMBOL_equality_expression = 97,       /* equality_expression  */
  YYSYMBOL_and_expression = 98,            /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 99,   /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 100,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 101,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 102,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 103,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 104,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 105,      /* assignment_operator  */
  YYSYMBOL_expression = 106,               /* expression  */
  YYSYMBOL_constant_expression = 107,      /* constant_expression  */
  YYSYMBOL_declaration = 108,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 109,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 110,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 111,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 112,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 113,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 114, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 115,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 116,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 117,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 118, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 119,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 120,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 121,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 122,          /* enumerator_list  */
  YYSYMBOL_enumerator = 123,               /* enumerator  */
  YYSYMBOL_type_qualifier = 124,           /* type_qualifier  */
  YYSYMBOL_declarator = 125,               /* declarator  */
  YYSYMBOL_direct_declarator = 126,        /* direct_declarator  */
  YYSYMBOL_pointer = 127,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 128,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 129,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 130,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 131,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 132,          /* identifier_list  */
  YYSYMBOL_type_name = 133,                /* type_name  */
  YYSYMBOL_abstract_declarator = 134,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 135, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 136,              /* initializer  */
  YYSYMBOL_initializer_list = 137,         /* initializer_list  */
  YYSYMBOL_statement = 138,                /* statement  */
  YYSYMBOL_labeled_statement = 139,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 140,       /* compound_statement  */
  YYSYMBOL_declaration_list = 141,         /* declaration_list  */
  YYSYMBOL_statement_list = 142,           /* statement_list  */
  YYSYMBOL_expression_statement = 143,     /* expression_statement  */
  YYSYMBOL_selection_statement = 144,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 145,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 146,           /* jump_statement  */
  YYSYMBOL_translation_unit = 147,         /* translation_unit  */
  YYSYMBOL_external_declaration = 148,     /* external_declaration  */
  YYSYMBOL_function_definition = 149       /* function_definition  */
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
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
       2,     2,     2,    72,     2,     2,     2,    74,    67,     2,
      61,    62,    68,    69,    66,    70,    65,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    82,
      75,    81,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    78,    84,    71,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    84,    85,    86,    87,    91,    92,    93,
      94,    95,    96,    97,    98,   102,   103,   107,   108,   109,
     110,   128,   129,   133,   134,   135,   136,   137,   138,   143,
     144,   148,   149,   150,   151,   155,   156,   157,   161,   162,
     163,   167,   168,   169,   170,   171,   175,   176,   177,   181,
     182,   186,   187,   191,   192,   196,   197,   201,   202,   206,
     207,   211,   212,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   258,   259,   263,   269,   270,   276,
     277,   278,   279,   280,   281,   285,   289,   296,   297,   302,
     303,   304,   305,   306,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   327,   328,   329,   333,
     334,   338,   339,   343,   347,   348,   349,   350,   354,   355,
     359,   360,   361,   365,   366,   367,   371,   372,   376,   377,
     382,   383,   387,   388,   392,   393,   394,   395,   396,   397,
     398,   402,   403,   404,   405,   409,   410,   415,   416,   420,
     421,   425,   426,   427,   432,   433,   437,   438,   442,   443,
     444,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     460,   461,   462,   466,   467,   471,   472,   473,   474,   475,
     476,   480,   481,   482,   486,   487,   488,   489,   497,   498,
     502,   503,   507,   508,   512,   513,   514,   518,   519,   520,
     521,   525,   526,   527,   528,   529,   533,   534,   538,   539,
     543,   544,   545,   546
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CONSTANT", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['",
  "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'",
  "'}'", "$accept", "root", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-223)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     878,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,    12,    19,    76,    46,  -223,    32,  1163,  1163,  -223,
      15,  -223,  1163,  1010,   -32,    56,   878,  -223,  -223,   -31,
      75,    71,  -223,  -223,    76,  -223,  -223,   -40,  -223,   990,
    -223,  -223,    52,   964,  -223,   277,  -223,    32,  -223,  1010,
     407,   593,   -32,  -223,    75,    65,    26,  -223,  -223,  -223,
    -223,    19,  -223,   523,  -223,  1010,   964,   964,   913,  -223,
      62,   964,    78,  -223,  -223,   762,   774,   774,   787,   107,
     147,   159,   166,   489,   186,   259,   195,   197,   559,   647,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,   183,
     273,   787,  -223,   158,    36,   185,    49,   196,   207,   198,
     200,   268,    -7,  -223,  -223,    25,  -223,  -223,  -223,   347,
     417,  -223,  -223,  -223,  -223,   220,  -223,  -223,  -223,  -223,
      13,   240,   237,  -223,    93,  -223,  -223,  -223,  -223,   261,
      54,   787,    75,  -223,  -223,   523,  -223,  -223,  -223,   933,
    -223,  -223,  -223,   787,   119,  -223,   249,  -223,   489,   647,
    -223,   787,  -223,  -223,   260,   489,   787,   787,   787,   285,
     577,   275,  -223,  -223,  -223,   127,   156,    84,   279,   339,
    -223,  -223,   663,   787,   340,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,   787,  -223,   787,   787,
     787,   787,   787,   787,   787,   787,   787,   787,   787,   787,
     787,   787,   787,   787,   787,   787,   787,   787,  -223,  -223,
     453,  -223,  -223,   833,   692,  -223,    41,  -223,     6,  -223,
    1142,  -223,   355,  -223,  -223,  -223,  -223,  -223,    55,  -223,
    -223,    62,  -223,   787,  -223,   300,   489,  -223,   172,   187,
     192,   302,   577,  -223,  -223,  -223,  1066,   139,  -223,   787,
    -223,  -223,   193,  -223,   -43,  -223,  -223,  -223,  -223,  -223,
     158,   158,    36,    36,   185,   185,   185,   185,    49,    49,
     196,   207,   198,   200,   268,   -12,  -223,  -223,  -223,   303,
     304,  -223,   305,     6,  1107,   733,  -223,  -223,  -223,   145,
    -223,  -223,  -223,  -223,  -223,   489,   489,   489,   787,   746,
    -223,  -223,   787,  -223,   787,  -223,  -223,  -223,  -223,   306,
    -223,   307,  -223,  -223,   312,  -223,  -223,   194,   489,   199,
    -223,  -223,  -223,  -223,   489,   288,  -223,   489,  -223,  -223,
    -223
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   134,   105,    89,    90,    91,    92,    93,    95,    96,
      97,    98,   101,   102,    99,   100,   130,   131,    94,   109,
     110,     0,     0,   141,     0,   209,     0,    79,    81,   103,
       0,   104,    83,     0,   133,     0,     2,   206,   208,   125,
       0,     0,   145,   143,   142,     1,    77,     0,    85,    87,
      80,    82,   108,     0,    84,     0,   188,     0,   213,     0,
       0,     0,   132,   207,     0,   128,     0,   126,   135,   146,
     144,     0,    78,     0,   211,     0,     0,   115,     0,   111,
       0,   117,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,    27,    28,   192,   184,     7,    17,
      29,     0,    31,    35,    38,    41,    46,    49,    51,    53,
      55,    57,    59,    61,    74,     0,   190,   175,   176,     0,
       0,   177,   178,   179,   180,    87,   189,   212,   154,   140,
     153,     0,   147,   149,     0,     3,   137,    29,    76,     0,
       0,     0,     0,   123,    86,     0,   170,    88,   210,     0,
     114,   107,   112,     0,     0,   118,   120,   116,     0,     0,
      21,     0,    18,    19,     0,     0,     0,     0,     0,     0,
       0,     0,   202,   203,   204,     0,     0,   156,     0,     0,
      13,    14,     0,     0,     0,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    63,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,   186,
       0,   185,   191,     0,     0,   151,   158,   152,   159,   138,
       0,   139,     0,   136,   124,   129,   127,   173,     0,   106,
     121,     0,   113,     0,   181,     0,     0,   183,     0,     0,
       0,     0,     0,   201,   205,     6,     0,   158,   157,     0,
      12,     9,     0,    15,     0,    11,    62,    32,    33,    34,
      36,    37,    39,    40,    44,    45,    42,    43,    47,    48,
      50,    52,    54,    56,    58,     0,    75,   187,   166,     0,
       0,   162,     0,   160,     0,     0,   148,   150,   155,     0,
     171,   119,   122,    22,   182,     0,     0,     0,     0,     0,
      30,    10,     0,     8,     0,   167,   161,   163,   168,     0,
     164,     0,   172,   174,   194,   196,   197,     0,     0,     0,
      16,    60,   169,   165,     0,     0,   199,     0,   195,   198,
     200
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -223,  -223,  -223,  -223,  -223,   -48,  -223,   -81,    24,    58,
      72,    48,   146,   150,   151,   149,   170,  -223,   -55,   -70,
    -223,   -94,   -54,    11,     0,  -223,   328,  -223,   -28,  -223,
    -223,   333,   -69,   -26,  -223,   160,  -223,   348,   272,    35,
     -14,   -33,    -3,  -223,   -59,  -223,   173,  -223,   258,  -123,
    -222,  -131,  -223,   -74,  -223,   148,   134,   299,  -173,  -223,
    -223,  -223,  -223,   396,  -223
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    24,   108,   109,   272,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     206,   125,   149,    56,    57,    47,    48,    27,    28,    29,
      30,    78,    79,    80,   164,   165,    31,    66,    67,    32,
      33,    34,    35,    44,   299,   142,   143,   144,   188,   300,
     238,   157,   248,   126,   127,   128,    59,   130,   131,   132,
     133,   134,    36,    37,    38
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,   141,    62,   156,   185,   186,   148,   262,    41,   162,
     225,    25,    49,   147,   303,    39,     1,   237,    52,   179,
      43,   323,     1,   227,   247,    77,    71,    50,    51,    60,
     207,    61,    54,   148,   174,     1,    26,   170,   172,   173,
     147,    70,    72,   135,     1,   303,    45,    25,    77,    77,
      77,   160,    64,    77,   227,   167,   232,   135,    42,     1,
     140,   215,   216,   147,   268,     1,   166,   304,   324,   305,
     136,    77,   226,   187,   233,   186,   234,   186,    65,    69,
      22,    23,   258,   259,   260,   156,   136,    23,    81,   319,
     162,   227,   152,    22,   254,    40,   148,   245,    53,   274,
      23,   257,   233,   147,   234,   211,   212,   228,   148,   250,
     153,    81,    81,    81,    46,   147,    81,    22,    16,    17,
     152,   309,   273,    22,   217,   218,   235,   277,   278,   279,
      23,    77,   295,    68,    81,    76,   276,   236,   244,   310,
     136,    77,   163,   187,    23,   266,   151,   234,   145,    83,
      84,    85,    23,    86,    87,   241,   232,   296,   168,   242,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   333,   148,
     302,    58,   314,    75,   267,   251,   147,   175,   320,   129,
     189,   190,   191,   227,    81,   213,   214,    74,   148,   312,
     266,   252,   234,    62,    81,   147,    99,   137,   176,   264,
     219,   220,   100,   101,   102,   103,   104,   105,   265,    41,
     177,   147,   227,   158,   337,   339,   208,   178,   155,   332,
     236,   209,   210,   140,   315,   280,   281,   166,   227,   156,
     140,   334,   335,   336,   192,   329,   193,   180,   194,   316,
     148,   331,   340,   227,   317,   321,   345,   147,   227,   322,
     227,   347,   181,   267,   346,   227,   140,   288,   289,   341,
     348,   282,   283,   350,   221,   222,   147,   182,   223,   183,
      82,    83,    84,    85,   224,    86,    87,   284,   285,   286,
     287,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,    73,   239,   240,   140,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   243,    88,    89,    90,   253,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   261,
     256,   269,   270,   275,   100,   101,   102,   103,   104,   105,
      82,    83,    84,    85,   205,    86,    87,   263,   308,   106,
      55,   107,   313,   318,   344,   325,   326,   290,   342,   327,
     349,   343,   291,   293,   292,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   294,    88,    89,    90,   154,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   159,
     138,   311,   150,   307,   100,   101,   102,   103,   104,   105,
      82,    83,    84,    85,   246,    86,    87,   255,   230,   106,
      55,   229,    63,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,    82,    83,    84,    85,
       0,    86,    87,     0,     0,     0,    88,    89,    90,   139,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
       0,     0,    82,    83,    84,    85,     0,    86,    87,   106,
      55,   231,    88,    89,    90,     0,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   145,    83,    84,    85,
       0,    86,    87,     0,     0,   106,    55,   297,    88,    89,
      90,     0,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   145,    83,    84,    85,     0,    86,    87,     0,
       0,   106,    55,     0,     0,     0,     0,     0,     0,     0,
     145,    83,    84,    85,    99,    86,    87,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   145,    83,    84,    85,
       0,    86,    87,     0,     0,     0,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,    99,     0,
       0,   184,     0,     0,   100,   101,   102,   103,   104,   105,
     145,    83,    84,    85,    99,    86,    87,   146,     0,   106,
     100,   101,   102,   103,   104,   105,   145,    83,    84,    85,
       0,    86,    87,     0,     0,     2,     0,     0,     0,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   145,    83,    84,    85,     0,
      86,    87,     0,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,    99,   271,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   145,    83,    84,    85,
       0,    86,    87,     0,     0,     0,     0,     0,     0,   145,
      83,    84,    85,    99,    86,    87,   301,     0,     0,   100,
     101,   102,   103,   104,   105,   145,    83,    84,    85,     0,
      86,    87,     0,     0,     0,     0,     0,   145,    83,    84,
      85,     0,    86,    87,     0,     0,     0,     0,     0,     0,
     145,    83,    84,    85,    99,    86,    87,   330,     0,     0,
     100,   101,   102,   103,   104,   105,     0,    99,   338,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,   169,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   171,     1,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,     0,    99,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,   298,   234,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     2,     0,     0,     0,     0,    23,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     2,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,   161,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,   249,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,   298,   234,
       0,     0,     0,     0,    23,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   328,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     306,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21
};

static const yytype_int16 yycheck[] =
{
       0,    60,    35,    73,    98,    99,    61,   180,    22,    78,
      17,     0,    26,    61,   236,     3,     3,   140,     3,    93,
      23,    64,     3,    66,   155,    53,    66,    27,    28,    61,
     111,    63,    32,    88,    88,     3,    36,    85,    86,    87,
      88,    44,    82,    57,     3,   267,     0,    36,    76,    77,
      78,    77,    83,    81,    66,    81,   130,    71,    23,     3,
      60,    12,    13,   111,   187,     3,    80,    61,    80,    63,
      59,    99,    79,    99,    61,   169,    63,   171,     3,    44,
      61,    68,   176,   177,   178,   155,    75,    68,    53,   262,
     159,    66,    66,    61,   168,    83,   151,   151,    83,   193,
      68,   175,    61,   151,    63,    69,    70,    82,   163,   163,
      84,    76,    77,    78,    82,   163,    81,    61,    42,    43,
      66,    66,   192,    61,    75,    76,   140,   208,   209,   210,
      68,   159,   226,    62,    99,    83,   206,   140,    84,    84,
     129,   169,    80,   169,    68,    61,    81,    63,     3,     4,
       5,     6,    68,     8,     9,    62,   230,   227,    80,    66,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   309,   234,
     234,    33,   256,    49,   187,    66,   234,    80,   269,    55,
       7,     8,     9,    66,   159,    10,    11,    49,   253,   253,
      61,    82,    63,   236,   169,   253,    61,    59,    61,    82,
      14,    15,    67,    68,    69,    70,    71,    72,    62,   233,
      61,   269,    66,    75,   318,   319,    68,    61,    83,    84,
     233,    73,    74,   233,    62,   211,   212,   251,    66,   309,
     240,   315,   316,   317,    61,   304,    63,    61,    65,    62,
     305,   305,   322,    66,    62,    62,    62,   305,    66,    66,
      66,    62,     3,   266,   338,    66,   266,   219,   220,   324,
     344,   213,   214,   347,    67,    77,   324,    82,    78,    82,
       3,     4,     5,     6,    16,     8,     9,   215,   216,   217,
     218,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    81,    62,    66,   304,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    64,    49,    50,    51,    80,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    54,
      80,    62,     3,     3,    67,    68,    69,    70,    71,    72,
       3,     4,     5,     6,    81,     8,     9,    82,     3,    82,
      83,    84,    62,    61,    52,    62,    62,   221,    62,    64,
      82,    64,   222,   224,   223,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,   225,    49,    50,    51,    71,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    76,
       3,   251,    64,   240,    67,    68,    69,    70,    71,    72,
       3,     4,     5,     6,   152,     8,     9,   169,   129,    82,
      83,    84,    36,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    49,    50,    51,    62,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    82,
      83,    84,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    82,    83,    84,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    61,     8,     9,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    82,    -1,    -1,    67,    68,    69,    70,    71,    72,
       3,     4,     5,     6,    61,     8,     9,    64,    -1,    82,
      67,    68,    69,    70,    71,    72,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    61,     8,     9,    64,    -1,    -1,    67,
      68,    69,    70,    71,    72,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    61,     8,     9,    64,    -1,    -1,
      67,    68,    69,    70,    71,    72,    -1,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    61,     3,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    28,    -1,    -1,    -1,    -1,    68,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    84,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    84,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      -1,    -1,    -1,    -1,    68,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    61,    68,    86,   108,   109,   112,   113,   114,
     115,   121,   124,   125,   126,   127,   147,   148,   149,     3,
      83,   125,   124,   127,   128,     0,    82,   110,   111,   125,
     109,   109,     3,    83,   109,    83,   108,   109,   140,   141,
      61,    63,   126,   148,    83,     3,   122,   123,    62,   124,
     127,    66,    82,    81,   140,   141,    83,   113,   116,   117,
     118,   124,     3,     4,     5,     6,     8,     9,    49,    50,
      51,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      67,    68,    69,    70,    71,    72,    82,    84,    87,    88,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   106,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   125,   108,   140,     3,    62,
     109,   129,   130,   131,   132,     3,    64,    90,   103,   107,
     122,    81,    66,    84,   111,    83,   104,   136,   140,   116,
     118,    84,   117,    80,   119,   120,   125,   118,    80,    61,
      90,    61,    90,    90,   107,    80,    61,    61,    61,   138,
      61,     3,    82,    82,    82,   106,   106,   118,   133,     7,
       8,     9,    61,    63,    65,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    81,   105,    92,    68,    73,
      74,    69,    70,    10,    11,    12,    13,    75,    76,    14,
      15,    67,    77,    78,    16,    17,    79,    66,    82,    84,
     142,    84,   138,    61,    63,   125,   127,   134,   135,    62,
      66,    62,    66,    64,    84,   107,   123,   136,   137,    84,
     107,    66,    82,    80,   138,   133,    80,   138,   106,   106,
     106,    54,   143,    82,    82,    62,    61,   127,   134,    62,
       3,    62,    89,   104,   106,     3,   104,    92,    92,    92,
      93,    93,    94,    94,    95,    95,    95,    95,    96,    96,
      97,    98,    99,   100,   101,   106,   104,    84,    62,   129,
     134,    64,   107,   135,    61,    63,    48,   131,     3,    66,
      84,   120,   107,    62,   138,    62,    62,    62,    61,   143,
      92,    62,    66,    64,    80,    62,    62,    64,    62,   129,
      64,   107,    84,   136,   138,   138,   138,   106,    62,   106,
     104,   103,    62,    64,    52,    62,   138,    62,   138,    82,
     138
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    91,    91,    91,    92,
      92,    93,    93,    93,    93,    94,    94,    94,    95,    95,
      95,    96,    96,    96,    96,    96,    97,    97,    97,    98,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   106,   106,   107,   108,   108,   109,
     109,   109,   109,   109,   109,   110,   110,   111,   111,   112,
     112,   112,   112,   112,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   114,   114,   114,   115,
     115,   116,   116,   117,   118,   118,   118,   118,   119,   119,
     120,   120,   120,   121,   121,   121,   122,   122,   123,   123,
     124,   124,   125,   125,   126,   126,   126,   126,   126,   126,
     126,   127,   127,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   131,   132,   132,   133,   133,   134,   134,
     134,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     136,   136,   136,   137,   137,   138,   138,   138,   138,   138,
     138,   139,   139,   139,   140,   140,   140,   140,   141,   141,
     142,   142,   143,   143,   144,   144,   144,   145,   145,   145,
     145,   146,   146,   146,   146,   146,   147,   147,   148,   148,
     149,   149,   149,   149
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     2,     1,     2,     1,     1,     3,
       1,     2,     3,     4,     5,     2,     1,     3,     1,     3,
       1,     1,     2,     1,     1,     3,     4,     3,     4,     4,
       3,     1,     2,     2,     3,     1,     2,     1,     3,     1,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     2,     5,     7,     5,     5,     7,     6,
       7,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       4,     3,     3,     2
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
  case 2: /* root: translation_unit  */
#line 81 "src/parser.y"
                        { g_root = (yyvsp[0].node_list); }
#line 1651 "src/parser.tab.cpp"
    break;

  case 3: /* primary_expression: IDENTIFIER  */
#line 84 "src/parser.y"
               { (yyval.node) = new Identifier(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1657 "src/parser.tab.cpp"
    break;

  case 4: /* primary_expression: CONSTANT  */
#line 85 "src/parser.y"
             { (yyval.node) = new Constant((yyvsp[0].number)); }
#line 1663 "src/parser.tab.cpp"
    break;

  case 6: /* primary_expression: '(' expression ')'  */
#line 87 "src/parser.y"
                       { (yyval.node) = (yyvsp[-1].node); }
#line 1669 "src/parser.tab.cpp"
    break;

  case 7: /* postfix_expression: primary_expression  */
#line 91 "src/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1675 "src/parser.tab.cpp"
    break;

  case 8: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 92 "src/parser.y"
                                          { (yyval.node) = new ArrayIndex((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1681 "src/parser.tab.cpp"
    break;

  case 9: /* postfix_expression: postfix_expression '(' ')'  */
#line 93 "src/parser.y"
                               { (yyval.node) = new FunctionCall((yyvsp[-2].node)->identifier); delete (yyvsp[-2].node); }
#line 1687 "src/parser.tab.cpp"
    break;

  case 10: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 94 "src/parser.y"
                                                        { (yyval.node) = new FunctionCall((yyvsp[-3].node)->identifier, (yyvsp[-1].node_list)); delete (yyvsp[-3].node); }
#line 1693 "src/parser.tab.cpp"
    break;

  case 13: /* postfix_expression: postfix_expression INC_OP  */
#line 97 "src/parser.y"
                              { (yyval.node) = new PostIncExpr((yyvsp[-1].node)); }
#line 1699 "src/parser.tab.cpp"
    break;

  case 14: /* postfix_expression: postfix_expression DEC_OP  */
#line 98 "src/parser.y"
                              { (yyval.node) = new PostDecExpr((yyvsp[-1].node)); }
#line 1705 "src/parser.tab.cpp"
    break;

  case 15: /* argument_expression_list: assignment_expression  */
#line 102 "src/parser.y"
                          { (yyval.node_list) = new NodeList((yyvsp[0].node)); }
#line 1711 "src/parser.tab.cpp"
    break;

  case 16: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 103 "src/parser.y"
                                                       { (yyval.node_list) = (yyvsp[-2].node_list); (yyval.node_list)->add_node((yyvsp[0].node)); }
#line 1717 "src/parser.tab.cpp"
    break;

  case 17: /* unary_expression: postfix_expression  */
#line 107 "src/parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1723 "src/parser.tab.cpp"
    break;

  case 18: /* unary_expression: INC_OP unary_expression  */
#line 108 "src/parser.y"
                            { (yyval.node) = new PreIncExpr((yyvsp[0].node)); }
#line 1729 "src/parser.tab.cpp"
    break;

  case 19: /* unary_expression: DEC_OP unary_expression  */
#line 109 "src/parser.y"
                            { (yyval.node) = new PreDecExpr((yyvsp[0].node)); }
#line 1735 "src/parser.tab.cpp"
    break;

  case 20: /* unary_expression: unary_operator cast_expression  */
#line 110 "src/parser.y"
                                   {
    if (*(yyvsp[-1].string) == "&") {
      (yyval.node) = new AddrOfExpr((yyvsp[0].node));
    } else if (*(yyvsp[-1].string) == "*") {
      (yyval.node) = new DerefExpr((yyvsp[0].node));
    } else if (*(yyvsp[-1].string) == "+") {
      (yyval.node) = new PlusExpr((yyvsp[0].node));
    } else if (*(yyvsp[-1].string) == "-") {
      (yyval.node) = new MinusExpr((yyvsp[0].node));
    } else if (*(yyvsp[-1].string) == "~") {
      (yyval.node) = new BitNotExpr((yyvsp[0].node));
    } else if (*(yyvsp[-1].string) == "!") {
      (yyval.node) = new NotExpr((yyvsp[0].node));
    } else {
      // Error
    }
    delete (yyvsp[-1].string);
  }
#line 1758 "src/parser.tab.cpp"
    break;

  case 23: /* unary_operator: '&'  */
#line 133 "src/parser.y"
        { (yyval.string) = new std::string("&"); }
#line 1764 "src/parser.tab.cpp"
    break;

  case 24: /* unary_operator: '*'  */
#line 134 "src/parser.y"
        { (yyval.string) = new std::string("*"); }
#line 1770 "src/parser.tab.cpp"
    break;

  case 25: /* unary_operator: '+'  */
#line 135 "src/parser.y"
        { (yyval.string) = new std::string("+"); }
#line 1776 "src/parser.tab.cpp"
    break;

  case 26: /* unary_operator: '-'  */
#line 136 "src/parser.y"
        { (yyval.string) = new std::string("-"); }
#line 1782 "src/parser.tab.cpp"
    break;

  case 27: /* unary_operator: '~'  */
#line 137 "src/parser.y"
        { (yyval.string) = new std::string("~"); }
#line 1788 "src/parser.tab.cpp"
    break;

  case 28: /* unary_operator: '!'  */
#line 138 "src/parser.y"
        { (yyval.string) = new std::string("!"); }
#line 1794 "src/parser.tab.cpp"
    break;

  case 29: /* cast_expression: unary_expression  */
#line 143 "src/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1800 "src/parser.tab.cpp"
    break;

  case 31: /* multiplicative_expression: cast_expression  */
#line 148 "src/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1806 "src/parser.tab.cpp"
    break;

  case 32: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 149 "src/parser.y"
                                                  { (yyval.node) = new MulExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1812 "src/parser.tab.cpp"
    break;

  case 33: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 150 "src/parser.y"
                                                  { (yyval.node) = new DivExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1818 "src/parser.tab.cpp"
    break;

  case 34: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 151 "src/parser.y"
                                                  { (yyval.node) = new ModExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1824 "src/parser.tab.cpp"
    break;

  case 35: /* additive_expression: multiplicative_expression  */
#line 155 "src/parser.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1830 "src/parser.tab.cpp"
    break;

  case 36: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 156 "src/parser.y"
                                                      { (yyval.node) = new AddExpr((yyvsp[-2].node) ,(yyvsp[0].node)); }
#line 1836 "src/parser.tab.cpp"
    break;

  case 37: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 157 "src/parser.y"
                                                      { (yyval.node) = new SubExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1842 "src/parser.tab.cpp"
    break;

  case 38: /* shift_expression: additive_expression  */
#line 161 "src/parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1848 "src/parser.tab.cpp"
    break;

  case 39: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 162 "src/parser.y"
                                                 { (yyval.node) = new LshiftExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1854 "src/parser.tab.cpp"
    break;

  case 40: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 163 "src/parser.y"
                                                  { (yyval.node) = new RshiftExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1860 "src/parser.tab.cpp"
    break;

  case 41: /* relational_expression: shift_expression  */
#line 167 "src/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1866 "src/parser.tab.cpp"
    break;

  case 42: /* relational_expression: relational_expression '<' shift_expression  */
#line 168 "src/parser.y"
                                               { (yyval.node) = new LtExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1872 "src/parser.tab.cpp"
    break;

  case 43: /* relational_expression: relational_expression '>' shift_expression  */
#line 169 "src/parser.y"
                                               { (yyval.node) = new GtExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1878 "src/parser.tab.cpp"
    break;

  case 44: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 170 "src/parser.y"
                                                 { (yyval.node) = new LeExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1884 "src/parser.tab.cpp"
    break;

  case 45: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 171 "src/parser.y"
                                                 { (yyval.node) = new GeExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1890 "src/parser.tab.cpp"
    break;

  case 46: /* equality_expression: relational_expression  */
#line 175 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1896 "src/parser.tab.cpp"
    break;

  case 47: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 176 "src/parser.y"
                                                    { (yyval.node) = new EqExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1902 "src/parser.tab.cpp"
    break;

  case 48: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 177 "src/parser.y"
                                                    { (yyval.node) = new NeExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1908 "src/parser.tab.cpp"
    break;

  case 49: /* and_expression: equality_expression  */
#line 181 "src/parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1914 "src/parser.tab.cpp"
    break;

  case 50: /* and_expression: and_expression '&' equality_expression  */
#line 182 "src/parser.y"
                                           { (yyval.node) = new AndExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1920 "src/parser.tab.cpp"
    break;

  case 51: /* exclusive_or_expression: and_expression  */
#line 186 "src/parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1926 "src/parser.tab.cpp"
    break;

  case 52: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 187 "src/parser.y"
                                               { (yyval.node) = new ExclOrExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1932 "src/parser.tab.cpp"
    break;

  case 53: /* inclusive_or_expression: exclusive_or_expression  */
#line 191 "src/parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1938 "src/parser.tab.cpp"
    break;

  case 54: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 192 "src/parser.y"
                                                        { (yyval.node) = new InclOrExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1944 "src/parser.tab.cpp"
    break;

  case 55: /* logical_and_expression: inclusive_or_expression  */
#line 196 "src/parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1950 "src/parser.tab.cpp"
    break;

  case 56: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 197 "src/parser.y"
                                                          { (yyval.node) = new LogicalAndExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1956 "src/parser.tab.cpp"
    break;

  case 57: /* logical_or_expression: logical_and_expression  */
#line 201 "src/parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1962 "src/parser.tab.cpp"
    break;

  case 58: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 202 "src/parser.y"
                                                       { (yyval.node) = new LogicalOrExpr((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1968 "src/parser.tab.cpp"
    break;

  case 59: /* conditional_expression: logical_or_expression  */
#line 206 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1974 "src/parser.tab.cpp"
    break;

  case 60: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 207 "src/parser.y"
                                                                    { (yyval.node) = new TernaryOp((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1980 "src/parser.tab.cpp"
    break;

  case 61: /* assignment_expression: conditional_expression  */
#line 211 "src/parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 1986 "src/parser.tab.cpp"
    break;

  case 62: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 212 "src/parser.y"
                                                               {
    // Expand assignments like x += 5 into x = x + 5.
    if (*(yyvsp[-1].string) == "=") {
      (yyval.node) = new AssignmentExpr((yyvsp[-2].node), (yyvsp[0].node));
    } else if (*(yyvsp[-1].string) == "*=") {
      (yyval.node) = new AssignmentExpr((yyvsp[-2].node), new MulExpr((yyvsp[-2].node), (yyvsp[0].node)));
    } else if (*(yyvsp[-1].string) == "/=") {
      (yyval.node) = new AssignmentExpr((yyvsp[-2].node), new DivExpr((yyvsp[-2].node), (yyvsp[0].node)));
    } else if (*(yyvsp[-1].string) == "%=") {
      (yyval.node) = new AssignmentExpr((yyvsp[-2].node), new ModExpr((yyvsp[-2].node), (yyvsp[0].node)));
    } else if (*(yyvsp[-1].string) == "+=") {
      (yyval.node) = new AssignmentExpr((yyvsp[-2].node), new AddExpr((yyvsp[-2].node), (yyvsp[0].node)));
    } else if (*(yyvsp[-1].string) == "-=") {
      (yyval.node) = new AssignmentExpr((yyvsp[-2].node), new SubExpr((yyvsp[-2].node), (yyvsp[0].node)));
    } else if (*(yyvsp[-1].string) == "<<=") {
      (yyval.node) = new AssignmentExpr((yyvsp[-2].node), new LshiftExpr((yyvsp[-2].node), (yyvsp[0].node)));
    } else if (*(yyvsp[-1].string) == ">>=") {
      (yyval.node) = new AssignmentExpr((yyvsp[-2].node), new RshiftExpr((yyvsp[-2].node), (yyvsp[0].node)));
    } else if (*(yyvsp[-1].string) == "&=") {
      (yyval.node) = new AssignmentExpr((yyvsp[-2].node), new AndExpr((yyvsp[-2].node), (yyvsp[0].node)));
    } else if (*(yyvsp[-1].string) == "^=") {
      (yyval.node) = new AssignmentExpr((yyvsp[-2].node), new ExclOrExpr((yyvsp[-2].node), (yyvsp[0].node)));
    } else if (*(yyvsp[-1].string) == "|=") {
      (yyval.node) = new AssignmentExpr((yyvsp[-2].node), new InclOrExpr((yyvsp[-2].node), (yyvsp[0].node)));
    } else {
      // Error
    }
    delete (yyvsp[-1].string);
  }
#line 2020 "src/parser.tab.cpp"
    break;

  case 63: /* assignment_operator: '='  */
#line 244 "src/parser.y"
        { (yyval.string) = new std::string("="); }
#line 2026 "src/parser.tab.cpp"
    break;

  case 64: /* assignment_operator: MUL_ASSIGN  */
#line 245 "src/parser.y"
               { (yyval.string) = new std::string("*="); }
#line 2032 "src/parser.tab.cpp"
    break;

  case 65: /* assignment_operator: DIV_ASSIGN  */
#line 246 "src/parser.y"
               { (yyval.string) = new std::string("/="); }
#line 2038 "src/parser.tab.cpp"
    break;

  case 66: /* assignment_operator: MOD_ASSIGN  */
#line 247 "src/parser.y"
               { (yyval.string) = new std::string("%="); }
#line 2044 "src/parser.tab.cpp"
    break;

  case 67: /* assignment_operator: ADD_ASSIGN  */
#line 248 "src/parser.y"
               { (yyval.string) = new std::string("+="); }
#line 2050 "src/parser.tab.cpp"
    break;

  case 68: /* assignment_operator: SUB_ASSIGN  */
#line 249 "src/parser.y"
               { (yyval.string) = new std::string("-="); }
#line 2056 "src/parser.tab.cpp"
    break;

  case 69: /* assignment_operator: LEFT_ASSIGN  */
#line 250 "src/parser.y"
                { (yyval.string) = new std::string("<<="); }
#line 2062 "src/parser.tab.cpp"
    break;

  case 70: /* assignment_operator: RIGHT_ASSIGN  */
#line 251 "src/parser.y"
                 { (yyval.string) = new std::string(">>="); }
#line 2068 "src/parser.tab.cpp"
    break;

  case 71: /* assignment_operator: AND_ASSIGN  */
#line 252 "src/parser.y"
               { (yyval.string) = new std::string("&="); }
#line 2074 "src/parser.tab.cpp"
    break;

  case 72: /* assignment_operator: XOR_ASSIGN  */
#line 253 "src/parser.y"
               { (yyval.string) = new std::string("^="); }
#line 2080 "src/parser.tab.cpp"
    break;

  case 73: /* assignment_operator: OR_ASSIGN  */
#line 254 "src/parser.y"
              { (yyval.string) = new std::string("|="); }
#line 2086 "src/parser.tab.cpp"
    break;

  case 74: /* expression: assignment_expression  */
#line 258 "src/parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2092 "src/parser.tab.cpp"
    break;

  case 76: /* constant_expression: conditional_expression  */
#line 263 "src/parser.y"
                           { (yyval.node) = (yyvsp[0].node); }
#line 2098 "src/parser.tab.cpp"
    break;

  case 77: /* declaration: declaration_specifiers ';'  */
#line 269 "src/parser.y"
                               { (yyval.node) = (yyvsp[-1].type_spec); }
#line 2104 "src/parser.tab.cpp"
    break;

  case 78: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 270 "src/parser.y"
                                                    { (yyval.node) = new Declaration((yyvsp[-2].type_spec), *(yyvsp[-1].declarator_list)); delete (yyvsp[-1].declarator_list); }
#line 2110 "src/parser.tab.cpp"
    break;

  case 81: /* declaration_specifiers: type_specifier  */
#line 278 "src/parser.y"
                   { (yyval.type_spec) = (yyvsp[0].type_spec); }
#line 2116 "src/parser.tab.cpp"
    break;

  case 85: /* init_declarator_list: init_declarator  */
#line 285 "src/parser.y"
                    {
    (yyval.declarator_list) = new std::vector<Declarator*>();
    (yyval.declarator_list)->push_back((yyvsp[0].declarator));
  }
#line 2125 "src/parser.tab.cpp"
    break;

  case 86: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 289 "src/parser.y"
                                             {
    (yyval.declarator_list) = (yyvsp[-2].declarator_list);
    (yyval.declarator_list)->push_back((yyvsp[0].declarator));
  }
#line 2134 "src/parser.tab.cpp"
    break;

  case 87: /* init_declarator: declarator  */
#line 296 "src/parser.y"
               { (yyval.declarator) = (yyvsp[0].declarator); }
#line 2140 "src/parser.tab.cpp"
    break;

  case 88: /* init_declarator: declarator '=' initializer  */
#line 297 "src/parser.y"
                               { (yyval.declarator) = new InitDeclarator((yyvsp[-2].declarator), (yyvsp[0].node_list)); }
#line 2146 "src/parser.tab.cpp"
    break;

  case 94: /* type_specifier: VOID  */
#line 312 "src/parser.y"
         { (yyval.type_spec) = new PrimType("void"); }
#line 2152 "src/parser.tab.cpp"
    break;

  case 95: /* type_specifier: CHAR  */
#line 313 "src/parser.y"
         { (yyval.type_spec) = new PrimType("char"); }
#line 2158 "src/parser.tab.cpp"
    break;

  case 97: /* type_specifier: INT  */
#line 315 "src/parser.y"
        { (yyval.type_spec) = new PrimType("int"); }
#line 2164 "src/parser.tab.cpp"
    break;

  case 99: /* type_specifier: FLOAT  */
#line 317 "src/parser.y"
          { (yyval.type_spec) = new PrimType("float"); }
#line 2170 "src/parser.tab.cpp"
    break;

  case 100: /* type_specifier: DOUBLE  */
#line 318 "src/parser.y"
           { (yyval.type_spec) = new PrimType("double"); }
#line 2176 "src/parser.tab.cpp"
    break;

  case 102: /* type_specifier: UNSIGNED  */
#line 320 "src/parser.y"
             { (yyval.type_spec) = new PrimType("unsigned"); }
#line 2182 "src/parser.tab.cpp"
    break;

  case 104: /* type_specifier: enum_specifier  */
#line 322 "src/parser.y"
                   { (yyval.type_spec) = (yyvsp[0].type_spec); }
#line 2188 "src/parser.tab.cpp"
    break;

  case 123: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 365 "src/parser.y"
                                 { (yyval.type_spec) = new EnumSpecifier((yyvsp[-1].node_list)); }
#line 2194 "src/parser.tab.cpp"
    break;

  case 124: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 366 "src/parser.y"
                                            { (yyval.type_spec) = new EnumSpecifier(*(yyvsp[-3].string), (yyvsp[-1].node_list)); delete (yyvsp[-3].string); }
#line 2200 "src/parser.tab.cpp"
    break;

  case 125: /* enum_specifier: ENUM IDENTIFIER  */
#line 367 "src/parser.y"
                    { (yyval.type_spec) = new EnumType(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 2206 "src/parser.tab.cpp"
    break;

  case 126: /* enumerator_list: enumerator  */
#line 371 "src/parser.y"
               { (yyval.node_list) = new NodeList((yyvsp[0].node)); }
#line 2212 "src/parser.tab.cpp"
    break;

  case 127: /* enumerator_list: enumerator_list ',' enumerator  */
#line 372 "src/parser.y"
                                   { (yyval.node_list) = (yyvsp[-2].node_list); (yyval.node_list)->add_node((yyvsp[0].node)); }
#line 2218 "src/parser.tab.cpp"
    break;

  case 128: /* enumerator: IDENTIFIER  */
#line 376 "src/parser.y"
               { (yyval.node) = new Enumerator(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 2224 "src/parser.tab.cpp"
    break;

  case 129: /* enumerator: IDENTIFIER '=' constant_expression  */
#line 377 "src/parser.y"
                                       { (yyval.node) = new Enumerator(*(yyvsp[-2].string), (yyvsp[0].node)); delete (yyvsp[-2].string); }
#line 2230 "src/parser.tab.cpp"
    break;

  case 132: /* declarator: pointer direct_declarator  */
#line 387 "src/parser.y"
                              { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->pointer = true; delete (yyvsp[-1].string); }
#line 2236 "src/parser.tab.cpp"
    break;

  case 133: /* declarator: direct_declarator  */
#line 388 "src/parser.y"
                      { (yyval.declarator) = (yyvsp[0].declarator); (yyval.declarator)->pointer = false; }
#line 2242 "src/parser.tab.cpp"
    break;

  case 134: /* direct_declarator: IDENTIFIER  */
#line 392 "src/parser.y"
               { (yyval.declarator) = new BasicDeclarator(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 2248 "src/parser.tab.cpp"
    break;

  case 135: /* direct_declarator: '(' declarator ')'  */
#line 393 "src/parser.y"
                       { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 2254 "src/parser.tab.cpp"
    break;

  case 136: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 394 "src/parser.y"
                                                  { (yyval.declarator) = new ArrayDeclarator((yyvsp[-3].declarator)->identifier); delete (yyvsp[-3].declarator); }
#line 2260 "src/parser.tab.cpp"
    break;

  case 137: /* direct_declarator: direct_declarator '[' ']'  */
#line 395 "src/parser.y"
                              { (yyval.declarator) = new ArrayDeclarator((yyvsp[-2].declarator)->identifier); delete (yyvsp[-2].declarator); }
#line 2266 "src/parser.tab.cpp"
    break;

  case 138: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 396 "src/parser.y"
                                                  { (yyval.declarator) = new FunctionDeclarator((yyvsp[-3].declarator)->identifier, (yyvsp[-1].node_list)); delete (yyvsp[-3].declarator); }
#line 2272 "src/parser.tab.cpp"
    break;

  case 140: /* direct_declarator: direct_declarator '(' ')'  */
#line 398 "src/parser.y"
                              { (yyval.declarator) = new FunctionDeclarator((yyvsp[-2].declarator)->identifier); delete (yyvsp[-2].declarator); }
#line 2278 "src/parser.tab.cpp"
    break;

  case 141: /* pointer: '*'  */
#line 402 "src/parser.y"
        { (yyval.string) = new std::string("*"); }
#line 2284 "src/parser.tab.cpp"
    break;

  case 147: /* parameter_type_list: parameter_list  */
#line 415 "src/parser.y"
                   { (yyval.node_list) = (yyvsp[0].node_list); }
#line 2290 "src/parser.tab.cpp"
    break;

  case 149: /* parameter_list: parameter_declaration  */
#line 420 "src/parser.y"
                          { (yyval.node_list) = new NodeList((yyvsp[0].node)); }
#line 2296 "src/parser.tab.cpp"
    break;

  case 150: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 421 "src/parser.y"
                                             { (yyval.node_list) = (yyvsp[-2].node_list); (yyval.node_list)->add_node((yyvsp[0].node)); }
#line 2302 "src/parser.tab.cpp"
    break;

  case 151: /* parameter_declaration: declaration_specifiers declarator  */
#line 425 "src/parser.y"
                                      { (yyval.node) = new ParameterDeclaration((yyvsp[-1].type_spec), (yyvsp[0].declarator)); }
#line 2308 "src/parser.tab.cpp"
    break;

  case 170: /* initializer: assignment_expression  */
#line 460 "src/parser.y"
                          { (yyval.node_list) = new NodeList((yyvsp[0].node)); }
#line 2314 "src/parser.tab.cpp"
    break;

  case 171: /* initializer: '{' initializer_list '}'  */
#line 461 "src/parser.y"
                             { (yyval.node_list) = (yyvsp[-1].node_list); }
#line 2320 "src/parser.tab.cpp"
    break;

  case 172: /* initializer: '{' initializer_list ',' '}'  */
#line 462 "src/parser.y"
                                 { (yyval.node_list) = (yyvsp[-2].node_list); }
#line 2326 "src/parser.tab.cpp"
    break;

  case 173: /* initializer_list: initializer  */
#line 466 "src/parser.y"
                { (yyval.node_list) = new NodeList((yyvsp[0].node_list)); }
#line 2332 "src/parser.tab.cpp"
    break;

  case 174: /* initializer_list: initializer_list ',' initializer  */
#line 467 "src/parser.y"
                                     { (yyval.node_list) = (yyvsp[-2].node_list); (yyval.node_list)->add_node((yyvsp[0].node_list)); }
#line 2338 "src/parser.tab.cpp"
    break;

  case 175: /* statement: labeled_statement  */
#line 471 "src/parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 2344 "src/parser.tab.cpp"
    break;

  case 176: /* statement: compound_statement  */
#line 472 "src/parser.y"
                       { (yyval.node) = (yyvsp[0].node_list); }
#line 2350 "src/parser.tab.cpp"
    break;

  case 177: /* statement: expression_statement  */
#line 473 "src/parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2356 "src/parser.tab.cpp"
    break;

  case 178: /* statement: selection_statement  */
#line 474 "src/parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2362 "src/parser.tab.cpp"
    break;

  case 179: /* statement: iteration_statement  */
#line 475 "src/parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2368 "src/parser.tab.cpp"
    break;

  case 180: /* statement: jump_statement  */
#line 476 "src/parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 2374 "src/parser.tab.cpp"
    break;

  case 182: /* labeled_statement: CASE constant_expression ':' statement  */
#line 481 "src/parser.y"
                                           { (yyval.node) = new CaseStatement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2380 "src/parser.tab.cpp"
    break;

  case 183: /* labeled_statement: DEFAULT ':' statement  */
#line 482 "src/parser.y"
                          { (yyval.node) = new DefaultStatement((yyvsp[0].node)); }
#line 2386 "src/parser.tab.cpp"
    break;

  case 184: /* compound_statement: '{' '}'  */
#line 486 "src/parser.y"
            { (yyval.node_list) = new NodeList(new EmptyNode()); }
#line 2392 "src/parser.tab.cpp"
    break;

  case 185: /* compound_statement: '{' statement_list '}'  */
#line 487 "src/parser.y"
                           { (yyval.node_list) = (yyvsp[-1].node_list); }
#line 2398 "src/parser.tab.cpp"
    break;

  case 186: /* compound_statement: '{' declaration_list '}'  */
#line 488 "src/parser.y"
                             { (yyval.node_list) = (yyvsp[-1].node_list); }
#line 2404 "src/parser.tab.cpp"
    break;

  case 187: /* compound_statement: '{' declaration_list statement_list '}'  */
#line 489 "src/parser.y"
                                            {
    (yyval.node_list) = new StatementList();
    (yyval.node_list)->add_node((yyvsp[-2].node_list));
    (yyval.node_list)->add_node((yyvsp[-1].node_list));
  }
#line 2414 "src/parser.tab.cpp"
    break;

  case 188: /* declaration_list: declaration  */
#line 497 "src/parser.y"
                { (yyval.node_list) = new StatementList((yyvsp[0].node)); }
#line 2420 "src/parser.tab.cpp"
    break;

  case 189: /* declaration_list: declaration_list declaration  */
#line 498 "src/parser.y"
                                 { (yyval.node_list) = (yyvsp[-1].node_list); (yyval.node_list)->add_node((yyvsp[0].node)); }
#line 2426 "src/parser.tab.cpp"
    break;

  case 190: /* statement_list: statement  */
#line 502 "src/parser.y"
              { (yyval.node_list) = new StatementList((yyvsp[0].node)); }
#line 2432 "src/parser.tab.cpp"
    break;

  case 191: /* statement_list: statement_list statement  */
#line 503 "src/parser.y"
                             { (yyval.node_list) = (yyvsp[-1].node_list); (yyval.node_list)->add_node((yyvsp[0].node)); }
#line 2438 "src/parser.tab.cpp"
    break;

  case 192: /* expression_statement: ';'  */
#line 507 "src/parser.y"
        { (yyval.node) = new EmptyNode(); }
#line 2444 "src/parser.tab.cpp"
    break;

  case 193: /* expression_statement: expression ';'  */
#line 508 "src/parser.y"
                   { (yyval.node) = (yyvsp[-1].node); }
#line 2450 "src/parser.tab.cpp"
    break;

  case 194: /* selection_statement: IF '(' expression ')' statement  */
#line 512 "src/parser.y"
                                    { (yyval.node) = new IfStatement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2456 "src/parser.tab.cpp"
    break;

  case 195: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 513 "src/parser.y"
                                                   { (yyval.node) = new IfElseStatement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2462 "src/parser.tab.cpp"
    break;

  case 196: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 514 "src/parser.y"
                                        { (yyval.node) = new SwitchStatement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2468 "src/parser.tab.cpp"
    break;

  case 197: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 518 "src/parser.y"
                                       { (yyval.node) = new WhileStatement((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2474 "src/parser.tab.cpp"
    break;

  case 198: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 519 "src/parser.y"
                                              { (yyval.node) = new DoWhileStatement((yyvsp[-5].node), (yyvsp[-2].node)); }
#line 2480 "src/parser.tab.cpp"
    break;

  case 199: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 520 "src/parser.y"
                                                                    { (yyval.node) = new ForStatement((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2486 "src/parser.tab.cpp"
    break;

  case 200: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 521 "src/parser.y"
                                                                               { (yyval.node) = new ForStatement((yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2492 "src/parser.tab.cpp"
    break;

  case 202: /* jump_statement: CONTINUE ';'  */
#line 526 "src/parser.y"
                 { (yyval.node) = new ContinueStatement(); }
#line 2498 "src/parser.tab.cpp"
    break;

  case 203: /* jump_statement: BREAK ';'  */
#line 527 "src/parser.y"
              { (yyval.node) = new BreakStatement(); }
#line 2504 "src/parser.tab.cpp"
    break;

  case 204: /* jump_statement: RETURN ';'  */
#line 528 "src/parser.y"
               { (yyval.node) = new ReturnStatement(); }
#line 2510 "src/parser.tab.cpp"
    break;

  case 205: /* jump_statement: RETURN expression ';'  */
#line 529 "src/parser.y"
                          { (yyval.node) = new ReturnStatement((yyvsp[-1].node)); }
#line 2516 "src/parser.tab.cpp"
    break;

  case 206: /* translation_unit: external_declaration  */
#line 533 "src/parser.y"
                         { (yyval.node_list) = new NodeList((yyvsp[0].node)); }
#line 2522 "src/parser.tab.cpp"
    break;

  case 207: /* translation_unit: translation_unit external_declaration  */
#line 534 "src/parser.y"
                                          { (yyval.node_list) = (yyvsp[-1].node_list); (yyval.node_list)->add_node((yyvsp[0].node)); }
#line 2528 "src/parser.tab.cpp"
    break;

  case 208: /* external_declaration: function_definition  */
#line 538 "src/parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2534 "src/parser.tab.cpp"
    break;

  case 209: /* external_declaration: declaration  */
#line 539 "src/parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 2540 "src/parser.tab.cpp"
    break;

  case 211: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 544 "src/parser.y"
                                                         { (yyval.node) = new FunctionDef((yyvsp[-2].type_spec), (yyvsp[-1].declarator), (yyvsp[0].node_list)); }
#line 2546 "src/parser.tab.cpp"
    break;


#line 2550 "src/parser.tab.cpp"

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

#line 549 "src/parser.y"


Node *g_root; // Definition of variable (to match declaration earlier)

Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
