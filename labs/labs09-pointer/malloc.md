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
       ptr[i] = i * i; // Assign values to the array
   }
   ```
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
    int n, i;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for 'n' integers
    arr = (int*) malloc(n * sizeof(int)); 

    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Read and store elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the array elements
    printf("Array elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}
```

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
    int *arr, i, n, new_n;

    printf("Enter the initial size of the array: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // ... (Populate the array) ...

    printf("Enter the new size of the array: ");
    scanf("%d", &new_n);

    // Reallocate memory for the new size
    int *temp = (int*) realloc(arr, new_n * sizeof(int));

    if (temp == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        // 'arr' still points to the old memory block
    } else {
        arr = temp; // Update the pointer 
    }

    // ... (Work with the resized array) ...

    free(arr);

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
    for (i = 0; i < size; i++) {
        printf("%d ", *ptr);
        ptr--;  // Move the pointer to the previous element
    }
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

**Example 3: Resizing an array using realloc**

**Problem:** Write a program that reads an unknown number of integers from the user until they enter -1. Store these
integers in a dynamically allocated array and then print the array.

**Solution:**

```c
#include <stdio.h>
#include <stdlib.h>

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
            arr = temp;
        }
        arr[size++] = num; // Add element to the array
    }

    printf("You entered: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
```

**Explanation:**

1. We start with an initial array capacity and dynamically allocate memory using `malloc`.
2. As the user inputs integers, we check if the array is full (`size == capacity`).
3. If full, we double the capacity using `realloc` to accommodate more elements.
4. The input is stored in the array, and the `size` is updated.
5. Finally, the array is printed, and the allocated memory is freed using `free`.

These examples illustrate the basic use of `malloc` and `realloc`. By mastering these functions, you gain the power to
manage memory dynamically, leading to more efficient and flexible C programs!
