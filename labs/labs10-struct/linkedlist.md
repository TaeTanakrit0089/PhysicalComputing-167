## Labs 05-06: Singly Linked List (C Version)

This document is a tutorial for implementing a singly linked list in C. It covers the following topics:

* **Creating a `DataNode` class:** This class represents a single node in the linked list and stores data along with a
  pointer to the next node.
* **Creating a `SinglyLinkedList` class:** This class manages the linked list and provides methods for adding, removing,
  and traversing nodes.

**Note:** This tutorial assumes you have a basic understanding of C programming concepts such as pointers, structs, and
functions.

### 1. DataNode Class

The `DataNode` class represents a single element in the linked list. It holds data and a pointer to the next `DataNode`
in the list.

#### 1.1. DataNode Structure

```c
typedef struct DataNode {
  char *data;
  struct DataNode *next;
} DataNode;
```

This code defines a structure named `DataNode`. It contains:

* `data`: A pointer to a character array (`char *`) to store the node's data.
* `next`: A pointer to the next `DataNode` in the list.

#### 1.2. Creating a New DataNode

```c
DataNode* createDataNode(char *data) {
  DataNode *newNode = (DataNode*)malloc(sizeof(DataNode));
  if (newNode == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  newNode->data = strdup(data); // Allocate memory for data and copy
  newNode->next = NULL;
  return newNode;
}
```

This function `createDataNode`:

1. Allocates memory for a new `DataNode` using `malloc()`.
2. Checks if memory allocation was successful.
3. Copies the input `data` to the `data` field of the new node using `strdup()` to avoid data sharing issues.
4. Sets the `next` pointer to `NULL` initially.
5. Returns the pointer to the newly created `DataNode`.

### 2. SinglyLinkedList Class

The `SinglyLinkedList` class manages a collection of `DataNode`s.

#### 2.1. SinglyLinkedList Structure

```c
typedef struct SinglyLinkedList {
  int count;
  DataNode *head;
} SinglyLinkedList;
```

This structure defines `SinglyLinkedList` and contains:

* `count`: An integer to store the number of nodes in the list.
* `head`: A pointer to the first `DataNode` in the list (the head of the list).

#### 2.2. Initializing a SinglyLinkedList

```c
SinglyLinkedList* createSinglyLinkedList() {
  SinglyLinkedList *list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
  if (list == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  list->count = 0;
  list->head = NULL;
  return list;
}
```

This function `createSinglyLinkedList`:

1. Allocates memory for a new `SinglyLinkedList`.
2. Initializes the `count` to `0` (empty list).
3. Sets the `head` pointer to `NULL` (empty list).
4. Returns the pointer to the newly created `SinglyLinkedList`.

#### 2.3. SinglyLinkedList Methods

You'll need to implement various methods for the `SinglyLinkedList` class. Here are some common ones:

##### 2.3.1. `traverse()`

This method iterates through the linked list and prints the data of each node.

```c
void traverse(SinglyLinkedList *list) {
  if (list->head == NULL) {
    printf("This is an empty list.\n");
    return;
  }

  DataNode *current = list->head;
  while (current != NULL) {
    printf("%s -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}
```

##### 2.3.2. `insert_last(data)`

This method adds a new node with the given data to the end of the list.

```c
void insert_last(SinglyLinkedList *list, char *data) {
  DataNode *newNode = createDataNode(data);

  if (list->head == NULL) {
    list->head = newNode;
  } else {
    DataNode *current = list->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
  list->count++;
}
```

##### 2.3.3. `insert_front(data)`

This method adds a new node with the given data to the beginning of the list.

```c
void insert_front(SinglyLinkedList *list, char *data) {
  DataNode *newNode = createDataNode(data);

  newNode->next = list->head;
  list->head = newNode;
  list->count++;
}
```

##### 2.3.4. `insert_before(node, data)`

This method adds a new node with the given data before a specified node in the list.

```c
void insert_before(SinglyLinkedList *list, char *nodeData, char *data) {
  DataNode *newNode = createDataNode(data);

  if (list->head == NULL) {
    printf("Cannot insert, \"%s\" does not exist.\n", nodeData);
    free(newNode); // Free the allocated memory for newNode
    return;
  }

  // If inserting before the head
  if (strcmp(list->head->data, nodeData) == 0) { 
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
    return;
  }

  DataNode *current = list->head;
  while (current->next != NULL && strcmp(current->next->data, nodeData) != 0) {
    current = current->next;
  }

  if (current->next != NULL) {
    newNode->next = current->next;
    current->next = newNode;
    list->count++;
  } else {
    printf("Cannot insert, \"%s\" does not exist.\n", nodeData);
    free(newNode); // Free the allocated memory for newNode
  }
}
```

##### 2.3.5. `delete(data)`

This method removes the first node containing the specified data from the list.

```c
void delete(SinglyLinkedList *list, char *data) {
  if (list->head == NULL) {
    printf("Cannot delete, \"%s\" does not exist.\n", data);
    return;
  }

  // If deleting the head node
  if (strcmp(list->head->data, data) == 0) {
    DataNode *temp = list->head;
    list->head = list->head->next;
    free(temp->data); // Free the data memory
    free(temp); // Free the node
    list->count--;
    return;
  }

  DataNode *current = list->head;
  while (current->next != NULL && strcmp(current->next->data, data) != 0) {
    current = current->next;
  }

  if (current->next != NULL) {
    DataNode *temp = current->next;
    current->next = current->next->next;
    free(temp->data); // Free the data memory
    free(temp); // Free the node
    list->count--;
  } else {
    printf("Cannot delete, \"%s\" does not exist.\n", data);
  }
}
```

#### 2.4. Freeing Memory

It's essential to free the allocated memory for the linked list and its nodes to prevent memory leaks.

```c
void freeSinglyLinkedList(SinglyLinkedList *list) {
  DataNode *current = list->head;
  while (current != NULL) {
    DataNode *temp = current;
    current = current->next;
    free(temp->data); // Free the data memory
    free(temp); // Free the node
  }
  free(list);
}
```

### 3. Example Usage

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include the DataNode and SinglyLinkedList structures and functions here

int main() {
  SinglyLinkedList *mylist = createSinglyLinkedList();

  insert_last(mylist, "Tawan");
  insert_last(mylist, "Sanja");
  printf("Initial list: ");
  traverse(mylist); 

  insert_front(mylist, "Nados");
  printf("After insert_front(\"Nados\"): ");
  traverse(mylist);

  insert_before(mylist, "Sanja", "Title"); 
  printf("After insert_before(\"Sanja\", \"Title\"): ");
  traverse(mylist);

  delete(mylist, "Tawan"); 
  printf("After delete(\"Tawan\"): ");
  traverse(mylist);

  freeSinglyLinkedList(mylist);
  return 0;
}
```

This code demonstrates how to create, populate, and manipulate a singly linked list. It also shows how to use the
`traverse()`, `insert_last()`, `insert_front()`, `insert_before()`, and `delete()` methods.

Remember to compile and run the code to see the output.