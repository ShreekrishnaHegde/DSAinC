/*
-------------------Evaluation of Suffix Expression-------------------
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

float stack[10];
int top=-1;


float pop();
void push(float n);
void calculate(float a,float b,char c);
bool isOperator(char c);
float evaluate(int n,char exp[]);

void main(){

    char exp[20];
    int size;
    printf("\nEnter the suffix expression: ");
    scanf("%s",exp);
    size=strlen(exp);
    printf("%f",evaluate(size,exp));
}

/*
----------------------Algorithm for evaluating suffix expression----------------------
1. For each character in the expression:
    a. If the character is an operand, 
        push it onto the stack.
    b. If the character is an operator, 
        pop two elements from the stack and perform the operation.
2. The result of the expression is the element left in the stack.
*/
float evaluate(int n,char exp[]){
    float x,y;
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
//This function does the arthmatic operations 
void calculate(float a,float b,char c){
    switch(c){
        case '+': push(b+a);
                  break;
        case '-': push(b-a);
                  break;
        case '*': push(b*a);
                  break;
        case '/': push(b/a);
                  break;
        case '^': push(pow(b,a));
                  break;
    }
}
//To add the element into the stack
void push(float n){
    stack[++top]=n;
}
//To remove the element from the stack
float pop(){
    float temp=stack[top--];
    return temp;
}

//Below function returns whether the argument is an operator or not.
bool isOperator(char c){
    if(c=='+' || c=='-' ||c=='*' || c=='/' || c=='^')
        return true;
    return false;
}
