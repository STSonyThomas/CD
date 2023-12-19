#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void main(){
    char operator[2],argument1[5],arguemnt2[5],result[5];
    FILE *fp1,*fp2;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    while(!feof(fp1)){
        fscanf(fp1,"%s%s%s%s",operator,argument1,arguemnt2,result);
        if(strcmp("+",operator)==0){
            fprintf(fp2,"\nMOV R0 %s",argument1);
            fprintf(fp2,"\nADD R0 %s",arguemnt2);
            fprintf(fp2,"\nMOV %s R0", result);
        }
        else if(strcmp("*",operator)==0){
            fprintf(fp2,"\nMOV R0 %s",argument1);
            fprintf(fp2,"\nMUL R0 %s",arguemnt2);
            fprintf(fp2,"\nMOV %s R0", result);
        }
        else if(strcmp("/",operator)==0){
            fprintf(fp2,"\nMOV R0 %s",argument1);
            fprintf(fp2,"\nDIV R0 %s",arguemnt2);
            fprintf(fp2,"\nMOV %s R0", result);
        }
        else if(strcmp("-",operator)==0){
            fprintf(fp2,"\nMOV R0 %s",argument1);
            fprintf(fp2,"\nSUB R0 %s",arguemnt2);
            fprintf(fp2,"\nMOV %s R0", result);
        }
        else if(strcmp("=",operator)==0){
            fprintf(fp2,"\nMOV R0 %s",argument1);
            fprintf(fp2,"\nMOV %s R0", result);
        }
    }
    fclose(fp1);
    fclose(fp2);
}