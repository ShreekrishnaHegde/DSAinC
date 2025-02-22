#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data,height;
    struct Node *left,*right;
}Node;
Node* create(int data);
int height(Node* node);
int max(int a,int b);

int getBalance(Node* node);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
Node* insert(Node* node,int data);
void printInorder(Node* root);



void main(){

    Node* root=NULL;
    int ch,data;
    int arr[]={10,20,30,40,50,25};
    for(int i=0;i<3;i++)
        root=insert(root,arr[i]);
    printInorder(root);
    
    
}
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
    else if(data>node->data)
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

void printInorder(Node* root){
    if(root==NULL)
        return;
    printInorder(root->left);
    printf("%d ",root->data);
    printInorder(root->right);
}
