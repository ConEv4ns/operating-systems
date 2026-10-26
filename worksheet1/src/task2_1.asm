%include "asm_io.inc"

segment .data

ask_num db "Enter a number between 50 and 100: ",0
welcome db "Welcome!",0
error_msg db "Error: number must be between 50 and 100",0

segment .bss

count resd 1

segment .text
global asm_main

asm_main:

    enter 0,0
    pusha

    mov eax, ask_num
    call print_string

    call read_int
    mov [count], eax

    cmp eax, 50
    jl invalid

    cmp eax, 100
    jg invalid

    mov ecx, [count]

print_loop:

    mov eax, welcome
    call print_string
    call print_nl

    loop print_loop

    jmp finish

invalid:

    mov eax, error_msg
    call print_string
    call print_nl

finish:

    popa
    mov eax, 0
    leave
    ret