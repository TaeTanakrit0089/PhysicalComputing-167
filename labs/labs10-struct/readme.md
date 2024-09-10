## Lab 10: C Struct

This tutorial introduces you to `struct`, a powerful tool in C for organizing your data effectively.

### More Informations:

- [Lab09 Recap](recap_week09.md)
- [Lecture Slides](lecture-slide.md)
- [Linked List (Recap)](linked-list-recap.md)
- [Linked List (Lab)](linked-list.md)

### What is a `struct`?

Imagine needing to store information about a student, including their name, age, and student ID. Using separate
variables for each piece of information can get messy:

```c
char student_name[50];
int student_age;
int student_id;
```

A `struct` lets you group these related variables under a single name:

```c
struct Student {
  char name[50];
  unsigned int id;
  float gpa;
};

struct Student student01 = {"Mr.ARNUPHAP MONGKOLSUKTAVI", 66070224, 3.50};
struct Student student02 = {"Mr.PANAVAT THAMCHAROEN", 66070113, 3.63};
struct Student student03 = {"Miss.SONRASAMON MEEPASEE", 66070200, 3.75};

printf("%s %d %f\n", student01.name, student01.id, student01.gpa);
printf("%s %d %f\n", student02.name, student02.id, student02.gpa);
printf("%s %d %f\n", student03.name, student03.id, student03.gpa);
```

Imagine without struct

```c
char name1[50] = "Mr.ARNUPHAP MONGKOLSUKTAVI";
unsigned int id1 = 66070224;
float gpa1 = 3.50;

char name2[50] = "Mr.PANAVAT THAMCHAROEN";
unsigned int id2 = 66070113;
float gpa2 = 3.63;

char name3[50] = "Miss.SONRASAMON MEEPASEE";
unsigned int id3 = 66070200;
float gpa3 = 3.75;

printf("%s %d %f\n", name1, id1, gpa1);
printf("%s %d %f\n", name2, id2, gpa2);
printf("%s %d %f\n", name3, id3, gpa3);
```

Now, `Student` is a new data type representing a student's information.

### Defining a `struct`

The general syntax is:

```c
struct struct_name {
  data_type member1;
  data_type member2;
  // ... more members
};
```

- **`struct`**: Keyword to define a structure.
- **`struct_name`**:  The name you choose for your new data type (e.g., `Student`, `Car`, `Point`).
- **`data_type`**:  Types of the members (e.g., `int`, `char`, `float`, arrays, even other structs).
- **`member1`, `member2`**:  Names of the members within the struct.

**Example:**

```c
struct Product {
  char name[50];
  float price;
  int quantity;
};
```

This defines a `struct` named `Product` with members for a product's `name`, `price`, and `quantity`.

### Declaring `struct` Variables

After defining a `struct`, you can declare variables of that type:

```c
struct Product milk;       // Declare a variable 'milk' of type 'struct Product'
struct Product bread;      // Declare another variable 'bread'
```

### Accessing `struct` Members

Use the dot operator (`.`) to access individual members:

```c
strcpy(milk.name, "Milk"); // Use strcpy for strings
milk.price = 3.99;
milk.quantity = 2;
```

### Initialization

You can initialize a `struct` during declaration:

```c
struct Product cheese = {"Cheese", 4.99, 1};
```

### Working with `struct`

Here's a complete example demonstrating how to define, declare, access, and work with `struct`s:

```c
#include <stdio.h>
#include <string.h>

struct Book {
  char title[50];
  char author[50];
  int year;
};

int main() {
  struct Book book1; 
  strcpy(book1.title, "The Lord of the Rings");
  strcpy(book1.author, "J.R.R. Tolkien");
  book1.year = 1954;

  printf("Book Title: %s\n", book1.title);
  printf("Author: %s\n", book1.author);
  printf("Year Published: %d\n", book1.year);

  return 0;
}
```

It's easy to get confused between structs and objects, especially if you're new to programming! They seem similar at
first, but there's a key difference. Here's a simplified explanation tailored for students:

**Structs:  The Basics**

* Think of a struct as a **blueprint** to create custom data types. It lets you group different variables (like `name`,
  `age`, `grade`) under a single name (like `Student`).
* **Focus on data:** Structs mainly focus on storing and organizing data.
* **Example:** Imagine a physical form with labeled boxes for "Name", "Age", and "Grade". A struct is like that form –
  it just holds the information.

**Objects: Taking Structs Further**

* Objects are built upon the idea of structs, but they add more capabilities.
* **Data AND Actions:** Objects not only store data (like structs) but also have **functions (called methods) that can
  directly act on that data**.
* **Example:** Instead of just a form, think of an object as an actual student who can fill out their own form (
  `writeName()`, `calculateAge()`, `getGrade()`), answer questions about their information, etc.

**In Simple Terms**

