#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    char *str, *ptr;

    // Get the string length (n) and interval (m) from the user
    scanf("%d", &n);
    scanf("%d", &m);

    // Allocate memory for the string dynamically
    str = (char *)malloc((n + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get the string from the user
    scanf(" %[^\n]s", str);

    // Print every m-th character
    ptr = str; // Initialize a pointer to the beginning of the string
    for (i = 0; i < (n/m); i++) {
//        if (*ptr == '\0') continue;
        printf("%c", *ptr);
        ptr += m; // Move the pointer to the next character
    }

    printf("\n");
    // Free the allocated memory
    free(str);

    return 0;
}