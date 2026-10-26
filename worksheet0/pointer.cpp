#include <stdio.h>

int main()
{
    int n = 5;

    int* ptr_to_n = &n;

    (*ptr_to_n)++;

    printf("%d\n", n);

    return 0;
}