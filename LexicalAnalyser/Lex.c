#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int kwd(char buffer[]);

int main(){
    char ch, buffer[15],operators[]="+-*/%=,;()";
    FILE* fp;
    int i,j=0;
    int ido=0;

    char ids[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    fp = fopen("input.txt","r");
    if(fp==NULL){
        perror("File not found\n");
        exit(0);
    }else{
        printf("File found\n");
    }

    while((ch=fgetc(fp))!=EOF){
        for(i=0;i<10;i++){
            // int res = kwd(buffer);
            // printf("%c res is %d\n",ch,res);
            if(ch==operators[i]&& kwd(buffer)==0){
                printf(" id");
            }
        }
        for(i=0;i<10;i++){
            if(ch==operators[i]){
                switch (operators[i]){
                    case '+':
                        printf(" op-plus");
                        break;
                    case '-':
                        printf(" op-sub");
                        break;
                    case '*':
                        printf(" op-mul");
                        break;
                    case '/':
                        printf(" op-div");
                        break;
                    case '%':
                        printf(" op-mod");
                        break;
                    case '=':
                        printf(" op-equ");
                        break;
                    case ';':
                        printf(";\n");
                        break;
                    case ',':
                        printf(",");
                        break;
                    case '(':
                        printf(".\n");
                        break;
                    default:
                        printf("\nSOMETHING WROTE AT OPERATOR TOKENIZATION\n");
         
                }
            }
        }
        //check if alphanumeric character
        if(isalnum(ch)){
            buffer[j++]=ch;

        }
        else if((ch == ' ' || ch == '\n')&& j!=0){
            buffer[j]='\0';
            j=0;
            if(kwd(buffer)==1){
                printf("KWD ");
            }

        }
    }
    fclose(fp);
    return 0;
}

//function definition for key-word definiton

int kwd(char buffer[]){
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
    int flag=0;

    for(int i=0;i<32;i++){
        if(strcmp(keywords[i],buffer)==0){
            flag=1;
            break;
        }
    }
    return flag;
}
