#include <stdio.h>

void binary_search(int a[10], int low, int high) {
    int mid, key;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &key);
    while(low <= high) {
        mid = (low + high) / 2;
        if(a[mid] == key) {
            printf("Element found at index %d\n", mid+1);
            return;
        }
        else if(a[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    if(low > high) {
        printf("Element not found\n");
    }
}

int main() {
    int i,n;
    int a[5] = {10,20,30,40,50};

    n=5;
    printf("\nGiven Array Elements");

    for(i=0;i<n;i++) {
        printf(" %d", a[i]);
    }

    binary_search(a,0,n-1);
    return 0;
}