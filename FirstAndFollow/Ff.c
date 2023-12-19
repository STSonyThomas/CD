#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define EPSILON '#'

// typedef struct Production{
//     char rightSide;
//     char leftSide[10];
// }productions;

int noOfProductions,idx,globalIdx,flag;
char outputBuffer[10],inputProductions[10][10],ch;

void calculate_first(char ch);
void calculate_follow(char ch);

int main(){
    printf("Enter the number of productions : ");
    scanf("%d",&noOfProductions);
 
    //stored here
    for(int idx=0;idx<noOfProductions;idx++){
        printf("Enter right prodcution 1(A->BC): ");
        fscanf(stdin,"%s",inputProductions[idx]);
    }
    //test of storage
    for(int idx=0;idx<noOfProductions;idx++){
        printf("%s\n",inputProductions[idx]);
        printf("%d\n",strlen(inputProductions[idx]));
    }

    do{
        globalIdx=0;
        printf("Symbol whose FIRST and FOLLOW has to be computed: ");
        scanf("%d");
        scanf("%c",&ch);
        calculate_first(ch);
        //print the first output
        for(int idx=0;idx<globalIdx;idx++){
            printf("%c",outputBuffer[idx]);
        }
        printf("\n----\n");
        globalIdx=0;
        // compute follow
        calculate_follow(ch);
        for(idx=0;idx<globalIdx;idx++){
            printf("%c",outputBuffer[idx]);
        }
        printf("\n-----\n");
        //to break out of the loop
        printf("Do you want to continue?(0/1): ");
        scanf("%d",&flag);
    }while(flag);
    return 0;
}

void calculate_first(char ch){
    if(islower(ch)){
        outputBuffer[globalIdx++]=ch;
    }
    else if(isupper(ch)){
        for(int idx=0;idx<noOfProductions;idx++){
            if(inputProductions[idx][0]==ch){
                for(int j =2;j<strlen(inputProductions[idx]);j++){
                    if(islower(inputProductions[idx][j])){
                        outputBuffer[globalIdx++]=inputProductions[idx][j];
                        break;
                    }
                    else if(inputProductions[idx][j]==EPSILON){
                        calculate_follow(inputProductions[idx][j]);
                        break;
                    }
                    else{
                        calculate_first(inputProductions[idx][j]);
                        break;
                    }
                }
            }
        }
    }
}

void calculate_follow(char ch){
    if(inputProductions[0][0]==ch){
        outputBuffer[globalIdx++]='$';
    }
    for(int idx=0;idx<noOfProductions;idx++){
        for(int j=2;j<strlen(inputProductions[idx]);j++){
            if(inputProductions[idx][j]==ch){
                char nextSymbol=inputProductions[idx][j++];
                if(islower(nextSymbol)){
                    outputBuffer[globalIdx++]=nextSymbol;
                    break;
                }
                else if(isupper(nextSymbol)){
                    calculate_first(nextSymbol);
                    break;
                }
                else if((nextSymbol==EPSILON) && (ch!=inputProductions[idx][0])){
                    calculate_follow(inputProductions[idx][0]);
                    break;
                }

            }
        }
    }
}