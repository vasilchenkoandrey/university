#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
//#include "h:\\OS\lab5yula\drawing.h"
#include "C:\PROJECT\lab5yula\drawing.h"
#include <bios.h>

void mouseEventHandler();
bool keyboardEventHandler(int pressButton);
void brush();
void eraser();
void clear();
void deleteChar();

int pressButton, borderColor = COLOR_BRUSH, SIZE_FIGURE = 15, fontSize=0, font = DEFAULT_FONT;

int main() {
	if (initMouse() == 1) {
		getch();
		return 0;
	}

	int gdriver = DETECT, gmode;
	//initgraph (&gdriver, &gmode, "G:\\PROGRAMS\\BC31\\BGI");
	initgraph (&gdriver, &gmode, "C:\\BORLANDC\\BGI");


	if (graphresult() != grOk) {
		cout << "ERROR. DRIVER NOT DETECTED. PRESS ANY KEY TO EXIT..." << endl;
		getch();
		return 0;
	}
	showMouse();
	
	while (1) {
		LAST_MOUSE_COOR_X = MOUSE_COOR_X;
		LAST_MOUSE_COOR_Y = MOUSE_COOR_Y;
		mouseState(MOUSE_COOR_X, MOUSE_COOR_Y, MOUSE_BUTTON);
		mouseEventHandler();

		if(bioskey(1) != 0) {
			pressButton = bioskey(0);
			if(keyboardEventHandler(pressButton)) {
				break;
			}
		}
	}

	closegraph();
	return 0;
}

void mouseEventHandler() {
	gotoxy(1, 1);
	cout << "X: " << MOUSE_COOR_X << " Y: " << MOUSE_COOR_Y << "  " <<endl;
	cout << "BUTTON: ";
	switch (MOUSE_BUTTON) {
				case 1:
					setMouseCursor(CURSOR_BRUSH);
					cout << "LBM";
					brush();
				break;

				case 2:
					setMouseCursor(CURSOR_ERASER);
					cout << "RBM";
					eraser();
				break;

				case 4:
					//
				break;

				default:
					setMouseCursor(CURSOR_DEFAULT);
					cout << "             ";
					MOUSE_BUTTON = 0;
	}
}	

bool keyboardEventHandler(int pressButton) {
int charWidth = textwidth("_"), charHeight = textheight("|");
		switch (pressButton) {
			case KB_ESC:
				return true;
			break;
			
			case KB_BACKSPACE:
				deleteChar();
			break;

			case KB_ENTER:
				casting();
			break;

			case KB_DELETE:
				clear();
			break;

			case KB_PLUS:
				fontSize = fontSize<10?fontSize+1:0;
				settextstyle(font, HORIZ_DIR, fontSize);
			break;

			case KB_MINUS:
				fontSize = fontSize>0?fontSize-1:10;
				settextstyle(font, HORIZ_DIR, fontSize);
			break;

			default:
				char *strSymb = "*";
				strSymb[0] = (char)pressButton;
				hideMouse();
				outtextxy(MOUSE_COOR_X, MOUSE_COOR_Y, strSymb);
				showMouse();
				mousePosition(MOUSE_COOR_X + charWidth, MOUSE_COOR_Y);
			break;
		}
	return false;
}

void brush() {
	if (MOUSE_COOR_X >= 120) {
		hideMouse();
		setcolor(COLOR_BRUSH);
		line(LAST_MOUSE_COOR_X, LAST_MOUSE_COOR_Y, MOUSE_COOR_X, MOUSE_COOR_Y);
		showMouse();
	}
}

void eraser() {
	hideMouse();
	if (MOUSE_COOR_X >= 120) {
		for (int i = MOUSE_COOR_X - SIZE_CURSOR; i <= MOUSE_COOR_X + SIZE_CURSOR; i++)
			for (int j = MOUSE_COOR_Y - SIZE_CURSOR; j <= MOUSE_COOR_Y + SIZE_CURSOR; j++) {
				putpixel (i, j, getbkcolor());
			}
	}
	showMouse();
}

void clear() {
	hideMouse();
	cleardevice();
	showMouse();
}

void deleteChar() {
	hideMouse();
	for (int i = 1; i <= charWidth+1; i++) {
		for (int j = 0; j <= charHeight; j++) {
			putpixel(MOUSE_COOR_X - i, MOUSE_COOR_Y + j, BLACK);
		}
	}
	mousePosition(MOUSE_COOR_X - charWidth, MOUSE_COOR_Y);
	showMouse();
}