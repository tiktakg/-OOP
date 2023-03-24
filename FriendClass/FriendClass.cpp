#include <iostream>
#include <string.h>
#include <Windows.h>
#include <conio.h>


void gotoxy(Triandgle t, Point p)
{
	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { t.x,t.y };
	SetConsoleCursorPosition(stdOut, coord);

	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { p.x,p.y };
	SetConsoleCursorPosition(stdOut, coord);
}

//class Triandgle
//{
//private:
//	
//	char cc;
//	
//	friend void gotoxy(Triandgle t, Point p);
//
//public:
//	short x, y, x1, y1, x2, y2;
//
//
//	void charlocus(short X, short Y, short X1, short Y1, short X2, short Y2, char CC)
//	{
//		x = X;
//		y = Y;
//		x1 = X1;
//		y1 = Y1;
//		x2 = X2;
//		y2 = Y2;
//		cc = CC;
//	}
//
//	void display(Triandgle t)
//	{
//		gotoxy(t, this);
//		std::cout << cc;
//		gotoxy(t, this);
//		std::cout << cc;
//		gotoxy(t, this);
//		std::cout << cc;
//	}
//
//};

class Point
{
private:
	

	friend void gotoxy( Point p);
	char cc;
	

public:
	short x, y;

	void charlocus(short X, short Y, char CC)
	{
		x = X;
		y = Y;
		cc = CC;
	}

	void display( Point p)
	{
		gotoxy(t, p);
		std::cout << cc;
	}
};


void gotoxy(Triandgle t, Point p)
{
	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { t.x,t.y };
	SetConsoleCursorPosition(stdOut, coord);

	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { p.x,p.y };
	SetConsoleCursorPosition(stdOut, coord);
}

int main()
{
	Point p;
	Triandgle t;

	p.charlocus(1, 1, 'q');
	p.display(t,p);

	p.charlocus(5, 10, 'e');
	p.display(t, p);

	t.charlocus(1, 4, 6, 7, 8, 2, 'f');
	t.display();
	system("pause");
}


