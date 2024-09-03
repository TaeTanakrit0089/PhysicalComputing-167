## Dynamic Memory Allocation in C: Mastering `malloc` and `realloc`

This document serves as a comprehensive guide to understanding and using `malloc` and `realloc`, two powerful functions
in C that allow dynamic memory allocation. We will delve into their syntax, functionality, common use cases, and
potential pitfalls.

### Introduction

In C, variables typically have a fixed size determined at compile time. This works well for many scenarios but falls
short when dealing with data structures whose size changes during program execution. Imagine creating a program to store
student names, where the number of students is unknown beforehand. This is where **dynamic memory allocation** comes to
the rescue.

Dynamic memory allocation allows programs to request memory from the operating system at runtime. This means you can
create data structures that grow or shrink dynamically based on the program's needs. C provides two primary functions
for this purpose: `malloc` and `realloc`.

### 1. `malloc`: Allocating Memory Blocks

The `malloc` function allocates a block of memory of a specified size and returns a pointer to the beginning of that
block.

**Syntax:**

```c
void* malloc(size_t size);
```

* **`void*`:** The function returns a `void` pointer, meaning it can point to any data type. You will need to explicitly
  typecast this pointer to the desired data type.
* **`size_t size`:** This argument specifies the size of the memory block to be allocated, in bytes.

**How to use `malloc`:**

1. **Include the `<stdlib.h>` header file:**
   ```c
   #include <stdlib.h> 
   ```
2. **Call `malloc` with the desired size:**
   ```c
   int *ptr = (int*) malloc(10 * sizeof(int));
   ```
   This code snippet allocates enough memory to store an array of 10 integers and assigns the starting address of the
   allocated block to the pointer `ptr`.
3. **Check for allocation success:**
   `malloc` returns a NULL pointer if memory allocation fails (e.g., insufficient memory). Always check the returned
   pointer before using it:
   ```c
   if (ptr == NULL) {
       // Handle memory allocation failure
       fprintf(stderr, "Memory allocation failed!\n");
       exit(1); 
   }
   ```
4. **Access and use the allocated memory:**
   You can now use the pointer to access and modify the allocated memory:
   ```c
   for (int i = 0; i < 10; i++) {
       *(ptr+i) = i * i;        // Assign values using pointer
       ptr[i] = i * i;          // Assign values using array
   }
   
   for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr+i));    // Access values using pointer
        printf("%d ", ptr[i]);      // Access values using array
   }
   ```
    1. **`*(ptr + i)`: Pointer Arithmetic and Dereferencing**

        - **`ptr + i`**:  This part performs pointer arithmetic. It calculates the memory address of the `i`-th element
          relative to the starting address stored in `ptr`. The calculation considers the data type `ptr` points to (in
          this
          case, `int`), so the address is incremented by `i * sizeof(int)`.
        - **`*(...)`**: The asterisk dereferences the calculated address. It means "go to the memory location pointed to
          by
          `(ptr + i)` and retrieve the value stored there."

    2. **`ptr[i]`: Array Indexing**

        - This notation is more concise and reads like accessing an array element directly.
        - However, under the hood, C translates this notation into pointer arithmetic. `ptr[i]` is equivalent to
          `*(ptr + i)`.
