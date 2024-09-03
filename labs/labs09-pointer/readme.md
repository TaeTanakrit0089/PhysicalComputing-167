# Lab09 Pointer

## Lecture Slide

- [lecture_slide.md](files/lecture_slide.md)
- [PC-Chapter 7 - Lecture Note.pdf](files/PC-Chapter%207%20-%20Lecture%20Note.pdf)

## Pointers

A pointer is a special type of variable that, instead of holding a value directly, **stores the memory address of
another variable**. Think of it like a street address that tells you where a house is located, but not what's inside the
house itself.

### Declaring Pointers:

Pointers are declared using an asterisk (*) before the variable name. The type of the pointer should match the type of
the data it points to.

```c
int *ptr;    // Declares a pointer named 'ptr' that can store the address of an integer variable.
char *name;  // Declares a pointer named 'name' that can store the address of a character variable.
float *price; // Declares a pointer named 'price' that can store the address of a float variable.
```

### Initializing Pointers:

- **Using the address-of operator (&):** The `&` operator gives you the memory address of a variable.

  ```c
  int num = 10;
  int *ptr = &num; // 'ptr' now holds the memory address of 'num'
  ```

- **Setting to NULL:** You can initialize a pointer to `NULL`, which signifies that it doesn't point to any valid memory
  location.

  ```c
  int *ptr = NULL;
  ```

### Accessing Data through Pointers (Dereferencing):

To access the value stored at the memory address held by a pointer, we use the **dereference operator (*)**.

```c
int num = 10;
int *ptr = &num;

printf("Value of num: %d\n", num);       // Output: 10
printf("Value pointed to by ptr: %d\n", *ptr); // Output: 10
```

### Pointer Arithmetic:

C allows basic arithmetic operations on pointers (addition, subtraction, increment, decrement). The behavior of these
operations is tied to the data type the pointer points to.

```c
int arr[] = {10, 20, 30, 40, 50};
int *ptr = arr; // Points to the first element of the array

printf("Value at ptr: %d\n", *ptr); // Output: 10
ptr++; // Move to the next element (address incremented by sizeof(int))
printf("Value at ptr: %d\n", *ptr); // Output: 20
```

### Example: Swapping Two Numbers Using Pointers:

```c
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int x = 10, y = 20;

  printf("Before swap: x = %d, y = %d\n", x, y);

  swap(&x, &y); // Pass addresses of x and y

  printf("After swap: x = %d, y = %d\n", x, y);

  return 0;
}
```

In this example, the `swap` function takes pointers to two integers. It modifies the values at the memory locations
pointed to by these pointers, effectively swapping the contents of the variables `x` and `y`.

### Key Takeaways:

- Pointers store memory addresses of other variables.
- They allow you to directly manipulate data in memory.
- Understanding how to declare, initialize, dereference, and perform arithmetic on pointers is essential in C.
- Pointers are heavily used in dynamic memory allocation, working with arrays and strings, and interfacing with
  hardware.

Practice working with pointers, and you'll gain a deeper understanding of how C interacts with memory, leading to more
efficient and powerful programs.

## Dynamic Memory Allocation in C: Mastering `malloc` and `realloc`

- [malloc.md](malloc.md)

## Dynamic Memory Allocation in C: Mastering `malloc` and `realloc`

- [malloc.md](malloc.md)

## Pointer Examples

1. **Reversing String**

   ```c
   #include <stdio.h>
   #include <string.h>
   void reverseString(char *str);
   
   int main() {
       char str[] = "hello";
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
   
   ```

   **Explanation:**

    1. **Pointers:**
        - `start`: Points to the first character of the string.
        - `end`: Points to the last character (excluding the null terminator `\0`).

    2. **Iteration:**
        - The `while` loop continues as long as the `start` pointer is located before the `end` pointer.

    3. **Swapping:**
        - Inside the loop, we swap the characters pointed to by `start` and `end` using a temporary variable `temp`.

    4. **Pointer Movement:**
        - After each swap, we increment `start` to move towards the right and decrement `end` to move towards the left.

---

2. **Dynamic Memory Allocation for Arrays**

    ```c
    #include <stdio.h>
    #include <stdlib.h> // For malloc(), free()
    
    int main() {
        int *arr;
        int size, i;
    
        printf("Enter the size of the array: ");
        scanf("%d", &size);
    
        // Dynamically allocate memory
        arr = (int*)malloc(size * sizeof(int)); 
    
        if (arr == NULL) { // Check for allocation failure
            printf("Memory allocation failed!\n");
            return 1;
        }
    
        printf("Enter %d elements:\n", size);
        for (i = 0; i < size; i++) {
            scanf("%d", &arr[i]); // Access elements using pointer arithmetic
        }
    
        printf("Array elements: ");
        for (i = 0; i < size; i++) {
            printf("%d ", *(arr + i)); // Another way to access elements
        }
        printf("\n");
    
        free(arr); // Release the allocated memory
        return 0;
    }
    ```

   **Key Concepts:**

    - `malloc(size * sizeof(type))`: Allocates a block of memory of the specified `size` (in bytes) and returns a
      pointer to the beginning of that block. It's crucial to multiply by `sizeof(type)` to allocate enough space for
      elements of the desired data type.
    - `free(ptr)`: Deallocates the memory previously allocated by `malloc()`, preventing memory leaks.

