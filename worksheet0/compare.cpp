#include <stdio.h>

int compare(int* a, int* b, int length)
{
    if(a == NULL || b == NULL)
        return 0;

    for(int i = 0; i < length; i++)
    {
        if(a[i] != b[i])
            return 0;
    }

    return 1;
}

int main()
{
    int arr1[3] = {1,2,3};
    int arr2[3] = {1,2,3};

    printf("%d\n", compare(arr1, arr2, 3));

    return 0;
}