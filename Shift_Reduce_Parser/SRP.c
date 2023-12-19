#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//global variables and arrays
int i=0,j=0,k=0,z=0,lengthOfString=0;
char inputBuffer[15], stackBuffer[15], actionBuffer[15],shiftBuffer[15];//shiftBuffer is just to store the word shift
//global variables and arrays end


//function to check if the characters have been accumulated for a reduce operation
void check();
//end of declaration of function


int main(){
    printf("The grammar under consideration here is E->E+E \n E->E*E \n E->(E) \n E->id\n");
    printf("Enter the input string: ");
    scanf("%s",inputBuffer);
    lengthOfString=strlen(inputBuffer);
    strcpy(shiftBuffer,"SHIFT->");
    printf("stack\t\tinput\t\taction\t\t");


    //logic for traversing the string while the string length hasnt exceeded and shifting encountered string to the stack
    for(i=0,j=0,k=0;i<lengthOfString;i++,j++,k++){
        if(inputBuffer[i]=='i'&& inputBuffer[i+1]=='d'){
            stackBuffer[j]=inputBuffer[i];
            stackBuffer[j+1]=inputBuffer[i+1];
            stackBuffer[j+2]='\0';
            inputBuffer[i]=' ';
            inputBuffer[i+1]=' ';
            printf("\n%s\t%s\t%sid",stackBuffer,inputBuffer,shiftBuffer);
            check();
        }
        else{
            stackBuffer[j]=inputBuffer[i];
            stackBuffer[j+1]='\0';
            inputBuffer[i]=' ';
            printf("\n%s\t%s\t%ssymbols",stackBuffer,inputBuffer,shiftBuffer);
            check();
        }
    }
}

//start of function definitions

void check(){
    strcpy(actionBuffer,"REDUCE TO E");
    for(z=0;z<lengthOfString;z++){
        if(stackBuffer[z]=='i' && stackBuffer[z+1]=='d'){
            stackBuffer[z]='E';
            stackBuffer[z+1]='\0';
            printf("\n%s\t%s\t%ssymbols",stackBuffer,inputBuffer,actionBuffer);
            i++;
        }
    }
    
    for(z=0;z<lengthOfString;z++){
        if(stackBuffer[z]=='E' && stackBuffer[z+1]=='+' && stackBuffer[z+2]=='E'){
            stackBuffer[z]='E';
            stackBuffer[z+1]='\0';
            stackBuffer[z+2]='\0';
            printf("\n%s\t%s\t%ssymbols",stackBuffer,inputBuffer,actionBuffer);
            j-=2;
        }
    }

     for(z=0;z<lengthOfString;z++){
        if(stackBuffer[z]=='E' && stackBuffer[z+1]=='*' && stackBuffer[z+2]=='E'){
            stackBuffer[z]='E';
            stackBuffer[z+1]='\0';
            stackBuffer[z+2]='\0';
            printf("\n%s\t%s\t%ssymbols",stackBuffer,inputBuffer,actionBuffer);
            j-=2;
        }
    }
     for(z=0;z<lengthOfString;z++){
        if(stackBuffer[z]=='(' && stackBuffer[z+1]=='E' && stackBuffer[z+2]==')'){
            stackBuffer[z]='E';
            stackBuffer[z+1]='\0';
            stackBuffer[z+2]='\0';
            printf("\n%s\t%s\t%ssymbols",stackBuffer,inputBuffer,actionBuffer);
            j-=2;
        }
    }

}