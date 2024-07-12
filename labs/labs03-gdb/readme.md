# Debugging C Code with GDB on Windows (Cygwin)

## What is GDB?

GDB (GNU Debugger) เป็นเครื่องมือสำหรับการดีบักโปรแกรม
ซึ่งช่วยให้ผู้พัฒนาสามารถตรวจสอบและแก้ไขข้อผิดพลาดในโค้ดโปรแกรมได้ โดย GDB สนับสนุนหลายภาษาโปรแกรม เช่น C, C++, และ
Fortran

คุณสมบัติหลักของ GDB มีดังนี้:

1. การรันโปรแกรมทีละบรรทัด: สามารถรันโปรแกรมทีละบรรทัดเพื่อดูการทำงานของแต่ละคำสั่งได้
2. การตั้งเบรกพอยต์ (Breakpoint): สามารถตั้งจุดหยุดชั่วคราวในโค้ด เพื่อดูค่าตัวแปรและการทำงานของโปรแกรมในจุดที่สนใจ
3. การตรวจสอบและเปลี่ยนแปลงค่าตัวแปร: สามารถตรวจสอบค่าตัวแปรในขณะรันโปรแกรมและเปลี่ยนแปลงค่าตัวแปรได้
4. การเรียกดูสแตก (Stack): สามารถเรียกดูสแตกเฟรมเพื่อวิเคราะห์การเรียกฟังก์ชันที่เกิดขึ้นก่อนหน้าการเกิดข้อผิดพลาด

![gdb-command-tutorial.jpg](files/gdb-command-tutorial.jpg)

## How to install GDB

### Verify GDB Installation

* **Open Cygwin Terminal**
* **Check GDB Version by enter the following command:**

```bash
gdb --version
```

ถ้าใน Shell มีการติดตั้ง Cygwin อยู่แล้ว จะขึ้นผลลัพธ์ดังรูป ถ้าไม่ขึ้นแบบนี้ให้ติดตั้งก่อนใช้

![gdb-command-tutorial.jpg](files/CheckGDBVersion.png)

### Windows

