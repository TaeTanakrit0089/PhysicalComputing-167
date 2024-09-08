## การบ้านเรื่อง Linked List

การบ้านนี้ประกอบด้วย 4 ข้อ โดยแต่ละข้อจะต่อยอดจากข้อก่อนหน้า โปรดเก็บโค้ดจากข้อก่อนหน้าไว้ใช้ในข้อถัดไป

### ข้อ 1: Create DataNode

**คำอธิบาย:**

ในข้อนี้ ให้เขียนโปรแกรมเพื่อสร้าง DataNode ซึ่งเป็นส่วนประกอบพื้นฐานของ Singly Linked List
โครงสร้างข้อมูลชนิดนี้มีลักษณะเป็นสายโซ่ของโหนดที่เชื่อมต่อกันในทิศทางเดียว
โดยแต่ละโหนดจะเก็บข้อมูลและหมายเลขอ้างอิงไปยังโหนดถัดไป

**คุณลักษณะของ DataNode:**

* **`data`:**  ข้อมูลของโหนด (เก็บข้อมูลเป็น String ความยาวไม่เกิน 100 ตัว)
    * รับค่าข้อมูลผ่านฟังก์ชัน `createDataNode(char* data)`
* **`next`:** Pointer ชี้ไปที่ Address ของ Node ถัดไป
    * ค่าเริ่มต้นคือ NULL

**ตัวอย่างโค้ด:**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DataNode structure using typedef
typedef struct DataNode {
  char* data;
  struct DataNode* next;
} DataNode;

DataNode* createDataNode(char* data);

// Create a new DataNode
DataNode* createDataNode(char* data) {
  // Allocate memory for the node
  DataNode* newNode = (DataNode*)malloc(sizeof(DataNode));

  // Allocate memory for the string and copy the data
  newNode->data = (char*)malloc(strlen(data) + 1);
  strcpy(newNode->data, data);

  newNode->next = NULL;
  return newNode;
}

int main() {
  char data[101];
  scanf("%[^\n]s", data);

  // Create a new DataNode
  DataNode* pNew = createDataNode(data);

  // Print the data and next pointer
  printf("%s\n", pNew->data);
  printf("%p\n", (void*)pNew->next);

  // Free allocated memory for data
  free(pNew->data);
  free(pNew);
  return 0;
}
```

**หมายเหตุ:**  eJudge ทำงานบน CentOS (Linux distribution (Unix-like OS))  เวลาปริ้น NULL Pointer ออกมาจะแสดงว่า `(nil)`

### ข้อ 2:  Traversal และ Insert Last

**คำอธิบาย:**

ให้สร้างโครงสร้างของ Linked List โดยมีฟังก์ชันสำหรับจัดการ DataNode ดังนี้

* **`traverse(mylist)`:** ท่องเข้าไปใน Linked List และแสดงข้อมูลตามลำดับทั้งหมดใน Linked List
    * เชื่อมต่อกันด้วย `->`  เช่น  `ฉงน -> ละอองดาว`
    * กรณีที่ Linked List ว่าง ให้แสดงข้อความ “This is an empty list.”
* **`insert_last(mylist, data)`:** สร้าง DataNode และแทรกไปที่ส่วนท้ายของ Linked List
    * เช่น  `insert_last(mylist, "สกาวเดือน")`  ผลลัพธ์จะออกมาเป็น  `traverse(mylist) = ฉงน -> ละอองดาว -> สกาวเดือน`

**คุณลักษณะของ LinkedList:**

* **`count`:**  จำนวนโหนดใน Linked List มีค่าเริ่มต้นเป็น 0 และอัปเดตทุกครั้งที่มีการเพิ่มหรือลบโหนด
* **`head`:** หมายเลขอ้างอิงถึงโหนดแรกสุด (Head Node)  เริ่มต้นจะไม่มีข้อมูลอ้างอิง

**ตัวอย่างโค้ด:**

```c
// SinglyLinkedList structure using typedef
typedef struct SinglyLinkedList {
  unsigned int count;
  DataNode* head;
} SinglyLinkedList;

// Function prototypes
DataNode *createDataNode(char *data);
SinglyLinkedList *createSinglyLinkedList();
void traverse(SinglyLinkedList *list);
void insert_last(SinglyLinkedList *list, char *data);

int main() {
    // ...  โค้ดสำหรับรันเทสเคส
}

// Create a new SinglyLinkedList
SinglyLinkedList* createSinglyLinkedList() {
    // ... โค้ดสำหรับสร้าง SinglyLinkedList
}

