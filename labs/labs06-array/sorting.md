## Sorting Number Arrays in C: A Comparative Guide

This tutorial explores five popular sorting algorithms for numerical arrays in C: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, and Quick Sort. We'll delve into their implementations, analyze their time complexities, and compare their strengths and weaknesses.

### 1. Bubble Sort

**Concept:** Repeatedly steps through the array, compares adjacent elements, and swaps them if they are in the wrong order.

**Implementation:**

```c
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
```

**Time Complexity:** O(n^2) in the worst and average cases, O(n) in the best case (already sorted).

**Pros:** Simple to understand and implement.

**Cons:** Inefficient for large datasets.

### 2. Selection Sort

**Concept:** Finds the minimum element in the unsorted part of the array and swaps it with the element at the beginning of the unsorted part.

**Implementation:**

```c
void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    int temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}
```

**Time Complexity:** O(n^2) in all cases.

**Pros:** Performs fewer swaps than Bubble Sort.

**Cons:** Still inefficient for large datasets.

### 3. Insertion Sort

**Concept:** Builds the sorted array one element at a time by inserting each element into its correct position within the already sorted part.

**Implementation:**

```c
void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}
```

**Time Complexity:** O(n^2) in the worst and average cases, O(n) in the best case (already sorted).

**Pros:** Efficient for small datasets or nearly sorted arrays.

**Cons:** Inefficient for large, unsorted datasets.

