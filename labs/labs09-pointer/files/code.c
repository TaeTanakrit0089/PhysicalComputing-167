#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        char *ptr = (char *)malloc(1024 * 1024); // Allocate 1GB
        // Memory is not freed, causing a leak
        // Do something with ptr if needed
    }
    return 0;
}