all: task1 task1_2 task2_1 task2_2 task2_3

task1:
	cd src && nasm -f elf task1.asm -o task1.o
	cd src && nasm -f elf asm_io.asm -o asm_io.o
	cd src && gcc -m32 -c driver.c -o driver.o
	cd src && gcc -m32 driver.o task1.o asm_io.o -o task1

task1_2:
	cd src && nasm -f elf task1_2.asm -o task1_2.o
	cd src && nasm -f elf asm_io.asm -o asm_io.o
	cd src && gcc -m32 -c driver.c -o driver.o
	cd src && gcc -m32 driver.o task1_2.o asm_io.o -o task1_2

task2_1:
	cd src && nasm -f elf task2_1.asm -o task2_1.o
	cd src && nasm -f elf asm_io.asm -o asm_io.o
	cd src && gcc -m32 -c driver.c -o driver.o
	cd src && gcc -m32 driver.o task2_1.o asm_io.o -o task2_1

task2_2:
	cd src && nasm -f elf task2_2.asm -o task2_2.o
	cd src && nasm -f elf asm_io.asm -o asm_io.o
	cd src && gcc -m32 -c driver.c -o driver.o
	cd src && gcc -m32 driver.o task2_2.o asm_io.o -o task2_2

task2_3:
	cd src && nasm -f elf task2_3.asm -o task2_3.o
	cd src && nasm -f elf asm_io.asm -o asm_io.o
	cd src && gcc -m32 -c driver.c -o driver.o
	cd src && gcc -m32 driver.o task2_3.o asm_io.o -o task2_3