5. **Free the allocated memory:**
   After you're done using the allocated memory, it's crucial to free it using `free` to avoid memory leaks:
   ```c
   free(ptr); 
   ```

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
   int *ptr = (int*) malloc(10 * sizeof(int));

   for (int i = 0; i < 10; i++) {
       *(ptr+i) = i * i;        // Assign values using pointer arithmetic
       ptr[i] = i * i;          // Assign values using array indexing
   }

   for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr+i));    // Access values using pointer arithmetic
        // printf("%d ", ptr[i]);   // Access values using array indexing
    }

   free(ptr);

   printf("\n");
   return 0;
}
```

---

### 2. `realloc`: Resizing Existing Memory Blocks

The `realloc` function allows you to resize a previously allocated memory block. This is particularly useful for dynamic
data structures like linked lists or dynamic arrays that need to grow or shrink based on the program's needs.

**Syntax:**

```c
void* realloc(void* ptr, size_t new_size);
```

* **`void* ptr`:** This argument is a pointer to the memory block previously allocated using `malloc`, `calloc`, or
  `realloc`.
* **`size_t new_size`:** This argument specifies the new desired size of the memory block in bytes.

**How to use `realloc`:**

1. **Call `realloc` with the original pointer and the new size:**
   ```c
   int *new_ptr = (int*) realloc(ptr, 20 * sizeof(int)); 
   ```
   This code attempts to resize the memory block pointed to by `ptr` to hold 20 integers.
2. **Check for reallocation success:**
   Like `malloc`, `realloc` can also fail if it cannot resize the block (e.g., insufficient contiguous memory). Always
   check the returned pointer:
   ```c
   if (new_ptr == NULL) {
       // Handle reallocation failure
       fprintf(stderr, "Memory reallocation failed!\n");
   
       // Important: 'ptr' still points to the old memory block!
       // Do not free 'ptr' here if reallocation failed.
       exit(1); 
   } else {
       // Update the pointer if reallocation succeeded
       ptr = new_ptr;
   }
   ```

**Key points to remember when using `realloc`:**

* If `realloc` succeeds, it returns a pointer to the resized memory block. This block might be at the same memory
  location or a new location if resizing requires moving the block.
* If `new_size` is 0, `realloc` behaves like `free`, and the memory block pointed to by `ptr` is freed.
* If `ptr` is NULL, `realloc` behaves like `malloc` and allocates a new block of memory of size `new_size`.

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    ptr = (int*) realloc(ptr, 15 * sizeof(int));

    for (int i = 0; i < 10; i++)
        *(ptr + i) = i * i;             // Assign values using pointer arithmetic

    printf("Initial array (%p):\t\t\t", ptr);
    for (int i = 0; i < 10; i++)
        printf("%d ", *(ptr + i));      // Access values using pointer arithmetic
    printf("\n");

    // Reallocate memory for 15 integers
    ptr = (int*) realloc(ptr, 15 * sizeof(int));

    // Assign values to the newly allocated memory
    for (int i = 10; i < 15; i++)
        *(ptr + i) = i * i;             // Assign values using pointer arithmetic

    printf("Array after reallocation (%p):\t", ptr);
    for (int i = 0; i < 15; i++)
        printf("%d ", *(ptr + i));      // Access values using pointer arithmetic
    printf("\n");

    free(ptr);

    printf("Array after freed (%p):\t\t", ptr);
    for (int i = 0; i < 15; i++)
        printf("%d ", *(ptr + i));      // Access values using pointer arithmetic
    printf("\n");
    return 0;
}
```

### Conclusion

Dynamic memory allocation with `malloc` and `realloc` provides significant flexibility when working with data structures
that can change size during program execution. By understanding their functionalities, potential pitfalls, and best
practices, you can write more efficient and dynamic C programs. Always remember to free dynamically allocated memory
using `free` to avoid memory leaks and ensure proper memory management.

## Dynamic Memory Problem Solving Examples

Let's solidify our understanding of `malloc` and `realloc` with these illustrative examples:

**Example 1: Allocating space for a single integer**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare a pointer to an integer
  int *ptr;

  // Allocate memory for one integer
  ptr = (int*) malloc(sizeof(int));

  // Use the allocated memory
  *ptr = 10;
  printf("Value at allocated memory: %d\n", *ptr);
  printf("Address of the allocated memory: %p\n", ptr);

  // Free the allocated memory
  free(ptr);

  return 0;
}
```

**Explanation:**

* We allocate enough memory to hold one integer using `sizeof(int)`.
* We check if `malloc` returned NULL, indicating an error.
* We use `*ptr` to access and modify the value at the allocated memory location.
* Finally, we free the memory using `free`.

---
**Example 2: Creating a dynamic array of a specific size**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    int *arr;

    printf("Enter the desired size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    arr = (int*) malloc(size * sizeof(int));

    // Populate the array
    for (i = 0; i < size; i++)
        arr[i] = i + 1;

   // Print the array in reverse using pointers
    printf("Array elements in reverse: ");
    int *ptr = arr + size - 1;  // Point to the last element of the array
    while (ptr >= arr)
        printf("%d ", *ptr--);  // Move the pointer to the previous element
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}

```

**Explanation:**

* We get the array size from the user.
* We allocate a block of memory large enough to hold `size` number of integers.
* The code populates and prints the dynamically allocated array.
* Again, `free` is used to release the allocated memory.

---
**Example 3: Traversing through String `Porsche Arnold` with pointer**

```c
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
```

---
**Example 4: Resizing an array using realloc**

**Problem:** Write a program that reads an unknown number of integers from the user until they enter -1. Store these
integers in a dynamically allocated array and then print the array.

**Solution:**