* **Struct:** A container to hold related pieces of data.
* **Object:** A more advanced container that holds data AND has actions it can perform on that data.

**Important Note:** C primarily uses structs. The concept of objects as described above is more central to
object-oriented programming languages like C++, Java, and Python.

---

## Structs and Pointers in C: A Powerful Combination

Combining `struct`s with pointers unlocks greater flexibility and efficiency in your C programs. Let's explore how to
use them together.

### Pointers to `struct`

You can declare a pointer to a `struct` just like you would with any other data type:

```c
struct Product {
  char name[50];
  float price;
  int quantity;
};

struct Product *ptr_product; // Declare a pointer named 'ptr_product'
```

Here, `ptr_product` is a pointer that can store the memory address of a `struct Product`.

### Accessing Members with Pointers

To access members of a `struct` using a pointer, use the arrow operator (`->`):

```c
struct Product milk = {"Milk", 3.99, 2};
ptr_product = &milk; // Assign the address of 'milk' to the pointer

printf("Product Name: %s\n", ptr_product->name); 
printf("Price: %.2f\n", ptr_product->price);
```

The `->` operator dereferences the pointer (accesses the value at the memory location) and then accesses the member.

### C Struct Member Access

Assuming that we have declare `juice` as a variable struct and `ptr_product` is a pointer.

```c
struct Product {
    char name[50];
    double price;
    int quantity;
};

struct Product juice = {"Orange Juice", 2.49, 5};
struct Product *ptr_product = &juice;
```

`juice` is a Product struct, and `ptr_product` is a pointer that holds the memory address of `juice`. To access the
members (
name, price, quantity) of the juice struct, you have three main operators:

**1. The Dot Operator (`.`)**

* **Purpose:** Used to access members of a struct directly when you have the struct variable itself.
* **Syntax:**  `struct_variable.member_name`
* **Example:**
  ```c
  printf("Product Name: %s\n", juice.name); 
  printf("Quantity: %d\n", juice.quantity);
  ```
* **Key Point:**  The dot operator assumes you are working with the actual struct variable, not a pointer to it.

**2. The Asterisk Operator (*)**

* **Purpose:**
    * **Dereference Operator:** When used with a pointer, it accesses the value stored at the memory location the
      pointer points to.
* **Syntax:** `*pointer_variable`
* **Example (Dereferencing):**
    - Create a pointer name `ptr_product`:
  ```c
  struct Product current_product = *ptr_product;  // Dereference to get the struct
  printf("Price: %.2f\n", current_product.price); // Now use '.'
  
  // or
  
  printf("Price: %.2f\n", *(ptr_product).price);
  ```
* **Key Point:** Dereferencing a pointer to a struct gives you a copy of the struct data. Changes made to this copy
  won't affect the original struct.

**3. The Arrow Operator (`->`)**

* **Purpose:**  Provides a concise way to access members of a struct through a pointer.
* **Syntax:**  `pointer_to_struct->member_name`
* **Example:**
  ```c
  struct Product *ptr_product = &juice;
  
  printf("Product Name: %s\n", ptr_product->name);
  ptr_product->quantity -= 1; // Modify the original struct directly 
  ```
* **Key Point:** The arrow operator combines dereferencing and member access in one step. It directly modifies the
  original struct.
* Think of `->` as a shorthand for:  `(*ptr).member` (where `ptr` is your pointer and `member` is the struct member you
  want to access).

**In Essence:**

* Use `.` when you have the struct variable itself.
* Use `*` to dereference a pointer to get the struct data (creates a copy).
* Use `->` to access members of a struct through a pointer (modifies the original).

---

## Dynamic Memory Allocation with `struct`

You can dynamically allocate memory for `struct`s using `malloc`:

```c
struct Product *new_product = (struct Product*) malloc(sizeof(struct Product));

strcpy(new_product->name, "Bread");
new_product->price = 2.50;
new_product->quantity = 1;

// ... use the 'new_product'

free(new_product); // Remember to free the allocated memory
}
```

This creates a `struct Product` dynamically on the heap, and you can access its members using the pointer `new_product`.

### Passing `struct`s to Functions

- **By Value:**  When you pass a `struct` by value, a copy of the entire `struct` is made. This can be inefficient for
  large `struct`s.
- **By Reference (using pointers):**  Passing a pointer to the `struct` is more efficient, as only the pointer's value (
  the memory address) is copied.

**1. Example (Passing by Reference):**

```c
#include <stdio.h>
#include <string.h>

struct Point {
  int x;
  int y;
};

void move_point(struct Point *p, int dx, int dy) {
  p->x += dx;
  p->y += dy;
}

int main() {
  struct Point p1 = {10, 20};
  move_point(&p1, 5, -3); // Pass the address of 'p1'

  printf("Point: (%d, %d)\n", p1.x, p1.y); 
  return 0;
}
```

