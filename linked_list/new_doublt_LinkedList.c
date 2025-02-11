#include <stdio.h>
#include <stdlib.h>

struct dlist {
    int data;
    struct dlist *rlink, *llink; // Corrected member names
};

typedef struct dlist node;
node *root = NULL, *last = NULL;

// Function to create the doubly linked list
void creation() {
    int a;
    node *cur, *ptr;
    printf("\nEnter data for node (-999 to stop): ");
    scanf("%d", &a);

    while (a != -999) {
        cur = (node *)malloc(sizeof(node));
        cur->data = a;
        cur->rlink = NULL;
        cur->llink = NULL;

        if (root == NULL) {
            root = cur;
            last = cur;
        } else {
            last->rlink = cur;
            cur->llink = last;
            last = cur;
        }

        printf("Enter data for node (-999 to stop): ");
        scanf("%d", &a);
    }
}

// Function to insert a node into the doubly linked list
void insertion() {
    int ele;
    char ch;
    node *cur, *ptr = root;

    cur = (node *)malloc(sizeof(node));
    printf("\nEnter the data for the new node: ");
    scanf("%d", &ele);
    cur->data = ele;
    cur->rlink = NULL;
    cur->llink = NULL;

    printf("Do you want to insert at the beginning? (y/n): ");
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y') {
        cur->rlink = root;
        if (root != NULL) {
            root->llink = cur;
        }
        root = cur;
        if (last == NULL) {
            last = cur;
        }
    } else {
        printf("Enter the element after which to insert: ");
        scanf("%d", &ele);

        while (ptr != NULL) {
            if (ptr->data == ele) {
                cur->rlink = ptr->rlink;
                cur->llink = ptr;
                if (ptr->rlink != NULL) {
                    ptr->rlink->llink = cur;
                } else {
                    last = cur;
                }
                ptr->rlink = cur;
                break;
            }
            ptr = ptr->rlink;
        }
        if (ptr == NULL) {
            printf("Element not found!\n");
        }
    }
}

// Function to delete a node from the doubly linked list
void deletion() {
    int ele;
    char ch;
    node *ptr = root;

    printf("Do you want to delete the first element? (y/n): ");
    scanf(" %c", &ch);

    if (ch == 'y' || ch == 'Y') {
        if (root == NULL) {
            printf("List is empty!\n");
            return;
        }
        root = root->rlink;
        if (root != NULL) {
            root->llink = NULL;
        } else {
            last = NULL;
        }
        free(ptr);
    } else {
        printf("Enter the element to delete: ");
        scanf("%d", &ele);

        while (ptr != NULL) {
            if (ptr->data == ele) {
                if (ptr->llink != NULL) {
                    ptr->llink->rlink = ptr->rlink;
                } else {
                    root = ptr->rlink;
                }
                if (ptr->rlink != NULL) {
                    ptr->rlink->llink = ptr->llink;
                } else {
                    last = ptr->llink;
                }
                free(ptr);
                printf("Element deleted successfully.\n");
                return;
            }
            ptr = ptr->rlink;
        }
        printf("Element not found!\n");
    }
}

// Function to display the doubly linked list
void display() {
    node *ptr = root;
    printf("\nThe doubly linked list is: \nroot -> ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->rlink;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int ch;

    do {
        printf("\n1. Create List");
        printf("\n2. Insert Node");
        printf("\n3. Delete Node");
        printf("\n4. Display List");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                creation();
                break;
            case 2:
                insertion();
                break;
            case 3:
                deletion();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (ch != 5);

    return 0;
}

