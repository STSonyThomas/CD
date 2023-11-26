%{
#include<stdio.h>
%}

%%

.*[Ss][Oo][Nn][Yy].* {printf("Not a valid string %s",yytext);}
.+ {printf("Valid string %s\n",yytext);}

%%

int main(){
    yylex();
    return 0;
}