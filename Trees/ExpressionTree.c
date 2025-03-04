/*
Program to create an expression tree from a postfix expression and evaluate the expression tree
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    char data;
    struct Node *left, *right;
}Node;

Node* createNode(char data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

int evalutate(Node* root){
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return root->data - '0';
    int leftSubTree=evalutate(root->left);
    int rightSubTree=evalutate(root->right);

    if(root->data=='+')
        return leftSubTree+rightSubTree;
    else if(root->data=='-')
        return leftSubTree-rightSubTree;
    else if(root->data=='*')
        return leftSubTree*rightSubTree;
    else if(root->data=='/')
        return leftSubTree/rightSubTree;
    else if(root->data=='^')
        return leftSubTree^rightSubTree;
    return -1;
}

int main(){

    Node* root=createNode('/');
    root->left=createNode('+');
    root->right=createNode('*');
    root->left->left=createNode('9');
    root->left->right=createNode('5');
    root->right->left=createNode('2');
    root->right->right=createNode('7');
    printf("Result: %d\n",evalutate(root));
    return 0;
}
