## ภาษา C: การใช้งานโครงสร้างข้อมูล (Structure)

**Lecture Slide:** [PC67-10_Structure.pdf](files/PC67-10_Structure.pdf)

เอกสารนี้จะเป็นการสอนเกี่ยวกับโครงสร้างข้อมูล (Structure) ในภาษา C อย่างละเอียด
โดยจะครอบคลุมตั้งแต่พื้นฐานไปจนถึงตัวอย่างการใช้งานจริง

**สารบัญ**

1. ความสำคัญของการใช้งานตัวแปรชนิดโครงสร้าง
2. โครงสร้างข้อมูล (Structure)
3. รูปแบบการประกาศโครงสร้างข้อมูล
4. การอ้างอิงข้อมูลในตัวแปรชนิดโครงสร้าง
5. การกำหนดค่าข้อมูลให้ตัวแปรชนิดโครงสร้าง
6. การกำหนดค่าเริ่มต้นให้แก่โครงสร้าง
7. อาร์เรย์ของตัวแปรชนิดโครงสร้าง (Array of Structure)
8. โครงสร้างซ้อนโครงสร้าง (Nested Structure)
9. ตัวอย่างแบบฝึกหัด

---

### 1. ความสำคัญของการใช้งานตัวแปรชนิดโครงสร้าง

ในภาษา C นั้น ตัวแปรชนิดโครงสร้างมีประโยชน์อย่างมากเมื่อเราต้องการจัดกลุ่มข้อมูลที่เกี่ยวข้องกันเข้าด้วยกัน เช่น
ข้อมูลของนักเรียน (ชื่อ นามสกุล อายุ) หรือ ข้อมูลสินค้า (ชื่อ ราคา จำนวน)

ยกตัวอย่างเช่น หากเราต้องการจัดเก็บข้อมูลของตัวละครในเกม ซึ่งประกอบด้วย

* ชื่อ (name)
* นามสกุล (surname)
* อายุ (age)
* วันเกิด/เดือนเกิด (b_date/b_month)
* เพศ (gender)
* ส่วนสูง (height)
* น้ำหนัก (weight)
* กรุ๊ปเลือด (blood)

ถ้าเราไม่ใช้โครงสร้างข้อมูล เราจำเป็นต้องประกาศตัวแปรมากมายดังนี้

```c
char character1_name[20],character2_name[20],character3_name[20];
char character1_surname[20],character2_surname[20],character3_surname[20];
int character1_age, character2_age, character3_age;
// และตัวแปรอื่น ๆ อีกมากมาย
```

จะเห็นได้ว่า การประกาศตัวแปรแบบนี้ทำให้โค้ดยาว และจัดการยาก

ดังนั้น โครงสร้างข้อมูลจึงถูกสร้างขึ้นเพื่อจัดกลุ่มข้อมูลเหล่านี้ให้อยู่ในรูปแบบที่เข้าใจง่าย
และสามารถเรียกใช้งานได้สะดวก

### 2. โครงสร้างข้อมูล (Structure)

**โครงสร้างข้อมูล (Structure)** ช่วยให้เรานิยามตัวแปรชนิดใหม่ โดยนำตัวแปรพื้นฐาน (เช่น int, float, char)
มารวมกันเป็นโครงสร้างใหม่ได้ เช่น

```c
struct student {
   char name[50];
   char surname[50];
   int age;
   char gender[10];
   char room[10];
};

struct product {
    char name[50];
    int count;
    float price;
};
```

ในตัวอย่างข้างต้น เราได้นิยามโครงสร้าง `student` สำหรับเก็บข้อมูลนักเรียน และโครงสร้าง `product` สำหรับเก็บข้อมูลสินค้า

### 3. รูปแบบการประกาศโครงสร้างข้อมูล

เราสามารถประกาศโครงสร้างข้อมูลได้ 2 รูปแบบ ดังนี้

**รูปแบบที่ 1:** ประกาศโครงสร้างข้อมูลก่อน แล้วค่อยประกาศตัวแปรทีหลัง

```c
struct str_name {
   type memvar_1;
   type memvar_2;
   ...
   type memvar_n;
};
struct str_name struct_var;  // ประกาศตัวแปร struct_var
```

**รูปแบบที่ 2:** ประกาศโครงสร้างข้อมูลพร้อมกับประกาศตัวแปร

```c
struct str_name{
   type memvar_1;
   type memvar_2;
   ...
   type memvar_n;
} struct_var;  // ประกาศตัวแปร struct_var พร้อมกัน
```

ตัวอย่างการประกาศโครงสร้าง `student` โดยใช้ทั้งสองแบบ

**แบบที่ 1:**

```c
struct student {
   char name[15];
   char surname[30];
   int age;
   char gender[7];
};

struct student st1, st2; 
```

ในตัวอย่างนี้ เราได้นิยามโครงสร้าง `student` ก่อน จากนั้นจึงประกาศตัวแปร `st1` และ `st2` ซึ่งเป็นตัวแปรชนิด `student`

