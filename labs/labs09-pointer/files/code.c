#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenateStrings(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t totalLen = len1 + len2 + 1; // +1 for null terminator

    char* result = (char*)malloc(totalLen * sizeof(char));
    if (result == NULL) {
        return NULL; // Handle allocation failure
    }

    strcpy(result, str1);  // Copy first string
    strcat(result, str2);  // Concatenate second string

    return result;
}

int main() {
    char str1[] = "Hello, ";
    char str2[] = "world!";
    char *combinedStr = concatenateStrings(str1, str2);

    if (combinedStr != NULL) {
        printf("Concatenated string: %s\n", combinedStr);
        free(combinedStr);
    }

    return 0;
}