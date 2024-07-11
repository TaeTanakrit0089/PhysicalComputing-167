## Debugging C Code with GDB on Windows (Cygwin)

This tutorial demonstrates how to use the GNU Debugger (GDB) to debug a simple C program compiled with GCC in a Cygwin environment on Windows.

**1. Writing the Code**

Create a file named `main.c` inside the "PhysicalCom" folder with the following code:

```c
#include "stdio.h"

int main() {
    int a = 17, b = 25, c = 50, d = 10;

    // Assignment Statements of Each Question

    return 0;
}
```

**3. Compiling with GCC**

Open a Cygwin terminal and navigate to your "PhysicalCom" directory using the `cd` command.

Compile the code using GCC with debugging symbols enabled:

```bash
gcc -g main.c -o main
```

This will create an executable file named `main`.

**4. Running GDB**

Start GDB by typing:

```bash
gdb main
```

You'll be presented with the GDB prompt (gdb).

**5. Setting Breakpoints**

Breakpoints halt the program execution at a specific line. To set a breakpoint, use the `break` command followed by the line number:

```gdb
break 5
```

This sets a breakpoint at line 5 of your code.

**6. Running the Program**

Start the program execution with:

```gdb
run
```

The program will run until it hits the breakpoint you set.

**7. Examining Variables**

Use the `print` command to examine the value of a variable:

```gdb
print a
```

This will print the value of the variable `a`.

**8. Stepping Through Code**

* **`next`:** Executes the next line of code.
* **`step`:** Executes the next line of code, stepping into any function calls.
* **`continue`:** Continues execution until the next breakpoint or the end of the program.

**9. Quitting GDB**

Exit GDB with:

```gdb
quit
```

**Additional GDB Commands**

* `info breakpoints`: Lists all set breakpoints.
* `delete <breakpoint_number>`: Deletes a breakpoint.
* `help`: Displays help information for GDB commands.



This tutorial provides a basic introduction to using GDB for debugging C code in a Cygwin environment. For more advanced debugging techniques and GDB features, refer to the official GDB documentation: [https://sourceware.org/gdb/](https://sourceware.org/gdb/).