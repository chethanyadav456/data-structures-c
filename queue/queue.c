#include <stdlib.h>
#include <stdio.h>

void push(int value);
void pop();
void display();

#define SIZE 10

int queue[SIZE];

int front = -1;

int rear = -1;

void push(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

void pop() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Popped element is %d\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// Output
// 1. Push
// 2. Pop
// 3. Display
// 4. Exit
// Enter your choice: 1
// Enter the value to be pushed: 10