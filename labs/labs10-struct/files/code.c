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