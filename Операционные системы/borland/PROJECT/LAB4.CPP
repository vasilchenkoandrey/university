#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <bios.h>
#include <ctype.h>
#include "drawing.h"
#define KB_ARROWRIGHT 0x4D00
#define KB_ESC 0x011B
#define KB_PLUS 0x0D3D
#define KB_MINUS 0x0C2D
#define KB_TAB 0x0F09
#define KB_DELETE 0x5300																																					    
#define KB_END 0x4F00
int main () {

	initMouse();
	if (regs.r_ax == 0) {
		cout << "ERROR. MOUSE NOT FOUND. PRESS ANY KEY TO EXIT..." << endl;
		return 0;
	}
	cout << "MOUSE IS PRESENT, AND HAS" << regs.r_bx << "BUTTON" << endl;

	int gdriver = DETECT, gmode;
	initgraph (&gdriver, &gmode, "C:\\BORLANDC\\BGI");
	if (graphresult() != grOk) {
		cout << "ERROR. DRIVER NOT DETECTED. PRESS ANY KEY TO EXIT..." << endl;
		return 0;
	}

	showMouse();
	textbackground(9);
	textcolor(9);
	//setbkcolor(3);
	int mX=0, mY=0, mB, prevX, prevY, barX, barY, sizeCursor = 3, colorBrush = 9, bkColor = 9;



 


	while (1) {
			while (bioskey(1) != 0);
				int key=bioskey(0);
				if(key == KB_ESC) {
					return 0;
				} else if(key == KB_ARROWRIGHT) {
					setbkcolor(3);
				}
			
		if (kbhit()) break;
		prevX=mX;
		prevY=mY;
		mouseState(mX, mY, mB);
		gotoxy (1, 1);

		if (mX>=150 && mY>=30) {
			if (mB == 0) {
				cout <<" "<< endl;
			}
			else if (mB == 1) {
				setMouseCursor(CURSOR_BRUSH);
				brushActive(mX, mY, prevX, prevY, sizeCursor, colorBrush);
			}
			else if (mB == 2) {
				setMouseCursor(CURSOR_ERASER);
				eraserActive(mX, mY, sizeCursor);
			}
			else
				cout << "UNKNOWN BUTTONS COMBINATION" << endl;
		}

	}

	closegraph ();
	return 0;
}