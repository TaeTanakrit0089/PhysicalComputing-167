## Physical Computing ครั้งที่ 9: Pointers

### RAM ( หน่วยความจำ )

RAM ประกอบด้วยส่วนที่เรียกว่า **Address (ตำแหน่ง)** และ **Values (ค่าข้อมูล)** โดย Address
แต่ละตำแหน่งจะเก็บค่าข้อมูลได้

**ตัวอย่าง:**

| Address | ข้อมูล |
|---------|--------|
| 0000    | 15     |
| 0001    |        |
| 0002    |        |
| 0003    | 3.1415 |
| 0004    |        |
| 0005    |        |
| 0006    | 'A'    |
| ...     | ...    |
| XXXX    |        |

### 1. บทนำ

ตัวอย่างการประกาศตัวแปรในภาษาซี:

```c
int x = 2;
```

**สิ่งที่เกิดขึ้น:**

1. จองพื้นที่ใน RAM เพื่อเก็บค่าตัวเลขจำนวนเต็ม
2. กำหนดชื่อตัวแปร `x` ให้เป็นชื่อของตำแหน่ง (address) ใน RAM
3. เก็บค่าข้อมูล `2` ลงในตำแหน่งนั้น

**ตัวอย่าง:**

- `x` คือ Location name
- `2` คือ Values at Location
- `0F45AB14` คือ Address number (Location Number)

**หมายเหตุ:** Address number ในความเป็นจริง อาจไม่ใช่หมายเลข 0F45AB14 แต่เป็นเพียงตัวอย่าง

### 2. การแสดงตำแหน่ง address

เราสามารถแสดงตำแหน่ง address ของตัวแปรได้ดังนี้:

```c
#include <stdio.h>

int main() {
  int a = 3;
  printf("Address of a = %d \n", &a);  // แสดง address ในเลขฐานสิบ
  printf("Address of a = %p \n", &a);  // แสดง address ในเลขฐานสิบหก
}
```

- `&` อ่านว่า แอมเพอร์แซนด์ (ampersand) หรือเรียกโดยทั่วไปว่า แอนด์ (and)
- `%d` แสดงตำแหน่งเป็นเลขฐานสิบ
- `%p` แสดงตำแหน่งเป็นเลขฐานสิบหก

### 3. การแสดงค่าข้อมูลที่ address นั้น ๆ

เราสามารถแสดงค่าข้อมูลที่ address ของตัวแปรได้ดังนี้:

```c
#include <stdio.h>

int main() {
  int a = 3;
  printf("Address of a = %d \n", &a);
  printf("Values of a = %d \n", a);
  printf("Values of a = %d \n", *(&a));  // แสดงค่าข้อมูลที่ address ของ a
}
```

- `*` อ่านว่า แอสเทอริส (asterisk) หรือเรียกโดยทั่วไปว่า ดอกจัน
- `*(&a)` หมายถึง Values at Address ของตัวแปร `a`

### 4. การประกาศตัวแปร pointer

เราสามารถเก็บค่า address ของตัวแปร ไว้ในตัวแปรอีกตัวหนึ่งได้ โดยตัวแปรที่ใช้เก็บ address นั้น เรียกว่า **pointer**

**ตัวอย่าง:**

```
b = &a 
```

- `b` เป็นตัวแปร pointer ที่เก็บ address ของตัวแปร `a`

**การประกาศตัวแปร pointer:**

```c
int *b;
```

- `int` คือ ชนิดของตัวแปรที่ pointer ชี้อยู่
- `*` คือ เครื่องหมายแสดงว่าเป็นตัวแปร pointer
- `b` คือ ชื่อของตัวแปร pointer

### ตัวอย่างการใช้ตัวแปร pointer

```c
#include <stdio.h>

int main() {
  int a = 3;
  int *b;
  b = &a;

  printf("Address of a = %d \n", &a);
  printf("Address of a = %d \n", b);
  printf("Address of b = %d \n", &b);
  printf("Values of a = %d \n", a);
  printf("Values of a = %d \n", *(&a));
  printf("Values of a = %d \n", *b);
  printf("Values of b = %d \n", b);
}
```

### 5. รูปแบบการประกาศตัวแปร pointer

```
type *pointer_name
```

- `type`: ชนิดของตัวแปรที่ pointer ชี้ (เช่น int, float)
- `*`:  เครื่องหมายแสดงว่าเป็นตัวแปร pointer
- `pointer_name`:  ชื่อของตัวแปร pointer

**ตัวอย่าง:**

```c
int num;
int *pnum;
float salary = 1200.50;
float *psalary;
```

### ตัวอย่างการใช้งาน pointer

```c
#include<stdio.h>
int main()
{
  char letter = 'D';
  int num = 19;
  float point = 26.09;
  
  char *pt_letter;
  int *pt_num;
  float *pt_point;
  
  pt_letter = &letter;
  pt_num = &num;
  pt_point = &point;

  printf("Address of letter = %p \n", pt_letter);
  printf("Address of num = %p \n", pt_num);
  printf("Address of point = %p \n", pt_point);

  return 0;
}
```

### 6. Pointer ของ pointer

pointer สามารถเก็บ address ของ pointer ตัวอื่นได้ ซึ่งเรียกว่า **nested pointer**

**ตัวอย่าง:**

```c
#include <stdio.h>

int main() {
  int a = 3;
  int *b;
  int **c;

  b = &a;
  c = &b;

  printf("Address of a = %d \n", &a);
  printf("Address of a = %d \n", b);
  printf("Address of a = %d \n", *c);
  printf("Address of b = %d \n", &b);
  printf("Address of b = %d \n", c);
  printf("Address of c = %d \n", &c);
  printf("Values of a = %d \n", a);
  printf("Values of a = %d \n", *(&a));
  printf("Values of a = %d \n", *b);
  printf("Values of a = %d \n", **c);
  printf("Values of b = %d \n", b);
  printf("Values of c = %d \n", c);
}
```

