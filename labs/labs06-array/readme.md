# Arrays in C: A Beginner's Guide

Arrays are fundamental data structures in C, used to store collections of elements of the same data type. This tutorial
will guide you through the basics of using arrays in C.

## Labs Tutorial

- [Array-Tutorial.md](array-tutorial.md)
- [(Slide) Lab06 - Array.pdf](files/Lab06%20-%20Array.pdf)

### 1. Declaring an Array

Before using an array, you need to declare it. The syntax is as follows:

```c
data_type array_name[array_size];
```

* `data_type` specifies the type of data the array will store (e.g., `int`, `float`, `char`).
* `array_name` is the name you give your array.
* `array_size` is the number of elements the array can hold.

**Example:**

```c
int numbers[5]; // Declares an integer array called 'numbers' with a size of 5
```

### 2. Initializing an Array

You can initialize an array during declaration. There are two ways:

* **Explicit Initialization:**

```c
int numbers[5] = {10, 20, 30, 40, 50}; // Initializes with specific values
```

* **Partial Initialization:**

```c
int numbers[5] = {10, 20, 30}; // Initializes the first three elements, others are set to 0 by default
```

### 3. Accessing Array Elements

Individual elements of an array are accessed using their **index**, starting from 0.

```c
int numbers[5] = {10, 20, 30, 40, 50};
printf("%d\n", numbers[0]); // Output: 10
printf("%d\n", numbers[2]); // Output: 30
```

**Important Note:** Accessing elements outside the array's bounds can lead to undefined behavior.

### 4. Traversing an Array

You can iterate through all elements of an array using a `for` loop:

```c
int numbers[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < 5; i++) {
    printf("%d ", numbers[i]); // Outputs: 10 20 30 40 50
}
```

### 5. Multi-Dimensional Arrays

Arrays can have multiple dimensions. They are often used to represent matrices or tables.

**Example:**

```c
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

This declares a 2x3 matrix. Accessing elements is similar, using multiple indices:

```c
printf("%d\n", matrix[0][1]); // Output: 2
```

### 6. Passing Arrays to Functions

Arrays can be passed to functions. However, they are passed by reference, which means changes made inside the function
will affect the original array.

```c
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    printArray(numbers, 5); // Outputs: 10 20 30 40 50
    return 0;
}
```

## C Arrays: Working with Different Data Types

Arrays in C are versatile, allowing you to store collections of various data types. This tutorial will explore how to
use arrays with `int`, `long`, `float`, `double`, `char`, and `unsigned` types.

### 1. Integer Arrays (`int`)

Integer arrays store collections of whole numbers.

```c
// Declaring an integer array
int ages[5]; 

// Initializing with values
int ages[5] = {25, 30, 22, 18, 27};

// Accessing elements
int firstAge = ages[0]; // firstAge will be 25

// Assigning values
ages[2] = 28;
```

### 2. Long Integer Arrays (`long`)

`long` arrays store larger whole numbers than `int`.

```c
// Declaring a long integer array
long population[10];

// Initializing
long population[10] = {1000000, 1500000, 2000000}; 

// Accessing
long thirdPopulation = population[2];
```

### 3. Floating-Point Arrays (`float` and `double`)

Floating-point arrays store numbers with decimal points. `float` uses less memory, but `double` provides greater
precision.

```c
// Declaring a float array
float prices[3];

// Initializing
float prices[3] = {19.99, 24.95, 12.50};

// Accessing
float secondPrice = prices[1];

// Declaring a double array
double distances[5];
```

### 4. Character Arrays (`char`)

Character arrays are used to store strings. Each element holds a single character.

```c
// Declaring a character array
char name[10];

// Initializing with a string
char name[10] = "John Doe";

// Accessing individual characters
char firstLetter = name[0]; // firstLetter will be 'J'

// String concatenation using array
char greeting[20] = "Hello, ";
strcat(greeting, name); // greeting will be "Hello, John Doe"
```

### 5. Unsigned Integer Arrays (`unsigned`)

`unsigned` arrays store non-negative integer values. They use the same memory space as signed integers but can represent
larger positive numbers.

```c
// Declaring an unsigned integer array
unsigned int counters[10];

// Initializing
unsigned int counters[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// Accessing
unsigned int secondCounter = counters[1]; 
```
