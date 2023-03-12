%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern Node *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  double number;
  std::string* string;
  Node* node;
  NodeList* node_list;
  Declarator* declarator;
  std::vector<Declarator*> declarator_list;
  InitDeclarator* init_declarator;
  std::vector<InitDeclarator*> init_declarator_list;
  ParameterDeclaration* parameter;
  std::vector<ParameterDeclaration*>* parameter_list;
}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

/*
The following statements are invalid and are left only to keep track of what there is left to implement.
*/
/*
%type <expr> struct_or_union_specifier struct_declaration_list struct_declaration specifier_qualifier_list struct_declarator_list
%type <expr> struct_declarator enum_specifier enumerator_list enumerator
%type <expr> type_name abstract_declarator direct_abstract_declarator
*/

// Unused symbols
%type <node> type_qualifier type_qualifier_list identifier_list

// Primitives
%type <number> CONSTANT
%type <string> IDENTIFIER STRING_LITERAL unary_operator assignment_operator storage_class_specifier pointer
%type <string> struct_or_union
%type <string> declaration_specifiers type_specifier

// Top-level
%type <node> external_declaration function_definition
// Expressions
%type <node> primary_expression postfix_expression unary_expression cast_expression multiplicative_expression
%type <node> additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression
%type <node> inclusive_or_expression logical_and_expression logical_or_expression conditional_expression assignment_expression
%type <node> expression constant_expression
// Statements
%type <node> expression_statement iteration_statement selection_statement labeled_statement statement jump_statement
// Other stuff
%type <node> declaration
// Node lists
%type <node_list> compound_statement statement_list declaration_list translation_unit argument_expression_list
%type <node_list> initializer initializer_list

%type <declarator> declarator direct_declarator init_declarator
%type <declarator_list> init_declarator_list

%type <parameter> parameter_declaration
%type <parameter_list> parameter_list parameter_type_list

%start translation_unit

%%

primary_expression
  : IDENTIFIER { $$ = new Identifier(*$1); delete $1; }
  | CONSTANT { $$ = new Constant($1); }
  | STRING_LITERAL
  | '(' expression ')' { $$ = $2; }
  ;

postfix_expression
  : primary_expression { $$ = $1; }
  | postfix_expression '[' expression ']' { $$ = new ArrayIndex($1, $3); }
  | postfix_expression '(' ')' { $$ = new FunctionCall($1->identifier); delete $1; }
  | postfix_expression '(' argument_expression_list ')' { $$ = new FunctionCall($1->identifier, $3); delete $1; }
  | postfix_expression '.' IDENTIFIER // Struct member access
  | postfix_expression PTR_OP IDENTIFIER // Deference + struct member access
  | postfix_expression INC_OP { $$ = new PostIncExpr($1); }
  | postfix_expression DEC_OP { $$ = new PostDecExpr($1); }
  ;

argument_expression_list
  : assignment_expression { $$ = new NodeList($1); }
  | argument_expression_list ',' assignment_expression { $$ = $1; $$->add_node($3); }
  ;

unary_expression
  : postfix_expression { $$ = $1; }
  | INC_OP unary_expression { $$ = new PreIncExpr($2); }
  | DEC_OP unary_expression { $$ = new PreDecExpr($2); }
  | unary_operator cast_expression {
    if (*$1 == '&') {
      $$ = new AddrOfExpr($2);
    } else if (*$1 == '*') {
      $$ = new DerefExpr($2);
    } else if (*$1 == '+') {
      $$ = new PlusExpr($2);
    } else if (*$1 == '-') {
      $$ = new MinusExpr($2);
    } else if (*$1 == '~') {
      $$ = new BitNotExpr($2);
    } else if (*$1 == '!') {
      $$ = new NotExpr($2);
    } else {
      // Error
    }
    delete $1;
  }
  | SIZEOF unary_expression
  | SIZEOF '(' type_name ')'
  ;

unary_operator
  : '&' { $$ = new std::string('&'); }
  | '*' { $$ = new std::string('*'); }
  | '+' { $$ = new std::string('+'); }
  | '-' { $$ = new std::string('-'); }
  | '~' { $$ = new std::string('~'); }
  | '!' { $$ = new std::string('!'); }
  ;

// Do not implement casts.
cast_expression
  : unary_expression { $$ = $1; }
  | '(' type_name ')' cast_expression
  ;

