/*

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* createNode();
void insertFirst(Node** tail);
void insertLast(Node** tail);
void deleteFirst(Node** tail);
void deleteLast(Node** tail);


void main(){
    Node* tail=NULL;
    int choice;
    printf("1.Insert First\n2.Insert Last\n3.Delete First\n4.Delete Last\n5.Exit\n");
    do{
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insertFirst(&tail);
                break;
            case 2:
                insertLast(&tail);
                break;
            case 3:
                deleteFirst(&tail);
                break;
            case 4:
                deleteLast(&tail);
                break;
            case 5:
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while(choice!=5);
}
Node* createNode(){
    Node* newNode=(Node*)malloc(sizeof(Node));
    printf("Enter the data:");
    scanf("%d",&newNode->data);
    newNode->next=newNode;
    return newNode;
}

void insertFirst(Node** tail){
    Node* newNode=createNode();
    if(*tail==NULL){
        *tail=newNode;
    }
    else{
        newNode->next=(*tail)->next;
        (*tail)->next=newNode;
    }
}

void insertLast(Node** tail){
    Node* newNode=createNode();
    if(*tail==NULL){    
        *tail=newNode;
    }
    else{
        newNode->next=(*tail)->next;
        (*tail)->next=newNode;
        tail=newNode;
    }
}

void deleteFirst(Node** tail){
    if(*tail==NULL){
        printf("List is Empty\n");
    }
    else{
        Node* temp=(*tail)->next;
        (*tail)->next=temp->next;
        free(temp);
    }
}

void deleteLast(Node** tail){
    if(*tail==NULL){
        printf("List is Empty\n");
    }
    Node* temp=(*tail)->next;
    while(temp->next!=*tail){
        temp=temp->next;
    }
    temp->next=(*tail)->next;
    free(*tail);
    *tail=temp;
}