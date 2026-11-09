#include "pic.h"
#include "io.h"

void pic_remap(s32int offset1, s32int offset2)
{
    outb(PIC_1_COMMAND, 0x11);
    outb(PIC_2_COMMAND, 0x11);

    outb(PIC_1_DATA, offset1);
    outb(PIC_2_DATA, offset2);

    outb(PIC_1_DATA, 0x04);
    outb(PIC_2_DATA, 0x02);

    outb(PIC_1_DATA, 0x01);
    outb(PIC_2_DATA, 0x01);

    outb(PIC_1_DATA, 0x00);
    outb(PIC_2_DATA, 0x00);
}

void pic_acknowledge(u32int interrupt)
{
    if (interrupt >= PIC_2_OFFSET)
    {
        outb(PIC_2_COMMAND, PIC_ACKNOWLEDGE);
    }

    outb(PIC_1_COMMAND, PIC_ACKNOWLEDGE);
}