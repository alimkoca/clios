#include "../../include/pr.h"
#include "../../include/port.h"
#include "../../include/type.h"

uint16_t curs_x = 0;
uint16_t curs_y = 0;
uint16_t* vid_mem = (uint16_t*)0xb8000;
uint8_t att_byt = 0;
uint8_t bg_color = 0;
uint8_t fg_color = 15;

static void curs_m(){
    uint16_t curs_pos = curs_y * 80 + curs_x;
    outb(0x3d4, 14);
    outb(0x3d5, curs_pos >> 8);
    outb(0x3d4, 15);
    outb(0x3d5, curs_pos);
}

static void scroll_sc(){
    uint8_t att_byt = (0 << 4) | (15 & 0x0f);
    uint16_t blk = 0x20 | (att_byt << 8);

    if(curs_y >= 25){
        int i;

        for(i = 0; i < 24*80; i++){
            vid_mem[i] = vid_mem[i+80];
        }

        for(i = 24*80; i < 25*80; i++){
            vid_mem[i] = blk;
        }

        curs_y = 24;

    }
}

void print_put(char c){
    att_byt = (bg_color << 4) | (fg_color & 0x0f);
    uint16_t att = att_byt << 8;
    uint16_t *loc;

    if(c == 0x08 && curs_x){
        curs_x--;
    }

    else if (c == 0x09){
       curs_x = (curs_x+8) & ~(8-1);
    }

    else if (c == '\r'){
        curs_x = 0;
    }

    else if (c == '\n'){
       curs_x = 0;
       curs_y++;
    }

    else if(c >= ' '){
       loc = vid_mem + (curs_y*80 + curs_x);
       *loc = c | att;
       curs_x++;
   }

    if (curs_x >= 80){
       curs_x = 0;
       curs_y ++;
    }

    scroll_sc();
    curs_m();
}

void printk(char *c){
    int i = 0;

    while(c[i]){
        print_put(c[i++]);
    }
}

void set_bg(){
   uint8_t att_byt = (bg_color << 4) | (15 & 0x0F);
   uint16_t blk= 0x20 | (att_byt << 8);
   int i;

   for (i = 0; i < 80*25; i++)
   {
       vid_mem[i] = blk;
   }

   curs_x = 0;
   curs_y = 0;
   curs_m();
}

void set_bg_color(uint8_t color){
    bg_color = color;
}

void set_fg_color(uint8_t color){
    fg_color = color;
}