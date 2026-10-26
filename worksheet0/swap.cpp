#include <stdio.h>

void swap(void* x, void* y)
{
    int temp = *(int*)x;

    *(int*)x = *(int*)y;
    *(int*)y = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    printf("Before: %d %d\n", a, b);

    swap(&a, &b);

    printf("After: %d %d\n", a, b);

    return 0;
}