#include <stdio.h>
#include <stdlib.h>

int main() {
  char *str, *p;
  int lowercase = 0, uppercase = 0, digits = 0;

  // Allocate memory for the strring dynamically
  str = (char *)malloc(100 * sizeof(char)); // Assuming a maximum of 100 characters
  if (str == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  scanf(" %[^\n]s", str); // Read the strring with spaces

  // Initialize the pointer to traverse the strring
  p = str;

  while (*p != '\0') {
    if (*p >= 'a' && *p <= 'z') {
      lowercase++;
    } else if (*p >= 'A' && *p <= 'Z') {
      uppercase++;
    } else if (*p >= '0' && *p <= '9') {
      digits++;
    }
    p++; // Move the pointer to the next character
  }

  printf("Lowercase letters: %d\n", lowercase);
  printf("Uppercase letters: %d\n", uppercase);
  printf("Digits: %d\n", digits);

  free(str); // Free the allocated memory

  return 0;
}