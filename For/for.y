%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(char *);
extern FILE *yyin;
%}

%token FOR NUM ID GE LE EQ NE OR AND
%right '='
%left OR AND
%left '>' '<' LE GE EQ NE
%left '+' '-'
%left '*' '/'
%left UMINUS
%left '!'

%%
S:
    ST  {printf("Input Accepted\n");
        exit(0);
    }
    |
    ;
ST:
    FOR '('E';'E2';'E')'DEF 
    |
    ;
DEF:
    '{' BODY '}'
    | E';'
    |
    ;
BODY:
    BODY BODY
    | E';'
    | ST
    |
    ;
E:
    ID '=' E
    | E '+' E
    | E '-' E
    | E '*' E
    | E '/' E
    | E '<' E
    | E '>' E
    | E LE E
    | E GE E
    | E EQ E
    | E NE E
    | E OR E
    | E AND E
    | E '+' '+'
    | E '-' '-'
    | ID 
    | NUM
    |
    ;
E2: 
    E'<'E
    | E'>'E
    | E LE E
    | E GE E
    | E EQ E
    | E NE E
    | E OR E
    | E AND E
%%
void yyerror(char *s){
    fprintf(stderr,"%s\n",s);
}

int main(){
    FILE* fp;
    fp=fopen("input.txt","r");
    yyin=fp;
    yyparse();
    fclose(fp);
    return 0;
}
