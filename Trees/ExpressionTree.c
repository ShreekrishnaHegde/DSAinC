/*
Program to create an expression tree from a postfix expression and evaluate the expression tree
*/

#include <stdio.h>

typedef struct Node{
    char data;
    struct Node *left, *right;
} Node;

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

