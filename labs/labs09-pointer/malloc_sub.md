Playing with `malloc` and pointers in C can be both educational and risky. Here are some interesting and potentially "
crazy" things you can do, but be cautious—these exercises can lead to undefined behavior and crashes if not handled
correctly.

### 1. **Memory Overwrites**

Allocate a block of memory and write beyond its bounds. This demonstrates how memory can be corrupted, which might lead
to crashes or unpredictable behavior.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    size_t size = 10;
    char *ptr = (char *)malloc(size);

    // Fill allocated memory
    strcpy(ptr, "0123456789");

    // Write beyond allocated memory
    ptr[size] = '\0'; // This is beyond the allocated size

    printf("Buffer: %s\n", ptr);

    free(ptr);
    return 0;
}
```

### 2. **Double Free**

Free the same memory twice to see how the program behaves. This is usually a serious bug and can lead to crashes or
security vulnerabilities.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr = (char *)malloc(10);

    if (ptr == NULL) {
        perror("malloc failed");
        return EXIT_FAILURE;
    }

    free(ptr);
    free(ptr); // Double free

    return 0;
}
```

### 3. **Use After Free**

Use memory after it has been freed. This often leads to crashes or corrupted data.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr = (char *)malloc(10);

    *ptr = 65;

    free(ptr);

    // Use after free
    printf("Value: %c\n", ptr[0]); // Undefined behavior

    return 0;
}

```

### 4. **Pointer Arithmetic**

Use pointer arithmetic to navigate memory blocks. This can be useful but also risky if done improperly.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 10;
    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        perror("malloc failed");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < size; ++i) {
        arr[i] = i;
    }

    int *ptr = arr;
    for (size_t i = 0; i < size; ++i) {
        printf("Value at %ld: %d\n", i, *(ptr + i));
    }

    free(arr);
    return 0;
}
```

### 5. **Dangling Pointer**

Use a pointer after the memory it points to has been freed. This is a common source of bugs and crashes.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));

    *ptr = 42;
    printf("Value: %d\n", *ptr);
    
    free(ptr);

    // Dangling pointer usage
    printf("Dangling value: %d\n", *ptr); // Undefined behavior

    return 0;
}
```

### 6. **Memory Leak**

Allocate memory and forget to free it. This causes a memory leak, which can eventually lead to resource exhaustion.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        char *ptr = (char *)malloc(1024 * 1024); // Allocate 1MB
        // Memory is not freed, causing a leak
        // Do something with ptr if needed
    }
    return 0;
}
```

### 7. **Pointer Swapping**

Swap pointers to see how it affects memory.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a = (int *)malloc(sizeof(int));
    int *b = (int *)malloc(sizeof(int));

    if (a == NULL || b == NULL) {
        perror("malloc failed");
        return EXIT_FAILURE;
    }

    *a = 10;
    *b = 20;

    printf("Before swap: a=%d, b=%d\n", *a, *b);

    // Swap pointers
    int *temp = a;
    a = b;
    b = temp;

    printf("After swap: a=%d, b=%d\n", *a, *b);

    free(a); // Free b
    free(b); // Free a

    return 0;
}
```

### Caution

- **Always check the return value of `malloc` to ensure it succeeded.**
- **Be extremely careful with pointer arithmetic and memory management to avoid undefined behavior and crashes.**
- **Use tools like Valgrind to check for memory leaks and undefined behavior.**

These examples are for educational purposes to illustrate how `malloc` and pointers can be manipulated. In practice,
proper memory management is crucial for writing safe and efficient C code.