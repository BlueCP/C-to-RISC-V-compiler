%option noyywrap

D [0-9]
L [a-zA-Z]
H [a-fA-F0-9]
E [Ee][+-]?{D}+
FS (f|F|l|L)
IS (u|U|l|L)*

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

// This lexer is based on https://www.lysator.liu.se/c/ANSI-C-grammar-y.html.

#include "parser.tab.hpp"
%}

%%

"auto"                  { return(AUTO); }
"break"                 { return(BREAK); }
"case"                  { return(CASE); }
"char"                  { return(CHAR); }
"const"                 { return(CONST); }
"continue"              { return(CONTINUE); }
"default"               { return(DEFAULT); }
"do"                    { return(DO); }
"double"                { return(DOUBLE); }
"else"                  { return(ELSE); }
"enum"                  { return(ENUM); }
"extern"                { return(EXTERN); }
"float"                 { return(FLOAT); }
"for"                   { return(FOR); }
"goto"                  { return(GOTO); }
"if"                    { return(IF); }
"int"                   { return(INT); }
"long"                  { return(LONG); }
"register"              { return(REGISTER); }
"return"                { return(RETURN); }
"short"                 { return(SHORT); }
"signed"                { return(SIGNED); }
"sizeof"                { return(SIZEOF); }
"static"                { return(STATIC); }
"struct"                { return(STRUCT); }
"switch"                { return(SWITCH); }
"typedef"               { return(TYPEDEF); }
"union"                 { return(UNION); }
"unsigned"              { return(UNSIGNED); }
"void"                  { return(VOID); }
"volatile"              { return(VOLATILE); }
"while"                 { return(WHILE); }

{L}({L}|{D})*           { yylval.string = new std::string(yytext); return(IDENTIFIER); // Return identifier instead of checkType for now.
}

0[xX]{H}+{IS}?          { yylval.number = strtod(yytext, 0); return(CONSTANT); }
0{D}+{IS}?              { yylval.number = strtod(yytext, 0); return(CONSTANT); } // Neglect unsigned/long types for now.
{D}+{IS}?               { yylval.number = strtod(yytext, 0); return(CONSTANT); }
L?'(\\.|[^\\'])+'       { std::string s(yytext); yylval.number = s[1]; return(CONSTANT); } // Char

{D}+{E}{FS}?            { return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?  { return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?  { return(CONSTANT); }

L?\"(\\.|[^\\"])*\"     { return(STRING_LITERAL); }

"..."                   { return(ELLIPSIS); }
">>="                   { return(RIGHT_ASSIGN); }
"<<="                   { return(LEFT_ASSIGN); }
"+="                    { return(ADD_ASSIGN); }
"-="                    { return(SUB_ASSIGN); }
"*="                    { return(MUL_ASSIGN); }
"/="                    { return(DIV_ASSIGN); }
"%="                    { return(MOD_ASSIGN); }
"&="                    { return(AND_ASSIGN); }
"^="                    { return(XOR_ASSIGN); }
"|="                    { return(OR_ASSIGN); }
">>"                    { return(RIGHT_OP); }
"<<"                    { return(LEFT_OP); }
"++"                    { return(INC_OP); }
"--"                    { return(DEC_OP); }
"->"                    { return(PTR_OP); }
"&&"                    { return(AND_OP); }
"||"                    { return(OR_OP); }
"<="                    { return(LE_OP); }
">="                    { return(GE_OP); }
"=="                    { return(EQ_OP); }
"!="                    { return(NE_OP); }
";"                     { return(';'); }
("{"|"<%")              { return('{'); }
("}"|"%>")              { return('}'); }
","                     { return(','); }
":"                     { return(':'); }
"="                     { return('='); }
"("                     { return('('); }
")"                     { return(')'); }
("["|"<:")              { return('['); }
("]"|":>")              { return(']'); }
"."                     { return('.'); }
"&"                     { return('&'); }
"!"                     { return('!'); }
"~"                     { return('~'); }
"-"                     { return('-'); }
"+"                     { return('+'); }
"*"                     { return('*'); }
"/"                     { return('/'); }
"%"                     { return('%'); }
"<"                     { return('<'); }
">"                     { return('>'); }
"^"                     { return('^'); }
"|"                     { return('|'); }
"?"                     { return('?'); }

[ \t\v\n\f]             { /* Ignore formatting escape characters */ }
.                       { /* Ignore invalid characters */ }



%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}

int check_type() {


  return(IDENTIFIER);

  /*
  In future expand this to detect type names as well.
  */

}
