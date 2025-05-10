%{
#include "type.h"
extern int line_no, syntax_err;
extern A_NODE *root;
extern A_ID *current_id;
extern int current_level;
extern A_TYPE *int_type;    
%}

%token AUTO_SYM BREAK_SYM CASE_SYM CONTINUE_SYM DEFAULT_SYM DO_SYM ELSE_SYM ENUM_SYM FOR_SYM IF_SYM RETURN_SYM
        SIZEOF_SYM STATIC_SYM STRUCT_SYM SWITCH_SYM TYPEDEF_SYM UNION_SYM WHILE_SYM PLUSPLUS MINUSMINUS
        ARROW LSS GTR LEQ GEQ EQL NEQ AMPAMP BARBAR DOTDOTDOT LP RP LB RB LR RR COLON PERIOD COMMA EXCL
        STAR SLASH PERCENT AMP SEMICOLON PLUS MINUS ASSIGN INTEGER_CONSTANT FLOAT_CONSTANT STRING_LITERAL
        CHARACTER_CONSTANT CONST_SYM ACCENT BAR QUESTION TILDE IDENTIFIER TYPE_IDENTIFIER GOTO_SYM
        LSHIFT RSHIFT
%start program

%%
program : translation_unit
        {root = makeNode(N_PROGRAM, NIL, $1, NIL); checkForwardReference();}
    ;
translation_unit
    : external_declaration  {$$ = $1;}
    | translation_unit external_declaration {$$ = linkDeclaratorList($1, $2);}
    ;
external_declaration
    : function_definition   {$$ = $1;}
    | declaration   {$$ = $1;}
    ;
function_definition
    : declaration_specifiers declarator {$$ = setFunctionDeclaratorSpecifier($2, $1);}
     compound_statement {$$ = setFunctionDeclaratorBody($3, $4);}
    | declarator {$$ = setFunctionDeclaratorSpecifier($1, makeSpecifier(int_type, 0));}
     compound_statement {$$ = setFunctionDeclaratorBody($2, $3);}
    ;
declaration_list_opt
    : /* empty */ {$$ = NIL;}
    | declaration_list {$$ = $1;}
    ;
declaration_list
    : declaration {$$ = $1;}
    | declaration_list declaration {$$ = linkDeclaratorList($1,$2);}
    ;
declaration
    : declaration_specifiers init_declarator_list_opt SEMICOLON {$$ = setDeclarationListSpecifier($2, $1);}
    ;
declaration_specifiers
    : type_specifier {$$ = makeSpecifier($1, 0);}
    | storage_class_specifier {$$ = makeSpecifier(0, $1);}
    | type_specifier declaration_specifiers {$$ = updateSpecifier($2, $1, 0);}
    | storage_class_specifier declaration_specifiers {$$ = updateSpecifier($2, 0, $1);}
    ;
storage_class_specifier
    : AUTO_SYM {$$ = S_AUTO;} | STATIC_SYM {$$ = S_STATIC;} | TYPEDEF_SYM {$$ = S_TYPEDEF;}
    ;
type_qualifier_opt
    :  /* empty */
    | type_qualifier
    ;
type_qualifier
    : CONST_SYM
    ;
init_declarator_list_opt
    :   /* empty */ {$$ = makeDummyIdentifier();}
    | init_declarator_list {$$ = $1;}
    ;
init_declarator_list
    : init_declarator {$$ = $1;}
    | init_declarator_list COMMA init_declarator {$$ = linkDeclaratorList($1, $3);}
    ;
init_declarator
    : declarator {$$ = $1;}
    | declarator ASSIGN initializer {$$ = setDeclaratorInit($1, $3);}
    ;
type_specifier
    : struct_specifier {$$ = $1;}
    | enum_specifier {$$ = $1;}
    | TYPE_IDENTIFIER {$$ = $1;}
    ;

