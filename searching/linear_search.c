#include <stdio.h>

void linear_search(int a[10], int n, int key) {
    int i;
    for(i = 0; i < n; i++) {
        if(a[i] == key) {
            printf("Element found at index %d\n", i+1);
            return;
        }
    }
    if(i == n) {
        printf("Element not found\n");
    }
}

int main() {
    int i,n,key;
    int a[5] = {10,20,30,40,50};

    n=5;
    printf("\nGiven Array Elements");

    for(i=0;i<n;i++) {
        printf(" %d", a[i]);
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);
    linear_search(a,n,key);
    return 0;
}