# Lab07 Function

## Lecture Slide

- [lecture_slide.md](lecture_slide.md)
- [PC-Chapter 7 - Lecture Note.pdf](files/PC-Chapter%207%20-%20Lecture%20Note.pdf)

# Pointer Examples

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