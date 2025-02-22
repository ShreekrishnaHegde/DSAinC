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

Node* rightRotate(Node* y){
    Node* x=y->left;
    Node* T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=1+max(height(y->left),height(y->right));

    return x;
}

Node* leftRotate(Node* x){
    Node* y=x->right;
    Node* T2=y->left;

    y->left=x;
    x->right=T2;

    x->height=1+max(height(y->left),height(y->right));

    return y;

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

    if(balance>1){
        if(data<node->left->data)
            return rightRotate(node);
        if(data>node->left->data){
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if(balance<-1){
        if(data>node->right->data)
            return leftRotate(node);
        if(data<node->right->data){
            node->right=rightRotate(node);
            return leftRotate(node);
        }
    }
    return node;
    
}