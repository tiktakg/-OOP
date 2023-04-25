#include <iostream>
#include <string.h>
#include <Windows.h>
#include <conio.h>


class Point;
class Square;

class Point
{
private:

	char cc;
	short x, y;
public:
	


	friend void gotoxy(Square& t, Point& p);


	void charlocus(short X, short Y, char CC)
	{
		x = X;
		y = Y;
		cc = CC;
	}

	void display(Square& t, Point& p)
	{
		gotoxy(t, p);
		std::cout << cc;
	}
};

class Square
{
private:

	char cc;
	short x, y, x1, y1, x2, y2;
	
public:
	

	friend void gotoxy(Square& t, Point& p);

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

	void display(Square t, Point p)
	{
		gotoxy(t,p);
	}

};





void gotoxy(Square& t,Point& p)
{

	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { p.x,p.y };
	SetConsoleCursorPosition(stdOut, coord);
;
	coord = { t.x,t.y };
	SetConsoleCursorPosition(stdOut, coord);
	std::cout << t.cc;
	coord = { t.x1,t.y1 };

	SetConsoleCursorPosition(stdOut, coord);
	std::cout << t.cc;
	coord = { t.x2,t.y2 };
	SetConsoleCursorPosition(stdOut, coord);
	std::cout << t.cc;


}



int main()
{
	
	
	Point p;
	Square t;

	

	p.charlocus(5, 10, 'e');
	p.display(t,p);

	t.charlocus(1, 4, 6, 7, 8, 2, 'f');
	t.display(t,p);
	system("pause");
}