multiplicative_expression
  : cast_expression { $$ = $1; }
  | multiplicative_expression '*' cast_expression { $$ = new MulExpr($1, $3); }
  | multiplicative_expression '/' cast_expression { $$ = new DivExpr($1, $3); }
  | multiplicative_expression '%' cast_expression { $$ = new ModExpr($1, $3); }
  ;

additive_expression
  : multiplicative_expression { $$ = $1; }
  | additive_expression '+' multiplicative_expression { $$ = new AddExpr($1 ,$3); }
  | additive_expression '-' multiplicative_expression { $$ = new SubExpr($1, $3); }
  ;

shift_expression
  : additive_expression { $$ = $1; }
  | shift_expression LEFT_OP additive_expression { $$ = new LshiftExpr($1, $3); }
  | shift_expression RIGHT_OP additive_expression { $$ = new RshiftExpr($1, $3); }
  ;

relational_expression
  : shift_expression { $$ = $1; }
  | relational_expression '<' shift_expression { $$ = new LtExpr($1, $3); }
  | relational_expression '>' shift_expression { $$ = new GtExpr($1, $3); }
  | relational_expression LE_OP shift_expression { $$ = new LeExpr($1, $3); }
  | relational_expression GE_OP shift_expression { $$ = new GeExpr($1, $3); }
  ;

equality_expression
  : relational_expression { $$ = $1; }
  | equality_expression EQ_OP relational_expression { $$ = new EqExpr($1, $3); }
  | equality_expression NE_OP relational_expression { $$ = new NeExpr($1, $3); }
  ;

and_expression
  : equality_expression { $$ = $1; }
  | and_expression '&' equality_expression { $$ = new AndExpr($1, $3); }
  ;

exclusive_or_expression
  : and_expression { $$ = $1; }
  | exclusive_or_expression '^' and_expression { $$ = new ExclOrExp($1, $3); }
  ;

inclusive_or_expression
  : exclusive_or_expression { $$ = $1; }
  | inclusive_or_expression '|' exclusive_or_expression { $$ = new InclOrExpr($1, $3); }
  ;

logical_and_expression
  : inclusive_or_expression { $$ = $1; }
  | logical_and_expression AND_OP inclusive_or_expression { $$ = new LogicalAndExpression($1, $3); }
  ;

logical_or_expression
  : logical_and_expression { $$ = $1; }
  | logical_or_expression OR_OP logical_and_expression { $$ = new LogicalOrExpression($1, $3); }
  ;

conditional_expression
  : logical_or_expression { $$ = $1; }
  | logical_or_expression '?' expression ':' conditional_expression { $$ = new TernaryOperator($1, $3, $5); }
  ;

assignment_expression
  : conditional_expression { $$ = $1; }
  | unary_expression assignment_operator assignment_expression {
    // Expand assignments like x += 5 into x = x + 5.
    if (*$2 == "=") {
      $$ = new AssignmentExpr($1, $3);
    } else if (*$2 == "*=") {
      $$ = new AssignmentExpr($1, new MulExpr($1, $3));
    } else if (*$2 == "/=") {
      $$ = new AssignmentExpr($1, new DivExpr($1, $3));
    } else if (*$2 == "%=") {
      $$ = new AssignmentExpr($1, new ModExpr($1, $3));
    } else if (*$2 == "+=") {
      $$ = new AssignmentExpr($1, new AddExpr($1, $3));
    } else if (*$2 == "-=") {
      $$ = new AssignmentExpr($1, new SubExpr($1, $3));
    } else if (*$2 == "<<=") {
      $$ = new AssignmentExpr($1, new LshiftExpr($1, $3));
    } else if (*$2 == ">>=") {
      $$ = new AssignmentExpr($1, new RshiftExpr($1, $3));
    } else if (*$2 == "&=") {
      $$ = new AssignmentExpr($1, new BitAndExpr($1, $3));
    } else if (*$2 == "^=") {
      $$ = new AssignmentExpr($1, new ExclOrExpr($1, $3));
    } else if (*$2 == "|=") {
      $$ = new AssignmentExpr($1, new InclOrExpr($1, $3));
    } else {
      // Error
    }
    delete $2;
  }
  ;

assignment_operator
  : '=' { $$ = new std::string('='); }
  | MUL_ASSIGN { $$ = new std::string('*='); }
  | DIV_ASSIGN { $$ = new std::string('/='); }
  | MOD_ASSIGN { $$ = new std::string('%='); }
  | ADD_ASSIGN { $$ = new std::string('+='); }
  | SUB_ASSIGN { $$ = new std::string('-='); }
  | LEFT_ASSIGN { $$ = new std::string('<<='); }
  | RIGHT_ASSIGN { $$ = new std::string('>>='); }
  | AND_ASSIGN { $$ = new std::string('&='); }
  | XOR_ASSIGN { $$ = new std::string('^='); }
  | OR_ASSIGN { $$ = new std::string('|='); }
  ;

