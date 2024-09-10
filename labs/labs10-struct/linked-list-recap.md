## Introduction to Linear Lists: Arrays and Linked Lists

This recap is created from Data Structures and Algorithms Lecture
Slide: [02_Array and Linkedlist_STD.pdf](files/02_Array%20and%20Linkedlist_STD.pdf)

This document provides a comprehensive tutorial on linear lists, focusing on two primary implementations: arrays and
linked lists.

**Objectives:**

* Understand the concept and functionality of linear lists.
* Apply linear list data structures (arrays and linked lists) in programming.

**Real-world Examples of Linear Lists:**

* **Gaming:** High score tracking, map representation.
* **Operating Systems:** Job scheduling queues.

### Linear Lists: Arrays and Linked Lists

There are two common ways to implement linear lists:

* **Arrays:** Store elements in contiguous memory locations.
* **Linked Lists:** Store elements with pointers connecting them in a sequence.

### Memory Representation

Before diving into arrays and linked lists, let's briefly discuss memory. In a computer, memory is organized like a
giant grid of cells, each with a unique address.

### Arrays

* Arrays allocate a fixed block of contiguous memory locations.
* Accessing elements is fast because their positions are directly calculated from the starting address.
* However, inserting or deleting elements can be inefficient, especially if the array is full.

### Linked Lists

* Linked Lists use nodes, where each node contains:
    * **Data:** The actual value being stored.
    * **Link:** A pointer pointing to the next node in the sequence.

* Linked lists are more flexible for insertion and deletion because elements don't need to be contiguous in memory.
* However, accessing a specific element can be slower because you need to traverse the list from the beginning.

### Static vs. Dynamic Allocation

* **Static Memory Allocation:** Memory for variables is allocated during compilation, and the size is fixed.
* **Dynamic Memory Allocation:** Memory is allocated during program execution (runtime), allowing for flexible size
  adjustments.

    * Linked lists utilize dynamic memory allocation, making them suitable for situations where the data size is unknown
      beforehand.

### Arrays in Detail

* Arrays store elements of the **same data type** in contiguous memory locations.
* Each element can be accessed using its **index**, which starts from 0.

**Example in C:**

```c
int score[5] = {10, 20, 30, 40, 50}; // Array declaration and initialization
```

* `score[0]` would access the first element (10), and `score[4]` would access the last element (50).

### Linked Lists in Detail

Linked lists are built using **nodes**. Each node contains:

* **Data:** The value stored in the node.
* **Link:** A pointer to the next node in the sequence.

**Types of Linked Lists:**

* **Singly Linked List:** Each node points to the next node in one direction only.
* **Doubly Linked List:** Each node has two pointers: one to the next node and one to the previous node.

### Linked List Node Structure

The data stored in a linked list node can be simple or complex:

* **Single Data Field:** E.g., storing only a number.
* **Multiple Data Fields:** E.g., storing name, ID, and grades.
* **Structure with Sub-fields:** E.g., storing a "Person" structure with name, address, and phone number as sub-fields.

### Links and Pointers

* Links in a linked list are implemented using **pointers**.
* A pointer is a variable that stores the **memory address** of another variable.
* In the context of linked lists, the link in a node stores the memory address of the next node in the sequence.

### Creating a Singly Linked List

**1. Define the Node Structure:**

```c
typedef struct DataNode {
  char* data;
  struct DataNode* next;
} DataNode;
```

**2. Create the Head Node:**

* This node usually contains metadata about the list, such as the number of elements.
* Initially, it points to `NULL` as the list is empty.

**3. Add Nodes to the List:**

* Allocate memory for a new node.
* Set the data field of the new node.
* Update the link of the last node to point to the new node.

### Basic Linked List Operations

* **Insertion:** Adding a new node to the list.
* **Deletion:** Removing an existing node from the list.
* **Retrieval:** Accessing the data within a specific node.
* **Traversal:** Iterating through all the nodes in the list.

### Insertion at Different Positions

* **Inserting at the Front:**
    1. Create the new node.
    2. Make the new node's 'next' pointer point to the current head.
    3. Update the head to point to the new node.

* **Inserting at the End:**
    1. Traverse to the last node of the list.
    2. Create the new node.
    3. Make the last node's 'next' pointer point to the new node.

* **Inserting in Sorted Order:**
    1. Traverse the list, comparing the data of the new node with the current node.
    2. When the correct position is found, insert the new node.

### Deletion

1. **Find the Node to Delete:** Traverse the list to find the node with the target data.
2. **Update Links:**
    * If deleting the head, update the head to point to the second node.
    * Otherwise, make the 'next' pointer of the previous node point to the node after the one being deleted.
3. **Deallocate Memory:** Free the memory occupied by the deleted node.

### Traversing a Linked List

To access or process each element in a linked list, you need to traverse it:

1. Start from the head node.
2. Access the data in the current node.
3. Move to the next node using the 'next' pointer.
4. Repeat steps 2-3 until you reach the end of the list (NULL pointer).

### Doubly Linked Lists

In a doubly linked list, each node has two links:

* `next`: Points to the next node in the sequence.
* `back`: Points to the previous node in the sequence.

**Advantages of Doubly Linked Lists:**

* Traversal in both directions.
* Easier deletion (no need to track the previous node separately).

### Operations on Doubly Linked Lists

The principles of insertion and deletion are similar to singly linked lists, but you need to update both the 'next'
and 'back' pointers accordingly.

### Lists in Python

* Python's built-in `list` data type is **not a linked list**.
* It's implemented as a dynamic array, where elements are stored in contiguous memory locations, and their addresses are
  managed by an array of pointers.

[//]: # (### Quiz 1 &#40;Singly Linked List&#41;)

[//]: # ()

[//]: # (Given a singly linked list with `info` and `next` fields, and pointers `p` and `r` pointing to specific nodes, what)

[//]: # (would be the output or effect of the following commands? &#40;Draw the linked list after each command&#41;)

[//]: # ()

[//]: # (```)

[//]: # (r.next.next.info = 23)

[//]: # (p.next.next = r.next.next)

[//]: # (p.next.info = 68)

[//]: # (r.next.next.next = p.next)

[//]: # (p.next = null)

[//]: # (```)

[//]: # ()

[//]: # (### Quiz 2 &#40;Singly Linked List&#41;)

[//]: # ()

[//]: # (Given the modified linked list from Quiz 1 and the following code snippet, what would be the output?)

[//]: # ()

[//]: # (```)

[//]: # (loop &#40;r.next != null&#41;)

[//]: # (    print r.info)

[//]: # (    r = r.next)

[//]: # (end loop )

[//]: # (```)

[//]: # ()

[//]: # (### Quiz 3 &#40;Doubly Linked List&#41;)

[//]: # ()

[//]: # (Given a doubly linked list with `back`, `info`, and `next` fields, and pointers `p` and `r` pointing to specific nodes,)

[//]: # (what would be the effect of the following commands? &#40;Draw the linked list after each command&#41;)

[//]: # ()

[//]: # (```)

[//]: # (r.back.back = p)

[//]: # (r = r.back)

[//]: # (r.back.next.info = 'XXX')

[//]: # (r.back = p.back)

[//]: # (```)

[//]: # ()

[//]: # (### Quiz 4 &#40;Appending Linked Lists&#41;)

[//]: # ()

[//]: # (Design an algorithm called `append&#40;list1, list2&#41;` that takes two linked lists &#40;list1 and list2&#41; as input and appends)

[//]: # (list2 to the end of list1. The algorithm should work for lists of any size and data.)
