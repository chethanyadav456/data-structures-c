#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};
typedef struct list node;
node *front = NULL, *rear;

void insertion() {
    int ele;
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\n enter data for the new node: ");
    scanf("%d", &ele);
    newnode->data = ele;
    newnode-> next=NULL;
    if(front==NULL) {
        front = newnode;
        rear=front;
    } else {
        rear->next=newnode;
        rear=newnode;
    }
} 

void deletion() {
    node *temp;
    if(front==NULL) {
        printf("\nQueue is empty(UNDERFLOW)");
    } else {
        temp=front;
        front=front->next;
        printf("\ndeleted element=%d\n", temp->data);
        free(temp);
    }
}

void display() {
    node *ptr;
    if(front==NULL) {
        printf("\n The Queue is empty\n");
    } else {
        printf("\nelements in queue are:\n");
        for(ptr=front;ptr!=NULL;ptr=ptr->next) {
            printf("\n\t%d", ptr->data);
        }
    }
}

int main() {
    int ch;
    printf("1. Insertion\n");
    printf("2. deletion\n");
    printf("3. display\n");
    printf("4. exit\n");
    do {
        printf("\n enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        } 
    } while(ch<=4);
    return 0;
}