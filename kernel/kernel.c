#include "../include/pr.h"
#include "../include/port.h"
#include "../include/type.h"
#include "../include/gdt.h"
#include "../include/get_input.h"
#include "../include/math/def.h"

extern void loaded(){
	printk("Loaded");
}

extern int kmain(){
	set_bg_color(0);
	set_bg();
	printk("Welcome CLIOS 0.0.1\n");
	printk("Live system for 0.0.1\n");
	load_gdt();
	printk("\n\n");
	set_fg_color(10);
	printk("[ LOG ] In Protected Mode\n");
	printk("[ LOG ] Succesfully booted\n");
	printk("[ LOG ] Loading Math Engine...\n");
	load_math_eng();
	printk("[ LOG ] Keyboard test, try type something: ");
	getfsh();
}