// Traverse the list and print data
void traverse(SinglyLinkedList* list) {
    if (list->count == 0) {
        printf("This is an empty list.\n");
        return;
    }
    struct DataNode* pointer = list->head;
    while (pointer->next != NULL) {
        // ปริ้นข้อมูลและขยับ pointer ไปเรื่อยๆ จนถึงโหนดตัวสุดท้าย
    }
    printf("%s\n", pointer->data);
}

// Insert a new node at the end of the list
void insert_last(SinglyLinkedList* list, char* data) {
    struct DataNode* pNew = createDataNode(data);
    if (list->count == 0) {
        // ... ถ้า Linked List ว่างให้เปลี่ยนตำแหน่ง list->head ไปที่ pNew
    } else {
        // ... ถ้า Linked List ไม่ว่างให้สร้าง Pointer ตัวใหม่และขยับไปที่โหนดสุดท้ายและเปลี่ยน pointer->next เป็น pNew
    }
    list->count++;
}
```

### ข้อ 3:  Insert Front

**คำอธิบาย:**

ให้เพิ่มฟังก์ชัน `insert_front` เข้าไปในโค้ดจากข้อ 2

* **`insert_front(mylist, data)`:** สร้าง DataNode และแทรกไปที่ส่วนหน้าของ Linked List
    * เช่น `insert_front(mylist, "สกาวเดือน")`  ผลลัพธ์จะออกมาเป็น  `traverse(mylist) = สกาวเดือน -> ฉงน -> ละอองดาว`

**ตัวอย่างโค้ด:**

```c
// ...  โค้ดจากข้อที่แล้ว
void insert_front(SinglyLinkedList* list, char* data); // <-- สร้างตัวนี้

int main() {
    // ...  โค้ดสำหรับรันเทสเคส
}

// ...  โค้ดจากข้อที่แล้ว

void insert_front(SinglyLinkedList* list, char* data) {
    DataNode* pNew = createDataNode(data);
    if (list->count == 0) {
        // ...  ถ้า Linked List ว่างให้เปลี่ยนตำแหน่ง list->head ไปที่ pNew
    } else {
        // ...  เปลี่ยนตำแหน่งของ pNew.next ไปที่โหนดตัวแรกสุดและเปลี่ยนตำแหน่ง head node ไปที่ pNew
    }
    list->count++;
}
```

### ข้อ 4:  Delete

**คำอธิบาย:**

ให้เพิ่มเมธอด `delete` เข้าไปในคลาสที่คุณเขียนจากข้อก่อนหน้า

* **`delete(mylist, data)`:** ลบ DataNode ออกจาก Linked List
    * กรณีที่ไม่มีโหนดใน Linked List ให้แสดงข้อความ “Cannot delete, <data> does not exist.”
    * เช่น  `delete(mylist, "ฉงน")`  ผลลัพธ์จะออกมาเป็น  `traverse(mylist) = ละอองดาว`

**ตัวอย่างโค้ด:**

```c
DataNode* createDataNode(char* data);
SinglyLinkedList* createSinglyLinkedList();
void traverse(SinglyLinkedList* list);
void insert_last(SinglyLinkedList* list, char* data);
void insert_front(SinglyLinkedList* list, char* data);
void delete(SinglyLinkedList* list, char* data); // <-- สร้างตัวนี้
```

**ให้นำโค้ดนี้ไปใช้รันเทสเคส:**

```c
int main() {
    SinglyLinkedList* mylist = createSinglyLinkedList();
    int n;
    char condition;
    char data[100]; // Assuming a maximum string length of 99 characters
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c: %[^\n]s", &condition, data); // Read condition and string data

        if (condition == 'F') {
            insert_front(mylist, data);
        } else if (condition == 'L') {
            insert_last(mylist, data);
        } else if (condition == 'D') {
            delete(mylist, data);
        } else {
            printf("Invalid Condition!\n");
        }
    }

    traverse(mylist);
    // Remember to free allocated memory for each node's data
    DataNode* current = mylist->head;
    while (current != NULL) {
        free(current->data);
        DataNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(mylist);
    return 0;
}
```

**หมายเหตุ:**

* โปรดตรวจสอบโค้ดในส่วนที่ต้องเติมให้ครบถ้วน
* อย่าลืมจัดการหน่วยความจำอย่างเหมาะสมโดยการใช้ `malloc` และ `free`
* ส่งโค้ดผ่าน eJudge เพื่อตรวจสอบความถูกต้อง