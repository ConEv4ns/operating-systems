#include <stdio.h>

int main()
{
    int numbers[3] = {10, 30, 2000};

    int* ptr = numbers;

    for(int i = 0; i < 3; i++)
    {
        printf(
            "Value: %d Address: %p\n",
            *(ptr + i),
            (void*)(ptr + i)
        );
    }

    return 0;
}