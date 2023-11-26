%{
#include<stdio.h>
#include "y.tab.h"
void yyerror(char *s);
%}

%%

[\t \n] ;
for {return FOR;}
[0-9]+ {return NUM;}
[a-zA-z]([a-zA-Z]|[0-9])* {return ID;}
">=" {return GE;}
"<=" {return LE;}
"==" {return EQ;}
"!=" {return NE;}
"||" {return OR;}
"&&" {return AND;}
. {return yytext[0];}

%%

int yywrap(){
    return 1;
}