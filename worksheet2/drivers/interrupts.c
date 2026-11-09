#include "interrupts.h"
#include "pic.h"
#include "io.h"
#include "frame_buffer.h"
#include "keyboard.h"

#define INTERRUPTS_DESCRIPTOR_COUNT 256
#define INTERRUPTS_KEYBOARD 33

struct IDTDescriptor idt_descriptors[INTERRUPTS_DESCRIPTOR_COUNT];
struct IDT idt;

void interrupts_init_descriptor(s32int index, u32int address)
{
    idt_descriptors[index].offset_high =
        (address >> 16) & 0xFFFF;

    idt_descriptors[index].offset_low =
        address & 0xFFFF;

    idt_descriptors[index].segment_selector = 0x08;

    idt_descriptors[index].reserved = 0x00;

    idt_descriptors[index].type_and_attr =
        (0x01 << 7) | 0x0E;
}

void interrupts_install_idt()
{
    interrupts_init_descriptor(
        INTERRUPTS_KEYBOARD,
        (u32int) interrupt_handler_33);

    idt.address = (u32int)&idt_descriptors;
    idt.size =
        sizeof(struct IDTDescriptor) *
        INTERRUPTS_DESCRIPTOR_COUNT;

    load_idt((u32int)&idt);

    pic_remap(PIC_1_OFFSET, PIC_2_OFFSET);
}

void interrupt_handler(
    struct cpu_state cpu,
    u32int interrupt,
    struct stack_state stack)
{
    u8int input;
    u8int ascii;

    (void)cpu;
    (void)stack;

    switch(interrupt)
    {
        case INTERRUPTS_KEYBOARD:

            input = keyboard_read_scan_code();

            ascii =
                keyboard_scan_code_to_ascii(input);

            if(ascii != 0)
            {
                fb_write_char(ascii);
            }

            pic_acknowledge(interrupt);

            break;

        default:
            break;
    }
}