**แบบที่ 2:**

```c
struct student {
   char name[15];
   char surname[30];
   int age;
   char gender[7];
} st1, st2; 
```

ในตัวอย่างนี้ เราได้นิยามโครงสร้าง `student` และประกาศตัวแปร `st1` และ `st2` ไปพร้อมกัน

### 4. การอ้างอิงข้อมูลในตัวแปรชนิดโครงสร้าง

เราสามารถเข้าถึงข้อมูลในตัวแปรชนิดโครงสร้างได้โดยใช้ตัวดำเนินการ `.`  ดังนี้

```
struct_var.member_var
```

* `struct_var`  คือ ชื่อตัวแปรชนิดโครงสร้าง
* `member_var` คือ ชื่อสมาชิกในตัวแปรชนิดโครงสร้าง

**ตัวอย่าง**:

```c
struct product pr1, pr2;

strcpy(pr1.name, "Mouse"); // กำหนดค่าให้ pr1.name
pr2.count = 5;   // กำหนดค่าให้ pr2.count
```

### 5. การกำหนดค่าข้อมูลให้ตัวแปรชนิดโครงสร้าง

การกำหนดค่าข้อมูลให้กับตัวแปรชนิดโครงสร้างนั้น จะใช้หลักการเดียวกับการกำหนดค่าให้กับตัวแปรทั่วไป
แต่จะต้องอ้างอิงถึงสมาชิกของโครงสร้างโดยใช้ตัวดำเนินการ `.`

**ตัวอย่าง**:

```c
#include<stdio.h>

struct income{
   float salary;
   float bonus;
   int age;
};

int main() {
  struct income people1; 

  people1.salary = 16000;  // กำหนดค่า salary ในโครงสร้าง people1
  people1.bonus = 40000;   // กำหนดค่า bonus ในโครงสร้าง people1
  people1.age = 23;       // กำหนดค่า age ในโครงสร้าง people1

  return 0;
}
```

### 6. การกำหนดค่าเริ่มต้นให้แก่โครงสร้าง

การกำหนดค่าเริ่มต้นให้กับตัวแปรชนิดโครงสร้าง ทำได้โดยกำหนดค่าตามลำดับของสมาชิกภายในโครงสร้างที่ประกาศไว้

**ตัวอย่าง**:

```c
struct book {
  char name[50];
  float price;
} b1 = {"Harry Potter", 250},
  b2 = {"Lord of the Rings", 300};
```

ในตัวอย่างนี้ `b1` และ `b2` จะถูกกำหนดค่าเริ่มต้นตามลำดับดังนี้

* `b1.name` = "Harry Potter"
* `b1.price` = 250
* `b2.name` = "Lord of the Rings"
* `b2.price` = 300

### 7. อาร์เรย์ของตัวแปรชนิดโครงสร้าง (Array of Structure)

ในบางครั้ง เราอาจต้องการสร้างตัวแปรชนิดโครงสร้างที่เหมือนกันหลายๆ ตัวพร้อมกัน เช่น เราต้องการเก็บข้อมูลนักเรียน 10 คน
เราสามารถทำได้โดยใช้อาร์เรย์ร่วมกับโครงสร้าง เรียกว่า "Array of Structure"

**ตัวอย่าง**:

```c
struct profile {
    char name[50];
    int age;
    float gpa;
};

struct profile student[10]; 
```

ในตัวอย่างข้างต้น `student` จะกลายเป็นอาร์เรย์ของโครงสร้าง `profile` ขนาด 10 ช่อง โดยแต่ละช่องจะเก็บข้อมูลของนักเรียน 1
คน

การเข้าถึงสมาชิกของโครงสร้างในอาร์เรย์ สามารถทำได้โดยใช้เครื่องหมาย `[]`
เช่น  `student[0].name` หมายถึง ชื่อของนักเรียนคนแรกในอาร์เรย์  `student`

**ตัวอย่าง**:

```c
#include<stdio.h>

struct profile{
    char name[20];
    int age;
    char grade;
};

int main() {
   struct profile student[3]; 

   strcpy(student[0].name, "John");
   student[0].age = 18;
   student[0].grade = 'A';

   printf("Name: %s\n", student[0].name);
   printf("Age: %d\n", student[0].age);
   printf("Grade: %c\n", student[0].grade);

   return 0;
}
```

### 8. โครงสร้างซ้อนโครงสร้าง (Nested Structure)

ภาษา C อนุญาตให้สร้าง "Nested Structure" ซึ่งเป็นโครงสร้างข้อมูลที่อยู่ภายในโครงสร้างข้อมูลอีกทีหนึ่ง

**ตัวอย่าง**:

```c
struct address{
  int house_no;
  char street[50];
  char city[50];
};

struct employee {
   char name[50];
   struct address addr; // โครงสร้าง address ภายใน employee 
   float salary;
};
```

