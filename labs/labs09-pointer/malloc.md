Dynamic Memory Allocation in C: Mastering malloc and realloc

This document serves as a comprehensive guide to understanding and using malloc and realloc, two powerful functions in C
that allow dynamic memory allocation. We will delve into their syntax, functionality, common use cases, and potential
pitfalls.

Introduction

In C, variables typically have a fixed size determined at compile time. This works well for many scenarios but falls
short when dealing with data structures whose size changes during program execution. Imagine creating a program to store
student names, where the number of students is unknown beforehand. This is where dynamic memory allocation comes to the
rescue.

Dynamic memory allocation allows programs to request memory from the operating system at runtime. This means you can
create data structures that grow or shrink dynamically based on the program's needs. C provides two primary functions
for this purpose: malloc and realloc.

1. malloc: Allocating Memory Blocks

The malloc function allocates a block of memory of a specified size and returns a pointer to the beginning of that
block.

Syntax:

void* malloc(size_t size);
content_copy
Use code with caution.
C

void*: The function returns a void pointer, meaning it can point to any data type. You will need to explicitly typecast
this pointer to the desired data type.

size_t size: This argument specifies the size of the memory block to be allocated, in bytes.

How to use malloc:

Include the <stdlib.h> header file:

#include <stdlib.h>
content_copy
Use code with caution.
C

Call malloc with the desired size:

int *ptr = (int*) malloc(10 * sizeof(int));
content_copy
Use code with caution.
C

This code snippet allocates enough memory to store an array of 10 integers and assigns the starting address of the
allocated block to the pointer ptr.

Check for allocation success:
malloc returns a NULL pointer if memory allocation fails (e.g., insufficient memory). Always check the returned pointer
before using it:

if (ptr == NULL) {
// Handle memory allocation failure
fprintf(stderr, "Memory allocation failed!\n");
exit(1);
}
content_copy
Use code with caution.
C

Access and use the allocated memory:
You can now use the pointer to access and modify the allocated memory:

for (int i = 0; i < 10; i++) {
ptr[i] = i * i; // Assign values to the array
}
content_copy
Use code with caution.
C

Free the allocated memory:
After you're done using the allocated memory, it's crucial to free it using free to avoid memory leaks:

free(ptr);
content_copy
Use code with caution.
C

Example:

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
content_copy
Use code with caution.
C

2. realloc: Resizing Existing Memory Blocks

The realloc function allows you to resize a previously allocated memory block. This is particularly useful for dynamic
data structures like linked lists or dynamic arrays that need to grow or shrink based on the program's needs.

Syntax:

void* realloc(void* ptr, size_t new_size);
content_copy
Use code with caution.
C

void* ptr: This argument is a pointer to the memory block previously allocated using malloc, calloc, or realloc.

size_t new_size: This argument specifies the new desired size of the memory block in bytes.

How to use realloc:

Call realloc with the original pointer and the new size:

int *new_ptr = (int*) realloc(ptr, 20 * sizeof(int));
content_copy
Use code with caution.
C

This code attempts to resize the memory block pointed to by ptr to hold 20 integers.

Check for reallocation success:
Like malloc, realloc can also fail if it cannot resize the block (e.g., insufficient contiguous memory). Always check
the returned pointer:

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
content_copy
Use code with caution.
C

Key points to remember when using realloc:

If realloc succeeds, it returns a pointer to the resized memory block. This block might be at the same memory location
or a new location if resizing requires moving the block.

If new_size is 0, realloc behaves like free, and the memory block pointed to by ptr is freed.

If ptr is NULL, realloc behaves like malloc and allocates a new block of memory of size new_size.

Example:

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
content_copy
Use code with caution.
C
Conclusion

Dynamic memory allocation with malloc and realloc provides significant flexibility when working with data structures
that can change size during program execution. By understanding their functionalities, potential pitfalls, and best
practices, you can write more efficient and dynamic C programs. Always remember to free dynamically allocated memory
using free to avoid memory leaks and ensure proper memory management.