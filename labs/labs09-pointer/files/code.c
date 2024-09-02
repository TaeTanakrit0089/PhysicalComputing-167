#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int size = 0;
    int capacity = 10; // Initial capacity
    int num;

    // Allocate initial memory
    arr = (int*)malloc(capacity * sizeof(int));

    printf("Enter integers (-1 to stop): ");
    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;

        // Resize array if needed
        if (size == capacity) {
            capacity *= 2; // Double the capacity
            int *temp = (int*)realloc(arr, capacity * sizeof(int));
            arr = temp;
        }
        arr[size++] = num; // Add element to the array
    }

    printf("You entered: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}