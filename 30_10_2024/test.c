#include <stdio.h>  
#include <stdlib.h>  
#define MAX 100    
int stack[MAX];  
int top = -1;  
void push(int item) 
{  
    if (top >= MAX - 1)
     {  
         printf("Stack Overflow\n");  
        return;  
     }  
      top++;  
      stack[top] = item;  
}  
int pop() 
{  
    if (top < 0)
     {  
        printf("Stack Underflow\n");  
        return -1;  
    }  
    int item = stack[top];  
    top--;  
    return item;  
}  
int isoperator(char symbol) {  
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {  
        return 1;  
    }  
    return 0;  
}  
int evaluate(char expression[])
{  
    int i = 0;  
    char symbol = expression[i];  
    int operand1, operand2, result;  
  
    while (symbol != '\0') {  
        if (symbol >= '0' && symbol <= '9') 
        {  
            int num = symbol - '0';  
            push(num);  
        }  
        else if (isoperator(symbol)) {  
            operand2 = pop();  
            operand1 = pop();  
            switch(symbol) {  
                case '+': result = operand1 + operand2; break;  //switch case
                case '-': result = operand1 - operand2; break;  
                case '*': result = operand1 * operand2; break;  
                case '/': result = operand1 / operand2; break;  
            }  
            push(result);  
        }  
        i++;  
        symbol = expression[i];  
    }  
    result = pop();  
    return result;  
}  
  
int main() {  
    char expression[20];
    printf("enter the expression");
    scanf("%s",expression) ;
    int result = evaluate(expression);  
printf("Result= %d\n", result);  
return 0;  
}  