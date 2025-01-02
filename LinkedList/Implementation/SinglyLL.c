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

/*
---------------------Function to insert a new element at the beginning of the singly linked list-------------------------
->Create a new node.
->If the linked list is empty set the new node as the Head  and return.
->Connect the next pointer of this new node to the Head of the linked list.
->Update the Head pointer and make it points to the new node
*/
void insertAtFirst(Node** head) {
    int data;
    Node* newNode=NULL;
    printf("\nEnter the value: ");
    scanf("%d",&data);
    newNode=createNode(data);
    newNode->next = *head;
    *head = newNode;
}
/*
-----------------------Function to delete a first element of the list.----------------------------------
->Ensure that the Head of the linked list is not NULL; if it is, the list is empty, so return.
->Create a temporary pointer and point it to the current Head of the list.
->Update the current head of the singly linked list to the next node.
->Point the next pointer of the temporary node to NULL to detach it from the singly linked list.
->Delete the temporary node.
*/
void deleteFromFirst(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    free(temp);
}
/*
-----------------------Function to insert last node of the list-----------------------------
->Create a new Node.
->If the list is empty, update the Head pointer to be this new node and then return.
->Otherwise traverse till the last node of the singly linked list.
->Connect next pointer of the last node to the new node.
*/
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

/*
-------------Function to delete the last node of the linked list.------------------------------
->Ensure that the Head of the linked list is not NULL; if it is, the list is empty, so return.
->If the singly linked list has only one node, delete the head node and point the head pointer to NULL.
->Traverse till the second last node of the singly linked list.
->Store the next node of the second last node in a temporary pointer.
->Connect the next pointer of the second last node to NULL.
->Delete the last node represented by the temporary pointer.
*/
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
/*
------------------------------Function to insert node at given position in linked list----------------------------
->Check if the position is 0.
->If it is 0, call the insertAtFirst function to insert the node at the first position of the list.
->Initialize a counter variable and a temporary pointer to traverse the linked list.
->Iterate over the linked list to find the node before the insertion point (position - 1).
    ->If the temporary pointer becomes NULL before reaching the desired position, the position is out of range. Return.
        Create a new node.
->Point the next pointer of the new node to the node present just after the temporary pointer.
->Point the next pointer of the temporary node to the new node and return.
*/
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
/*
->Check if the head pointer of the linked list is NULL.
    If it is NULL, the linked list is empty, so return.
->Check if the position is 0.
    If it is 0, call the deleteFromFirst function to delete the first node.
->Initialize a counter variable and a temporary pointer to traverse the linked list.
->Iterate the linked list to find the node before the deletion point (position - 1).
->If the temporary pointer becomes NULL before reaching the desired position the position is out of range. Return
->Store the next node of the temporary pointer in a temporary pointer.
->Update the next pointer of the temporary pointer to the next pointer of the node to be deleted.
->Delete the node represented by the temporary pointer.
*/
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