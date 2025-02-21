/*
---------------------------Program to convert infix expression to postfix expression---------------------------
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int precedence(char operator);
bool isOperator(char ch);
void convert(int n,char infix[]);

void main(){
    char infix[100];
    printf("\nEnter an infix expression: ");
    scanf("%s",infix);
    int n=strlen(infix);
    convert(n,infix);
}

/*
--------------------Algorithm for converting infix to postfix--------------------
1. Create a stack and a result string.
2. For each character in the infix expression string:
    a. If the character is an operand, 
        append it to the result string.
    b. If the character is an opening parenthesis, 
        push it onto the stack.
    c. If the character is a closing parenthesis, 
        pop all the elements from the stack and append them to the result string until 
        an opening parenthesis is encountered.Then pop the opening parenthesis from the stack.
    d. If the character is an operator, 
        pop all the elements from the stack and append them to the result string until 
        an operator with lower precedence is encountered.Then Push the current operator onto the stack.
3. Pop all the remaining elements from the stack and append them to the result string.
4. The result string is the postfix expression.
--------------------------------------------------------------------------------
*/
void convert(int n,char infix[]){
    char stack[100],postfix[100];
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


/*
Below Function returns true if the passed argument is a operator, otherwise it returns false
*/
bool isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='%')
        return true;
    return false;
}

/*
----------------------Algorithm for precedence of operators----------------------
(Priority increases with increase in return value)
1. If the operator is + or -, return 1.
2. If the operator is * or / or %, return 2.
3. If the operator is ^, return 3.
4. If the operator is not any of the above, return -1.
*/
int precedence(char operator){
    switch(operator){
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
        case '%':
                return 2;
        case '^':
                return 3;
        default: return -1;
    }
}
