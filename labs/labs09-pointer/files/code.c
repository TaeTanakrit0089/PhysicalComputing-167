#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    char *str, *ptr;

    scanf("%d", &n);
    scanf("%d", &m);

    str = (char *)malloc((n + 1) * sizeof(char));

    scanf(" %[^\n]s", str);

    ptr = str;
    while(ptr < (str + n)) {
        printf("%c", *ptr);
        ptr += m;
    }

    printf("\n");
    free(str);
    return 0;
}