สามารถใช้ Cygwin ในการรันได้เลยโดยจะต้องติดตั้ง Package ดังนี้ (https://www.cygwin.com/)

- `gcc-core`
- `gcc-g++`
- `libgcc1`
- `gdb`
- `libgdbm-devel`
- `libgdbm4`
- `libgdbm6`
- `libgdbm_compat4`

### MacOS

เนื่องจาก Apple ได้เปลี่ยนสถาปัตยกรรมของ CPU ใน Mac รุ่นใหม่จาก X86_64 ไปเป็นแบบ ARM ทำให้ไม่สามารถใช้ GDB ในการ debugging ได้ 

ซึ่งผู้ใช้ Mac ARM นั้นสามารถใช้โปรแกรม `lldb` ในการ debugging ซึ่งสามารถเช็คว่าได้ทำการติดตั้งลงเครื่องหรือยังผ่านคำสั่ง

```bash
lldb --version
```

ถ้าหากว่าในเครื่องได้มีโปรแกรมอยู่แล้ว จะขึ้นข้อความดังนี้
   ```
   lldb-1500.0.404.7
   Apple Swift version 5.10 (swiftlang-5.10.0.13 clang-1500.3.9.4)
   ```



## Starting Debugging with GDB

**1. Writing the Code**

- **คอมคณะ:** ใน Desktop ของเครื่องที่ห้องแลป 203 จะมีโฟลเดอร์ "PhysicalCom" ที่มีไฟล์โค้ดภาษา C ชื่อว่า `main.c`, ถ้าไม่มีให้ทำตาม Private Computer (Windows)
- **Private Computer (Windows)**: สามารถก็อบคำสั่งด้านล่างไปใส่ใน cmd.exe ได้เลยหรือให้สร้างไฟล์ชื่อ `main.c` โดยข้างในไฟล์ต้องมีโค้ดเหมือนกับตัวอย่างด้านล่าง
  ```bash
  mkdir "%USERPROFILE%\Desktop\PhysicalCom"
  curl -o "%USERPROFILE%\Desktop\PhysicalCom\main.c" "https://raw.githubusercontent.com/TaeTanakrit0089/PhysicalComputing-167/main/labs/labs03-gdb/files/main.c"
  ```

- **Private Computer (MacOS)**: สามารถก็อบคำสั่งด้านล่างไปใส่ใน Terminal ได้เลย โดยที่คำสั่งนี้จะสร้างโฟลเดอร์ `PhysicalCom` ที่ Desktop และสร้างไฟล์ให้อัตโนมัติ 
  ```bash
  mkdir -p ~/Desktop/PhysicalCom
  curl -o ~/Desktop/PhysicalCom/main.c "https://raw.githubusercontent.com/TaeTanakrit0089/PhysicalComputing-167/main/labs/labs03-gdb/files/main.c"
  ```

ให้ลองเปิดไฟล์ที่สร้างขึ้นมาใหม่ดู ข้างในไฟล์ต้องมีโค้ดดังนี้:

```c
#include "stdio.h"

int main() {
    int a = 10, b = 20, c = 30, d = 40;

    d = a++ + b++ + c++;
    d = ++a + ++b + ++c;

    return 0;
}
```

## Debugging C Code: A Step-by-Step Guide with `main.c` Example

This tutorial will guide you through debugging the provided `main.c` code using a debugger. We'll cover how to check variable values, print statements, and set breakpoints to understand the code's execution flow.

**Understanding the Code:**

The `main.c` code demonstrates the use of increment operators (`++`) in C. It initializes four integer variables (`a`, `b`, `c`, `d`) and performs two calculations involving these variables.

**Debugging Tools:**

For this tutorial, we'll assume you're using a debugger like **GDB** (GNU Debugger).

**Steps:**

1. **Compile the Code:**

   Before debugging, compile your code using a C compiler (like GCC) with debugging symbols enabled:

   ```bash
   gcc -g main.c -o main
   ```

   The `-g` flag tells the compiler to generate debugging information, which is essential for the debugger.

2. **Start the Debugger:**

   Run the debugger with the compiled executable:

   ```bash
   gdb main
   ```

3. **Set Breakpoints:**

   Breakpoints halt the program's execution at a specific line. To set a breakpoint, use the `break` command followed by the line number:

   ```gdb
   (gdb) break 6
   ```

   This sets a breakpoint at line 6 of your code.

4. **Run the Program:**

   Start the program execution:

   ```gdb
   (gdb) run
   ```

   The program will run until it hits the breakpoint you set.

5. **Check Variable Values:**

   Use the `print` command to display the value of a variable:

   ```gdb
   (gdb) print a
   (gdb) print b
   (gdb) print c
   (gdb) print d
   ```

   This will show you the current values of variables `a`, `b`, `c`, and `d`.

6. **Step Through the Code:**

   Use the following commands to step through the code line by line:

    * `next`: Executes the current line and moves to the next.
    * `step`: Executes the current line and steps into any function calls.
    * `continue`: Continues execution until the next breakpoint or the program ends.

7. **Examine the Call Stack:**

   The call stack shows the order of function calls. Use the `backtrace` command to view the call stack:

   ```gdb
   (gdb) backtrace
   ```

8. **Remove Breakpoints:**

   To remove a breakpoint, use the `delete` command followed by the breakpoint number:

   ```gdb
   (gdb) delete 1
   ```

9. **Quit the Debugger:**

   Exit the debugger with the `quit` command:

   ```gdb
   (gdb) quit
   ```

**Analyzing the `main.c` Code:**

By following these steps, you can analyze the execution flow of the `main.c` code and understand how the increment operators affect the variable values. Pay attention to the values of `a`, `b`, `c`, and `d` at different stages of execution.


]