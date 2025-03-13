#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new BST node
struct Node *newNode(int item) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to preform inorder Traversal of BST
void inOrder(struct Node *root) {
    if(root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Function to insert a new key into BST
struct Node *insert(struct Node *node, int key) {
    if(node == NULL) return newNode(key);
    
    //Ortherwise, recur doen the tree
    if(key < node->key) 
        node->left = insert(node->left, key);
    else if (key > node->key) 
        node->right = insert(node->right, key);
    
    return node;
}

int main() {
    //Creating the BST
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    //print the BST inOrder Traversal
    printf("InOrder Traversal of BST\n");
    inOrder(root);
    printf("\n");
    
    return 0;
}