#include "../drivers/frame_buffer.h"

int sum_of_three(int a, int b, int c)
{
    return a + b + c;
}

int multiply(int a, int b)
{
    return a * b;
}

int subtract(int a, int b)
{
    return a - b;
}

void kmain(void)
{
    int result1;
    int result2;
    int result3;

    result1 = sum_of_three(10, 20, 30);
    result2 = multiply(5, 6);
    result3 = subtract(100, 25);

    fb_clear();

    fb_set_colour(0x0A);

    fb_move(10, 5);
    fb_write_string("sum_of_three = ");
    fb_write_int(result1);

    fb_move(10, 7);
    fb_write_string("multiply = ");
    fb_write_int(result2);

    fb_move(10, 9);
    fb_write_string("subtract = ");
    fb_write_int(result3);

    while (1)
    {
    }
}