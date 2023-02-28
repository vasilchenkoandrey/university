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
#define KB_PLUS 0x0D3D
#define KB_MINUS 0x0C2D		
#define KB_NUMPADPLUS 0x4E2B
#define KB_NUMPADMINUS 0x4A2D
#define KB_PLUS 0x0D3D
#define KB_MINUS 0x0C2D
#define KB_TAB 0x0F09
#define KB_ARROWUP 0x4800
#define KB_ARROWRIGHT 0x4D00
#define KB_ARROWLEFT 0x4B00
#define KB_ARROWDOWN 0x5000																														    

struct REGPACK regs;
typedef enum{false, true} bool;

int MOUSE_COOR_X = 0, MOUSE_COOR_Y = 0, LAST_MOUSE_COOR_X, LAST_MOUSE_COOR_Y, MOUSE_BUTTON, SIZE_CURSOR = 3, COLOR_BRUSH = 9, STYLE_BRUSH = 0, SIZE_BRUSH = 0;
//bool click = false;

unsigned CURSOR_BRUSH[17] = {0x001C, 0x003F, 0x0073, 0x00B3, 0x01BF, 0x03DE, 0x07E4, 0x0BF8, 0x0BF0, 0x1DE0, 0x1E40, 0x3F80, 0x2E00, 0x5800, 0x6000, 0x6000, 0x0F01};
unsigned CURSOR_ERASER[17] = {0x0FC0, 0x1BE0, 0x3DF0, 0x7EF8, 0xFF70, 0x7FBE, 0x3FD1, 0x1FE1, 0x0FDE, 0x07BC, 0x0378, 0x01F0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0004};
unsigned CURSOR_DEFAULT[17] = {0x0000,0x4000,0x3000,0x3C00,0x1F00,0x0FC0,0x0FF0,0x0FFC,0x07FF,0x0780,0x0380,0x0380,0x0180,0x0180,0x0080,0x0080,0x1100};

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
