#include <windows.h>
#include <iostream>
#include <string>


int enterData(std::string text)
{
	int date;

	std::cout << "Write a date \n";
	std::cin >> date;

	return date;
}

class Matrix
{
public:
	int lengthN;
	int lengthM;
	int** matrix;

	Matrix(int LengthN, int LengthM,int userInput)
	{
		lengthN = LengthN;
		lengthM = LengthM;

		matrix = new int* [LengthN];
		
		for (int i = 0; i < LengthN; ++i)
		{
			matrix[i] = new int[LengthM] {};
		}

		if (userInput == 1)
		{
			for (int i = 0; i < LengthN; ++i)
				for (int j = 0; j < lengthM; ++j)
					matrix[i][j] = enterData("Write a number");
		}
		else if(userInput == 2)
		{
			int firstNumber = enterData("Write a number for first range");
			int secondNumber = enterData("Write a number for second range");

			for (int i = 0; i < LengthN; ++i)
				for (int j = 0; j < lengthM; ++j)
					 matrix[i][j] = firstNumber + rand() % secondNumber;
		}
		


	}

	~Matrix()
	{
		for (int i = 0; i < lengthN; i++)
			delete[] matrix[i];

		delete[] matrix;

		std::cout << "The matrix is deleted\n";
	}

	void DisplayMatrix()
	{
		for (int i = 0; i < lengthN; ++i)
		{
			for (int j = 0; j < lengthM; ++j)
					std::cout << matrix[i][j] << " ";

			std::cout  << std::endl;
		}
	}

};

Matrix& operator + (Matrix& MatrixA, Matrix& MatrixB)
{
	if (MatrixA.lengthN == MatrixB.lengthN and MatrixA.lengthM == MatrixB.lengthM)
	{
		for (int i = 0; i < MatrixA.lengthN; ++i)
			for (int j = 0; j < MatrixA.lengthM; ++j)
				MatrixA.matrix[i][j] += MatrixB.matrix[i][j];
	}
	else
		std::cout << "MatixA != MatrixB \n";

	return MatrixA;
	 
}

Matrix& operator * (Matrix& MatrixA, Matrix& MatrixB)
{
	Matrix m(MatrixA.lengthN, MatrixB.lengthM ,3);

	if (MatrixA.lengthN == MatrixB.lengthM)
	{
		int number =0;
		int number2 = 0;
		int d = 0;
		int k = 0;
		for (int i = 0; i <= MatrixA.lengthN; ++i)
		{
			// std::cout << "|||||||||||||||\n";
			 
			/*m.DisplayMatrix();
			system("Pause");
			system("cls");*/

			if (d == MatrixB.lengthM and i == MatrixA.lengthN)
			{	
				return m;	
			}

			d = 0;
			for (int j = 0; j <= MatrixB.lengthM; ++j)
			{
				number += MatrixA.matrix[i][j] * MatrixB.matrix[j][0];
				//std::cout << MatrixA.matrix[i][j] << " * " << MatrixB.matrix[j][0] << "\n";
				
			}

			//std::cout << number << "\n";
			m.matrix[i][d] = number;
			d++;
			number = 0;
			
			k++;


			for (int j = 0; j <= MatrixB.lengthM; ++j)
			{
				number += MatrixA.matrix[i][j] * MatrixB.matrix[j][k];
				//std::cout << MatrixA.matrix[i][j] << " * " << MatrixB.matrix[j][k] << "\n";

			}

			//std::cout << number << "\n";
			//std::cout << i << " " << d << "\n";
			m.matrix[i][d] = number;
			d++;
			number = 0;
			system("Pause");
			system("cls");
			
			k = 0;
			
			
			//std::cout << "|||||||||||||||\n";
			//m.DisplayMatrix();

			
		}
	}
	else
		std::cout << "MatixA string lenght != MatrixB column lenght \n";


}


void main()
{
	
	Matrix A(3, 3, 2);
	Matrix B(3, 2, 2);
	std::cout << "|||||||||||||||\n";
	A.DisplayMatrix();

	std::cout << "|||||||||||||||\n";
	B.DisplayMatrix();
	std::cout << "|||||||||||||||\n";



	
	A = A * B;
	std::cout << "||||||||adsad|||||||\n";
	A.DisplayMatrix();




	
}