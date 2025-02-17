#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size = 0;        // Current size of the tree
int maxSize = 0;

// Structure for a binary tree node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function prototypes
Node* createNode(int data);
void printInOrder(Node* node);
void printPreOrder(Node* node);
void printPostOrder(Node* node);
Node* search(Node* node, int key);
Node* insertAt(Node* node);

void setMaxSize(int max) {
    maxSize = max;
}

int main() {
    int count, ch, key;
    Node* root = NULL;

    printf("Enter the number of Integers (nodes) in the tree: ");
    scanf("%d", &count);
    setMaxSize(count);

    printf("\nMenu:\n");
    printf("1. Insertion\n");
    printf("2. Display\n");
    printf("3. Search\n");
    printf("4. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                root = insertAt(root);
                break;
            case 2:
                printf("\nPreorder Traversal: ");
                printPreOrder(root);
                printf("\nInorder Traversal: ");
                printInOrder(root);
                printf("\nPostorder Traversal: ");
                printPostOrder(root);
                break;
            case 3:
                printf("\nEnter the element to be searched: ");
                scanf("%d", &key);
                if (search(root, key) != NULL) {
                    printf("Element Found\n");
                } else {
                    printf("Element Not Found\n");
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 4);

    return 0;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*
-------------------------Algotithm for Inorder Traversal--------------------
If root is NULL, then return
otherwise
    1. Traverse the left subtree.
    2. Visit the root.
    3. Traverse the right subtree.
*/
void printInOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}
/*
-------------------------Algorithm for Preorder Traversal--------------------
If root is NULL, then return
otherwise
    1. Visit the root.
    2. Traverse the left subtree.
    3. Traverse the right subtree.
*/
void printPreOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}
/*
--------------------------Algorithm for PostOrder Traversal------------------------
If root is NULL, then return
otherwise
    1. Traverse the left subtree.
    2. Traverse the right subtree.
    3. Visit the root.
*/
void printPostOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->data);
}

/*
----------------------------Function for Searching a node in the tree------------------------
*/
Node* search(Node* node, int key) {
    if (node == NULL || node->data == key) {
        return node;
    }
    Node* found = search(node->left, key);
    if (found != NULL) {
        return found;
    }
    return search(node->right, key);
}

/*
--------------------------------Function for inserting a node in the tree------------------------
*/
Node* insertAt(Node* node) {
    if (size >= maxSize) {
        printf("Cannot insert more nodes. Maximum size reached.\n");
        return node;
    }

    if (node == NULL) {
        int val;
        printf("Enter the value for the node: ");
        scanf("%d", &val);
        size++;
        return createNode(val);
    }

    bool isLeft, isRight;
    printf("Do you want to insert to the left of %d? (1 for yes / 0 for no): ", node->data);
    scanf("%d", &isLeft);
    if (isLeft && size < maxSize) {
        node->left = insertAt(node->left);
    }

    if (size >= maxSize) {
        return node; // Stop further insertions if the size limit is reached
    }

    printf("Do you want to insert to the right of %d? (1 for yes / 0 for no): ", node->data);
    scanf("%d", &isRight);
    if (isRight && size < maxSize) {
        node->right = insertAt(node->right);
    }

    return node;
}
