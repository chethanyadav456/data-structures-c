#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node *left;
    struct node *right;
};

//In-Order Traversal method
void inOrderTraversal(struct node *root) {
    if(root==NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->item);
    inOrderTraversal(root->right);
}

//Pre-Order Traversal method
void preOrderTraversal(struct node *root) {
    if(root == NULL) return;
    printf("%d ", root->item);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//Post-Order Traversal method
void postOrderTraversal(struct node *root) {
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->item);
}

//Create a new NODE
struct node *create(int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

// Insert on the left of the node
struct node *insertLeft(struct node *root, int value) {
    root->left = create(value);
    return root->left;
}

//Insert on the right of the node
struct node *insertRight(struct node *root, int value) {
    root->right = create(value);
    return root->right;
}

// Main fucntion
int main() {
    struct node *root = create(1);
    insertLeft(root,4);
    insertRight(root, 6);
    insertLeft(root->left, 42);
    insertRight(root->left, 3);
    insertLeft(root->right, 2);
    insertRight(root->right, 33);
    
    printf("Traversal of the inserted binary tree\n");
    printf("InOrder Traversal\n");
    inOrderTraversal(root);
    
    printf("\npreOrder Traversal\n");
    preOrderTraversal(root);
    
    printf("\nPostOrder Traversal\n");
    postOrderTraversal(root);
    
    return 0;
}