struct_specifier
    : struct_or_union IDENTIFIER 
    {$$ = setTypeStructOrEnumIdentifier($1, $2, ID_STRUCT);}
    LR {$$ = current_id; current_level++;} struct_declaration_list RR
    {checkForwardReference(); $$ = setTypeField($3, $6); current_level--; current_id = $5;}
    | struct_or_union {$$ = makeType($1);} LR {$$ = current_id; current_level++;}
     struct_declaration_list RR {checkForwardReference(); $$ = setTypeField($2, $5);
     current_level--; current_id = $4;}
    | struct_or_union IDENTIFIER
    {$$ = getTypeOfStructOrEnumRefIdentifier($1, $2, ID_STRUCT);}
    ;
struct_or_union
    : STRUCT_SYM {$$ = T_STRUCT;}
    | UNION_SYM {$$ = T_UNION;}
    ;
struct_declaration_list
    : struct_declaration {$$ = $1;}
    | struct_declaration_list struct_declaration {$$ = linkDeclaratorList($1, $2);}
    ;
struct_declaration
    : type_specifier struct_declarator_list SEMICOLON
    {$$ = setStructDeclaratorListSpecifier($2, $1);}
    ;

struct_declarator_list
    : struct_declarator {$$ = $1;}
    | struct_declarator_list COMMA struct_declarator {$$ = linkDeclaratorList($1, $3)}
    ;
struct_declarator
    : declarator {$$ = $1;}
    ;

enum_specifier
    : ENUM_SYM IDENTIFIER
      {$$ = setTypeStructOrEnumIdentifier(T_ENUM, $2, ID_ENUM);}
     LR enumerator_list RR {$$ = setTypeField($3, $5);}
    | ENUM_SYM {$$ = makeType(T_ENUM)}
    LR enumerator_list RR {$$ = setTypeField($2, $4);}
    | ENUM_SYM IDENTIFIER
    {$$ = getTypeOfStructOrEnumRefIdentifier(T_ENUM, $2, ID_ENUM);}
    ;
enumerator_list
    : enumerator {$$ = $1;}
    | enumerator_list COMMA enumerator {$$ = linkDeclaratorList($1, $3);}
    ;
enumerator
    : IDENTIFIER
    {$$ = setDeclaratorKind(makeIdentifier($1), ID_ENUM_LITERAL);}
    | IDENTIFIER
     {$$ = setDeclaratorKind(makeIdentifier($1), ID_ENUM_LITERAL);}
     ASSIGN constant_expression {$$=setDeclaratorInit($2, $4);}
    ;
declarator
    : pointer direct_declarator
    | direct_declarator
    ;
pointer
    : STAR type_qualifier_opt
    | STAR type_qualifier_opt pointer
    ;

direct_declarator
    : IDENTIFIER
    | LP declarator RP
    | direct_declarator LB constant_expression_opt RB
    | direct_declarator LP parameter_type_list_opt RP
    ;
constant_expression_opt
    : /* empty */
    | constant_expression
    ;
parameter_type_list_opt
    : /* empty */
    | parameter_type_list
    ;
parameter_type_list
    : parameter_list
    | parameter_list COMMA DOTDOTDOT
    ;
parameter_list
    : parameter_declaration
    | parameter_list COMMA parameter_declaration
    ;
parameter_declaration
    : declaration_specifiers declarator
    | declaration_specifiers abstract_declarator_opt
    ;
abstract_declarator_opt
    : /* empty */
    | abstract_declarator
    ;
abstract_declarator
    : pointer
    | direct_abstract_declarator
    | pointer direct_abstract_declarator
    ;
direct_abstract_declarator
    : LP abstract_declarator RP
    | LB constant_expression_opt RB
    | LP parameter_type_list_opt RP
    | direct_abstract_declarator LB constant_expression_opt RB
    | direct_abstract_declarator LP parameter_type_list_opt RP 
    ;
initializer
    : constant_expression {$$ = makeNode(N_INIT_LIST_ONE, NIL, $1, NIL)}
    | LR initializer_list RR {$$ = $2;}
    ;