expression
  : assignment_expression { $$ = $1; }
  | expression ',' assignment_expression // Do not implement sequence points.
  ;

constant_expression
  : conditional_expression { $$ = $1; }
  ;

// Assume this refers to a variable declaration for now
// (add function declarations later).
declaration
  : declaration_specifiers ';'
  | declaration_specifiers init_declarator_list ';' { $$ = new Declaration(*$1, *$2); delete $1; delete $2; }
  ;

// For now, assume that a declaration specifier can only contain one type.
declaration_specifiers
  : storage_class_specifier
  | storage_class_specifier declaration_specifiers
  | type_specifier { $$ = $1; }
  | type_specifier declaration_specifiers
  | type_qualifier
  | type_qualifier declaration_specifiers
  ;

init_declarator_list
  : init_declarator {
    $$ = new std::vector<Declarator*>();
    $$->push_back($1);
  }
  | init_declarator_list ',' init_declarator {
    $$ = $1;
    $$->push_back($3);
  }
  ;

init_declarator
  : declarator { $$ = $1; }
  | declarator '=' initializer { $$ = new InitDeclarator($1, $3); }
  ;

// Implement typedef later.
storage_class_specifier
  : TYPEDEF
  | EXTERN
  | STATIC
  | AUTO
  | REGISTER
  ;

type_specifier
  : VOID
  | CHAR
  | SHORT
  | INT { $$ = new std::string("int"); }
  | LONG
  | FLOAT
  | DOUBLE
  | SIGNED
  | UNSIGNED
  | struct_or_union_specifier
  | enum_specifier
  | TYPE_NAME
  ;

struct_or_union_specifier
  : struct_or_union IDENTIFIER '{' struct_declaration_list '}'
  | struct_or_union '{' struct_declaration_list '}'
  | struct_or_union IDENTIFIER
  ;

struct_or_union
  : STRUCT
  | UNION // Do not implement unions.
  ;

struct_declaration_list
  : struct_declaration
  | struct_declaration_list struct_declaration
  ;

struct_declaration
  : specifier_qualifier_list struct_declarator_list ';'
  ;

specifier_qualifier_list
  : type_specifier specifier_qualifier_list
  | type_specifier
  | type_qualifier specifier_qualifier_list
  | type_qualifier
  ;

struct_declarator_list
  : struct_declarator
  | struct_declarator_list ',' struct_declarator
  ;

struct_declarator
  : declarator
  | ':' constant_expression
  | declarator ':' constant_expression
  ;

enum_specifier
  : ENUM '{' enumerator_list '}'
  | ENUM IDENTIFIER '{' enumerator_list '}'
  | ENUM IDENTIFIER
  ;

enumerator_list
  : enumerator
  | enumerator_list ',' enumerator
  ;

enumerator
  : IDENTIFIER
  | IDENTIFIER '=' constant_expression
  ;

// Do not implement either of these keywords.
type_qualifier
  : CONST
  | VOLATILE
  ;

declarator
  : pointer direct_declarator { $$ = $2; $$->pointer = true; }
  | direct_declarator { $$ = $1; $$->pointer = false; }
  ;

direct_declarator
  : IDENTIFIER { $$ = new Declarator(*$1); delete $1; }
  | '(' declarator ')' { $$ = $2; }
  | direct_declarator '[' constant_expression ']' { $$ = new ArrayDeclarator($1->identifier, $3); delete $1; }
  | direct_declarator '[' ']'
  | direct_declarator '(' parameter_type_list ')' { $$ = new FunctionDeclarator($1->identifier, *$3); delete $1; delete $3; }
  | direct_declarator '(' identifier_list ')' // Do not implement K&R-style function declarations.
  | direct_declarator '(' ')' { $$ = new FunctionDeclarator($1->identifier); delete $1; }
  ;

pointer
  : '*' { $$ = new std::string('*'); }
  | '*' type_qualifier_list
  | '*' pointer
  | '*' type_qualifier_list pointer
  ;

type_qualifier_list
  : type_qualifier
  | type_qualifier_list type_qualifier
  ;


parameter_type_list
  : parameter_list { $$ = $1; }
  | parameter_list ',' ELLIPSIS // Do not implement this.
  ;

