#include <stdio.h>
#include <string.h>
void reverseString(char *str);

int main() {
    char str[60];
    scanf("%[^\n]s", str);
    reverseString(str);
    printf("Reversed string: %s\n", str); // Output: olleh
    return 0;
}

void reverseString(char *str) {
    char *start = str;          // Pointer to the beginning
    char *end = str + strlen(str) - 1; // Pointer to the end (excluding null terminator)
    char temp;

    while (start < end) {       // Loop until pointers cross or meet
        temp = *start;          // Swap characters
        *start = *end;
        *end = temp;

        start++;              // Move pointers towards each other
        end--;
    }
}