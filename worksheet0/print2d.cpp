#include <stdio.h>

void print_array(int* arr, int width, int height)
{
    for(int r = 0; r < height; r++)
    {
        for(int c = 0; c < width; c++)
        {
            printf("%d ", arr[r * width + c]);
        }

        printf("\n");
    }
}

int main()
{
    int data[2][3] =
    {
        {1,2,3},
        {4,5,6}
    };

    print_array((int*)data, 3, 2);

    return 0;
}