```c
#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort (ascending order)
int compare(const void *a, const void *b);

int main() {
    int *arr = NULL;
    int size = 0;
    int capacity = 10; // Initial capacity
    int num;

    // Allocate initial memory
    arr = (int*)malloc(capacity * sizeof(int));

    printf("Enter integers (-1 to stop): ");
    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;

        // Resize array if needed
        if (size == capacity) {
            capacity *= 2; // Double the capacity
            int *temp = (int*)realloc(arr, capacity * sizeof(int));
            if (temp == NULL) { // Check for realloc failure
                printf("Memory allocation failed!\n");
                free(arr);
                return 1;
            }
            arr = temp;
        }
        arr[size++] = num; // Add element to the array
    }

    // Sort the array using qsort
    qsort(arr, size, sizeof(int), compare);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
```

**Explanation:**

This code demonstrates dynamic memory allocation in C, along with sorting an array of integers using the `qsort`
function. Here's a breakdown:

1. Header Files:

    - `#include <stdio.h>`: Provides standard input/output functions like `printf` and `scanf`.
    - `#include <stdlib.h>`:  Includes functions for memory allocation (`malloc`, `realloc`, `free`) and sorting (
      `qsort`).

2. `compare` Function (For Sorting):

    - `int compare(const void *a, const void *b)`: This function is crucial for `qsort`. It compares two elements of the
      array and determines their relative order.
        - It takes two void pointers (`a` and `b`) because `qsort` works with any data type.
        - Inside the function:
            - `(int *)a` and `(int *)b`: Cast the void pointers to integer pointers.
            - `*(int *)a` and `*(int *)b`: Dereference the pointers to get the actual integer values.
            - The difference `(*(int *)a - *(int *)b)` is returned:
                - Negative: if `a` should come before `b`
                - Zero: if `a` and `b` are equal
                - Positive: if `a` should come after `b`

3. `main` Function:

    - `int *arr = NULL;`: Declares an integer pointer `arr`, initially set to `NULL`. This will store the address of our
      dynamic array.
    - `int size = 0;`: Keeps track of the number of elements currently in the array.
    - `int capacity = 10;`: The initial capacity (number of elements the array can hold).

4. Memory Allocation:

    - `arr = (int*)malloc(capacity * sizeof(int));`: Allocates a block of memory large enough to store `capacity` (10)
      integers.
        - `malloc()` returns a void pointer, so we cast it to `(int*)` to store it in `arr`.

5. Input Loop:

    - `while (1) { ... }`: An infinite loop that continues until the user enters `-1`.
        - `scanf("%d", &num);`: Reads an integer from the user and stores it in the `num` variable.
        - `if (num == -1) break;`: If the user enters `-1`, the loop breaks.

6. Resizing the Array:

    - `if (size == capacity) { ... }`: Checks if the array is full (number of elements `size` equals the `capacity`).
        - `capacity *= 2;`: If full, the capacity is doubled.
        - `int *temp = (int*)realloc(arr, capacity * sizeof(int));`:  `realloc` attempts to resize the memory block
          pointed
          to by `arr` to the new `capacity`.
            - If successful:  `realloc` returns the pointer to the potentially resized block.
            - If unsuccessful (memory allocation fails): `realloc` returns `NULL`.
        - Error Handling: We check if `temp` is `NULL`. If it is, an error message is printed, the previously allocated
          memory is freed (`free(arr);`), and the program exits with an error code (`return 1;`).
        - `arr = temp;`: Update `arr` to point to the potentially resized memory block.
    - `arr[size++] = num;`: Adds the entered number (`num`) to the array at the next available index (`size`) and then
      increments `size`.

7. Printing the Original Array:

    - The code uses a `for` loop to iterate through the elements of the array (`arr`) from index 0 to `size - 1` and
      prints
      each element.

8. Sorting with `qsort`:

    - `qsort(arr, size, sizeof(int), compare);`: Sorts the array `arr` in ascending order.
        - `arr`: The array to sort.
        - `size`: Number of elements.
        - `sizeof(int)`: Size of each element in bytes.
        - `compare`: Pointer to the comparison function.

9. Printing the Sorted Array:

    - The code iterates through the now-sorted array and prints each element, similar to printing the original array.

10. Freeing Memory:

    - `free(arr);`:  Releases the dynamically allocated memory pointed to by `arr` back to the operating system. This is
      essential to prevent memory leaks.

11. Return 0:

    - Indicates that the program executed successfully.

These examples illustrate the basic use of `malloc` and `realloc`. By mastering these functions, you gain the power to
manage memory dynamically, leading to more efficient and flexible C programs!

