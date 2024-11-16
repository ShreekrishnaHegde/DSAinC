/*Menu driven program for the operations of linear queue*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 5   

int front=-1;
int rear=-1;
int queue[MAX];
void Enqueue();
void Dequeue();
void Display();

void main(){
    int choice;
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:Enqueue();
                break;
        case 2:Dequeue();
                break;
        case 3:dispplay();
                break;
        default:
                exit(0);
                break;
        }
    }
    while (choice!=4);
}
void Enqueue(){
    int item;
    if(rear=MAX-1)
        printf("\nOverflow");
    else{
        printf("\nEnter the element: ");
        scanf("%d",&item);
        if(front==-1 && rear==-1)
            front++;
        rear++;
        queue[rear]=item;
        printf("\nEnqueue Successfull");
    }
}
void Dequeue(){
    int item;
    if(front==-1 && rear==-1)
        printf("\nUnderflow");
    else{
        item=queue[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
        

    }
}

void Display(){
    int i;
    if(front==-1 && rear==-1)
        printf("\nQueue is empty");
    else if(front==rear)
        printf("\n%d",queue[front]);
    else{
        printf("\nElements of queue are: ");
        for(int i=front;i<=rear;i++)
            printf(" %d",queue[i]);
    }
}