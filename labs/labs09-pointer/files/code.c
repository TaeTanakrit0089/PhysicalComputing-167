#include <stdio.h>
#include <stdlib.h>

int main() {
  char c, *str, *temp;
  int len = 0;

  str = (char *)malloc(sizeof(char));

  do {
    scanf(" %c", &c);

    if (c != '-') {
      len++;

      temp = (char *)realloc(str, (len + 1) * sizeof(char));

      str = temp;

      // Added charactor into string
      *(str + len - 1) = c;
      *(str + len) = '\0';
    }

  } while (c != '-');

  printf("%s\n", str);

  // Free up the memory
  free(str);

  return 0;
}