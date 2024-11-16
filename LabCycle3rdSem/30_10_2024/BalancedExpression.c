#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int top=-1;
char stack[10];

void push(char c){
    top++;
    stack[top]=c;
}
char pop(){
    char temp=stack[top];
    top--;
    return temp;
}


void main(){
    char exp[10]="()";
    for(int i=0;i<strlen(exp);i++){
        char c=exp[i];
        if(c=='{'  ||c=='[' || c=='(')
            push(c);
        if( c=='}' || c==']' ||c==')'){
            if(top==-1){
                printf("\nNot Valid Expression");
                exit(0);
            }
            if(pop()!=c){
                printf("\nNot Valid expression");
                exit(0);
            }
        }
        
    }
    
   

}