initializer_list
    : initializer {$$ = makeNode(N_INIT_LIST, $1, NIL, makeNode(N_INIT_LIST_NIL, NIL, NIL, NIL)); // 오른쪽 끝은 NIL}
    | initializer_list COMMA initializer {$$ = makeNodeList(N_INIT_LIST, $1, $3);}
    ;
statement_list_opt
    : /* empty */
    | statement_list
    ;
statement_list
    : statement
    | statement_list statement
    ;
statement
    : labeled_statement
    | compound_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    ;

labeled_statement
    : CASE_SYM constant_expression COLON statement
    | DEFAULT_SYM COLON statement
    ;

compound_statement
    : LR declaration_list_opt statement_list_opt RR
    ;

expression_statement
    : SEMICOLON
    | expression SEMICOLON
    ;

selection_statement
    : IF_SYM LP expression RP statement
    | IF_SYM LP expression RP statement ELSE_SYM statement
    | SWITCH_SYM LP expression RP statement
    ;
iteration_statement
    : WHILE_SYM LP expression RP statement
    | DO_SYM statement WHILE_SYM LP expression RP SEMICOLON
    | FOR_SYM LP expression_opt SEMICOLON expression_opt SEMICOLON expression_opt RP statement
    ;
expression_opt
    : /* empty */
    | expression
    ;
jump_statement
    : RETURN_SYM expression_opt SEMICOLON
    | CONTINUE_SYM SEMICOLON
    | BREAK_SYM SEMICOLON
    | GOTO_SYM IDENTIFIER SEMICOLON
    ;
primary_expression
    : IDENTIFIER
    | INTEGER_CONSTANT
    | FLOAT_CONSTANT
    | CHARACTER_CONSTANT
    | STRING_LITERAL
    | LP expression RP
    ;
postfix_expression
    : primary_expression
    | postfix_expression LB expression RB
    | postfix_expression LP arg_expression_list_opt RP
    | postfix_expression PERIOD IDENTIFIER
    | postfix_expression ARROW IDENTIFIER
    | postfix_expression PLUSPLUS
    | postfix_expression MINUSMINUS
    ;
arg_expression_list_opt
    : /* empty */
    | arg_expression_list
    ;

arg_expression_list
    : assignment_expression
    | arg_expression_list COMMA assignment_expression
    ;

unary_expression
    : postfix_expression
    | PLUSPLUS unary_expression
    | MINUSMINUS unary_expression
    | AMP cast_expression
    | STAR cast_expression
    | EXCL cast_expression
    | MINUS cast_expression
    | PLUS cast_expression
    | TILDE cast_expression
    | SIZEOF_SYM unary_expression
    | SIZEOF_SYM LP type_name RP
    ;

cast_expression
    : unary_expression
    | LP type_name RP cast_expression
    ;

type_name
    : declaration_specifiers abstract_declarator_opt
    ;

multiplicative_expression
    : cast_expression
    | multiplicative_expression STAR cast_expression
    | multiplicative_expression SLASH cast_expression
    | multiplicative_expression PERCENT cast_expression
    ;

additive_expression
    : multiplicative_expression
    | additive_expression PLUS multiplicative_expression
    | additive_expression MINUS multiplicative_expression

shift_expression
    : additive_expression
    | shift_expression LSHIFT additive_expression
    | shift_expression RSHIFT additive_expression
    ;

relational_expression
    : shift_expression
    | relational_expression LSS shift_expression
    | relational_expression GTR shift_expression
    | relational_expression LEQ shift_expression
    | relational_expression GEQ shift_expression
    ;

equality_expression
    : relational_expression
    | equality_expression EQL relational_expression
    | equality_expression NEQ relational_expression
    ;

AND_expression
    : equality_expression
    | AND_expression AMP equality_expression
    ;

exclusive_OR_expression
    : AND_expression
    | exclusive_OR_expression ACCENT AND_expression
    ;

inclusive_OR_expression
    : exclusive_OR_expression
    | inclusive_OR_expression BAR exclusive_OR_expression
    ;

logical_AND_expression
    : inclusive_OR_expression
    | logical_AND_expression AMPAMP inclusive_OR_expression
    ;

logical_OR_expression
    : logical_AND_expression
    | logical_OR_expression BARBAR logical_AND_expression
    ;

conditional_expression
    : logical_OR_expression
    | logical_OR_expression QUESTION expression COLON conditional_expression
    ;

assignment_expression
    : conditional_expression
    | unary_expression ASSIGN assignment_expression
    ;

expression
    : assignment_expression
    ;

constant_expression
    : expression
    ;
    
    