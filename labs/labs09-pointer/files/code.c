#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr, i, n, new_n;

    printf("Enter the initial size of the array: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // ... (Populate the array) ...

    printf("Enter the new size of the array: ");
    scanf("%d", &new_n);

    // Reallocate memory for the new size
    int *temp = (int*) realloc(arr, new_n * sizeof(int));

    if (temp == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        // 'arr' still points to the old memory block
    } else {
        arr = temp; // Update the pointer
    }

    // ... (Work with the resized array) ...

    free(arr);

    return 0;
}