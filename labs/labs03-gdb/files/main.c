#include "stdio.h"

int main() {
    int a = 10, b = 20, c = 30, d = 40;

    d = a++ + b++ + c++;
    d = ++a + ++b + ++c;

    printf("Hello, IT-KMITL");

    a = a++ + ++d;
    c = ++a + ++c;

    return 0;
}