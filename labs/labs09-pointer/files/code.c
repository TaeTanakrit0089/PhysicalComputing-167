#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    int *arr;

    printf("Enter the desired size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    arr = (int*) malloc(size * sizeof(int));

    // Populate the array
    for (i = 0; i < size; i++)
        arr[i] = i + 1;

    // Print the array in reverse using pointers
    printf("Array elements in reverse: ");
    int *ptr = arr + size - 1;  // Point to the last element of the array
    for (i = 0; i < size; i++) {
        printf("%d ", *ptr);
        ptr--;  // Move the pointer to the previous element
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}
