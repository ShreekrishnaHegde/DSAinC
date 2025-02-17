/*
------------------------Program to implement Binary Search Tree------------------------

*/

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
Node* search(Node* node,int key);
Node* insert(Node* node,int data);
Node* delete(Node* node,int data);

void main(){
    int data,item,ch,key;
    Node* root=NULL;
    printf("\n1.Insertion\n2.Display\n3.Search\n4.Exit");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter the element: ");
                    scanf("%d",&data);
                    root=insert(root,data);
                    break;
            case 2: printf("\nPreorder Traversal: ");
                    printPreOrder(root);
                    printf("\nInorder Traversal: ");
                    printInOrder(root);
                    printf("\nPostorder Traversal: ");
                    printPostOrder(root);
                    break;
            case 3: printf("\nEnter the element to be searched: ");
                    scanf("%d",&key);
                    search(root,key)==NULL ? printf("\nElement Found"): printf("\nElement not found");
                    break;
            case 4: printf("\nThank you!");
                    exit(0);
            default: exit(0);                    
        }
    }
    while(ch!=4);
}

//to create and initialize the node
Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
/*
-----------------------------------Algorithm for PostOrder Traversal------------------------
If root is NULL, then return
otherwise
    1. Traverse the left subtree.
    2. Traverse the right subtree.
    3. Visit the root.
*/
void printPostOrder(Node* node){
    if(node==NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf(" %d",node->data);
}
/*
-------------------------Algorithm for inorder Traversal--------------------
If root is NULL, then return
otherwise
    1. Traverse the left subtree.
    2. Visit the root.
    3. Traverse the right subtree.
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
-----------------------------Algorithm for PreOrder Traversal-----------------------------
If root is NULL, then return
otherwise
    1. Visit the root.
    2. Traverse the left subtree.
    3. Traverse the right subtree.
*/
void printPreOrder(Node* node){
    if(node==NULL)
        return;
    printf(" %d",node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}
/*
----------------------------Algorithm for Searching a node in the tree------------------------
If the tree is empty or If the key is already present in the tree, return the node
If the key to be inserted is greater than the node's key, insert it in the right subtree
If the key to be inserted is smaller than the node's key, insert it in the left subtree
*/
Node* search(Node* node,int key){
    if(node==NULL || node->data==key)
        return node;
    if(node->data<key)
        search(node->right,key);
    if(node->data>key)
        search(node->left,key);
}
/*
    ->If the tree is empty, return a new node
    ->If the key is already present in the tree,
        return the node
    ->Otherwise, recur down the tree. 
    ->If the key to be inserted is greater than the node's key,
        insert it in the right subtree
    ->If the key to be inserted is smaller than the node's key,
        insert it in the left subtree
    ->Return the (unchanged) node pointer
*/
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


