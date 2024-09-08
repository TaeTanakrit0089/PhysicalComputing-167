## Physical Computing Labs 10: Linked List

This document provides instructions and code examples for implementing a singly linked list in C.

**Linked List Recap**

* [linked-list-recap.md](linked-list-recap.md)

**Table of Contents**

* [01: Create DataNode](#01-create-datanode)
* [02: Singly Linked List (Traversal and Insert Last)](#02-singly-linked-list-traversal-and-insert-last)
* [03: Singly Linked List (Insert Front)](#03-singly-linked-list-insert-front)
* [04: Singly Linked List (Insert Before)](#04-singly-linked-list-insert-before)
* [05: Singly Linked List (Delete)](#05-singly-linked-list-delete)

### 01: Create DataNode

**Objective:** Implement a `DataNode` class to represent a node in a singly linked list.

**Attributes:**

* `data`: The data stored in the node (integer).
* `next`: A pointer to the next node in the list (DataNode*).

**Example Usage:**

```c
#include <stdio.h>
#include <stdlib.h>

// DataNode structure
struct DataNode {
  char* data;
  struct DataNode* next;
};

// Create a new DataNode
struct DataNode* createDataNode(char* data) {
  struct DataNode* newNode = (struct DataNode*)malloc(sizeof(struct DataNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

int main() {
  // Create a new DataNode
  struct DataNode* pNew = createDataNode("Tawan");

  // Print the data and next pointer
  printf("%s\n", pNew->data); // Output: Tawan
  printf("%p\n", (void*)pNew->next); // Output: NULL (or equivalent)

  return 0;
}
```

### 02: Singly Linked List (Traversal and Insert Last)

**Objective:** Implement a `SinglyLinkedList` class with traversal and insertion at the end functionality.

**Attributes:**

* `count`: Number of nodes in the list (int).
* `head`: Pointer to the first node (DataNode*).

**Methods:**

* `traverse()`: Prints the data of all nodes in the list, separated by "->". If the list is empty, print "This is an
  empty list."
* `insert_last(data)`: Creates a new node with the given data and inserts it at the end of the list.

**Example Usage:**

```c
// ... (DataNode structure and createDataNode function from Lab 05.01)

// SinglyLinkedList structure
struct SinglyLinkedList {
  int count;
  struct DataNode* head;
};

// Create a new SinglyLinkedList
struct SinglyLinkedList* createSinglyLinkedList() {
  struct SinglyLinkedList* newList = (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));
  newList->count = 0;
  newList->head = NULL;
  return newList;
}

// Traverse the list and print data
void traverse(struct SinglyLinkedList* list) {
  if (list->count == 0) {
    printf("This is an empty list.\n");
    return;
  }
  struct DataNode* current = list->head;
  while (current != NULL) {
    printf("%s", current->data);
    if (current->next != NULL) {
      printf(" -> ");
    }
    current = current->next;
  }
  printf("\n");
}

// Insert a new node at the end of the list
void insert_last(struct SinglyLinkedList* list, char* data) {
  struct DataNode* newNode = createDataNode(data);
  if (list->count == 0) {
    list->head = newNode;
  } else {
    struct DataNode* current = list->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
  list->count++;
}

int main() {
  // Create a new SinglyLinkedList
  struct SinglyLinkedList* mylist = createSinglyLinkedList();

  // Insert data
  insert_last(mylist, "Tawan");
  insert_last(mylist, "Sanja");
  insert_last(mylist, "Nados");

  // Traverse the list
  traverse(mylist); // Output: Tawan -> Sanja -> Nados

  return 0;
}
```

### 03: Singly Linked List (Insert Front)

**Objective:** Implement the `insert_front(data)` method in the `SinglyLinkedList` class.

**Functionality:**

* Creates a new node with the given data and inserts it at the beginning of the list.

**Example Usage:**

```c
// ... (previous code from Lab 05.01 and 05.02)

// Insert a new node at the beginning of the list
void insert_front(struct SinglyLinkedList* list, char* data) {
  struct DataNode* newNode = createDataNode(data);
  newNode->next = list->head;
  list->head = newNode;
  list->count++;
}

int main() {
  // ... (previous code from Lab 05.02)

  // Insert data at the front
  insert_front(mylist, "Nados");

  // Traverse the list
  traverse(mylist); // Output: Nados -> Tawan -> Sanja -> Nados

  return 0;
}
```

### .04: Singly Linked List (Insert Before)

**Objective:** Implement the `insert_before(node, data)` method in the `SinglyLinkedList` class.

**Functionality:**

* Creates a new node with the given data and inserts it before the specified node.
* If the specified node is not found, print "Cannot insert, <node> does not exist."

**Example Usage:**

```c
// ... (previous code from Lab 05.01, 05.02, and 05.03)

// Insert a new node before the specified node
void insert_before(struct SinglyLinkedList* list, char* nodeData, char* data) {
  struct DataNode* newNode = createDataNode(data);
  if (list->head == NULL) {
    printf("Cannot insert, %s does not exist.\n", nodeData);
    return;
  }
  if (strcmp(list->head->data, nodeData) == 0) {
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
    return;
  }
  struct DataNode* current = list->head;
  while (current->next != NULL && strcmp(current->next->data, nodeData) != 0) {
    current = current->next;
  }
  if (current->next == NULL) {
    printf("Cannot insert, %s does not exist.\n", nodeData);
    return;
  }
  newNode->next = current->next;
  current->next = newNode;
  list->count++;
}

int main() {
  // ... (previous code from Lab 05.02 and 05.03)

  // Insert data before "Sanja"
  insert_before(mylist, "Sanja", "Nados");

  // Traverse the list
  traverse(mylist); // Output: Tawan -> Nados -> Sanja -> Nados

  return 0;
}
```

### 05: Singly Linked List (Delete)

**Objective:** Implement the `delete(data)` method in the `SinglyLinkedList` class.

**Functionality:**

* Deletes the first occurrence of a node with the given data.
* If the specified data is not found, print "Cannot delete, <data> does not exist."

**Example Usage:**

```c
// ... (previous code from Lab 05.01, 05.02, 05.03, and 05.04)

// Delete the first occurrence of a node with the given data
void delete(struct SinglyLinkedList* list, char* data) {
  if (list->head == NULL) {
    printf("Cannot delete, %s does not exist.\n", data);
    return;
  }
  if (strcmp(list->head->data, data) == 0) {
    struct DataNode* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->count--;
    return;
  }
  struct DataNode* current = list->head;
  while (current->next != NULL && strcmp(current->next->data, data) != 0) {
    current = current->next;
  }
  if (current->next == NULL) {
    printf("Cannot delete, %s does not exist.\n", data);
    return;
  }
  struct DataNode* temp = current->next;
  current->next = current->next->next;
  free(temp);
  list->count--;
}

int main() {
  // ... (previous code from Lab 05.02, 05.03, and 05.04)

  // Delete "Tawan"
  delete(mylist, "Tawan");

  // Traverse the list
  traverse(mylist); // Output: Nados -> Sanja -> Nados

  return 0;
}
```

This document provides a comprehensive guide to implementing a singly linked list in C. Each lab builds upon the
previous one, culminating in a fully functional linked list implementation. Remember to test your code thoroughly after
each step.