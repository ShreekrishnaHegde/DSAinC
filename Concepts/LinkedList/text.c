/*Implementation of Singly linked list*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* next;
    int data;
}Node;

//to create new Node
Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}


void main(){
    Node* head=NULL;
    
    return 0;
}