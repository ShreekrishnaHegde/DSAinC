#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

Node* create(int data);
Node*  insert(Node* node,int data);
void printInOrder(Node* node);
Node* search(Node* node,int key);

void main(){
    Node* root=create(50);
    // int tree[]={30,20,40,70,60,80};
    // int n=sizeof(tree)/sizeof(int);
    // for(int i=0;i<n;i++){
    //     root=insert(root,tree[i]);
    // }
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,60);
    root=insert(root,80);
    
    printf("\nInorder Traversal of BST: ");
    printInOrder(root);

    search(root,100)!=NULL ? printf("\nFound") :printf("\nNot Found");

}

Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
//Inserting an item in BTS
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
//Printing with InOrder Traversal Algorithm
void printInOrder(Node* node){
    if(node==NULL)
        return;
    printInOrder(node->left);
    printf(" %d",node->data);
    printInOrder(node->right);
}
/*
--------------------------------Function to search an element in the BST--------------------------------------
->We compare the value to be searched with the value of the root. 
->If it’s equal we are done with the search 
->if it’s smaller we know that we need to go to the left subtree 
    because in a binary search tree all the elements in the left subtree are smaller and all the elements in the right subtree are larger. 
->If its is larger, we need to go to the right subtree
->Repeat the above step till no more traversal is possible
->If at any iteration, key is found, return True. Else False.
*/
Node* search(Node* node,int key){
    if(node==NULL || node->data==key)
        return node;
    if(key > node->data)
        return search(node->right,key);
    else    
        return search(node->left,key);
}