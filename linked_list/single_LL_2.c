#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

void insert();
void delete();
void create();
void display();

int main() {
    int choice;
    while(1) {
        printf("\n1. Create\n2. Insert\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create();
                    break;
            case 2: insert();
                    break;
            case 3: delete();
                    break;
            case 4: display();
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

struct node *head = NULL;

void create() {
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if(head == NULL) {
        head = new_node;
    } else {
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert() {
    struct node *new_node, *temp;
    int loc, i;
    new_node = (struct node *)malloc(sizeof(struct node));
    if(new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    printf("Enter the location: ");
    scanf("%d", &loc);
    if(loc == 0) {
        new_node->next = head;
        head = new_node;
    } else {
        temp = head;
        for(i = 0; i < loc - 1; i++) {
            if(temp == NULL) {
                printf("Invalid location\n");
                return;
            }
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete() {
    struct node *temp, *ptr;
    int loc, i;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the location: ");
    scanf("%d", &loc);
    if(loc == 0) {
        temp = head;
        head = head->next;
        free(temp);
    } else {
        temp = head;
        for(i = 0; i < loc - 1; i++) {
            if(temp == NULL) {
                printf("Invalid location\n");
                return;
            }
            temp = temp->next;
        }
        if(temp->next == NULL) {
            printf("Invalid location\n");
            return;
        }
        ptr = temp->next;
        temp->next = ptr->next;
        free(ptr);
    }
}

void display() {
    struct node *temp;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

