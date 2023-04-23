#include <windows.h>
#include <iostream>
#include <string>


int enterData(std::string text)
{
	int date;

	std::cout << text;
	std::cin >> date;

	return date;
}

class Matrix
{
public:
	int lengthN;
	int lengthM;


	int** matrix;

	Matrix(int userInput = 1, int LengthN = 0, int LengthM = 0)
	{
		
		if (userInput != 3)
		{
			std::cout << "Write a lenght N \n";
			std::cin >> lengthN;

			std::cout << "Write a lenght M \n";
			std::cin >> lengthM;

			std::cout << "Write a filling method \n1 - manual \n2 - automatic  \n";
			std::cin >> userInput;

			LengthN = lengthN;
			LengthM = lengthM;

			system("cls");

		}
		else
		{

			lengthN = LengthN;
			lengthM = LengthM;

		}
		

		matrix = new int* [LengthN];

		for (int i = 0; i < LengthN; ++i)
		{
			matrix[i] = new int[LengthM] {};
		}

		if (userInput == 1)
		{
			for (int i = 0; i < LengthN; ++i)
				for (int j = 0; j < LengthM; ++j)
					matrix[i][j] = enterData("Write a number \n");

			system("cls");
		}
		else if (userInput == 2)
		{
			int firstNumber = enterData("Write a number for first range\n");
			int secondNumber = enterData("Write a number for second range\n");

			system("cls");

			for (int i = 0; i < LengthN; ++i)
				for (int j = 0; j < LengthM; ++j)
					matrix[i][j] = firstNumber + rand() % secondNumber;
		}
	

	}

	void UpgradeMatrix(int OldLengthN, int LengthN, int LengthM)
	{
		//for (int i = 0; i < OldLengthN; ++i)
		//	delete[] matrix[i];

		//delete[] matrix;

		matrix = new int* [LengthN];

		for (int i = 0; i < LengthN; ++i)
		{
			matrix[i] = new int[LengthM] {};
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

			std::cout << std::endl;
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

		return MatrixA;
	}
	else
		std::cout << "MatixA != MatrixB \n";

	

}


Matrix& operator * (Matrix& MatrixA, Matrix& MatrixB)
{
	Matrix m(3, MatrixA.lengthN, MatrixB.lengthM);

	if (MatrixA.lengthN == MatrixB.lengthM)
	{
		for (int i = 0; i < MatrixA.lengthN; ++i)
			for (int d = 0; d < MatrixB.lengthM; d++)
				for (int j = 0; j < MatrixA.lengthM; j++)
					m.matrix[i][d] += MatrixA.matrix[i][j] * MatrixB.matrix[j][d];
	}
	else
		std::cout << "MatixA string lenght != MatrixB column lenght \n";


	MatrixA.UpgradeMatrix(MatrixA.lengthN, m.lengthN, m.lengthM);

	MatrixA.lengthM = m.lengthM;
	MatrixA.lengthN = m.lengthN;

	for (int i = 0; i < m.lengthN; ++i)
		for (int j = 0; j < m.lengthM; ++j)
			MatrixA.matrix[i][j] = m.matrix[i][j];

	return MatrixA;
}




int main()
{
	std::srand(std::time(nullptr));


	Matrix A;
	Matrix B;


	std::cout << "|||||||||||||||\n";

	A.DisplayMatrix();
	std::cout << "|||||||||||||||\n";
	B.DisplayMatrix();


	Matrix C = A + B;
	std::cout << "|||||||||||||||\n";
	C.DisplayMatrix();
	std::cout << "|||||||||||||||\n";
	A = A * B;
	std::cout << "|||||||||||||||\n";
	A.DisplayMatrix();
	std::cout << "|||||||||||||||\n";

}
