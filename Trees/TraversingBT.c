#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

Node* create(int data);
void printInOrder(Node* node);
void printPreOrder(Node* node);
void printPostOrder(Node* node);

void main(){

    Node* root=create(1);
    root->left=create(2);
    root->right=create(3);
    root->left->left=create(4);
    root->left->right=create(5);
    root->right->right=create(6);

    printf("\nInorder Traversal: ");
    printInOrder(root);
    printf("\nPreOrder Traversal: ");
    printPreOrder(root);
}

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
/*
-------------------------Algorithm for inorder Traversal--------------------
Inorder(root):
If root is NULL, then return
Inorder (root -> left)
Process root (For example, print root’s data)
Inorder (root -> right)
*/
void printInOrder(Node* node){
    //Base Condition
    if(node==NULL)
        return;
    //Print Left Sub tree
    printInOrder(node->left);
    //Print Node
    printf("%d ",node->data);
    //Print Right Sub tree
    printInOrder(node->right);
}
/*
-----------------------------algorithm for PreOrder Traversal-----------------------------
If root is NULL then return
Process root (For example, print root’s data)
Preorder (root -> left)
Preorder (root -> right)
*/
void printPreOrder(Node* node){
    if(node==NULL)
        return;
    printf(" %d",node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}
/*
-----------------------------------Algorithm for PostOrder Traversal------------------------
Traverse left subtree
Traverse the right subtree
Visit the root and print the data.
*/
void printPostOrder(Node* node){
    if(node==NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf(" %d",node->data);
}