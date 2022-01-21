#include "../../include/get_input.h"
#include "../../include/port.h"

void ex_scan(){
      asm volatile("mov 4, %eax");
}

char getfsh(void){
    asm volatile("inb $0x64, %al\n"
                 "mov $0x1, %ah\n"
                 "jne ex_scan\n"
                 "outb %al, $0x64");
}