//Program to convert infix expression to postfix expression using stacks
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int precedence(char operator);
bool isOperator(char ch);
void convert(int n,char infix[]);

void main(){
    char infix[20];
    printf("\nEnter an infix expression: ");
    scanf("%s",infix);
    int n=strlen(infix);
    convert(n,infix);
}
/*Function to convert infix expresion to postfix expression*/
void convert(int n,char infix[]){
    char stack[20],postfix[20];
    int top=-1,j=0;
    for(int i=0;i<n;i++){
        char c=infix[i];
        //If char is an operand append to the result.
        if(isalnum(c))
            postfix[j++]=c;
        //When ( is encountred, it needs to be pushed into the stack
        else if(c=='(')
            stack[++top]=infix[i];
        //When ) is encountered, all the elements inside the stack should be popped out.
        else if(c==')'){
            while(top>-1 && stack[top]!='('){
                postfix[j++]=stack[top--];
            }
            top--;
        }
        //When char is an operator, check for the precedence with the top of the stack A + B * (C + D) / F + D * E
        else if(isOperator(c)){
            while (top>-1 && precedence(stack[top])>=precedence(c))
                postfix[j++]=stack[top--];
            stack[++top]=c;
            
        }
    }
    while(top>-1)
        postfix[j++]=stack[top--];
    postfix[j]='\0';
    printf("%s",postfix);
}


/*Below Function returns true if the passed argument is a operator, otherwise it returns false*/
bool isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        return true;
    return false;
}
/*Function to return the precedence of the operator.Priority increases with increase in return value.*/
int precedence(char operator){
    switch(operator){
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
                return 2;
        case '^':
                return 3;
        default: return -1;
    }
}
