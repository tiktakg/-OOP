#include <iostream>
#include <string.h>
#include <Windows.h>
#include <conio.h>


void gotoxy(short x, short y)
{
	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x,y };
	SetConsoleCursorPosition(stdOut, coord);
}

class Triandgle
{
private:
	char cc;
	short x, y,x1,y1,x2,y2;


	friend void gotoxy(short x, short y);

public:

	void charlocus(short X, short Y, short X1, short Y1, short X2, short Y2, char CC)
	{
		x = X;
		y = Y;
		x1 = X1;
		y1 = Y1;
		x2 = X2;
		y2 = Y2;
		cc = CC;
	}

	void display()
	{
		gotoxy(x, y);
		std::cout << cc;
		gotoxy(x1, y1);
		std::cout << cc;
		gotoxy(x2, y2);
		std::cout << cc;
	}

};

class Point
{
private:
	char cc;
	short x, y;

	friend void gotoxy(short x, short y);


public:

	void charlocus(short X, short Y, char CC)
	{
		x = X;
		y = Y;
		cc = CC;
	}

	void display()
	{
		gotoxy( x,y);
		std::cout << cc;
	}
};




int main()
{
	Point p;
	Triandgle t;

	p.charlocus(1, 1, 'q');
	p.display();

	p.charlocus(5, 10, 'e');
	p.display();

	t.charlocus(1, 4, 6, 7, 8, 2, 'f');
	t.display();
	system("pause");
}