ในตัวอย่างนี้ โครงสร้าง `address`  ถูกประกาศซ้อนอยู่ภายในโครงสร้าง `employee`  เราสามารถเข้าถึงข้อมูลใน  `address`
ของพนักงานได้โดยใช้ตัวดำเนินการ `.` สองครั้ง

**ตัวอย่าง**:

```c
struct employee emp1;

strcpy(emp1.addr.city, "Bangkok"); // กำหนดค่า city ใน address ของ emp1

printf("City: %s\n", emp1.addr.city);  // แสดงค่า city ของ emp1 
```

### 9. ตัวอย่างแบบฝึกหัด

**โจทย์**: เขียนโปรแกรมรับข้อมูลรายการหนังสือ โดยจะระบุ ID หนังสือ, ชื่อหนังสือ, ราคาหนังสือ และชื่อผู้แต่งตามลำดับ
จากนั้นให้ผู้ใช้ป้อนชื่อหนังสือที่ต้องการซื้อ จบการซื้อด้วยคำว่า "End"
และให้แสดงผลลัพธ์เป็นรายการหนังสือที่ซื้อพร้อมราคาสุทธิหลังหักส่วนลด 20% ถ้าไม่มีการซื้อหนังสือใด ๆ ให้แสดงผลว่า "none"

**ตัวอย่าง Input/Output**:

**Input**:

```
2
B0001 Math 50 Panwit
B0002 PSIT 45 Chotipat
Math
End
```

**Output**:

```
B0001 Math 40.00 Baht
```

**Input**:

```
3
B0001 Compro 120 Panwit
B0002 Multi 500 Supawan
B0003 Comor 75 Anantapat
Multi
End
```

**Output**:

```
B0002 Multi 400.00 Baht
```

**Input**:

```
0
End
```

**Output**:

```
none
```

**แนวทางการเขียนโปรแกรม:**

1. ประกาศโครงสร้าง `book` เพื่อเก็บข้อมูล ID หนังสือ, ชื่อหนังสือ, ราคาหนังสือ และชื่อผู้แต่ง
2. สร้างอาร์เรย์ของ `book` เพื่อเก็บข้อมูลหนังสือหลายๆ เล่ม
3. รับข้อมูลรายละเอียดหนังสือจากผู้ใช้
4. รับชื่อหนังสือที่ผู้ใช้ต้องการซื้อ และวนรับไปเรื่อย ๆ จนกว่าผู้ใช้จะป้อนคำว่า "End"
5. ตรวจสอบว่ามีการซื้อหนังสือหรือไม่ ถ้ามี แสดงรายการหนังสือที่ซื้อพร้อมราคาหลังหักส่วนลด 20% ถ้าไม่มี ให้แสดงผลว่า "
   none"

**โค้ดโปรแกรม**:

```c
#include <stdio.h>
#include <string.h>

struct book {
    char id[10];
    char name[50];
    float price;
    char author[50];
};

int main() {
    int n, i, j, found;
    char buy_book[50]; 

    printf("Enter number of books: ");
    scanf("%d", &n);

    struct book books[n];

    // รับข้อมูลหนังสือ
    for (i = 0; i < n; i++) {
        printf("Book %d:\n", i + 1);
        printf("\tID: ");
        scanf("%s", books[i].id);
        printf("\tName: ");
        scanf(" %[^\n]", books[i].name); 
        printf("\tPrice: ");
        scanf("%f", &books[i].price);
        printf("\tAuthor: ");
        scanf(" %[^\n]", books[i].author); 
    }

    // รับชื่อหนังสือที่ต้องการซื้อ
    printf("Enter book name to buy (End to finish): ");
    scanf(" %[^\n]", buy_book); 

    found = 0;
    while (strcmp(buy_book, "End") != 0) {
        for (i = 0; i < n; i++) {
            if (strcmp(books[i].name, buy_book) == 0) {
                printf("%s %.2f Baht\n", books[i].id, books[i].price * 0.8); 
                found = 1;
                break;
            }
        }

        printf("Enter book name to buy (End to finish): ");
        scanf(" %[^\n]", buy_book); 
    }
   
   if (found==0){
    printf("none\n"); 
   }

    return 0;
}
```

## สรุป

บทเรียนนี้ได้สอนเกี่ยวกับพื้นฐานการใช้งานโครงสร้างข้อมูลในภาษา C
ซึ่งเป็นเครื่องมือสำคัญที่ช่วยให้โปรแกรมเมอร์สามารถเขียนโปรแกรมได้อย่างมีประสิทธิภาพมากยิ่งขึ้น โครงสร้างข้อมูล
ช่วยให้สามารถจัดเก็บข้อมูลที่ซับซ้อน และสามารถนำไปประมวลผลได้ง่ายขึ้น
และยังสามารถนำไปประยุกต์ใช้ในการพัฒนาโปรแกรมในระดับที่สูงขึ้นต่อไป