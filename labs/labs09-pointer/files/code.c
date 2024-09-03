#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort (ascending order)
int compare(const void *a, const void *b);

int main() {
    int *arr = NULL;
    int size = 0;
    int capacity = 10; // Initial capacity
    int num;

    // Allocate initial memory
    arr = (int*)malloc(capacity * sizeof(int));

    while (1) {
        scanf(" %d", &num);
        if (num == -1)
            break;

        // Resize array if needed
        if (size >= capacity) {
            capacity *= 2; // Double the capacity
            int *temp = (int*) realloc(arr, capacity * sizeof(int));
            arr = temp;
        }

        // Add element to the array
        *(arr + size++) = num;
    }

    printf("You entered: ");

    int *ptr = arr;
    while (ptr < (arr+size))
        printf("%d ", *ptr++);
    printf("\n");

    // Sort the array using qsort
    qsort(arr, size, sizeof(int), compare);

    // Print to sorted array
    ptr = arr;
    printf("Sorted array: ");
    while (ptr < (arr+size))
        printf("%d ", *ptr++);
    printf("\n");

    free(arr);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}