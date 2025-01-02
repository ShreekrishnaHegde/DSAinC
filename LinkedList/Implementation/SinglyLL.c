// // C Program for Implementation of Singly Linked List
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
}Node;

//Operations on Singly Linked List
Node* createNode(int data);
void insertAtFirst(Node** head);
void deleteFromFirst(Node** head);
void insertAtLast(Node** head);
void deleteLast(Node** head);
void insertAtPos(Node **head);
void deleteAtPos(Node** head);
void print(Node* head);
void size(Node* head);
// Driver Code
int main() {
    struct Node* head = NULL;
    insertAtFirst(&head);
    insertAtLast(&head);
    print(head);
    insertAtPos(&head);
    print(head);
    return 0;
}

// Function to create a new node 
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a new element at the beginning of the singly linked list
void insertAtFirst(Node** head) {
    int data;
    Node* newNode=NULL;
    printf("\nEnter the value: ");
    scanf("%d",&data);
    newNode=createNode(data);
    newNode->next = *head;
    *head = newNode;
}
//Function to delete a first element of the list.
void deleteFromFirst(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    free(temp);
}
//Function to insert last node of the list
void insertAtLast(Node** head){
    int data;
    Node *newNode=NULL,*temp=*head;
    printf("\nEnter the value: ");
    scanf("%d",&data);
    newNode=createNode(data);
    if(temp==NULL){
        *head=newNode;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
//Function to delete the last node of the linked list.
void deleteLast(Node** head){
    //If list is empty
    if(*head==NULL){
        printf("\nList is empty!");
        return;
    }
    Node *temp=*head;
    //If list has only 1 node
    if(temp->next==NULL){
        free(temp);
        *head=NULL;
        return;
    }
    //If list has more than 1 node
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
//Function to insert node at given position in linked list
void insertAtPos(Node **head){
    int data,pos;   
    Node *temp=*head,*newNode=NULL;
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    //If position is 0, then call insertFirst function
    if(pos==0){
        insertAtFirst(head);
        return;
    }
    printf("\nEnter the value: ");
    scanf("\n%d",&data);
    newNode=createNode(data);
    for(int i=0;i<pos-1 && temp!=NULL ;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;    
}
//Function to delete a node at given position
void deleteAtPos(Node** head){
    int pos,data;
    Node *temp=*head,*deleted;
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    if(*head==NULL){
        printf("\nList is empty");
        return;
    }
    if(pos==0){
        deleteFromFirst(head);
        return;
    }
    printf("\nEnter the value: ");
    scanf("%d",&data);
    for(int i=0;i<pos && temp!=NULL;i++)
        temp=temp->next;
    if(temp==NULL || temp->next==NULL){
        printf("\nPosition out of range");
        return;
    }
    deleted=temp->next;
    temp->next=temp->next->next;
    free(deleted);    
}
// Function to print the LinkedList
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf(" %d ---> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    size(head);
}

void size(Node* head){
    Node* temp=head;
    int count=0;
    while (temp!=NULL){
        temp=temp->next;
        ++count;
    }
    printf("\nSize of the list is: %d\n",count);
    
}