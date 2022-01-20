#include "../include/pr.h"
#include "../include/port.h"
#include "../include/type.h"
#include "../include/gdt.h"

extern void loaded(){
	printk("Loaded");
}

extern int kmain(){
	set_bg_color(0);
	set_bg();
	printk("Welcome CLIOS 0.0.1\n");
	printk("Live system for 0.0.1\n");
	load_gdt();
	printk("\n");
	set_fg_color(10);
	printk("[ LOG ] In Protected Mode");
}