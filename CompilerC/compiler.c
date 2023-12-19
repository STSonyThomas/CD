#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// firstly building a lexical analyser

int kwd (char buffer[]);

int main(){
    char ch, buffer[15];
    char operators[]= "+-*/=,;()";
    int i,j=0;
    FILE *fp;

    fp=fopen("input.txt","r");
    if(fp ==NULL){
        perror("File not found\n");
        exit(0);
    }
    while((ch=fgetc(fp))!=EOF){
        for(int i=0;i<10;i++){
            if(ch==operators[i] && kwd(buffer)==0 ){
                printf("ID");
            }
        }
        
        for( int i=0;i<10;i++){
            if(ch==operators[i]){
                switch(ch){
                case '+':
                    printf("op-plus");
                    break;
                case '-':
                    printf("op-minus");
                    break;
                case '*':
                    printf("opp-mul");
                    break;
                case '/':
                    printf("opp-div");
                    break;
                case ',':
                    printf("%c",ch);
                    break;
                case ';':
                    printf("%c",ch);
                    break;
                case '(':
                    printf(".");
                    break;
                // default:
                // printf(".");
            }
            }

        }

        if(isalnum(ch)){
            buffer[j++]=ch;
        }
        else if((ch == ' ' || ch== '\n' ) && j!=0 ){
            buffer[j]='\0';
            j=0;

            if ( kwd(buffer)==1){
                printf("kwd");
            }
        }

    }
    fclose(fp);
    return 0;
}


int kwd(char buffer[]){
    char keywords[32][10]={"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
    int i,flag=0;
    for(int i=0;i<32;i++){
        if(strcmp(buffer,keywords[i])==0){
            flag=1;
            break;
        }
    }

    return flag;
}
    