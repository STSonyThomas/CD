#include<stdio.h>
#include<string.h>


void main(){
 char stack[20],ip[20],opt[10][10][1],ter[10];
 int i=0,j,k,n,top=0,col,row;
    //clearing out the input, stack and the precedence storage matrix
 for(i=0;i<10;i++){
    stack[i]=NULL;
    ip[i]=NULL;
    for(j=0;j<10;j++){
        opt[i][j][1]=NULL;
    }
 }   
 // clearance done and now taking input of the number of terminals required
 printf("Enter the number of terminals\n");
 scanf("%d",&n);
 printf("Enter the terminals\n");
 scanf("%s",&ter);
 printf("\n Enter the table values\n");
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("Enter the value for %c %c", ter[i],ter[j]);
        scanf("%s",opt[i][j]);
    }
 }
 //time to print the table values

 printf("\n*******OPERATOR PRECEDENCE TABLE*******\n");
 for(int i=0;i<n;i++){
    printf("\t%c",ter[i]);
 }// this is the column header

 printf("\n");//just for aesthetics

 for(int i=0;i<n;i++){
    printf("\n%c",ter[i]);
    for(int j=0;j<n;j++){
        printf("\t%c",opt[i][j][0]);
    }
 }// these are the values with the row-headers
stack[top]='$';
i=0;
printf("\nEnter the input string: ");
scanf("%s",ip);
printf("\nSTACK\t\t\tINPUT\t\t\tACTION\n");

while(i<=strlen(ip)){
for(int k=0;k<n;k++){
   if(stack[top]==ter[k]){
      col=k;
   }
   if(ip[i]==ter[k]){
      row=k;
   }
}
//define the exit condition for the loop first
if((stack[top]=='$') && (ip[i]=='$')){
   printf("String Accepted\n");
   break;
}
//checking if the input grammar requires a shift
else if(opt[col][row][0]=='<'||opt[col][row]=='='){
   stack[++top]=opt[col][row][0];
   stack[++top]=ip[i];
   printf("Shift %c",ip[i]);
   i++;

}
//checking if the input grammar/string requires a reduce 
else if(opt[col][row][0]='>'){
   while(stack[top]!='<')--top;
   top--;
   printf("reduce");
}
//if the string has neither a > or a < or an = then the string isnt accepted cause the characters in the string arent recognized
else{
   printf("\nString is not accepted");
   break;
}
printf("\n");
for(k=0;k<=top;k++){
   printf("%c",stack[k]);//printing the current stack on the next line
}
printf("\t\t\t");//just for aesthetics
for(k=i;k<strlen(ip);k++){
   printf("%c",ip[k]);//printing the next to be considered input string balance
}
printf("\t\t\t");//just for aesthetics

}//end of the while loop first defined for the traversal of the input string
}