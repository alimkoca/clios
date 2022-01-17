CC=gcc
CFLAGS=-m32 -c

AS=nasm
ASFLAGS=-felf32

install: clios.iso

clios.iso: kernel.o pr.o port.o boot.o desc.o 
	ld kernel.o pr.o port.o boot.o -o boot.bin -T linker.ld -m elf_i386
	cp boot.bin iso/init/
	grub-mkrescue -o $@ iso

boot.o: boot/boot.asm kernel.o pr.o port.o
	$(AS) $(ASFLAGS) $< -o $@

desc_asm.o: include/asm/desc.asm
	$(AS) $(ASFLAGS) $< -o $@

kernel.o: kernel/kernel.c pr.o port.o
	$(CC) $(CFLAGS) $< -o $@

pr.o: kernel/tty/pr.c port.o
	$(CC) $(CFLAGS) $< -o $@

port.o: kernel/port.c
	$(CC) $(CFLAGS) $< -o $@	

desc.o: kernel/desc.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm *.o *.iso
