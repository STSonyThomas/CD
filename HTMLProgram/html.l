%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
int yylex(void);

%}

%%

"<" {return OPENER;}
">" {return CLOSER;}
"\/" {return ENDER;}
[a-zA-z]+ {return TAG;}
[^><\/]* {return CONTENT;}

%%

int yywrap(){
    return 1;
}

