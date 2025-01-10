#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *link;
};

typedef struct list node;
node *top = NULL;

void push() {
    node *temp;
    int x;
    printf("\nEnter the data to be pushed into the stack: ");
    scanf("%d", &x);
    temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->link=top;
    top=temp;

}

void pop() {
    node *temp;
    int x;
    if(top==NULL) {
        printf("\nThe stack is empty\n");
    } else {
        temp = top;
        top = top->link;
        x=temp->data;
        free(temp);
        printf("\nDeleted the element %d\n", x);
    }
}

void display() {
    node *temp;
    if(top==NULL) {
        printf("\nThe stack is empty\n");
    } else {
        printf("\nThe stack contents are\n");
        temp=top;
            while(temp!= NULL) {
                printf("\t%d\n", temp->data);
                temp = temp->link;
            }
    }
}

int main() {
    int ch;
    printf("\n\t1. push\n");
    printf("\t2. pop\n");
    printf("\t3. display\n");
    printf("\t4. exit\n");
    do {
        printf("\nenter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            }
        } while (ch<=4);
}