#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Node*  insert(Node* node,int data){
    if(node==NULL)
        return create(data);
    if(node->data==data)
        return node;
    if(data<node->data)
        node->left=insert(node->left,data);
    else
        node->right=insert(node->right,data);
    return node;
}
void printInOrder(Node* node){
    if(node==NULL)
        return;
    printInOrder(node->left);
    printf(" %d",node->data);
    printInOrder(node->right);
}
void main(){
    Node* root=create(50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,60);
    root=insert(root,80);
    printf("\nInorder Traversal of BST: ");
    printInOrder(root);

}