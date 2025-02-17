/*
Polynomial addition using circular linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    int x,y,z,coef;
    struct Node* next;
}Node;

Node* createNode(int coef,int x,int y,int z);
void display(Node** head);
void insertLast(Node** head,int coef,int x,int y,int z);
void evalulate(Node* head,int x,int y,int z);
Node* add(Node* p1,Node* p2);
Node* isSameDegree(Node* head,int x,int y,int z);

void main(){
    Node *p1=NULL,*p2=NULL,*pSum=NULL;
    insertLast(&p1,6,2,2,1);
    insertLast(&p1,-4,1,2,5);
    insertLast(&p1,3,3,1,1);
    insertLast(&p1,2,1,5,1);
    insertLast(&p1,-2,1,1,3);

    insertLast(&p2,1,2,2,1);
    insertLast(&p2,2,0,1,5);
    insertLast(&p2,-1,3,1,1);
    insertLast(&p2,2,1,5,1);
    insertLast(&p2,-1,1,1,3);

    display(&p1);
    display(&p2);
    pSum=add(p1,p2);
    display(&pSum);
}

/*
->Create a new pointer of Node type and allocate memory using malloc function
->Initialize all the members.
->return the pointer.
*/
Node* createNode(int coef,int x,int y,int z){
    Node* newNode=(Node* )malloc(sizeof(Node));
    newNode->coef=coef;
    newNode->x=x;
    newNode->y=y;
    newNode->z=z;
    //Circular linked list
    newNode->next=newNode;
    return newNode;
}


void display(Node **head){
    if(*head==NULL)
        return;
    Node* temp=*head;
    //Iterate through all the nodes and print the data
    do{
        printf("%dx^%dy^%dz^%d ",temp->coef,temp->x,temp->y,temp->z);
        temp=temp->next;
    }
    //Since it is circular linked list,you have to check the below condition.
    while(temp!=*head);
    printf("\n");
}


void insertLast(Node** head,int coef,int x,int y,int z){
    Node* newNode=createNode(coef,x,y,z);
    if(*head==NULL)
        *head=newNode;
    else{
        Node* temp=*head;
        //Circular linked list
        while(temp->next!=*head)
            temp=temp->next;
        temp->next=newNode;
        newNode->next=*head;
    }
}
/*
->Initialize the result to 0
->If head is pointing to NULL return.abort
->Create a temporary pointer and assign the value of head to the temporary pointer
->Iterate through each node(each node represents a term of polynomial)
    compute the result by placing corresponding values of variables as passed in the arguments.
->Print the value of of the result.
*/
void evalulate(Node* head,int x,int y,int z){
    if(head==NULL)
        return;
    Node* temp=head;
    float result=0;
    do{
        result+=temp->coef*pow(x,temp->x)*pow(y,temp->y)*pow(z,temp->z);
        temp=temp->next;
    }
    while(temp!=head);
    printf("\nEvaluation: %d",result);
}
/*
->Decalre and initialze pSum pointer to NULL to store the resulting polynomial.
->Decalre temp1 and temp2 to store polynomial 1 and polynomial 2.
->Iterate through each node in p1
    Check if a node with the same degree already exists in pSum (using isSameDegree function).
        If it does, add their coefficients together.
        If it doesn't, add the current node to pSum.
->Iterate through each node in p2
    Check if a node with the same degree already exists in pSum (using isSameDegree function).
        If it does, add their coefficients together.
        If it doesn't, add the current node to pSum.
*/
Node* add(Node* p1,Node* p2){
    Node* pSum=NULL;
    Node* temp1=p1;
    Node* temp2=p2;
    do{
        Node* term=isSameDegree(pSum,temp1->x,temp1->y,temp1->z);
        if(term)
            term->coef+=temp1->coef;
        else
            insertLast(&pSum,temp1->coef,temp1->x,temp1->y,temp1->z);
        temp1=temp1->next;
    }
    while(temp1!=p1);
    do{
        Node* term=isSameDegree(pSum,temp2->x,temp2->y,temp2->z);
        if(term)
            term->coef+=temp2->coef;
        else
            insertLast(&pSum,temp2->coef,temp2->x,temp2->y,temp2->z);
        temp2=temp2->next;
    }
    while(temp2!=p2);
    return pSum;
}
/*
->if head is pointing to NULL, return
->Else create a temporary varibale to which points to same address as head.
->Iterate though the each node of the list
    Check if the current node has the same degrees as the ones passed in the arguments (x,y,z).
        If so return the current node
->If no match is found, return NULL.
*/
Node* isSameDegree(Node* head,int x,int y,int z){
    if(head==NULL)
        return NULL;
    Node* temp=head;
    do{
        if(temp->x==x && temp->y==y && temp->z==z)
            return temp;
        temp=temp->next;
    }
    while(temp!=head);
    return NULL;
}