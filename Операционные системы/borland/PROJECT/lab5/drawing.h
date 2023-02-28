#ifndef DRAWING_H
#define DRAWING_H
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>

#define KB_ESC 0x011B
#define KB_ENTER 0x1C0D
#define KB_BACKSPACE 0x0E08
#define KB_DELETE 0x5300	
#define KB_END 0x4F00																																				    

struct REGPACK regs;
typedef enum{false, true} bool;

int MOUSE_COOR_X = 0, MOUSE_COOR_Y = 0, LAST_MOUSE_COOR_X, LAST_MOUSE_COOR_Y, MOUSE_BUTTON, SIZE_CURSOR = 3, COLOR_BRUSH = 9;
bool click = false;

unsigned CURSOR_SHAPE[17] = {0x0FC0, 0x1FE0, 0x3030, 0x6018, 0xC00C, 0xC00C, 0xC00C, 0xC00C, 0xC00C, 0xC00C, 0x6018, 0x3030, 0x1FE0, 0x0FC0, 0x0000, 0x0000, 0x0707};
unsigned CURSOR_ERASER[17] = {0x0FC0, 0x1FE0, 0x3FF0, 0x7FF8, 0xFFFC, 0xFFFC, 0xFFFC, 0xFFFC, 0xFFFC, 0xFFFC, 0x7FF8, 0x3FF0, 0x1FC0, 0x07C0, 0x0000, 0x0000, 0x0707};

void intrMouse(int param) { 
    regs.r_ax = param;
    intr(0x33, &regs);
}

int initMouse() {
	intrMouse(0);
	if (regs.r_ax == 0) {
		printf ("ERROR. MOUSE NOT FOUND. PRESS ANY KEY TO EXIT...");
		return 1;
	}
	else {
		printf ("MOUSE IS PRESENT, AND HAS %d BUTTON", regs.r_bx);
		return 0;
	}
	
}

void showMouse(void) {
	intrMouse(1);
}

void hideMouse(void) {
	intrMouse(2);
}

void mouseState(int &MOUSE_COOR_X, int &MOUSE_COOR_Y, int &MOUSE_BUTTON) {
	intrMouse(3);
	MOUSE_COOR_X = regs.r_cx;
	MOUSE_COOR_Y = regs.r_dx;
	MOUSE_BUTTON = regs.r_bx;
}

void mousePosition(int MOUSE_COOR_X, int MOUSE_COOR_Y) {
	regs.r_cx = MOUSE_COOR_X;
	regs.r_dx = MOUSE_COOR_Y;
	intrMouse(4);
}

/*int mouseClick () {
	if ((MOUSE_BUTTON == 1) && (click == false)) click = true;
	if ((MOUSE_BUTTON == 0) && (click == true)) {
		click = false;
		return 0;
	}
}*/

void setMouseCursor(unsigned styleCursor[17]) {
	unsigned newStyleCursor[32];
	for(int i=0; i<16; i++) {
		newStyleCursor[i] = (~styleCursor[i]);
		newStyleCursor[i+16] = styleCursor[i];
	}
	regs.r_bx = styleCursor[16]/0x100;
	regs.r_cx = styleCursor[16]%0x100;
	regs.r_es = FP_SEG(&newStyleCursor);
	regs.r_dx = FP_OFF(&newStyleCursor);
	intrMouse(9);
}


#endif
