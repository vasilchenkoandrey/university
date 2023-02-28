#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <bios.h>
#include <ctype.h>
#include "C:\PROJECT\lab5test\drawing.h"

#define KB_ESC 0x011B
#define KB_ENTER 0x1C0D
#define KB_BACKSPACE 0x0E08
#define KB_DELETE 0x5300																																					    
#define KB_END 0x4F00
#define KB_NUMPADPLUS 0x4E2B
#define KB_NUMPADMINUS 0x4A2D
#define KB_PLUS 0x0D3D
#define KB_MINUS 0x0C2D
#define KB_TAB 0x0F09
#define KB_ARROWUP 0x4800
#define KB_ARROWRIGHT 0x4D00
#define KB_ARROWLEFT 0x4B00
#define KB_ARROWDOWN 0x5000
#define KB_F2 0x3C00
#define KB_CTRL 0x0004

typedef enum{false, true} bool;

void mouseAndInterfaceTick(int mX, int mY, int mB, int oldX, int oldY);
bool keyboardTick(int mX, int mY, int keyCode);

int fontSize = 0, color = WHITE, font = DEFAULT_FONT;
int modifiers = 0;

int main(void) {
	if (initMouse() == 1) {
		getch();
		return 0;
	}
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI");

	if(graphresult()!=grOk) {
		printf("Error! Driver not found.");
		getch();
		return 2;
	}

	int mX, mY, mB, oldX, oldY, keyCode;
	showMouse();
	setcolor(color);

	while(true) {
		oldX = mX;
		oldY = mY;
		getMouseState(mX, mY, mB);
		mouseAndInterfaceTick(mX, mY, mB, oldX, oldY);
		if(bioskey(1) != 0) {
			keyCode = bioskey(0);
			if(keyboardTick(mX, mY, keyCode)) {
				break;
			}

			modifiers = bioskey(0x04); //контрл зажата
			if (modifiers) {
				if (modifiers & KB_ENTER) {
					setMousePos(0, 0); //если зажата контрл и нажат ENTER
				}
				else if (modifiers & KB_END) {
					setMousePos(getmaxx(), getmaxy());
				}
			}
		}
	}
	return 0;
}

//обработчик мышки
void mouseAndInterfaceTick(int mX, int mY, int mB, int oldX, int oldY) {
	gotoxy(1, 1);
	printf("X=%3d Y=%3d ", mX, mY);
	printf("\nCOLOR:%d   ", color);
	printf("\nFONT SIZE:%d   ", fontSize);

	//если нажата клавиша, то ...
	if(mB==0) { //...ничего не делать, просто изменить указатель на стрелку (не нажата кнопка мышки)
		setMouseCursor(CURSOR_POINTER);
		printf("\n   ");
	} else if(mB==1) { //...рисовать (левая кнопка мышки)
		setMouseCursor(CURSOR_PENCIL);
		printf("\nLMB");
		hideMouse();
		line(oldX, oldY, mX, mY);
		showMouse();
	} else if(mB==2) { //...стирать (правая кнопка мышки)
		setMouseCursor(CURSOR_ERASER);
		printf("\nRMB");
		hideMouse();
		for(int i = mX-5; i < mX+5; i++) {
			for(int j = mY-5; j < mY+5; j++) {
				putpixel(i, j, BLACK);
			}
		}
		showMouse();
	} else if(mB==4){ //...нарисовать окружность (средняя кнопка мышки)
		hideMouse();
		circle(mX, mY, 20);
		showMouse();
	} else if(mB==3){ //... (левая и правая кнопка мышки одновременно)
		//сюда код если нужно
	}
}

//обработчик клавиатуры
bool keyboardTick(int mX, int mY, int keyCode) {
	int cw = textwidth("A"), ch = textheight("A");
	//если нажата клавиша, то ...
	if(keyCode == KB_ESC) { //...выйти из программы
		return true;
	} else if(keyCode == KB_ARROWRIGHT) { //...указатель мышки вправо на один символ
		setMousePos(mX + cw, mY); 
	} else if(keyCode == KB_ARROWUP) { //...указатель мышки вверх на один символ
		setMousePos(mX, mY - ch); 
	} else if(keyCode == KB_ARROWDOWN) { //...указатель мышки вниз на один символ
		setMousePos(mX, mY + ch); 
	} else if(keyCode == KB_ARROWLEFT) { //...указатель мышки влево на один символ
		setMousePos(mX - cw, mY); 
	} else if(keyCode == KB_END) { //...указатель мышки вконец
		setMousePos(getmaxx() - cw, mY); 
	} else if(keyCode == KB_ENTER) { //...указатель мышки на новую строку
		setMousePos(0, mY + ch); 
	} else if(keyCode == KB_TAB) { //...указатель мышки на размер таба
		setMousePos(mX + 4 * cw, mY); 
	} else if(keyCode == KB_NUMPADPLUS) { //...увеличить шрифт
		fontSize = fontSize<10?fontSize+1:0; 
		settextstyle(font, HORIZ_DIR, fontSize);
	} else if(keyCode == KB_NUMPADMINUS) { //...уменьшить шрифт
		fontSize = fontSize>0?fontSize-1:10; 
		settextstyle(font, HORIZ_DIR, fontSize);
	} else if(keyCode == KB_PLUS) { //...следующий цвет кисти
		color = color<getmaxcolor()?color+1:0; 
		setcolor(color);
	} else if(keyCode == KB_MINUS) { //...предыдущий цвет кисти
		color = color>0?color-1:getmaxcolor(); 
		setcolor(color);
	} else if(keyCode == KB_BACKSPACE) { //...удалить символ
		hideMouse();
		for(int i = 1; i <= cw+1; i++) {
			for(int j = 0; j <= ch; j++) {
				putpixel(mX - i, mY + j, BLACK);
			}
		}
		setMousePos(mX - cw, mY);
		showMouse();
	} else if(keyCode == KB_DELETE) { //...удалить все с окна
		cleardevice();
	} else if(keyCode != 0) { //...печатать символы в окне
		char *strSymb = "*";
		strSymb[0] = (char)keyCode;
		hideMouse();
		outtextxy(mX, mY, strSymb);
		showMouse();
		setMousePos(mX + cw, mY);
	}
	return false;
}
