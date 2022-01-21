CC=gcc
CFLAGS=-m32 -c -nostdlib

AS=nasm
ASFLAGS=-felf32

install: clios.iso

clios.iso: kernel.o pr.o port.o boot.o gdt.o desc.o math.o get_input.o
	ld kernel.o pr.o port.o boot.o gdt.o desc.o math.o get_input.o -o boot.bin -T linker.ld -m elf_i386
	cp boot.bin iso/init/
	grub-mkrescue -o $@ iso

boot.o: boot/boot.asm kernel.o pr.o port.o 
	$(AS) $(ASFLAGS) $< -o $@

kernel.o: kernel/kernel.c pr.o
	$(CC) $(CFLAGS) $< -o $@

pr.o: kernel/tty/pr.c port.o
	$(CC) $(CFLAGS) $< -o $@

port.o: kernel/port.c
	$(CC) $(CFLAGS) $< -o $@

desc.o: kernel/desc.c
	$(CC) $(CFLAGS) $< -o $@

get_input.o: kernel/tty/get_input.c
	$(CC) $(CFLAGS) $< -o $@

math.o: math/math.c
	$(CC) $(CFLAGS) $< -o $@

gdt.o: include/asm/gdt.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	-rm *.o *.iso *.bin
