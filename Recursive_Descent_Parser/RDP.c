#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SUCCESS 1
#define FAILURE 0
//declaring the functions I need for my grammar
int E();
int Edash();
int T();
int Tdash();
int F();
//end of declaration

//global variables and arrays
char *cursor;// to traverse through the input language
char string[64];//to store the input language instance
int main(){
    printf("Enter the string: ");
    scanf("%s",string);
    cursor=string;
    printf("\n");
    printf("\nINPUT\t\tACTION\t\t\t\n");
    if( E() && *cursor=='\0'){
        printf("\nSuccessful\n");
        return 0;
    }else{
        printf("\nString not parsed\nOperation Unsuccessful\n");
        return 1;
    }
}

//grammar E->TE'
int E(){
    printf("%-16s E->TE'\n",cursor);
    if (T())
    {
        if(Edash()){
            return SUCCESS;
        }else{
            return FAILURE;
        }
    }else{
        return FAILURE;
    }
    
}
// E'->+TE'|$
int Edash(){
    if(*cursor=='+'){
        printf("%-16s E'->+TE'\n",cursor);
        cursor++;
        if(T()){
            if(Edash()){
                return SUCCESS;
            }else{
                return FAILURE;
            }
        }else{
            return FAILURE;
        }

    }else{
        printf("%-16s E'->$\n",cursor);
        return SUCCESS;
    }
}
//T->FT'
int T(){
    printf("%-16s T->FT'\n",cursor);
    if(F()){
        if(Tdash()){
            return SUCCESS;
        }else{
            return FAILURE;
        }
    }else{
        return FAILURE;
    }
}

//T'->*FT'|$

int Tdash(){
     if (*cursor == '*') {
        printf("%-16s T' -> * F T'\n", cursor);
        cursor++;
        if (F()) { // Call non-terminal F
            if (Tdash()) // Call non-terminal T'
                return SUCCESS;
            else
                return FAILURE;
        } 
        else
            return FAILURE;
    } 
    else {
        printf("%-16s T' -> $\n", cursor);
        return SUCCESS;
    }
}
//F->(E)|i
int F(){
    if(*cursor=='('){
        printf("%-16s F->(E)\n",cursor);
        cursor++;
        if(E()){
            if(*cursor==')'){
                cursor++;
                return SUCCESS;
            }else{
                return FAILURE;
            }
        }else{
            return FAILURE;
        }
    }else if(*cursor=='i'){
        printf("%-16s F->|i\n",cursor);
        cursor++;
        return SUCCESS;
    }else{
        return FAILURE;
    }
}
