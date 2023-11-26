%{
#include<stdio.h>
int yylines=0;
%}

%%

^.*\n {printf("Lines is %d\n",++yylines);}

%%

int main(){
    FILE* fp;
    fp=fopen("input.txt","r");
    yyin=fp;
    yylex();
    printf("\n");
    return 0;
    fclose(fp);
}
int yywrap(){
    return 1;
}