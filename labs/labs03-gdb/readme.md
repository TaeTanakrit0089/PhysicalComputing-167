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

ในการลงนั้นจำเป็นจะต้องใช้ Homebrew

**1. Install Homebrew**

ถ้าหากว่าในเครื่องน้องยังไม่ได้ลง Homebrew ให้ลงผ่านลิงก์นี้ก่อน : [https://brew.sh/](https://brew.sh/).

**2. Install GDB**

ให้เปิด Terminal ใน Mac ขึ้นมาและใส่คำสั่งนี้ลงไป:

```bash
brew install x86_64-elf-gdb
```

คำสั่งนี้จะดาวน์โหลดและติดตั้งแพคเกจ `x86_64-elf-gdb`

**3. Configure Your Shell**

เพื่อความสะดวกและรวดเร็วในการเข้าถึง GDB จาก Terminal ให้เพิ่มบรรทัดต่อไปนี้ในไฟล์กำหนดค่า Shell ของน้อง

```bash
echo "alias gdb='x86_64-elf-gdb'" >> ~/.zshrc
```

คำสั่งจะสร้าง alias ที่ชื่อว่า gdb ซึ่งชี้ไปที่คำสั่ง `x86_64-elf-gdb` ใน `$PATH`

**4. Source Your Shell Configuration**

หลังจากเพิ่ม alias แล้ว ต้องรันคำสั่งนี้เพื่อ refresh shell:

```bash
source ~/.zshrc
```

You should see the version information for the installed GDB.

### Verify Installation

* **Open Cygwin Terminal**
* **Check GDB Version by enter the following command:**

```bash
gdb --version
```

ถ้าใน Shell มีการติดตั้ง Cygwin อยู่แล้ว จะขึ้นผลลัพธ์ดังรูป ถ้าไม่ขึ้นแบบนี้ให้ติดตั้งก่อนใช้

![gdb-command-tutorial.jpg](files/CheckGDBVersion.png)

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

Breakpoints halt the program execution at a specific line. To set a breakpoint, use the `break` command followed by the
line number:

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

This tutorial provides a basic introduction to using GDB for debugging C code in a Cygwin environment. For more advanced
debugging techniques and GDB features, refer to the official GDB
documentation: [https://sourceware.org/gdb/](https://sourceware.org/gdb/).