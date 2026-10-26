%include "asm_io.inc"

segment .data

msg1 db "Enter start (1-100): ",0
msg2 db "Enter end (1-100): ",0

segment .bss

array resd 100
start resd 1
finish resd 1

segment .text
global asm_main

asm_main:

    enter 0,0
    pusha

    mov ecx, 0

fill_array:

    mov eax, ecx
    add eax, 1

    mov [array + ecx*4], eax

    inc ecx

    cmp ecx, 100
    jl fill_array

    mov eax, msg1
    call print_string

    call read_int
    mov [start], eax

    mov eax, msg2
    call print_string

    call read_int
    mov [finish], eax

    mov ecx, [start]
    dec ecx

    mov edx, [finish]
    dec edx

    mov ebx, 0

sum_loop:

    add ebx, [array + ecx*4]

    inc ecx

    cmp ecx, edx
    jle sum_loop

    mov eax, ebx

    call print_int
    call print_nl

    popa
    mov eax, 0
    leave
    ret