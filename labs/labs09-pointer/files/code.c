#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str;

    // Allocate memory for the string "Porsche Arnold" (including null terminator)
    str = (char*) malloc(15 * sizeof(char));

    // Copy "Porsche Arnold" into the allocated memory
    strcpy(str, "Porsche Arnold");

    // Print the string
    char *ptr = str;
    while (*ptr)
        printf("%c", *ptr++);
    // printf("%s", str);

    // Free the allocated memory
    free(str);

    printf("\n");
    return 0;
}