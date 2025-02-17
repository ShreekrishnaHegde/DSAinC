/*

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

/*
------------------------Algorithm to create new Node------------------------
1. Create a new Node
2. Read the data and initialize all the fields accordingly.
3. Initialize next pointer to NULL
4. Return the new Node
*/
Node* createNode(){
    Node* newNode=(Node*)malloc(sizeof(Node));
    printf("Enter the data:");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    return newNode;
}
/*
-----------------Algorithm to insert node at given position
*/
void insert(Node** head){
    int pos;
    printf("\nEnter the position:");
    scanf("%d",&pos);
    Node* newNode=createNode();
    if(*head==NULL){
        *head=newNode;
    }
    else if(pos==1){
        newNode->next=*head;
        *head=newNode;
    }
    else{
        Node* temp=*head;
        for(int i=1;i<pos-1;i++){
            if(temp->next==NULL){
                printf("Invalid Position\n");
                return;
            }
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
/*
------------------------------------Algorithm to insert a new Node at the beginning------------------------------------
1.create a new Node
2.if head is NULL, assign the new Node to head
3.else,
    assign head to next of newNode and
    update head to newNode
*/
void insertFirst(Node** head){
    Node* newNode=createNode();
    if(*head==NULL){
        *head=newNode;
    }
    else{
        newNode->next=*head;
        *head=newNode;
    }
}
/*
-------------------------------------Algorithm to insert a new Node at the end-------------------------------------
1.create a new Node
2.if head is NULL, assign the new Node to head
3.else,
    assign head to temp.
    iterate through the list till the last Node and assign temp to the last Node.
    assign newNode to next of temp.
*/
void insertLast(Node** head){
    Node* newNode=createNode();
    if(*head==NULL){
        *head=newNode;
    }
    else{
        Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
/*
-----------------------------------Algorithm to delete the first Node-----------------------------------
1. if head is NULL, print "List is Empty"
2. else if head->next is NULL (means there is only one node), free head and assign NULL to head
3. else,
    assign head to temp.
    update head to head->next.
    free temp.
*/
void deleteFirst(Node** head){
    if(*head==NULL){
        printf("List is Empty\n");
    }
    else{
        Node* temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}
/*
------------------------------------Algorithm to delete the last Node------------------------------------
1. if head is NULL, print "List is Empty"
2. else if head->next is NULL (means there is only one node), free head and assign NULL to head
3. else,
    assign head to temp.
    iterate through the list till the last Node and assign lastnode to temp.
    free temp.
    assign NULL to next of prev of temp
*/
void deleteLast(Node** head){
    if(*head==NULL){
        printf("List is Empty\n");
    }
    else if((*head)->next==NULL){
        free(*head);
        *head=NULL;
    }
    else{
        Node* temp=*head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}
/*
--------------------------Algorithm to display the list--------------------------
1. if head is NULL, print "List is Empty"
2. else,
    assign head to temp.
    iterate through the list till the last Node and print the data of each Node.
    increment count for each Node.
*/
void display(Node* head){
    int count=0;
    if(head==NULL){
        printf("List is Empty\n");
    }
    else{
        Node* temp=head;
        while(temp!=NULL){
            printf("%d\n",temp->data);
            count++;
            temp=temp->next;
        }
        printf("Number of Nodes:%d\n",count);
        printf("\n");
    }
}
/*
---------------------------Algorithm to get the length of the list---------------------------
1. if head is NULL, print "List is Empty"
2. else,
    assign head to temp.
    iterate through the list till the last Node and increment count for each Node.
    print the count.
*/
void getLength(Node* head){
    int count=0;
    if(head==NULL){
        printf("List is Empty\n");
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("\nNumber of Nodes:%d\n",count);
}

void main(){
    Node* head=NULL;
    int choice,data;
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit");
    do{
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert(&head);
                break;
            case 2:
                delete(&head);
                break;
            case 3:
                display(head);
                getLength(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    while(choice!=6);
}