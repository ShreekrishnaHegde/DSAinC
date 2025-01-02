// // C Program for Implementation of Singly Linked List
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
}Node;

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
    Node *temp=*head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    
}
// Function to print the LinkedList
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf(" %d ---> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver Code
int main() {
    struct Node* head = NULL;
    insertAtFirst(&head);
    insertAtFirst(&head);
    insertAtFirst(&head);
    print(head); 
    deleteFromFirst(&head);
    print(head);
    insertAtLast(&head);
    insertAtLast(&head);
    print(head);

    return 0;
}