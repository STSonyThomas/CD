%{
#include<stdio.h>
#include<stdlib.h>
void yyerror(char *);
int yylex(void);

%}
%token OPENER TAG CLOSER ENDER CONTENT

%%
S:
    ST  {printf("valid HTML Tag\n");}
    |
    ;
ST:
    OPENER TAG CLOSER EXPR OPENER ENDER TAG CLOSER
    |
    OPENER TAG ENDER CLOSER
EXPR:
    ST
    |
    CONTENT
    |
    TAG
    |
    ;


%%

void yyerror(char*s){
    fprintf(stderr,"%s\n",s);
}
int main(){
    yyparse();
    printf("\n");
    return 1;
}


