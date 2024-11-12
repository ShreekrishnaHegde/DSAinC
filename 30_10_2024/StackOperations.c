//Program to illustrate push and pop operations 
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 50

int stack[MAX],n,top=-1;
char charStack[MAX];
//Palidrome
bool isPalindrome(){
    char str[10];
    printf("\nEnter the string: ");
    gets(str);
    for(int i=0;i!='/0';i++){
        
    }

}
//To display the status of the stack
void status()
{
        if(top==-1)
            printf("\n The Stack is empty! Stack underflow");
        else if(top==n-1)
            printf("\n The Stack is full! Stack Overflow");
        else
            printf("\nStack is not full!");
}
//To delete an elment from the stack
void pop()
{
    if(top<=-1)
        printf("\n Stack is Empty");
    else{
        printf("\nThe popped element is %d",stack[top]);
        top--;
    }
}
//To insert an element into the stack
void push()
{
    int x;
    if(top>=n-1)
        printf("\nStack is Full");
    else{
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
int main()
{
    
    return 0;
}



