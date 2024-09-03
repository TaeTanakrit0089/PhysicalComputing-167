# Homeworks

## HW 09.01 - Traversing Through String with Pointer

This tutorial explains a C program that takes a string of length `<n>` and an integer `<m>` as input and prints every
`<m>`-th character of the string.

### Code Explanation

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    char *str, *ptr;

    // Get the string length (n) and interval (m) from the user
    printf("Enter the length of the string (n): ");
    scanf("%d", &n);
    printf("Enter the value of m: ");
    scanf("%d", &m);

    // Allocate memory for the string dynamically
    str = (char *)malloc((n + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Get the string from the user
    printf("Enter the string: ");
    scanf(" %[^\n]s", str);

    // Print every m-th character
    ptr = str; // Initialize a pointer to the beginning of the string
    printf("Characters at every %d positions:\n", m);
    for (i = 0; i < (n/m); i++) {
        printf("%c", *ptr);
        ptr += m; // Move the pointer to the next character
    }

    printf("\n");
    // Free the allocated memory
    free(str);

    return 0;
}
```

### Step-by-Step Breakdown

1. **Include Header Files:**
    - `stdio.h`: Provides standard input/output functions like `printf` and `scanf`.
    - `stdlib.h`: Provides memory allocation functions like `malloc` and `free`.

2. **Declare Variables:**
    - `n`: Stores the length of the string.
    - `m`: Stores the interval for printing characters.
    - `i`: Loop counter variable.
    - `str`: Character pointer to store the string.
    - `ptr`:  Character pointer used for traversing the string.

3. **Get Input from the User:**
    - The program prompts the user to enter the length of the string (`n`) and the interval (`m`).

4. **Dynamic Memory Allocation:**
    - Memory is allocated dynamically for the string using `malloc`.
    - The size allocated is `(n + 1)` to accommodate the string characters and the null terminator (`\0`).
    - The `if` statement checks if memory allocation was successful. If not, an error message is printed, and the
      program exits.

5. **Get String Input:**
    - The program prompts the user to enter the string.
    - `scanf(" %[^\n]s", str);` reads the entire string, including spaces, until a newline character is encountered. The
      leading space in the format specifier consumes any leading whitespace.

6. **Print Every M-th Character:**
    - `ptr` is initialized to point to the beginning of the string (`str`).
    - A `for` loop iterates from 0 to `(n/m)`, ensuring that characters within the string length are accessed.
        - Inside the loop:
            - `printf("%c", *ptr);` prints the character pointed to by `ptr`.
            - `ptr += m;` moves the pointer `m` positions ahead, effectively skipping over characters.

7. **Free Allocated Memory:**
    - `free(str);` deallocates the memory previously allocated for the string, preventing memory leaks.

8. **Return 0:**
    - Indicates successful program execution.

### Example

Let's assume the user inputs the string "HelloWorld" (`n = 10`) and the interval `m = 3`. The program will print the
characters at positions 0, 3, 6, and 9:

```
Hlod
```

This tutorial explained a C program that efficiently extracts and prints every `<m>`-th character of a string,
demonstrating dynamic memory allocation and string manipulation in C.

---

## HW 09.02 - Reversing String using Pointer

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
---

## HW 09.03 - Character Counter

### โจทย์ (Problem Statement)

จงเขียนโปรแกรมรับข้อความ แล้วนับจำนวนตัวอักษรพิมพ์เล็ก พิมพ์ใหญ่ และตัวเลขในข้อความ (Write a program that takes a
string as input and counts the number of lowercase letters, uppercase letters, and digits in the string).

**ข้อห้าม:** ห้ามใช้ Array โดยเด็ดขาด (Do not use arrays).

### Solution and Explanation

```c
#include <stdio.h>

int main() {
  char *str, *p;
  int lowercase = 0, uppercase = 0, digits = 0;

  // Allocate memory for the string dynamically
  str = (char *)malloc(100 * sizeof(char)); // Assuming a maximum of 100 characters
  if (str == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  printf("Enter a string: ");
  scanf(" %[^\n]s", str); // Read the string with spaces

  // Initialize the pointer to traverse the string
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
```

---

## HW 09.04 - String Collector

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
