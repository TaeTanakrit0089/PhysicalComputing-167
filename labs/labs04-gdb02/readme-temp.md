## Debugging C code with GDB: A Step-by-Step Tutorial

This tutorial will guide you through debugging the provided C code using GDB (GNU Debugger). We'll break down each
assignment statement and demonstrate how to use GDB to inspect variables and track the program's execution.

**1. Setting up GDB:**

* **Compile with Debugging Symbols:** Compile the code with the `-g` flag to enable debugging information:
   ```bash
   gcc -g main.c -o main
   ```
* **Start GDB:** Run GDB on the executable:
   ```bash
   gdb main
   ```

**2. Debugging Assignment Statements:**

Let's walk through each assignment statement and how to debug it using GDB:

**1. `c=i+=j`:**

* **Set a breakpoint:**
   ```gdb
   break main.c:7
   ```
  This sets a breakpoint at the line containing the assignment statement.
* **Run the program:**
   ```gdb
   run
   ```
* **Inspect variables:**
   ```gdb
   print i
   print j
   print c
   ```
  This will show the values of `i`, `j`, and `c` before and after the assignment.
* **Step over the line:**
   ```gdb
   n
   ```
  This steps to the next line and allows you to observe the change in `c`.

**2. `y=x=z-j`:**

* **Set a breakpoint at line 8:**
   ```gdb
   break main.c:8
   ```
* **Continue running:**
   ```gdb
   c
   ```
* **Inspect the values:**
   ```gdb
   print x
   print y
   print z
   print j
   ```

**3. `z/j`:**

* **This is an expression, not an assignment.** GDB can still evaluate it.
* **Evaluate the expression:**
   ```gdb
   print z/j
   ```

**4. `(d <= 'a') && ('A' >= c-30)`:**

* **Set a breakpoint at line 9:**
   ```gdb
   break main.c:9
   ```
* **Run to the breakpoint:**
   ```gdb
   c
   ```
* **Evaluate the expression:**
   ```gdb
   print (d <= 'a') && ('A' >= c-30)
   ```
* **Step over the expression:**
   ```gdb
   n
   ```

**5. `y-=(c+d)/i+x`:**

* **Set a breakpoint at line 10:**
   ```gdb
   break main.c:10
   ```
* **Continue execution:**
   ```gdb
   c
   ```
* **Inspect values before and after assignment:**
   ```gdb
   print y
   print (c+d)/i+x
   n
   print y
   ```

**6. `(y-x)>=z`:**

* **Set a breakpoint at line 11:**
   ```gdb
   break main.c:11
   ```
* **Continue execution:**
   ```gdb
   c
   ```
* **Evaluate the expression:**
   ```gdb
   print (y-x)>=z
   ```

**7. `j*=(int)(x+z)/2`:**

* **Set a breakpoint at line 12:**
   ```gdb
   break main.c:12
   ```
* **Continue execution:**
   ```gdb
   c
   ```
* **Inspect values before and after assignment:**
   ```gdb
   print j
   print (int)(x+z)/2
   n
   print j
   ```

**8. `i=c%j`:**

* **Set a breakpoint at line 13:**
   ```gdb
   break main.c:13
   ```
* **Continue execution:**
   ```gdb
   c
   ```
* **Inspect values before and after assignment:**
   ```gdb
   print i
   print c%j
   n
   print i
   ```

**9. `(x*j) >= (z*i)`:**

* **Set a breakpoint at line 14:**
   ```gdb
   break main.c:14
   ```
* **Continue execution:**
   ```gdb
   c
   ```
* **Evaluate the expression:**
   ```gdb
   print (x*j) >= (z*i)
   ```

**10. `j*(i-7)>(y-2)`:**

* **Set a breakpoint at line 15:**
   ```gdb
   break main.c:15
   ```
* **Continue execution:**
   ```gdb
   c
   ```
* **Evaluate the expression:**
   ```gdb
   print j*(i-7)>(y-2)
   ```

**3. Quitting GDB:**

* **Use the `quit` command:**
   ```gdb
   quit
   ```

**Key GDB Commands:**

* **`break [filename]:[line_number]`:** Set a breakpoint at a specific line.
* **`run`:** Run the program.
* **`c`:** Continue execution.
* **`n`:** Step over the next line.
* **`print [expression]`:** Display the value of an expression.
* **`quit`:** Exit GDB.

By following these steps, you can effectively debug your C code using GDB to identify issues and understand how your
program executes. Remember to refer to the GDB documentation for more advanced features and debugging techniques. 
