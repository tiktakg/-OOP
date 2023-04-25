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


	void gotoxy(int x,int y)
	{
		HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coord = { x,y };
		SetConsoleCursorPosition(stdOut, coord);
	}
};

class Square : Point
{
private:

	char cc;
	short x, y;

public:


	void charlocus(short X, short Y,char CC)
	{
		x = X;
		y = Y;
		cc = CC;
	}

	void disply()
	{
		
		
		gotoxy(x, y);
		std::cout << cc;
		gotoxy(x+2, y);
		std::cout << cc;
		gotoxy(x, y+2);
		std::cout << cc;
		gotoxy(x+2, y+2);
		std::cout << cc;
	}
	

};




int main()
{

	Square t;
	t.charlocus(1, 1, 'c');
	t.disply();



	
}



