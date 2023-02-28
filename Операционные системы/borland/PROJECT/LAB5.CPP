#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include "C:\\PROJECT\\drawing.h"
#include <bios.h>

void mouseEventHandler();
bool keyboardEventHandler(int pressButton);
void fillbar(int x1, int y1, int x2, int y2, int COLOR_BRUSH);
void palette();
void selectColorPalette();
void menu();
void brush();
void eraser();
void casting();
void pipette();
void clear();
void GUI();

int pressButton, borderColor = COLOR_BRUSH, SIZE_FIGURE=15;
bool click = false, menuActive = false;

int main() {
	if (initMouse() == 1) {
		getch();
		return 0;
	}
	
	int gdriver = DETECT, gmode;
	initgraph (&gdriver, &gmode, "C:\\BORLANDC\\BGI");

	if (graphresult() != grOk) {
		cout << "ERROR. DRIVER NOT DETECTED. PRESS ANY KEY TO EXIT..." << endl;
		getch();
		return 0;
	}

	GUI();
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
					setMouseCursor(CURSOR_SHAPE);
					cout << "LBM";
					brush();
				break;

				case 2:
					setMouseCursor(CURSOR_ERASER);
					cout << "RBM";
					eraser();
				break;

				case 4:
					pipette();
				break;

				default:
					setMouseCursor(CURSOR_SHAPE);
					cout << "             ";
					MOUSE_BUTTON = 0;
	}

	// palette
	if (MOUSE_COOR_X > 19 && MOUSE_COOR_Y > 98 && MOUSE_COOR_X < 97 && MOUSE_COOR_Y < 128) {
		if ((MOUSE_BUTTON == 1) && (click == false)) click = true;
		if ((MOUSE_BUTTON == 0) && (click == true)) {
			hideMouse();
			menuActive = true;
			palette();
			showMouse();
			click = false;
		}
	}
	if (menuActive == true) {
		selectColorPalette();
	}
	// end palette
}	

bool keyboardEventHandler(int pressButton) {
	int charWidth = textwidth("_"), charHeight = textheight("|");
	if (MOUSE_COOR_X >= 120) {
		switch (pressButton) {
			case KB_ESC:
				return true;
			break;
			
			case KB_BACKSPACE:
				hideMouse();
					for (int i = 1; i <= charWidth+1; i++) {
						for (int j = 0; j <= charHeight; j++) {
							putpixel(MOUSE_COOR_X - i, MOUSE_COOR_Y + j, BLACK);
						}
					}
					mousePosition(MOUSE_COOR_X - charWidth, MOUSE_COOR_Y);
					GUI();
				showMouse();
			break;

			case KB_ENTER:
				casting();
			break;

			case KB_DELETE:
				clear();
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
	}
	return false;
}

void fillbar(int x1, int y1, int x2, int y2, int color) {
   setfillstyle(1, color);
   bar(x1, y1, x2, y2);
}

void palette() {
   int color = 0, x1 = 18, y1 = 128;
	 setcolor(COLOR_BRUSH);
   setcolor(0);
   for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++){
      fillbar(x1 + 20 * j, y1 + 20 * i, x1 + 80, y1 + 80, color);
      setcolor(0); 
      rectangle(x1 + 20 * j, y1 + 20 * i, x1 + 80, y1 + 80);
      color++;
    }
}

void selectColorPalette() {
	if (MOUSE_COOR_X >= 18 && MOUSE_COOR_Y >= 128 && MOUSE_COOR_X <= 97 && MOUSE_COOR_Y <= 207) {
		setMouseCursor(CURSOR_ERASER);
		if ((MOUSE_BUTTON == 1) && (click == false)) click = true;
			if ((MOUSE_BUTTON == 0) && (click == true)) {
				hideMouse();
				COLOR_BRUSH = getpixel(MOUSE_COOR_X, MOUSE_COOR_Y);
				menuActive = false;
				GUI();
				showMouse();
				click = false;
			}
	}
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

void casting() {
	if (MOUSE_COOR_X >= 120) {
		setcolor(borderColor);
		setfillstyle(XHATCH_FILL, COLOR_BRUSH);
		hideMouse();
		floodfill(MOUSE_COOR_X, MOUSE_COOR_Y, COLOR_BRUSH);
		GUI();
		showMouse();
	}
}

void pipette() {
	hideMouse();
	COLOR_BRUSH = getpixel(MOUSE_COOR_X, MOUSE_COOR_Y);
	showMouse();
}

void clear() {
	hideMouse();
	cleardevice();
	GUI();
	showMouse();
}

void menu() {
  setcolor(WHITE);
  outtextxy(3, 400, "ESC-Exit" );
  outtextxy(3, 410, "LMB-Brush" );
  outtextxy(3, 420, "RMB-Eraser" );
	outtextxy(3, 430, "CMB-Pipett" );
	outtextxy(3, 440, "ENTER-Casting" );
	outtextxy(3, 450, "DELETE-Clear" );
}

void GUI() {
	fillbar(0, 0, 115, getmaxy(), 7);
	// pipette
	if (COLOR_BRUSH == 10 || COLOR_BRUSH == 11 || COLOR_BRUSH == 14 || COLOR_BRUSH == 15) {
		setcolor(BLACK);
	}
	else {
		setcolor(WHITE);
	}
	fillbar(18, 97, 98, 129, BLACK);
	fillbar(19, 98, 97, 128, COLOR_BRUSH);
	outtextxy(37, 110, "COLOR" );
	// end pipette
	
	// figures
	//fillellipse (58, 160, SIZE_FIGURE, SIZE_FIGURE);
	//fillbar(58-SIZE_FIGURE, 190-SIZE_FIGURE, 58+SIZE_FIGURE, 190+SIZE_FIGURE, COLOR_BRUSH);
	// end figures

	menu();
}
