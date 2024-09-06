## Structs in C: Your Guide to Custom Data Structures

This tutorial introduces you to `struct`, a powerful tool in C for organizing your data effectively.

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
  int age;
  int id;
};
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

### Working with `struct`s

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

### Key Takeaways

- **Organization:** `struct`s group related data, making your code clearer and easier to manage.
- **Custom Data Types:** Create your own data types to model real-world entities or concepts in your programs.
- **Flexibility:** Combine different data types within a `struct` for versatile data representation.

This tutorial is an introduction to `struct`s in C. They can be used in more complex ways, including nested structures,
arrays of structures, and pointers to structures. Happy coding!

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

- **`*` (Asterisk):**
    - **Dereference operator:**  It accesses the value stored at the memory address held by a pointer.
    - **Usage:**  Used with pointers to access the variable they point to.
    - **Example:**
        ```c
        int x = 10;
        int *ptr = &x;
        printf("%d\n", *ptr); // Output: 10 (accessing the value of x)
        ```

- **`->` (Arrow operator):**
    - **Member access operator (for pointers to structs):**  Combines dereferencing and member access in a single
      operation.
    - **Usage:**  Specifically designed to access members of a `struct` through a pointer to that `struct`.
    - **Example:**
        ```c
        struct Product milk = {"Milk", 3.99};
        struct Product *ptr = &milk;
        printf("%s\n", ptr->name); // Output: Milk 
        ```

**In essence:**

- Use `*` to dereference a pointer and get the value it points to (regardless of the data type).
- Use `->` specifically to access members of a `struct` using a pointer to that `struct`.

Think of `->` as a shorthand for:  `(*ptr).member` (where `ptr` is your pointer and `member` is the struct member you
want to access).

### The difference between `.` and `->` in struct

- **`milk.price`**
    - **Direct member access:** Used when `milk` is a `struct` variable, not a pointer.
    - **Accesses the `price` member directly within the `milk` struct.**

- **`milk->price`**
    - **Member access through pointer:** Used when `milk` is a *pointer* to a `struct`.
    - **Dereferences the pointer `milk` and then accesses the `price` member of the struct it points to.**

**In short:**

- Use `.` when you have a struct variable.
- Use `->` when you have a pointer to a struct.

### Dynamic Memory Allocation with `struct`s

You can dynamically allocate memory for `struct`s using `malloc`:

```c
struct Product *new_product = malloc(sizeof(struct Product));

if (new_product == NULL) {
  // Handle memory allocation error
} else {
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

**Example (Passing by Reference):**

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

### Benefits of Using Pointers with `struct`s

- **Efficient Data Modification:**  Modify `struct`s directly within functions without copying the entire `struct`.
- **Dynamic Memory Allocation:** Create `struct`s dynamically as needed.
- **Data Structures:** Pointers to `struct`s are essential for building complex data structures like linked lists,
  trees, and graphs.

**Remember:** When working with dynamically allocated memory, always free it using `free()` to avoid memory leaks. 

