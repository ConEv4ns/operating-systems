#include "frame_buffer.h"

char *fb = (char *)0xB8000;

unsigned int fb_index = 0;
char fb_colour = 0x0F;

void fb_write_char(char c)
{
    fb[fb_index++] = c;
    fb[fb_index++] = fb_colour;
}

void fb_write_string(char *str)
{
    while (*str)
    {
        fb_write_char(*str);
        str++;
    }
}

void fb_clear(void)
{
    int i;

    for (i = 0; i < 80 * 25 * 2; i += 2)
    {
        fb[i] = ' ';
        fb[i + 1] = fb_colour;
    }

    fb_index = 0;
}

void fb_move(unsigned short x, unsigned short y)
{
    fb_index = (y * 80 + x) * 2;
}

void fb_set_colour(char colour)
{
    fb_colour = colour;
}

void fb_write_int(int num)
{
    char buffer[12];
    int i = 0;

    if (num == 0)
    {
        fb_write_char('0');
        return;
    }

    while (num > 0)
    {
        buffer[i++] = '0' + (num % 10);
        num /= 10;
    }

    while (i > 0)
    {
        fb_write_char(buffer[--i]);
    }
}
