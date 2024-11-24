//Program to illustrate push and pop operations 
#include<stdio.h>
#include<stdbool.h>
int stack[20],n,top=-1;
//to check whether stack is full
bool isFull(){
    return top>=n-1;
}
//to check whether stack is empty or not
bool isEmpty(){
    return top<=-1;
}
//To display all elements of stack
void display()
{
        if(isEmpty())
            printf("\n The Stack is empty");
        else{
            printf("\n The elements in Stack: ");
            for(int i=top; i>=0; i--)
                printf(" %d",stack[i]);
        }
}
//To delete an elment from the stack
void pop()
{
    if(isEmpty())
        printf("\n Stack is Empty");
    else{
        printf("\nThe popped element is %d",stack[top]);
        top--;
    }
}
//To diplay the top element of the stack
void peek()
{
    if(isEmpty())
        printf("\n Stack is Empty");
    else{
        printf("\nThe peek element is %d",stack[top]);
    }
}
//To insert an element into the stack
void push()
{
    int x;
    if(isFull())
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
    int choice;
    printf("\nEnter the size of Stack: ");
    scanf("%d",&n);
    printf("\nEnter your choice:");
    printf("\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Quit");
    do
    {   
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("\nThank you!");
                break;
            default:
                printf ("\nInvalid Choice");
                
        }
    }
    while(choice!=5);
    return 0;
}



