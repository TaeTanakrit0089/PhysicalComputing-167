# Lab09 Pointer

## Lecture Slide

- [lecture_slide.md](files/lecture_slide.md)
- [PC-Chapter 7 - Lecture Note.pdf](files/PC-Chapter%207%20-%20Lecture%20Note.pdf)

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

## Debugging C Dynamic Array Resizing with GDB

This document guides you through debugging the provided C code snippet using GDB. The code demonstrates resizing a
dynamically allocated array using `realloc()`. We'll focus on inspecting memory, variable values, and potential issues.

### 1. Compile for Debugging

Compile the code with debugging symbols (`-g` flag):

```bash
gcc -g -o resize_array resize_array.c
```

### 2. Start GDB

Load the program into GDB:

```bash
gdb resize_array
```

### 3. Set Breakpoints

Set breakpoints at critical points to pause execution and examine the program state:

```gdb
break 12     // Break before memory allocation
break 25     // Break before reallocation
break 36     // Break before freeing memory
```

### 4. Run the Program

Start running the program within GDB:

```gdb
run
```

### 5. Inspecting Memory Allocation (Breakpoint 1)

The program pauses at the first breakpoint. Use the following commands:

- `print n`: Display the initial array size.
- `print arr`: Display the address where `arr` points (should be `NULL` initially).
- `next`: Execute the `malloc()` call.
- `print arr`: Observe that `arr` now points to a valid memory address.
- `x/10i arr`: Examine the first 10 elements of the allocated memory (they might contain garbage values).

### 6. Populate the Array

Continue execution and provide input for populating the array:

```gdb
continue
```

- Input the initial size and array elements as prompted.

### 7. Inspecting Reallocation (Breakpoint 2)

The program pauses before `realloc()`. Use these commands:

- `print new_n`: Display the desired new size.
- `print arr`: Check the current memory address of `arr`.
- `x/10i arr`: Examine the current array elements.
- `next`: Execute the `realloc()` call.
- `print temp`: Check the address returned by `realloc()`.
    - If the address is different from `arr`, reallocation allocated a new memory block.
    - If the address is the same, `realloc()` resized the existing block in place (if possible).
- `print arr`: Observe if `arr` has been updated to point to the new memory location.
- `x/10i arr`: Inspect the array elements, noting if data was preserved during reallocation.

### 8. Handling Reallocation Failure

- Intentionally provide a very large value for the new size to potentially trigger a `realloc()` failure.
- If `temp` is `NULL` after `realloc()`, the code correctly handles the failure.

### 9. Inspecting Memory Deallocation (Breakpoint 3)

- `continue`: Resume execution until the `free()` call.
- `print arr`: Observe the address being passed to `free()`.
- `next`: Execute the `free()` call.

### 10. Additional Debugging Tips

- Use `watch arr` to monitor changes in `arr`'s value throughout the program.
- Employ `step` instead of `next` to step into function calls (like `malloc()`, `realloc()`, `free()`) for deeper
  analysis.
- Leverage GDB's memory examination commands (`x`, `dump memory`) to analyze the heap and detect potential memory leaks
  or corruption.

By carefully stepping through the code with GDB, you can gain a thorough understanding of how dynamic memory allocation
and reallocation work in C, and identify potential pitfalls in your code. 