### ตัวอย่าง Nested Pointer

```c
float time = 9.28;
float *pt_time;
float **ptt_time;

pt_time = &time;
ptt_time = &pt_time;

float temp1;
temp1 = *pt_time;

float temp2;
temp2 = **ptt_time;
```

**ภาพประกอบ:**

- `time` มีค่าเป็น 9.28 และอยู่ที่ address 0100
- `pt_time` เก็บ address ของ `time` (0100)
- `ptt_time` เก็บ address ของ `pt_time` (0250)

### 7. การกระทำทางคณิตศาสตร์ของ Pointer

สามารถใช้ +, -, ++, -- กับ pointer ได้

- `+`: เพิ่มค่า address ให้สูงขึ้น (เลื่อนไปตำแหน่งถัดไป)
- `-`: ลดค่า address ให้ต่ำลง (เลื่อนไปตำแหน่งก่อนหน้า)

**หมายเหตุ:** การเลื่อน address ขึ้นอยู่กับขนาดของข้อมูลที่ pointer ชี้อยู่ด้วย (int, char, float)

### 8. ความสัมพันธ์ของ Pointer และ Array

- Pointer สามารถชี้ไปที่ address แรกของ Array ได้
- สามารถใช้ pointer อ้างอิง element ใน Array โดยการบวกค่า address

**ตัวอย่าง:**

```c
#include <stdio.h>
int main()
{
    int number[] = {100,200,300};
    int *pt;

    pt = number;
    printf("number[0] = %d \n", *pt);
    printf("number[1] = %d \n", *(pt+1));
    printf("number[2] = %d \n", *(pt+2));
}
```

### ตัวอย่างการใช้งาน Pointer ในการบวกเลข

```c
#include <stdio.h>
int main()
{
    int a, b, r;
    int *pa = &a;
    int *pb = &b;
    int *pr = &r;
    
    printf("Enter the first number: ");
    scanf("%d", pa);
    
    printf("Enter the second number: ");
    scanf("%d", pb);
    
    *pr = *pa + *pb;
    printf("\n%d + %d is %d", *pa, *pb, *pr);
    
    return 0;
}
```

### ตัวอย่างการใช้งาน Pointer เดียวกับหลายตัวแปร

```c
#include <stdio.h>
void main (void)
{
    int a, b, c;
    int *p;
    
    printf("Enter three numbers and key return: ");
    scanf("%d %d %d", &a, &b, &c);
    
    p = &a;
    printf("\n %3d", *p);
    
    p = &b;
    printf("\n %3d ", *p);
    
    p = &c;
    printf("\n %3d", *p);
}
```

### ตัวอย่างการใช้งานหลาย Pointer กับตัวแปรเดียว

```c
#include <stdio.h>
void main (void)
{
    int a;
    int *p = &a;
    int *q = &a;
    int *r = &a;
    
    printf("Enter a number: ");
    scanf("%d", &a);
    
    printf("\n %d ", *p);
    printf("\n %d ", *q);
    printf("\n %d ", *r);
}
```

### Function: Pass by value vs Pass by reference

**Pass by value**: คิดค่าข้อมูลไปใช้ในฟังก์ชั่น ตัวแปรเดิมไม่เปลี่ยนแปลง

**Pass by reference**: ส่ง address ของตัวแปรไปยังฟังก์ชั่น การเปลี่ยนแปลงค่าในฟังก์ชั่นจะส่งผลต่อตัวแปรเดิมด้วย

### ตัวอย่างการประยุกต์ใช้ Pointer: Linked list

- Linked list คือ โครงสร้างข้อมูลที่ประกอบด้วย node หลายๆ node เชื่อมต่อกัน
- แต่ละ node จะเก็บข้อมูลและ address ของ node ถัดไป

**การใช้งาน Linked list:**

- เพิ่ม ลบ แก้ไข node ใน list
- ใช้เป็น stack หรือ queue

### การลบ Node ใน Linked list

- เปลี่ยน pointer ของ node ก่อนหน้า node ที่ต้องการลบ ให้ชี้ไปยัง node ถัดไปของ node ที่ถัดไป

### การเพิ่ม Node ใน Linked list

- สร้าง node ใหม่
- เปลี่ยน pointer ของ node ก่อนหน้าตำแหน่งที่ต้องการแทรก ให้ชี้ไปที่ node ใหม่
- เปลี่ยน pointer ของ node ใหม่ ให้ชี้ไปที่ node ถัดไป

### แบบฝึกหัด

1. เขียนโปรแกรมรับข้อมูลตัวเลขทศนิยม 3 จำนวน แล้วส่งไปยังฟังก์ชันย่อยเพื่อสลับตำแหน่ง
   โดยให้ตัวเลขตัวแรกไปอยู่ตำแหน่งที่สอง ตัวที่สองไปอยู่ตำแหน่งที่สาม และตัวที่สามไปอยู่ตำแหน่งแรก
2. เขียนโปรแกรมรับข้อความ แล้วตรวจสอบว่าเป็นข้อความสมมาตร (palindrome) หรือไม่ โดยใช้ pointer
3. เขียนโปรแกรมรับค่า แล้วแสดงผลแบบย้อนกลับ

## สรุป

Pointers เป็นเครื่องมือที่มีประโยชน์มากในการเขียนโปรแกรมภาษาซี ช่วยให้จัดการหน่วยความจำได้อย่างมีประสิทธิภาพ
และสามารถใช้สร้างโครงสร้างข้อมูลที่ซับซ้อนได้ 
