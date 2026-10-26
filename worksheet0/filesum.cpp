#include <stdio.h>

int main()
{
    FILE* file = fopen("foo.txt", "r");

    int value;
    int total = 0;

    while(fscanf(file, "%d", &value) == 1)
    {
        total += value;
    }

    fclose(file);

    printf("%d\n", total);

    return 0;
}