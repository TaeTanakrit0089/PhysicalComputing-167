#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_elements = 100;
    int *data = (int *)malloc(sizeof(int) * num_elements / 2); // Potential off-by-one error!

    printf("%d\n", *data);

    free(data);
    return 0;
}