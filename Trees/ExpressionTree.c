/*
C program to illustrate the evaluation of an expression tree
*/

#include <stdio.h>

typedef struct Node{
    char info;
    struct Node *left,*right;
} Node;

int eval(Node* root) 
{ 
    // empty tree 
    if (!root) 
        return 0; 
 
    // leaf node i.e, an integer 
    if (!root->left && !root->right) 
        return toInt(root->info); 
 
    // Evaluate left subtree 
    int l_val = eval(root->left); 
 
    // Evaluate right subtree 
    int r_val = eval(root->right); 
 
    // Check which operator to apply 
    if (root->info=="+") 
        return l_val+r_val; 
 
    if (root->info=="-") 
        return l_val-r_val; 
 
    if (root->info=="*") 
        return l_val*r_val; 
 
    return l_val/r_val; 
} 