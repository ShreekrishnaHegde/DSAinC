#include <stdio.h>

typedef struct Node{
    int data,height;
    struct Node *left,*right;
}Node;

int height(Node* node){
    if(node==NULL)
        return 0;
    return node->height;
}

int max(int a,int b){
    return a>b ? a: b;
}

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->height=1;
    return newNode;
}

int getBalance(Node* node){
    if(node==NULL)
        return 0;
    return height(node->left)-height(node->right);
}

Node* insert(Node* node,int data){
    if(node==NULL)
        return create(data);
    if(data<node->data)
        node->left=insert(node->left,data);
    else if(data>node->right)
        node->right=insert(node->right,data);
    else    
        return node;
    node->height=1+max(height(node->left),height(node->right));    

    int balance=getBalance(node);

    
}