# Array Tutorial

สำหรับวันนี้เราก็จะมาดูกันว่า Array นั้นทำงานอย่างไรโดยใช้โปรแกรม GDB

## Debugging C Arrays in GDB: Inspecting Memory, Bit Values, and Two's Complement

This guide walks through debugging C arrays using GDB with a focus on inspecting memory addresses, bit values, and understanding two's complement representation for signed integers.

**1. Sample Code**

Let's start with a simple C program containing an array:

```c
#include <stdio.h>

int main() {
  int numbers[] = {10, -5, 20, -128};

  // ... (rest of your code) ...

  return 0;
}
```

**2. Compiling for Debugging**

Compile your code with debugging symbols using the `-g` flag:

```bash
gcc -g -o myprogram myprogram.c
```

**3. Launching GDB**

Start the GDB debugger with your program:

```bash
gdb ./myprogram
```

**4. Setting Breakpoints**

Set a breakpoint where you want to start inspecting your array:

```gdb
break main
run
```

**5. Inspecting Memory Addresses**

* **Print the array:**
   ```gdb
   print numbers
   ```
  This shows the array's contents in a familiar format.
* **Get the address of the array:**
   ```gdb
   print &numbers
   ```
  This displays the memory address where the array begins.
* **Examine memory contents:**
   ```gdb
   x/4xw &numbers
   ```
  This command examines memory at the address of `numbers`, displaying 4 words (typically 4 bytes each on 32-bit systems) in hexadecimal format.

**6. Inspecting Bit Values**

* **Examine memory in binary:**
   ```gdb
   x/4bt &numbers
   ```
  This displays the memory contents in binary format, showing the individual bits.

**7. Understanding Two's Complement**

Two's complement is used to represent signed integers. Let's break down how to interpret the binary representation of `-5` in our array.

1. **Find the binary representation:**  From the `x/4bt` output, locate the bytes representing -5.
2. **Invert the bits:** Change all 0s to 1s and 1s to 0s.
3. **Add 1:** Add binary 1 to the inverted result.
4. **Interpret the result:** The resulting binary number represents the magnitude of the negative value.

**Example:**

Assuming a 32-bit system, `-5` might be represented as:

```
11111111 11111111 11111111 11111011 
```

1. **Invert:** `00000000 00000000 00000000 00000100`
2. **Add 1:**  `00000000 00000000 00000000 00000101`
3. **Result:** This final binary representation is equivalent to decimal 5, confirming the original value was -5.

**8. Advanced Techniques**

* **Inspecting Individual Array Elements:** Access elements using their indices (e.g., `print numbers[2]`).
* **Changing Array Values:** Use the `set` command (e.g., `set numbers[1] = 7`).
* **Watchpoints:** Set watchpoints on array elements to halt execution when their values change.

**Practice:**

Experiment with these commands and techniques to gain a deeper understanding of array storage and representation in memory. Modify the sample code, introduce errors, and use GDB's powerful debugging features to analyze and fix them. 
