# Array Tutorial

สำหรับวันนี้เราก็จะมาดูกันว่า Array นั้นทำงานอย่างไรโดยใช้โปรแกรม GDB

## Debugging C Arrays in GDB: Inspecting Memory, Bit Values, and Two's Complement

This guide walks through debugging C arrays using GDB with a focus on inspecting memory addresses, bit values, and
understanding two's complement representation for signed integers.

1. **Writing the Code**

    - **คอมคณะ:** ใน Desktop ของเครื่องที่ห้องแลป 203 จะมีโฟลเดอร์ "PhysicalCom" ที่มีไฟล์โค้ดภาษา C ชื่อว่า `array.c`
      ถ้าไม่มีให้ทำตาม Private Computer (Windows)
    - **Private Computer (Windows)**: สามารถก็อบคำสั่งด้านล่างไปใส่ใน cmd.exe ได้เลยหรือให้สร้างไฟล์ชื่อ `array.c`
      โดยข้างในไฟล์ต้องมีโค้ดเหมือนกับตัวอย่างด้านล่าง
      ```bash
      mkdir "%USERPROFILE%\Desktop\PhysicalCom"
      curl -o "%USERPROFILE%\Desktop\PhysicalCom\array.c" "https://raw.githubusercontent.com/TaeTanakrit0089/PhysicalComputing-167/main/labs/labs06-array/files/array.c"
      ```

    - **Private Computer (MacOS)**: สามารถก็อบคำสั่งด้านล่างไปใส่ใน Terminal ได้เลย
      โดยที่คำสั่งนี้จะสร้างโฟลเดอร์ `PhysicalCom` ที่ Desktop และสร้างไฟล์ให้อัตโนมัติ
      ```bash
      mkdir -p ~/Desktop/PhysicalCom
      curl -o ~/Desktop/PhysicalCom/array.c "https://raw.githubusercontent.com/TaeTanakrit0089/PhysicalComputing-167/main/labs/labs06-array/files/array.c"
      ```

   ให้ลองเปิดไฟล์ที่สร้างขึ้นมาใหม่ดู ข้างในไฟล์ต้องมีโค้ดดังนี้:

    ```c
    #include <stdio.h>
    
    int main() {
        int num[7] = {10, -20, 30, -40, 50, -60};
        num[6] = 70;
    
        // Calculate the size of the array
        int array_size = sizeof(num) / sizeof(num[0]); 
        // Iterate over the array using a for loop
        for (int i = 0; i < array_size; i++) 
            printf("%d ", num[i]);
    
        printf("\n"); 
        return 0;
    }

---

2. **Compile the Code:**

   ก่อนที่จะเริ่มการ debugging ให้ compile ไฟล์ `array.c` โดยใช้ GCC **โดยต้องเติม option `-g`**:

   ```bash
   gcc -g array.c -o array
   ```

    - The `-g` flag tells the compiler to generate debugging information.
    - The `-o <file>` flag tells the compiler to write output to <file>.

---

3. **Start the Debugger:**

   เมื่อ compile เสร็จแล้วจะได้ไฟล์ที่มีชื่อว่า `array` และในการรัน debugging สามารถรันได้โดยพิมพ์คำสั่ง `gdb`
   ตามด้วยชื่อไฟล์:

   ```bash
   gdb array
   ```
   เมื่อเรียกใช้ gdb จะพบหน้าต่างดังรูป โดยเราสามารถพิมพ์คำสั่งต่อจาก `(gdb)` ได้เลย

4. **Setting Breakpoints**

   ในตัวอย่างนี้ให้ตั้ง Breakpoint ไว้บรรทัดที่ 5
   ```gdb
   (gdb) b 5
   ```
   บรรทัดที่ 5 จะมีโค้ดตามนี้
   ```
   4           int num[7] = {10, -20, 30, -40, 50, -60};
   5           num[6] = 70;
   6
   ```
5. **Run the Program:**

   เริ่มการทำงานของโปรแกรมโดยใช้คำสั่ง `run`:

   ```gdb
   (gdb) r
   Starting program: /cygdrive/c/Users/LAB203_xx/Desktop/PhysicalCom/array
   [New Thread 5948.0x3d80]
   [New Thread 5948.0x3268]
   [New Thread 5948.0x26b0]
   [New Thread 5948.0x28c0]


   Thread 1 "array" hit Breakpoint 1, main () at array.c:5
   5           num[6] = 70;
   ```

   โปรแกรมจะทำงานไปจนกว่าถึงจุด breakpoint ที่ตั้งเอาไว้ เมื่อถึงจุด breakpoint (บรรทัดที่ 5)
   โปรแกรมจะหยุดการทำงานชั่วคราวและจะรอรับคำสั่งในการ debug จากเรา

---

6. **Check The Array Values:**

   ใช้คำสั่ง `print` ในการแสดงค่าของข้อมูลใน Array `num` แต่ละตัว:

   ```gdb
   (gdb) p num
   $1 = {10, -20, 30, -40, 50, -60, 0}
   (gdb) p num[0]
   $2 = 10
   (gdb) p num[1]
   $3 = -20
   (gdb) p num[3]
   $4 = -40
   (gdb) p num[5]
   $5 = -60
   (gdb) p num[6]
   $6 = 0  // ค่า default คือ 0
   ```
   คำสั่งด้านบนจะแสดงผลลัพธ์ของค่าของ array num และข้อมูลลำดับที่ 0, 1, 3, 5 และ 6

---

7. **Check The Array Address:**

   เราสามารถใช้คำสั่ง print ในการแสดงค่ารหัส address ใน memory ของตัวแปรได้ โดยวิธีการดูคือให้ใส่เครื่องหมาย
   Ampersand `&` นำหน้าชื่อตัวแปร
   ```gdb
   (gdb) p &num
   $8 = (int (*)[7]) 0x7ffffcbd0
   (gdb) p &num[0]
   $9 = (int *) 0x7ffffcbd0
   (gdb) p &num[1]
   $10 = (int *) 0x7ffffcbd4
   (gdb) p &num[3]
   $11 = (int *) 0x7ffffcbdc
   (gdb) p &num[5]
   $12 = (int *) 0x7ffffcbe4
   (gdb) p &num[6]
   $13 = (int *) 0x7ffffcbe8
   (gdb)
   ```
   **รายละเอียด:**

    1. **`p &num`**:
        - คำสั่งนี้แสดง address ของ array `num`
        - ผลลัพธ์ `(int (*)[7]) 0x7ffffcbd0` แสดงถึง:
            - `(int (*)[7])`: ชนิดของตัวแปรที่ถูกชี้ไป ซึ่งเป็น pointer ไปยัง array ของ integer ขนาด 7
            - `0x7ffffcbd0`: address ในหน่วยความจำของ array `num` (เลขฐานสิบหก)

    2. **`p &num[0]` ถึง `p &num[6]`**:
        - คำสั่งเหล่านี้แสดง address ของแต่ละ element ใน array `num` ตั้งแต่ index 0 ถึง 6
        - ผลลัพธ์แสดงถึง:
            - `(int *)`: ชนิดของตัวแปรที่ถูกชี้ไป ซึ่งเป็น pointer ไปยัง integer
            - `0x7ffffcbd0`, `0x7ffffcbd4`, `0x7ffffcbdc`, `0x7ffffcbe4`, `0x7ffffcbe8`: address ในหน่วยความจำของแต่ละ
              element ใน array โดย address จะเพิ่มขึ้นทีละ 4 bytes (ขนาดของ integer)

   **Remark:**

    - Address ในหน่วยความจำที่แสดงในผลลัพธ์อาจแตกต่างกันไปในแต่ละครั้งที่รันโปรแกรม

---

8. **Check The Bit Values:**

   เราสามารถใช้ gdb ในการเช็คค่าบิตของค่าในตัวแปรที่ถูกเก็บไว้ใน memory ได้โดยใช้คำสั่ง `print/t`

   **รูปแบบคำสั่ง:**

   ```
   (gdb) print/t <expression>
   ```

    - `print/t`:  บอก GDB ให้แสดงค่าของ expression ในรูปแบบบิต (binary)
    - `<expression>`:  นิพจน์ที่ต้องการตรวจสอบค่าบิต เช่น ตัวแปร ค่าคงที่ หรือผลลัพธ์ของการดำเนินการ

   ```gdb
   (gdb) p/t num
   $15 = {1010, 11111111111111111111111111101100, 11110,
   11111111111111111111111111011000, 110010, 11111111111111111111111111000100, 0}
   (gdb) p/t num[0]
   $16 = 1010
   (gdb) p/t num[1]
   $17 = 11111111111111111111111111101100
   (gdb) p/t num[3]
   $18 = 11111111111111111111111111011000
   (gdb) p/t num[5]
   $19 = 11111111111111111111111111000100
   (gdb) p/t num[6]
   $20 = 0
   ```



