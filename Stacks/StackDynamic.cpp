/*

*/


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


int *stack,*top,n;


void display();
void pop();
void push(int ele);
bool isFull();
bool isEmpty();


int main(){
    int ch,ele;
    printf("\nEnter the size of the stack: ");
    scanf("%d",&n);
    stack=(int*)malloc(n*sizeof(int));
    top=stack-1;

    printf("\n1.Push\n2.Pop\n3.Display\n5.Exit");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter the element to be pushed(0-9): ");
                    scanf("%d",&ele);
                    push(ele);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4:
                    break;
        }
    }   
    while(ch!=4);
    return 0;
}


/*
--------------------------Algorithm for display()-------------------------------------
1. Check if the stack is empty
    If empty, 
    print "The Stack is empty"
3. Else,
    Check if the stack is full
    If full, 
        print "The Stack is full"
4. Else,
        print the stack elements
*/
void display(){
        if(isEmpty())
            printf("\n The Stack is empty!");
        else{
            printf("\nStack elements: ");
            for(int *i=stack;i<=top;i++)
                printf("%d ",*i);
            printf("\n");
        }
}
/*
--------------------------Algorithm for pop()-------------------------------------
1. Check if the stack is empty
2. If empty, 
    print "Stack is Empty"
3. Else, 
    print the popped element and decrement the top
*/
void pop(){        
    if(isEmpty())
        printf("\n Stack is Empty");
    else
        printf("\nThe popped element is %d",*(top--));
}
/*
---------------------------Algorithm for push()-------------------------------------
1. Check if the stack is full
2. If full, 
    print "Stack is Full"
3. Else,
    increment the top and push the element into the stack
    print the pushed element
*/
void push(int ele){
    if(isFull())
        printf("\nStack is Full");
    else{
        *(++top)=ele;
        printf("\nElement pushed is: %d",ele);
    }
}
/*
-----------------------Algorithm for isFull()--------------------------------------
1. Check if the top is equal to MAX-1
If true, 
    return true
3. Else, 
    return false
*/
bool isFull(){
    return top>=stack+n;
}
/*
-----------------------------Algorithm for isEmpty()--------------------------------
1. Check if the top is equal to -1
If true, 
    return true
3. Else,
    return false
*/
bool isEmpty(){
    return top==stack-1;
}



