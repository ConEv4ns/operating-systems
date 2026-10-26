%include "asm_io.inc"

segment .bss

array resd 100

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

    mov ecx, 0
    mov ebx, 0

sum_array:

    add ebx, [array + ecx*4]

    inc ecx

    cmp ecx, 100
    jl sum_array

    mov eax, ebx

    call print_int
    call print_nl

    popa
    mov eax, 0
    leave
    ret