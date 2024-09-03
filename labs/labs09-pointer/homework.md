# Homeworks

## HW 09.01 - Reversing String using Pointer

### โจทย์ (Problem Statement)

จงเขียนโปรแกรมรับข้อความ แล้วให้สลับตัวอักษรในข้อความจากหลังไปหน้า (Write a program that takes a string as input and
reverses it without using an array).

**ข้อห้าม:** ห้ามใช้ Array โดยเด็ดขาด (Do not use arrays).

### Solution and Explanation

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str = NULL; // Start with a null pointer for safety
    int size = 100;    // Initial size for the string (can be adjusted)

    // Dynamically allocate memory for the string
    str = (char*) malloc(size * sizeof(char)); 
    // Handle potential allocation failure
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }

    // Read the string from the user
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    // Pointer to traverse the string
    char *i = str; 

    // Move the pointer 'i' to the end of the string
    while (*i != '\0') { 
        i++; 
    }

    // Print the string in reverse
    printf("Reversed string: ");
    // Decrement 'i' before accessing the character to start from the last character
    while (i > str) {
        printf("%c", *--i); 
    }

    printf("\n");

    // Free the dynamically allocated memory
    free(str); 

    return 0;
}
```

### Explanation:

1. **Include Headers:**
    - `stdio.h`: Provides standard input/output functions like `printf` and `scanf`.
    - `stdlib.h`: Provides memory allocation functions like `malloc` and `free`.

2. **Dynamic Memory Allocation:**
    - `char *str = NULL;`: Declares a character pointer `str` and initializes it to `NULL`.
    - `str = (char*) malloc(size * sizeof(char));`: Dynamically allocates memory to store the string.
        - `malloc(size * sizeof(char))`: Allocates a block of memory large enough to hold `size` characters.
          `sizeof(char)` ensures the correct size for each character.
        - `(char*)`: Casts the returned void pointer from `malloc` to a character pointer.

3. **Reading the String:**
    - `scanf("%[^\n]s", str);`: Reads the input string from the user until a newline character (`\n`) is encountered.
      This format specifier allows reading strings with spaces.

4. **Traversing and Reversing:**
    - `char *i = str;`: Declares a character pointer `i` and initializes it with the address stored in `str` (start of
      the string).
    - **Finding the End:** The first `while` loop iterates until `*i` (the character pointed to by `i`) becomes `\0` (
      null terminator), marking the end of the string.
    - **Printing in Reverse:** The second `while` loop starts from the end of the string (`i` points to the null
      terminator initially).
        - `*--i`:  Decrements the pointer `i` first (moving it one position back) and then accesses the character at
          that location.
        - `printf("%c", *--i);`: Prints the character pointed to by `i`.

5. **Freeing Memory:**
    - `free(str);`:  Deallocates the memory dynamically allocated for `str`, preventing memory leaks.

### Example:

```
Enter a string: Hello World!
Reversed string: !dlroW olleH
```

This program demonstrates how to reverse a string using pointers without relying on arrays, highlighting key concepts of
dynamic memory allocation and pointer manipulation in C.

## HW 09.03 - String Collector

This tutorial demonstrates how to construct a string in C by continuously reading characters from the input until a '-'
character is encountered. We'll achieve this without using arrays, relying solely on pointers for memory management.

**Code:**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  char c, *str, *temp;
  int len = 0;

  // Allocate initial memory for a single character string
  str = (char *)malloc(sizeof(char));
  if (str == NULL) {
    printf("Memory allocation failed!\n");
    return 1; 
  }
  *str = '\0'; // Initialize as an empty string

  printf("Enter characters (enter '-' to stop): ");

  do {
    scanf(" %c", &c); // Read a character

    if (c != '-') {
      len++; // Increase string length

      // Reallocate memory for the larger string
      temp = (char *)realloc(str, (len + 1) * sizeof(char));

      // Handle reallocation failure
      if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        free(str);
        return 1;
      }

      str = temp; // Update the string pointer

      // Append the new character
      *(str + len - 1) = c; 
      *(str + len) = '\0'; // Add null terminator
    }

  } while (c != '-'); 

  printf("Final string: %s\n", str);

  // Free the allocated memory
  free(str);

  return 0;
}
```

**Explanation:**

1. **Initialization:**
    - We declare a character variable `c` to store the input character.
    - Two character pointers `str` and `temp` are declared:
        - `str`: Points to the dynamically allocated memory where the string is built.
        - `temp`: Used temporarily during reallocation.
    - `len` variable tracks the current length of the string.

2. **Memory Allocation:**
    - We start by allocating memory for a single character using `malloc(sizeof(char))`. This memory will hold the first
      character and the null terminator.
    - `str` is assigned the address of this allocated memory.

3. **Character Input and Processing:**
    - The program enters a `do...while` loop that continues until the user enters the '-' character.
    - Inside the loop:
        - `scanf(" %c", &c)` reads a character from the input. The leading space in the format string consumes any
          leading whitespace characters like newline from the previous input.
        - If the character is not '-':
            - `len` is incremented to reflect the increased string length.
            - `realloc()` is called to resize the memory block pointed to by `str`. It attempts to expand the memory to
              accommodate `(len + 1)` characters (including the null terminator).
            - If `realloc()` fails to allocate contiguous memory, it returns `NULL`. We check for this condition and
              handle it gracefully by freeing the existing memory and exiting.
            - The new character is added to the string at the correct position using pointer arithmetic (
              `*(str + len - 1) = c`).
            - The null terminator is added at the end of the string (`*(str + len) = '\0'`).

4. **Output and Cleanup:**
    - After exiting the loop, the program prints the constructed string using `printf()`.
    - Finally, `free(str)` is called to release the dynamically allocated memory back to the heap, preventing memory
      leaks.

**Key Points:**

- **Dynamic Memory Allocation:** Using `malloc()` and `realloc()` allows us to create a string whose size is determined
  at runtime based on user input.
- **Pointers:** Pointers provide flexibility in manipulating memory. By using `str` and `temp`, we can easily manage the
  dynamically allocated memory block.
- **Null Termination:** Remember that C strings are null-terminated, so we add `\0` after the last character.
- **Error Handling:** Checking the return values of `malloc()` and `realloc()` is crucial for writing robust code.
- **Memory Leaks:**  Always `free()` the dynamically allocated memory after you are done using it.

This tutorial provides a fundamental understanding of building strings dynamically using pointers in C. You can adapt
this approach for various string manipulation tasks.
