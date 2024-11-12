/*
a. Design, Develop and Implement a Program for the following Stack Applications a.
Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int stack[10];
int top=-1;

bool isOperator(char c);
int pop();
void push(int n);
void calculate(float a,float b,char c);
bool isOperator(char c);
int evaluate(int n,char exp[]);

int evaluate(int n,char exp[]){
    int x,y;
    for(int i=0;i<n;i++){
        char c=exp[i];
        if(isdigit(c))
            push(c-'0');
        else if(isOperator(c)){
            x=pop();
            y=pop();
            calculate(x,y,c);
        }
    }
    return pop();
}
void calculate(float a,float b,char c){
    switch(c){
        case '+': push(a+b);
                  break;
        case '-': push(a-b);
                  break;
        case '*': push(a*b);
                  break;
        case '/': push(a/b);
                  break;
        case '^': push(pow(a,b));
                  break;
    }
}
void push(int n){
    top++;
    stack[top]=n;
}
int pop(){
    int temp=stack[top];
    top--;
    return temp;
}
bool isOperator(char c){
    if(c=='+' || c=='-' ||c=='*' || c=='/' || c=='^')
        return true;
    return false;
}


void main(){

    char exp[20];
    int size;
    printf("\nEnter the suffix expression: ");
    scanf("%s",exp);
    size=strlen(exp);
    printf("%d",evaluate(size,exp));
}

