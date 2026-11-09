#include "../drivers/frame_buffer.h"
#include "../drivers/interrupts.h"

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
    fb_clear();

    fb_set_colour(0x0A);

    fb_move(10, 5);
    fb_write_string("ConnorOS");

    fb_move(10, 7);
    fb_write_string("Keyboard Interrupt Test");

    interrupts_install_idt();

    while (1)
    {
    }
}