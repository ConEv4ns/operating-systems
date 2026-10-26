%include "asm_io.inc"

segment .data

integer1 dd 15
integer2 dd 6

segment .bss

result resd 1

segment .text
global asm_main

asm_main:

    enter 0,0
    pusha

    mov eax, [integer1]
    add eax, [integer2]
    mov [result], eax

    mov eax, [result]
    call print_int
    call print_nl

    popa

    mov eax, 0
    leave
    ret