**2. Modifying a `struct` Within a Function (By Value vs. By Reference):**

```c
#include <stdio.h>

struct Product {
  char name[50];
  float price;
};

// Pass by value (makes a copy)
void update_price_copy(struct Product prod, float new_price) {
  prod.price = new_price; 
  printf("Inside update_price_copy: %.2f\n", prod.price); 
}

// Pass by reference (using a pointer)
void update_price_ref(struct Product *prod, float new_price) {
  prod->price = new_price; 
  printf("Inside update_price_ref: %.2f\n", prod->price);
}

int main() {
  struct Product item = {"Coffee", 4.99};

  update_price_copy(item, 5.99); 
  printf("After update_price_copy: %.2f\n", item.price); // Price unchanged!

  update_price_ref(&item, 5.99); 
  printf("After update_price_ref: %.2f\n", item.price); // Price updated!

  return 0;
}
```

**Explanation:** `update_price_copy` receives a copy of the `struct`, so the original `item` remains unchanged.
`update_price_ref` receives a pointer, allowing direct modification of the original `item`.

**3. Array of `struct`s and Pointers:**

```c
#include <stdio.h>

struct Student {
  int id;
  char name[50];
};

int main() {
  struct Student students[3] = {
    {101, "Alice"},
    {102, "Bob"},
    {103, "Charlie"}
  };

  struct Student *ptr = students; // Pointer to the first student

  for (int i = 0; i < 3; i++) {
    printf("ID: %d, Name: %s\n", (ptr + i)->id, (ptr + i)->name);
  }

  return 0;
}
```

**Explanation:**  We create an array of `Student` structs. The pointer `ptr` iterates through the array, accessing each
`Student`'s data using pointer arithmetic and the `->` operator.

**4. Linked List (Simple Example):**

```c
#include <stdio.h>
#include <stdlib.h> // For malloc and free

struct Node {
  int data;
  struct Node *next;
};

int main() {
  struct Node *new_node01 = (struct Node*)malloc(sizeof(struct Node));
  new_node01->data = 10;
  new_node01->next = NULL;

  struct Node *new_node02 = (struct Node*)malloc(sizeof(struct Node));
  new_node02->data = 20;
  new_node02->next = NULL;
  new_node01->next = new_node02;

  struct Node *new_node03 = (struct Node*)malloc(sizeof(struct Node));
  new_node03->data = 30;
  new_node03->next = NULL;
  new_node02->next = new_node03;

  struct Node *p_new = new_node01;
  while (p_new != NULL) {
        printf("%d ", p_new->data);
        p_new = p_new->next;
  }
  printf("\n");
  // Free the list
  p_new = new_node01;
  struct Node *next_node;

  while (p_new != NULL) {
        next_node = p_new->next; // Save the next node
        free(p_new); // Free the current node
        p_new = next_node; // Move to the next node
  }
  return 0;
}
```

**Explanation:**  This snippet demonstrates the fundamental building block of a linked list. Each `Node` contains data
and a pointer (`next`) to the next node. Pointers are crucial for connecting nodes in a linked list.

Let me know if you'd like to dive deeper into any of these examples or explore other data structures like trees!

### Benefits of Using Pointers with `struct`s

- **Efficient Data Modification:**  Modify `struct`s directly within functions without copying the entire `struct`.
- **Dynamic Memory Allocation:** Create `struct`s dynamically as needed.
- **Data Structures:** Pointers to `struct`s are essential for building complex data structures like linked lists,
  trees, and graphs.

### Typedef with Structs

You can use `typedef` with `struct` to create more concise type names. This improves code readability and makes it
easier to work with your custom data types.

**Example (Not Using typedef):**

```c
struct Product {
  char name[50];
  float price;
}; 

int main() {
  struct Product item1;  
}
```

**Example (Using typedef):**

```c
typedef struct {
  char name[50];
  float price;
} Product; // Now 'Product' is an alias for the struct

int main() {
  Product item1;  // No need to write 'struct Product'
}
```

**Explanation:**

1. **`typedef struct { ... } Product;`**: This statement combines the `struct` definition with a `typedef`. It creates a
   new type alias `Product` for the `struct`.
2. **`Product item1;`**:  You can now declare variables of type `Product` directly without using the `struct` keyword.

**Benefits of using `typedef` with `struct`s:**

- **Code Readability:** Makes your code cleaner and more concise.
- **Reduced Redundancy:** Avoid repeatedly writing `struct` before the structure name.
- **Easier Maintenance:** If you need to change the `struct` definition later, you only need to modify it in one place (
  the `typedef`).

**Remember:** When working with dynamically allocated memory, always free it using `free()` to avoid memory leaks.

## Struct with Singly Linked List

- [Link List Lab](linked-list.md)

[//]: # (- [Link List Recap]&#40;linked-list-recap.md&#41;)