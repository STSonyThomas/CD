digit [0-9]
letter [a-zA-Z]
%{
#include<stdio.h>
int count=0;
%}

%%

{letter}({letter}|{digit})* {count++;}

%%

int main(){
    FILE* fp;
    fp=fopen("input.txt","r");
    yyin=fp;
    yylex();
    printf("\n");
    return 0;
}

int yywrap(){
    return 1;
}
