//ให้รับค่า n และสร้าง array ผ่าน pointer โดยข้อมูลใน array จะมีขนาด n ตัวและมีตัวเลขจาก 1 ถึง n
//
//ข้อห้าม: ห้ามใช้ Array โดยเด็ดขาด

#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    int *arr;

    scanf("%d", &size);

    // Allocate memory for the array
    arr = (int*) malloc(size * sizeof(int));

    // Populate the array
    for (i = 0; i < size; i++)
        *(arr + i) = i + 1;

    int *ptr = arr;  // Point to the first element of the array

    // Print the array in order using pointers
    printf("Array elements in order: ");
    while (ptr < (arr+size))
        printf("%d ", *ptr++);

    printf("\n");

    // Print the array in reverse using pointers
    printf("Array elements in reverse: ");
    while (ptr > arr)
        printf("%d ", *--ptr);  // Move the pointer to the previous element
    printf("\n");

    // Free the allocated memory
    free(ptr);

    return 0;
}