parameter_list
  : parameter_declaration {
    $$ = new std::vector<ParameterDeclaration*>();
    $$->push_back($1);
  }
  | parameter_list ',' parameter_declaration {
    $$ = $1;
    $$->push_back($3);
  }
  ;

parameter_declaration
  : declaration_specifiers declarator { $$ = new ParameterDeclaration(*$1, $2); delete $1; }
  | declaration_specifiers abstract_declarator
  | declaration_specifiers
  ;

// Do not implement K&R-style function declarations.
identifier_list
  : IDENTIFIER
  | identifier_list ',' IDENTIFIER
  ;

type_name
  : specifier_qualifier_list
  | specifier_qualifier_list abstract_declarator
  ;

abstract_declarator
  : pointer
  | direct_abstract_declarator
  | pointer direct_abstract_declarator
  ;

direct_abstract_declarator
  : '(' abstract_declarator ')'
  | '[' ']'
  | '[' constant_expression ']'
  | direct_abstract_declarator '[' ']'
  | direct_abstract_declarator '[' constant_expression ']'
  | '(' ')'
  | '(' parameter_type_list ')'
  | direct_abstract_declarator '(' ')'
  | direct_abstract_declarator '(' parameter_type_list ')'
  ;

initializer
  : assignment_expression { $$ = new NodeList($1); }
  | '{' initializer_list '}' { $$ = $2; }
  | '{' initializer_list ',' '}' { $$ = $2; }
  ;

initializer_list
  : initializer { $$ = new NodeList($1); }
  | initializer_list ',' initializer { $$ = $1; $$->add_node($3); }
  ;

statement
  : labeled_statement { $$ = $1; }
  | compound_statement { $$ = $1; }
  | expression_statement { $$ = $1; }
  | selection_statement { $$ = $1; }
  | iteration_statement { $$ = $1; }
  | jump_statement { $$ = $1; }
  ;

labeled_statement
  : IDENTIFIER ':' statement
  | CASE constant_expression ':' statement { $$ = new CaseStatement($2, $4); }
  | DEFAULT ':' statement { $$ = new DefaultStatement($3); }
  ;

compound_statement
  : '{' '}'
  | '{' statement_list '}' { $$ = $2; }
  | '{' declaration_list '}' { $$ = $2; }
  | '{' declaration_list statement_list '}' {
    $$ = new StatementList();
    $$->add_node($2);
    $$->add_node($3);
  }
  ;

declaration_list
  : declaration { $$ = new StatementList($2); }
  | declaration_list declaration { $$ = $1; $$->add_node($2); }
  ;

statement_list
  : statement { $$ = new StatementList($1); }
  | statement_list statement { $$ = $1; $$->add_node($2); }
  ;

expression_statement
  : ';' { $$ = new EmptyNode(); }
  | expression ';' { $$ = $1; }
  ;

selection_statement
  : IF '(' expression ')' statement { $$ = new IfStatement($3, $5); }
  | IF '(' expression ')' statement ELSE statement { $$ = new IfElseStatement($3, $5, $7); }
  | SWITCH '(' expression ')' statement { $$ = new SwitchStatement($3, $5); }
  ;

iteration_statement
  : WHILE '(' expression ')' statement { $$ = new WhileStatement($3, $5); }
  | DO statement WHILE '(' expression ')' ';' { $$ = new DoWhileStatement($2, $5); }
  | FOR '(' expression_statement expression_statement ')' statement { $$ = new ForStatement($3, $4, $6); }
  | FOR '(' expression_statement expression_statement expression ')' statement { $$ = new ForStatement($3, $4, $5, $7); }
  ;

jump_statement
  : GOTO IDENTIFIER ';'
  | CONTINUE ';' { $$ = new ContinueStatement(); }
  | BREAK ';' { $$ = new BreakStatement(); }
  | RETURN ';' { $$ = new ReturnStatement(); }
  | RETURN expression ';' { $$ = new ReturnStatement($2); }
  ;

translation_unit
  : external_declaration { $$ = new NodeList($1); }
  | translation_unit external_declaration { $$ = $1; $$->add_node($2); }
  ;

external_declaration
  : function_definition { $$ = $1; }
  | declaration { $$ = $1; }
  ;

function_definition
  : declaration_specifiers declarator declaration_list compound_statement
  | declaration_specifiers declarator compound_statement { $$ = new FunctionDef(*$1, $2, $3); delete $1; }
  | declarator declaration_list compound_statement
  | declarator compound_statement
  ;

%%

Node *g_root; // Definition of variable (to match declaration earlier)

Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
