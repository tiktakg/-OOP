#include <iostream>
#include <string.h>
#include <Windows.h>
#include <conio.h>


class Triandgle
{
private:
	char cc;

	class Point;
	friend void gotoxy(Triandgle*, Point*);

	

public:
	short x, y;

	void charlocus(short X, short Y,char CC)
	{
		x = X;
		y = Y;
		cc = CC;
	}

	void display()
	{
		
		std::cout << cc;
	}

	
	
};

//void friendPutChar(Triandgle* p, char c)
//{
//	p->cc = c;
//}

void gotoxy(Triandgle* t, Point p)
{
	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { p->x,p->y };
	COORD coord = { t->x,t->y };
	SetConsoleCursorPosition(stdOut, coord);
}


class Point
{
private:
	
	char cc;

	class Triandgle;
	//friend void friendPutChar(Triandgle*, char);

	friend void gotoxy(Point*,Triandgle*);

	//void gotoxy(int x, int y)
	//{
	//	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//	COORD coord = { x,y };
	//	SetConsoleCursorPosition(stdOut, coord);
	//}

public:
	short x, y;

	void charlocus(short X, short Y, char CC)
	{
		x = X;
		y = Y;
		cc = CC;
	}

	void display()
	{
		std::cout << cc;
	}
		

};

int main()
{
	Triandgle t;
	Point p;
	t.charlocus(3, 5, 'd');
	p.charlocus(5, 3, 'g');
	gotoxy(&t);\
	gotoxy(&p);
	t.display();
	p.display();
	

}

//#include <iostream>
//#include <string.h>
//#include <Windows.h>
//#include <conio.h>
//
//
//class Triandgle
//{
//private:
//	int x, y;
//	char cc;
//
//	friend void gotoxy(Triandgle*, int x, int y);
//
//
//public:
//	void charlocus(int X, int Y, char CC)
//	{
//		x = X;
//		y = Y;
//		cc = CC;
//	}
//
//	void display()
//	{
//		std::cout << cc;
//	}
//
//};
//
//void gotoxy(Triandgle* p, int x, int y)
//{
//	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD coord = { x,y };
//	SetConsoleCursorPosition(stdOut, coord);
//}
//
//
//
//class Point
//{
//private:
//	int x, y;
//	char cc;
//
//	friend void gotoxy(Point*, int x, int y);
//
//
//public:
//	void charlocus(int X, int Y, char CC)
//	{
//		x = X;
//		y = Y;
//		cc = CC;
//	}
//
//	void display()
//	{
//
//		std::cout << cc;
//	}
//
//
//};
//
//
//int main()
//{
//	Point t;
//	Triandgle d;
//
//	t.charlocus(3, 5, 'd');
//	d.charlocus(1, 5, 'd');
//
//
//	gotoxy(&t, 6, 5);
//	gotoxy(&d, 3, 1);
//	t.display();
//	d.display();
//
//}
//
