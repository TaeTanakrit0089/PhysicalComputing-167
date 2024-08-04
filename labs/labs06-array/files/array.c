#include <stdio.h>

int main() {
    int num[7] = {10, -20, 30, -40, 50, -60};
    num[6] = 70;

    // Calculate the size of the array
    int array_size = sizeof(num) / sizeof(num[0]); 
    // Iterate over the array using a for loop
    for (int i = 0; i < array_size; i++) 
        printf("%d ", num[i]);

    printf("\n"); 
    return 0;
}