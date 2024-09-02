#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = NULL; // Start with a null pointer
    int size, i = 0;

    printf("Enter the initial size of the string: ");
    scanf("%d", &size);

    // Allocate memory dynamically using malloc
    str = (char*) malloc(size * sizeof(char));

    printf("Enter the string: ");
    // Consume the newline left in the buffer from previous scanf
    getchar();

    // Read characters one by one until newline is encountered
    while ((str[i++] = getchar()) != '\n') {
        if (i == size) {
            // Reallocate memory if needed
            size *= 2;
            str = (char*) realloc(str, size * sizeof(char));
            if (str == NULL) {
                printf("Memory reallocation failed!\n");
                return 1;
            }
        }
    }

    // Null-terminate the string
    str[i - 1] = '\0';

    printf("You entered: %s\n", str);

    // Free the dynamically allocated memory
    free(str);
    return 0;
}